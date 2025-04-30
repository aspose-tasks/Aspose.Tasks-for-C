/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "AddNewTask.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/Duration.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace KnowledgeBase {

RTTI_INFO_IMPL_HASH(1586598724u, ::Aspose::Tasks::Examples::CPP::KnowledgeBase::AddNewTask, ThisTypeBaseTypesInfo);

void AddNewTask::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:AddNewTask            
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project1.mpp");
    
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task1");
    task->Set(Tsk::ActualStart(), System::DateTime::Parse(u"23-Aug-2012"));
    
    // Set duration in hours
    task->Set<Duration>(Tsk::Duration(), project->GetDuration(24, Aspose::Tasks::TimeUnitType::Hour));
    
    // Save the Project as XML
    project->Save(dataDir + u"AddNewTask_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:AddNewTask        
}

} // namespace KnowledgeBase
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
