/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetResourceExtendedAttributes.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/decimal.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <ResourceCollection.h>
#include <Resource.h>
#include <Project.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/ExtendedAttributeResource.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(662723715u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::SetResourceExtendedAttributes, ThisTypeBaseTypesInfo);

void SetResourceExtendedAttributes::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:SetResourceExtendedAttributes
        // Create project instance
        System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceExtendedAttributes.mpp");
        
        // Define extended attribute
        System::SharedPtr<ExtendedAttributeDefinition> myNumber1 = project1->get_ExtendedAttributes()->GetById((int32_t)Aspose::Tasks::ExtendedAttributeTask::Number1);
        if (myNumber1 == nullptr)
        {
            myNumber1 = ExtendedAttributeDefinition::CreateResourceDefinition(Aspose::Tasks::ExtendedAttributeResource::Number1, u"Age");
            project1->get_ExtendedAttributes()->Add(myNumber1);
        }
        
        // Create extended attribute and set its value
        System::SharedPtr<ExtendedAttribute> number1Resource = myNumber1->CreateExtendedAttribute();
        number1Resource->set_NumericValue(System::Decimal("30.5345"));
        
        // Add a new resource and its extended attribute   
        System::SharedPtr<Resource> rsc = project1->get_Resources()->Add(u"R1");
        rsc->get_ExtendedAttributes()->Add(number1Resource);
        
        // Save project as MPP
        project1->Save(dataDir + u"ResourceExtendedAttributes_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:SetResourceExtendedAttributes
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
