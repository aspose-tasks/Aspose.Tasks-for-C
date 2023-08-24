#include "WorkingWithProjects/WorkingWithProjectProperties/ReadProjectInfo.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/NullableBool.h>
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

RTTI_INFO_IMPL_HASH(634675322u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ReadProjectInfo, ThisTypeBaseTypesInfo);

void ReadProjectInfo::Run()
{
    // ExStart:ReadProjectInfo
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create a project reader instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadProjectInfo.mpp");
    
    // Display project information
    if (NullableBool::to_Boolean(project->Get<NullableBool>(Prj::ScheduleFromStart())))
    {
        System::Console::WriteLine(System::String(u"Project Finish Date : ") + project->Get<System::DateTime>(Prj::StartDate()).ToShortDateString());
    }
    else
    {
        System::Console::WriteLine(System::String(u"Project Finish Date : ") + project->Get<System::DateTime>(Prj::FinishDate()).ToShortDateString());
    }
    System::Console::WriteLine(project->Get<System::String>(Prj::Author()));
    System::Console::WriteLine(project->Get<System::String>(Prj::LastAuthor()));
    System::Console::WriteLine(project->Get<int32_t>(Prj::Revision()));
    System::Console::WriteLine(project->Get<System::String>(Prj::Keywords()));
    System::Console::WriteLine(project->Get<System::String>(Prj::Comments()));
    System::Console::WriteLine(u"The program has run successfully");
    // ExEnd:ReadProjectInfo
}

} // namespace WorkingWithProjectProperties
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
