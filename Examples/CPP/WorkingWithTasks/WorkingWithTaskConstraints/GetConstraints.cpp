/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "GetConstraints.h"

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
#include <enums/ConstraintType.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

namespace WorkingWithTaskConstraints {

RTTI_INFO_IMPL_HASH(282009408u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WorkingWithTaskConstraints::GetConstraints, ThisTypeBaseTypesInfo);

void GetConstraints::Run()
{
    // ExStart:GetConstraints
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(project1->get_RootTask(), collector, 0);
    
    // Parse through all the collected tasks
    
    {
        auto tsk1_enumerator = (collector->get_Tasks())->GetEnumerator();
        while (tsk1_enumerator->MoveNext())
        {
            auto&& tsk1 = tsk1_enumerator->get_Current();
            if (tsk1->Get<System::DateTime>(Tsk::ConstraintDate()).ToShortDateString() == u"1/1/2000")
            {
                System::Console::WriteLine(u"NA");
            }
            else
            {
                System::Console::WriteLine(tsk1->Get<System::DateTime>(Tsk::ConstraintDate()).ToShortDateString());
            }
            
            System::Console::WriteLine(System::ObjectExt::ToString(tsk1->Get<ConstraintType>(Tsk::ConstraintType())));
        }
    }
    // ExEnd:GetConstraints
}

} // namespace WorkingWithTaskConstraints
} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
