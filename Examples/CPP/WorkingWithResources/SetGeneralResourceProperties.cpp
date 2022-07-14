/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetGeneralResourceProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/decimal.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/RscKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(1575962436u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::SetGeneralResourceProperties, ThisTypeBaseTypesInfo);

void SetGeneralResourceProperties::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // ExStart:SetGeneralResourceProperties
    // Add resources
    System::SharedPtr<Resource> rsc1 = project->get_Resources()->Add(u"Rsc");
    
    // Set resource properties, Resource properties are represented by static class Rsc
    rsc1->Set<System::Decimal>(Rsc::StandardRate(), static_cast<System::Decimal>(15));
    rsc1->Set<System::Decimal>(Rsc::OvertimeRate(), static_cast<System::Decimal>(20));
    // ExEnd:SetGeneralResourceProperties
    
    // Save project as XML
    project->Save(dataDir + u"SetGeneralResourceProperties_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
