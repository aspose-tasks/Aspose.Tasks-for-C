#include "WorkingWithProjects/TaskSettingStartFinishDates.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/CalculationMode.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(3695054809u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::TaskSettingStartFinishDates, ThisTypeBaseTypesInfo);

void TaskSettingStartFinishDates::Run()
{
    // ExStart:TaskSettingStartFinishDates
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(project->Get<System::DateTime>(Prj::StartDate())));
    System::Console::WriteLine(System::ObjectExt::ToString(project->get_CalculationMode()));
    
    project->set_CalculationMode(Aspose::Tasks::CalculationMode::None);
    
    System::Console::WriteLine(System::ObjectExt::ToString(project->get_CalculationMode()));
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task1");
    
    task->Set(Tsk::Start(), System::DateTime(2012, 8, 1));
    task->Set(Tsk::Finish(), System::DateTime(2012, 8, 5));
    
    System::Console::WriteLine(u"*************** Before Recalculate *****************");
    System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(task->Get<System::DateTime>(Tsk::Start())));
    System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(task->Get<System::DateTime>(Tsk::Finish())));
    
    
    project->Recalculate();
    
    System::Console::WriteLine(u"*************** After Recalculate *****************");
    System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(task->Get<System::DateTime>(Tsk::Start())));
    System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(task->Get<System::DateTime>(Tsk::Finish())));
    
    // ExEnd:TaskSettingStartFinishDates
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
