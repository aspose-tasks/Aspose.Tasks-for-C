#include "GetResourceAssignmentPercentWorkComplete.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/ResourceAssignmentCollection.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/AsnKey.h>
#include <cstdint>
#include <aspose.tasks.cpp/Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(2305109646u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GetResourceAssignmentPercentWorkComplete, ThisTypeBaseTypesInfo);

void GetResourceAssignmentPercentWorkComplete::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceAssignmentPercentWorkComplete
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceAssignmentPercentWorkComplete.mpp");
    
    // Print assignment percent completion
    
    {
        auto ra_enumerator = (project1->get_ResourceAssignments())->GetEnumerator();
        while (ra_enumerator->MoveNext())
        {
            auto&& ra = ra_enumerator->get_Current();
            System::Console::WriteLine(System::Convert::ToString(ra->Get<int32_t>(Asn::PercentWorkComplete())));
        }
    }
    // ExEnd:GetResourceAssignmentPercentWorkComplete
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
