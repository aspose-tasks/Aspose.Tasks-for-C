/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadHeaderFooterInfo.h"

#include <visualization/View/PrinterPaperSize.h>
#include <visualization/PageViewSettings.h>
#include <visualization/PageSettings.h>
#include <visualization/PageMargins.h>
#include <visualization/PageLegend.h>
#include <visualization/PageInfo.h>
#include <visualization/HeaderFooterInfo.h>
#include <visualization/Enums/Legend.h>
#include <visualization/Enums/Border.h>
#include <View.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/primitive_types.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <Project.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(2603176686u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::ReadHeaderFooterInfo, ThisTypeBaseTypesInfo);

void ReadHeaderFooterInfo::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project and project info instances
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
    System::SharedPtr<PageInfo> info = project->get_DefaultView()->get_PageInfo();
    
    System::Console::WriteLine(u"Page data cannot be null : {0} ", System::ObjectExt::Box<bool>(!System::ObjectExt::Equals(info, nullptr)));
    
    if (info != nullptr)
    {
        AssertHeaderFooterCorrect(info);
        AssertPageSettingsCorrect(info);
        AssertPageViewSettingsCorrect(info);
        AssertMarginsCorrect(info);
        AssertLegendCorrect(info);
    }
    
}

void ReadHeaderFooterInfo::AssertHeaderFooterCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info)
{
    System::Console::WriteLine(u"Header left text Equals LEFT HEADER : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Header()->get_LeftText(), u"LEFT HEADER")));
    System::Console::WriteLine(u"Header center text Equals CENTER HEADER : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Header()->get_CenteredText(), u"CENTER HEADER")));
    System::Console::WriteLine(u"Header right text Equals RIGHT HEADER : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Header()->get_RightText(), u"RIGHT HEADER")));
    
    System::Console::WriteLine(u"Footer left text Equals LEFT FOOTER : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Footer()->get_LeftText(), u"LEFT FOOTER")));
    System::Console::WriteLine(u"Footer center text Equals CENTER FOOTER : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Footer()->get_CenteredText(), u"CENTER FOOTER")));
    System::Console::WriteLine(u"Footer right text Equals RIGHT FOOTER : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Footer()->get_RightText(), u"RIGHT FOOTER")));
}

void ReadHeaderFooterInfo::AssertPageSettingsCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info)
{
    System::Console::WriteLine(u"Portrait Orientation is Portrait : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageSettings()->get_IsPortrait(), true)));
    System::Console::WriteLine(u"AdjustToPercentOfNormalSize is enabled : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageSettings()->get_AdjustToPercentOfNormalSize(), true)));
    
    System::Console::WriteLine(u"PercentOfNormalSize Equals 150 : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageSettings()->get_PercentOfNormalSize(), 150)));
    System::Console::WriteLine(u"PagesInWidth Equals 3 : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageSettings()->get_PagesInWidth(), 3)));
    System::Console::WriteLine(u"PagesInHeight Equals 7 : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageSettings()->get_PagesInHeight(), 7)));
    System::Console::WriteLine(u"PaperSize Equals PaperA4 : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_PageSettings()->get_PaperSize(), Aspose::Tasks::Visualization::PrinterPaperSize::PaperA4)));
    System::Console::WriteLine(u"FirstPageNumber : {0} ", System::ObjectExt::Box<int16_t>(info->get_PageSettings()->get_FirstPageNumber()));
}

void ReadHeaderFooterInfo::AssertPageViewSettingsCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info)
{
    System::Console::WriteLine(u"PrintAllSheetColumns is set to false : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageViewSettings()->get_PrintAllSheetColumns(), false)));
    System::Console::WriteLine(u"PrintFirstColumnsCountOnAllPages is set to true : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageViewSettings()->get_PrintFirstColumnsCountOnAllPages(), true)));
    
    System::Console::WriteLine(u"FirstColumnsCount Equals 3 : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageViewSettings()->get_FirstColumnsCount(), 3)));
    System::Console::WriteLine(u"PrintNotes is set to true : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageViewSettings()->get_PrintNotes(), true)));
    System::Console::WriteLine(u"PrintBlankPages is set to false : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageViewSettings()->get_PrintBlankPages(), false)));
    System::Console::WriteLine(u"FitTimescaleToEndOfPage is set to true : {0} ", System::ObjectExt::Box<bool>(System::Equals(info->get_PageViewSettings()->get_FitTimescaleToEndOfPage(), true)));
}

void ReadHeaderFooterInfo::AssertMarginsCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info)
{
    System::Console::WriteLine(u"Margins.Left Equals 1 : {0} ", System::ObjectExt::Box<bool>((info->get_Margins()->get_Left() - 1 <= 1e-5) ? true : false));
    System::Console::WriteLine(u"Margins.Top Equals 1.1 : {0} ", System::ObjectExt::Box<bool>((info->get_Margins()->get_Top() - 1.1 <= 1e-5) ? true : false));
    System::Console::WriteLine(u"Margins.Right Equals 1.2 : {0} ", System::ObjectExt::Box<bool>((info->get_Margins()->get_Right() - 1.2 <= 1e-5) ? true : false));
    System::Console::WriteLine(u"Margins.Bottom Equals 1.2 : {0} ", System::ObjectExt::Box<bool>((info->get_Margins()->get_Bottom() - 1.3 <= 1e-5) ? true : false));
    
    System::Console::WriteLine(u"Margin.Borders Equals Border.AroundEveryPage : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Margins()->get_Borders(), Aspose::Tasks::Visualization::Border::AroundEveryPage)));
}

void ReadHeaderFooterInfo::AssertLegendCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info)
{
    System::Console::WriteLine(u"Legend left text Equals LEFT LEGEND : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Legend()->get_LeftText(), u"LEFT LEGEND")));
    System::Console::WriteLine(u"Legend center text Equals CENTER LEGEND : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Legend()->get_CenteredText(), u"CENTER LEGEND")));
    System::Console::WriteLine(u"Legend right text Equals RIGHT LEGEND : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Legend()->get_RightText(), u"RIGHT LEGEND")));
    
    System::Console::WriteLine(u"LegendOn Equals Legend.OnEveryPage : {0} ", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(info->get_Legend()->get_LegendOn(), Aspose::Tasks::Visualization::Legend::OnEveryPage)));
    System::Console::WriteLine(u"Legend Width Equals 5 : {0} ", System::ObjectExt::Box<bool>((info->get_Legend()->get_Width() - 5 <= 1e-5) ? true : false));
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
