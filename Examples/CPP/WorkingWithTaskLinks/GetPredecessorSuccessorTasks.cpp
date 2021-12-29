#include "GetPredecessorSuccessorTasks.h"

#include <Tsk.h>
#include <TaskLinkCollection.h>
#include <TaskLink.h>
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
#include <enums/TaskKey.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskLinks {

RTTI_INFO_IMPL_HASH(3001112903u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks::GetPredecessorSuccessorTasks, ThisTypeBaseTypesInfo);

void GetPredecessorSuccessorTasks::Run()
{
    // ExStart:GetPredecessorSuccessorTasks
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"GetPredecessorSuccessorTasks.mpp");
    
    // Display names of predecessor and successor tasks
    
    {
        auto tsklnk_enumerator = (project1->get_TaskLinks())->GetEnumerator();
        while (tsklnk_enumerator->MoveNext())
        {
            auto&& tsklnk = tsklnk_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Predecessor ") + tsklnk->get_PredTask()->Get(Tsk::Name()));
            System::Console::WriteLine(System::String(u"Predecessor ") + tsklnk->get_SuccTask()->Get(Tsk::Name()));
        }
    }
    // ExEnd:GetPredecessorSuccessorTasks
}

} // namespace WorkingWithTaskLinks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
