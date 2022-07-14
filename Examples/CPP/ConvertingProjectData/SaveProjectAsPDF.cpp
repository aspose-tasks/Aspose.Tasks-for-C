#include "ConvertingProjectData/SaveProjectAsPDF.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(386513545u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::SaveProjectAsPDF, ThisTypeBaseTypesInfo);

void SaveProjectAsPDF::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SaveProjectAsPDF
    // Read the input Project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    // Save the Project as PDF
    project->Save(dataDir + u"SaveProjectAsPDF_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
    // ExEnd:SaveProjectAsPDF
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
