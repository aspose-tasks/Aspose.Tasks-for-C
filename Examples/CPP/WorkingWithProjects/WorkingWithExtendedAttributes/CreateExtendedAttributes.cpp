/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "CreateExtendedAttributes.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/ExtendedAttributeTask.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithExtendedAttributes {

RTTI_INFO_IMPL_HASH(1750979089u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithExtendedAttributes::CreateExtendedAttributes, ThisTypeBaseTypesInfo);

void CreateExtendedAttributes::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:CreateExtendedAttributes  
        System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        
        System::SharedPtr<ExtendedAttributeDefinition> myTextAttributeDefinition = project1->get_ExtendedAttributes()->GetById((int32_t)Aspose::Tasks::ExtendedAttributeTask::Text1);
        
        // If the Custom field doesn't exist in Project, create it
        if (myTextAttributeDefinition == nullptr)
        {
            myTextAttributeDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Text1, u"My text field");
            project1->get_ExtendedAttributes()->Add(myTextAttributeDefinition);
        }
        
        // Generate Extended Attribute from definition
        System::SharedPtr<ExtendedAttribute> text1TaskAttribute = myTextAttributeDefinition->CreateExtendedAttribute();
        
        text1TaskAttribute->set_TextValue(u"Text attribute value");
        
        // Add extended attribute to task
        System::SharedPtr<Task> tsk = project1->get_RootTask()->get_Children()->Add(u"Task 1");
        tsk->get_ExtendedAttributes()->Add(text1TaskAttribute);
        
        project1->Save(dataDir + u"CreateExtendedAttributes_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:CreateExtendedAttributes
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithExtendedAttributes
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
