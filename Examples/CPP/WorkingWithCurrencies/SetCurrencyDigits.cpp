/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetCurrencyDigits.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCurrencies {

RTTI_INFO_IMPL_HASH(4232689378u, ::Aspose::Tasks::Examples::CPP::WorkingWithCurrencies::SetCurrencyDigits, ThisTypeBaseTypesInfo);

void SetCurrencyDigits::Run()
{
    // ExStart:SetCurrencyDigits
    // Create new project and set currency digits
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    project1->Set<int32_t>(Prj::CurrencyDigits(), 2);
    // ExEnd:SetCurrencyDigits
    
    // Save project as XML
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project1->Save(dataDir + u"project_CurrencyDigits_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
}

} // namespace WorkingWithCurrencies
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
