/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "HideLegendsDuringSave.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Pdf/PdfSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Saving/LegendDrawingOptions.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(2306347293u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::HideLegendsDuringSave, ThisTypeBaseTypesInfo);

void HideLegendsDuringSave::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    // ExStart:HideLegendsDuringSave
    System::SharedPtr<SaveOptions> saveOptions = System::MakeObject<PdfSaveOptions>();
    
    // Set the LegendOnEachPage property to false to hide legends
    saveOptions->set_LegendDrawingOptions(LegendDrawingOptions::NoLegend);
    // ExEnd:HideLegendsDuringSave
    
    project->Save(dataDir + u"HideLegendsDuringSave_out.pdf", saveOptions);
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
