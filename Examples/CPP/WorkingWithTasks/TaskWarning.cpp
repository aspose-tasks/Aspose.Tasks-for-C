#include "TaskWarning.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3117995345u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::TaskWarning, ThisTypeBaseTypesInfo);

void TaskWarning::Run()
{
    // ExStart:TaskWarning
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    auto project = System::MakeObject<Project>(dataDir + u"schedule-conflict.mpp");
    auto task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(task->Get<bool>(Tsk::Warning()));
    // ExEnd:TaskWarning
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
