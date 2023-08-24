#include "WorkingWithProjects/MPPFileUpdate.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(4212413296u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::MPPFileUpdate, ThisTypeBaseTypesInfo);

void MPPFileUpdate::Run()
{
    try
    {
        // ExStart:MPPFileUpdate
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // Read an existing project
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"MPPFileUpdate.mpp");
        
        // Create a new task
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task1");
        
        task->Set(Tsk::Start(), System::DateTime(2012, 8, 1));
        task->Set(Tsk::Finish(), System::DateTime(2012, 8, 5));
        
        // Save the project as MPP project file
        project->Save(dataDir + u"AfterLinking_out.Mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:MPPFileUpdate   
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
