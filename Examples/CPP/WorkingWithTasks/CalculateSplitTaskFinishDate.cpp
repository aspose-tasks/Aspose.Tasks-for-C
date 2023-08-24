#include "CalculateSplitTaskFinishDate.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/Calendar.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1298182848u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::CalculateSplitTaskFinishDate, ThisTypeBaseTypesInfo);

void CalculateSplitTaskFinishDate::Run()
{
    // ExStart:CalculateSplitTaskFinishDate
    // Read project            
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::String projectName = u"SplitTaskFinishDate.mpp";
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + projectName);
    
    // Find a split task
    System::SharedPtr<Task> splitTask = project->get_RootTask()->get_Children()->GetByUid(4);
    
    // Find the project calendar
    System::SharedPtr<Calendar> calendar = project->Get<System::SharedPtr<Calendar>>(Prj::Calendar());
    
    // Calculate task's finish date with different durations
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 8 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(8, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 16 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(16, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 24 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(24, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 28 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(28, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 32 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(32, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 46 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(46, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 61 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(61, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 75 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(75, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 80 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(80, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 120 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(120, 0, 0)));
    System::Console::WriteLine(System::String(u"Start Date: ") + splitTask->Get<System::DateTime>(Tsk::Start()).ToShortDateString() + u"\n+ Duration 150 hours\nFinish Date: " + calendar->GetTaskFinishDateFromDuration(splitTask, System::TimeSpan(150, 0, 0)));
    // ExEnd:CalculateSplitTaskFinishDate
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
