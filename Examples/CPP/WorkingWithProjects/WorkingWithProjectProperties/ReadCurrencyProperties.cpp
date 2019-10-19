#include "WorkingWithProjects/WorkingWithProjectProperties/ReadCurrencyProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <enums/CurrencySymbolPositionType.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(3354857169u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ReadCurrencyProperties, ThisTypeBaseTypesInfo);

void ReadCurrencyProperties::Run()
{
    // ExStart:ReadCurrencyProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadCurrencyProperties.mpp");
    
    // Display currency properties
    System::Console::WriteLine(System::String(u"Currency Code : ") + System::ObjectExt::ToString(project->Get<System::String>(Prj::CurrencyCode())));
    System::Console::WriteLine(System::String(u"<br>Currency Digits : ") + System::Convert::ToString(project->Get<int32_t>(Prj::CurrencyDigits())));
    System::Console::WriteLine(System::String(u"<br>Currency Symbol : ") + System::ObjectExt::ToString(project->Get<System::String>(Prj::CurrencySymbol())));
    System::Console::WriteLine(System::String(u"Currency Symbol Position") + System::ObjectExt::ToString(project->Get<CurrencySymbolPositionType>(Prj::CurrencySymbolPosition())));
    // ExEnd:ReadCurrencyProperties
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
