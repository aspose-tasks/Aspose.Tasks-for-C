/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadTaskProperties.h"

#include <util/TaskUtils.h>
#include <util/ChildTasksCollector.h>
#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/date_time.h>
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

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(4264924116u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskProperties, ThisTypeBaseTypesInfo);

void ReadTaskProperties::Run()
{
    // ExStart:ReadTaskProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> prj = System::MakeObject<Project>(dataDir + u"ReadTaskProperties.mpp");
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(prj->get_RootTask(), collector, 0);
    
    // Parse through all the collected tasks
    
    {
        auto tsk_enumerator = (collector->get_Tasks())->GetEnumerator();
        while (tsk_enumerator->MoveNext())
        {
            auto&& tsk = tsk_enumerator->get_Current();
            System::Console::WriteLine(u"Task Id: {0}", System::ObjectExt::Box<int32_t>(tsk->Get<int32_t>(Tsk::Id())));
            System::Console::WriteLine(u"Task Uid: {0}", System::ObjectExt::Box<int32_t>(tsk->Get<int32_t>(Tsk::Uid())));
            System::Console::WriteLine(u"Task Name: {0}", System::ObjectExt::Box<System::String>(tsk->Get(Tsk::Name())));
            System::Console::WriteLine(u"Task Start: {0}", System::ObjectExt::Box<System::DateTime>(tsk->Get<System::DateTime>(Tsk::Start())));
            System::Console::WriteLine(u"Task Finish: {0}", System::ObjectExt::Box<System::DateTime>(tsk->Get<System::DateTime>(Tsk::Finish())));
        }
    }
    // ExEnd:ReadTaskProperties
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
