/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderResourceUsageView.h"

#include <visualization/Enums/Timescale.h>
#include <visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
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

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(2845093445u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::RenderResourceUsageView, ThisTypeBaseTypesInfo);

void RenderResourceUsageView::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:RenderResourceUsageView
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceUsageView.mpp");
    
    // Define the SaveOptions with required TimeScale settings as Days
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Days);
    
    // Set the Presentation format to ResourceUsage
    options->set_PresentationFormat(Aspose::Tasks::Visualization::PresentationFormat::ResourceUsage);
    
    // Save the Project
    System::String outputFile = u"result_ResourceUsageView_days_out.pdf";
    project1->Save(dataDir + outputFile, options);
    
    // Set the Tiemscale settings to ThirdsOfMonths and save the Project
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    outputFile = u"result_ResourceUsageView_thirdsOfMonths_out.pdf";
    project1->Save(dataDir + outputFile, options);
    
    // Set the Timescale settings to Months and save the Project
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::Months);
    outputFile = u"result_ResourceUsageView_months_out.pdf";
    project1->Save(dataDir + outputFile, options);
    // ExEnd:RenderResourceUsageView
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
