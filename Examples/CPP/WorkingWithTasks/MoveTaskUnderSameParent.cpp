/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "MoveTaskUnderSameParent.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(936812108u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::MoveTaskUnderSameParent, ThisTypeBaseTypesInfo);

void MoveTaskUnderSameParent::Run()
{
    try
    {
        // ExStart:MoveTaskUnderSameParent
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // Loading project file
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"MoveTask.mpp");
        
        // Move tasks with id 5 before task with id 3
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(5);
        task->MoveToSibling(3);
        
        // Saving File To Disk
        project->Save(dataDir + u"MoveTaskUnderSameParent_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:MoveTaskUnderSameParent
    }
    catch (System::Exception& exception)
    {
        System::Console::WriteLine(exception->get_Message() + u"\nThis example will only work if you apply a valid Aspose.Tasks License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
