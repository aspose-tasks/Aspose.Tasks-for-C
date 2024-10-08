/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadTaskPriority.h"

#include <aspose.tasks.cpp/util/TaskUtils.h>
#include <aspose.tasks.cpp/util/ChildTasksCollector.h>
#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(283526469u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskPriority, ThisTypeBaseTypesInfo);

void ReadTaskPriority::Run()
{
    // ExStart:ReadTaskPriority
    // Read project from file stream
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(dataDir + u"TaskPriority.mpp", System::IO::FileMode::Open);
    System::SharedPtr<Project> prj = System::MakeObject<Project>(fs);
    fs->Close();
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(prj->get_RootTask(), collector, 0);
    
    // Display Priorities for all tasks
    
    {
        auto tsk1_enumerator = (collector->get_Tasks())->GetEnumerator();
        while (tsk1_enumerator->MoveNext())
        {
            auto&& tsk1 = tsk1_enumerator->get_Current();
            System::Console::WriteLine(tsk1->Get(Tsk::Name()) + u" - Priority : " + System::Convert::ToString(tsk1->Get<int32_t>(Tsk::Priority())));
        }
    }
    // ExEnd:ReadTaskPriority
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
