/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ChangeGanttBarsColorGradient.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Xaml/XamlOptions.h>
#include <saving/SaveOptions.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(3597980571u, ::Aspose::Tasks::Examples::CPP::Articles::ChangeGanttBarsColorGradient, ThisTypeBaseTypesInfo);

void ChangeGanttBarsColorGradient::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ChangeGanttBarsColorGradient
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
    
    System::SharedPtr<SaveOptions> options = System::MakeObject<XamlOptions>();
    options->set_UseGradientBrush(false);
    project->Save(dataDir + u"ChangeGanttBarsColorGradient_Solid_out.xaml", options);
    
    options->set_UseGradientBrush(true);
    project->Save(dataDir + u"ChangeGanttBarsColorGradient_Gradient_out.xaml", options);
    // ExEnd:ChangeGanttBarsColorGradient
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
