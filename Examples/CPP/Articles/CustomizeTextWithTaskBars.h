#pragma once

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>

namespace Aspose { namespace Tasks { class Task; } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

class CustomizeTextWithTaskBars : public System::Object
{
    typedef CustomizeTextWithTaskBars ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static System::String _anonymous_method_0(System::SharedPtr<Task> t);
    static void Run();
    
};

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


