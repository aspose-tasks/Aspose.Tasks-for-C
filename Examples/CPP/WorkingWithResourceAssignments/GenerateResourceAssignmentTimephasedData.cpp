#include "GenerateResourceAssignmentTimephasedData.h"

#include <TimephasedDataCollection.h>
#include <TimephasedData.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Project.h>
#include <Prj.h>
#include <Key.h>
#include <enums/WorkContourType.h>
#include <enums/PrjKey.h>
#include <enums/AsnKey.h>
#include <Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(35230752u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::GenerateResourceAssignmentTimephasedData, ThisTypeBaseTypesInfo);

void GenerateResourceAssignmentTimephasedData::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:GenerateResourceAssignmentTimephasedData
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceAssignmentTimephasedData.mpp");
    
    // Get the first task of the Project
    System::SharedPtr<Task> task = project1->get_RootTask()->get_Children()->GetById(1);
    
    // Get the First Resource Assignment of the Project
    System::SharedPtr<ResourceAssignment> firstRA = project1->get_ResourceAssignments()->ToList()->idx_get(0);
    
    // Flat contour is default contour
    System::Console::WriteLine(u"Flat contour");
    
    auto tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::Turtle);
    System::Console::WriteLine(u"Turtle contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::BackLoaded);
    System::Console::WriteLine(u"BackLoaded contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::FrontLoaded);
    System::Console::WriteLine(u"FrontLoaded contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::Bell);
    System::Console::WriteLine(u"Bell contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::EarlyPeak);
    System::Console::WriteLine(u"EarlyPeak contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::LatePeak);
    System::Console::WriteLine(u"LatePeak contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    
    // Change contour
    firstRA->Set<WorkContourType>(Asn::WorkContour(), Aspose::Tasks::WorkContourType::DoublePeak);
    System::Console::WriteLine(u"DoublePeak contour");
    tdList = task->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()));
    
    {
        auto td_enumerator = (tdList)->GetEnumerator();
        decltype(td_enumerator->get_Current()) td;
        while (td_enumerator->MoveNext() && (td = td_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(td->get_Start().ToShortDateString() + u" " + td->get_Value());
        }
    }
    // ExEnd:GenerateResourceAssignmentTimephasedData
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
