#include "HandleExceptionOccurences.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <enums/CalendarExceptionType.h>
#include <cstdint>
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

RTTI_INFO_IMPL_HASH(743188025u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendarExceptions::HandleExceptionOccurences, ThisTypeBaseTypesInfo);

void HandleExceptionOccurences::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    
    // Define Calendar
    System::SharedPtr<Aspose::Tasks::Calendar> cal = project1->get_Calendars()->Add(u"Calendar1");
    
    // ExStart:HandleExceptionOccurences
    // Define exception and specify occurences
    System::SharedPtr<CalendarException> except = System::MakeObject<CalendarException>();
    except->set_EnteredByOccurrences(true);
    except->set_Occurrences(5);
    except->set_Type(Aspose::Tasks::CalendarExceptionType::YearlyByDay);
    // ExEnd:HandleExceptionOccurences
    
    // Add exception to calendar and save the Project
    // cal->get_Exceptions()->Add(except);
    project1->Save(dataDir + u"Project_HandleExceptionOccurences_out.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
}

} // namespace WorkingWithCalendarExceptions
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
