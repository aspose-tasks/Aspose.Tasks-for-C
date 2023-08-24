/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithProjectProperties/WriteDefaultProperties.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/NullableBool.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskType.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/EarnedValueMethodType.h>
#include <aspose.tasks.cpp/enums/CostAccrualType.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectProperties {

RTTI_INFO_IMPL_HASH(1672038092u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::WriteDefaultProperties, ThisTypeBaseTypesInfo);

void WriteDefaultProperties::Run()
{
    // ExStart:WriteDefaultProperties
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project instance and Set default properties
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    project->Set<NullableBool>(Prj::ScheduleFromStart(), NullableBool::to_NullableBool(true));
    project->Set(Prj::StartDate(), System::DateTime::get_Now());
    project->Set(Prj::DefaultStartTime(), project->Get<System::DateTime>(Prj::StartDate()));
    project->Set<TaskType>(Prj::DefaultTaskType(), Aspose::Tasks::TaskType::FixedDuration);
    project->Set<double>(Prj::DefaultStandardRate(), 15.0);
    project->Set<double>(Prj::DefaultOvertimeRate(), 12.0);
    project->Set<EarnedValueMethodType>(Prj::DefaultTaskEVMethod(), Aspose::Tasks::EarnedValueMethodType::PercentComplete);
    project->Set<CostAccrualType>(Prj::DefaultFixedCostAccrual(), Aspose::Tasks::CostAccrualType::Prorated);
    
    // Save the project to XML format
    project->Save(dataDir + u"WriteDefaultProperties_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:WriteDefaultProperties
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
