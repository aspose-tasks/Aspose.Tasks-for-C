#include "SupportForTextStyle.h"

#include <visualization/View/Styles/TableTextStyle.h>
#include <ViewCollection.h>
#include <View.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/enum_helpers.h>
#include <system/collections/list.h>
#include <Project.h>
#include <GanttChartView.h>
#include <enums/Field.h>
#include <drawing/font_style.h>
#include <drawing/color.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectViews {

RTTI_INFO_IMPL_HASH(685538304u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectViews::SupportForTextStyle, ThisTypeBaseTypesInfo);

void SupportForTextStyle::Run()
{
    // ExStart:SupportForTextStyle
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project5.mpp");
    // Create a new project task
    auto ganttChartView = System::DynamicCast_noexcept<Aspose::Tasks::GanttChartView>(project->get_Views()->ToList()->idx_get(0));
    if (ganttChartView != nullptr)
    {
        ganttChartView->get_TableTextStyles()->Clear();
        ganttChartView->get_TableTextStyles()->Add([&]{ auto tmp_0 = System::MakeObject<TableTextStyle>(1); tmp_0->set_Color(System::Drawing::Color::get_Red()); tmp_0->set_Field(Aspose::Tasks::Field::TaskName); return tmp_0; }());
        ganttChartView->get_TableTextStyles()->Add([&]{ auto tmp_1 = System::MakeObject<TableTextStyle>(1); tmp_1->set_Color(System::Drawing::Color::get_Gray()); tmp_1->set_Field(Aspose::Tasks::Field::TaskDurationText); return tmp_1; }());
        ganttChartView->get_TableTextStyles()->Add([&]{ auto tmp_2 = System::MakeObject<TableTextStyle>(2); tmp_2->set_Color(System::Drawing::Color::get_Blue()); tmp_2->set_FontStyle(System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline); return tmp_2; }());
    }
    // ExEnd:SupportForTextStyle
}

} // namespace WorkingWithProjectViews
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
