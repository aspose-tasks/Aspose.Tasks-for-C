#pragma once
/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/

#include <aspose.tasks.cpp/Task.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/collections/icomparer.h>
#include <cstdint>


namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

class SortTasksByColumnInGanttChart :  public System::Object
{
    typedef SortTasksByColumnInGanttChart ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType>    ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    class TasksNameComparer : public System::Collections::Generic::IComparer<System::SharedPtr<Aspose::Tasks::Task>>
    {
        typedef TasksNameComparer ThisType;
        typedef System::Collections::Generic::IComparer<System::SharedPtr<Aspose::Tasks::Task>> BaseType;
        
        typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
        RTTI_INFO_DECL();
        
    public:
    
        int32_t Compare(System::SharedPtr<Task> const &x, System::SharedPtr<Task> const &y) ASPOSE_CONST override;
        
    };
    
    class TasksDurationComparer : public System::Collections::Generic::IComparer<System::SharedPtr<Aspose::Tasks::Task>>
    {
        typedef TasksDurationComparer ThisType;
        typedef System::Collections::Generic::IComparer<System::SharedPtr<Aspose::Tasks::Task>> BaseType;
        
        typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
        RTTI_INFO_DECL();
        
    public:
    
        int32_t Compare(System::SharedPtr<Task> const &x, System::SharedPtr<Task> const &y) ASPOSE_CONST override;
        
    };
    
    
public:

    static void Run();
    
};

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


