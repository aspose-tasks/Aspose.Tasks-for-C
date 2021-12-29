#include "ReadCriticalPath.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace KnowledgeBase {

RTTI_INFO_IMPL_HASH(630007418u, ::Aspose::Tasks::Examples::CPP::KnowledgeBase::ReadCriticalPath, ThisTypeBaseTypesInfo);

void ReadCriticalPath::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadCriticalPath
    // Load MPP file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project1.mpp");
    
    // Get the critical path
    System::SharedPtr<TaskCollection> criticalPath = project->get_CriticalPath();
    
    // Enumerate the tasks in the critical path
    
    {
        auto task_enumerator = (criticalPath)->GetEnumerator();
        while (task_enumerator->MoveNext())
        {
            auto&& task = task_enumerator->get_Current();
            System::Console::WriteLine(System::Convert::ToString(task->Get<int32_t>(Tsk::Id())) + u"  " + task->Get(Tsk::Name()));
            System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(task->Get<System::DateTime>(Tsk::Start())));
            System::Console::WriteLine(System::Convert::ToString(task->Get<System::DateTime>(Tsk::Finish())) + u"\n");
        }
    }
    // ExEnd:ReadCriticalPath
}

} // namespace KnowledgeBase
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
