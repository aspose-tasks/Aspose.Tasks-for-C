#include "HandleExceptions.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <Project.h>
#include <exceptions/TasksReadingException.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(1067222091u, ::Aspose::Tasks::Examples::CPP::Miscellaneous::HandleExceptions, ThisTypeBaseTypesInfo);

void HandleExceptions::Run()
{
    // ExStart:HandleExceptions
    System::SharedPtr<Project> project;
    try
    {
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        project = System::MakeObject<Project>(dataDir + u"project.mpp");
    }
    catch (TasksReadingException& ex)
    {
        System::Console::WriteLine(u"Message:");
        System::Console::WriteLine(ex->get_Message());
        System::Console::WriteLine(u"Log:");
        System::Console::WriteLine(ex->get_LogText());
        if (ex->get_InnerException() != nullptr)
        {
            System::Console::WriteLine(u"Inner exception message:");
            System::Console::WriteLine(ex->get_InnerException()->get_Message());
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
    // ExEnd:HandleExceptions
}

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
