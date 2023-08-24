/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/Miscellaneous/EmbeddedObjectsCreatedInsideApplication.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/io/file_stream.h>
#include <system/io/file_mode.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/collections/idictionary.h>
#include <system/collections/dictionary.h>
#include <system/array.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/OleObjectCollection.h>
#include <aspose.tasks.cpp/OleObject.h>
#include <cstdint>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace Miscellaneous {

RTTI_INFO_IMPL_HASH(4112062410u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::Miscellaneous::EmbeddedObjectsCreatedInsideApplication, ThisTypeBaseTypesInfo);

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
void EmbeddedObjectsCreatedInsideApplication::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:EmbeddedObjectsCreatedInsideApplication
        System::SharedPtr<System::Collections::Generic::IDictionary<System::String, System::String>> fileFormatExt = System::MakeObject<System::Collections::Generic::Dictionary<System::String, System::String>>();
        fileFormatExt->Add(u"RTF", u"_rtfFile_out.rtf");
        fileFormatExt->Add(u"MSWordDoc", u"_wordFile_out.docx");
        fileFormatExt->Add(u"ExcelML12", u"_excelFile_out.xlsx");
        
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Embedded.mpp");
        
        
        {
            auto oleObject_enumerator = (project->get_OleObjects())->GetEnumerator();
            while (oleObject_enumerator->MoveNext())
            {
                auto&& oleObject = oleObject_enumerator->get_Current();
                if (!System::String::IsNullOrEmpty(oleObject->get_FileFormat()) && fileFormatExt->ContainsKey(oleObject->get_FileFormat()))
                {
                    System::String path = dataDir + u"EmbeddedContent_" + fileFormatExt->idx_get(oleObject->get_FileFormat());
                    {
                        System::SharedPtr<System::IO::FileStream> fileStream = System::MakeObject<System::IO::FileStream>(path, System::IO::FileMode::Create);
                        // Clearing resources under 'using' statement
                        System::Details::DisposeGuard<1> __dispose_guard_0({ fileStream});
                        // ------------------------------------------
                        
                        try
                        {
                            fileStream->Write(oleObject->get_Content(), 0, oleObject->get_Content()->get_Length());
                        }
                        catch(...)
                        {
                            __dispose_guard_0.SetCurrentException(std::current_exception());
                        }
                    }
                }
            }
        }
        // ExEnd:EmbeddedObjectsCreatedInsideApplication
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
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
