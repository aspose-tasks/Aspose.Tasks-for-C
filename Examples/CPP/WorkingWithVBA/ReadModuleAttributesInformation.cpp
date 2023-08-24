/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithVBA/ReadModuleAttributesInformation.h"

#include <aspose.tasks.cpp/vba/VbaProject.h>
#include <aspose.tasks.cpp/vba/VbaModuleCollection.h>
#include <aspose.tasks.cpp/vba/VbaModuleAttributeCollection.h>
#include <aspose.tasks.cpp/vba/VbaModuleAttribute.h>
#include <aspose.tasks.cpp/vba/VbaModule.h>
#include <aspose.tasks.cpp/vba/IVbaModule.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/Project.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithVBA {

RTTI_INFO_IMPL_HASH(1933725510u, ::Aspose::Tasks::Examples::CPP::WorkingWithVBA::ReadModuleAttributesInformation, ThisTypeBaseTypesInfo);

void ReadModuleAttributesInformation::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadModuleAttributesInformation
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"VbaProject1.mpp");
    System::SharedPtr<VbaProject> vbaProject = project->get_VbaProject();
    System::SharedPtr<IVbaModule> vbaModule = vbaProject->get_Modules()->ToList()->idx_get(0);
    
    System::Console::WriteLine(System::String(u"Attributes Count: ") + vbaModule->get_Attributes()->get_Count());
    System::Console::WriteLine(System::String(u"VB_Name: ") + vbaModule->get_Attributes()->ToList()->idx_get(0)->get_Key());
    System::Console::WriteLine(System::String(u"Module1: ") + vbaModule->get_Attributes()->ToList()->idx_get(0)->get_Value());
    // ExEnd:ReadModuleAttributesInformation
}

} // namespace WorkingWithVBA
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
