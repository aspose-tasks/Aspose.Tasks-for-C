/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/CustomizeDateFormats.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <enums/DateFormat.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(707367056u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::CustomizeDateFormats, ThisTypeBaseTypesInfo);

void CustomizeDateFormats::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:CustomizeDateFormats
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    project->Set(Prj::StartDate(), System::DateTime(2014, 9, 22));
    
    // By default project.DateFormat == DateFormat.Date_ddd_mm_dd_yy (Mon 09/22/14) customize DateFormat (September 22, 2014)
    project->Set<DateFormat>(Prj::DateFormat(), Aspose::Tasks::DateFormat::DateMmmmDdYyyy);
    project->Save(dataDir + u"CustomizeDateFormats1_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
    
    // Export to date format 19/07/2016
    project->Set<DateFormat>(Prj::DateFormat(), Aspose::Tasks::DateFormat::DateDdMmYyyy);
    project->Save(dataDir + u"CustomizeDateFormats2_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
    // ExEnd:CustomizeDateFormats
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
