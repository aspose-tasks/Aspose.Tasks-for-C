/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithFormulas/WriteFormulasInExtendedAttributesToMPP.h"

#include <Tsk.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/decimal.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Project.h>
#include <Prj.h>
#include <NullableBool.h>
#include <license/License.h>
#include <Key.h>
#include <ExtendedAttributeDefinitionCollection.h>
#include <ExtendedAttributeDefinition.h>
#include <enums/TaskKey.h>
#include <enums/PrjKey.h>
#include <enums/ExtendedAttributeTask.h>
#include <enums/CustomFieldType.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithFormulas {

RTTI_INFO_IMPL_HASH(1737328486u, ::Aspose::Tasks::Examples::CPP::WorkingWithFormulas::WriteFormulasInExtendedAttributesToMPP, ThisTypeBaseTypesInfo);

void WriteFormulasInExtendedAttributesToMPP::Run()
{
    try
    {
        auto lic = System::MakeObject<License>();
        lic->SetLicense(u"E:\\Aspose\\License\\Aspose.Tasks.lic");
        
        // ExStart:WriteFormulasInExtendedAttributesToMPP
        // Create project instance
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project1.mpp");
        project->Set<NullableBool>(Prj::NewTasksAreManual(), NullableBool::to_NullableBool(false));
        
        // Create new custom field (Task Text1) with formula which will double task cost
        System::SharedPtr<ExtendedAttributeDefinition> attr = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::CustomFieldType::Text, Aspose::Tasks::ExtendedAttributeTask::Text1, u"Custom");
        attr->set_Alias(u"Double Costs");
        attr->set_Formula(u"[Cost]*2");
        project->get_ExtendedAttributes()->Add(attr);
        
        // Add a task
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"Task");
        
        // Set task cost            
        task->Set<System::Decimal>(Tsk::Cost(), static_cast<System::Decimal>(100));
        
        // Save project
        project->Save(dataDir + u"WriteFormulasInExtendedAttributesToMPP_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:WriteFormulasInExtendedAttributesToMPP
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithFormulas
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
