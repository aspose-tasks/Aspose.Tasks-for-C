#pragma once

#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/collections/icomparer.h>
#include <Resource.h>
#include <cstdint>


namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Miscellaneous {

class SortResourcesByName : public System::Object
{
    typedef SortResourcesByName ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
private:

    class RscNameComparer : public System::Collections::Generic::IComparer<System::SharedPtr<Aspose::Tasks::Resource>>
    {
        typedef RscNameComparer ThisType;
        typedef System::Collections::Generic::IComparer<System::SharedPtr<Aspose::Tasks::Resource>> BaseType;
        
        typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
        RTTI_INFO_DECL();
        
    public:
    
        int32_t Compare(System::SharedPtr<Resource> const &x, System::SharedPtr<Resource> const &y) ASPOSE_CONST override;
        
    };
    
    
public:

    static void Run();
    
};

} // namespace Miscellaneous
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


