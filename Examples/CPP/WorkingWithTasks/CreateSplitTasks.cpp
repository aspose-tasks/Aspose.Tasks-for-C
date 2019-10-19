/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "CreateSplitTasks.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <saving/Enums/SaveFileFormat.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/WorkContourType.h>
#include <enums/TaskKey.h>
#include <enums/PrjKey.h>
#include <enums/AsnKey.h>
#include <Duration.h>
#include <Calendar.h>
#include <Asn.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(2074371254u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::CreateSplitTasks, ThisTypeBaseTypesInfo);

void CreateSplitTasks::Run()
{
    // ExStart:CreateSplitTasks
    // Create new project
    System::SharedPtr<Project> splitTaskProject = System::MakeObject<Project>();
    
    // Get a standard calendar
    System::SharedPtr<Calendar> calendar = splitTaskProject->Get<System::SharedPtr<Calendar>>(Prj::Calendar());
    
    // Set project's calendar settings
    splitTaskProject->Set(Prj::StartDate(), System::DateTime(2000, 3, 15, 8, 0, 0));
    splitTaskProject->Set(Prj::FinishDate(), System::DateTime(2000, 4, 21, 17, 0, 0));
    
    // Add a new task to root task
    System::SharedPtr<Task> rootTask = splitTaskProject->get_RootTask();
    rootTask->Set<System::String>(Tsk::Name(), u"Root");
    System::SharedPtr<Task> taskToSplit = rootTask->get_Children()->Add(u"Task1");
    taskToSplit->Set<Duration>(Tsk::Duration(), splitTaskProject->GetDuration(3));
    
    // Create a new resource assignment and generate timephased data
    System::SharedPtr<ResourceAssignment> splitResourceAssignment = splitTaskProject->get_ResourceAssignments()->Add(taskToSplit, nullptr);
    splitResourceAssignment->TimephasedDataFromTaskDuration(calendar);
    
    // Split the task into 3 parts.
    // Provide start date and finish date arguments to SplitTask method which will be used for split
    splitResourceAssignment->SplitTask(System::DateTime(2000, 3, 16, 8, 0, 0), System::DateTime(2000, 3, 16, 17, 0, 0), calendar);
    splitResourceAssignment->SplitTask(System::DateTime(2000, 3, 18, 8, 0, 0), System::DateTime(2000, 3, 18, 17, 0, 0), calendar);
    splitResourceAssignment->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::Contoured);
    
    // Save the Project
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    splitTaskProject->Save(dataDir + u"CreateSplitTasks_out.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
    // ExEnd:CreateSplitTasks
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
