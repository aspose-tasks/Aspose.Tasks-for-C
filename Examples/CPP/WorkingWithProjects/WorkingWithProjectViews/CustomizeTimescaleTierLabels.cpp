#include "WorkingWithProjects/WorkingWithProjectViews/CustomizeTimescaleTierLabels.h"

#include <visualization/View/TimescaleTier.h>
#include <visualization/View/DateTimeConverter.h>
#include <visualization/Enums/TimescaleUnit.h>
#include <View.h>
#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/array.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <GanttChartView.h>
#include <functional>
#include <enums/PrjKey.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectViews {

RTTI_INFO_IMPL_HASH(1025476229u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectViews::CustomizeTimescaleTierLabels, ThisTypeBaseTypesInfo);

void CustomizeTimescaleTierLabels::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:CustomizeTimescaleTierLabels
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project5.mpp");
    
    // Add task links
    project->get_TaskLinks()->Add(project->get_RootTask()->get_Children()->Add(u"Task 1"), project->get_RootTask()->get_Children()->Add(u"Task 2"));
    
    System::SharedPtr<GanttChartView> view = System::DynamicCast<Aspose::Tasks::GanttChartView>(project->get_DefaultView());
    
    // This code is added for better visualization
    view->get_MiddleTimescaleTier()->set_Unit(Aspose::Tasks::Visualization::TimescaleUnit::Months);
    project->Set(Prj::TimescaleStart(), System::DateTime(2012, 8, 6));
    
    // Customize middle tier dates
    
    // CSPORTCPP: [WARNING] Using local variables. Make sure that local function ptr does not leave the current scope.
    std::function<System::String(System::DateTime date)> _local_func_0 = [](System::DateTime date)
    {
        return System::MakeArray<System::String>({u"Янв.", u"Фев.", u"Мар.", u"Апр.", u"Май", u"Июнь", u"Июль", u"Авг.", u"Сен.", u"Окт.", u"Ноя.", u"Дек."})->idx_get(date.get_Month() - 1);
    };
    
    view->get_MiddleTimescaleTier()->set_DateTimeConverter(_local_func_0);
    project->Save(dataDir + u"CustomizeTimescaleTierLabels_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::PDF);
    // ExEnd:CustomizeTimescaleTierLabels
}

} // namespace WorkingWithProjectViews
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
