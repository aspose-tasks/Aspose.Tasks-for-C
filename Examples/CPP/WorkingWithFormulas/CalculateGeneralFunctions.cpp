#include "CalculateGeneralFunctions.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <system/array.h>
#include <Project.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/CustomFieldType.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(789176484u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::CalculateGeneralFunctions, ThisTypeBaseTypesInfo);

void CalculateGeneralFunctions::Run()
{
    EvaluateChoose();
    EvaluateIsNumeric();
    EvaluateSwitch();
}

void CalculateGeneralFunctions::EvaluateChoose()
{
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    // Set Formula
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"Choose(3, \"This is a\", \"right\", \"choice\")");
    
    // Print extended attribute value
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
}

void CalculateGeneralFunctions::EvaluateIsNumeric()
{
    System::ArrayPtr<System::String> numericFormulas = System::MakeArray<System::String>({u"IsNumeric('AAA')", u"IsNUmeric(1)", u"IsNumeric(1<0)", u"IsNumeric(\"1.1\")", u"IsNumeric(Choose((2 + Sgn(2^-3)), 123, \"one two three\"))"});
    
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    
    {
        for (System::String numericFormula : numericFormulas)
        {
            // Set Formula
            project->get_ExtendedAttributes()->idx_get(0)->set_Formula(numericFormula);
            
            // Print extended attribute value
            System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
            System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
        }
        
    }
}

void CalculateGeneralFunctions::EvaluateSwitch()
{
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    // Set Formula
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"Switch( 0 < 1, \"0 is lesser than 1\", 0 > 1, \"0 is greater than 1\")");
    
    // Print extended attribute value
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
}

System::SharedPtr<Project> CalculateGeneralFunctions::CreateTestProjectWithCustomField()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text1, u"Custom Field");
    project->get_ExtendedAttributes()->Add(attr);
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    
    System::SharedPtr<ExtendedAttribute> a = attr->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(a);
    return project;
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
