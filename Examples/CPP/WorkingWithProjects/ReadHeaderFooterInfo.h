#pragma once
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/

#include <system/shared_ptr.h>
#include <system/object.h>

namespace Aspose { namespace Tasks { namespace Visualization { class PageInfo; } } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

class ReadHeaderFooterInfo : public System::Object
{
    typedef ReadHeaderFooterInfo ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static void Run();
    
private:

    static void AssertHeaderFooterCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info);
    static void AssertPageSettingsCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info);
    static void AssertPageViewSettingsCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info);
    static void AssertMarginsCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info);
    static void AssertLegendCorrect(System::SharedPtr<Aspose::Tasks::Visualization::PageInfo> info);
    
};

} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


