/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadTaskWBS.h"

#include <aspose.tasks.cpp/util/TaskUtils.h>
#include <aspose.tasks.cpp/util/ChildTasksCollector.h>
#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(2441415239u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskWBS, ThisTypeBaseTypesInfo);

void ReadTaskWBS::Run()
{
    // ExStart:ReadTaskWBS
    // Read project
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"TaskWBS.mpp");
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(project1->get_RootTask(), collector, 0);
    
    // Parse through all the collected tasks
    
    {
        auto tsk_enumerator = (collector->get_Tasks())->GetEnumerator();
        while (tsk_enumerator->MoveNext())
        {
            auto&& tsk = tsk_enumerator->get_Current();
            System::Console::WriteLine(tsk->Get(Tsk::WBS()));
            System::Console::WriteLine(tsk->Get(Tsk::WBSLevel()));
            
            // Set custom WBS
            tsk->Set<System::String>(Tsk::WBS(), System::String(u"custom wbs") + tsk->Get(Tsk::WBS()));
        }
    }
    // ExEnd:ReadTaskWBS
    
    // Save project as PDF
    project1->Save(dataDir + u"TaskWBS_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
