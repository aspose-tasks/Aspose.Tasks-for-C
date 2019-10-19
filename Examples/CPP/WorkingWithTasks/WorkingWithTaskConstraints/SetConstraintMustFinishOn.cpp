/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetConstraintMustFinishOn.h"

#include <visualization/Enums/Timescale.h>
#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/date_time.h>
#include <saving/SaveOptions.h>
#include <saving/Pdf/PdfSaveOptions.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <enums/PrjKey.h>
#include <enums/ConstraintType.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

namespace WorkingWithTaskConstraints {

RTTI_INFO_IMPL_HASH(2033670874u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintMustFinishOn, ThisTypeBaseTypesInfo);

void SetConstraintMustFinishOn::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ConstraintMustFinishOn.mpp");
    
    // ExStart:SetConstraintMustFinishOn
    // Set constraint Must Finish On for task with Id 15
    System::SharedPtr<Task> interiorFixtures = project1->get_RootTask()->get_Children()->GetById(15);
    interiorFixtures->Set<ConstraintType>(Tsk::ConstraintType(), Aspose::Tasks::ConstraintType::MustFinishOn);
    interiorFixtures->Set(Tsk::ConstraintDate(), System::DateTime(2017, 3, 1, 18, 0, 0));
    
    // Save project as pdf
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_StartDate(project1->Get<System::DateTime>(Prj::StartDate()));
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    project1->Save(dataDir + u"project_MustFinishOn_out.pdf", options);
    // ExEnd:SetConstraintMustFinishOn
}

} // namespace WorkingWithTaskConstraints
} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
