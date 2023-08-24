/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Miscellaneous/ReadFilterDefinitionData.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/FilterCollection.h>
#include <aspose.tasks.cpp/Filter.h>
#include <aspose.tasks.cpp/enums/ItemType.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(613948055u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::ReadFilterDefinitionData, ThisTypeBaseTypesInfo);

void ReadFilterDefinitionData::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadFilterDefinitionData
    // Instantiate project and access task filters
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadFilterDefinitionData.mpp");
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<Filter>>> taskFilters = project->get_TaskFilters()->ToList();
    System::Console::WriteLine(System::String(u"Task Filters Count: ") + taskFilters->get_Count());
    System::Console::WriteLine(System::String(u"All Tasks: ") + taskFilters->idx_get(0)->get_Name());
    System::Console::WriteLine(System::String(u"Task Item: ") + System::ObjectExt::ToString(taskFilters->idx_get(0)->get_FilterType()));
    System::Console::WriteLine(System::String(u"Task Filters Show In Menu: ") + taskFilters->idx_get(0)->get_ShowInMenu());
    System::Console::WriteLine(System::String(u"Task filter ShowRelatedSummaryRows: ") + taskFilters->idx_get(0)->get_ShowRelatedSummaryRows());
    
    // Access resource filters
    System::SharedPtr<System::Collections::Generic::List<System::SharedPtr<Filter>>> rscFilters = project->get_ResourceFilters()->ToList();
    System::Console::WriteLine(System::String(u"Project.ResourceFilters count: ") + rscFilters->get_Count());
    System::Console::WriteLine(System::String(u"Resource Filter Item Type: Item.ResourceType: ") + System::ObjectExt::ToString(rscFilters->idx_get(0)->get_FilterType()));
    System::Console::WriteLine(System::String(u"Resource filter ShowInMenu") + rscFilters->idx_get(0)->get_ShowInMenu());
    System::Console::WriteLine(System::String(u"Resource filter ShowRelatedSummaryRows: ") + rscFilters->idx_get(0)->get_ShowRelatedSummaryRows());
    // ExEnd:ReadFilterDefinitionData
}

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
