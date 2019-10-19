/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "FindEstimatedMilestoneTasks.h"

#include <util/TaskUtils.h>
#include <util/ChildTasksCollector.h>
#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <NullableBool.h>
#include <Key.h>
#include <enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(2762554203u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::FindEstimatedMilestoneTasks, ThisTypeBaseTypesInfo);

void FindEstimatedMilestoneTasks::Run()
{
    // ExStart:FindEstimatedMilestoneTasks
    // Read project from file stream
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(dataDir + u"EstimatedMilestoneTasks.mpp", System::IO::FileMode::Open);
    System::SharedPtr<Project> prj = System::MakeObject<Project>(fs);
    fs->Close();
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(prj->get_RootTask(), collector, 0);
    
    // Parse through all the collected tasks
    
    {
        auto tsk1_enumerator = (collector->get_Tasks())->GetEnumerator();
        decltype(tsk1_enumerator->get_Current()) tsk1;
        while (tsk1_enumerator->MoveNext() && (tsk1 = tsk1_enumerator->get_Current(), true))
        {
            System::String strEst = tsk1->Get<NullableBool>(Tsk::IsEstimated()).get_Value() ? System::String(u"Estimated") : System::String(u"Non-Estimated");
            System::String strMileStone = tsk1->Get<NullableBool>(Tsk::IsMilestone()).get_Value() ? System::String(u"Milestone") : System::String(u"Non-Milestone");
            System::Console::WriteLine(tsk1->Get(Tsk::Name()) + u" : " + strEst);
            System::Console::WriteLine(tsk1->Get(Tsk::Name()) + u" : " + strMileStone);
        }
    }
    // ExEnd:FindEstimatedMilestoneTasks
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
