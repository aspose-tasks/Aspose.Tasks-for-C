#include "WorkingWithProjects/WorkingWithProjectProperties/ReadDefaultProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/convert.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskType.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/EarnedValueMethodType.h>
#include <aspose.tasks.cpp/enums/CostAccrualType.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(3393139143u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ReadDefaultProperties, ThisTypeBaseTypesInfo);

void ReadDefaultProperties::Run()
{
    // ExStart:DefaultProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"DefaultProperties.mpp");
    
    // Display default properties
    System::Console::WriteLine(System::String(u"New Task Default Start: ") + project->Get<System::DateTime>(Prj::DefaultStartTime()).ToShortDateString());
    System::Console::WriteLine(System::String(u"New Task Default Type: ") + System::ObjectExt::ToString(project->Get<TaskType>(Prj::DefaultTaskType())));
    System::Console::WriteLine(System::String(u"Resouce Default Standard Rate: ") + System::Convert::ToString(project->Get<double>(Prj::DefaultStandardRate())));
    System::Console::WriteLine(System::String(u"Resource Default Overtime Rate: ") + System::Convert::ToString(project->Get<double>(Prj::DefaultOvertimeRate())));
    System::Console::WriteLine(System::String(u"Default Task EV Method: ") + System::ObjectExt::ToString(project->Get<EarnedValueMethodType>(Prj::DefaultTaskEVMethod())));
    System::Console::WriteLine(System::String(u"Default Cost Accrual: ") + System::ObjectExt::ToString(project->Get<CostAccrualType>(Prj::DefaultFixedCostAccrual())));
    // ExEnd:DefaultProperties
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
