#include "ReadResourceTimephasedData.h"

#include <aspose.tasks.cpp/TimephasedDataCollection.h>
#include <aspose.tasks.cpp/TimephasedData.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/environment.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimephasedDataType.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(446232193u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::ReadResourceTimephasedData, ThisTypeBaseTypesInfo);

void ReadResourceTimephasedData::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadResourceTimephasedData
    // Create project instance
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ResourceTimephasedData.mpp");
    
    // Get the Resource by its ID
    System::SharedPtr<Resource> resource = project1->get_Resources()->GetByUid(1);
    
    // Print Timephased data of ResourceWork
    System::Console::WriteLine(u"Timephased data of ResourceWork");
    
    {
        auto td_enumerator = (resource->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate())))->GetEnumerator();
        while (td_enumerator->MoveNext())
        {
            auto&& td = td_enumerator->get_Current();
            System::Console::Write(System::String(u"Start: ") + td->get_Start().ToShortDateString());
            System::Console::Write(System::String(u" Work: ") + td->get_Value() + System::Environment::get_NewLine());
        }
    }
    
    // Print Timephased data of ResourceCost
    System::Console::WriteLine(u"Timephased data of ResourceCost");
    
    {
        auto td_enumerator = (resource->GetTimephasedData(project1->Get<System::DateTime>(Prj::StartDate()), project1->Get<System::DateTime>(Prj::FinishDate()), Aspose::Tasks::TimephasedDataType::ResourceCost))->GetEnumerator();
        while (td_enumerator->MoveNext())
        {
            auto&& td = td_enumerator->get_Current();
            System::Console::Write(System::String(u"Start: ") + td->get_Start().ToShortDateString());
            System::Console::Write(System::String(u" Cost: ") + td->get_Value() + System::Environment::get_NewLine());
        }
    }
    // ExEnd:ReadResourceTimephasedData
}

} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
