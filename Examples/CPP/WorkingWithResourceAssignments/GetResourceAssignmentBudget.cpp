#include "GetResourceAssignmentBudget.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/decimal.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Project.h>
#include <Key.h>
#include <enums/AsnKey.h>
#include <Duration.h>
#include <Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(401941254u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GetResourceAssignmentBudget, ThisTypeBaseTypesInfo);

void GetResourceAssignmentBudget::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceAssignmentBudget
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceAssignmentBudget.mpp");
    
    // Print assignment budget cost and budget work
    
    {
        auto ra_enumerator = (project1->get_ResourceAssignments())->GetEnumerator();
        while (ra_enumerator->MoveNext())
        {
            auto&& ra = ra_enumerator->get_Current();
            System::Console::WriteLine(ra->Get<System::Decimal>(Asn::BudgetCost()));
            System::Console::WriteLine(System::ObjectExt::ToString(ra->Get<Duration>(Asn::BudgetWork())));
        }
    }
    // ExEnd:GetResourceAssignmentBudget
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
