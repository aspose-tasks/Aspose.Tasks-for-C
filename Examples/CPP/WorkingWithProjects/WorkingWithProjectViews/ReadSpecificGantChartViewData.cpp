/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithProjectViews/ReadSpecificGantChartViewData.h"

#include <visualization/View/TimescaleTier.h>
#include <visualization/View/Styles/GanttBarStyle.h>
#include <visualization/View/RecurringInterval.h>
#include <visualization/View/ProgressLines.h>
#include <visualization/View/Gridlines.h>
#include <visualization/Enums/TimescaleUnit.h>
#include <visualization/Enums/LinePattern.h>
#include <visualization/Enums/Interval.h>
#include <visualization/Enums/GridlineType.h>
#include <visualization/Enums/GanttBarMiddleShape.h>
#include <visualization/Enums/GanttBarEndShape.h>
#include <visualization/Enums/DateLabel.h>
#include <ViewCollection.h>
#include <View.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <GanttChartView.h>
#include <enums/GanttBarSize.h>
#include <enums/Field.h>
#include <drawing/string_alignment.h>
#include <drawing/color.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectViews {

RTTI_INFO_IMPL_HASH(917273115u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectViews::ReadSpecificGantChartViewData, ThisTypeBaseTypesInfo);

void ReadSpecificGantChartViewData::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadSpecificGantChartViewData   
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadSpecificGantChartViewData.mpp");
    
    System::SharedPtr<GanttChartView> view = System::DynamicCast_noexcept<Aspose::Tasks::GanttChartView>(project->get_Views()->ToList()->idx_get(0));
    System::Console::WriteLine(System::String(u"Is Bar Rounding: ") + view->get_BarRounding());
    System::Console::WriteLine(System::String(u"Show Bar Splits? : ") + view->get_ShowBarSplits());
    System::Console::WriteLine(System::String(u"Show Drawings? : ") + view->get_ShowDrawings());
    System::Console::WriteLine(System::String(u"Roll Up Gantt Bars? ") + view->get_RollUpGanttBars());
    System::Console::WriteLine(System::String(u"Hide Rollup Bars When Summary Expa0nded: ") + view->get_HideRollupBarsWhenSummaryExpanded());
    System::Console::WriteLine(System::String(u"Bar Size: ") + System::ObjectExt::ToString(view->get_BarSize()));
    System::Console::WriteLine(System::String(u"Bar Style: ") + view->get_BarStyles()->get_Count());
    System::Console::WriteLine(u"\n************************ RETREIVING BAR STYLES INFORMATION FROM THE VIEW *********************");
    int32_t i = 0;
    
    {
        auto barStyle_enumerator = (view->get_BarStyles())->GetEnumerator();
        while (barStyle_enumerator->MoveNext())
        {
            auto&& barStyle = barStyle_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Name: ") + barStyle->get_Name());
            System::Console::WriteLine(System::String(u"ShowForCategories: ") + System::ObjectExt::ToString(barStyle->get_ShowForCategories()));
            System::Console::WriteLine(System::String(u"ShowForTaskUid: ") + System::ObjectExt::ToString(barStyle->get_ShowForTaskUid()));
            System::Console::WriteLine(System::String(u"Row: ") + barStyle->get_Row());
            System::Console::WriteLine(System::String(u"From: ") + System::ObjectExt::ToString(barStyle->get_From()));
            System::Console::WriteLine(System::String(u"To: ") + System::ObjectExt::ToString(barStyle->get_To()));
            System::Console::WriteLine(System::String(u"MiddleShape: ") + System::ObjectExt::ToString(barStyle->get_MiddleShape()));
            System::Console::WriteLine(System::String(u"MiddleShapeColor: ") + barStyle->get_MiddleShapeColor());
            System::Console::WriteLine(System::String(u"StartShape: ") + System::ObjectExt::ToString(barStyle->get_StartShape()));
            System::Console::WriteLine(System::String(u"EndShape: ") + System::ObjectExt::ToString(barStyle->get_EndShape()));
            System::Console::WriteLine(System::String(u"EndShapeColor: ") + barStyle->get_EndShapeColor());
            i++;
        }
    }
    
    System::Console::WriteLine(System::String(u"Grid Lines Count: ") + view->get_Gridlines()->get_Count());
    System::SharedPtr<Gridlines> gridlines = view->get_Gridlines()->idx_get(0);
    System::Console::WriteLine(u"\n************************ RETREIVING GRID LINES PROPERTIES *********************");
    System::Console::WriteLine(System::String(u"GridLine Type: ") + System::ObjectExt::ToString(gridlines->get_Type()));
    System::Console::WriteLine(System::String(u"Gridlines Internval: ") + gridlines->get_Interval());
    System::Console::WriteLine(System::String(u"Gridlines Color: ") + gridlines->get_NormalColor());
    System::Console::WriteLine(System::String(u"Gridlines NormalPattern: ") + System::ObjectExt::ToString(gridlines->get_NormalPattern()));
    System::Console::WriteLine(System::String(u"Gridlines IntervalPattern: ") + System::ObjectExt::ToString(gridlines->get_IntervalPattern()));
    System::Console::WriteLine(System::String(u"Gridlines IntervalColor: ") + gridlines->get_IntervalColor());
    System::Console::WriteLine(u"\n************************ RETREIVING PROGRESS LINES PROPERTIES *********************");
    System::Console::WriteLine(u"ProgressLInes.BeginAtDate: ", System::ObjectExt::Box<System::DateTime>(view->get_ProgressLines()->get_BeginAtDate()));
    System::Console::WriteLine(System::String(u"ProgressLines.isBaselinePlan: ") + view->get_ProgressLines()->get_IsBaselinePlan());
    System::Console::WriteLine(System::String(u"ProgressLines.DisplaySelected: ") + view->get_ProgressLines()->get_DisplaySelected());
    System::Console::WriteLine(System::String(u"ProgressLines.SelectedDates.Count: ") + view->get_ProgressLines()->get_SelectedDates()->get_Count());
    System::Console::WriteLine(System::String(u"ProgressLines.SelectedDates[0]: ") + view->get_ProgressLines()->get_SelectedDates()->idx_get(0));
    System::Console::WriteLine(System::String(u"ProgressLines.SelectedDates[1]: ") + view->get_ProgressLines()->get_SelectedDates()->idx_get(1));
    System::Console::WriteLine(System::String(u"ProgressLines.SelectedDates[2]: ") + view->get_ProgressLines()->get_SelectedDates()->idx_get(2));
    System::Console::WriteLine(System::String(u"ProgressLines.DisplayAtRecurringIntervals: ") + view->get_ProgressLines()->get_DisplayAtRecurringIntervals());
    System::Console::WriteLine(System::String(u"ProgressLines.RecurringInterval.Interval: ") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::Interval::Weekly), System::ObjectExt::Box<Interval>(view->get_ProgressLines()->get_RecurringInterval()->get_Interval()));
    System::Console::WriteLine(System::String(u"ProgressLines.RecurringInterval.WeeklyDays.Count") + view->get_ProgressLines()->get_RecurringInterval()->get_WeeklyDays()->get_Count());
    System::Console::WriteLine(System::String(u"Recurring Interval.WeeklyDays: ") + view->get_ProgressLines()->get_RecurringInterval()->get_WeeklyDays());
    System::Console::WriteLine(System::String(u"Recurring Interval.DayType.Saturday: ") + view->get_ProgressLines()->get_RecurringInterval()->get_WeeklyDays());
    System::Console::WriteLine(System::String(u"Recurring Interval.DayType.Sunday: ") + view->get_ProgressLines()->get_RecurringInterval()->get_WeeklyDays());
    System::Console::WriteLine(System::String(u"ProgressLines.ShowDate: ") + view->get_ProgressLines()->get_ShowDate());
    System::Console::WriteLine(System::String(u"ProgressLines.ProgressPointShape: ") + System::ObjectExt::ToString(view->get_ProgressLines()->get_ProgressPointShape()));
    System::Console::WriteLine(System::String(u"ProgressLines.ProgressPointColor: ") + view->get_ProgressLines()->get_ProgressPointColor());
    System::Console::WriteLine(System::String(u"ProgressLines.LineColor: ") + System::Drawing::Color::get_Red(), System::ObjectExt::Box<System::Drawing::Color>(view->get_ProgressLines()->get_LineColor()));
    System::Console::WriteLine(System::String(u"ProgressLines.LinePattern: ") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::LinePattern::Solid), System::ObjectExt::Box<LinePattern>(view->get_ProgressLines()->get_LinePattern()));
    System::Console::WriteLine(System::String(u"ProgressLines.OtherProgressPointShape: ") + System::ObjectExt::ToString(view->get_ProgressLines()->get_OtherProgressPointShape()));
    System::Console::WriteLine(System::String(u"ProgressLines.OtherProgressPointColor: ") + System::ObjectExt::ToString(view->get_ProgressLines()->get_OtherProgressPointColor()));
    System::Console::WriteLine(System::String(u"ProgressLines.OtherLineColor: ") + view->get_ProgressLines()->get_OtherLineColor());
    System::Console::WriteLine(u"\n************************ BOTTOM TIMESCALE IFORMATION ******************");
    System::Console::WriteLine(System::String(u"BottomTimescaleTier.Count:") + view->get_BottomTimescaleTier()->get_Count());
    System::Console::WriteLine(System::String(u"BottomTimescaleTier.Unit:") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::TimescaleUnit::Days), System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_BottomTimescaleTier()->get_Unit())));
    System::Console::WriteLine(System::String(u"BottomTimescaleTier.UsesFiscalYear: ") + view->get_BottomTimescaleTier()->get_UsesFiscalYear());
    System::Console::WriteLine(System::String(u"BottomTimescaleTier.Alignment: ") + System::ObjectExt::ToString(System::Drawing::StringAlignment::Center), System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_BottomTimescaleTier()->get_Alignment())));
    System::Console::WriteLine(System::String(u"BottomTimescaleTier.ShowTicks: ") + System::Convert::ToString(view->get_BottomTimescaleTier()->get_ShowTicks()));
    System::Console::WriteLine(System::String(u"BottomTimescaleTier.Label:") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::DateLabel::DayDi), System::ObjectExt::Box<DateLabel>(view->get_BottomTimescaleTier()->get_Label()));
    System::Console::WriteLine(u"\n************************ MIDDLE TIMESCALE IFORMATION ******************");
    System::Console::WriteLine(System::String(u"MiddleTimescaleTier.Count:") + view->get_MiddleTimescaleTier()->get_Count());
    System::Console::WriteLine(System::String(u"MiddleTimescaleTier.Unit:") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::TimescaleUnit::Days), System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_MiddleTimescaleTier()->get_Unit())));
    System::Console::WriteLine(System::String(u"MiddleTimescaleTier.UsesFiscalYear: ") + view->get_MiddleTimescaleTier()->get_UsesFiscalYear());
    System::Console::WriteLine(System::String(u"MiddleTimescaleTier.Alignment: ") + System::ObjectExt::ToString(System::Drawing::StringAlignment::Center), System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_MiddleTimescaleTier()->get_Alignment())));
    System::Console::WriteLine(System::String(u"MiddleTimescaleTier.ShowTicks: ") + System::Convert::ToString(view->get_MiddleTimescaleTier()->get_ShowTicks()));
    System::Console::WriteLine(System::String(u"MiddleTimescaleTier.Label:") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::DateLabel::DayDi), System::ObjectExt::Box<DateLabel>(view->get_MiddleTimescaleTier()->get_Label()));
    System::Console::WriteLine(u"\n************************ TOP TIMESCALE IFORMATION ******************");
    System::Console::WriteLine(System::String(u"TopTimescaleTier.Unit:") + System::ObjectExt::ToString(Aspose::Tasks::Visualization::TimescaleUnit::Days), System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_TopTimescaleTier()->get_Unit())));
    System::Console::WriteLine(System::String(u"TopTimescaleTier.UsesFiscalYear: ") + view->get_TopTimescaleTier()->get_UsesFiscalYear());
    System::Console::WriteLine(System::String(u"TopTimescaleTier.Alignment: ") + System::ObjectExt::ToString(System::Drawing::StringAlignment::Center), System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_TopTimescaleTier()->get_Alignment())));
    System::Console::WriteLine(System::String(u"TopTimescaleTier.ShowTicks: ") + System::Convert::ToString(view->get_TopTimescaleTier()->get_ShowTicks()));
    System::Console::WriteLine(u"TopTimescaleTier.Label: ", System::ObjectExt::Box<System::String>(System::ObjectExt::ToString(view->get_TopTimescaleTier()->get_Label())));
    // ExEnd:ReadSpecificGantChartViewData
}

} // namespace WorkingWithProjectViews
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
