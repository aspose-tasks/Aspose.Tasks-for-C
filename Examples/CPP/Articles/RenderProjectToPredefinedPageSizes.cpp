/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderProjectToPredefinedPageSizes.h"

#include <visualization/View/PageSize.h>
#include <visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enum.h>
#include <system/array.h>
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

RTTI_INFO_IMPL_HASH(2355156363u, ::Aspose::Tasks::Examples::CPP::Articles::RenderProjectToPredefinedPageSizes, ThisTypeBaseTypesInfo);

void RenderProjectToPredefinedPageSizes::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:RenderProjectToPredefinedPageSizes
    // Source File to Render
    System::String fileName = u"Project2.mpp";
    
    // Read the Project
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + fileName);
    
    // Select a Presentation format
    PresentationFormat format = Aspose::Tasks::Visualization::PresentationFormat::GanttChart;
    
    // Render the project to all Pre-Defined page sizes
    
    {
        for (PageSize pageSize : System::DynamicCast<System::Array<Aspose::Tasks::Visualization::PageSize>>(System::Enum<PageSize>::GetValues()))
        {
            if (pageSize == Aspose::Tasks::Visualization::PageSize::DefinedInView) continue;

            System::SharedPtr<PdfSaveOptions> options = System::MakeObject<PdfSaveOptions>();
            options->set_PresentationFormat(format);
            options->set_FitContent(true);
            options->set_PageSize(pageSize);
            System::String resultFile = System::String(u"result_PredefinedPageSizes_") + System::ObjectExt::ToString(format) + u"_" + System::ObjectExt::ToString(pageSize) + u"_out.pdf";
            project1->Save(dataDir + resultFile, System::StaticCast<Aspose::Tasks::Saving::SaveOptions>(options));
        }
        
    }
    // ExEnd:RenderProjectToPredefinedPageSizes
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
