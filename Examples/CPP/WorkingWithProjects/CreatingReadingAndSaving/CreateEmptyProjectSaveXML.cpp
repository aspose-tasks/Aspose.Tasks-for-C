/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/CreatingReadingAndSaving/CreateEmptyProjectSaveXML.h"

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

namespace CreatingReadingAndSaving {

RTTI_INFO_IMPL_HASH(2591759090u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving::CreateEmptyProjectSaveXML, ThisTypeBaseTypesInfo);

void CreateEmptyProjectSaveXML::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:CreateEmptyProjectSaveXML
    // Create empty project
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Save project as xml 
    project->Save(dataDir + u"EmptyProjectSaveXML_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:CreateEmptyProjectSaveXML
}

} // namespace CreatingReadingAndSaving
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
