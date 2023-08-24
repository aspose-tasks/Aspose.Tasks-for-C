#include "GetGeneralResourceAssignmentProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
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

RTTI_INFO_IMPL_HASH(1124610448u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GetGeneralResourceAssignmentProperties, ThisTypeBaseTypesInfo);

void GetGeneralResourceAssignmentProperties::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetGeneralResourceAssignmentProperties
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"GetGeneralResourceAssignmentProperties.mpp");
    
    // Print general resource assignment properties
    
    {
        auto ra_enumerator = (project1->get_ResourceAssignments())->GetEnumerator();
        while (ra_enumerator->MoveNext())
        {
            auto&& ra = ra_enumerator->get_Current();
            System::Console::WriteLine(ra->Get<int32_t>(Asn::Uid()));
            System::Console::WriteLine(ra->Get<System::DateTime>(Asn::Start()).ToShortDateString());
            System::Console::WriteLine(ra->Get<System::DateTime>(Asn::Finish()).ToShortDateString());
        }
    }
    // ExEnd:GetGeneralResourceAssignmentProperties
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
