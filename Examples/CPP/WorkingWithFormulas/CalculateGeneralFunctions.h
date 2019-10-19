#pragma once

#include <system/shared_ptr.h>
#include <system/object.h>

namespace Aspose { namespace Tasks { class Project; } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

class CalculateGeneralFunctions : public System::Object
{
    typedef CalculateGeneralFunctions ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static void Run();
    static void EvaluateChoose();
    static void EvaluateIsNumeric();
    static void EvaluateSwitch();
    static System::SharedPtr<Project> CreateTestProjectWithCustomField();
    
};

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


