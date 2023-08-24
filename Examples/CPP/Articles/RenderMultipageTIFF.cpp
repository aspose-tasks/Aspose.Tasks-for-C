/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderMultipageTIFF.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Image/ImageSaveOptions.h>
#include <aspose.tasks.cpp/saving/Image/Enums/TiffCompression.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(1962243355u, ::Aspose::Tasks::Examples::CPP::Articles::RenderMultipageTIFF, ThisTypeBaseTypesInfo);

void RenderMultipageTIFF::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:RenderMultipageTIFF
    // Source file to be converted to TIFF
    System::String file = u"Project2.mpp";
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + file);
    
    // Save the project to TIFF
    project->Save(dataDir + u"RenderMultipageTIFF_out.tif", Aspose::Tasks::Saving::SaveFileFormat::Tiff);
    
    // Save the project with CCITT4 compression
    System::SharedPtr<ImageSaveOptions> options = System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::Tiff);
    options->set_TiffCompression(Aspose::Tasks::Saving::TiffCompression::Ccitt4);
    project->Save(dataDir + u"RenderMultipageTIFF_options_out.tif", System::ExplicitCast<Aspose::Tasks::Saving::SaveOptions>(options));
    
    // Remove the compression
    options->set_TiffCompression(Aspose::Tasks::Saving::TiffCompression::None);
    project->Save(dataDir + u"RenderMultipageTIFF_comp_none_out.tif", System::ExplicitCast<Aspose::Tasks::Saving::SaveOptions>(options));
    // ExEnd:RenderMultipageTIFF
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
