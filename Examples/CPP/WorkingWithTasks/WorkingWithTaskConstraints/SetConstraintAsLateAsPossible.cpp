/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetConstraintAsLateAsPossible.h"

#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/date_time.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Pdf/PdfSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/ConstraintType.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

namespace WorkingWithTaskConstraints {

RTTI_INFO_IMPL_HASH(149605754u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WorkingWithTaskConstraints::SetConstraintAsLateAsPossible, ThisTypeBaseTypesInfo);

void SetConstraintAsLateAsPossible::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ConstraintAsLateAsPossible.mpp");
    
    // ExStart:SetConstraintAsLateAsPossible
    // Set constraint As Late As Possible for task with Id 11
    System::SharedPtr<Task> wallBoard = project1->get_RootTask()->get_Children()->GetById(11);
    wallBoard->Set<ConstraintType>(Tsk::ConstraintType(), Aspose::Tasks::ConstraintType::AsLateAsPossible);
    
    // Save project as pdf
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_StartDate(project1->Get<System::DateTime>(Prj::StartDate()));
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    project1->Save(dataDir + u"project_AsLateAsPossible_out.pdf", options);
    // ExEnd:SetConstraintAsLateAsPossible
}

} // namespace WorkingWithTaskConstraints
} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
