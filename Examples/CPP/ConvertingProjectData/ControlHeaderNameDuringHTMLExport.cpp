/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ControlHeaderNameDuringHTMLExport.h"

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

RTTI_INFO_IMPL_HASH(55874192u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::ControlHeaderNameDuringHTMLExport, ThisTypeBaseTypesInfo);

void ControlHeaderNameDuringHTMLExport::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ControlHeaderNameDuringHTMLExport
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    System::SharedPtr<HtmlSaveOptions> htmlSaveOptions = System::MakeObject<HtmlSaveOptions>();
    
    // Determines whether to include project name in HTML title (true by default)
    htmlSaveOptions->set_IncludeProjectNameInTitle(false);
    
    // Determines whether to include project name in HTML page header  (true by default)
    htmlSaveOptions->set_IncludeProjectNameInPageHeader(false);
    
    htmlSaveOptions->set_Pages(System::MakeObject<System::Collections::Generic::List<int32_t>>());
    htmlSaveOptions->get_Pages()->Add(1);
    project->Save(dataDir + u"ControlHeaderNameDuringHTMLExport_out.html", htmlSaveOptions);
    // ExEnd:ControlHeaderNameDuringHTMLExport
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
