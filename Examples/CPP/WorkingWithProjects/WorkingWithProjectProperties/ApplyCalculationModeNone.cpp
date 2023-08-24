#include "ApplyCalculationModeNone.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/primitive_types.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/CalculationMode.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(347228461u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ApplyCalculationModeNone, ThisTypeBaseTypesInfo);

void ApplyCalculationModeNone::Run()
{
    // ExStart:ApplyCalculationModeNone
    // Create empty project and set calculation mode to None
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->set_CalculationMode(Aspose::Tasks::CalculationMode::None);
    
    // Add a new task
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
    
    // Note that even ids were not calculated            
    System::Console::WriteLine(u"Task.Id Equals 0 : {0} ", System::ObjectExt::Box<bool>(System::Equals(task->Get<int32_t>(Tsk::Id()), 0)));
    System::Console::WriteLine(u"Task.OutlineLevel Equals 0 : {0} ", System::ObjectExt::Box<bool>(System::Equals(task->Get<int32_t>(Tsk::OutlineLevel()), 0)));
    System::Console::WriteLine(u"Task Start Equals DateTime.MinValue : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task->Get<System::DateTime>(Tsk::Start()), System::DateTime::MinValue)));
    System::Console::WriteLine(u"Task Finish Equals DateTime.MinValue : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task->Get<System::DateTime>(Tsk::Finish()), System::DateTime::MinValue)));
    System::Console::WriteLine(u"Task Duration Equals 0 mins : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(task->Get<Duration>(Tsk::Duration())), u"0 mins")));
    
    // Set duration property
    task->Set<Duration>(Tsk::Duration(), project->GetDuration(2, Aspose::Tasks::TimeUnitType::Day));
    System::Console::WriteLine(u"Task Duration Equals 2 days : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(System::ObjectExt::ToString(task->Get<Duration>(Tsk::Duration())), u"2 days")));
    System::Console::WriteLine(u"Task Start Equals DateTime.MinValue  : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task->Get<System::DateTime>(Tsk::Start()), System::DateTime::MinValue)));
    System::Console::WriteLine(u"Task Finish Equals DateTime.MinValue  : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task->Get<System::DateTime>(Tsk::Finish()), System::DateTime::MinValue)));
    // ExEnd:ApplyCalculationModeNone
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
