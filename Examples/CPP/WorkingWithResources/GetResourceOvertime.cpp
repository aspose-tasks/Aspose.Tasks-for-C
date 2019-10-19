#include "GetResourceOvertime.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
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
#include <enums/RateFormatType.h>
#include <Duration.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(2425816712u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::GetResourceOvertime, ThisTypeBaseTypesInfo);

void GetResourceOvertime::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceOvertime
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceOvertime.mpp");
    
    // Display overtime related parameters for all resources
    
    {
        auto res_enumerator = (project1->get_Resources())->GetEnumerator();
        decltype(res_enumerator->get_Current()) res;
        while (res_enumerator->MoveNext() && (res = res_enumerator->get_Current(), true))
        {
            if (res->Get<System::String>(Rsc::Name()) != nullptr)
            {
                System::Console::WriteLine(res->Get<System::Decimal>(Rsc::OvertimeCost()));
                System::Console::WriteLine(System::ObjectExt::ToString(res->Get<Duration>(Rsc::OvertimeWork())));
                System::Console::WriteLine(System::ObjectExt::ToString(res->Get<RateFormatType>(Rsc::OvertimeRateFormat())));
            }
        }
    }
    // ExEnd:GetResourceOvertime
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
