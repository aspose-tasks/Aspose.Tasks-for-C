#include "CalculateTextFunctions.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
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

RTTI_INFO_IMPL_HASH(3351188317u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::CalculateTextFunctions, ThisTypeBaseTypesInfo);

void CalculateTextFunctions::Run()
{
    EvaluateStrConv();
    EvaluateStringFunction();
}
// ExStart:CalculateTextFunctions
void CalculateTextFunctions::EvaluateStrConv()
{
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    // Set formulas and print extended attribute value
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"StrConv(\"sTring and sTRINg\",3)");
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"StrConv(\"sTring and sTRINg\",1)");
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"StrConv(\"sTring and sTRINg\",2)");
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
}

void CalculateTextFunctions::EvaluateStringFunction()
{
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    // Set formulas and print extended attribute value
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"String(5, 40)");
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"String(5, \"A\")");
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"String(-5, \"A\")");
    // #Error
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
}

System::SharedPtr<Project> CalculateTextFunctions::CreateTestProjectWithCustomField()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text1, u"Custom Field");
    project->get_ExtendedAttributes()->Add(attr);
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    
    System::SharedPtr<ExtendedAttribute> a = attr->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(a);
    return project;
}
// ExEnd:CalculateTextFunctions
} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
