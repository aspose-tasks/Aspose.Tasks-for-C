#include "WorkingWithProjects/WorkingWithProjectProperties/WriteWeekdayProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <enums/DayType.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(1220802323u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::WriteWeekdayProperties, ThisTypeBaseTypesInfo);

void WriteWeekdayProperties::Run()
{
    // ExStart:WriteWeekdayProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"WriteWeekdayProperties.mpp");
    
    // Set week days properties
    project->Set<DayType>(Prj::WeekStartDay(), Aspose::Tasks::DayType::Monday);
    project->Set<int32_t>(Prj::DaysPerMonth(), 24);
    project->Set<int32_t>(Prj::MinutesPerDay(), 540);
    project->Set<int32_t>(Prj::MinutesPerWeek(), 3240);
    project->Save(dataDir + u"WriteWeekdayProperties_out.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
    // ExEnd:WriteWeekdayProperties            
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
