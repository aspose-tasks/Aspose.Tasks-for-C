/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "AddTaskExtendedAttributes.h"

#include <aspose.tasks.cpp/Value.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/nullable.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/enums/CustomFieldType.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1868768528u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::AddTaskExtendedAttributes, ThisTypeBaseTypesInfo);

void AddTaskExtendedAttributes::Run()
{
    try
    {
        // ExStart:AddTaskExtendedAttributes
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // Create new project
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        
        
        // C# preprocessor directive: #region Adding Plain Text Attribute
        
        //Create an Extended Attribute Definition of Text1 type
        auto taskExtendedAttributeText1Definition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text1, u"Task City Name");
        
        //Add it to the project's Extended Attributes collection
        project->get_ExtendedAttributes()->Add(taskExtendedAttributeText1Definition);
        
        //Add a task to the project
        auto task = project->get_RootTask()->get_Children()->Add(u"Task 1");
        
        //Create an Extended Attribute from the Attribute Definition
        auto taskExtendedAttributeText1 = taskExtendedAttributeText1Definition->CreateExtendedAttribute();
        
        //Assign a value to the generated Extended Attribute. The type of the attribute is "Text", the "TextValue" property should be used.
        taskExtendedAttributeText1->set_TextValue(u"London");
        
        //Add the Extended Attribute to task
        task->get_ExtendedAttributes()->Add(taskExtendedAttributeText1);
        
        project->Save(dataDir + u"PlainTextExtendedAttribute_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        
        // C# preprocessor directive: #endregion
        
        
        
        // C# preprocessor directive: #region Adding Text Attribute with Lookup option
        
        
        System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        
        //Create an Extended Attribute Definition of Text2 type
        auto taskExtendedAttributeText2Definition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text2, u"Task Towns Name");
        
        //Add lookup values for the extended attribute definition
        taskExtendedAttributeText2Definition->AddLookupValue([&]{ auto tmp_0 = System::MakeObject<Value>(); tmp_0->set_Id(1); tmp_0->set_StringValue(u"Town1"); tmp_0->set_Description(u"This is Town1"); return tmp_0; }());
        taskExtendedAttributeText2Definition->AddLookupValue([&]{ auto tmp_1 = System::MakeObject<Value>(); tmp_1->set_Id(2); tmp_1->set_StringValue(u"Town2"); tmp_1->set_Description(u"This is Town2"); return tmp_1; }());
        
        //Add it to the porject's Extended Attributes collection
        project1->get_ExtendedAttributes()->Add(taskExtendedAttributeText2Definition);
        
        //Add a task to the project
        auto task2 = project1->get_RootTask()->get_Children()->Add(u"Task 2");
        
        //Crate an Extended Attribute from the Text2 Lookup Definition for Id 1
        auto taskExtendedAttributeText2 = taskExtendedAttributeText2Definition->CreateExtendedAttribute(taskExtendedAttributeText2Definition->get_ValueList()->idx_get(1));
        
        //Add the Extended Attribute to task
        task2->get_ExtendedAttributes()->Add(taskExtendedAttributeText2);
        
        project1->Save(dataDir + u"TextExtendedAttributeWithLookup_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        
        // C# preprocessor directive: #endregion
        
        
        
        // C# preprocessor directive: #region Adding Duration Attribute with Lookup option
        
        
        System::SharedPtr<Project> project2 = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        
        //Create an Extended Attribute Definition of Duration2 type
        auto taskExtendedAttributeDuration2Definition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::CustomFieldType::Duration, Aspose::Tasks::ExtendedAttributeTask::Duration2, u"Some duration");
        
        //Add lookup values for extended attribute definition
        taskExtendedAttributeDuration2Definition->AddLookupValue([&]{ auto tmp_2 = System::MakeObject<Value>(); tmp_2->set_Id(2); tmp_2->set_Duration(project2->GetDuration(4, Aspose::Tasks::TimeUnitType::Hour)); tmp_2->set_Description(u"4 hours"); return tmp_2; }());
        taskExtendedAttributeDuration2Definition->AddLookupValue([&]{ auto tmp_3 = System::MakeObject<Value>(); tmp_3->set_Id(3); tmp_3->set_Duration(project2->GetDuration(1, Aspose::Tasks::TimeUnitType::Day)); tmp_3->set_Description(u"1 day"); return tmp_3; }());
        taskExtendedAttributeDuration2Definition->AddLookupValue([&]{ auto tmp_4 = System::MakeObject<Value>(); tmp_4->set_Id(4); tmp_4->set_Duration(project2->GetDuration(1, Aspose::Tasks::TimeUnitType::Hour)); tmp_4->set_Description(u"1 hour"); return tmp_4; }());
        taskExtendedAttributeDuration2Definition->AddLookupValue([&]{ auto tmp_5 = System::MakeObject<Value>(); tmp_5->set_Id(7); tmp_5->set_Duration(project2->GetDuration(10, Aspose::Tasks::TimeUnitType::Day)); tmp_5->set_Description(u"10 days"); return tmp_5; }());
        
        //Add the definition to the project's Extended Attributes collection
        project2->get_ExtendedAttributes()->Add(taskExtendedAttributeDuration2Definition);
        
        //Add a task to the project
        auto task3 = project2->get_RootTask()->get_Children()->Add(u"Task 3");
        
        //Create an Extended Attribute from the Duration2 Lookup Definition for Id 3
        auto taskExtendedAttributeDuration2 = taskExtendedAttributeDuration2Definition->CreateExtendedAttribute(taskExtendedAttributeDuration2Definition->get_ValueList()->idx_get(3));
        
        //Add the Extended Attribute to task
        task3->get_ExtendedAttributes()->Add(taskExtendedAttributeDuration2);
        
        project2->Save(dataDir + u"DurationExtendedAttributeWithLookup_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        
        
        // C# preprocessor directive: #endregion
        
        
        
        // C# preprocessor directive: #region Adding Date-Time with Lookup option
        
        
        System::SharedPtr<Project> project3 = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        
        //Create an Extended Attribute Definition of Finish2 Type
        auto taskExtendedAttributeFinish2Definition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::CustomFieldType::Finish, Aspose::Tasks::ExtendedAttributeTask::Finish2, u"Some finish");
        
        //Add lookup values for extended attribute defintion
        taskExtendedAttributeFinish2Definition->AddLookupValue([&]{ auto tmp_6 = System::MakeObject<Value>(); tmp_6->set_Id(2); tmp_6->set_DateTimeValue(System::DateTime(1984, 1, 1, 00, 00, 1)); tmp_6->set_Description(u"This is Value2"); return tmp_6; }());
        taskExtendedAttributeFinish2Definition->AddLookupValue([&]{ auto tmp_7 = System::MakeObject<Value>(); tmp_7->set_Id(3); tmp_7->set_DateTimeValue(System::DateTime(1994, 1, 1, 00, 1, 1)); tmp_7->set_Description(u"This is Value3"); return tmp_7; }());
        taskExtendedAttributeFinish2Definition->AddLookupValue([&]{ auto tmp_8 = System::MakeObject<Value>(); tmp_8->set_Id(4); tmp_8->set_DateTimeValue(System::DateTime(2009, 12, 31, 00, 00, 00)); tmp_8->set_Description(u"This is Value4"); return tmp_8; }());
        taskExtendedAttributeFinish2Definition->AddLookupValue([&]{ auto tmp_9 = System::MakeObject<Value>(); tmp_9->set_Id(7); tmp_9->set_DateTimeValue(System::DateTime::get_Now()); tmp_9->set_Description(u"This is Value6"); return tmp_9; }());
        
        //Add the definition to the project's Extended Attributes collection
        project3->get_ExtendedAttributes()->Add(taskExtendedAttributeFinish2Definition);
        
        //Add a task to the project
        auto task4 = project3->get_RootTask()->get_Children()->Add(u"Task 4");
        
        //Create an Extneded Attribute from the Finish2 Lookup Definition for Id 3
        auto taskExtendedAttributeFinish2 = taskExtendedAttributeFinish2Definition->CreateExtendedAttribute(taskExtendedAttributeFinish2Definition->get_ValueList()->idx_get(3));
        
        //Add the Extended Attribute to task
        task4->get_ExtendedAttributes()->Add(taskExtendedAttributeFinish2);
        
        // Save the Project               
        project3->Save(dataDir + u"FinishExtendedAttributeWithLookup_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        
        // C# preprocessor directive: #endregion
        
        
        
        // ExEnd:AddTaskExtendedAttributes
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
