/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Rescheduling/RescheduleProjectFromStartDate.h"

#include <TaskCollection.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <Project.h>
#include <Prj.h>
#include <NullableBool.h>
#include <Key.h>
#include <enums/PrjKey.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Rescheduling {

RTTI_INFO_IMPL_HASH(1661744736u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Rescheduling::RescheduleProjectFromStartDate, ThisTypeBaseTypesInfo);

void RescheduleProjectFromStartDate::Run()
{
    // ExStart:ReschedueProjectFromStartDate
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    project->Set<NullableBool>(Prj::ScheduleFromStart(), NullableBool::to_NullableBool(true));
    project->Set(Prj::StartDate(), System::DateTime(2014, 1, 1));
    
    // Now all tasks dates (Start, Finish, EarlyStart, EarlyFinish, LateStart, LateFinish) are calculated. To get the critical path we need to calculate slacks (can be invoked in separate thread, but only after calculation of all early/late dates)
    project->Recalculate();
    System::SharedPtr<TaskCollection> criticalPath = project->get_CriticalPath();
    // ExEnd:ReschedueProjectFromStartDate
}

} // namespace Rescheduling
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
