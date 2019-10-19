/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "UpdateResourceDataInMPP.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/decimal.h>
#include <system/console.h>
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

RTTI_INFO_IMPL_HASH(1199011210u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::UpdateResourceDataInMPP, ThisTypeBaseTypesInfo);

void UpdateResourceDataInMPP::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:UpdateResourceDataInMPP
        // Create project instance
        System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"UpdateResourceData.mpp");
        
        // Add resource and set some properties
        System::SharedPtr<Resource> rsc1 = project1->get_Resources()->Add(u"Rsc");
        rsc1->Set<System::Decimal>(Rsc::StandardRate(), static_cast<System::Decimal>(30));
        rsc1->Set<System::Decimal>(Rsc::OvertimeRate(), static_cast<System::Decimal>(45));
        rsc1->Set<System::String>(Rsc::Group(), u"Workgroup1");
        
        // Save the Project
        project1->Save(dataDir + u"UpdateResourceData_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:UpdateResourceDataInMPP
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
