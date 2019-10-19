/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WriteTaskProperties.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1887260977u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WriteTaskProperties, ThisTypeBaseTypesInfo);

void WriteTaskProperties::Run()
{
    // ExStart:WriteTaskProperties
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Add task and set task properties
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task1");
    task->Set(Tsk::Start(), project->get_RootTask()->Get<System::DateTime>(Tsk::Start()).AddDays(1));
    task->Set<System::String>(Tsk::Name(), u"new name");
    // ExEnd:WriteTaskProperties
    
    // Save project
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project->Save(dataDir + u"WriteTaskProperties_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::PDF);
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
