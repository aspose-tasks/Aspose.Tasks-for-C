/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "RenderTaskUsageViewWithDetails.h"

#include <View.h>
#include <UsageView.h>
#include <TaskUsageView.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/exceptions.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <drawing/string_alignment.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(552948183u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::RenderTaskUsageViewWithDetails, ThisTypeBaseTypesInfo);

void RenderTaskUsageViewWithDetails::Run()
{
    // ExStart:RenderTaskUsageViewWithDetails
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"TaskUsageViewWithDetails.mpp");
    
    // Get Default view
    System::SharedPtr<UsageView> view = System::DynamicCast_noexcept<Aspose::Tasks::TaskUsageView>(project1->get_DefaultView());
    
    // Details header column will not be displayed
    view->set_DisplayDetailsHeaderColumn(false);
    view->set_RepeatDetailsHeaderOnAllRows(false);
    view->set_AlignDetailsData(System::Drawing::StringAlignment::Near);
    project1->Save(dataDir + u"task usage1_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
    
    // Display details header column
    view->set_DisplayDetailsHeaderColumn(true);
    
    // Repeat details header on all assignments rows
    view->set_RepeatDetailsHeaderOnAllRows(true);
    view->set_AlignDetailsData(System::Drawing::StringAlignment::Far);
    project1->Save(dataDir + u"task usage2_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
    // ExEnd:RenderTaskUsageViewWithDetails
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
