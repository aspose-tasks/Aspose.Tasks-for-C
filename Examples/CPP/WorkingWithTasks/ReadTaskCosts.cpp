#include "ReadTaskCosts.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/decimal.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(503818597u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskCosts, ThisTypeBaseTypesInfo);

void ReadTaskCosts::Run()
{
    // ExStart:ReadTaskCosts
    // Create new project
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Add task and set cost
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    task->Set<System::Decimal>(Tsk::Cost(), static_cast<System::Decimal>(800));
    
    // Display cost related properties of task
    System::Console::WriteLine(task->Get<System::Decimal>(Tsk::RemainingCost()));
    System::Console::WriteLine(task->Get<double>(Tsk::FixedCost()));
    System::Console::WriteLine(task->Get<double>(Tsk::CostVariance()));
    System::Console::WriteLine(project->get_RootTask()->Get<System::Decimal>(Tsk::Cost()));
    System::Console::WriteLine(project->get_RootTask()->Get<double>(Tsk::FixedCost()));
    System::Console::WriteLine(project->get_RootTask()->Get<System::Decimal>(Tsk::RemainingCost()));
    System::Console::WriteLine(project->get_RootTask()->Get<double>(Tsk::CostVariance()));
    // ExEnd:ReadTaskCosts
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
