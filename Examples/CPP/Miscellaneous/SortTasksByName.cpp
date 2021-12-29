/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SortTasksByName.h"

#include <util/TaskUtils.h>
#include <util/ChildTasksCollector.h>
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
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(1484668144u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::SortTasksByName::TaskNameComparer, ThisTypeBaseTypesInfo);
// ExStart:ImplementIComparer
int32_t SortTasksByName::TaskNameComparer::Compare(System::SharedPtr<Task> const &x, System::SharedPtr<Task> const &y) ASPOSE_CONST
{
    if (System::String::IsNullOrEmpty(x->Get(Tsk::Name())))
    {
        return 1;
    }
    if (System::String::IsNullOrEmpty(y->Get(Tsk::Name())))
    {
        return -1;
    }
    return x->Get(Tsk::Name()).CompareTo(y->Get(Tsk::Name()));
}
// ExEnd:ImplementIComparer

RTTI_INFO_IMPL_HASH(239093779u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::SortTasksByName, ThisTypeBaseTypesInfo);

void SortTasksByName::Run()
{
    // ExStart:SortTasksByName
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"project-sort.mpp");
    System::SharedPtr<ChildTasksCollector> coll = System::MakeObject<ChildTasksCollector>();
    TaskUtils::Apply(project->get_RootTask(), coll, 0);
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<Task>>> tasks = coll->get_Tasks();
    
    tasks->Sort(System::MakeObject<SortTasksByName::TaskNameComparer>());
    
    
    {
        auto task_enumerator = (tasks)->GetEnumerator();
        while (task_enumerator->MoveNext())
        {
            auto&& task = task_enumerator->get_Current();
            System::Console::WriteLine(task);
        }
    }
    // ExEnd:SortTasksByName
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
