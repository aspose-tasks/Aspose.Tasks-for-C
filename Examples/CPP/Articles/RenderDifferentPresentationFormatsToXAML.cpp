/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderDifferentPresentationFormatsToXAML.h"

#include <aspose.tasks.cpp/visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Xaml/XamlOptions.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(637603822u, ::Aspose::Tasks::Examples::CPP::Articles::RenderDifferentPresentationFormatsToXAML, ThisTypeBaseTypesInfo);

void RenderDifferentPresentationFormatsToXAML::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:RenderDifferentPresentationFormatsToXAML
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    
    PresentationFormat presentationFormat = Aspose::Tasks::Visualization::PresentationFormat::GanttChart;
    System::String resultFile = System::String(u"RenderDifferentPresentationFormatsToXAML_") + System::ObjectExt::ToString(presentationFormat) + u"_out.xaml";
    System::SharedPtr<SaveOptions> options = System::MakeObject<XamlOptions>();
    options->set_PresentationFormat(presentationFormat);
    
    project->Save(dataDir + resultFile, options);
    // ExEnd:RenderDifferentPresentationFormatsToXAML
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
