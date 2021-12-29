#include "ReadTaskAndResources.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <enums/RscKey.h>
#include <enums/ResourceType.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace KnowledgeBase {

RTTI_INFO_IMPL_HASH(2627745833u, ::Aspose::Tasks::Examples::CPP::KnowledgeBase::ReadTaskAndResources, ThisTypeBaseTypesInfo);

void ReadTaskAndResources::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadTaskAndResources
    // Load MPP file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project1.mpp");
    
    // Load all tasks
    System::SharedPtr<TaskCollection> allTasks = project->get_RootTask()->get_Children();
    
    // Loop through each task and read information related to tasks
    
    {
        auto task_enumerator = (allTasks)->GetEnumerator();
        while (task_enumerator->MoveNext())
        {
            auto&& task = task_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Reading Task ") + task->Get(Tsk::Name()));
            System::Console::WriteLine(System::String(u"\nID: ") + task->Get<int32_t>(Tsk::Id()));
            System::Console::WriteLine(System::String(u"Start: ") + task->Get<System::DateTime>(Tsk::Start()));
            System::Console::WriteLine(System::String(u"Finish: ") + task->Get<System::DateTime>(Tsk::Finish()));
            System::Console::WriteLine(u"\n===========================\n");
        }
    }
    
    // Loop through each resource and read information related to resources
    
    {
        auto resource_enumerator = (project->get_Resources())->GetEnumerator();
        while (resource_enumerator->MoveNext())
        {
            auto&& resource = resource_enumerator->get_Current();
            System::String resourceType;
            switch (resource->Get<ResourceType>(Rsc::Type()))
            {
                case Aspose::Tasks::ResourceType::Material:
                    resourceType = u"Material";
                    break;
                
                case Aspose::Tasks::ResourceType::Work:
                    resourceType = u"Work";
                    break;
                
                default: 
                    resourceType = u"Cost";
                    break;
                
            }
            
            System::Console::WriteLine(System::String(u"Reading Resource ") + resource->Get<System::String>(Rsc::Name()));
            System::Console::WriteLine(System::String(u"\nID: ") + resource->Get<int32_t>(Rsc::Id()));
            System::Console::WriteLine(System::String(u"Type: ") + resourceType);
            System::Console::WriteLine(u"\n===========================\n");
        }
    }
    // ExEnd:ReadTaskAndResources
}

} // namespace KnowledgeBase
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
