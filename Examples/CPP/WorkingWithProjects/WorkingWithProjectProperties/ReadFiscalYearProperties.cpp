#include "WorkingWithProjects/WorkingWithProjectProperties/ReadFiscalYearProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <Project.h>
#include <Prj.h>
#include <NullableBool.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <enums/Month.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(2168374651u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ReadFiscalYearProperties, ThisTypeBaseTypesInfo);

void ReadFiscalYearProperties::Run()
{
    // ExStart:ReadFiscalYearProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadFiscalYearProperties.mpp");
    
    // Display fiscal year properties
    System::Console::WriteLine(System::String(u"Fiscal Year Start Date : ") + System::ObjectExt::ToString(project->Get<Month>(Prj::FyStartDate())));
    System::Console::WriteLine(System::String(u"Fiscal Year Numbering : ") + System::ObjectExt::ToString(project->Get<NullableBool>(Prj::FiscalYearStart())));
    // ExEnd:ReadFiscalYearProperties
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
