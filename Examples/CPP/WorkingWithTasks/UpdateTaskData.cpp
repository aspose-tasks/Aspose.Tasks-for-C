/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "UpdateTaskData.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/TimeUnitType.h>
#include <enums/TaskKey.h>
#include <enums/PrjKey.h>
#include <enums/ConstraintType.h>
#include <Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(18700254u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::UpdateTaskData, ThisTypeBaseTypesInfo);

void UpdateTaskData::Run()
{
    try
    {
        // ExStart:UpdateTaskData
        // Create project instance
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        System::String newProject = u"UpdateTaskData.mpp";
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + newProject);
        
        // Set project start date
        project->Set(Prj::StartDate(), System::DateTime(2012, 7, 29, 8, 0, 0));
        
        // Add summary task and set its properties
        System::SharedPtr<Task> summary = project->get_RootTask()->get_Children()->Add(u"Summary task");
        System::SharedPtr<Task> task1 = summary->get_Children()->Add(u"First task");
        task1->Set<Duration>(Tsk::Duration(), project->GetDuration(3));
        task1->Set(Tsk::Deadline(), task1->Get<System::DateTime>(Tsk::Start()).AddDays(10));
        task1->Set<System::String>(Tsk::NotesText(), u"The first task.");
        task1->Set<TimeUnitType>(Tsk::DurationFormat(), Aspose::Tasks::TimeUnitType::MinuteEstimated);
        task1->Set<ConstraintType>(Tsk::ConstraintType(), Aspose::Tasks::ConstraintType::FinishNoLaterThan);
        task1->Set(Tsk::ConstraintDate(), task1->Get<System::DateTime>(Tsk::Deadline()).AddDays(-1));
        
        
        // Create 10 new sub tasks for summary task
        for (int32_t i = 0; i < 10; i++)
        {
            System::SharedPtr<Task> subTask = summary->get_Children()->Add(System::String::Format(u"Task{0}",i + 2));
            subTask->Set<Duration>(Tsk::Duration(), task1->Get<Duration>(Tsk::Duration()).Add(project->GetDuration(i + 1)));
            subTask->Set<TimeUnitType>(Tsk::DurationFormat(), Aspose::Tasks::TimeUnitType::Day);
            subTask->Set(Tsk::Deadline(), task1->Get<System::DateTime>(Tsk::Deadline()).AddDays(i + 1));
        }
        
        // Save the Project
        project->Save(dataDir + u"project_UpdateTaskData_updated_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:UpdateTaskData
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
