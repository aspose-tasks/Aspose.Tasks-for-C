/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithVBA/ReadModulesInformation.h"

#include <vba/VbaProject.h>
#include <vba/VbaModuleCollection.h>
#include <vba/VbaModule.h>
#include <vba/IVbaModule.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <Project.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithVBA {

RTTI_INFO_IMPL_HASH(3822349992u, ::Aspose::Tasks::Examples::CPP::WorkingWithVBA::ReadModulesInformation, ThisTypeBaseTypesInfo);

void ReadModulesInformation::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadModulesInformation
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"VbaProject1.mpp");
    
    System::SharedPtr<VbaProject> vbaProject = project->get_VbaProject();
    System::Console::WriteLine(System::String(u"Total Modules Count: ") + vbaProject->get_Modules()->get_Count());
    
    System::SharedPtr<IVbaModule> vbaModule = vbaProject->get_Modules()->ToList()->idx_get(0);
    System::Console::WriteLine(System::String(u"Module Name: ") + vbaModule->get_Name());
    System::Console::WriteLine(System::String(u"Source Code: ") + vbaModule->get_SourceCode());
    // ExEnd:ReadModulesInformation
}

} // namespace WorkingWithVBA
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
