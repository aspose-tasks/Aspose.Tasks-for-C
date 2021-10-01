#include "ConvertingProjectData/RenderCommentsWhenConverting.h"

#include <visualization/PageViewSettings.h>
#include <visualization/PageInfo.h>
#include <View.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(2568439768u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::RenderCommentsWhenConverting, ThisTypeBaseTypesInfo);

void RenderCommentsWhenConverting::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:RenderCommentsWhenConverting
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Input.mpp");
    project->get_DefaultView()->get_PageInfo()->get_PageViewSettings()->set_PrintNotes(true);
    project->Save(dataDir + u"ProjectWithComments_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::PDF);
    // ExEnd:RenderCommentsWhenConverting
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
