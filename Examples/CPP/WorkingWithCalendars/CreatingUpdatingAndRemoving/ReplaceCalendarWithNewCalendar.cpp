/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/ReplaceCalendarWithNewCalendar.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/CalendarCollection.h>
#include <aspose.tasks.cpp/Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

namespace CreatingUpdatingAndRemoving {

RTTI_INFO_IMPL_HASH(3541174386u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving::ReplaceCalendarWithNewCalendar, ThisTypeBaseTypesInfo);

void ReplaceCalendarWithNewCalendar::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:ReplaceCalendarWithNewCalendar
        // Create project
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project5.mpp");
        
        // Access project calendars
        System::SharedPtr<CalendarCollection> calColl = project->get_Calendars();
        calColl->Remove(calColl->GetByName(u"TestCalendar"));
        
        // Add new calendar
        System::SharedPtr<Calendar> newCalendar = calColl->Add(u"TestCalendar");
        project->Save(dataDir + u"ReplaceCalendar_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:ReplaceCalendarWithNewCalendar
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace CreatingUpdatingAndRemoving
} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
