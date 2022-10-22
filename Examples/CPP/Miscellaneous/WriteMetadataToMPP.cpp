/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WriteMetadataToMPP.h"

#include <WorkingTimeCollection.h>
#include <WorkingTime.h>
#include <WeekDayCollection.h>
#include <WeekDay.h>
#include <Tsk.h>
#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <Prj.h>
#include <NullableBool.h>
#include <Key.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <ExtendedAttributeCollection.h>
#include <ExtendedAttribute.h>
#include <enums/TimeUnitType.h>
#include <enums/TaskLinkType.h>
#include <enums/TaskKey.h>
#include <enums/RscKey.h>
#include <enums/ResourceType.h>
#include <enums/RateFormatType.h>
#include <enums/PrjKey.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/CustomFieldType.h>
#include <enums/CostAccrualType.h>
#include <enums/AsnKey.h>
#include <Duration.h>
#include <cstdint>
#include <Calendar.h>
#include <Asn.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(3374767811u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::WriteMetadataToMPP, ThisTypeBaseTypesInfo);

void WriteMetadataToMPP::Run()
{
    try
    {
        // ExStart:WriteMetadataToMPP
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project1.mpp");
        
        // Add working times to project calendar
        System::SharedPtr<WorkingTime> wt = System::MakeObject<WorkingTime>(System::DateTime(2010, 1, 1, 19, 0, 0), System::DateTime(2010, 1, 1, 20, 0, 0));
        System::SharedPtr<WeekDay> day = project->Get<System::SharedPtr<Calendar>>(Prj::Calendar())->get_WeekDays()->ToList()->idx_get(1);
        day->get_WorkingTimes()->Add(wt);
        
        // Change calendar name
        project->Get<System::SharedPtr<Calendar>>(Prj::Calendar())->set_Name(u"CHANGED NAME!");
        
        // Add tasks and set task meta data
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task 1");
        task->Set<TimeUnitType>(Tsk::DurationFormat(), Aspose::Tasks::TimeUnitType::Day);
        task->Set<Duration>(Tsk::Duration(), project->GetDuration(3));
        task->Set<System::String>(Tsk::Contact(), u"Rsc 1");
        task->Set<bool>(Tsk::IsMarked(), true);
        task->Set<bool>(Tsk::IgnoreWarnings(), true);
        System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->Add(u"Task 2");
        task2->Set<TimeUnitType>(Tsk::DurationFormat(), Aspose::Tasks::TimeUnitType::Day);
        task2->Set<System::String>(Tsk::Contact(), u"Rsc 2");
        
        // Link tasks
        project->get_TaskLinks()->Add(task, task2, Aspose::Tasks::TaskLinkType::FinishToStart, project->GetDuration(-1, Aspose::Tasks::TimeUnitType::Day));
        
        // Set project start date
        project->Set(Prj::StartDate(), System::DateTime(2013, 8, 13, 9, 0, 0));
        
        // Add resource and set resource meta data
        System::SharedPtr<Resource> rsc1 = project->get_Resources()->Add(u"Rsc 1");
        rsc1->Set<ResourceType>(Rsc::Type(), Aspose::Tasks::ResourceType::Work);
        rsc1->Set<System::String>(Rsc::Initials(), u"WR");
        rsc1->Set<CostAccrualType>(Rsc::AccrueAt(), Aspose::Tasks::CostAccrualType::Prorated);
        rsc1->Set<double>(Rsc::MaxUnits(), 1.0);
        rsc1->Set<System::String>(Rsc::Code(), u"Code 1");
        rsc1->Set<System::String>(Rsc::Group(), u"Workers");
        rsc1->Set<System::String>(Rsc::EMailAddress(), u"1@gmail.com");
        rsc1->Set<System::String>(Rsc::WindowsUserAccount(), u"user_acc1");
        rsc1->Set<NullableBool>(Rsc::IsGeneric(), NullableBool(true));
        rsc1->Set<CostAccrualType>(Rsc::AccrueAt(), Aspose::Tasks::CostAccrualType::End);
        rsc1->Set<System::Decimal>(Rsc::StandardRate(), static_cast<System::Decimal>(10));
        rsc1->Set<RateFormatType>(Rsc::StandardRateFormat(), Aspose::Tasks::RateFormatType::Day);
        rsc1->Set<System::Decimal>(Rsc::OvertimeRate(), static_cast<System::Decimal>(15));
        rsc1->Set<RateFormatType>(Rsc::OvertimeRateFormat(), Aspose::Tasks::RateFormatType::Hour);
        
        rsc1->Set<bool>(Rsc::IsTeamAssignmentPool(), true);
        rsc1->Set<System::String>(Rsc::CostCenter(), u"Cost Center 1");
        
        // Create resource assignment and set resource assignment meta data
        System::SharedPtr<ResourceAssignment> assn = project->get_ResourceAssignments()->Add(task, rsc1);
        assn->Set<int32_t>(Asn::Uid(), 1);
        assn->Set<Duration>(Asn::Work(), task->Get<Duration>(Tsk::Duration()));
        assn->Set<Duration>(Asn::RemainingWork(), assn->Get<Duration>(Asn::Work()));
        assn->Set<Duration>(Asn::RegularWork(), assn->Get<Duration>(Asn::Work()));
        task->Set<Duration>(Tsk::Work(), assn->Get<Duration>(Asn::Work()));
        
        rsc1->Set<Duration>(Rsc::Work(), task->Get<Duration>(Tsk::Work()));
        assn->Set(Asn::Start(), task->Get<System::DateTime>(Tsk::Start()));
        assn->Set(Asn::Finish(), task->Get<System::DateTime>(Tsk::Finish()));
        
        // Add extended attribute for project and task
        System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Flag, Aspose::Tasks::ExtendedAttributeTask::Flag1, u"My Flag Field");
        project->get_ExtendedAttributes()->Add(attr);
        
        System::SharedPtr<ExtendedAttribute> taskAttr = attr->CreateExtendedAttribute();
        taskAttr->set_FlagValue(true);
        task2->get_ExtendedAttributes()->Add(taskAttr);
        
        // Save project as MPP
        project->Save(dataDir + u"WriteMetaData_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:WriteMetadataToMPP
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
