#include "GetResourceCalendar.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/RscKey.h>
#include <Calendar.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(1757921733u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::GetResourceCalendar, ThisTypeBaseTypesInfo);

void GetResourceCalendar::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceCalendar
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceCalendar.mpp");
    
    // Display base calendar name for all resources
    
    {
        auto res_enumerator = (project1->get_Resources())->GetEnumerator();
        while (res_enumerator->MoveNext())
        {
            auto&& res = res_enumerator->get_Current();
            if (res->Get<System::String>(Rsc::Name()) != nullptr)
            {
                System::Console::WriteLine(res->Get<System::SharedPtr<Calendar>>(Rsc::Calendar())->get_BaseCalendar()->get_Name());
            }
        }
    }
    // ExEnd:GetResourceCalendar
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
