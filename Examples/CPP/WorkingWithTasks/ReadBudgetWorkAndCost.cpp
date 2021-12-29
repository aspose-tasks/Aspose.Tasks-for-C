#include "ReadBudgetWorkAndCost.h"

#include <Tsk.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/decimal.h>
#include <system/convert.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/TaskKey.h>
#include <enums/RscKey.h>
#include <enums/ResourceType.h>
#include <enums/AsnKey.h>
#include <Duration.h>
#include <Asn.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(1997485298u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadBudgetWorkAndCost, ThisTypeBaseTypesInfo);

void ReadBudgetWorkAndCost::Run()
{
    // ExStart:ReadBudgetWorkAndCost
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"BudgetWorkAndCost.mpp");
    
    // Display budget work and budget cost for project summary task
    System::SharedPtr<Task> projSummary = project1->get_RootTask();
    System::Console::WriteLine(System::String(u"projSummary.BudgetWork = ") + System::ObjectExt::ToString(projSummary->Get<Duration>(Tsk::BudgetWork())));
    System::Console::WriteLine(System::String(u"projSummary.BudgetCost = ") + System::Convert::ToString(projSummary->Get<System::Decimal>(Tsk::BudgetCost())));
    
    // Display resource budget work
    System::SharedPtr<Resource> rsc = project1->get_Resources()->GetByUid(6);
    System::Console::WriteLine(System::String(u"Resource BudgetWork = ") + System::ObjectExt::ToString(rsc->Get<Duration>(Rsc::BudgetWork())));
    
    // Display resource budget cost
    rsc = project1->get_Resources()->GetByUid(7);
    System::Console::WriteLine(System::String(u"Resource BudgetCost = ") + System::Convert::ToString(rsc->Get<System::Decimal>(Rsc::BudgetCost())));
    
    // Display assignment budget work and budget cost
    
    {
        auto assn_enumerator = (projSummary->get_Assignments())->GetEnumerator();
        while (assn_enumerator->MoveNext())
        {
            auto&& assn = assn_enumerator->get_Current();
            // C# preprocessor directive: #if !__cplusplus
            
            
            // C# preprocessor directive: #endif
            
            auto resource = assn->Get(Asn::Resource());
            
            if (static_cast<ResourceType>(resource->Get(Rsc::Type())) == Aspose::Tasks::ResourceType::Work)
            {
                System::Console::WriteLine(System::String(u"Assignment BudgetWork = ") + System::ObjectExt::ToString(assn->Get<Duration>(Asn::BudgetWork())));
            }
            else
            {
                System::Console::WriteLine(System::String(u"Assignment BudgetCost = ") + System::Convert::ToString(assn->Get<System::Decimal>(Asn::BudgetCost())));
            }
        }
    }
    // ExEnd:ReadBudgetWorkAndCost
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
