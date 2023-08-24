/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SaveSlippingTasksReport.h"

#include <aspose.tasks.cpp/visualization/Reporting/ReportType.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(2301320436u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::SaveSlippingTasksReport, ThisTypeBaseTypesInfo);

void SaveSlippingTasksReport::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:SaveSlippingTasksReport
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"Homemoveplan.mpp");
    project1->SaveReport(dataDir + u"SlippingTasks_out.pdf", Aspose::Tasks::Visualization::ReportType::SlippingTasks);
    // ExEnd:SaveSlippingTasksReport
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
