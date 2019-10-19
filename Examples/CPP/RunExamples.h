#pragma once

#include <system/string.h>
#include <system/object.h>

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

class RunExamples : public System::Object
{
    typedef RunExamples ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static void Main();
    static System::String GetDataDir(System::String exampleName);
    
};

} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


