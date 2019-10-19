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

namespace Aspose { namespace Tasks { class Task; } }
namespace Aspose { namespace Tasks { class Resource; } }
namespace Aspose { namespace Tasks { class ResourceAssignment; } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

class UsingXlsxOptions : public System::Object
{
    typedef UsingXlsxOptions ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static System::String _anonymous_method_0(System::SharedPtr<Task> task);
    static System::String _anonymous_method_1(System::SharedPtr<Resource> resource);
    static System::String _anonymous_method_2(System::SharedPtr<ResourceAssignment> assignment);
    static void Run();
    
};

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


