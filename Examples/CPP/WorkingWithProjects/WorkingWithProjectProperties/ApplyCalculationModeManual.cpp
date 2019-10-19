#include "ApplyCalculationModeManual.h"

#include <Tsk.h>
#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/primitive_types.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/TaskLinkType.h>
#include <enums/TaskKey.h>
#include <enums/PrjKey.h>
#include <enums/CalculationMode.h>
#include <Duration.h>
#include <cstdint>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(527368123u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ApplyCalculationModeManual, ThisTypeBaseTypesInfo);

void ApplyCalculationModeManual::Run()
{
    // ExStart:ApplyCalculationModeManual
    // Create empty project and set calculation mode to Manual
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->set_CalculationMode(Aspose::Tasks::CalculationMode::Manual);
    
    // Set project start date and add new tasks
    project->Set(Prj::StartDate(), System::DateTime(2015, 4, 15));
    System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->Add(u"Task 2");
    
    // The necessary properties are set in manual mode
    System::Console::WriteLine(u"Task1.Id Equals 1 : {0} ", System::ObjectExt::Box<bool>(System::Equals(task1->Get<int32_t>(Tsk::Id()), 1)));
    System::Console::WriteLine(u"Task1 OutlineLevel Equals 1 : {0} ", System::ObjectExt::Box<bool>(System::Equals(task1->Get<int32_t>(Tsk::OutlineLevel()), 1)));
    System::Console::WriteLine(u"Task1 Start Equals 15/04/2015 08:00 AM : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task1->Get<System::DateTime>(Tsk::Start()), System::DateTime(2015, 4, 15, 8, 0, 0))));
    System::Console::WriteLine(u"Task1 Finish Equals 15/04/2015 05:00 PM : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task1->Get<System::DateTime>(Tsk::Finish()), System::DateTime(2015, 4, 15, 17, 0, 0))));
    System::Console::WriteLine(u"Task1 Duration Equals 1 day : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(task1->Get<Duration>(Tsk::Duration())), u"1 day")));
    System::Console::WriteLine(u"Task2 Start Equals 15/04/2015 08:00 AM : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task2->Get<System::DateTime>(Tsk::Start()), System::DateTime(2015, 4, 15, 8, 0, 0))));
    System::Console::WriteLine(u"Task2 Finish Equals 15/04/2015 05:00 PM : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task2->Get<System::DateTime>(Tsk::Finish()), System::DateTime(2015, 4, 15, 17, 0, 0))));
    System::Console::WriteLine(u"Task2 Duration Equals 1 day : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(task2->Get<Duration>(Tsk::Duration())), u"1 day")));
    
    // When we link two tasks together their dates are not recalculated in manual mode
    System::SharedPtr<TaskLink> link = project->get_TaskLinks()->Add(task1, task2, Aspose::Tasks::TaskLinkType::FinishToStart);
    
    // Task 2 Start has not been changed
    System::Console::WriteLine(u"Task1 Start Equals Task2 Start : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task1->Get<System::DateTime>(Tsk::Start()), task2->Get<System::DateTime>(Tsk::Start()))));
    System::Console::WriteLine(u"Task1 Finish Equals Task2 Finish : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task1->Get<System::DateTime>(Tsk::Finish()), task2->Get<System::DateTime>(Tsk::Finish()))));
    // ExEnd:ApplyCalculationModeManual
    
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
