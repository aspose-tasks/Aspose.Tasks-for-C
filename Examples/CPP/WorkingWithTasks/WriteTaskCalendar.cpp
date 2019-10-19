/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WriteTaskCalendar.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <CalendarCollection.h>
#include <Calendar.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(3850181724u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::WriteTaskCalendar, ThisTypeBaseTypesInfo);

void WriteTaskCalendar::Run()
{
    // ExStart:WriteTaskCalendar
    // Create project instance
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    // Add task
    System::SharedPtr<Task> tsk1 = project->get_RootTask()->get_Children()->Add(u"Task1");
    
    // Create calendar and assign to task
    System::SharedPtr<Aspose::Tasks::Calendar> cal = project->get_Calendars()->Add(u"TaskCal1");
    tsk1->Set<System::SharedPtr<Calendar>>(Tsk::Calendar(), cal);
    // ExEnd:WriteTaskCalendar      
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
