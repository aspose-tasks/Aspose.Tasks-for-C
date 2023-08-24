#include "CreateTaskLinks.h"

#include <aspose.tasks.cpp/TaskLinkCollection.h>
#include <aspose.tasks.cpp/TaskLink.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <aspose.tasks.cpp/Project.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskLinks {

RTTI_INFO_IMPL_HASH(218633228u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks::CreateTaskLinks, ThisTypeBaseTypesInfo);

void CreateTaskLinks::Run()
{
    // ExStart:CreateTaskLinks
    // Create new project and add tasks
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    System::SharedPtr<Task> pred = project1->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> succ = project1->get_RootTask()->get_Children()->Add(u"Task 2");
    
    // Links tasks
    System::SharedPtr<TaskLink> link = project1->get_TaskLinks()->Add(pred, succ);
    // ExEnd:CreateTaskLinks
}

} // namespace WorkingWithTaskLinks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
