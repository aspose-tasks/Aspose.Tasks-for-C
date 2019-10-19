#include "WorkingWithResourceAssignments/AddExtendedAttributesToRAWithLookUp.h"

#include <Value.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <ResourceCollection.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/ExtendedAttributeResource.h>
#include <enums/CustomFieldType.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(153630347u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::AddExtendedAttributesToRAWithLookUp, ThisTypeBaseTypesInfo);

void AddExtendedAttributesToRAWithLookUp::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    //ExStart: AddExtendedAttributesToRAWithLookUp
    // Create new project
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
    
    // Assign resource "1 TRG: Trade Group" to the "TASK 1" by creating a ResourceAssignment object.
    System::SharedPtr<Resource> resource = project->get_Resources()->GetById(1);
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    System::SharedPtr<ResourceAssignment> assignment = project->get_ResourceAssignments()->Add(task, resource);
    
    // Create custom attribute definition with lookup.
    System::SharedPtr<ExtendedAttributeDefinition> resCostAttr = ExtendedAttributeDefinition::CreateLookupResourceDefinition(Aspose::Tasks::CustomFieldType::Cost, Aspose::Tasks::ExtendedAttributeResource::Cost5, u"My lookup resource cost");
    project->get_ExtendedAttributes()->Add(resCostAttr);
    
    auto value1 = [&]{ auto tmp_0 = System::MakeObject<Value>(); tmp_0->set_NumberValue(1500); tmp_0->set_Description(u"Val 1"); tmp_0->set_Id(1); tmp_0->set_Val(u"1500"); return tmp_0; }();
    
    resCostAttr->AddLookupValue(value1);
    
    resCostAttr->AddLookupValue([&]{ auto tmp_1 = System::MakeObject<Value>(); tmp_1->set_NumberValue(2500); tmp_1->set_Description(u"Val 2"); tmp_1->set_Id(2); return tmp_1; }());
    
    // This value can be seen in "Resource usage" view of MS Project.
    auto attributeValue = resCostAttr->CreateExtendedAttribute(value1);
    assignment->get_ExtendedAttributes()->Add(attributeValue);
    
    // Create custom attribute definition with lookup.
    System::SharedPtr<ExtendedAttributeDefinition> taskCostAttr = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Cost4, u"My lookup task cost");
    
    project->get_ExtendedAttributes()->Add(taskCostAttr);
    
    auto taskLookupValue1 = [&]{ auto tmp_2 = System::MakeObject<Value>(); tmp_2->set_NumberValue(18); tmp_2->set_Description(u"Task val 1"); tmp_2->set_Id(3); tmp_2->set_Val(u"18"); return tmp_2; }();
    taskCostAttr->AddLookupValue(taskLookupValue1);
    
    resCostAttr->AddLookupValue([&]{ auto tmp_3 = System::MakeObject<Value>(); tmp_3->set_NumberValue(30); tmp_3->set_Description(u"Task val 2"); tmp_3->set_Id(4); return tmp_3; }());
    
    // This value can be seen in "Task usage" view of MS Project.
    assignment->get_ExtendedAttributes()->Add(taskCostAttr->CreateExtendedAttribute(taskLookupValue1));
    
    project->Save(dataDir + u"AddExtendedAttributesToRAWithLookUp_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
    //ExEnd: AddExtendedAttributesToRAWithLookUp
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
