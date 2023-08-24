/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "CreateResourcesAndLinkToTasks.h"

#include <aspose.tasks.cpp/util/TaskUtils.h>
#include <aspose.tasks.cpp/util/ChildTasksCollector.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Rsc.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/ResourceAssignmentCollection.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/RscKey.h>
#include <aspose.tasks.cpp/enums/ResourceType.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace KnowledgeBase {

RTTI_INFO_IMPL_HASH(2573578539u, ::Aspose::Tasks::Examples::CPP::KnowledgeBase::CreateResourcesAndLinkToTasks, ThisTypeBaseTypesInfo);

void CreateResourcesAndLinkToTasks::Run()
{
    try
    {
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:CreateResourcesAndLinkToTasks
        System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"SampleProject.mpp");
        
        // Declare ChildTasksCollector class object
        System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
        
        // Use TaskUtils to get all children tasks in RootTask
        TaskUtils::Apply(project1->get_RootTask(), collector, 0);
        
        // Define Resources
        for (int32_t i = 0; i <= 4; i++)
        {
            System::String devloper = System::String(u"Developer0") + i;
            
            // Add resource to project
            System::SharedPtr<Resource> newResource = project1->get_Resources()->Add(devloper);
            newResource->Set<ResourceType>(Rsc::Type(), Aspose::Tasks::ResourceType::Work);
            
            // Define assignment
            System::SharedPtr<ResourceAssignment> newResourceAssignment = project1->get_ResourceAssignments()->Add(System::ExplicitCast<Aspose::Tasks::Task>(collector->get_Tasks()->idx_get(i)), newResource);
        }
        
        project1->Save(dataDir + u"CreateResourcesAndLinkToTasks_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:CreateResourcesAndLinkToTasks
    }
    catch (System::NotSupportedException& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace KnowledgeBase
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
