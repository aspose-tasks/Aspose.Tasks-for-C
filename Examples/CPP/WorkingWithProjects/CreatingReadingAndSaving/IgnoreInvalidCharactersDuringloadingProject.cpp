/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/CreatingReadingAndSaving/IgnoreInvalidCharactersDuringloadingProject.h"

#include <system/type_info.h>
#include <system/timespan.h>
#include <system/text/regularexpressions/regex.h>
#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/io/text_reader.h>
#include <system/io/stream_reader.h>
#include <system/io/memory_stream.h>
#include <system/exceptions.h>
#include <system/diagnostics/debug.h>
#include <system/details/dispose_guard.h>
#include <system/array.h>
#include <Project.h>
#include <io/xml/ParseErrorCallback.h>
#include <io/xml/ParseErrorArgs.h>
#include <Duration.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace CreatingReadingAndSaving {

RTTI_INFO_IMPL_HASH(1268776269u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving::IgnoreInvalidCharactersDuringloadingProject, ThisTypeBaseTypesInfo);

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
void IgnoreInvalidCharactersDuringloadingProject::Run()
{
    // Open modified xml stream
    {
        System::SharedPtr<System::IO::MemoryStream> stream = System::MakeObject<System::IO::MemoryStream>(System::Text::Encoding::get_UTF8()->GetBytes(GetModifiedXml()));
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ stream});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<Project> project = System::MakeObject<Project>(stream, static_cast<ParseErrorCallback>(CustomDurationHandler));
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

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
System::String IgnoreInvalidCharactersDuringloadingProject::GetModifiedXml()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::String xml;
    
    // Open valid xml file and modify it
    {
        System::SharedPtr<System::IO::TextReader> reader = System::MakeObject<System::IO::StreamReader>(dataDir + u"IgnoreInvalidCharacters.xml");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ reader});
        // ------------------------------------------
        
        try
        {
            xml = reader->ReadToEnd();
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    
    System::SharedPtr<System::Text::RegularExpressions::Regex> regex = System::MakeObject<System::Text::RegularExpressions::Regex>(u"PT(\\d+)H(\\d+)M(\\d+)S");
    return regex->Replace(xml, u"**$1Hrs$2Mins$3Secs**");
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

System::SharedPtr<System::Object> IgnoreInvalidCharactersDuringloadingProject::CustomDurationHandler(System::SharedPtr<System::Object> sender, System::SharedPtr<ParseErrorArgs> args)
{
    System::SharedPtr<System::Text::RegularExpressions::Regex> regex = System::MakeObject<System::Text::RegularExpressions::Regex>(u"[*]{2}(\\d+)Hrs(\\d+)Mins(\\d+)Secs[*]{2}");
    if (args->get_FieldType() == System::ObjectExt::GetType<System::TimeSpan>())
    {
        System::Diagnostics::Debug::Print(u"Object field : {0}, Invalid value : {1}", System::MakeArray<System::SharedPtr<System::Object>>({System::ObjectExt::Box<System::String>(args->get_FieldName()), System::ObjectExt::Box<System::String>(args->get_InvalidValue())}));
        System::String duration = regex->Replace(args->get_InvalidValue(), u"PT$1H$2M$3S");
        System::TimeSpan newValue = Duration::ParseTimeSpan(duration);
        System::Diagnostics::Debug::Print(u"New value : {0}", System::MakeArray<System::SharedPtr<System::Object>>({System::ObjectExt::Box<System::TimeSpan>(newValue)}));
        return System::ObjectExt::Box<System::TimeSpan>(newValue);
    }
    // Here we handle only TimeSpan instances, so rethrow original exception with other types
    args->get_Exception().Throw();
}

} // namespace CreatingReadingAndSaving
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
