#include "WorkingWithProjects/Miscellaneous/CalculateCriticalPath.h"

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
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskLinkType.h>
#include <enums/TaskKey.h>
#include <enums/CalculationMode.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(4057473310u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::CalculateCriticalPath, ThisTypeBaseTypesInfo);

void CalculateCriticalPath::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:CalculateCriticalPath
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CalculateCriticalPath.mpp");
    project->set_CalculationMode(Aspose::Tasks::CalculationMode::Automatic);
    
    System::SharedPtr<Task> subtask1 = project->get_RootTask()->get_Children()->Add(u"1");
    System::SharedPtr<Task> subtask2 = project->get_RootTask()->get_Children()->Add(u"2");
    System::SharedPtr<Task> subtask3 = project->get_RootTask()->get_Children()->Add(u"3");
    project->get_TaskLinks()->Add(subtask1, subtask2, Aspose::Tasks::TaskLinkType::FinishToStart);
    
    // Display the critical path now
    
    {
        auto task_enumerator = (project->get_CriticalPath())->GetEnumerator();
        while (task_enumerator->MoveNext())
        {
            auto&& task = task_enumerator->get_Current();
            System::Console::WriteLine(task->Get(Tsk::Name()));
        }
    }
    // ExEnd:CalculateCriticalPath
}

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
