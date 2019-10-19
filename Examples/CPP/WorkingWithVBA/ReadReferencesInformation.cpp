/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithVBA/ReadReferencesInformation.h"

#include <vba/VbaReferenceCollection.h>
#include <vba/VbaReference.h>
#include <vba/VbaProject.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
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

RTTI_INFO_IMPL_HASH(3762697441u, ::Aspose::Tasks::Examples::CPP::WorkingWithVBA::ReadReferencesInformation, ThisTypeBaseTypesInfo);

void ReadReferencesInformation::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadReferencesInformation
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"VbaProject1.mpp");
    
    System::SharedPtr<VbaProject> vbaProject = project->get_VbaProject();
    System::SharedPtr<VbaReferenceCollection> references = vbaProject->get_References();
    System::Console::WriteLine(u"Reference count ", System::ObjectExt::Box<int32_t>(references->get_Count()));
    
    System::SharedPtr<VbaReference> reference = vbaProject->get_References()->ToList()->idx_get(0);
    System::Console::WriteLine(System::String(u"Identifier: ") + reference->get_LibIdentifier());
    System::Console::WriteLine(System::String(u"Name: ") + reference->get_Name());
    
    reference = vbaProject->get_References()->ToList()->idx_get(1);
    System::Console::WriteLine(System::String(u"Identifier: ") + reference->get_LibIdentifier());
    System::Console::WriteLine(System::String(u"Name: ") + reference->get_Name());
    
    reference = vbaProject->get_References()->ToList()->idx_get(2);
    System::Console::WriteLine(System::String(u"Identifier: ") + reference->get_LibIdentifier());
    System::Console::WriteLine(System::String(u"Name: ") + reference->get_Name());
    // ExEnd:ReadReferencesInformation
}

} // namespace WorkingWithVBA
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
