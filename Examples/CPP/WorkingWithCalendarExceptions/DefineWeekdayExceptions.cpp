#include "DefineWeekdayExceptions.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <enums/CalendarExceptionType.h>
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

RTTI_INFO_IMPL_HASH(4268649607u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendarExceptions::DefineWeekdayExceptions, ThisTypeBaseTypesInfo);

void DefineWeekdayExceptions::Run()
{
    // ExStart:DefineWeekdayExceptions
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance
    System::SharedPtr<Project> prj = System::MakeObject<Project>();
    
    // Define Calendar
    System::SharedPtr<Aspose::Tasks::Calendar> cal = prj->get_Calendars()->Add(u"Calendar1");
    
    // Define week days exception for a holiday
    System::SharedPtr<CalendarException> except = System::MakeObject<CalendarException>();
    except->set_EnteredByOccurrences(false);
    except->set_FromDate(System::DateTime(2009, 12, 24, 0, 0, 0));
    except->set_ToDate(System::DateTime(2009, 12, 31, 23, 59, 0));
    except->set_Type(Aspose::Tasks::CalendarExceptionType::Daily);
    except->set_DayWorking(false);
    cal->get_Exceptions()->Add(except);
    
    // Save the Project
    prj->Save(dataDir + u"Project_DefineWeekDayException_out.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
    // ExEnd:DefineWeekdayExceptions
    
}

} // namespace WorkingWithCalendarExceptions
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
