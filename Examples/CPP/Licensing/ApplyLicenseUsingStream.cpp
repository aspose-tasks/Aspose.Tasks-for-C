#include "ApplyLicenseUsingStream.h"

#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <aspose.tasks.cpp/license/License.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Licensing {

RTTI_INFO_IMPL_HASH(114070370u, ::Aspose::Tasks::Examples::CPP::Licensing::ApplyLicenseUsingStream, ThisTypeBaseTypesInfo);

void ApplyLicenseUsingStream::Run()
{
    // ExStart:ApplyLicenseUsingStream
    System::SharedPtr<Aspose::Tasks::License> license = System::MakeObject<Aspose::Tasks::License>();
    System::SharedPtr<System::IO::FileStream> myStream = System::MakeObject<System::IO::FileStream>(u"Aspose.Tasks.lic", System::IO::FileMode::Open);
    license->SetLicense(myStream);
    // ExEnd:ApplyLicenseUsingStream
}

} // namespace Licensing
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
