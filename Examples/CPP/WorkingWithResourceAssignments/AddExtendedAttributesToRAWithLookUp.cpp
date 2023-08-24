#include "WorkingWithResourceAssignments/AddExtendedAttributesToRAWithLookUp.h"

#include <aspose.tasks.cpp/Value.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/console.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/ResourceAssignmentCollection.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeResource.h>
#include <aspose.tasks.cpp/enums/CustomFieldType.h>
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
try
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
    
    auto value1 = [&]{ auto tmp_0 = System::MakeObject<Value>(); tmp_0->set_NumericValue(1500); tmp_0->set_Description(u"Val 1"); tmp_0->set_Id(1); tmp_0->set_Val(u"1500"); return tmp_0; }();
    
    resCostAttr->AddLookupValue(value1);
    
    resCostAttr->AddLookupValue([&]{ auto tmp_1 = System::MakeObject<Value>(); tmp_1->set_NumericValue(2500); tmp_1->set_Description(u"Val 2"); tmp_1->set_Id(2); return tmp_1; }());
    
    // This value can be seen in "Resource usage" view of MS Project.
    auto attributeValue = resCostAttr->CreateExtendedAttribute(value1);
    assignment->get_ExtendedAttributes()->Add(attributeValue);
    
    // Create custom attribute definition with lookup.
    System::SharedPtr<ExtendedAttributeDefinition> taskCostAttr = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Cost4, u"My lookup task cost");
    
    project->get_ExtendedAttributes()->Add(taskCostAttr);
    
    auto taskLookupValue1 = [&]{ auto tmp_2 = System::MakeObject<Value>(); tmp_2->set_NumericValue(18); tmp_2->set_Description(u"Task val 1"); tmp_2->set_Id(3); tmp_2->set_Val(u"18"); return tmp_2; }();
    taskCostAttr->AddLookupValue(taskLookupValue1);
    
    resCostAttr->AddLookupValue([&]{ auto tmp_3 = System::MakeObject<Value>(); tmp_3->set_NumericValue(30); tmp_3->set_Description(u"Task val 2"); tmp_3->set_Id(4); return tmp_3; }());
    
    // This value can be seen in "Task usage" view of MS Project.
    assignment->get_ExtendedAttributes()->Add(taskCostAttr->CreateExtendedAttribute(taskLookupValue1));
    
    project->Save(dataDir + u"AddExtendedAttributesToRAWithLookUp_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
    //ExEnd: AddExtendedAttributesToRAWithLookUp
}
catch (System::NotSupportedException& ex)
{
    System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
}
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
