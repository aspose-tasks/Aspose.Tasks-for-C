#include "ReadTaskExtendedAttributes.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/decimal.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/CustomFieldType.h>
#include <aspose.tasks.cpp/Duration.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(480443953u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::ReadTaskExtendedAttributes, ThisTypeBaseTypesInfo);

void ReadTaskExtendedAttributes::Run()
{
    // ExStart:ReadTaskExtendedAttributes
    // Create project instance
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"ReadTaskExtendedAttributes.mpp");
    
    // Read extended attributes for tasks
    
    {
        auto tsk_enumerator = (project1->get_RootTask()->get_Children())->GetEnumerator();
        while (tsk_enumerator->MoveNext())
        {
            auto&& tsk = tsk_enumerator->get_Current();
            auto ea_enumerator = (tsk->get_ExtendedAttributes())->GetEnumerator();
            while (ea_enumerator->MoveNext())
            {
                auto&& ea = ea_enumerator->get_Current();
                System::Console::WriteLine(ea->get_FieldId());
                System::Console::WriteLine(ea->get_ValueGuid());
                
                switch (ea->get_AttributeDefinition()->get_CfType())
                {
                    case Aspose::Tasks::CustomFieldType::Date:
                    case Aspose::Tasks::CustomFieldType::Start:
                    case Aspose::Tasks::CustomFieldType::Finish:
                        System::Console::WriteLine(System::ObjectExt::Box<System::DateTime>(ea->get_DateValue()));
                        break;
                    
                    case Aspose::Tasks::CustomFieldType::Text:
                        System::Console::WriteLine(ea->get_TextValue());
                        break;
                    
                    case Aspose::Tasks::CustomFieldType::Duration:
                        System::Console::WriteLine(System::ObjectExt::ToString(ea->get_DurationValue()));
                        break;
                    
                    case Aspose::Tasks::CustomFieldType::Cost:
                    case Aspose::Tasks::CustomFieldType::Number:
                        System::Console::WriteLine(ea->get_NumericValue());
                        break;
                    
                    case Aspose::Tasks::CustomFieldType::Flag:
                        System::Console::WriteLine(ea->get_FlagValue());
                        break;
                    
                    default:
                        break;
                }
            }
        }
    }
    // ExEnd:ReadTaskExtendedAttributes
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
