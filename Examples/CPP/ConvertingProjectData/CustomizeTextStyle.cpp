/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "../ConvertingProjectData/CustomizeTextStyle.h"

#include <visualization/View/Styles/TextStyle.h>
#include <visualization/Enums/TextItemType.h>
#include <visualization/Enums/PresentationFormat.h>
#include <visualization/FontStyles.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/setters_wrap.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <system/collections/list.h>
#include <saving/SaveOptions.h>
#include <saving/Pdf/PdfSaveOptions.h>
#include <Project.h>
#include <drawing/font_style.h>
#include <drawing/color.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(1527304934u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::CustomizeTextStyle, ThisTypeBaseTypesInfo);

void CustomizeTextStyle::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:CustomizeTextStyle
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_PresentationFormat(Aspose::Tasks::Visualization::PresentationFormat::ResourceSheet);
    
    System::SharedPtr<TextStyle> style = System::MakeObject<TextStyle>(FontStyles::Italic | FontStyles::Bold);
    style->set_Color(System::Drawing::Color::get_OrangeRed());
    style->set_ItemType(Aspose::Tasks::Visualization::TextItemType::OverallocatedResources);
    
    options->set_TextStyles(System::MakeObject<System::Collections::Generic::List<System::SharedPtr<TextStyle>>>());
    options->get_TextStyles()->Add(style);
    project->Save(dataDir + u"CustomizeTextStyle_out.pdf", options);
    // ExEnd:CustomizeTextStyle
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
