#include "TimescaleSettings.h"

#include <visualization/Enums/Timescale.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Image/ImageSaveOptions.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(2852692948u, ::Aspose::Tasks::Examples::CPP::Articles::TimescaleSettings, ThisTypeBaseTypesInfo);

void TimescaleSettings::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:TimescaleSettings
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    
    // Save to one page image (Timescale.days by default)
    project->Save(u"NewProductDevDays.jpeg", System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::JPEG));
    
    
    // Save to one page image (Timescale.ThirdsOfMonths)
    System::SharedPtr<ImageSaveOptions> options = System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::JPEG);
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    
    project->Save(u"NewProductDevThirdsOfMonths.jpeg", options);
    
    // Save to one page image (Timescale.Months)
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Months);
    project->Save(u"NewProductDevMonths.jpeg", options);
    // ExEnd:TimescaleSettings
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
