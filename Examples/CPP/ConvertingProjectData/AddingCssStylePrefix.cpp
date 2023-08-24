#include "AddingCssStylePrefix.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Html/HtmlSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(1446574182u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::AddingCssStylePrefix, ThisTypeBaseTypesInfo);

void AddingCssStylePrefix::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:AddingCssStylePrefix
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    System::SharedPtr<HtmlSaveOptions> options = [&]{ auto tmp_0 = System::MakeObject<HtmlSaveOptions>(); tmp_0->set_CssStylePrefix(u"test_prefix"); return tmp_0; }();
    
    project->Save(dataDir + u"TestCssStylePrefix_out.html", options);
    // ExEnd:AddingCssStylePrefix
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
