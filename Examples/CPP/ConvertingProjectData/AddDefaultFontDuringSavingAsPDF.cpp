/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
 * 
*/
#include "AddDefaultFontDuringSavingAsPDF.h"

#include <visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <saving/SaveOptions.h>
#include <saving/Pdf/PdfSaveOptions.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(992021873u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::AddDefaultFontDuringSavingAsPDF, ThisTypeBaseTypesInfo);

void AddDefaultFontDuringSavingAsPDF::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    //ExStart: AddDefaultFontDuringSavingAsPDF
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    auto options = [&]{ auto tmp_0 = System::MakeObject<PdfSaveOptions>(); tmp_0->set_PresentationFormat(Aspose::Tasks::Visualization::PresentationFormat::GanttChart); tmp_0->set_FitContent(true); tmp_0->set_UseProjectDefaultFont(false); tmp_0->set_DefaultFontName(u"Segoe UI Black"); return tmp_0; }();
    project->Save(dataDir + u"CreateProject2_out.pdf", System::StaticCast<Aspose::Tasks::Saving::SaveOptions>(options));
    //ExEnd: AddDefaultFontDuringSavingAsPDF
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
