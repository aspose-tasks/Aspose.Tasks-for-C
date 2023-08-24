#include "WorkingWithProjects/WorkingWithProjectProperties/ReadWeekdayProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/convert.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/DayType.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(2941903374u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ReadWeekdayProperties, ThisTypeBaseTypesInfo);

void ReadWeekdayProperties::Run()
{
    // ExStart:ReadWeekdayProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadWeekdayProperties.mpp");
    
    // Display week days properties
    System::Console::WriteLine(System::String(u"Week Start Date : ") + System::ObjectExt::ToString(project->Get<DayType>(Prj::WeekStartDay())));
    System::Console::WriteLine(System::String(u"Days Per Month : ") + System::Convert::ToString(project->Get<int32_t>(Prj::DaysPerMonth())));
    System::Console::WriteLine(System::String(u"Minutes Per Day : ") + System::Convert::ToString(project->Get<int32_t>(Prj::MinutesPerDay())));
    System::Console::WriteLine(System::String(u"Minutes Per Week : ") + System::Convert::ToString(project->Get<int32_t>(Prj::MinutesPerWeek())));
    // ExEnd:ReadWeekdayProperties            
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
