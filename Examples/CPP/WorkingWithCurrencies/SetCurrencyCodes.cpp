/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetCurrencyCodes.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/PrjKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCurrencies {

RTTI_INFO_IMPL_HASH(1626674122u, ::Aspose::Tasks::Examples::CPP::WorkingWithCurrencies::SetCurrencyCodes, ThisTypeBaseTypesInfo);

void SetCurrencyCodes::Run()
{
    // ExStart:SetCurrencyCodes
    // Create new project and set currency code
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    project1->Set<System::String>(Prj::CurrencyCode(), u"USD");
    // ExEnd:SetCurrencyCodes
    
    // Save project as XML
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project1->Save(dataDir + u"project_CurrencyCodes_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
}

} // namespace WorkingWithCurrencies
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
