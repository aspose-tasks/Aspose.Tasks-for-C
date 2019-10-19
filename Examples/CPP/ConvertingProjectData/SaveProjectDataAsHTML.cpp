/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/SaveProjectDataAsHTML.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <saving/Html/HtmlSaveOptions.h>
#include <Project.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(4061357406u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::SaveProjectDataAsHTML, ThisTypeBaseTypesInfo);

void SaveProjectDataAsHTML::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SaveProjectDataAsHTML
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    System::SharedPtr<HtmlSaveOptions> option = System::MakeObject<HtmlSaveOptions>();
    project->Save(dataDir + u"SaveProjectDataAsHTML_out.html", option);
    
    // OR
    
    // Adding only one page (page number 2)
    option = System::MakeObject<HtmlSaveOptions>();
    option->get_Pages()->Add(2);
    project->Save(dataDir + u"SaveProjectDataAsHTML2_out.html", option);
    // ExEnd:SaveProjectDataAsHTML
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
