#include "RetrieveCalendarExceptions.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <CalendarExceptionCollection.h>
#include <CalendarException.h>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendarExceptions {

RTTI_INFO_IMPL_HASH(399123240u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendarExceptions::RetrieveCalendarExceptions, ThisTypeBaseTypesInfo);

void RetrieveCalendarExceptions::Run()
{
    // ExStart:RetrieveCalendarExceptions
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"project_RetrieveExceptions_test.mpp");
    
    // Access calendars
    
    {
        auto cal_enumerator = (project1->get_Calendars())->GetEnumerator();
        decltype(cal_enumerator->get_Current()) cal;
        while (cal_enumerator->MoveNext() && (cal = cal_enumerator->get_Current(), true))
        {
            // Access calendar exceptions
            auto calExc_enumerator = (cal->get_Exceptions())->GetEnumerator();
            decltype(calExc_enumerator->get_Current()) calExc;
            while (calExc_enumerator->MoveNext() && (calExc = calExc_enumerator->get_Current(), true))
            {
                System::Console::WriteLine(System::String(u"From: ") + calExc->get_FromDate().ToShortDateString());
                System::Console::WriteLine(System::String(u"To: ") + calExc->get_ToDate().ToShortDateString());
            }
        }
    }
    // ExEnd:RetrieveCalendarExceptions
}

} // namespace WorkingWithCalendarExceptions
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
