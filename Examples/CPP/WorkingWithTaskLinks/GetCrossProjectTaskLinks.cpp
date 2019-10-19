#include "GetCrossProjectTaskLinks.h"

#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskLinks {

RTTI_INFO_IMPL_HASH(33739153u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks::GetCrossProjectTaskLinks, ThisTypeBaseTypesInfo);

void GetCrossProjectTaskLinks::Run()
{
    // ExStart:GetCrossProjectTaskLinks
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"GetCrossProjectTaskLinks.mpp");
    
    // Check cross project task links
    
    {
        auto tsklnk_enumerator = (project1->get_TaskLinks())->GetEnumerator();
        decltype(tsklnk_enumerator->get_Current()) tsklnk;
        while (tsklnk_enumerator->MoveNext() && (tsklnk = tsklnk_enumerator->get_Current(), true))
        {
            if (tsklnk->get_IsCrossProject())
            {
                System::Console::WriteLine(tsklnk->get_CrossProjectName());
            }
        }
    }
    // ExEnd:GetCrossProjectTaskLinks
}

} // namespace WorkingWithTaskLinks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
