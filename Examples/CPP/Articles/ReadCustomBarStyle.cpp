/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadCustomBarStyle.h"

#include <visualization/View/Styles/GanttBarStyle.h>
#include <visualization/Enums/GanttBarType.h>
#include <visualization/Enums/GanttBarMiddleShape.h>
#include <visualization/Enums/GanttBarFillPattern.h>
#include <visualization/Enums/GanttBarEndShape.h>
#include <View.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/collections/list.h>
#include <Project.h>
#include <GanttChartView.h>
#include <enums/Field.h>
#include <drawing/color.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(2856737393u, ::Aspose::Tasks::Examples::CPP::Articles::ReadCustomBarStyle, ThisTypeBaseTypesInfo);

void ReadCustomBarStyle::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:ReadCustomBarStyle
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CustomBarStyle.mpp");
    
    System::SharedPtr<GanttChartView> view = System::DynamicCast_noexcept<Aspose::Tasks::GanttChartView>(project->get_DefaultView());
    System::Console::WriteLine(u"Custom bar styles count: {0}", System::ObjectExt::Box<int32_t>(view->get_CustomBarStyles()->get_Count()));
    
    System::SharedPtr<GanttBarStyle> style1 = view->get_CustomBarStyles()->idx_get(0);
    
    System::Console::WriteLine(u"Style1.LeftField is TaskDurationText : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style1->get_LeftField(), Aspose::Tasks::Field::TaskDurationText)));
    System::Console::WriteLine(u"Style1.RightField is TaskResourceNames : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style1->get_RightField(), Aspose::Tasks::Field::TaskResourceNames)));
    System::Console::WriteLine(u"Style1.TopField is TaskACWP: {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style1->get_TopField(), Aspose::Tasks::Field::TaskACWP)));
    System::Console::WriteLine(u"Style1.BottomField is Undefined : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style1->get_BottomField(), Aspose::Tasks::Field::Undefined)));
    System::Console::WriteLine(u"Style1.InsideField is Undefined : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style1->get_InsideField(), Aspose::Tasks::Field::Undefined)));
    
    System::SharedPtr<GanttBarStyle> style2 = view->get_CustomBarStyles()->idx_get(1);
    System::Console::WriteLine(u"Style2.LeftField is TaskActualWork : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style2->get_LeftField(), Aspose::Tasks::Field::TaskActualWork)));
    System::Console::WriteLine(u"Style2.RightField is TaskActualCost : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style2->get_RightField(), Aspose::Tasks::Field::TaskActualCost)));
    System::Console::WriteLine(u"Style2.TopField is Undefined : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style2->get_TopField(), Aspose::Tasks::Field::Undefined)));
    System::Console::WriteLine(u"Style2.BottomField is Undefined : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style2->get_BottomField(), Aspose::Tasks::Field::Undefined)));
    System::Console::WriteLine(u"Style2.InsideField is Undefined : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style2->get_InsideField(), Aspose::Tasks::Field::Undefined)));
    
    System::SharedPtr<GanttBarStyle> style3 = view->get_CustomBarStyles()->idx_get(2);
    System::Console::WriteLine(u"Style3.LeftField is TaskPercentComplete : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_LeftField(), Aspose::Tasks::Field::TaskPercentComplete)));
    System::Console::WriteLine(u"Style3.RightField is TaskPercentWorkComplete : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_RightField(), Aspose::Tasks::Field::TaskPercentWorkComplete)));
    System::Console::WriteLine(u"Style3.TopField is Field.TaskActive : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_TopField(), Aspose::Tasks::Field::TaskActive)));
    System::Console::WriteLine(u"Style3.BottomField is TaskActualCost : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_BottomField(), Aspose::Tasks::Field::TaskActualCost)));
    System::Console::WriteLine(u"Style3.InsideField is Field.TaskActualDuration : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_InsideField(), Aspose::Tasks::Field::TaskActualDuration)));
    
    System::Console::WriteLine(u"Style3.StartShape is HouseDown : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_StartShape(), Aspose::Tasks::Visualization::GanttBarEndShape::HouseDown)));
    System::Console::WriteLine(u"Style3.StartShapeType is Framed : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_StartShapeType(), Aspose::Tasks::Visualization::GanttBarType::Framed)));
    System::Console::WriteLine(u"Style3.StartShapeColor is Red : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_StartShapeColor(), System::Drawing::Color::FromArgb(System::Drawing::Color::get_Red().ToArgb()))));
    
    System::Console::WriteLine(u"Style3.EndShape is CircleDiamond : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_EndShape(), Aspose::Tasks::Visualization::GanttBarEndShape::CircleDiamond)));
    System::Console::WriteLine(u"Style3.EndShapeType is Solid : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_EndShapeType(), Aspose::Tasks::Visualization::GanttBarType::Solid)));
    System::Console::WriteLine(u"Style3.EndShapeColor is Yellow : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_EndShapeColor(), System::Drawing::Color::FromArgb(System::Drawing::Color::get_Yellow().ToArgb()))));
    
    System::Console::WriteLine(u"Style3.MiddleShape is RectangleTop : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_MiddleShape(), Aspose::Tasks::Visualization::GanttBarMiddleShape::RectangleTop)));
    System::Console::WriteLine(u"Style3.MiddleFillPattern is SolidFill : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_MiddleFillPattern(), Aspose::Tasks::Visualization::GanttBarFillPattern::SolidFill)));
    System::Console::WriteLine(u"Style3.EndShapeColor is Red : {0}", System::ObjectExt::Box<bool>(System::ObjectExt::Equals(style3->get_MiddleShapeColor(), System::Drawing::Color::FromArgb(System::Drawing::Color::get_Red().ToArgb()))));
    // ExEnd:ReadCustomBarStyle
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
