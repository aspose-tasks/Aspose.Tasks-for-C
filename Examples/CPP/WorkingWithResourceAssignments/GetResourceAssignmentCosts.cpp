#include "GetResourceAssignmentCosts.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/decimal.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Project.h>
#include <Key.h>
#include <enums/AsnKey.h>
#include <Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(1693613893u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GetResourceAssignmentCosts, ThisTypeBaseTypesInfo);

void GetResourceAssignmentCosts::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceAssignmentCosts
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceAssignmentCosts.mpp");
    
    // Print resource assignment costs
    
    {
        auto ra_enumerator = (project1->get_ResourceAssignments())->GetEnumerator();
        while (ra_enumerator->MoveNext())
        {
            auto&& ra = ra_enumerator->get_Current();
            System::Console::WriteLine(ra->Get<System::Decimal>(Asn::Cost()));
            System::Console::WriteLine(ra->Get<double>(Asn::ACWP()));
            System::Console::WriteLine(ra->Get<double>(Asn::BCWP()));
            System::Console::WriteLine(ra->Get<double>(Asn::BCWS()));
        }
    }
    // ExEnd:GetResourceAssignmentCosts
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
