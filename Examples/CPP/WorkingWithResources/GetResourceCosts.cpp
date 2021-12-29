#include "GetResourceCosts.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/decimal.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/RscKey.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(2473456543u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::GetResourceCosts, ThisTypeBaseTypesInfo);

void GetResourceCosts::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceCosts
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceCosts.mpp");
    
    // Display all resources costs
    
    {
        auto res_enumerator = (project1->get_Resources())->GetEnumerator();
        while (res_enumerator->MoveNext())
        {
            auto&& res = res_enumerator->get_Current();
            if (res->Get<System::String>(Rsc::Name()) != nullptr)
            {
                System::Console::WriteLine(res->Get<System::Decimal>(Rsc::Cost()));
                System::Console::WriteLine(res->Get<double>(Rsc::ACWP()));
                System::Console::WriteLine(res->Get<double>(Rsc::BCWS()));
                System::Console::WriteLine(res->Get<double>(Rsc::BCWP()));
            }
        }
    }
    // ExEnd:GetResourceCosts
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
