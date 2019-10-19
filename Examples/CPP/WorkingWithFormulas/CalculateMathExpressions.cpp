#include "CalculateMathExpressions.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/decimal.h>
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

RTTI_INFO_IMPL_HASH(3937735554u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::CalculateMathExpressions, ThisTypeBaseTypesInfo);

void CalculateMathExpressions::Run()
{
    EvaluateSine();
}

void CalculateMathExpressions::EvaluateSine()
{
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    // Set formula Sin(pi/2)
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"Sin(3.1415926/2)");
    
    // Print Calculated value
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(u"Sin(pi/2): {0}", System::ObjectExt::Box<System::Decimal>(task->get_ExtendedAttributes()->idx_get(0)->get_NumericValue()));
}

System::SharedPtr<Project> CalculateMathExpressions::CreateTestProjectWithCustomField()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Number, Aspose::Tasks::ExtendedAttributeTask::Number1, u"Sine");
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
