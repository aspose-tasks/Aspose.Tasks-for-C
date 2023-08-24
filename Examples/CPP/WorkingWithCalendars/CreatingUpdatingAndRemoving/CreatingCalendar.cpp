/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "CreatingCalendar.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/CalendarCollection.h>
#include <aspose.tasks.cpp/Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

namespace CreatingUpdatingAndRemoving {

RTTI_INFO_IMPL_HASH(1389606051u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving::CreatingCalendar, ThisTypeBaseTypesInfo);

void CreatingCalendar::Run()
{
    // ExStart:CreatingCalendar            
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // New calendar can be added to a project's calendar collection using the collection's Add method.
    System::SharedPtr<Aspose::Tasks::Calendar> cal1 = project->get_Calendars()->Add(u"New Info");
    System::SharedPtr<Aspose::Tasks::Calendar> cal2 = project->get_Calendars()->Add(u"no name");
    System::SharedPtr<Aspose::Tasks::Calendar> cal3 = project->get_Calendars()->Add(u"cal3");
    
    // Save the Project
    System::String dataDir = Examples::CPP::RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project->Save(dataDir + u"CreatingCalendar_out.Xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:CreatingCalendar
}

} // namespace CreatingUpdatingAndRemoving
} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
