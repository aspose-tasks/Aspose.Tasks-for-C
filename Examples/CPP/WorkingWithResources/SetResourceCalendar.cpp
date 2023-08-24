/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetResourceCalendar.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Rsc.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/RscKey.h>
#include <aspose.tasks.cpp/CalendarCollection.h>
#include <aspose.tasks.cpp/Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(3579988945u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::SetResourceCalendar, ThisTypeBaseTypesInfo);

void SetResourceCalendar::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SetResourceCalendar
    // Create project instance and add resource
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::SharedPtr<Resource> res = project->get_Resources()->Add(u"Resource1");
    
    // Add standard calendar and assign to resource
    System::SharedPtr<Aspose::Tasks::Calendar> cal = project->get_Calendars()->Add(u"Resource1");
    res->Set<System::SharedPtr<Calendar>>(Rsc::Calendar(), cal);
    // ExEnd:SetResourceCalendar
    
    // Save project as XML
    project->Save(dataDir + u"SetResourceCalendar_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
