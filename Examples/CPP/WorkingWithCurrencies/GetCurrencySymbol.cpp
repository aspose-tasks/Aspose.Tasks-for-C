#include "GetCurrencySymbol.h"

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

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCurrencies {

RTTI_INFO_IMPL_HASH(3837853768u, ::Aspose::Tasks::Examples::CPP::WorkingWithCurrencies::GetCurrencySymbol, ThisTypeBaseTypesInfo);

void GetCurrencySymbol::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetCurrencySymbol
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"project.mpp");
    System::Console::WriteLine(project1->Get<System::String>(Prj::CurrencySymbol()));
    // ExEnd:GetCurrencySymbol
}

} // namespace WorkingWithCurrencies
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
