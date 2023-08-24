#include "CalculateDateTimeFunctions.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/Duration.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(3366688527u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::CalculateDateTimeFunctions, ThisTypeBaseTypesInfo);

void CalculateDateTimeFunctions::Run()
{
    // ExStart:CalculateDateTimeFunctions
    System::SharedPtr<Project> project = CreateTestProject();
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    System::SharedPtr<ExtendedAttributeDefinition> numberDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Number1, nullptr);
    project->get_ExtendedAttributes()->Add(numberDefinition);
    
    System::SharedPtr<ExtendedAttribute> numberAttribute = numberDefinition->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(numberAttribute);
    
    // Set ProjDateDiff formula and print extended attribute value
    numberDefinition->set_Formula(u"ProjDateDiff(\"03/23/2015\",\"03/18/2015\")");
    System::Console::WriteLine(numberAttribute->get_NumericValue());
    numberDefinition->set_Formula(u"ProjDateDiff(\"03/23/2015\",\"03/25/2015\")");
    System::Console::WriteLine(numberAttribute->get_NumericValue());
    
    System::SharedPtr<ExtendedAttributeDefinition> dateDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Date1, nullptr);
    project->get_ExtendedAttributes()->Add(dateDefinition);
    System::SharedPtr<ExtendedAttribute> dateAttribute = dateDefinition->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(dateAttribute);
    
    System::SharedPtr<ExtendedAttributeDefinition> durationDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Duration4, u"Custom duration field");
    project->get_ExtendedAttributes()->Add(durationDefinition);
    System::SharedPtr<ExtendedAttribute> durationAttribute = durationDefinition->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(durationAttribute);
    
    System::SharedPtr<ExtendedAttributeDefinition> textDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Text5, u"Custom text field");
    project->get_ExtendedAttributes()->Add(textDefinition);
    System::SharedPtr<ExtendedAttribute> textAttribute = textDefinition->CreateExtendedAttribute();
    task->get_ExtendedAttributes()->Add(textAttribute);
    
    // Set ProjDateSub formula and print extended attribute value
    dateDefinition->set_Formula(u"ProjDateSub(\"3/19/2015\", \"1d\")");
    System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(dateAttribute->get_DateValue()));
    
    // We can set ProjDurConv formula to duration-valued attribute as well as to text-valued attribute.
    
    // Set ProjDurConv formula to duration-valued extended attribute and print its value.
    durationDefinition->set_Formula(u"ProjDurConv([Duration], pjHours)");
    System::Console::WriteLine(System::ObjectExt::Box<Duration>(durationAttribute->get_DurationValue()));
    
    // Set ProjDurConv formula to text-valued extended attribute and print its value.
    textDefinition->set_Formula(u"ProjDurConv([Duration], pjHours)");
    System::Console::WriteLine(textAttribute->get_TextValue());
    
    textDefinition->set_Formula(u"ProjDurConv([Duration], pjWeeks)");
    System::Console::WriteLine(textAttribute->get_TextValue());
    
    // Set Second formula and print entended attribute value
    numberDefinition->set_Formula(u"Second(\"4/21/2015 2:53:41 AM\")");
    System::Console::WriteLine(numberAttribute->get_NumericValue());
    
    // Set Weekday formula and print entended attribute value
    numberDefinition->set_Formula(u"Weekday(\"24/3/2015\", 1)");
    System::Console::WriteLine(numberAttribute->get_NumericValue());
    numberDefinition->set_Formula(u"Weekday(\"24/3/2015\", 2)");
    System::Console::WriteLine(numberAttribute->get_NumericValue());
    numberDefinition->set_Formula(u"Weekday(\"24/3/2015\", 3)");
    System::Console::WriteLine(numberAttribute->get_NumericValue());
    // ExEnd:CalculateDateTimeFunctions
}

System::SharedPtr<Project> CalculateDateTimeFunctions::CreateTestProject()
{
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->get_RootTask()->get_Children()->Add(u"Task");
    return project;
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
