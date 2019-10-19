/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/ImportingAndExporting/ReadXMLFileWithMultipleProjects.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <Project.h>
#include <io/xml/Primavera/PrimaveraXmlReadingOptions.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace ImportingAndExporting {

RTTI_INFO_IMPL_HASH(1317166971u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::ImportingAndExporting::ReadXMLFileWithMultipleProjects, ThisTypeBaseTypesInfo);

void ReadXMLFileWithMultipleProjects::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadXMLFileWithMultipleProjects
    System::SharedPtr<PrimaveraXmlReadingOptions> options = System::MakeObject<PrimaveraXmlReadingOptions>();
    options->set_ProjectUid(4557);
    // Returns project with special Uid
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project.xml", options);
    // ExEnd:ReadXMLFileWithMultipleProjects
}

} // namespace ImportingAndExporting
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
