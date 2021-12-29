#include "GetResourceAssignmentVariance.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
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

RTTI_INFO_IMPL_HASH(2955462930u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GetResourceAssignmentVariance, ThisTypeBaseTypesInfo);

void GetResourceAssignmentVariance::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceAssignmentVariance
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceAssignmentVariance.mpp");
    
    // Print assignment variances
    
    {
        auto ra_enumerator = (project1->get_ResourceAssignments())->GetEnumerator();
        while (ra_enumerator->MoveNext())
        {
            auto&& ra = ra_enumerator->get_Current();
            System::Console::WriteLine(System::ObjectExt::Box<Duration>(ra->Get<Duration>(Asn::WorkVariance())));
            System::Console::WriteLine(ra->Get<double>(Asn::CostVariance()));
            System::Console::WriteLine(System::ObjectExt::Box<Duration>(ra->Get<Duration>(Asn::StartVariance())));
            System::Console::WriteLine(System::ObjectExt::Box<Duration>(ra->Get<Duration>(Asn::FinishVariance())));
        }
    }
    // ExEnd:GetResourceAssignmentVariance
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
