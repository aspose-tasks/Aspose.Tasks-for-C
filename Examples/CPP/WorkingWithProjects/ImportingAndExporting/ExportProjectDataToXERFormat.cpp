/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/ImportingAndExporting/ExportProjectDataToXERFormat.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace ImportingAndExporting {

RTTI_INFO_IMPL_HASH(986490436u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::ImportingAndExporting::ExportProjectDataToXERFormat, ThisTypeBaseTypesInfo);

void ExportProjectDataToXERFormat::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ExportProjectDataToXERFormat
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project5.mpp");
    
    // Save project in desired format
    project->Save(dataDir + u"ExportProjectDataToXERFormat_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::PrimaveraXer);
    // ExEnd:ExportProjectDataToXERFormat
}

} // namespace ImportingAndExporting
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
