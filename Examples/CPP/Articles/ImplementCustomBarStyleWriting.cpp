/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ImplementCustomBarStyleWriting.h"

#include <visualization/View/Styles/GanttBarStyle.h>
#include <visualization/Enums/GanttBarMiddleShape.h>
#include <visualization/Enums/GanttBarFillPattern.h>
#include <visualization/Enums/GanttBarEndShape.h>
#include <View.h>
#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <saving/MPPSaveOptions.h>
#include <Project.h>
#include <GanttChartView.h>
#include <enums/Field.h>
#include <drawing/color.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(125600182u, ::Aspose::Tasks::Examples::CPP::Articles::ImplementCustomBarStyleWriting, ThisTypeBaseTypesInfo);

void ImplementCustomBarStyleWriting::Run()
{
    ImplementCustomBarSytle();
}

void ImplementCustomBarStyleWriting::ImplementCustomBarSytle()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"Blank2010.mpp");
        project->get_RootTask()->get_Children()->Add(u"Task");
        
        System::SharedPtr<GanttChartView> view = System::ExplicitCast<Aspose::Tasks::GanttChartView>(project->get_DefaultView());
        System::SharedPtr<GanttBarStyle> custom = GetCustomBarStyle();
        
        // Add the custom bar style to the custom bar collection of the project view
        view->get_CustomBarStyles()->Add(custom);
        
        System::String file = u"ImplementCustomBarStyleWriting_out.mpp";
        
        System::SharedPtr<MPPSaveOptions> options = System::MakeObject<MPPSaveOptions>();
        options->set_WriteViewData(true);
        
        project->Save(dataDir + file, options);
    }
    catch (System::NotSupportedException& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

System::SharedPtr<Aspose::Tasks::Visualization::GanttBarStyle> ImplementCustomBarStyleWriting::GetCustomBarStyle()
{
    System::SharedPtr<GanttBarStyle> style = System::MakeObject<GanttBarStyle>();
    style->set_ShowForTaskUid(1);
    style->set_MiddleShape(Aspose::Tasks::Visualization::GanttBarMiddleShape::RectangleBottom);
    style->set_MiddleFillPattern(Aspose::Tasks::Visualization::GanttBarFillPattern::MediumFill);
    style->set_MiddleShapeColor(System::Drawing::Color::get_Blue());
    
    style->set_StartShape(Aspose::Tasks::Visualization::GanttBarEndShape::ArrowDown);
    style->set_StartShapeColor(System::Drawing::Color::get_Red());
    
    style->set_EndShape(Aspose::Tasks::Visualization::GanttBarEndShape::ArrowUp);
    style->set_EndShapeColor(System::Drawing::Color::get_Yellow());
    
    style->set_LeftField(Aspose::Tasks::Field::TaskResourceNames);
    style->set_RightField(Aspose::Tasks::Field::TaskName);
    style->set_TopField(Aspose::Tasks::Field::TaskStart);
    style->set_BottomField(Aspose::Tasks::Field::TaskFinish);
    style->set_InsideField(Aspose::Tasks::Field::TaskDuration);
    
    return style;
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
