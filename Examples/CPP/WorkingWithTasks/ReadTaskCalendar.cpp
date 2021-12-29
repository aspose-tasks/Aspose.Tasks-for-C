/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadTaskCalendar.h"

#include <util/TaskUtils.h>
#include <util/ChildTasksCollector.h>
#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <Calendar.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1858814079u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskCalendar, ThisTypeBaseTypesInfo);

void ReadTaskCalendar::Run()
{
    // ExStart:ReadTaskCalendar
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> prj = System::MakeObject<Project>(dataDir + u"ReadTaskCalendar.mpp");
    
    // Declare ChildTasksCollector class object
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Use TaskUtils to get all children tasks in RootTask
    TaskUtils::Apply(prj->get_RootTask(), collector, 0);
    
    // Parse all the recursive children
    
    {
        auto tsk_enumerator = (collector->get_Tasks())->GetEnumerator();
        while (tsk_enumerator->MoveNext())
        {
            auto&& tsk = tsk_enumerator->get_Current();
            System::SharedPtr<Calendar> tskCal = tsk->Get<System::SharedPtr<Calendar>>(Tsk::Calendar());
            System::Console::WriteLine(u"Task calendar name: {0}", System::ObjectExt::Box<System::String>(tskCal == nullptr ? u"None" : tskCal->get_Name()));
        }
    }
    // ExEnd:ReadTaskCalendar
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
