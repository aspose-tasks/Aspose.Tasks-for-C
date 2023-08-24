#include "ApplyCalculationModeAuto.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskLinkCollection.h>
#include <aspose.tasks.cpp/TaskLink.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskLinkType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/CalculationMode.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(3134459396u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ApplyCalculationModeAuto, ThisTypeBaseTypesInfo);

void ApplyCalculationModeAuto::Run()
{
    // ExStart:ApplyCalculationModeAuto
    // Create empty project and set calculation mode to Automatic
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->set_CalculationMode(Aspose::Tasks::CalculationMode::Automatic);
    
    // Set project start date and add new tasks
    project->Set(Prj::StartDate(), System::DateTime(2015, 4, 15));
    System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->Add(u"Task 2");
    
    // Link tasks
    System::SharedPtr<TaskLink> link = project->get_TaskLinks()->Add(task1, task2, Aspose::Tasks::TaskLinkType::FinishToStart);
    
    // Verify dates have been recalculated
    System::Console::WriteLine(u"Task1 Start + 1 Equals Task2 Start : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task1->Get<System::DateTime>(Tsk::Start()).AddDays(1), task2->Get<System::DateTime>(Tsk::Start()))));
    System::Console::WriteLine(u"Task1 Finish + 1 Equals Task2 Finish : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task1->Get<System::DateTime>(Tsk::Finish()).AddDays(1), task2->Get<System::DateTime>(Tsk::Finish()))));
    System::Console::WriteLine(u"RootTask Finish Equals Task2 Finish : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task2->Get<System::DateTime>(Tsk::Finish()), project->get_RootTask()->Get<System::DateTime>(Tsk::Finish()))));
    System::Console::WriteLine(u"Project Finish Date Equals Task2 Finish : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(task2->Get<System::DateTime>(Tsk::Finish()), project->Get<System::DateTime>(Prj::FinishDate()))));
    // ExEnd:ApplyCalculationModeAuto
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
