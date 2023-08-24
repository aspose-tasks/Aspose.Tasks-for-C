/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderTaskUsageView.h"

#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <aspose.tasks.cpp/visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Pdf/PdfSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3315732613u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::RenderTaskUsageView, ThisTypeBaseTypesInfo);

void RenderTaskUsageView::Run()
{
    // ExStart:RenderTaskUsageView
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"TaskUsageView.mpp");
    
    // Define the SaveOptions with required TimeScale settings as Days
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Days);
    
    // Set the Presentation format to ResourceUsage
    options->set_PresentationFormat(Aspose::Tasks::Visualization::PresentationFormat::TaskUsage);
    
    // Save the Project
    System::String outputProject = u"project_TaskUsageView_result_days_out.pdf";
    project1->Save(dataDir + outputProject, options);
    
    // Set the Tiemscale settings to ThirdsOfMonths
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    
    // Save the Project
    outputProject = u"project_TaskUsageView_result_thirdsOfMonths_out.pdf";
    project1->Save(dataDir + outputProject, options);
    
    // Set the Timescale settings to Months
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Months);
    
    // Save the project
    outputProject = u"project_TaskUsageView_result_months_out.pdf";
    project1->Save(dataDir + outputProject, options);
    // ExEnd:RenderTaskUsageView
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
