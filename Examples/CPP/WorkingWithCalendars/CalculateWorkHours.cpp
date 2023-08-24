#include "CalculateWorkHours.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/timespan.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/Rsc.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/RscKey.h>
#include <aspose.tasks.cpp/Calendar.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithCalendars {

RTTI_INFO_IMPL_HASH(3543226341u, ::Aspose::Tasks::Examples::CPP::WorkingWithCalendars::CalculateWorkHours, ThisTypeBaseTypesInfo);

void CalculateWorkHours::Run()
{
    // ExStart:CalculateWorkHours
    // Load an existing project
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CalculateWorkHours.mpp");
    
    // Access Task By Id
    System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->GetById(1);
    
    // Access Calendar and it's start and end dates
    System::SharedPtr<Aspose::Tasks::Calendar> taskCalendar = task->Get<System::SharedPtr<Calendar>>(Tsk::Calendar());
    System::DateTime startDate = task->Get<System::DateTime>(Tsk::Start());
    System::DateTime endDate = task->Get<System::DateTime>(Tsk::Finish());
    System::DateTime tempDate = startDate;
    
    // Access resource and their calendar
    System::SharedPtr<Resource> resource = project->get_Resources()->GetByUid(1);
    System::SharedPtr<Aspose::Tasks::Calendar> resourceCalendar = resource->Get<System::SharedPtr<Calendar>>(Rsc::Calendar());
    
    System::TimeSpan timeSpan;
    
    // Get Duration in Minutes
    double durationInMins = 0;
    while (tempDate < endDate)
    {
        if (taskCalendar->IsDayWorking(tempDate) && resourceCalendar->IsDayWorking(tempDate))
        {
            timeSpan = taskCalendar->GetWorkingHours(tempDate);
            durationInMins = durationInMins + timeSpan.get_TotalMinutes();
        }
        tempDate = tempDate.AddDays(1);
    }
    tempDate = startDate;
    
    // Get Duration in Hours
    double durationInHours = 0;
    while (tempDate < endDate)
    {
        if (taskCalendar->IsDayWorking(tempDate) && resourceCalendar->IsDayWorking(tempDate))
        {
            timeSpan = taskCalendar->GetWorkingHours(tempDate);
            durationInHours = durationInHours + timeSpan.get_TotalHours();
        }
        tempDate = tempDate.AddDays(1);
    }
    tempDate = startDate;
    
    // Get Duration in Days
    double durationInDays = 0;
    while (tempDate < endDate)
    {
        if (taskCalendar->IsDayWorking(tempDate) && resourceCalendar->IsDayWorking(tempDate))
        {
            timeSpan = taskCalendar->GetWorkingHours(tempDate);
            if (timeSpan.get_TotalHours() > 0)
            {
                durationInDays = durationInDays + timeSpan.get_TotalDays() * (24 / (timeSpan.get_TotalHours()));
            }
        }
        tempDate = tempDate.AddDays(1);
    }
    
    System::Console::WriteLine(System::String(u"Duration in Minutes = ") + durationInMins);
    System::Console::WriteLine(System::String(u"Duration in Hours = ") + durationInHours);
    System::Console::WriteLine(System::String(u"Duration in Days = ") + durationInDays);
    // ExEnd:CalculateWorkHours
}

} // namespace WorkingWithCalendars
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
