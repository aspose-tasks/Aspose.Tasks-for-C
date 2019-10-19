#include "CreateRecurringTask.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/date_time.h>
#include <system/console.h>
#include <recurring/weeks/WeeklyRepetitionBase.h>
#include <recurring/weeks/WeeklyRepetition.h>
#include <recurring/weeks/WeeklyRecurrencePattern.h>
#include <recurring/RecurringTaskParameters.h>
#include <recurring/RecurrenceRangeBase.h>
#include <recurring/RecurrencePatternBase.h>
#include <recurring/EndByRecurrenceRange.h>
#include <Project.h>
#include <enums/WeekdayType.h>
#include <enums/TimeUnitType.h>
#include <Duration.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3410270624u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::CreateRecurringTask, ThisTypeBaseTypesInfo);

void CreateRecurringTask::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:CreateRecurringTask
        // Create project instance
        auto project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        auto parameters = [&]{ auto tmp_0 = System::MakeObject<RecurringTaskParameters>(); tmp_0->set_TaskName(u"Recurring task"); tmp_0->set_Duration(project->GetDuration(1, Aspose::Tasks::TimeUnitType::Day)); tmp_0->set_RecurrencePattern([&]{ auto tmp_1 = System::MakeObject<WeeklyRecurrencePattern>(); tmp_1->set_Repetition([&]{ auto tmp_2 = System::MakeObject<WeeklyRepetition>(); tmp_2->set_RepetitionInterval(2); tmp_2->set_WeekDays(Aspose::Tasks::WeekdayType::Sunday | Aspose::Tasks::WeekdayType::Monday | Aspose::Tasks::WeekdayType::Friday); return tmp_2; }()); tmp_1->set_RecurrenceRange([&]{ auto tmp_3 = System::MakeObject<EndByRecurrenceRange>(); tmp_3->set_Start(System::DateTime(2018, 7, 1, 8, 0, 0)); tmp_3->set_Finish(System::DateTime(2018, 7, 20, 17, 0, 0)); return tmp_3; }()); return tmp_1; }()); return tmp_0; }();
        project->get_RootTask()->get_Children()->Add(parameters);
        // ExEnd:CreateRecurringTask
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
