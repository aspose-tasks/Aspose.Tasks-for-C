#include "ApplyLicenseUsingFile.h"

#include <system/shared_ptr.h>
#include <system/string.h>
#include <system/object.h>
#include <license/License.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Licensing {

RTTI_INFO_IMPL_HASH(931127390u, ::Aspose::Tasks::Examples::CPP::Licensing::ApplyLicenseUsingFile, ThisTypeBaseTypesInfo);

void ApplyLicenseUsingFile::Run()
{
    // ExStart:ApplyLicenseUsingFile
    System::SharedPtr<Aspose::Tasks::License> license = System::MakeObject<Aspose::Tasks::License>();
    license->SetLicense(u"Aspose.Tasks.lic");
    // ExEnd:ApplyLicenseUsingFile
}

} // namespace Licensing
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
