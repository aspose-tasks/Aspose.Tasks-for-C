/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadStopResumeDates.h"

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
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Util;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(278134234u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadStopResumeDates, ThisTypeBaseTypesInfo);

void ReadStopResumeDates::Run()
{
    // ExStart:ReadStopResumeDates
    // Read project from file stream
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(dataDir + u"StopResumeDates.mpp", System::IO::FileMode::Open);
    System::SharedPtr<Project> prj = System::MakeObject<Project>(fs);
    fs->Close();
    
    // Create a ChildTasksCollector instance
    System::SharedPtr<ChildTasksCollector> collector = System::MakeObject<ChildTasksCollector>();
    
    // Collect all the tasks from RootTask using TaskUtils
    TaskUtils::Apply(prj->get_RootTask(), collector, 0);
    
    // Check Stop and Resume dates for all tasks
    
    {
        auto tsk1_enumerator = (collector->get_Tasks())->GetEnumerator();
        decltype(tsk1_enumerator->get_Current()) tsk1;
        while (tsk1_enumerator->MoveNext() && (tsk1 = tsk1_enumerator->get_Current(), true))
        {
            if (tsk1->Get<System::DateTime>(Tsk::Stop()).ToShortDateString() == u"1/1/2000")
            {
                System::Console::WriteLine(u"Stop: NA");
            }
            else
            {
                System::Console::WriteLine(System::String(u"Stop: ") + tsk1->Get<System::DateTime>(Tsk::Stop()).ToShortDateString());
            }
            
            if (tsk1->Get<System::DateTime>(Tsk::Resume()).ToShortDateString() == u"1/1/2000")
            {
                System::Console::WriteLine(u"Resume: NA");
            }
            else
            {
                System::Console::WriteLine(System::String(u"Resume: ") + tsk1->Get<System::DateTime>(Tsk::Resume()).ToShortDateString());
            }
        }
    }
    // ExEnd:ReadStopResumeDates
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
