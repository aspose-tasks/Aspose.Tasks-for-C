/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/UsingArithmeticExpression.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/decimal.h>
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

RTTI_INFO_IMPL_HASH(11805937u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::UsingArithmeticExpression, ThisTypeBaseTypesInfo);

void UsingArithmeticExpression::Run()
{
    // ExStart:UsingArithmeticExpression
    System::SharedPtr<Project> project = CreateTestProjectWithCustomField();
    
    // Set arithmetic formula for extended attribute
    System::SharedPtr<ExtendedAttributeDefinition> attr = project->get_ExtendedAttributes()->idx_get(0);
    attr->set_Alias(u"Arithmetic Expression");
    attr->set_Formula(u"(1+3*(2+ -5)+8/2)^3");
    
    // Display extended attribute value
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    System::Console::WriteLine(task->get_ExtendedAttributes()->idx_get(0)->get_NumericValue());
    // ExEnd:UsingArithmeticExpression
}

System::SharedPtr<Project> UsingArithmeticExpression::CreateTestProjectWithCustomField()
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
