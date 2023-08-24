/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "AlignCellContents.h"

#include <aspose.tasks.cpp/visualization/View/ViewColumn.h>
#include <aspose.tasks.cpp/visualization/View/ResourceViewColumn.h>
#include <aspose.tasks.cpp/visualization/View/ProjectView.h>
#include <aspose.tasks.cpp/visualization/View/GanttChartColumn.h>
#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <aspose.tasks.cpp/visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Pdf/PdfSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Visualization/View/HorizontalStringAlignment.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(3207564405u, ::Aspose::Tasks::Examples::CPP::Articles::AlignCellContents, ThisTypeBaseTypesInfo);

void AlignCellContents::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:AlignCellContents
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Months);
    options->set_View(ProjectView::GetDefaultGanttChartView());
    
    System::SharedPtr<GanttChartColumn> column1 = System::ExplicitCast<Aspose::Tasks::Visualization::GanttChartColumn>(options->get_View()->get_Columns()->idx_get(2));
    column1->set_StringAlignment(HorizontalStringAlignment::Center);
    column1 = System::ExplicitCast<Aspose::Tasks::Visualization::GanttChartColumn>(options->get_View()->get_Columns()->idx_get(3));
    column1->set_StringAlignment(HorizontalStringAlignment::Far);
    column1 = System::ExplicitCast<Aspose::Tasks::Visualization::GanttChartColumn>(options->get_View()->get_Columns()->idx_get(4));
    column1->set_StringAlignment(HorizontalStringAlignment::Far);
    
    project->Save(dataDir + u"AlignCellContents_GanttChart_out.pdf", options);
    
    options->set_PresentationFormat(Aspose::Tasks::Visualization::PresentationFormat::ResourceSheet);
    options->set_View(ProjectView::GetDefaultResourceSheetView());
    
    System::SharedPtr<ResourceViewColumn> column2 = System::ExplicitCast<Aspose::Tasks::Visualization::ResourceViewColumn>(options->get_View()->get_Columns()->idx_get(2));
    column2->set_StringAlignment(HorizontalStringAlignment::Center);
    column2 = System::ExplicitCast<Aspose::Tasks::Visualization::ResourceViewColumn>(options->get_View()->get_Columns()->idx_get(3));
    column2->set_StringAlignment(HorizontalStringAlignment::Far);
    column2 = System::ExplicitCast<Aspose::Tasks::Visualization::ResourceViewColumn>(options->get_View()->get_Columns()->idx_get(4));
    column2->set_StringAlignment(HorizontalStringAlignment::Far);
    
    project->Save(dataDir + u"AlignCellContents_ResourceSheet_out.pdf", options);
    // ExEnd:AlignCellContents
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
