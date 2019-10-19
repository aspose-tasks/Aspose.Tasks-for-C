/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "UpdateOutlineCodes.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/convert.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <OutlineValueCollection.h>
#include <OutlineValue.h>
#include <OutlineMaskCollection.h>
#include <OutlineMask.h>
#include <OutlineCodeDefinitionCollection.h>
#include <OutlineCodeDefinition.h>
#include <enums/OutlineValueType.h>
#include <enums/MaskType.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/ExtendedAttributeResource.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(1376762188u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::UpdateOutlineCodes, ThisTypeBaseTypesInfo);

void UpdateOutlineCodes::Run()
{
    try
    {
        // ExStart:UpdateOutlineCodes
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"project.mpp");
        
        // Define outline code and its outline mask
        System::SharedPtr<OutlineCodeDefinition> code1 = System::MakeObject<OutlineCodeDefinition>();
        code1->set_Alias(u"New task outline code1");
        code1->set_FieldId(System::Convert::ToString(((int32_t)Aspose::Tasks::ExtendedAttributeTask::OutlineCode1)));
        code1->set_FieldName(u"Outline Code1");
        System::SharedPtr<OutlineMask> mask = System::MakeObject<OutlineMask>();
        mask->set_Separator(u"+");
        mask->set_Level(1);
        mask->set_Type(Aspose::Tasks::MaskType::Numbers);
        code1->get_Masks()->Add(mask);
        
        // Add outline value
        System::SharedPtr<OutlineValue> value = System::MakeObject<OutlineValue>();
        value->set_Description(u"Value description");
        value->set_ValueId(1);
        value->set_Value(u"123456");
        value->set_Type(Aspose::Tasks::OutlineValueType::Number);
        code1->get_Values()->Add(value);
        
        // Add outline code to project
        project->get_OutlineCodes()->Add(code1);
        
        // Define outline code and its outline mask
        System::SharedPtr<OutlineCodeDefinition> code2 = System::MakeObject<OutlineCodeDefinition>();
        code2->set_Alias(u"New rsc outline code2");
        code2->set_FieldId(System::Convert::ToString(((int32_t)Aspose::Tasks::ExtendedAttributeResource::OutlineCode2)));
        code2->set_FieldName(u"Outline Code2");
        System::SharedPtr<OutlineMask> mask2 = System::MakeObject<OutlineMask>();
        mask2->set_Separator(u"/");
        mask2->set_Level(1);
        mask2->set_Type(Aspose::Tasks::MaskType::Numbers);
        code2->get_Masks()->Add(mask2);
        
        // Add outline value
        System::SharedPtr<OutlineValue> value2 = System::MakeObject<OutlineValue>();
        value2->set_Description(u"Value2 description");
        value2->set_ValueId(2);
        value2->set_Value(u"987654");
        value2->set_Type(Aspose::Tasks::OutlineValueType::Number);
        code2->get_Values()->Add(value2);
        
        // Add outline code to project
        project->get_OutlineCodes()->Add(code2);
        
        // Save project as MPP
        project->Save(dataDir + u"Updated_project_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:UpdateOutlineCodes
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
