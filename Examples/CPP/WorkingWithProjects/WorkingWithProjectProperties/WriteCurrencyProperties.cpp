#include "WorkingWithProjects/WorkingWithProjectProperties/WriteCurrencyProperties.h"

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
#include <aspose.tasks.cpp/enums/CurrencySymbolPositionType.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(2652322572u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::WriteCurrencyProperties, ThisTypeBaseTypesInfo);

void WriteCurrencyProperties::Run()
{
    // ExStart:WriteCurrencyProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"WriteCurrencyProperties.mpp");
    
    // Set currency properties
    project->Set<System::String>(Prj::CurrencyCode(), u"AUD");
    project->Set<int32_t>(Prj::CurrencyDigits(), 2);
    project->Set<System::String>(Prj::CurrencySymbol(), u"$");
    project->Set<CurrencySymbolPositionType>(Prj::CurrencySymbolPosition(), Aspose::Tasks::CurrencySymbolPositionType::After);
    
    // Save the project as XML project file
    project->Save(dataDir + u"WriteCurrencyProperties_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:WriteCurrencyProperties
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
