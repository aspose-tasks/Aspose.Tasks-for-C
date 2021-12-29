#include "ViewSplitTasks.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <SplitPartCollection.h>
#include <SplitPart.h>
#include <Project.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(890748031u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ViewSplitTasks, ThisTypeBaseTypesInfo);

void ViewSplitTasks::Run()
{
    // ExStart:ViewSplitTasks
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ViewSplitTasks.mpp");
    
    // Access task 
    System::SharedPtr<Task> splitTask = project1->get_RootTask()->get_Children()->GetById(4);
    
    // Display split parts of task
    System::SharedPtr<SplitPartCollection> collection = splitTask->get_SplitParts();
    
    {
        auto splitPart_enumerator = (collection)->GetEnumerator();
        while (splitPart_enumerator->MoveNext())
        {
            auto&& splitPart = splitPart_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Index: ") + splitPart->get_Index() + u"\nStart: " + splitPart->get_Start() + u"\nFinish: " + splitPart->get_Finish() + u"\n");
        }
    }
    // ExEnd:ViewSplitTasks
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
