#include "WorkingWithProjects/GetNumberOfPagesForViews.h"

#include <visualization/Enums/Timescale.h>
#include <visualization/Enums/PresentationFormat.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
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

RTTI_INFO_IMPL_HASH(1122778133u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::GetNumberOfPagesForViews, ThisTypeBaseTypesInfo);

void GetNumberOfPagesForViews::Run()
{
    // ExStart:GetNumberOfPagesForViews
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Read the source Project
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"GetNumberOfPagesForViews.mpp");
    
    // Get number of pages,  Months and  ThirdsOfMonths
    System::Console::WriteLine(System::String::Format(u"Number of Pages = '{0}'",project->GetPageCount(Aspose::Tasks::Visualization::PresentationFormat::ResourceUsage, Aspose::Tasks::Visualization::Timescale::Days)));
    System::Console::WriteLine(System::String::Format(u"Number of Pages = '{0}'",project->GetPageCount(Aspose::Tasks::Visualization::PresentationFormat::ResourceUsage, Aspose::Tasks::Visualization::Timescale::Months)));
    System::Console::WriteLine(System::String::Format(u"Number of Pages = '{0}'",project->GetPageCount(Aspose::Tasks::Visualization::PresentationFormat::ResourceUsage, Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths)));
    // ExEnd:GetNumberOfPagesForViews
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
