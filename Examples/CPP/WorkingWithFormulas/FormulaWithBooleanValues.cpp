/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/FormulaWithBooleanValues.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/PrjKey.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/CustomFieldType.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(1055388019u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::FormulaWithBooleanValues, ThisTypeBaseTypesInfo);

void FormulaWithBooleanValues::Run()
{
    // ExStart:FormulaWithBooleanValues
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    // Set formula for extended attribute
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"[Critical]-[Marked]+4+[Active]-Not [Active]");
    
    // Print value of extened attribute
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(System::String(u"Formula with boolean values: ") + task->get_ExtendedAttributes()->idx_get(0)->get_TextValue());
    // ExEnd:FormulaWithBooleanValues
}

System::SharedPtr<Project> FormulaWithBooleanValues::CreateTestProjectWithCustomField()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->Set(Prj::StartDate(), System::DateTime(2015, 3, 6, 8, 0, 0));
    System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text1, u"Custom Field");
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
