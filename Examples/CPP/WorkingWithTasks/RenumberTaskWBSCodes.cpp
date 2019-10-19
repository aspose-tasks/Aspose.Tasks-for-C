/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenumberTaskWBSCodes.h"

#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <system/collections/ienumerable.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1197666693u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::RenumberTaskWBSCodes, ThisTypeBaseTypesInfo);

void RenumberTaskWBSCodes::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    //ExStart: RenumberTaskWBSCodes
    auto project = System::MakeObject<Project>(dataDir + u"RenumberExample.mpp");
    
    auto tasks = project->get_RootTask()->SelectAllChildTasks();
    
    System::Console::WriteLine(u"WBS codes before: ");
    
    // output: ""; "1"; "2"; "4"
    
    {
        auto task_enumerator = (tasks)->GetEnumerator();
        decltype(task_enumerator->get_Current()) task;
        while (task_enumerator->MoveNext() && (task = task_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(u"\"") + task->Get(Tsk::WBS()) + u"\"" + u"; ");
        }
    }
    
    // project.RenumberWBSCode(); // this overload could have used too
    project->RenumberWBSCode([&]{ int32_t init_0[] = {1, 2, 3}; auto list_0 = System::MakeObject<System::Collections::Generic::List<int32_t>>(); list_0->AddInitializer(3, init_0); return list_0; }());
    
    System::Console::WriteLine(u"\nWBS codes after: ");
    
    // output: ""; "1"; "2"; "3"
    
    {
        auto task_enumerator = (tasks)->GetEnumerator();
        decltype(task_enumerator->get_Current()) task;
        while (task_enumerator->MoveNext() && (task = task_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String(u"\"") + task->Get(Tsk::WBS()) + u"\"" + u"; ");
        }
    }
    //ExEnd: RenumberTaskWBSCodes
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
