/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/SaveProjectAsSVG.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(412478843u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::SaveProjectAsSVG, ThisTypeBaseTypesInfo);

void SaveProjectAsSVG::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SaveProjectAsSVG
    // Read the input Project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject1.mpp");
    
    // Save the Project as SVG
    project->Save(dataDir + u"SaveProjectAsSVG_out.SVG", Aspose::Tasks::Saving::SaveFileFormat::Svg);
    // ExEnd:SaveProjectAsSVG
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
