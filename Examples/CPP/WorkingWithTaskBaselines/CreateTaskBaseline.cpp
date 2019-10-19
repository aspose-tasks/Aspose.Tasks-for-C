#include "CreateTaskBaseline.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/array.h>
#include <Project.h>
#include <enums/BaselineType.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskBaselines {

RTTI_INFO_IMPL_HASH(3374331879u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskBaselines::CreateTaskBaseline, ThisTypeBaseTypesInfo);

void CreateTaskBaseline::Run()
{
    // ExStart:CreateTaskBaseline
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    
    // Creating TaskBaseline:
    System::SharedPtr<Task> task = project1->get_RootTask()->get_Children()->Add(u"Task");
    
    // Set baseline for specified tasks and entire project
    project1->SetBaseline(Aspose::Tasks::BaselineType::Baseline, System::MakeArray<System::SharedPtr<Aspose::Tasks::Task>>({task}));
    project1->SetBaseline(Aspose::Tasks::BaselineType::Baseline);
    // ExEnd:CreateTaskBaseline
}

} // namespace WorkingWithTaskBaselines
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
