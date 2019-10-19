#include "AddRemoveCalendarExceptions.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/details/dispose_guard.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
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

RTTI_INFO_IMPL_HASH(1034431325u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendarExceptions::AddRemoveCalendarExceptions, ThisTypeBaseTypesInfo);

// Using statement is translated using System::Details::DisposeGuard class which may store exception and then throw from destructor.
// We block the warnings related as these are false alarms (the exception, if caught, will be re-thrown from the destructor).
#if defined(__MSVC__)
#pragma warning( push )
#pragma warning(disable : 4715)
#pragma warning(disable : 4700)
#pragma warning(disable : 4701)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#endif
void AddRemoveCalendarExceptions::Run()
{
    // ExStart:AddRemoveCalendarExceptions
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    {
        System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(dataDir + u"project_test.mpp", System::IO::FileMode::Open);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ fs});
        // ------------------------------------------
        
        try
        {
            // Create project instance
            System::SharedPtr<Project> prj = System::MakeObject<Project>(fs);
            
            // Remove an exception
            System::SharedPtr<Aspose::Tasks::Calendar> cal = prj->get_Calendars()->ToList()->idx_get(0);
            if (cal->get_Exceptions()->get_Count() > 1)
            {
                System::SharedPtr<CalendarException> exc = cal->get_Exceptions()->ToList()->idx_get(0);
                cal->get_Exceptions()->Remove(exc);
            }
            
            // Add an exception
            System::SharedPtr<CalendarException> calExc = System::MakeObject<CalendarException>();
            calExc->set_FromDate(System::DateTime(2009, 1, 1));
            calExc->set_ToDate(System::DateTime(2009, 1, 3));
            cal->get_Exceptions()->Add(calExc);
            
            // Display exceptions
            
            {
                auto calExc1_enumerator = (cal->get_Exceptions())->GetEnumerator();
                decltype(calExc1_enumerator->get_Current()) calExc1;
                while (calExc1_enumerator->MoveNext() && (calExc1 = calExc1_enumerator->get_Current(), true))
                {
                    System::Console::WriteLine(System::String(u"From") + calExc1->get_FromDate().ToShortDateString());
                    System::Console::WriteLine(System::String(u"To") + calExc1->get_ToDate().ToShortDateString());
                }
            }
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:AddRemoveCalendarExceptions
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

} // namespace WorkingWithCalendarExceptions
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
