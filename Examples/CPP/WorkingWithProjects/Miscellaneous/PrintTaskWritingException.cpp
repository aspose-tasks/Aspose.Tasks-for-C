#include "WorkingWithProjects/Miscellaneous/PrintTaskWritingException.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <exceptions/TasksWritingException.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(1734764825u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::PrintTaskWritingException, ThisTypeBaseTypesInfo);

void PrintTaskWritingException::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:PrintTaskWritingException
    try
    {
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"PrintTaskWritingException.mpp");
        System::Console::Write(u"This example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
        project->Save(dataDir + u"project_out.MPP", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
    }
    catch (TasksWritingException& ex)
    {
        System::Console::WriteLine(ex->get_LogText());
    }
    catch (System::NotSupportedException& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:PrintTaskWritingException
}

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
