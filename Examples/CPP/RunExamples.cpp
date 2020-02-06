#include "RunExamples.h"

#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/path.h>
#include <system/io/directory.h>
#include <system/console.h>
#include <license/License.h>

#include "WorkingWithVBA/ReadVBAProjectInformation.h"
#include "WorkingWithVBA/ReadReferencesInformation.h"
#include "WorkingWithVBA/ReadModulesInformation.h"
#include "WorkingWithVBA/ReadModuleAttributesInformation.h"
#include "WorkingWithTasks/WriteTaskProperties.h"
#include "WorkingWithTasks/WriteTaskDuration.h"
#include "WorkingWithTasks/WriteTaskCalendar.h"
#include "WorkingWithTasks/WorkingWithTaskConstraints/SetConstraintStartNoEarlierThan.h"
#include "WorkingWithTasks/WorkingWithTaskConstraints/SetConstraintMustStartOn.h"
#include "WorkingWithTasks/WorkingWithTaskConstraints/SetConstraintMustFinishOn.h"
#include "WorkingWithTasks/WorkingWithTaskConstraints/SetConstraintFinishNoEarlierThan.h"
#include "WorkingWithTasks/WorkingWithTaskConstraints/SetConstraintAsLateAsPossible.h"
#include "WorkingWithTasks/WorkingWithTaskConstraints/GetConstraints.h"
#include "WorkingWithTasks/ViewSplitTasks.h"
#include "WorkingWithTasks/UpdateTaskData.h"
#include "WorkingWithTasks/TaskWarning.h"
#include "WorkingWithTasks/RenumberTaskWBSCodes.h"
#include "WorkingWithTasks/RenderTaskUsageViewWithDetails.h"
#include "WorkingWithTasks/RenderTaskUsageView.h"
#include "WorkingWithTasks/RenderTaskSheetView.h"
#include "WorkingWithTasks/ReadWriteTimephasedData.h"
#include "WorkingWithTasks/ReadTaskWBS.h"
#include "WorkingWithTasks/ReadTaskProperties.h"
#include "WorkingWithTasks/ReadTaskPriority.h"
#include "WorkingWithTasks/ReadTaskPercentageCompletion.h"
#include "WorkingWithTasks/ReadTaskOvertimes.h"
#include "WorkingWithTasks/ReadTaskOutlineProperties.h"
#include "WorkingWithTasks/ReadTaskExtendedAttributes.h"
#include "WorkingWithTasks/ReadTaskCosts.h"
#include "WorkingWithTasks/ReadTaskCalendar.h"
#include "WorkingWithTasks/ReadStopResumeDates.h"
#include "WorkingWithTasks/ReadParentChildTasks.h"
#include "WorkingWithTasks/ReadBudgetWorkAndCost.h"
#include "WorkingWithTasks/ReadActualTaskProperties.h"
#include "WorkingWithTasks/MoveTaskUnderSameParent.h"
#include "WorkingWithTasks/MoveTaskUnderAnotherParent.h"
#include "WorkingWithTasks/MoveTaskAtTheEnd.h"
#include "WorkingWithTasks/FindEstimatedMilestoneTasks.h"
#include "WorkingWithTasks/FindCriticalEffortDrivenTasks.h"
#include "WorkingWithTasks/CreateTasks.h"
#include "WorkingWithTasks/CreateSubProjectTask.h"
#include "WorkingWithTasks/CreateSplitTasks.h"
#include "WorkingWithTasks/ChangeTaskProgress.h"
#include "WorkingWithTasks/CalculateTaskDurations.h"
#include "WorkingWithTasks/CalculateSplitTaskFinishDate.h"
#include "WorkingWithTasks/AddWBSCodes.h"
#include "WorkingWithTasks/AddTaskExtendedAttributes.h"
#include "WorkingWithTaskLinks/SetTaskLinkType.h"
#include "WorkingWithTaskLinks/IdentifyCrossProjectTasks.h"
#include "WorkingWithTaskLinks/GetTaskLinkType.h"
#include "WorkingWithTaskLinks/GetPredecessorSuccessorTasks.h"
#include "WorkingWithTaskLinks/GetCrossProjectTaskLinks.h"
#include "WorkingWithTaskLinks/CreateTaskLinks.h"
#include "WorkingWithTaskBaselines/GetTaskBaselineSchedule.h"
#include "WorkingWithTaskBaselines/GetTaskBaselineDuration.h"
#include "WorkingWithTaskBaselines/CreateTaskBaseline.h"
#include "WorkingWithResources/UpdateResourceDataInMPP.h"
#include "WorkingWithResources/SetResourceExtendedAttributes.h"
#include "WorkingWithResources/SetResourceCalendar.h"
#include "WorkingWithResources/SetGeneralResourceProperties.h"
#include "WorkingWithResources/ResourcePrefixForNestedResources.h"
#include "WorkingWithResources/RenderResourceUsageView.h"
#include "WorkingWithResources/RenderResourceSheetView.h"
#include "WorkingWithResources/ReadResourceTimephasedData.h"
#include "WorkingWithResources/GetResourceWorkVariance.h"
#include "WorkingWithResources/GetResourcePercentWorkComplete.h"
#include "WorkingWithResources/GetResourceOvertime.h"
#include "WorkingWithResources/GetResourceCosts.h"
#include "WorkingWithResources/GetResourceCalendar.h"
#include "WorkingWithResources/CreateResources.h"
#include "WorkingWithResourceAssignments/UpdateResourceAssignmentInMPP.h"
#include "WorkingWithResourceAssignments/ReadWriteRateScaleForResourceAssignment.h"
#include "WorkingWithResourceAssignments/GetResourceAssignmentVariance.h"
#include "WorkingWithResourceAssignments/GetResourceAssignmentStopResumeDates.h"
#include "WorkingWithResourceAssignments/GetResourceAssignmentPercentWorkComplete.h"
#include "WorkingWithResourceAssignments/GetResourceAssignmentOvertimes.h"
#include "WorkingWithResourceAssignments/GetResourceAssignmentCosts.h"
#include "WorkingWithResourceAssignments/GetResourceAssignmentBudget.h"
#include "WorkingWithResourceAssignments/GetGeneralResourceAssignmentProperties.h"
#include "WorkingWithResourceAssignments/GenerateResourceAssignmentTimephasedData.h"
#include "WorkingWithResourceAssignments/CreateResourceAssignments.h"
#include "WorkingWithResourceAssignments/AddExtendedAttributesToResourceAssignment.h"
#include "WorkingWithResourceAssignments/AddExtendedAttributesToRAWithLookUp.h"
#include "WorkingWithProjects/WorkingWithProjectViews/SupportForTextStyle.h"
#include "WorkingWithProjects/WorkingWithProjectViews/SetTimeScaleCount.h"
#include "WorkingWithProjects/WorkingWithProjectViews/ReadSpecificGantChartViewData.h"
#include "WorkingWithProjects/WorkingWithProjectViews/CustomizeTimescaleTierLabels.h"
#include "WorkingWithProjects/WorkingWithProjectViews/ConfigureTheGantChartViewShowSelectedColumnFields.h"
#include "WorkingWithProjects/WorkingWithProjectViews/ConfigureGantChart.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteWeekdayProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteProjectInfo.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteMPPProjectSummary.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteFiscalYearProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteDefaultProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteCurrencyProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/SetAttributesForNewTasks.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ReadWeekdayProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ReadProjectInfo.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ReadFiscalYearProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ReadDefaultProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ReadCurrencyProperties.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/DetermineProjectVersion.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ApplyCalculationModeNone.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ApplyCalculationModeManual.h"
#include "WorkingWithProjects/WorkingWithProjectProperties/ApplyCalculationModeAuto.h"
#include "WorkingWithProjects/WorkingWithOutlineCodes.h"
#include "WorkingWithProjects/WorkingWithExtendedAttributes/WriteUpdatedExtendedAttributeDefinitions.h"
#include "WorkingWithProjects/WorkingWithExtendedAttributes/WriteExtendedAttributes.h"
#include "WorkingWithProjects/WorkingWithExtendedAttributes/CreateExtendedAttributes.h"
#include "WorkingWithProjects/TaskSettingStartFinishDates.h"
#include "WorkingWithProjects/Rescheduling/UpdateProjectAndRescheduleUncompletedWork.h"
#include "WorkingWithProjects/Rescheduling/RescheduleProjectStartOrFinishDate.h"
#include "WorkingWithProjects/Rescheduling/RescheduleProjectFromStartDate.h"
#include "WorkingWithProjects/Rescheduling/RescheduleProjectFromFinishDate.h"
#include "WorkingWithProjects/ReadHeaderFooterInfo.h"
#include "WorkingWithProjects/MPPFileUpdate.h"
#include "WorkingWithProjects/Miscellaneous/ReadTableDataFromProjectFile.h"
#include "WorkingWithProjects/Miscellaneous/ReadGroupDefinitionData.h"
#include "WorkingWithProjects/Miscellaneous/ReadFilterDefinitionData.h"
#include "WorkingWithProjects/Miscellaneous/ReadFilterCriteriaData.h"
#include "WorkingWithProjects/Miscellaneous/PrintTaskWritingException.h"
#include "WorkingWithProjects/Miscellaneous/EmbeddedObjectsCreatedInsideApplication.h"
#include "WorkingWithProjects/Miscellaneous/CalculateCriticalPath.h"
#include "WorkingWithProjects/ImportingAndExporting/UsingPrimaveraXMLSaveOptions.h"
#include "WorkingWithProjects/ImportingAndExporting/ImportDataFromXMLFileFormats.h"
#include "WorkingWithProjects/ImportingAndExporting/ExportProjectDataToXMLFormat.h"
#include "WorkingWithProjects/ImportingAndExporting/ExportProjectDataToXERFormat.h"
#include "WorkingWithProjects/ImportingAndExporting/ExportProjectDataToPrimaveraMPXFormat.h"
#include "WorkingWithProjects/GetPageCountOnStartAndEndDates.h"
#include "WorkingWithProjects/GetNumberOfPagesForViews.h"
#include "WorkingWithProjects/GetNumberOfPages.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/WorkingWithEncodings.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/ReadProjectFiles.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/ReadProjectFileFromStream.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/ReadPasswordProtectedProjectFile.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/IgnoreInvalidCharactersDuringloadingProject.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/CreateEmptyProjectSaveMPP.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/CreateEmptyProjectSaveXML.h"
#include "WorkingWithProjects/CreatingReadingAndSaving/CreateEmptyProjectSaveStream.h"
#include "WorkingWithProjects/AddImageToPageHeaderFooter.h"
#include "WorkingWithFormulas/WriteFormulasInExtendedAttributesToMPP.h"
#include "WorkingWithFormulas/UsingTasksAndResourceFieldsInFormulaCalculations.h"
#include "WorkingWithFormulas/UsingTaskNumberFields.h"
#include "WorkingWithFormulas/UsingArithmeticExpression.h"
#include "WorkingWithFormulas/ReadFormulasExtendedAttributesFromMPP.h"
#include "WorkingWithFormulas/FormulaWithProjectFields.h"
#include "WorkingWithFormulas/FormulaWithBooleanValues.h"
#include "WorkingWithFormulas/CalculateTextFunctions.h"
#include "WorkingWithFormulas/CalculateMathExpressions.h"
#include "WorkingWithFormulas/CalculateGeneralFunctions.h"
#include "WorkingWithFormulas/CalculateDateTimeFunctions.h"
#include "WorkingWithFormulas/AccessReadOnlyCustomFieldValuesUsingFormulas.h"
#include "WorkingWithCurrencies/SetCurrencySymbol.h"
#include "WorkingWithCurrencies/SetCurrencyDigits.h"
#include "WorkingWithCurrencies/SetCurrencyCodes.h"
#include "WorkingWithCurrencies/GetCurrencySymbol.h"
#include "WorkingWithCurrencies/GetCurrencyDigits.h"
#include "WorkingWithCurrencies/GetCurrencyCodes.h"
#include "WorkingWithCalendars/RetrieveCalendarInfo.h"
#include "WorkingWithCalendars/ReadWorkWeeksInformation.h"
#include "WorkingWithCalendars/GeneralCalendarProperties.h"
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/WriteUpdatedCalendarDataToMPP.h"
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/ReplaceCalendarWithNewCalendar.h"
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/ReplaceCalendar.h"
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/MakeAStandardCalendar.h"
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/DefineWeekdaysForCalendar.h"
#include "WorkingWithCalendars/CreatingUpdatingAndRemoving/CreatingCalendar.h"
#include "WorkingWithCalendars/CalculateWorkHours.h"
#include "WorkingWithCalendarExceptions/RetrieveCalendarExceptions.h"
#include "WorkingWithCalendarExceptions/HandleExceptionOccurences.h"
#include "WorkingWithCalendarExceptions/DefineWeekdayExceptions.h"
#include "WorkingWithCalendarExceptions/AddRemoveCalendarExceptions.h"
#include "Miscellaneous/WriteMetadataToMPP.h"
#include "Miscellaneous/UpdateOutlineCodes.h"
#include "Miscellaneous/SortTasksByName.h"
#include "Miscellaneous/SortResourcesByName.h"
#include "Miscellaneous/SaveWorkOverviewReport.h"
#include "Miscellaneous/SaveUpcomingTasksReport.h"
#include "Miscellaneous/SaveTaskCostOverviewReport.h"
#include "Miscellaneous/SaveSlippingTasksReport.h"
#include "Miscellaneous/SaveResourceOverviewReport.h"
#include "Miscellaneous/SaveResourceCostOverviewReport.h"
#include "Miscellaneous/SaveProjectOverviewReport.h"
#include "Miscellaneous/SaveOverallocatedResourcesReport.h"
#include "Miscellaneous/SaveMilestonesReport.h"
#include "Miscellaneous/SaveLateTasksReport.h"
#include "Miscellaneous/SaveCriticalTasksReport.h"
#include "Miscellaneous/SaveCostOverviewReport.h"
#include "Miscellaneous/SaveCostOverrunsReport.h"
#include "Miscellaneous/SaveCashFlowReport.h"
#include "Miscellaneous/SaveBurnDownReport.h"
#include "Miscellaneous/SaveBestPracticeAnalyzerReport.h"
#include "Miscellaneous/PerformRiskAnalysis.h"
#include "Miscellaneous/HandleExceptions.h"
#include "KnowledgeBase/ReadTaskAndResources.h"
#include "KnowledgeBase/ReadCriticalPath.h"
#include "KnowledgeBase/LinkTasks.h"
#include "KnowledgeBase/CreateResourcesAndLinkToTasks.h"
#include "KnowledgeBase/AddNewTask.h"
#include "ConvertingProjectData/UsingXlsxOptions.h"
#include "ConvertingProjectData/UsingSvgOptions.h"
#include "ConvertingProjectData/UsingSpreadsheet2003SaveOptions.h"
#include "ConvertingProjectData/SaveToMultiplePDFFiles.h"
#include "ConvertingProjectData/SaveProjectDataToSpreadsheet2003XML.h"
#include "ConvertingProjectData/SaveProjectDataAsTemplate.h"
#include "ConvertingProjectData/SaveProjectDataAsHTML.h"
#include "ConvertingProjectData/SaveProjectAsXLSX.h"
#include "ConvertingProjectData/SaveProjectAsText.h"
#include "ConvertingProjectData/SaveProjectAsSVG.h"
#include "ConvertingProjectData/SaveProjectAsPDF.h"
#include "ConvertingProjectData/SaveProjectAsJPEG.h"
#include "ConvertingProjectData/SaveProjectAsCSV.h"
#include "ConvertingProjectData/RenderProjectDataToFormat24bppRgb.h"
#include "ConvertingProjectData/RenderCommentsWhenConverting.h"
#include "ConvertingProjectData/ReducingGapBetweenTasksListAndFooter.h"
#include "ConvertingProjectData/PrintProjectPagesToSeparateFiles.h"
#include "ConvertingProjectData/HideLegendsDuringSave.h"
#include "ConvertingProjectData/FitContentsToCellSize.h"
#include "ConvertingProjectData/CustomizeTextStyle.h"
#include "ConvertingProjectData/CustomizeDateFormats.h"
#include "ConvertingProjectData/ControlHeaderNameDuringHTMLExport.h"
#include "ConvertingProjectData/AddDefaultFontDuringSavingAsPDF.h"
#include "Articles/TimescaleSettings.h"
#include "Articles/SortTasksByColumnInGanttChart.h"
#include "Articles/SetGanttChartViewStartDate.h"
#include "Articles/RenderXAMLWithOptions.h"
#include "Articles/RenderToXAML.h"
#include "Articles/RenderProjectToPredefinedPageSizes.h"
#include "Articles/RenderMultipageTIFF.h"
#include "Articles/RenderGanttChartWithBarsRolledUp.h"
#include "Articles/RenderGanttChartWithBarsNotRolledUp.h"
#include "Articles/RenderDifferentPresentationFormatsToXAML.h"
#include "Articles/ReadCustomBarStyle.h"
#include "Articles/ImplementCustomBarStyleWriting.h"
#include "Articles/CustomizeTextWithTaskBars.h"
#include "Articles/ChangeGanttBarsColorGradient.h"
#include "Articles/AlignCellContents.h"


using namespace Aspose::Tasks::Examples::CPP::Articles;
using namespace Aspose::Tasks::Examples::CPP::ConvertingProjectData;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::ImportingAndExporting;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithResources;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithTasks;
using namespace Aspose::Tasks::Examples::CPP::KnowledgeBase;
using namespace Aspose::Tasks::Examples::CPP::Miscellaneous;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithCalendarExceptions;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithCalendars;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CreatingUpdatingAndRemoving;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithCurrencies;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithFormulas;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::Rescheduling;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithExtendedAttributes;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectViews;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithTaskBaselines;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithTasks::WorkingWithTaskConstraints;
using namespace Aspose::Tasks::Examples::CPP::WorkingWithVBA;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

RTTI_INFO_IMPL_HASH(1854676261u, ::Aspose::Tasks::Examples::CPP::RunExamples, ThisTypeBaseTypesInfo);

void RunExamples::Main()
{
    System::Console::WriteLine(u"Open RunExamples.cs. \nIn Main() method, uncomment the example that you want to run");
    System::Console::WriteLine(u"=====================================================");
    
    System::SharedPtr<License> lic = System::MakeObject<License>();
    
	auto files = System::IO::Directory::GetFiles(u"lic", u"aspose*.lic");
	if (files->get_Length() == 0)
	{
		System::Console::WriteLine(u"Please put license file into 'lic' subdirectory.");
		return;
	}
	System::Console::WriteLine(u"Using license file: " + files[0]);
	lic->SetLicense(files[0]);
    
    // Uncomment the one you want to try out
    
    // =====================================================
    // =====================================================
    // Articles
    // =====================================================
    // =====================================================
    
    Articles::AlignCellContents::Run();
    Articles::ChangeGanttBarsColorGradient::Run();
    Articles::ImplementCustomBarStyleWriting::Run();
    Articles::ReadCustomBarStyle::Run();
    Articles::RenderDifferentPresentationFormatsToXAML::Run();
    Articles::RenderGanttChartWithBarsNotRolledUp::Run();
    Articles::RenderGanttChartWithBarsRolledUp::Run();
    Articles::RenderMultipageTIFF::Run();
    Articles::RenderProjectToPredefinedPageSizes::Run();
    Articles::RenderToXAML::Run();
    Articles::RenderXAMLWithOptions::Run();
    Articles::SetGanttChartViewStartDate::Run();
    Articles::SortTasksByColumnInGanttChart::Run();
    Articles::TimescaleSettings::Run();
    Articles::CustomizeTextWithTaskBars::Run();
    
    
    // C# preprocessor directive: #region Converting Project Data
    
    ConvertingProjectData::AddDefaultFontDuringSavingAsPDF::Run();
    ConvertingProjectData::ControlHeaderNameDuringHTMLExport::Run();
    ConvertingProjectData::CustomizeDateFormats::Run();
    ConvertingProjectData::CustomizeTextStyle::Run();
    ConvertingProjectData::FitContentsToCellSize::Run();
    ConvertingProjectData::HideLegendsDuringSave::Run();
    ConvertingProjectData::PrintProjectPagesToSeparateFiles::Run();
    ConvertingProjectData::ReducingGapBetweenTasksListAndFooter::Run();
    ConvertingProjectData::RenderProjectDataToFormat24bppRgb::Run();
    ConvertingProjectData::SaveProjectAsCSV::Run();
    ConvertingProjectData::SaveProjectAsJPEG::Run();
    ConvertingProjectData::SaveProjectAsPDF::Run();
    ConvertingProjectData::SaveProjectAsSVG::Run();
    ConvertingProjectData::SaveProjectAsText::Run();
    ConvertingProjectData::SaveProjectAsXLSX::Run();
    ConvertingProjectData::SaveProjectDataAsHTML::Run();
    ConvertingProjectData::SaveProjectDataAsTemplate::Run();
    ConvertingProjectData::SaveProjectDataToSpreadsheet2003XML::Run();
    ConvertingProjectData::SaveToMultiplePDFFiles::Run();
    ConvertingProjectData::UsingSpreadsheet2003SaveOptions::Run();
    ConvertingProjectData::UsingSvgOptions::Run();
    ConvertingProjectData::UsingXlsxOptions::Run();
    ConvertingProjectData::RenderCommentsWhenConverting::Run();
    
    // C# preprocessor directive: #endregion
    
    
    // =====================================================
    // =====================================================
    // Knowledge Base
    // =====================================================
    // =====================================================
    
    KnowledgeBase::AddNewTask::Run();
    KnowledgeBase::CreateResourcesAndLinkToTasks::Run();
    KnowledgeBase::LinkTasks::Run();
    KnowledgeBase::ReadCriticalPath::Run();
    KnowledgeBase::ReadTaskAndResources::Run();
    
    // =====================================================
    // =====================================================
    // Miscellaneous
    // =====================================================
    // =====================================================
    
    Miscellaneous::HandleExceptions::Run();
    Miscellaneous::PerformRiskAnalysis::Run();
    Miscellaneous::SaveBestPracticeAnalyzerReport::Run();
    Miscellaneous::SaveBurnDownReport::Run();
    Miscellaneous::SaveCashFlowReport::Run();
    Miscellaneous::SaveCostOverrunsReport::Run();
    Miscellaneous::SaveCostOverviewReport::Run();
    Miscellaneous::SaveCriticalTasksReport::Run();
    Miscellaneous::SaveLateTasksReport::Run();
    Miscellaneous::SaveMilestonesReport::Run();
    Miscellaneous::SaveOverallocatedResourcesReport::Run();
    Miscellaneous::SaveProjectOverviewReport::Run();
    Miscellaneous::SaveResourceCostOverviewReport::Run();
    Miscellaneous::SaveResourceOverviewReport::Run();
    Miscellaneous::SaveSlippingTasksReport::Run();
    Miscellaneous::SaveTaskCostOverviewReport::Run();
    Miscellaneous::SaveUpcomingTasksReport::Run();
    Miscellaneous::SaveWorkOverviewReport::Run();
    Miscellaneous::SortResourcesByName::Run();
    Miscellaneous::SortTasksByName::Run();
    Miscellaneous::UpdateOutlineCodes::Run();
    Miscellaneous::WriteMetadataToMPP::Run();
    
    // =====================================================
    // =====================================================
    // Working With Calendar Exceptions
    // =====================================================
    // =====================================================
    
    WorkingWithCalendarExceptions::RetrieveCalendarExceptions::Run();
    WorkingWithCalendarExceptions::AddRemoveCalendarExceptions::Run();
    WorkingWithCalendarExceptions::DefineWeekdayExceptions::Run();
    WorkingWithCalendarExceptions::HandleExceptionOccurences::Run();
    
    // =====================================================
    // =====================================================
    // Working With Calendars
    // =====================================================
    // =====================================================
    
    WorkingWithCalendars::CalculateWorkHours::Run();
    WorkingWithCalendars::GeneralCalendarProperties::Run();
    WorkingWithCalendars::ReadWorkWeeksInformation::Run();
    WorkingWithCalendars::RetrieveCalendarInfo::Run();
    
    // Creating, Updating and Removing
    // =====================================================
    
    WorkingWithCalendars::CreatingUpdatingAndRemoving::CreatingCalendar::Run();
    WorkingWithCalendars::CreatingUpdatingAndRemoving::DefineWeekdaysForCalendar::Run();
    WorkingWithCalendars::CreatingUpdatingAndRemoving::MakeAStandardCalendar::Run();
    WorkingWithCalendars::CreatingUpdatingAndRemoving::ReplaceCalendar::Run();
    WorkingWithCalendars::CreatingUpdatingAndRemoving::ReplaceCalendarWithNewCalendar::Run();
    WorkingWithCalendars::CreatingUpdatingAndRemoving::WriteUpdatedCalendarDataToMPP::Run();
    
    // =====================================================
    // =====================================================
    // Working With Currencies
    // =====================================================
    // =====================================================
    
    WorkingWithCurrencies::GetCurrencyCodes::Run();
    WorkingWithCurrencies::GetCurrencyDigits::Run();
    WorkingWithCurrencies::GetCurrencySymbol::Run();
    WorkingWithCurrencies::SetCurrencyCodes::Run();
    WorkingWithCurrencies::SetCurrencyDigits::Run();
    WorkingWithCurrencies::SetCurrencySymbol::Run();
    
    // =====================================================
    // =====================================================
    // Working With Formulas
    // =====================================================
    // =====================================================
    
    WorkingWithFormulas::AccessReadOnlyCustomFieldValuesUsingFormulas::Run();
    WorkingWithFormulas::CalculateDateTimeFunctions::Run();
    WorkingWithFormulas::CalculateGeneralFunctions::Run();
    WorkingWithFormulas::CalculateMathExpressions::Run();
    WorkingWithFormulas::CalculateTextFunctions::Run();
    WorkingWithFormulas::FormulaWithBooleanValues::Run();
    WorkingWithFormulas::FormulaWithProjectFields::Run();
    WorkingWithFormulas::ReadFormulasExtendedAttributesFromMPP::Run();
    WorkingWithFormulas::UsingArithmeticExpression::Run();
    WorkingWithFormulas::UsingTaskNumberFields::Run();
    WorkingWithFormulas::UsingTasksAndResourceFieldsInFormulaCalculations::Run();
    WorkingWithFormulas::WriteFormulasInExtendedAttributesToMPP::Run();
    
    // =====================================================
    // =====================================================
    // Working With Projects
    // =====================================================
    // =====================================================
    
    WorkingWithProjects::AddImageToPageHeaderFooter::Run();
    WorkingWithProjects::GetNumberOfPages::Run();
    WorkingWithProjects::GetNumberOfPagesForViews::Run();
    WorkingWithProjects::GetPageCountOnStartAndEndDates::Run();
    WorkingWithProjects::MPPFileUpdate::Run();
    WorkingWithProjects::ReadHeaderFooterInfo::Run();
    WorkingWithProjects::WorkingWithOutlineCodes::Run();
    ConvertingProjectData::SaveProjectDataAsTemplate::Run();
    WorkingWithProjects::TaskSettingStartFinishDates::Run();
    
    // Creating, Reading and Saving
    // =====================================================
    
	WorkingWithProjects::CreatingReadingAndSaving::CreateEmptyProjectSaveMPP::Run();
    WorkingWithProjects::CreatingReadingAndSaving::CreateEmptyProjectSaveXML::Run();
    WorkingWithProjects::CreatingReadingAndSaving::CreateEmptyProjectSaveStream::Run();
    WorkingWithProjects::CreatingReadingAndSaving::IgnoreInvalidCharactersDuringloadingProject::Run();
    
    // C# preprocessor directive: #if !__cplusplus
    
    
    // C# preprocessor directive: #endif
    
    WorkingWithProjects::CreatingReadingAndSaving::ReadPasswordProtectedProjectFile::Run();
    WorkingWithProjects::CreatingReadingAndSaving::ReadProjectFileFromStream::Run();
    WorkingWithProjects::CreatingReadingAndSaving::ReadProjectFiles::Run();
    WorkingWithProjects::CreatingReadingAndSaving::WorkingWithEncodings::Run();
    
    // Importing and Exporting
    // =====================================================
    
    WorkingWithProjects::ImportingAndExporting::ExportProjectDataToPrimaveraMPXFormat::Run();
    WorkingWithProjects::ImportingAndExporting::ExportProjectDataToXERFormat::Run();
    WorkingWithProjects::ImportingAndExporting::ExportProjectDataToXMLFormat::Run();
    WorkingWithProjects::ImportingAndExporting::ImportDataFromXMLFileFormats::Run();
    
    // C# preprocessor directive: #if !__cplusplus
    
    
    // C# preprocessor directive: #endif
    
    WorkingWithProjects::ImportingAndExporting::UsingPrimaveraXMLSaveOptions::Run();
    
    // Miscellaneous
    // =====================================================
    
    WorkingWithProjects::Miscellaneous::CalculateCriticalPath::Run();
    WorkingWithProjects::Miscellaneous::EmbeddedObjectsCreatedInsideApplication::Run();
    WorkingWithProjects::Miscellaneous::PrintTaskWritingException::Run();
    WorkingWithProjects::Miscellaneous::ReadFilterCriteriaData::Run();
    WorkingWithProjects::Miscellaneous::ReadFilterDefinitionData::Run();
    WorkingWithProjects::Miscellaneous::ReadGroupDefinitionData::Run();
    WorkingWithProjects::Miscellaneous::ReadTableDataFromProjectFile::Run();
    
    // Printing
    // =====================================================
    
    // C# preprocessor directive: #if !__cplusplus
    
    
    // C# preprocessor directive: #endif
    
    
    // Rescheduling
    // =====================================================
    
    WorkingWithProjects::Rescheduling::RescheduleProjectFromFinishDate::Run();
    WorkingWithProjects::Rescheduling::RescheduleProjectFromStartDate::Run();
    WorkingWithProjects::Rescheduling::RescheduleProjectStartOrFinishDate::Run();
    WorkingWithProjects::Rescheduling::UpdateProjectAndRescheduleUncompletedWork::Run();
    
    // Working with Extended Attributes
    // =====================================================
    
    WorkingWithProjects::WorkingWithExtendedAttributes::CreateExtendedAttributes::Run();
    WorkingWithProjects::WorkingWithExtendedAttributes::WriteExtendedAttributes::Run();
    WorkingWithProjects::WorkingWithExtendedAttributes::WriteUpdatedExtendedAttributeDefinitions::Run();
    
    // Working with Project properties
    // =====================================================
    
    WorkingWithProjects::WorkingWithProjectProperties::ApplyCalculationModeAuto::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ApplyCalculationModeManual::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ApplyCalculationModeNone::Run();
    WorkingWithProjects::WorkingWithProjectProperties::DetermineProjectVersion::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ReadCurrencyProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ReadDefaultProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ReadFiscalYearProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ReadProjectInfo::Run();
    WorkingWithProjects::WorkingWithProjectProperties::ReadWeekdayProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::SetAttributesForNewTasks::Run();
    WorkingWithProjects::WorkingWithProjectProperties::WriteCurrencyProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::WriteDefaultProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::WriteFiscalYearProperties::Run();
    WorkingWithProjects::WorkingWithProjectProperties::WriteMPPProjectSummary::Run();
    WorkingWithProjects::WorkingWithProjectProperties::WriteProjectInfo::Run();
    WorkingWithProjects::WorkingWithProjectProperties::WriteWeekdayProperties::Run();
    
    // Working with Project Views
    // =====================================================
    
    WorkingWithProjects::WorkingWithProjectViews::ConfigureGantChart::Run();
    WorkingWithProjects::WorkingWithProjectViews::ConfigureTheGantChartViewShowSelectedColumnFields::Run();
    WorkingWithProjects::WorkingWithProjectViews::CustomizeTimescaleTierLabels::Run();
    WorkingWithProjects::WorkingWithProjectViews::ReadSpecificGantChartViewData::Run();
    WorkingWithProjects::WorkingWithProjectViews::SetTimeScaleCount::Run();
    WorkingWithProjects::WorkingWithProjectViews::SupportForTextStyle::Run();
    
    // =====================================================
    // =====================================================
    // Working With Resource Assignments
    // =====================================================
    // =====================================================
    
    WorkingWithResourceAssignments::AddExtendedAttributesToResourceAssignment::Run();
    WorkingWithResourceAssignments::AddExtendedAttributesToRAWithLookUp::Run();
    WorkingWithResourceAssignments::CreateResourceAssignments::Run();
    WorkingWithResourceAssignments::GenerateResourceAssignmentTimephasedData::Run();
    WorkingWithResourceAssignments::GetGeneralResourceAssignmentProperties::Run();
    WorkingWithResourceAssignments::GetResourceAssignmentBudget::Run();
    WorkingWithResourceAssignments::GetResourceAssignmentCosts::Run();
    WorkingWithResourceAssignments::GetResourceAssignmentOvertimes::Run();
    WorkingWithResourceAssignments::GetResourceAssignmentPercentWorkComplete::Run();
    WorkingWithResourceAssignments::GetResourceAssignmentStopResumeDates::Run();
    WorkingWithResourceAssignments::GetResourceAssignmentVariance::Run();
    WorkingWithResourceAssignments::UpdateResourceAssignmentInMPP::Run();
    WorkingWithResourceAssignments::ReadWriteRateScaleForResourceAssignment::Run();
    
    // =====================================================
    // =====================================================
    // Working With Resources
    // =====================================================
    // =====================================================
    
    WorkingWithResources::CreateResources::Run();
    WorkingWithResources::GetResourceCalendar::Run();
    WorkingWithResources::GetResourceCosts::Run();
    WorkingWithResources::GetResourceOvertime::Run();
    WorkingWithResources::GetResourcePercentWorkComplete::Run();
    WorkingWithResources::GetResourceWorkVariance::Run();
    WorkingWithResources::ReadResourceTimephasedData::Run();
    WorkingWithResources::RenderResourceSheetView::Run();
    WorkingWithResources::RenderResourceUsageView::Run();
    WorkingWithResources::SetGeneralResourceProperties::Run();
    WorkingWithResources::SetResourceCalendar::Run();
    WorkingWithResources::SetResourceExtendedAttributes::Run();
    WorkingWithResources::UpdateResourceDataInMPP::Run();
    WorkingWithResources::ResourcePrefixForNestedResources::Run();
    
    // =====================================================
    // =====================================================
    // Working With Task Baselines
    // =====================================================
    // =====================================================
    
    WorkingWithTaskBaselines::CreateTaskBaseline::Run();
    WorkingWithTaskBaselines::GetTaskBaselineDuration::Run();
    WorkingWithTaskBaselines::GetTaskBaselineSchedule::Run();
    
    // =====================================================
    // =====================================================
    // Working With Task Links
    // =====================================================
    // =====================================================
    
    WorkingWithTaskLinks::CreateTaskLinks::Run();
    WorkingWithTaskLinks::GetCrossProjectTaskLinks::Run();
    WorkingWithTaskLinks::GetPredecessorSuccessorTasks::Run();
    WorkingWithTaskLinks::GetTaskLinkType::Run();
    WorkingWithTaskLinks::IdentifyCrossProjectTasks::Run();
    WorkingWithTaskLinks::SetTaskLinkType::Run();
    
    // =====================================================
    // =====================================================
    // Working With Tasks
    // =====================================================
    // =====================================================
    
    // C# preprocessor directive: #region Working with Tasks
    
    WorkingWithTasks::AddTaskExtendedAttributes::Run();
    WorkingWithTasks::AddWBSCodes::Run();
    WorkingWithTasks::CalculateSplitTaskFinishDate::Run();
    WorkingWithTasks::CalculateTaskDurations::Run();
    WorkingWithTasks::ChangeTaskProgress::Run();
    WorkingWithTasks::CreateSplitTasks::Run();
    WorkingWithTasks::CreateSubProjectTask::Run();
    WorkingWithTasks::CreateTasks::Run();
    WorkingWithTasks::FindCriticalEffortDrivenTasks::Run();
    WorkingWithTasks::FindEstimatedMilestoneTasks::Run();
    WorkingWithTasks::MoveTaskAtTheEnd::Run();
    WorkingWithTasks::MoveTaskUnderAnotherParent::Run();
    WorkingWithTasks::MoveTaskUnderSameParent::Run();
    WorkingWithTasks::ReadActualTaskProperties::Run();
    WorkingWithTasks::ReadBudgetWorkAndCost::Run();
    WorkingWithTasks::ReadParentChildTasks::Run();
    WorkingWithTasks::ReadStopResumeDates::Run();
    WorkingWithTasks::ReadTaskCalendar::Run();
    WorkingWithTasks::ReadTaskCosts::Run();
    WorkingWithTasks::ReadTaskExtendedAttributes::Run();
    WorkingWithTasks::ReadTaskOutlineProperties::Run();
    WorkingWithTasks::ReadTaskOvertimes::Run();
    WorkingWithTasks::ReadTaskPercentageCompletion::Run();
    WorkingWithTasks::ReadTaskPriority::Run();
    WorkingWithTasks::ReadTaskProperties::Run();
    WorkingWithTasks::ReadTaskWBS::Run();
    WorkingWithTasks::ReadWriteTimephasedData::Run();
    WorkingWithTasks::RenderTaskSheetView::Run();
    WorkingWithTasks::RenderTaskUsageView::Run();
    WorkingWithTasks::RenderTaskUsageViewWithDetails::Run();
    WorkingWithTasks::RenumberTaskWBSCodes::Run();
    WorkingWithTasks::UpdateTaskData::Run();
    WorkingWithTasks::ViewSplitTasks::Run();
    WorkingWithTasks::WriteTaskCalendar::Run();
    WorkingWithTasks::WriteTaskDuration::Run();
    WorkingWithTasks::WriteTaskProperties::Run();
    WorkingWithTasks::TaskWarning::Run();
    
    // C# preprocessor directive: #endregion
    
    
    // Working with Task Constraints
    // =====================================================
    
    WorkingWithTasks::WorkingWithTaskConstraints::GetConstraints::Run();
    WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintAsLateAsPossible::Run();
    WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintFinishNoEarlierThan::Run();
    WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintMustFinishOn::Run();
    WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintMustStartOn::Run();
    WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintStartNoEarlierThan::Run();
    
    // =====================================================
    // =====================================================
    // Working With VBA
    // =====================================================
    // =====================================================
    
    WorkingWithVBA::ReadModuleAttributesInformation::Run();
    WorkingWithVBA::ReadModulesInformation::Run();
    WorkingWithVBA::ReadReferencesInformation::Run();
    WorkingWithVBA::ReadVBAProjectInformation::Run();
    
    // Stop before exiting
    System::Console::WriteLine(u"\n\nProgram Finished. Press any key to exit..");
    System::Console::ReadKey();
}

System::String RunExamples::GetDataDir(System::String exampleName)
{
    System::String categoryName = exampleName;
    
    // C# preprocessor directive: #if !__cplusplus
    
    
    // C# preprocessor directive: #else
    
    categoryName = categoryName.Substring(categoryName.IndexOf(u"Aspose::Tasks::Examples::CPP::") + 30);
    categoryName = categoryName.Substring(0, categoryName.IndexOf(u"::"));
    categoryName = categoryName.Replace(u"::", System::String(u"") + System::IO::Path::DirectorySeparatorChar);
    
    // C# preprocessor directive: #endif
    
    System::String p = System::IO::Path::GetFullPath(System::IO::Path::Combine(System::MakeArray<System::String>({System::IO::Directory::GetCurrentDirectory(), u"Data", categoryName})));
    p += System::IO::Path::DirectorySeparatorChar;
    
    if (System::IO::Directory::Exists(p))
    {
        System::Console::WriteLine(u"Using Data Dir {0}", System::ObjectExt::Box<System::String>(p));
    }
    else
    {
        System::IO::Directory::CreateDirectory_(p);
        System::Console::WriteLine(u"Created Data Dir {0}", System::ObjectExt::Box<System::String>(p));
    }
    
    return p;
}

} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    Aspose::Tasks::Examples::CPP::RunExamples::Main();
    return 0;
}
