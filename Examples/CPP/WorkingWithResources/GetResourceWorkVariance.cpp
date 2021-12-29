#include "GetResourceWorkVariance.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Rsc.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/RscKey.h>
#include <enums/AsnKey.h>
#include <Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(2559448457u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::GetResourceWorkVariance, ThisTypeBaseTypesInfo);

void GetResourceWorkVariance::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GetResourceWorkVariance
    // Read the input Project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"WorkVariance.mpp");
    Key<System::SharedPtr<Resource>, AsnKey> asnRsc = Asn::Resource();
    
    {
        auto ra_enumerator = (project->get_ResourceAssignments())->GetEnumerator();
        while (ra_enumerator->MoveNext())
        {
            auto&& ra = ra_enumerator->get_Current();
            System::SharedPtr<Resource> rsc;
            
            // C# preprocessor directive: #if !__cplusplus
            
            
            // C# preprocessor directive: #endif
            
            rsc = ra->Get(asnRsc);
            
            double d = rsc->Get<double>(Rsc::WorkVariance());
            
            System::Console::WriteLine(d);
        }
    }
    // ExEnd:GetResourceWorkVariance
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
