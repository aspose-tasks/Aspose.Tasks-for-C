#include "IdentifyCrossProjectTasks.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskLinks {

RTTI_INFO_IMPL_HASH(380903485u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks::IdentifyCrossProjectTasks, ThisTypeBaseTypesInfo);

void IdentifyCrossProjectTasks::Run()
{
    // ExStart:IdentifyCrossProjectTasks
    // Create project instance and access task
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"External.mpp");
    System::SharedPtr<Task> externalTask = project1->get_RootTask()->get_Children()->GetByUid(1);
    
    // Show ID of the task in the external project
    System::Console::WriteLine(System::Convert::ToString(externalTask->Get<int32_t>(Tsk::Id())));
    
    // Show ID of the task in the original project
    System::Console::WriteLine(System::Convert::ToString(externalTask->Get<int32_t>(Tsk::ExternalId())));
    // ExEnd:IdentifyCrossProjectTasks
}

} // namespace WorkingWithTaskLinks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
