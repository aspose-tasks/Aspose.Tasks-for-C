#include "GetCurrencyDigits.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCurrencies {

RTTI_INFO_IMPL_HASH(1169155798u, ::Aspose::Tasks::Examples::CPP::WorkingWithCurrencies::GetCurrencyDigits, ThisTypeBaseTypesInfo);

void GetCurrencyDigits::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetCurrencyDigits
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"project.mpp");
    System::Console::WriteLine(project1->Get<int32_t>(Prj::CurrencyDigits()));
    // ExEnd:GetCurrencyDigits
}

} // namespace WorkingWithCurrencies
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
