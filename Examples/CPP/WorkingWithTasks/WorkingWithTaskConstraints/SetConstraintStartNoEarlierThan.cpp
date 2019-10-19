/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetConstraintStartNoEarlierThan.h"

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

RTTI_INFO_IMPL_HASH(3501217053u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintStartNoEarlierThan, ThisTypeBaseTypesInfo);

void SetConstraintStartNoEarlierThan::Run()
{
    // ExStart:SetConstraintStartNoEarlierThan
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ConstraintStartNoEarlierThan.mpp");
    
    // Set constraint Start No Earlier Than on task with Id 1
    System::SharedPtr<Task> summary = project->get_RootTask()->get_Children()->GetById(1);
    summary->Set<ConstraintType>(Tsk::ConstraintType(), Aspose::Tasks::ConstraintType::StartNoEarlierThan);
    summary->Set(Tsk::ConstraintDate(), System::DateTime(2016, 12, 1, 9, 0, 0));
    
    // Save project as pdf
    System::SharedPtr<SaveOptions> o = System::MakeObject<PdfSaveOptions>();
    o->set_StartDate(project->Get<System::DateTime>(Prj::StartDate()));
    o->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    project->Save(dataDir + u"project_StartNoEarlierThan_out.pdf", o);
    // ExEnd:SetConstraintStartNoEarlierThan
}

} // namespace WorkingWithTaskConstraints
} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
