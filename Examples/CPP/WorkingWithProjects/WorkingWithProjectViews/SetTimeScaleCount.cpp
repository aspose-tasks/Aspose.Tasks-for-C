#include "WorkingWithProjects/WorkingWithProjectViews/SetTimeScaleCount.h"

#include <aspose.tasks.cpp/visualization/View/TimescaleTier.h>
#include <aspose.tasks.cpp/ViewCollection.h>
#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/GanttChartView.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectViews {

RTTI_INFO_IMPL_HASH(4196928426u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectViews::SetTimeScaleCount, ThisTypeBaseTypesInfo);

void SetTimeScaleCount::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SetTimeScaleCount
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Init Gantt Chart View
    System::SharedPtr<GanttChartView> view = System::MakeObject<GanttChartView>();
    
    // Set Time Scale count
    view->get_BottomTimescaleTier()->set_Count(2);
    view->get_BottomTimescaleTier()->set_ShowTicks(false);
    view->get_MiddleTimescaleTier()->set_Count(2);
    view->get_MiddleTimescaleTier()->set_ShowTicks(false);
    
    // Add Gantt Chart View to project
    project->get_Views()->Add(view);
    
    // Add some test data to project
    System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->Add(u"Task 2");
    task1->Set<Duration>(Tsk::Duration(), task1->get_ParentProject()->GetDuration(24, Aspose::Tasks::TimeUnitType::Hour));
    task2->Set<Duration>(Tsk::Duration(), task1->get_ParentProject()->GetDuration(40, Aspose::Tasks::TimeUnitType::Hour));
    project->Save(dataDir + u"SetTimeScaleCount_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
    // ExEnd:SetTimeScaleCount
}

} // namespace WorkingWithProjectViews
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
