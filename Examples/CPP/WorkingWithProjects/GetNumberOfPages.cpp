/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/GetNumberOfPages.h"

#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/Project.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(2719827344u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::GetNumberOfPages, ThisTypeBaseTypesInfo);

void GetNumberOfPages::Run()
{
    // ExStart:GetNumberOfPages
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Read the input Project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"GetNumberOfPages.mpp");
    
    // Get number of pages,  Timescale.Months, Timescale.ThirdsOfMonths
    int32_t iPages = project->GetPageCount();
    iPages = project->GetPageCount(Aspose::Tasks::Visualization::Timescale::Months);
    iPages = project->GetPageCount(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    // ExEnd:GetNumberOfPages
    
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
