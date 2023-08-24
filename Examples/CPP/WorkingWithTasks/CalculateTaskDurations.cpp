#include "CalculateTaskDurations.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/Duration.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3764745626u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::CalculateTaskDurations, ThisTypeBaseTypesInfo);

void CalculateTaskDurations::Run()
{
    // ExStart:CalculateTaskDurations
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"TaskDurations.mpp");
    
    // Get a task to calculate its duration in different formats
    System::SharedPtr<Task> task = project1->get_RootTask()->get_Children()->GetById(1);
    
    // Get the duration in Minutes, Days, Hours, Weeks and Months
    double mins = task->Get<Duration>(Tsk::Duration()).Convert(Aspose::Tasks::TimeUnitType::Minute).ToDouble();
    System::Console::WriteLine(u"Duration in Mins: {0}", System::ObjectExt::Box<double>(mins));
    double days = task->Get<Duration>(Tsk::Duration()).Convert(Aspose::Tasks::TimeUnitType::Day).ToDouble();
    System::Console::WriteLine(u"Duration in Days: {0}", System::ObjectExt::Box<double>(days));
    double hours = task->Get<Duration>(Tsk::Duration()).Convert(Aspose::Tasks::TimeUnitType::Hour).ToDouble();
    System::Console::WriteLine(u"Duration in Hours: {0}", System::ObjectExt::Box<double>(hours));
    double weeks = task->Get<Duration>(Tsk::Duration()).Convert(Aspose::Tasks::TimeUnitType::Week).ToDouble();
    System::Console::WriteLine(u"Duration in Weeks: {0}", System::ObjectExt::Box<double>(weeks));
    double months = task->Get<Duration>(Tsk::Duration()).Convert(Aspose::Tasks::TimeUnitType::Month).ToDouble();
    System::Console::WriteLine(u"Duration in Months: {0}", System::ObjectExt::Box<double>(months));
    // ExEnd:CalculateTaskDurations
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
