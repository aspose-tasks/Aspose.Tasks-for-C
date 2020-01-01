#include "WorkingWithResources/ResourcePrefixForNestedResources.h"

#include <visualization/View/PageSize.h>
#include <visualization/Enums/Timescale.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/io/stream.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/io/directory.h>
#include <system/enum_helpers.h>
#include <system/details/dispose_guard.h>
#include <system/collections/list.h>
#include <saving/Html/ImageSavingArgs.h>
#include <saving/Html/IImageSavingCallback.h>
#include <saving/Html/IFontSavingCallback.h>
#include <saving/Html/ICssSavingCallback.h>
#include <saving/Html/HtmlSaveOptions.h>
#include <saving/Html/FontSavingArgs.h>
#include <saving/Html/CssSavingArgs.h>
#include <Project.h>
#include <mutex>
#include <enums/ResourceExportType.h>
#include <enums/FontFaceType.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

RTTI_INFO_IMPL_HASH(2682247042u, ::Aspose::Tasks::Examples::CPP::WorkingWithResources::ResourcePrefixForNestedResources, ThisTypeBaseTypesInfo);

System::String& ResourcePrefixForNestedResources::dataDir()
{
    static System::String value;
    static std::once_flag once;
    std::call_once(once, []
    {
        value = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    });
    return value;
}

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
// ExStart:ResourcePrefixForNestedResources
void ResourcePrefixForNestedResources::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    {
        System::SharedPtr<System::IO::FileStream> fs = System::MakeObject<System::IO::FileStream>(dataDir + u"Project1.mpp", System::IO::FileMode::Open);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_1({ fs});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<Project> project = System::MakeObject<Project>(fs);
            System::SharedPtr<HtmlSaveOptions> options = GetSaveOptions(1);
            {
                System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(dataDir + u"document.html", System::IO::FileMode::Create);
                // Clearing resources under 'using' statement
                System::Details::DisposeGuard<1> __dispose_guard_0({ stream});
                // ------------------------------------------
                
                try
                {
                    project->Save(stream, options);
                }
                catch(...)
                {
                    __dispose_guard_0.SetCurrentException(std::current_exception());
                }
            }
        }
        catch(...)
        {
            __dispose_guard_1.SetCurrentException(std::current_exception());
        }
    }
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

void ResourcePrefixForNestedResources::CssSaving(System::SharedPtr<CssSavingArgs> args)
{
    System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(dataDir() + u"css/" + args->get_FileName(), System::IO::FileMode::Create);
    args->set_Stream(stream);
    args->set_KeepStreamOpen(false);
    args->set_Uri(dataDir() + u"css/" + args->get_FileName());
}

void ResourcePrefixForNestedResources::FontSaving(System::SharedPtr<FontSavingArgs> args)
{
    System::SharedPtr<System::IO::FileStream> stream = System::MakeObject<System::IO::FileStream>(dataDir() + u"fonts/" + args->get_FileName(), System::IO::FileMode::Create);
    args->set_Stream(stream);
    args->set_KeepStreamOpen(false);
    args->set_Uri(dataDir() + u"fonts/" + args->get_FileName());
}

void ResourcePrefixForNestedResources::ImageSaving(System::SharedPtr<ImageSavingArgs> args)
{
    if (args->get_FileName().EndsWith(u"png"))
    {
        System::SharedPtr<System::IO::FileStream> stream1 = System::MakeObject<System::IO::FileStream>(dataDir() + u"resources/nestedResources/" + args->get_FileName(), System::IO::FileMode::Create);
        args->set_Stream(stream1);
        args->set_KeepStreamOpen(false);
        args->set_Uri(dataDir() + u"resources/" + args->get_FileName());
        //args->set_NestedUri(dataDir() + u"nestedResources/" + args->get_FileName());
    }
    else
    {
        System::SharedPtr<System::IO::FileStream> stream2 = System::MakeObject<System::IO::FileStream>(dataDir() + u"resources/" + args->get_FileName(), System::IO::FileMode::Create);
        args->set_Stream(stream2);
        args->set_KeepStreamOpen(false);
        args->set_Uri(dataDir() + u"resources/" + args->get_FileName());
    }
}

System::SharedPtr<Aspose::Tasks::Saving::HtmlSaveOptions> ResourcePrefixForNestedResources::GetSaveOptions(int32_t pageNumber)
{
    auto saveOptions = [&]{ auto tmp_0 = System::MakeObject<HtmlSaveOptions>(); tmp_0->set_Pages(System::MakeObject<System::Collections::Generic::List<int32_t>>()); tmp_0->set_IncludeProjectNameInPageHeader(false); tmp_0->set_IncludeProjectNameInTitle(false); tmp_0->set_PageSize(Aspose::Tasks::Visualization::PageSize::A3); tmp_0->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths); tmp_0->set_ReduceFooterGap(true); tmp_0->set_FontFaceTypes(Aspose::Tasks::FontFaceType::Ttf); tmp_0->set_ExportCss(Aspose::Tasks::ResourceExportType::AsFile); tmp_0->set_ExportFonts(Aspose::Tasks::ResourceExportType::AsFile); tmp_0->set_ExportImages(Aspose::Tasks::ResourceExportType::AsFile); return tmp_0; }();
    
    System::SharedPtr<ResourcePrefixForNestedResources> program = System::MakeObject<ResourcePrefixForNestedResources>();
    saveOptions->set_FontSavingCallback(program);
    saveOptions->set_CssSavingCallback(program);
    saveOptions->set_ImageSavingCallback(program);
    
    saveOptions->get_Pages()->Clear();
    saveOptions->get_Pages()->Add(pageNumber);
    
    if (!System::IO::Directory::Exists(dataDir() + u"fonts"))
    {
        System::IO::Directory::CreateDirectory_(dataDir() + u"fonts");
    }
    
    if (!System::IO::Directory::Exists(dataDir() + u"resources"))
    {
        System::IO::Directory::CreateDirectory_(dataDir() + u"resources");
    }
    
    if (!System::IO::Directory::Exists(dataDir() + u"nestedResources"))
    {
        System::IO::Directory::CreateDirectory_(dataDir() + u"resources/nestedResources");
    }
    
    if (!System::IO::Directory::Exists(dataDir() + u"css"))
    {
        System::IO::Directory::CreateDirectory_(dataDir() + u"css");
    }
    
    return saveOptions;
}
// ExEnd:ResourcePrefixForNestedResources
} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
