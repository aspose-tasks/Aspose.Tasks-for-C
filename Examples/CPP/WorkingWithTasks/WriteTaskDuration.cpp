/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WriteTaskDuration.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/Duration.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3538907410u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WriteTaskDuration, ThisTypeBaseTypesInfo);

void WriteTaskDuration::Run()
{
    // ExStart:WriteTaskDuration
    // Create a new project and add a new task
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    
    // Task duration in days (default time unit)
    Duration duration = task->Get<Duration>(Tsk::Duration());
    System::Console::WriteLine(u"Duration equals 1 day: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(duration), u"1 day")));
    
    // Convert to hours time unit
    duration = duration.Convert(Aspose::Tasks::TimeUnitType::Hour);
    System::Console::WriteLine(u"Duration equals 8 hrs: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(duration), u"8 hrs")));
    
    // Get wrapped TimeSpan instance
    System::Console::WriteLine(u"Duration TimeSpan equals to TimeSpan of 8 hrs: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(duration.get_TimeSpan(), System::TimeSpan::FromHours(8))));
    
    // Increase task duration to 1 week and display if duration is updated successfully
    task->Set<Duration>(Tsk::Duration(), project->GetDuration(1, Aspose::Tasks::TimeUnitType::Week));
    System::Console::WriteLine(u"Duration equals 1 wk: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(task->Get<Duration>(Tsk::Duration())), u"1 wk")));
    
    // Decrease task duration and display if duration is updated successfully
    task->Set<Duration>(Tsk::Duration(), task->Get<Duration>(Tsk::Duration()).Subtract(0.5));
    System::Console::WriteLine(u"Duration equals 0.5 wks: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(task->Get<Duration>(Tsk::Duration())), u"0.5 wks")));
    // ExEnd:WriteTaskDuration
    
    // Save project as PDF
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project->Save(dataDir + u"WriteTaskDuration_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
