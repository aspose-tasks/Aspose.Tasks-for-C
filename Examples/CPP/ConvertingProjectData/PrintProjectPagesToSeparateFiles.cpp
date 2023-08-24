/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/PrintProjectPagesToSeparateFiles.h"

#include <aspose.tasks.cpp/visualization/View/Gridline.h>
#include <aspose.tasks.cpp/visualization/Enums/LinePattern.h>
#include <aspose.tasks.cpp/visualization/Enums/GridlineType.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Image/ImageSaveOptions.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <drawing/color.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(4069296646u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::PrintProjectPagesToSeparateFiles, ThisTypeBaseTypesInfo);

void PrintProjectPagesToSeparateFiles::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:PrintProjectPagesToSeparateFiles
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    System::SharedPtr<ImageSaveOptions> saveOptions = System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::Png);
    saveOptions->set_StartDate(project->Get<System::DateTime>(Prj::StartDate()).AddDays(-3));
    saveOptions->set_EndDate(project->Get<System::DateTime>(Prj::FinishDate()));
    
    saveOptions->set_MarkCriticalTasks(true);
    saveOptions->set_LegendOnEachPage(false);
    
    saveOptions->set_Gridlines(System::MakeObject<System::Collections::Generic::List<System::SharedPtr<Gridline>>>());
    
    System::SharedPtr<Gridline> gridline = System::MakeObject<Gridline>();
    gridline->set_GridlineType(Aspose::Tasks::Visualization::GridlineType::GanttRow);
    gridline->set_Color(System::Drawing::Color::get_CornflowerBlue());
    gridline->set_Pattern(Aspose::Tasks::Visualization::LinePattern::Dashed);
    saveOptions->get_Gridlines()->Add(gridline);
    
    // Save the whole project layout to one file
    saveOptions->set_RenderToSinglePage(true);
    project->Save(dataDir + u"PrintProjectPagesToSeparateFiles1_out.png", System::ExplicitCast<Aspose::Tasks::Saving::SaveOptions>(saveOptions));
    
    // Save project layout to separate files
    saveOptions->set_RenderToSinglePage(false);
    project->Save(dataDir + u"PrintProjectPagesToSeparateFiles2_out.png", System::ExplicitCast<Aspose::Tasks::Saving::SaveOptions>(saveOptions));
    // ExEnd:PrintProjectPagesToSeparateFiles
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
