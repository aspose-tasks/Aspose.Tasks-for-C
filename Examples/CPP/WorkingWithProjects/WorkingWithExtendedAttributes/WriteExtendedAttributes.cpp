#include "WorkingWithProjects/WorkingWithExtendedAttributes/WriteExtendedAttributes.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/enums/CustomFieldType.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithExtendedAttributes {

RTTI_INFO_IMPL_HASH(3465984554u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithExtendedAttributes::WriteExtendedAttributes, ThisTypeBaseTypesInfo);

void WriteExtendedAttributes::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ExtendedAttributes
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ExtendedAttributes.mpp");
    
    // Create extended attribute definition
    System::SharedPtr<ExtendedAttributeDefinition> attributeDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Start, Aspose::Tasks::ExtendedAttributeTask::Start7, u"Start 7");
    project->get_ExtendedAttributes()->Add(attributeDefinition);
    
    // Get zero index task
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    // Add extended attribute
    System::SharedPtr<ExtendedAttribute> attribute = attributeDefinition->CreateExtendedAttribute();
    attribute->set_DateValue(System::DateTime::get_Now());
    
    // Also the following short syntax can be used: ExtendedAttribute attribute = attributeDefinition.CreateExtendedAttribute(DateTime.Now);
    task->get_ExtendedAttributes()->Add(attribute);
    // ExEnd:ExtendedAttributes
}

} // namespace WorkingWithExtendedAttributes
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
