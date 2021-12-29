#include "SortResourcesByName.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/RscKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(2008484304u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::SortResourcesByName::RscNameComparer, ThisTypeBaseTypesInfo);
// ExStart:ImplementIComparer
int32_t SortResourcesByName::RscNameComparer::Compare(System::SharedPtr<Resource> const &x, System::SharedPtr<Resource> const &y) ASPOSE_CONST
{
    if (System::String::IsNullOrEmpty(x->Get<System::String>(Rsc::Name())))
    {
        return 1;
    }
    if (System::String::IsNullOrEmpty(y->Get<System::String>(Rsc::Name())))
    {
        return -1;
    }
    return x->Get<System::String>(Rsc::Name()).CompareTo(y->Get<System::String>(Rsc::Name()));
}
// ExEnd:ImplementIComparer

RTTI_INFO_IMPL_HASH(1099296714u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::SortResourcesByName, ThisTypeBaseTypesInfo);

void SortResourcesByName::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SortResourcesByName
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"project-sort.mpp");
    
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<Resource>>> resources = project->get_Resources()->ToList();
    resources->Sort(System::MakeObject<SortResourcesByName::RscNameComparer>());
    
    
    {
        auto rsc_enumerator = (resources)->GetEnumerator();
        while (rsc_enumerator->MoveNext())
        {
            auto&& rsc = rsc_enumerator->get_Current();
            System::Console::WriteLine(rsc);
        }
    }
    // ExEnd:SortResourcesByName
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
