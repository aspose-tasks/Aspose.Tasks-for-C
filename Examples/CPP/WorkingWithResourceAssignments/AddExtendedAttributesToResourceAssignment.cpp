#include "WorkingWithResourceAssignments/AddExtendedAttributesToResourceAssignment.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/decimal.h>
#include <saving/Enums/SaveFileFormat.h>
#include <system/console.h>
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

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(1605151895u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::AddExtendedAttributesToResourceAssignment, ThisTypeBaseTypesInfo);

void AddExtendedAttributesToResourceAssignment::Run()
{
try
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    //ExStart: AddExtendedAttributesToResourceAssignment
    // Create new project
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
    
    // Add new task and resource
    System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->Add(u"Task");
    System::SharedPtr<Resource> rsc1 = project->get_Resources()->Add(u"Rsc");
    
    // Assign the resource to the desired task
    System::SharedPtr<ResourceAssignment> assignment = project->get_ResourceAssignments()->Add(task1, rsc1);
    
    // Custom attributes which is visible in "Resource Usage" view can be created with ExtendedAttributeDefinition.CreateResourceDefinition method.
    
    {
        System::SharedPtr<ExtendedAttributeDefinition> resCostAttributeDefinition = ExtendedAttributeDefinition::CreateResourceDefinition(Aspose::Tasks::CustomFieldType::Cost, Aspose::Tasks::ExtendedAttributeResource::Cost5, u"My cost");
        
        project->get_ExtendedAttributes()->Add(resCostAttributeDefinition);
        
        auto value = resCostAttributeDefinition->CreateExtendedAttribute();
        
        // The type of the attribute is "Cost", so we need to use "NumericValue" property.
        value->set_NumericValue(1500);
        
        assignment->get_ExtendedAttributes()->Add(value);
    }
    
    // Custom attributes which is visible in "Task Usage" view can be created with ExtendedAttributeDefinition.CreateTaskDefinition method
    
    {
        System::SharedPtr<ExtendedAttributeDefinition> taskCostAttributeDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Cost, Aspose::Tasks::ExtendedAttributeTask::Cost5, u"My cost for task");
        
        project->get_ExtendedAttributes()->Add(taskCostAttributeDefinition);
        
        auto value = taskCostAttributeDefinition->CreateExtendedAttribute();
        
        // The type of the attribute is "Cost", so we need to use "NumericValue" property.
        value->set_NumericValue(2300);
        
        assignment->get_ExtendedAttributes()->Add(value);
    }
    
    project->Save(dataDir + u"AddExtendedAttributesToResourceAssignment_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
    //ExEnd: AddExtendedAttributesToResourceAssignment
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
