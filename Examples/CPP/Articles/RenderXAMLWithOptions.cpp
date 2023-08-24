/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderXAMLWithOptions.h"

#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
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

RTTI_INFO_IMPL_HASH(2002889390u, ::Aspose::Tasks::Examples::CPP::Articles::RenderXAMLWithOptions, ThisTypeBaseTypesInfo);

void RenderXAMLWithOptions::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:RenderXAMLWithOptions
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    const System::String resultFile = u"RenderXAMLWithOptions_out.xaml";
    System::SharedPtr<SaveOptions> options = System::MakeObject<XamlOptions>();
    options->set_FitContent(true);
    options->set_LegendOnEachPage(false);
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    project->Save(dataDir + resultFile, options);
    // ExEnd:RenderXAMLWithOptions
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
