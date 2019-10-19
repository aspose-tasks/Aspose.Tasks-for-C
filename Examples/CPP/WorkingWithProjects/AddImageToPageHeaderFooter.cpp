/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/AddImageToPageHeaderFooter.h"

#include <visualization/PageLegend.h>
#include <visualization/PageInfo.h>
#include <visualization/HeaderFooterInfo.h>
#include <View.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <saving/MPPSaveOptions.h>
#include <Project.h>
#include <drawing/image.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

RTTI_INFO_IMPL_HASH(2281577038u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::AddImageToPageHeaderFooter, ThisTypeBaseTypesInfo);

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
void AddImageToPageHeaderFooter::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:AddImageToPageHeaderFooter
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"AddImageToPageHeaderFooter.mpp");
        
        project->get_RootTask()->get_Children()->Add(u"Task1");
        System::SharedPtr<PageInfo> pageInfo = project->get_DefaultView()->get_PageInfo();
        
        {
            System::SharedPtr<System::Drawing::Image> image = System::Drawing::Image::FromFile(dataDir + u"Image1.png");
            // Clearing resources under 'using' statement
            System::Details::DisposeGuard<1> __dispose_guard_0({ image});
            // ------------------------------------------
            
            try
            {
                pageInfo->get_Header()->set_CenteredImage(image);
                pageInfo->get_Legend()->set_LeftImage(image);
                pageInfo->get_Legend()->set_LeftText(System::String::Empty);
                System::SharedPtr<MPPSaveOptions> saveOptions = System::MakeObject<MPPSaveOptions>();
                saveOptions->set_WriteViewData(true);
                project->Save(dataDir + u"AddImageToPageHeaderFooter_out.mpp", saveOptions);
            }
            catch(...)
            {
                __dispose_guard_0.SetCurrentException(std::current_exception());
            }
        }
        // ExEnd:AddImageToPageHeaderFooter
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}
#if defined(__MSVC__)
#pragma warning( pop )
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
