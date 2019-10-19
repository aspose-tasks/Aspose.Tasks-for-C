/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadWorkWeeksInformation.h"

#include <WorkWeekCollection.h>
#include <WorkWeek.h>
#include <WorkingTimeCollection.h>
#include <WeekDayCollection.h>
#include <WeekDay.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

RTTI_INFO_IMPL_HASH(2924610081u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::ReadWorkWeeksInformation, ThisTypeBaseTypesInfo);

void ReadWorkWeeksInformation::Run()
{
    // ExStart:ReadWorkWeeksInformation       
    System::String dataDir = Examples::CPP::RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance and access calendar and work weeks collection
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadWorkWeeksInformation.mpp");
    System::SharedPtr<Calendar> calendar = project->get_Calendars()->GetByUid(3);
    System::SharedPtr<WorkWeekCollection> collection = calendar->get_WorkWeeks();
    
    
    {
        auto workWeek_enumerator = (collection)->GetEnumerator();
        decltype(workWeek_enumerator->get_Current()) workWeek;
        while (workWeek_enumerator->MoveNext() && (workWeek = workWeek_enumerator->get_Current(), true))
        {
            // Display work week name, from and to dates
            System::String Name = workWeek->get_Name();
            System::DateTime fromDate = workWeek->get_FromDate();
            System::DateTime toDate = workWeek->get_ToDate();
            
            // This data is all about "Details." button you can set special working times for special WeekDay or even make it nonworking
            System::SharedPtr<WeekDayCollection> weekDays = workWeek->get_WeekDays();
            
            {
                auto day_enumerator = (weekDays)->GetEnumerator();
                decltype(day_enumerator->get_Current()) day;
                while (day_enumerator->MoveNext() && (day = day_enumerator->get_Current(), true))
                {
                    // You can further traverse through working times and display these
                    System::SharedPtr<WorkingTimeCollection> workingTimes = day->get_WorkingTimes();
                }
            }
        }
    }
    // ExEnd:ReadWorkWeeksInformation
}

} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
