/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Miscellaneous/ReadTableDataFromProjectFile.h"

#include <TableFieldCollection.h>
#include <TableField.h>
#include <TableCollection.h>
#include <Table.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <system/collections/ienumerator.h>
#include <Project.h>
#include <drawing/string_alignment.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(4214469493u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::ReadTableDataFromProjectFile, ThisTypeBaseTypesInfo);

void ReadTableDataFromProjectFile::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadTableDataFromProjectFile
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadTableData.mpp");
    
    // Access table
    System::SharedPtr<Table> task1 = project->get_Tables()->ToList()->idx_get(0);
    System::Console::WriteLine(System::String(u"Table Fields Count") + task1->get_TableFields()->get_Count());
    
    // Display all table fields information
    
    {
        auto tableField_enumerator = (task1->get_TableFields())->GetEnumerator();
        while (tableField_enumerator->MoveNext())
        {
            auto&& tableField = tableField_enumerator->get_Current();
            System::Console::WriteLine(System::String(u"Field width: ") + tableField->get_Width());
            System::Console::WriteLine(System::String(u"Field Title: ") + tableField->get_Title());
            System::Console::WriteLine(System::String(u"Field Title Alignment: ") + System::ObjectExt::ToString(tableField->get_AlignTitle()));
            System::Console::WriteLine(System::String(u"Field Align Data: ") + System::ObjectExt::ToString(tableField->get_AlignData()));
        }
    }
    // ExEnd:ReadTableDataFromProjectFile
}

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
