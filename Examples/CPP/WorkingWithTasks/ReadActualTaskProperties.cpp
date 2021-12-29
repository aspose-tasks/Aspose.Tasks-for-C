/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadActualTaskProperties.h"

#include <util/TaskUtils.h>
#include <util/ChildTasksCollector.h>
#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(2895944706u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadActualTaskProperties, ThisTypeBaseTypesInfo);

void ReadActualTaskProperties::Run()
{
    // ExStart:ReadActualTaskProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create Project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ActualTaskProperties.mpp");
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(project->get_RootTask(), collector, 0);
    
    // Parse through all the collected tasks
    
    {
        auto task_enumerator = (collector->get_Tasks())->GetEnumerator();
        while (task_enumerator->MoveNext())
        {
            auto&& task = task_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Task Name : ") + task->Get(Tsk::Name()));
            System::Console::WriteLine(System::String(u"Actual Start: ") + task->Get<System::DateTime>(Tsk::ActualStart()).ToLongDateString());
            System::Console::WriteLine(System::String(u"Actual Finish: ") + task->Get<System::DateTime>(Tsk::ActualFinish()).ToLongDateString());
            System::Console::WriteLine(System::String(u"Actual Duration: ") + System::Convert::ToString(task->Get<Duration>(Tsk::ActualDuration()).get_TimeSpan().get_Hours()));
            System::Console::WriteLine(System::String(u"Actual Cost: ") + System::Convert::ToString(task->Get<System::Decimal>(Tsk::ActualCost())));
            System::Console::WriteLine(u"---------------------------------------------");
        }
    }
    // ExEnd:ReadActualTaskProperties
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
