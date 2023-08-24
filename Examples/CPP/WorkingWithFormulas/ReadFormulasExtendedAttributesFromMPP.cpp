/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/ReadFormulasExtendedAttributesFromMPP.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(3139723451u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::ReadFormulasExtendedAttributesFromMPP, ThisTypeBaseTypesInfo);

void ReadFormulasExtendedAttributesFromMPP::Run()
{
    // ExStart:ReadFormulasExtendedAttributesFromMPP
    // The path to the documents directory.
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ReadFormulas.mpp");
    // Attached test mpp
    
    // Read extended attribute formula
    System::SharedPtr<ExtendedAttributeDefinition> attr = project1->get_ExtendedAttributes()->idx_get(0);
    System::Console::WriteLine(System::String(u"Attribute Formula: ") + attr->get_Formula());
    // ExEnd:ReadFormulasExtendedAttributesFromMPP
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
