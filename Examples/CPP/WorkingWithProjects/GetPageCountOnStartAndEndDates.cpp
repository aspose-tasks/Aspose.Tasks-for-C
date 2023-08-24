/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "GetPageCountOnStartAndEndDates.h"

#include <aspose.tasks.cpp/visualization/View/PageSize.h>
#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Image/ImageSaveOptions.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(248656106u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::GetPageCountOnStartAndEndDates, ThisTypeBaseTypesInfo);

void GetPageCountOnStartAndEndDates::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    //ExStart: GetPageCountOnStartAndEndDates
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"GetNumberOfPages.mpp");
    
    auto options = [&]{ auto tmp_0 = System::MakeObject<ImageSaveOptions>(Aspose::Tasks::Saving::SaveFileFormat::Png); tmp_0->set_RenderToSinglePage(false); tmp_0->set_PageSize(Aspose::Tasks::Visualization::PageSize::A3); tmp_0->set_Timescale(Aspose::Tasks::Visualization::Timescale::Months); tmp_0->set_StartDate(project->Get<System::DateTime>(Prj::StartDate()) - System::TimeSpan::FromDays(10)); tmp_0->set_EndDate(project->Get<System::DateTime>(Prj::FinishDate()) + System::TimeSpan::FromDays(30)); return tmp_0; }();
    int32_t pageCount = project->GetPageCount(Aspose::Tasks::Visualization::PageSize::A3, Aspose::Tasks::Visualization::Timescale::Months, project->Get<System::DateTime>(Prj::StartDate()) - System::TimeSpan::FromDays(10), project->Get<System::DateTime>(Prj::FinishDate()) + System::TimeSpan::FromDays(30));
    
    System::Console::WriteLine(pageCount);
    //ExEnd: GetPageCountOnStartAndEndDates
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
