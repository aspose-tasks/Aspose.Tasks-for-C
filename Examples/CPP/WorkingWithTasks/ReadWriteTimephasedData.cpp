#include "ReadWriteTimephasedData.h"

#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TimephasedDataCollection.h>
#include <aspose.tasks.cpp/TimephasedData.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/Rsc.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/ResourceAssignmentCollection.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/NullableBool.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/WorkContourType.h>
#include <aspose.tasks.cpp/enums/TimephasedDataType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/RscKey.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>
#include <aspose.tasks.cpp/enums/BaselineType.h>
#include <aspose.tasks.cpp/enums/AsnKey.h>
#include <aspose.tasks.cpp/Duration.h>
#include <cstdint>
#include <aspose.tasks.cpp/Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(373900163u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadWriteTimephasedData, ThisTypeBaseTypesInfo);

void ReadWriteTimephasedData::Run()
{
    // ExStart:ReadWriteTimephasedData
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ReadWriteTimephasedData.mpp");
    
    // Set project properties
    project1->Set(Prj::StartDate(), System::DateTime(2013, 10, 30, 9, 0, 0));
    project1->Set<NullableBool>(Prj::NewTasksAreManual(), NullableBool::to_NullableBool(false));
    
    // Add task and resources
    System::SharedPtr<Task> task = project1->get_RootTask()->get_Children()->Add(u"Task");
    System::SharedPtr<Resource> rsc = project1->get_Resources()->Add(u"Rsc");
    
    // Set resource rates and task duration
    rsc->Set<System::Decimal>(Rsc::StandardRate(), static_cast<System::Decimal>(10));
    rsc->Set<System::Decimal>(Rsc::OvertimeRate(), static_cast<System::Decimal>(15));
    task->Set<Duration>(Tsk::Duration(), project1->GetDuration(6));
    
    // Create resource assignment
    System::SharedPtr<ResourceAssignment> assn = project1->get_ResourceAssignments()->Add(task, rsc);
    assn->Set(Asn::Stop(), System::DateTime::MinValue);
    assn->Set(Asn::Resume(), System::DateTime::MinValue);
    
    // Set Backloaded contour, it increases task duration from 6 to 10 days
    assn->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::BackLoaded);
    
    project1->SetBaseline(Aspose::Tasks::BaselineType::Baseline);
    task->Set<int32_t>(Tsk::PercentComplete(), 50);
    
    // Read timephased data
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<TimephasedData>>> td = assn->GetTimephasedData(assn->Get<System::DateTime>(Asn::Start()), assn->Get<System::DateTime>(Asn::Finish()), Aspose::Tasks::TimephasedDataType::AssignmentRemainingWork)->ToList();
    System::Console::WriteLine(td->get_Count());
    
    {
        auto timePhasedValue_enumerator = (td)->GetEnumerator();
        while (timePhasedValue_enumerator->MoveNext())
        {
            auto&& timePhasedValue = timePhasedValue_enumerator->get_Current();
            System::Console::WriteLine(timePhasedValue->get_Value());
        }
    }
    // ExEnd:ReadWriteTimephasedData
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
