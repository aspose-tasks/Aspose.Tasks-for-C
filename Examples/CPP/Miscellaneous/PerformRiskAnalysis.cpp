/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "PerformRiskAnalysis.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskPatternCollection.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskPattern.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskItemType.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskItemStatisticsCollection.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskItemStatistics.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskAnalyzer.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskAnalysisSettings.h>
#include <aspose.tasks.cpp/RiskAnalysis/RiskAnalysisResult.h>
#include <aspose.tasks.cpp/RiskAnalysis/ProbabilityDistributionType.h>
#include <aspose.tasks.cpp/RiskAnalysis/ConfidenceLevel.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::RiskAnalysis;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(1075861549u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::PerformRiskAnalysis, ThisTypeBaseTypesInfo);

void PerformRiskAnalysis::Run()
{
    // ExStart:PrepareAnalysisSettings
    System::SharedPtr<RiskAnalysisSettings> settings = System::MakeObject<RiskAnalysisSettings>();
    
    // Set number of iterations for Monte Carlo simulation (the default value is 100).
    settings->set_IterationsCount(200);
    // ExEnd:PrepareAnalysisSettings
    
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:IdentifyAnalysisInput
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Software Development Plan-1.mpp");
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(17);
    
    // Initialize a risk pattern
    System::SharedPtr<RiskPattern> pattern = System::MakeObject<RiskPattern>(task);
    
    // Select a distribution type for the random number generator to generate possible values from (only two types currently supported, namely normal and uniform)            
    // For more details see here: https://en.wikipedia.org/wiki/Normal_distribution)
    pattern->set_Distribution(Aspose::Tasks::RiskAnalysis::ProbabilityDistributionType::Normal);
    
    // Set the percentage of the most likely task duration which can happen in the best possible project scenario 
    // The default value is 75, which means that if the estimated specified task duration is 4 days then the optimistic duration will be 3 days
    pattern->set_Optimistic(70);
    
    // Set the percentage of the most likely task duration which can happen in the worst possible project scenario 
    // The defaut value is 125, which means that if the estimated specified task duration is 4 days then the pessimistic duration will be 5 days.
    pattern->set_Pessimistic(130);
    
    // Set a confidence level that correspond to the percentage of the time the actual values will be within optimistic and pessimistic estimates. 
    // You can think of it as a value of standard deviation: the more uncertain about your estimates you are, the more the value of standard deviation used in random number generator is
    pattern->set_ConfidenceLevel(Aspose::Tasks::RiskAnalysis::ConfidenceLevel::CL75);
    
    settings->get_Patterns()->Add(pattern);
    // ExEnd:IdentifyAnalysisInput
    
    // ExStart:AnalyzeRisks
    // Analyze the project risks
    System::SharedPtr<RiskAnalyzer> analyzer = System::MakeObject<RiskAnalyzer>(settings);
    System::SharedPtr<RiskAnalysisResult> analysisResult = analyzer->Analyze(project);
    // ExEnd:AnalyzeRisks
    
    // ExStart:UseAnalysisResult
    // Select the desired output (here we get early finish of the root task)
    System::SharedPtr<RiskItemStatistics> rootEarlyFinish = analysisResult->GetRiskItems(Aspose::Tasks::RiskAnalysis::RiskItemType::EarlyFinish)->Get(project->get_RootTask());
    
    System::Console::WriteLine(u"Expected value: {0}", System::ObjectExt::Box<System::DateTime>(rootEarlyFinish->get_ExpectedValue()));
    System::Console::WriteLine(u"StandardDeviation: {0}", System::ObjectExt::Box<Duration>(rootEarlyFinish->get_StandardDeviation()));
    System::Console::WriteLine(u"10% Percentile: {0}", System::ObjectExt::Box<System::DateTime>(rootEarlyFinish->GetPercentile(10)));
    System::Console::WriteLine(u"50% Percentile: {0}", System::ObjectExt::Box<System::DateTime>(rootEarlyFinish->GetPercentile(50)));
    System::Console::WriteLine(u"90% Percentile: {0}", System::ObjectExt::Box<System::DateTime>(rootEarlyFinish->GetPercentile(90)));
    System::Console::WriteLine(u"Minimum: {0}", System::ObjectExt::Box<System::DateTime>(rootEarlyFinish->get_Minimum()));
    System::Console::WriteLine(u"Maximum: {0}", System::ObjectExt::Box<System::DateTime>(rootEarlyFinish->get_Maximum()));
    
    // Save PDF report which is rendered for Project Root Task Finish date
    analysisResult->SaveReport(dataDir + u"AnalysisReport_out.pdf");
    // ExEnd:UseAnalysisResult
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
