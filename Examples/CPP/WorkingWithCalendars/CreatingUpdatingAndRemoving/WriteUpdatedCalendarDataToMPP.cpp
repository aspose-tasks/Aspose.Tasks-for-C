/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WriteUpdatedCalendarDataToMPP.h"

#include <WorkingTimeCollection.h>
#include <WorkingTime.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <CalendarExceptionCollection.h>
#include <CalendarException.h>
#include <CalendarCollection.h>
#include <Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks;
using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

namespace CreatingUpdatingAndRemoving {

RTTI_INFO_IMPL_HASH(444529282u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving::WriteUpdatedCalendarDataToMPP, ThisTypeBaseTypesInfo);

void WriteUpdatedCalendarDataToMPP::Run()
{
    // ExStart:WriteUpdatedCalendarDataToMPP
    System::String resultFile = u"result_WriteUpdatedCalendarDataToMPP_out.mpp";
    System::String newFile = u"project_update_test.mpp";
    System::String dataDir = Examples::CPP::RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    try
    {
        // Create project instance and access calendar
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + newFile);
        System::SharedPtr<Calendar> cal = project->get_Calendars()->GetByUid(3);
        
        // Update the calendar information
        Calendar::MakeStandardCalendar(cal);
        cal->set_Name(u"Test calendar");
        System::SharedPtr<CalendarException> exc = System::MakeObject<CalendarException>();
        exc->set_FromDate(System::DateTime::get_Now());
        exc->set_ToDate(System::DateTime::get_Now().AddDays(2));
        exc->set_DayWorking(true);
        
        System::SharedPtr<WorkingTime> wt1 = System::MakeObject<WorkingTime>(System::DateTime(10, 1, 1, 9, 0, 0), System::DateTime(10, 1, 1, 13, 0, 0));
        
        System::SharedPtr<WorkingTime> wt2 = System::MakeObject<WorkingTime>(System::DateTime(10, 1, 1, 14, 0, 0), System::DateTime(10, 1, 1, 19, 0, 0));
        
        System::SharedPtr<WorkingTime> wt3 = System::MakeObject<WorkingTime>(System::DateTime(10, 1, 1, 20, 0, 0), System::DateTime(10, 1, 1, 21, 0, 0));
        
        exc->get_WorkingTimes()->Add(wt1);
        exc->get_WorkingTimes()->Add(wt2);
        exc->get_WorkingTimes()->Add(wt3);
        cal->get_Exceptions()->Add(exc);
        
        System::SharedPtr<CalendarException> exc2 = System::MakeObject<CalendarException>();
        exc2->set_FromDate(System::DateTime::get_Now().AddDays(7));
        exc2->set_ToDate(exc2->get_FromDate());
        exc2->set_DayWorking(false);
        cal->get_Exceptions()->Add(exc2);
        
        project->Set<System::SharedPtr<Calendar>>(Prj::Calendar(), cal);
        
        // Save project
        project->Save(dataDir + resultFile, Aspose::Tasks::Saving::SaveFileFormat::Mpp);
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:WriteUpdatedCalendarDataToMPP
}

} // namespace CreatingUpdatingAndRemoving
} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
