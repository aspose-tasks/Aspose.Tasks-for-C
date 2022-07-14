/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithProjectProperties/SetAttributesForNewTasks.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/TaskStartDateType.h>
#include <enums/PrjKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(1552159925u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::SetAttributesForNewTasks, ThisTypeBaseTypesInfo);

void SetAttributesForNewTasks::Run()
{
    // ExStart:SetAttributesForNewTasks
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance Set new task property and Save the project as XML project file
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->Set<TaskStartDateType>(Prj::NewTaskStartDate(), Aspose::Tasks::TaskStartDateType::CurrentDate);
    project->Save(dataDir + u"SetAttributesForNewTasks_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    
    // Display Status.
    System::Console::WriteLine(u"New Task created with start date successfully.");
    // ExEnd:SetAttributesForNewTasks
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
