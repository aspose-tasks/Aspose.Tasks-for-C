/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "WorkingWithProjects/WorkingWithProjectViews/ConfigureGantChart.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <aspose.tasks.cpp/TableFieldCollection.h>
#include <aspose.tasks.cpp/TableField.h>
#include <aspose.tasks.cpp/TableCollection.h>
#include <aspose.tasks.cpp/Table.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/MPPSaveOptions.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinitionCollection.h>
#include <aspose.tasks.cpp/ExtendedAttributeDefinition.h>
#include <aspose.tasks.cpp/ExtendedAttributeCollection.h>
#include <aspose.tasks.cpp/ExtendedAttribute.h>
#include <aspose.tasks.cpp/enums/Field.h>
#include <aspose.tasks.cpp/enums/ExtendedAttributeTask.h>
#include <aspose.tasks.cpp/Visualization/View/HorizontalStringAlignment.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace WorkingWithProjectViews {

RTTI_INFO_IMPL_HASH(2127371106u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectViews::ConfigureGantChart, ThisTypeBaseTypesInfo);

void ConfigureGantChart::Run()
{
    try
    {
        // ExStart:ConfigureGantChart
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Project5.mpp");
        // Create a new project task
        System::SharedPtr<Task> task = project->get_RootTask()->get_Children()->Add(u"New Activity");
        
        // Define new custom attribute
        System::SharedPtr<ExtendedAttributeDefinition> text1Definition = ExtendedAttributeDefinition::CreateTaskDefinition(Aspose::Tasks::ExtendedAttributeTask::Text1, nullptr);
        project->get_ExtendedAttributes()->Add(text1Definition);
        // Add custom text attribute to created task.
        task->get_ExtendedAttributes()->Add(text1Definition->CreateExtendedAttribute(System::String(u"Activity attribute")));
        
        // Customize table by adding text attribute field
        System::SharedPtr<TableField> attrField = System::MakeObject<TableField>();
        attrField->set_Field(Aspose::Tasks::Field::TaskText1);
        attrField->set_Width(20);
        attrField->set_Title(u"Custom attribute");
        attrField->set_AlignTitle(Visualization::HorizontalStringAlignment::Center);
        attrField->set_AlignData(Visualization::HorizontalStringAlignment::Center);
        
        System::SharedPtr<Table> table = project->get_Tables()->ToList()->idx_get(0);
        table->get_TableFields()->Insert(3, attrField);
        
        project->Save(dataDir + u"ConfigureGantChart_out.mpp", [&]{ auto tmp_0 = System::MakeObject<MPPSaveOptions>(); tmp_0->set_WriteViewData(true); return tmp_0; }());
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http:// Www.aspose.com/purchase/default.aspx.");
    }
    
    // ExEnd:ConfigureGantChart
}

} // namespace WorkingWithProjectViews
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
