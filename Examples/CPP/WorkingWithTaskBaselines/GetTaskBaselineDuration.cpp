#include "GetTaskBaselineDuration.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <TaskBaselineCollection.h>
#include <TaskBaseline.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <enums/BaselineType.h>
#include <Duration.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskBaselines {

RTTI_INFO_IMPL_HASH(3152970483u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskBaselines::GetTaskBaselineDuration, ThisTypeBaseTypesInfo);

void GetTaskBaselineDuration::Run()
{
    // ExStart:GetTaskBaselineDuration
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Creating TaskBaseline
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    project->SetBaseline(Aspose::Tasks::BaselineType::Baseline);
    
    // Display task baseline duration
    System::SharedPtr<TaskBaseline> baseline = task->get_Baselines()->ToList()->idx_get(0);
    System::Console::WriteLine(u"Baseline duration is 1 day: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(baseline->get_Duration()), u"1 day")));
    System::Console::WriteLine(u"BaselineStart is same as Task Start: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(baseline->get_Start(), task->Get<System::DateTime>(Tsk::Start()))));
    System::Console::WriteLine(u"BaselineFinish is same as Task Finish: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(baseline->get_Finish(), task->Get<System::DateTime>(Tsk::Finish()))));
    // ExEnd:GetTaskBaselineDuration            
}

} // namespace WorkingWithTaskBaselines
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
