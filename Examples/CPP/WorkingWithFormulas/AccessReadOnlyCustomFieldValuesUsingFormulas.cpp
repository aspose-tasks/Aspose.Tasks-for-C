#include "WorkingWithFormulas/AccessReadOnlyCustomFieldValuesUsingFormulas.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
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

RTTI_INFO_IMPL_HASH(1188211521u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::AccessReadOnlyCustomFieldValuesUsingFormulas, ThisTypeBaseTypesInfo);

void AccessReadOnlyCustomFieldValuesUsingFormulas::Run()
{
    // ExStart:AccessReadOnlyCustomFieldValuesUsingFormulas
    // Create new project and extended attribute definition
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    System::SharedPtr<ExtendedAttributeDefinition> attribute = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Cost, Aspose::Tasks::ExtendedAttributeTask::Cost1, u"");
    attribute->set_Formula(u"[Cost]-[Actual Cost]");
    
    project->get_ExtendedAttributes()->Add(attribute);
    
    // Add task
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    
    // Create extended attribute
    System::SharedPtr<ExtendedAttribute> extendedAttribute = attribute->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(extendedAttribute);
    
    // Display if extended attributes are read only or not
    System::Console::WriteLine(extendedAttribute->get_ValueReadOnly() == true ? System::String(u"Value is Read only") : System::String(u"Value is not read only"));
    extendedAttribute->set_NumericValue(-System::Decimal(1000000));
    System::Console::WriteLine(extendedAttribute->get_NumericValue() == -System::Decimal(1000000) ? System::String(u"Formula values are read-only") : System::String(u"Values are not read-only"));
    // ExEnd:AccessReadOnlyCustomFieldValuesUsingFormulas
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
