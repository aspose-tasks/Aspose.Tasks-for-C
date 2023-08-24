#include "GetResourcePercentWorkComplete.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/Rsc.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/RscKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(2042447848u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::GetResourcePercentWorkComplete, ThisTypeBaseTypesInfo);

void GetResourcePercentWorkComplete::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourcePercentWorkComplete
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourcePercentWorkComplete.mpp");
    
    // Display work percentage completion for all resources
    
    {
        auto res_enumerator = (project1->get_Resources())->GetEnumerator();
        while (res_enumerator->MoveNext())
        {
            auto&& res = res_enumerator->get_Current();
            if (res->Get<System::String>(Rsc::Name()) != nullptr)
            {
                System::Console::WriteLine(res->Get<int32_t>(Rsc::PercentWorkComplete()));
            }
        }
    }
    // ExEnd:GetResourcePercentWorkComplete
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
