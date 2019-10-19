#include "WorkingWithEncodings.h"

#include <system/type_info.h>
#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/io/stream_reader.h>
#include <system/io/stream.h>
#include <system/details/dispose_guard.h>
#include <Project.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace CreatingReadingAndSaving {

RTTI_INFO_IMPL_HASH(2187330665u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving::WorkingWithEncodings, ThisTypeBaseTypesInfo);

// Using statement is translated using System::Details::DisposeGuard class which may store exception and then throw from destructor.
// We block the warnings related as these are false alarms (the exception, if caught, will be re-thrown from the destructor).
#if defined(__MSVC__)
#pragma warning( push )
#pragma warning(disable : 4715)
#pragma warning(disable : 4700)
#pragma warning(disable : 4701)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
#endif
void WorkingWithEncodings::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:WorkingWithEncodings
    // Specify Encodings
    {
        System::SharedPtr<System::IO::StreamReader> streamReader = System::MakeObject<System::IO::StreamReader>(dataDir + u"Project.mpx", System::Text::Encoding::GetEncoding(u"ISO-8859-1"));
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ streamReader});
        // ------------------------------------------
        
        try
        {
            auto project = System::MakeObject<Project>(streamReader->get_BaseStream());
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:WorkingWithEncodings
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

} // namespace CreatingReadingAndSaving
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
