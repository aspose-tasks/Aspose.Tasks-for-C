#include "SetTaskLinkType.h"

#include <TaskLinkCollection.h>
#include <TaskLink.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Project.h>
#include <enums/TaskLinkType.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTaskLinks {

RTTI_INFO_IMPL_HASH(2578451823u, ::Aspose::Tasks::Examples::CPP::WorkingWithTaskLinks::SetTaskLinkType, ThisTypeBaseTypesInfo);

void SetTaskLinkType::Run()
{
    // ExStart:SetTaskLinkType                        
    // Create new project and add tasks
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    System::SharedPtr<Task> pred = project->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> succ = project->get_RootTask()->get_Children()->Add(u"Task 2");
    
    // Link tasks with link type set to Start to Start
    System::SharedPtr<TaskLink> link = project->get_TaskLinks()->Add(pred, succ);
    link->set_LinkType(Aspose::Tasks::TaskLinkType::StartToStart);
    // ExEnd:SetTaskLinkType
}

} // namespace WorkingWithTaskLinks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
