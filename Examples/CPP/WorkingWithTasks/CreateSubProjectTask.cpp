/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "CreateSubProjectTask.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1522613568u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::CreateSubProjectTask, ThisTypeBaseTypesInfo);

void CreateSubProjectTask::Run()
{
    try
    {
        // ExStart:CreateSubProjectTask
        // Create project instance
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"SubProjectTask.mpp");
        
        // Add task
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task 1");
        
        // Setting new subproject link
        task->Set<System::String>(Tsk::SubprojectName(), dataDir + u"subProject.mpp");
        
        // Save project
        project->Save(dataDir + u"SubProjectTask_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:CreateSubProjectTask
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose.Tasks License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
