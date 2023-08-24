/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/SaveToMultiplePDFFiles.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Pdf/PdfSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(3352159826u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::SaveToMultiplePDFFiles, ThisTypeBaseTypesInfo);

void SaveToMultiplePDFFiles::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SaveToMultiplePDFFiles
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Software Development Plan.mpp");
    System::SharedPtr<PdfSaveOptions> saveOptions = System::MakeObject<PdfSaveOptions>();
    saveOptions->set_SaveToSeparateFiles(true);
    saveOptions->set_Pages(System::MakeObject<System::Collections::Generic::List<int32_t>>());
    saveOptions->get_Pages()->Add(1);
    saveOptions->get_Pages()->Add(4);
    project->Save(dataDir + u"SaveToMultiplePDFFiles_out.pdf", System::ExplicitCast<Aspose::Tasks::Saving::SaveOptions>(saveOptions));
    // ExEnd:SaveToMultiplePDFFiles
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
