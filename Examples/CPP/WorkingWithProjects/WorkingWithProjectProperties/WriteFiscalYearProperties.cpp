/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteFiscalYearProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <NullableBool.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <enums/Month.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(253133878u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::WriteFiscalYearProperties, ThisTypeBaseTypesInfo);

void WriteFiscalYearProperties::Run()
{
    try
    {
        // ExStart:WriteFiscalYearProperties
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // Create a project instance
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"WriteFiscalYearProperties.mpp");
        
        // Set fiscal year properties
        project->Set<Month>(Prj::FyStartDate(), Aspose::Tasks::Month::July);
        project->Set<NullableBool>(Prj::FiscalYearStart(), NullableBool::to_NullableBool(true));
        project->Save(dataDir + u"WriteFiscalYearProperties_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::MPP);
        // ExEnd:WriteFiscalYearProperties
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
