#include "GetTaskLinkType.h"

#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <enums/TaskLinkType.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskLinks {

RTTI_INFO_IMPL_HASH(3495163747u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks::GetTaskLinkType, ThisTypeBaseTypesInfo);

void GetTaskLinkType::Run()
{
    // ExStart:GetTaskLinkType
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"GetTaskLinkType.mpp");
    
    // Display task link types 
    auto allinks = project1->get_TaskLinks();
    
    {
        auto tsklnk_enumerator = (allinks)->GetEnumerator();
        while (tsklnk_enumerator->MoveNext())
        {
            auto&& tsklnk = tsklnk_enumerator->get_Current();
            System::Console::WriteLine(System::ObjectExt::ToString(tsklnk->get_LinkType()));
        }
    }
    // ExEnd:GetTaskLinkType
}

} // namespace WorkingWithTaskLinks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
