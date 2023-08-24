#include "ChangeTaskProgress.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/CalculationMode.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1997724040u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ChangeTaskProgress, ThisTypeBaseTypesInfo);

void ChangeTaskProgress::Run()
{
    // ExStart:ChangeTaskProgress
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::Console::WriteLine(u"Project Calculation mode is Automatic: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(project->get_CalculationMode(), Aspose::Tasks::CalculationMode::Automatic)));
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    task->Set<Duration>(Tsk::Duration(), project->GetDuration(2));
    task->Set<int32_t>(Tsk::PercentComplete(), 50);
    // ExEnd:ChangeTaskProgress
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
