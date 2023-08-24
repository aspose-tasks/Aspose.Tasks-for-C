/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
 * 
*/
#include "SaveProjectAsJPEG.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Image/ImageSaveOptions.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(1420606801u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::SaveProjectAsJPEG, ThisTypeBaseTypesInfo);

void SaveProjectAsJPEG::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    //ExStart: SaveProjectAsJPEG
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    // in order to manipulate JPEG quality one can use ImageSaveOptions.JpegQuality property.
    // The allowed value range is 0..100.
    auto options = [&]{ auto tmp_0 = System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::Jpeg); tmp_0->set_JpegQuality(50); return tmp_0; }();
    
    project->Save(dataDir + u"image_out.jpeg", System::ExplicitCast<Aspose::Tasks::Saving::SaveOptions>(options));
    //ExEnd: SaveProjectAsJPEG
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
