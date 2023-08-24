#include "WorkingWithProjects/WorkingWithProjectProperties/DetermineProjectVersion.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/convert.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(2032020507u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::DetermineProjectVersion, ThisTypeBaseTypesInfo);

void DetermineProjectVersion::Run()
{
    // ExStart:DetermineProjectVersion
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Read project from template file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"DetermineProjectVersion.mpp");
    
    // Display project version
    System::Console::WriteLine(System::String(u"Project Version : ") + System::Convert::ToString(project->Get<int32_t>(Prj::SaveVersion())));
    System::Console::WriteLine(System::String(u"Last Saved : ") + project->Get<System::DateTime>(Prj::LastSaved()).ToShortDateString());
    // ExEnd:DetermineProjectVersion
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
