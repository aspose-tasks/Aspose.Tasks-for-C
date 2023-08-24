/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "SetGanttChartViewStartDate.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/date_time.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Prj.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/PrjKey.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(1912857483u, ::Aspose::Tasks::Examples::CPP::Articles::SetGanttChartViewStartDate, ThisTypeBaseTypesInfo);

void SetGanttChartViewStartDate::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:SetGanttChartViewStartDate
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project2.mpp");
        project->Set(Prj::TimescaleStart(), System::DateTime(2012, 4, 30));
        project->Save(dataDir + u"SetGanttChartViewStartDate_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:SetGanttChartViewStartDate
    }
    catch (System::NotSupportedException& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
