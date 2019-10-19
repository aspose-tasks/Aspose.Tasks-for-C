/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SortTasksByColumnInGanttChart.h"

#include <visualization/Enums/Timescale.h>
#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/icomparer.h>
#include <saving/SaveOptions.h>
#include <saving/Pdf/PdfSaveOptions.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(3999740463u, ::Aspose::Tasks::Examples::CPP::Articles::SortTasksByColumnInGanttChart::TasksDurationComparer, ThisTypeBaseTypesInfo);
// ExEnd:SortTasksByColumnInGanttChart
int32_t SortTasksByColumnInGanttChart::TasksDurationComparer::Compare(System::SharedPtr<Task> const &x, System::SharedPtr<Task> const &y) ASPOSE_CONST
{
    Duration durX = x->Get<Duration>(Tsk::Duration());
    Duration durY = y->Get<Duration>(Tsk::Duration());
    return durX.get_TimeSpan().CompareTo(durY.get_TimeSpan());
}

RTTI_INFO_IMPL_HASH(3294090278u, ::Aspose::Tasks::Examples::CPP::Articles::SortTasksByColumnInGanttChart::TasksNameComparer, ThisTypeBaseTypesInfo);

int32_t SortTasksByColumnInGanttChart::TasksNameComparer::Compare(System::SharedPtr<Task> const &x, System::SharedPtr<Task> const &y) ASPOSE_CONST
{
    return x->Get(Tsk::Name()).CompareTo(y->Get(Tsk::Name()));
}


RTTI_INFO_IMPL_HASH(2274840928u, ::Aspose::Tasks::Examples::CPP::Articles::SortTasksByColumnInGanttChart, ThisTypeBaseTypesInfo);

void SortTasksByColumnInGanttChart::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Months);
    
    options->set_TasksComparer(System::MakeObject<SortTasksByColumnInGanttChart::TasksNameComparer>());
    project->Save(dataDir + u"SortedByNames_out.pdf", options);
    
    options->set_TasksComparer(System::MakeObject<SortTasksByColumnInGanttChart::TasksDurationComparer>());
    project->Save(dataDir + u"SortedByDurations_out.pdf", options);
}
// ExEnd:SortTasksByColumnInGanttChart
} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
