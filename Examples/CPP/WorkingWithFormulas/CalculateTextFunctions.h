#pragma once

#include <system/shared_ptr.h>
#include <system/object.h>

namespace Aspose { namespace Tasks { class Project; } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

class CalculateTextFunctions : public System::Object
{
    typedef CalculateTextFunctions ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static void Run();
    static void EvaluateStrConv();
    static void EvaluateStringFunction();
    static System::SharedPtr<Project> CreateTestProjectWithCustomField();
    
};

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


