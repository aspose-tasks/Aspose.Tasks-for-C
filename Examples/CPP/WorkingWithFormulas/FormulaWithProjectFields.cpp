/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/FormulaWithProjectFields.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/enums/CustomFieldType.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(4037105883u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::FormulaWithProjectFields, ThisTypeBaseTypesInfo);

void FormulaWithProjectFields::Run()
{
	// ExStart:FormulaWithProjectFields
    System::SharedPtr<Project> project = CreateTestProjectWithCustomFieldWithoutResource();
    
    // Set formula
    project->get_ExtendedAttributes()->idx_get(0)->set_Formula(u"\"Total tasks: \" & [Task Count] & \" Total resources: \" & [Resource Count]");
    
    // Print if formula value is computed correctly
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(u"Check Total tasks: 1 Total resources: 0 - {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task->get_ExtendedAttributes()->idx_get(0)->get_TextValue(), u"Total tasks: 1 Total resources: 0")));
	// ExEnd:FormulaWithProjectFields
}

System::SharedPtr<Project> FormulaWithProjectFields::CreateTestProjectWithCustomFieldWithoutResource()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->Set(Prj::StartDate(), System::DateTime(2015, 3, 6, 8, 0, 0));
    System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text1, u"Custom");
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
