/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithVBA/ReadVBAProjectInformation.h"

#include <vba/VbaProject.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <Project.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithVBA {

RTTI_INFO_IMPL_HASH(3612703397u, ::Aspose::Tasks::Examples::CPP::WorkingWithVBA::ReadVBAProjectInformation, ThisTypeBaseTypesInfo);

void ReadVBAProjectInformation::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadVBAProjectInformation
    // Loading project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"VbaProject1.mpp");
    
    System::SharedPtr<VbaProject> vbaProject = project->get_VbaProject();
    
    System::Console::WriteLine(System::String(u"VbaProject.Name ") + vbaProject->get_Name());
    System::Console::WriteLine(System::String(u"VbaProject.Description ") + vbaProject->get_Description());
    System::Console::WriteLine(System::String(u"VbaProject.CompilationArguments") + vbaProject->get_CompilationArguments());
    System::Console::WriteLine(System::String(u"VbaProject.HelpContextId") + vbaProject->get_HelpContextId());
    // ExEnd:ReadVBAProjectInformation
}

} // namespace WorkingWithVBA
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
