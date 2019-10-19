#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/ReplaceCalendar.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

namespace CreatingUpdatingAndRemoving {

RTTI_INFO_IMPL_HASH(1933825542u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving::ReplaceCalendar, ThisTypeBaseTypesInfo);

void ReplaceCalendar::Run()
{
    // ExStart:ReplaceCalendar
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReplaceCalendar.mpp");
    
    // Add a new calendar to the project's calendars collection
    project->get_Calendars()->Add(u"New cal1", project->Get<System::SharedPtr<Calendar>>(Prj::Calendar()));
    
    // Now traverse through project calendars and replace the already added calendar with a new one
    System::SharedPtr<CalendarCollection> calColl = project->get_Calendars();
    
    
    {
        auto c_enumerator = (calColl)->GetEnumerator();
        decltype(c_enumerator->get_Current()) c;
        while (c_enumerator->MoveNext() && (c = c_enumerator->get_Current(), true))
        {
            if (c->get_Name() == u"New cal1")
            {
                calColl->Remove(c);
                calColl->Add(u"New cal2", project->Get<System::SharedPtr<Calendar>>(Prj::Calendar()));
                break;
            }
        }
    }
    // ExEnd:ReplaceCalendar            
}

} // namespace CreatingUpdatingAndRemoving
} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
