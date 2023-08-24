/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Rescheduling/UpdateProjectAndRescheduleUncompletedWork.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskLinkCollection.h>
#include <aspose.tasks.cpp/TaskLink.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/NullableBool.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskLinkType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Rescheduling {

RTTI_INFO_IMPL_HASH(779039209u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Rescheduling::UpdateProjectAndRescheduleUncompletedWork, ThisTypeBaseTypesInfo);

void UpdateProjectAndRescheduleUncompletedWork::Run()
{
    // ExStart:UpdateProjectAndRescheduleUncompletedWork
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a new project and set start date
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->Set(Prj::StartDate(), System::DateTime(2014, 1, 27, 8, 0, 0));
    
    // Add new tasks
    System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->Add(u"Task 2");
    task2->Set<Duration>(Tsk::Duration(), task2->get_ParentProject()->GetDuration(16, Aspose::Tasks::TimeUnitType::Hour));
    System::SharedPtr<Task> task3 = project->get_RootTask()->get_Children()->Add(u"Task 3");
    task3->Set<Duration>(Tsk::Duration(), task2->get_ParentProject()->GetDuration(24, Aspose::Tasks::TimeUnitType::Hour));
    System::SharedPtr<Task> task4 = project->get_RootTask()->get_Children()->Add(u"Task 4");
    task4->Set<Duration>(Tsk::Duration(), task2->get_ParentProject()->GetDuration(16, Aspose::Tasks::TimeUnitType::Hour));
    System::SharedPtr<Task> task5 = project->get_RootTask()->get_Children()->Add(u"Task 5");
    task5->Set<Duration>(Tsk::Duration(), task2->get_ParentProject()->GetDuration(16, Aspose::Tasks::TimeUnitType::Hour));
    
    // Add links between tasks
    System::SharedPtr<TaskLink> link12 = project->get_TaskLinks()->Add(task1, task2, Aspose::Tasks::TaskLinkType::FinishToStart);
    System::SharedPtr<TaskLink> link23 = project->get_TaskLinks()->Add(task2, task3, Aspose::Tasks::TaskLinkType::FinishToStart);
    // One day lag
    link23->set_LinkLag(4800);
    System::SharedPtr<TaskLink> link34 = project->get_TaskLinks()->Add(task3, task4, Aspose::Tasks::TaskLinkType::FinishToStart);
    System::SharedPtr<TaskLink> link45 = project->get_TaskLinks()->Add(task4, task5, Aspose::Tasks::TaskLinkType::FinishToStart);
    
    // Add new tasks
    System::SharedPtr<Task> task6 = project->get_RootTask()->get_Children()->Add(u"Task 6");
    System::SharedPtr<Task> task7 = project->get_RootTask()->get_Children()->Add(u"Task 7");
    task7->Set<Duration>(Tsk::Duration(), task7->get_ParentProject()->GetDuration(24, Aspose::Tasks::TimeUnitType::Hour));
    System::SharedPtr<Task> task8 = project->get_RootTask()->get_Children()->Add(u"Task 8");
    task8->Set<Duration>(Tsk::Duration(), task2->get_ParentProject()->GetDuration(16, Aspose::Tasks::TimeUnitType::Hour));
    System::SharedPtr<Task> task9 = project->get_RootTask()->get_Children()->Add(u"Task 9");
    task9->Set<Duration>(Tsk::Duration(), task2->get_ParentProject()->GetDuration(16, Aspose::Tasks::TimeUnitType::Hour));
    System::SharedPtr<Task> task10 = project->get_RootTask()->get_Children()->Add(u"Task 10");
    
    // Add links between tasks
    System::SharedPtr<TaskLink> link67 = project->get_TaskLinks()->Add(task6, task7, Aspose::Tasks::TaskLinkType::FinishToStart);
    System::SharedPtr<TaskLink> link78 = project->get_TaskLinks()->Add(task7, task8, Aspose::Tasks::TaskLinkType::FinishToStart);
    System::SharedPtr<TaskLink> link89 = project->get_TaskLinks()->Add(task8, task9, Aspose::Tasks::TaskLinkType::FinishToStart);
    System::SharedPtr<TaskLink> link910 = project->get_TaskLinks()->Add(task9, task10, Aspose::Tasks::TaskLinkType::FinishToStart);
    task6->Set<NullableBool>(Tsk::IsManual(), NullableBool::to_NullableBool(true));
    task7->Set<NullableBool>(Tsk::IsManual(), NullableBool::to_NullableBool(true));
    task8->Set<NullableBool>(Tsk::IsManual(), NullableBool::to_NullableBool(true));
    task9->Set<NullableBool>(Tsk::IsManual(), NullableBool::to_NullableBool(true));
    task10->Set<NullableBool>(Tsk::IsManual(), NullableBool::to_NullableBool(true));
    
    // Save project before and after updating work as completed 
    project->Save(dataDir + u"RescheduleUncompletedWork_not updated_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    project->UpdateProjectWorkAsComplete(System::DateTime(2014, 1, 28, 17, 0, 0), false);
    project->Save(dataDir + u"RescheduleUncompletedWork_updated_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    
    // Save project after rescheduling uncompleted work
    project->RescheduleUncompletedWorkToStartAfter(System::DateTime(2014, 2, 7, 8, 0, 0));
    project->Save(dataDir + u"RescheduleUncompletedWork_rescheduled_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:UpdateProjectAndRescheduleUncompletedWork
}

} // namespace Rescheduling
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
