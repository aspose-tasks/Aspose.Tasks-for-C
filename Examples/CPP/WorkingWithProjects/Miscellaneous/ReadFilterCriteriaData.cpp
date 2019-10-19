/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Miscellaneous/ReadFilterCriteriaData.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/array.h>
#include <Project.h>
#include <FilterCriteria.h>
#include <FilterCollection.h>
#include <Filter.h>
#include <enums/FilterOperation.h>
#include <enums/FilterComparisonType.h>
#include <enums/Field.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(1294544771u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::ReadFilterCriteriaData, ThisTypeBaseTypesInfo);

void ReadFilterCriteriaData::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadFilterCriteriaData
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2003.mpp");
    
    System::SharedPtr<Filter> filter = project->get_TaskFilters()->ToList()->idx_get(1);
    System::Console::WriteLine(filter->get_Criteria()->get_CriteriaRows()->get_Count());
    System::Console::WriteLine(System::ObjectExt::ToString(filter->get_Criteria()->get_Operation()));
    
    System::SharedPtr<FilterCriteria> criteria1 = filter->get_Criteria()->get_CriteriaRows()->idx_get(0);
    System::Console::WriteLine(System::ObjectExt::ToString(criteria1->get_Test()));
    System::Console::WriteLine(System::ObjectExt::ToString(criteria1->get_Field()));
    System::Console::WriteLine(System::ObjectExt::ToString(criteria1->get_Values()[0]));
    
    System::SharedPtr<FilterCriteria> criteria2 = filter->get_Criteria()->get_CriteriaRows()->idx_get(1);
    System::Console::WriteLine(System::ObjectExt::ToString(criteria2->get_Operation()));
    System::Console::WriteLine(criteria2->get_CriteriaRows()->get_Count());
    
    System::SharedPtr<FilterCriteria> criteria21 = criteria2->get_CriteriaRows()->idx_get(0);
    System::Console::WriteLine(System::ObjectExt::ToString(criteria21->get_Test()));
    System::Console::WriteLine(System::ObjectExt::ToString(criteria21->get_Field()));
    System::Console::WriteLine(System::ObjectExt::ToString(criteria21->get_Values()[0]));
    
    System::SharedPtr<FilterCriteria> criteria22 = criteria2->get_CriteriaRows()->idx_get(1);
    System::Console::WriteLine(System::ObjectExt::ToString(criteria22->get_Test()));
    System::Console::WriteLine(System::ObjectExt::ToString(criteria22->get_Field()));
    System::Console::WriteLine(System::ObjectExt::ToString(criteria22->get_Values()[0]));
    System::Console::WriteLine(filter->get_Criteria());
    // ExEnd:ReadFilterCriteriaData
}

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
