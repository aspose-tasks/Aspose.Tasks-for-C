#include "WorkingWithProjects/Miscellaneous/ExtractEmbeddedObjects.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/details/dispose_guard.h>
#include <system/collections/list.h>
#include <system/array.h>
#include <Project.h>
#include <OleObjectCollection.h>
#include <OleObject.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(2474031637u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::ExtractEmbeddedObjects, ThisTypeBaseTypesInfo);

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
void ExtractEmbeddedObjects::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ExtractEmbeddedObjects
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ExtractEmbeddedObjects.mpp");
    System::SharedPtr<OleObject> ole = project->get_OleObjects()->ToList()->idx_get(0);
    
    // We have to check this property because it can be null if the embedded object was created inside the ms project application Or, alternatively, you can use this check: if (ole.FileFormat == "Package")
    if (!System::String::IsNullOrEmpty(ole->get_FullPath()))
    {
        {
            System::SharedPtr<System::IO::FileStream> fileStream = System::MakeObject<System::IO::FileStream>(dataDir, System::IO::FileMode::Create);
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ fileStream});
            // ------------------------------------------
            
            try
            {
                fileStream->Write(ole->get_Content(), 0, ole->get_Content()->get_Length());
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
    }
    // ExEnd:ExtractEmbeddedObjects
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

} // namespace Miscellaneous
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
