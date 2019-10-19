#include "LinkTasks.h"

#include <Tsk.h>
#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskLinkType.h>
#include <enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace KnowledgeBase {

RTTI_INFO_IMPL_HASH(2135736948u, ::Aspose::Tasks::Examples::CPP::KnowledgeBase::LinkTasks, ThisTypeBaseTypesInfo);

void LinkTasks::Run()
{
    try
    {
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:LinkTasks            
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"SampleProject.mpp");
        
        System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->GetById(1);
        System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->GetById(2);
        System::SharedPtr<Task> task3 = project->get_RootTask()->get_Children()->GetById(3);
        System::SharedPtr<Task> task4 = project->get_RootTask()->get_Children()->GetById(4);
        System::SharedPtr<Task> task5 = project->get_RootTask()->get_Children()->GetById(5);
        
        // Link the tasks
        System::SharedPtr<TaskLink> tsklnk = project->get_TaskLinks()->Add(task1, task2, Aspose::Tasks::TaskLinkType::FinishToStart);
        tsklnk = project->get_TaskLinks()->Add(task2, task3, Aspose::Tasks::TaskLinkType::FinishToStart);
        tsklnk = project->get_TaskLinks()->Add(task3, task4, Aspose::Tasks::TaskLinkType::FinishToStart);
        tsklnk = project->get_TaskLinks()->Add(task4, task5, Aspose::Tasks::TaskLinkType::FinishToStart);
        tsklnk = project->get_TaskLinks()->Add(task2, task5, Aspose::Tasks::TaskLinkType::FinishToStart);
        
        // Display links among the tasks
        System::SharedPtr<TaskLinkCollection> allinks = project->get_TaskLinks();
        
        {
            auto tasklnk_enumerator = (allinks)->GetEnumerator();
            decltype(tasklnk_enumerator->get_Current()) tasklnk;
            while (tasklnk_enumerator->MoveNext() && (tasklnk = tasklnk_enumerator->get_Current(), true))
            {
                System::Console::WriteLine(System::String(u"From ID = ") + tasklnk->get_PredTask()->Get<int32_t>(Tsk::Id()) + u"=>To ID = " + tasklnk->get_SuccTask()->Get<int32_t>(Tsk::Id()));
                System::Console::WriteLine(u"________________________________________");
            }
        }
        
        // Save the project
        project->Save(dataDir + u"LinkTasks_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:LinkTasks
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
