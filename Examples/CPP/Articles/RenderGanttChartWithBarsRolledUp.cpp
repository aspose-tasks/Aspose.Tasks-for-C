/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderGanttChartWithBarsRolledUp.h"

#include <visualization/View/PageSize.h>
#include <visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/io/path.h>
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

namespace Articles {

RTTI_INFO_IMPL_HASH(3820349257u, ::Aspose::Tasks::Examples::CPP::Articles::RenderGanttChartWithBarsRolledUp, ThisTypeBaseTypesInfo);

void RenderGanttChartWithBarsRolledUp::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::String fileName = u"Project2.mpp";
    
    // ExStart:RenderGanttChartWithBarsRolledUp
    System::SharedPtr<PdfSaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_PresentationFormat(Aspose::Tasks::Visualization::PresentationFormat::GanttChart);
    options->set_FitContent(true);
    options->set_RollUpGanttBars(true);
    options->set_DrawNonWorkingTime(true);
    options->set_PageSize(Aspose::Tasks::Visualization::PageSize::A3);
    
    System::String file = System::IO::Path::Combine(dataDir, fileName);
    System::String resultFile = System::IO::Path::Combine(dataDir, u"RenderGanttChartWithBarsNotRolledUp_out.pdf");
    
    System::SharedPtr<Project> project = System::MakeObject<Project>(file);
    //for (int i = 14; i <= 23; i++)
    //    project.GetTaskById(i).HideBar = false;
    project->Save(resultFile, System::StaticCast<Aspose::Tasks::Saving::SaveOptions>(options));
    // ExEnd:RenderGanttChartWithBarsRolledUp
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
