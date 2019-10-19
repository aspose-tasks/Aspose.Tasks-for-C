/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "EvaluationDateTimeLimitations.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Licensing {

RTTI_INFO_IMPL_HASH(2704315891u, ::Aspose::Tasks::Examples::CPP::Licensing::EvaluationDateTimeLimitations, ThisTypeBaseTypesInfo);

void EvaluationDateTimeLimitations::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:DateTimeLimitations
    // Create a prject instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    
    // Define Tasks
    System::SharedPtr<Task> task1 = project1->get_RootTask()->get_Children()->Add(u"Task1");
    task1->Set(Tsk::ActualStart(), System::DateTime::Parse(u"06-Apr-2010"));
    
    System::SharedPtr<Task> task2 = project1->get_RootTask()->get_Children()->Add(u"Task2");
    task2->Set(Tsk::ActualStart(), System::DateTime::Parse(u"10-Apr-2010"));
    
    // Save the Project as XML
    project1->Save(u"EvalProject_out.xml", Aspose::Tasks::Saving::SaveFileFormat::XML);
    // ExEnd:DateTimeLimitations
}

} // namespace Licensing
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
