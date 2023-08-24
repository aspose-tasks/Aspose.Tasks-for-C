/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithOutlineCodes.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/OutlineValueCollection.h>
#include <aspose.tasks.cpp/OutlineValue.h>
#include <aspose.tasks.cpp/OutlineMaskCollection.h>
#include <aspose.tasks.cpp/OutlineMask.h>
#include <aspose.tasks.cpp/OutlineCodeDefinitionCollection.h>
#include <aspose.tasks.cpp/OutlineCodeDefinition.h>
#include <aspose.tasks.cpp/enums/OutlineValueType.h>
#include <aspose.tasks.cpp/enums/MaskType.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(1983464473u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithOutlineCodes, ThisTypeBaseTypesInfo);

void WorkingWithOutlineCodes::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    try
    {
        // ReadOutlineCodes(dataDir);
        CheckOutlineCodeIdUniqueness(dataDir);
    }
    catch (System::NotSupportedException& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
}

void WorkingWithOutlineCodes::ReadOutlineCodes(System::String dataDir)
{
    // ExStart:ReadOutlineCodes
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"OutlineCodes.mpp");
    
    
    {
        auto ocd_enumerator = (project->get_OutlineCodes())->GetEnumerator();
        while (ocd_enumerator->MoveNext())
        {
            auto&& ocd = ocd_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Alias = ") + ocd->get_Alias());
            if (ocd->get_AllLevelsRequired())
            {
                System::Console::WriteLine(u"It contains property: must have all levels");
            }
            else
            {
                System::Console::WriteLine(u"It does not contain property: must have all levels");
            }
            if (ocd->get_Enterprise())
            {
                System::Console::WriteLine(u"It is an enterprise custom outline code.");
            }
            else
            {
                System::Console::WriteLine(u"It is not an enterprise custom outline code.");
            }
            
            System::Console::WriteLine(System::String(u"Reference to another custom field for which this outline code definition is an alias is = ") + ocd->get_EnterpriseOutlineCodeAlias());
            System::Console::WriteLine(System::String(u"Field Id = ") + ocd->get_FieldId());
            System::Console::WriteLine(System::String(u"Field Name = ") + ocd->get_FieldName());
            System::Console::WriteLine(System::String(u"Phonetic Alias = ") + ocd->get_PhoneticAlias());
            System::Console::WriteLine(System::String(u"Guid = ") + ocd->get_Guid());
            
            // Display outline code masks
            
            {
                auto outlineMask_enumerator = (ocd->get_Masks())->GetEnumerator();
                while (outlineMask_enumerator->MoveNext())
                {
                    auto&& outlineMask = outlineMask_enumerator->get_Current();
                    System::Console::WriteLine(System::String(u"Level of a mask = ") + outlineMask->get_Level());
                    System::Console::WriteLine(System::String(u"Mask = ") + System::ObjectExt::ToString(outlineMask));
                }
            }
            
            // Display out line code values
            
            {
                auto outlineMask1_enumerator = (ocd->get_Values())->GetEnumerator();
                while (outlineMask1_enumerator->MoveNext())
                {
                    auto&& outlineMask1 = outlineMask1_enumerator->get_Current();
                    System::Console::WriteLine(System::String(u"Description of outline value = ") + outlineMask1->get_Description());
                    System::Console::WriteLine(System::String(u"Value Id = ") + outlineMask1->get_ValueId());
                    System::Console::WriteLine(System::String(u"Value = ") + outlineMask1->get_Value());
                    System::Console::WriteLine(System::String(u"Type = ") + System::ObjectExt::ToString(outlineMask1->get_Type()));
                }
            }
        }
    }
    // ExEnd:ReadOutlineCodes
}

void WorkingWithOutlineCodes::CheckOutlineCodeIdUniqueness(System::String dataDir)
{
    // ExStart:CheckOutlineCodeIdUniqueness
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"OutlineValues2010.mpp");
    
    System::SharedPtr<OutlineCodeDefinition> textOutline = System::MakeObject<OutlineCodeDefinition>();
    textOutline->set_FieldId(System::Convert::ToString((int)Aspose::Tasks::ExtendedAttributeTask::OutlineCode7));
    textOutline->set_Alias(u"My Outline Code");
    
    project->get_OutlineCodes()->Add(textOutline);
    
    System::SharedPtr<OutlineMask> mask = System::MakeObject<OutlineMask>();
    mask->set_Type(Aspose::Tasks::MaskType::Characters);
    textOutline->get_Masks()->Add(mask);
    
    System::SharedPtr<OutlineValue> textValue = System::MakeObject<OutlineValue>();
    textValue->set_Value(u"Text value 1");
    textValue->set_ValueId(1);
    textValue->set_Type(Aspose::Tasks::OutlineValueType::Text);
    textValue->set_Description(u"Text value descr 1");
    textOutline->get_Values()->Add(textValue);
    
    project->Save(dataDir + u"MultipleOutlineValues_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
    // ExEnd:CheckOutlineCodeIdUniqueness
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
