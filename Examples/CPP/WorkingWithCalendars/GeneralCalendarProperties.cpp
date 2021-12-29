/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "GeneralCalendarProperties.h"

#include <WeekDayCollection.h>
#include <WeekDay.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <enums/DayType.h>
#include <cstdint>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

RTTI_INFO_IMPL_HASH(2209426892u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::GeneralCalendarProperties, ThisTypeBaseTypesInfo);

void GeneralCalendarProperties::Run()
{
    // ExStart:ReadCalendarProps            
    // Load an existing project
    System::String dataDir = Examples::CPP::RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project_GeneralCalendarProperties.xml");
    
    
    {
        auto cal_enumerator = (project->get_Calendars())->GetEnumerator();
        while (cal_enumerator->MoveNext())
        {
            auto&& cal = cal_enumerator->get_Current();
            if (cal->get_Name() != nullptr)
            {
                System::Console::WriteLine(System::String(u"UID : ") + System::Convert::ToString(cal->get_Uid()) + u" Name: " + cal->get_Name());
                
                // Show if it is has a base calendar
                System::Console::Write(u"Base Calendar : ");
                if (cal->get_IsBaseCalendar())
                {
                    System::Console::WriteLine(u"Self");
                }
                else
                {
                    System::Console::WriteLine(cal->get_BaseCalendar()->get_Name());
                }
                
                // Get Time in hours on each working day
                
                {
                    auto wd_enumerator = (cal->get_WeekDays())->GetEnumerator();
                    while (wd_enumerator->MoveNext())
                    {
                        auto&& wd = wd_enumerator->get_Current();
                        System::TimeSpan ts = wd->GetWorkingTime();
                        System::Console::WriteLine(System::String(u"Day Type: ") + System::ObjectExt::ToString(wd->get_DayType()) + u" Hours: " + System::ObjectExt::ToString(ts));
                    }
                }
            }
        }
    }
    // ExEnd:ReadCalendarProps
}

} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
