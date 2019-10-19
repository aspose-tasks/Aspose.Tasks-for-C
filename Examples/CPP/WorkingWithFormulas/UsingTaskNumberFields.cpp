/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/UsingTaskNumberFields.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/console.h>
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
#include <cstdint>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(3860875606u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::UsingTaskNumberFields, ThisTypeBaseTypesInfo);

void UsingTaskNumberFields::Run()
{
    // ExStart:UsingTaskNumberFields
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    // Set formula
    System::SharedPtr<ExtendedAttributeDefinition> attr = project->get_ExtendedAttributes()->idx_get(0);
    attr->set_Alias(u"Task number fields");
    attr->set_Formula(u"([Outline Level] + [Priority] + [% Complete])/2");
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    // Print extended attribute value before and after updating task percent complete
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_NumericValue());
    task->Set<int32_t>(Tsk::PercentComplete(), 50);
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_NumericValue());
    // ExEnd:UsingTaskNumberFields
}

System::SharedPtr<Project> UsingTaskNumberFields::CreateTestProjectWithCustomField()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->Set(Prj::StartDate(), System::DateTime(2015, 3, 6, 8, 0, 0));
    System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Number, Aspose::Tasks::ExtendedAttributeTask::Number1, u"Custom");
    project->get_ExtendedAttributes()->Add(attr);
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    System::SharedPtr<ExtendedAttribute> extendedAttribute = attr->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(extendedAttribute);
    return project;
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
