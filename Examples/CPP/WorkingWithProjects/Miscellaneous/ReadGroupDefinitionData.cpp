/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Miscellaneous/ReadGroupDefinitionData.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/enum_helpers.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/GroupCriterionCollection.h>
#include <aspose.tasks.cpp/GroupCriterion.h>
#include <aspose.tasks.cpp/GroupCollection.h>
#include <aspose.tasks.cpp/Group.h>
#include <aspose.tasks.cpp/Visualization/FontDescriptor.h>
#include <aspose.tasks.cpp/Visualization/FontStyles.h>
#include <aspose.tasks.cpp/enums/GroupOn.h>
#include <aspose.tasks.cpp/enums/Field.h>
#include <aspose.tasks.cpp/enums/BackgroundPattern.h>
#include <drawing/font_style.h>
#include <drawing/font.h>
#include <drawing/color.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(2501166746u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::ReadGroupDefinitionData, ThisTypeBaseTypesInfo);

void ReadGroupDefinitionData::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadGroupDefinitionData
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadGroupDefinitionData.mpp");
    
    System::Console::WriteLine(System::String(u"Task Groups Count: ") + project->get_TaskGroups()->get_Count());
    System::SharedPtr<Group> taskGroup = project->get_TaskGroups()->ToList()->idx_get(1);
    System::Console::WriteLine(u"Group Name:", System::ObjectExt::Box<System::String>(taskGroup->get_Name()));
    System::Console::WriteLine(System::String(u"Group Criteria count: ") + taskGroup->get_GroupCriteria()->get_Count());
    System::Console::WriteLine(u"\n************* Retrieving Task Group's Criterion information *************");
    System::SharedPtr<GroupCriterion> criterion = taskGroup->get_GroupCriteria()->ToList()->idx_get(0);
    System::Console::WriteLine(System::String(u"Criterion Field: ") + System::ObjectExt::ToString(criterion->get_Field()));
    System::Console::WriteLine(System::String(u"Criterion GroupOn: ") + System::ObjectExt::ToString(criterion->get_GroupOn()));
    System::Console::WriteLine(System::String(u"Criterion Cell Color: ") + criterion->get_CellColor());
    System::Console::WriteLine(System::String(u"Criterion Pattern: ") + System::ObjectExt::ToString(criterion->get_Pattern()));
    
    if (taskGroup == criterion->get_ParentGroup())
    {
        System::Console::WriteLine(u"Parent Group is equval to task Group.");
    }
    
    System::Console::WriteLine(u"\n*********** Retreivnig Criterion's Font Information ***********");
    System::Console::WriteLine(System::String(u"Font Name: ") + criterion->get_Font()->get_FontFamily());
    System::Console::WriteLine(System::String(u"Font Size: ") + criterion->get_Font()->get_Size());
    System::Console::WriteLine(System::String(u"Font Style: ") + System::ObjectExt::ToString(criterion->get_Font()->get_Style()));
    System::Console::WriteLine(System::String(u"Ascending/Dscending: ") + criterion->get_Ascending());
    // ExEnd:ReadGroupDefinitionData
}

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
