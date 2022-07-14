/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "MakeAStandardCalendar.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
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

namespace CreatingUpdatingAndRemoving {

RTTI_INFO_IMPL_HASH(2090492546u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving::MakeAStandardCalendar, ThisTypeBaseTypesInfo);

void MakeAStandardCalendar::Run()
{
    // ExStart:MakeAStandardCalendar
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Define Calendar and make it standard
    System::SharedPtr<Aspose::Tasks::Calendar> cal1 = project->get_Calendars()->Add(u"My Cal");
    Aspose::Tasks::Calendar::MakeStandardCalendar(cal1);
    
    // Save the Project
    System::String dataDir = Examples::CPP::RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project->Save(dataDir + u"Project_MakeStandardCalendar_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:MakeAStandardCalendar
}

} // namespace CreatingUpdatingAndRemoving
} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
