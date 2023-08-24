/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithExtendedAttributes/WriteUpdatedExtendedAttributeDefinitions.h"

#include <aspose.tasks.cpp/Value.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/MPPSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeResource.h>
#include <aspose.tasks.cpp/enums/ElementType.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithExtendedAttributes {

RTTI_INFO_IMPL_HASH(3026620222u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithExtendedAttributes::WriteUpdatedExtendedAttributeDefinitions, ThisTypeBaseTypesInfo);

void WriteUpdatedExtendedAttributeDefinitions::Run()
{
    // This example requires Aspose.Task for .NET, a trial version can be download from  http://www.aspose.com/corporate/purchase/temporary-license.aspx
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:WriteUpdatedExtendedAttributeDefinitions
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"WriteUpdatedExtendedAttributeDefinitions.mpp");
        
        
        // C# preprocessor directive: #region task attributes
        
        
        // Add new text3 extended attribute with lookup and one lookup value
        System::SharedPtr<ExtendedAttributeDefinition> taskTextAttributeDefinition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Text3, u"New text3 attribute");
        taskTextAttributeDefinition->set_ElementType(Aspose::Tasks::ElementType::Task);
        project->get_ExtendedAttributes()->Add(taskTextAttributeDefinition);
        
        System::SharedPtr<Value> textVal = System::MakeObject<Value>();
        textVal->set_Id(1);
        textVal->set_Description(u"Text value descr");
        textVal->set_Val(u"Text value1");
        
        taskTextAttributeDefinition->AddLookupValue(textVal);
        
        // Add new cost1 extended attribute with lookup and two cost values
        System::SharedPtr<ExtendedAttributeDefinition> taskCostAttributeDefinition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Cost1, u"New cost1 attribute");
        project->get_ExtendedAttributes()->Add(taskCostAttributeDefinition);
        
        System::SharedPtr<Value> costVal1 = System::MakeObject<Value>();
        costVal1->set_Id(2);
        costVal1->set_Description(u"Cost value 1 descr");
        costVal1->set_Val(u"99900");
        
        System::SharedPtr<Value> costVal2 = System::MakeObject<Value>();
        costVal2->set_Id(3);
        costVal2->set_Description(u"Cost value 2 descr");
        costVal2->set_Val(u"11100");
        
        taskCostAttributeDefinition->AddLookupValue(costVal1);
        taskCostAttributeDefinition->AddLookupValue(costVal2);
        
        // Add new task and assign attribute lookup value.
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"New task");
        
        System::SharedPtr<ExtendedAttribute> taskAttr = taskCostAttributeDefinition->CreateExtendedAttribute(costVal1);
        task->get_ExtendedAttributes()->Add(taskAttr);
        
        System::SharedPtr<ExtendedAttributeDefinition> taskStartAttributeDefinition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Start7, u"New start 7 attribute");
        
        System::SharedPtr<Value> startVal = System::MakeObject<Value>();
        startVal->set_Id(4);
        startVal->set_DateTimeValue(System::DateTime::get_Now());
        startVal->set_Description(u"Start 7 value description");
        
        taskStartAttributeDefinition->AddLookupValue(startVal);
        
        project->get_ExtendedAttributes()->Add(taskStartAttributeDefinition);
        
        System::SharedPtr<ExtendedAttributeDefinition> taskFinishAttributeDefinition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Finish4, u"New finish 4 attribute");
        
        System::SharedPtr<Value> finishVal = System::MakeObject<Value>();
        finishVal->set_Id(5);
        finishVal->set_DateTimeValue(System::DateTime::get_Now());
        finishVal->set_Description(u"Finish 4 value description");
        
        taskFinishAttributeDefinition->get_ValueList()->Add(finishVal);
        
        project->get_ExtendedAttributes()->Add(taskFinishAttributeDefinition);
        
        System::SharedPtr<ExtendedAttributeDefinition> numberAttributeDefinition = ExtendedAttributeDefinition::CreateLookupTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Number20, u"New number attribute");
        
        System::SharedPtr<Value> val1 = System::MakeObject<Value>();
        val1->set_Id(6);
        val1->set_Val(u"1");
        val1->set_Description(u"Number 1 value");
        System::SharedPtr<Value> val2 = System::MakeObject<Value>();
        val2->set_Id(7);
        val2->set_Val(u"2");
        val2->set_Description(u"Number 2 value");
        System::SharedPtr<Value> val3 = System::MakeObject<Value>();
        val2->set_Id(8);
        val3->set_Val(u"3");
        val3->set_Description(u"Number 3 value");
        
        numberAttributeDefinition->AddLookupValue(val1);
        numberAttributeDefinition->AddLookupValue(val2);
        numberAttributeDefinition->AddLookupValue(val3);
        
        project->get_ExtendedAttributes()->Add(numberAttributeDefinition);
        
        
        // C# preprocessor directive: #endregion
        
        
        System::SharedPtr<ExtendedAttributeDefinition> rscStartAttributeDefinition = ExtendedAttributeDefinition::CreateLookupResourceDefinition(Aspose::Tasks::ExtendedAttributeResource::Start5, u"New start5 attribute");
        
        System::SharedPtr<Value> startVal2 = System::MakeObject<Value>();
        startVal2->set_Id(9);
        startVal2->set_DateTimeValue(System::DateTime::get_Now());
        startVal2->set_Description(u"this is start5 value descr");
        
        rscStartAttributeDefinition->AddLookupValue(startVal2);
        
        project->get_ExtendedAttributes()->Add(rscStartAttributeDefinition);
        
        // Define a duration attribute without lookup.
        System::SharedPtr<ExtendedAttributeDefinition> taskDurationAttributeDefinition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Duration1, u"New Duration");
        project->get_ExtendedAttributes()->Add(taskDurationAttributeDefinition);
        
        // Add new task and assign duration value to the previously defined duration attribute.
        System::SharedPtr<Task> timeTask = project->get_RootTask()->get_Children()->Add(u"New task");
        
        System::SharedPtr<ExtendedAttribute> durationExtendedAttribute = taskDurationAttributeDefinition->CreateExtendedAttribute();
        
        durationExtendedAttribute->set_DurationValue(project->GetDuration(3.0, Aspose::Tasks::TimeUnitType::Hour));
        timeTask->get_ExtendedAttributes()->Add(durationExtendedAttribute);
        
        System::SharedPtr<MPPSaveOptions> mppSaveOptions = System::MakeObject<MPPSaveOptions>();
        mppSaveOptions->set_WriteViewData(true);
        
        // Save the project as MPP project file
        project->Save(dataDir + u"WriteUpdatedExtendedAttributeDefinitions_out.mpp", mppSaveOptions);
        // ExEnd:WriteUpdatedExtendedAttributeDefinitions
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
    
}

} // namespace WorkingWithExtendedAttributes
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
