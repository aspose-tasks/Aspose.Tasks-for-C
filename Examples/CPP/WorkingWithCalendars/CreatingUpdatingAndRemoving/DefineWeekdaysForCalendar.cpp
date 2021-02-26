/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "DefineWeekdaysForCalendar.h"

#include <WorkingTimeCollection.h>
#include <WorkingTime.h>
#include <WeekDayCollection.h>
#include <WeekDay.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <enums/DayType.h>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

namespace CreatingUpdatingAndRemoving {

RTTI_INFO_IMPL_HASH(1186780245u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving::DefineWeekdaysForCalendar, ThisTypeBaseTypesInfo);

void DefineWeekdaysForCalendar::Run()
{
    // ExStart:DefineWeekdaysForCalendar
    // This example shows how Aspose.Tasks API can be used to define a new Calendar, add week days to it and define working times for days
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Define Calendar
    System::SharedPtr<Aspose::Tasks::Calendar> cal = project->get_Calendars()->Add(u"Calendar1");
    
    // Add working days monday through thursday with default timings
    cal->get_WeekDays()->Add(WeekDay::CreateDefaultWorkingDay(Aspose::Tasks::DayType::Monday));
    cal->get_WeekDays()->Add(WeekDay::CreateDefaultWorkingDay(Aspose::Tasks::DayType::Tuesday));
    cal->get_WeekDays()->Add(WeekDay::CreateDefaultWorkingDay(Aspose::Tasks::DayType::Wednesday));
    cal->get_WeekDays()->Add(WeekDay::CreateDefaultWorkingDay(Aspose::Tasks::DayType::Thursday));
    cal->get_WeekDays()->Add(System::MakeObject<WeekDay>(Aspose::Tasks::DayType::Saturday));
    cal->get_WeekDays()->Add(System::MakeObject<WeekDay>(Aspose::Tasks::DayType::Sunday));
    
    // Set friday as short working day
    System::SharedPtr<WeekDay> myWeekDay = System::MakeObject<WeekDay>(Aspose::Tasks::DayType::Friday);
    
    // Sets working time. Only time part of DateTime is important
    System::SharedPtr<WorkingTime> wt1 = System::MakeObject<WorkingTime>();
    wt1->set_FromTime(System::DateTime(1, 1, 1, 9, 0, 0, 0));
    wt1->set_ToTime(System::DateTime(1, 1, 1, 12, 0, 0, 0));
    System::SharedPtr<WorkingTime> wt2 = System::MakeObject<WorkingTime>();
    wt2->set_FromTime(System::DateTime(1, 1, 1, 13, 0, 0, 0));
    wt2->set_ToTime(System::DateTime(1, 1, 1, 16, 0, 0, 0));
    myWeekDay->get_WorkingTimes()->Add(wt1);
    myWeekDay->get_WorkingTimes()->Add(wt2);
    myWeekDay->set_DayWorking(true);
    cal->get_WeekDays()->Add(myWeekDay);
    
    // Save the Project
    System::String dataDir = Examples::CPP::RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project->Save(dataDir + u"Project_DefineCalendarWeekdays_out.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
    // ExEnd:DefineWeekdaysForCalendar
}

} // namespace CreatingUpdatingAndRemoving
} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
