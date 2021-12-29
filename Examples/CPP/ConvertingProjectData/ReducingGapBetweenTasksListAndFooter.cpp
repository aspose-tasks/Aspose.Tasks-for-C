#include "ReducingGapBetweenTasksListAndFooter.h"

#include <visualization/View/PageSize.h>
#include <visualization/Enums/Timescale.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <saving/SaveOptions.h>
#include <saving/Pdf/PdfSaveOptions.h>
#include <saving/Image/ImageSaveOptions.h>
#include <saving/Html/HtmlSaveOptions.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(1640744640u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::ReducingGapBetweenTasksListAndFooter, ThisTypeBaseTypesInfo);

void ReducingGapBetweenTasksListAndFooter::Run()
{
    //ExStart: ReducingGapBetweenTasksListAndFooter
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    //Read the MPP file.
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    //Use ReduceFooterGap property to reduce the gap between list of tasks and Footer
    auto imageSaveOptions = [&]{ auto tmp_0 = System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::PNG); tmp_0->set_ReduceFooterGap(true); tmp_0->set_RenderToSinglePage(false); tmp_0->set_PageSize(Aspose::Tasks::Visualization::PageSize::A0); tmp_0->set_Timescale(Aspose::Tasks::Visualization::Timescale::Days); return tmp_0; }();
    project->Save(dataDir + u"ReducingGapBetweenTasksListAndFooter_out.png", System::StaticCast<Aspose::Tasks::Saving::SaveOptions>(imageSaveOptions));
    
    auto pdfSaveOptions = [&]{ auto tmp_1 = System::MakeObject<PdfSaveOptions>(); tmp_1->set_ReduceFooterGap(true); tmp_1->set_SaveToSeparateFiles(true); tmp_1->set_PageSize(Aspose::Tasks::Visualization::PageSize::A0); tmp_1->set_Timescale(Aspose::Tasks::Visualization::Timescale::Days); return tmp_1; }();
    project->Save(dataDir + u"ReducingGapBetweenTasksListAndFooter_out.pdf", System::StaticCast<Aspose::Tasks::Saving::SaveOptions>(pdfSaveOptions));
    
    auto htmlSaveOptions = [&]{ auto tmp_2 = System::MakeObject<HtmlSaveOptions>(); tmp_2->set_ReduceFooterGap(false); tmp_2->set_IncludeProjectNameInPageHeader(false); tmp_2->set_IncludeProjectNameInTitle(false); tmp_2->set_PageSize(Aspose::Tasks::Visualization::PageSize::A0); tmp_2->set_Timescale(Aspose::Tasks::Visualization::Timescale::Days); return tmp_2; }();
    project->Save(dataDir + u"ReducingGapBetweenTasksListAndFooter_out.html", htmlSaveOptions);
    //ExEnd: ReducingGapBetweenTasksListAndFooter
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
