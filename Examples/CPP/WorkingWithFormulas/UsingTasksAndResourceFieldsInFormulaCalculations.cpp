/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/UsingTasksAndResourceFieldsInFormulaCalculations.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <ResourceCollection.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/TaskKey.h>
#include <enums/PrjKey.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/CustomFieldType.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(3569261964u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::UsingTasksAndResourceFieldsInFormulaCalculations, ThisTypeBaseTypesInfo);

void UsingTasksAndResourceFieldsInFormulaCalculations::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
        
        // Set formula for extended attribute
        System::SharedPtr<ExtendedAttributeDefinition> extendedAttributeDefinition1 = project->get_ExtendedAttributes()->idx_get(0);
        extendedAttributeDefinition1->set_Alias(u"Days from finish to deadline");
        extendedAttributeDefinition1->set_Formula(u"[Deadline] - [Finish]");
        
        // Set Task Deadline and save project
        System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->GetById(1);
        task->Set(Tsk::Deadline(), System::DateTime(2015, 3, 20, 17, 0, 0));
        project->Save(dataDir + u"project_UsingTasksAndResourceFields_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

System::SharedPtr<Project> UsingTasksAndResourceFieldsInFormulaCalculations::CreateTestProjectWithCustomField()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create new project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
    project->Set(Prj::StartDate(), System::DateTime(2015, 3, 6, 8, 0, 0));
    
    // Add new task with extended attribute
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    System::SharedPtr<ExtendedAttributeDefinition> extendedAttributeDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text5, u"My Ext Attr");
    project->get_ExtendedAttributes()->Add(extendedAttributeDefinition);
    System::SharedPtr<ExtendedAttribute> extendedAttribute = extendedAttributeDefinition->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(extendedAttribute);
    
    // Add resource and resource assignment
    System::SharedPtr<Resource> rsc = project->get_Resources()->Add(u"Rsc");
    System::SharedPtr<ResourceAssignment> assn = project->get_ResourceAssignments()->Add(task, rsc);
    return project;
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
