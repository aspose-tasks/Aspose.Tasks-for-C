#pragma once
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>

namespace Aspose { namespace Tasks { class ParseErrorArgs; } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace CreatingReadingAndSaving {

class IgnoreInvalidCharactersDuringloadingProject : public System::Object
{
    typedef IgnoreInvalidCharactersDuringloadingProject ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static void Run();
    
private:

    static System::String GetModifiedXml();
    static System::SharedPtr<System::Object> CustomDurationHandler(System::SharedPtr<System::Object> sender, System::SharedPtr<ParseErrorArgs> args);
    
};

} // namespace CreatingReadingAndSaving
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


