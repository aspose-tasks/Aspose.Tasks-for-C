#include "ReadTaskOvertimes.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/decimal.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <Duration.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(2504575921u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskOvertimes, ThisTypeBaseTypesInfo);

void ReadTaskOvertimes::Run()
{
    // ExStart:ReadTaskOvertimes
    // Read project from file stream
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(dataDir + u"TaskOvertimes.mpp", System::IO::FileMode::Open);
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(fs);
    fs->Close();
    
    // Read overtime and percentage completion for tasks
    
    {
        auto tsk1_enumerator = (project1->get_RootTask()->get_Children())->GetEnumerator();
        decltype(tsk1_enumerator->get_Current()) tsk1;
        while (tsk1_enumerator->MoveNext() && (tsk1 = tsk1_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(tsk1->Get<System::Decimal>(Tsk::OvertimeCost()));
            System::Console::WriteLine(System::ObjectExt::ToString(tsk1->Get<Duration>(Tsk::OvertimeWork())));
            System::Console::WriteLine(tsk1->Get<int32_t>(Tsk::PercentComplete()));
            System::Console::WriteLine(System::Convert::ToString(tsk1->Get<int32_t>(Tsk::PercentWorkComplete())));
            System::Console::WriteLine(System::Convert::ToString(tsk1->Get<int32_t>(Tsk::PhysicalPercentComplete())));
            
            // Set percent complete
            tsk1->Set<int32_t>(Tsk::PercentComplete(), 100);
        }
    }
    // ExEnd:ReadTaskOvertimes
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
