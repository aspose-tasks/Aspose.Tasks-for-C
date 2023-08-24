#include "CustomizeTextWithTaskBars.h"

#include <aspose.tasks.cpp/visualization/View/Styles/BarStyle.h>
#include <aspose.tasks.cpp/visualization/Enums/Timescale.h>
#include <aspose.tasks.cpp/visualization/Enums/BarItemType.h>
#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/TaskLinkCollection.h>
#include <aspose.tasks.cpp/TaskLink.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/SaveOptions.h>
#include <aspose.tasks.cpp/saving/Pdf/PdfSaveOptions.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/ResourceAssignmentCollection.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TimeUnitType.h>
#include <aspose.tasks.cpp/enums/TaskLinkType.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/Duration.h>
#include <drawing/color.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace Articles {

RTTI_INFO_IMPL_HASH(776557103u, ::Aspose::Tasks::Examples::CPP::Articles::CustomizeTextWithTaskBars, ThisTypeBaseTypesInfo);

System::String CustomizeTextWithTaskBars::_anonymous_method_0(System::SharedPtr<Task> t)
{
    return System::String::Format(u"This task is on critical path");
}

void CustomizeTextWithTaskBars::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:CustomizeTextWithTaskBars
    System::SharedPtr<Project> project = System::MakeObject<Project>();
    
    System::SharedPtr<Task> task1 = project->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> task2 = project->get_RootTask()->get_Children()->Add(u"Task 2");
    
    task1->Set<Duration>(Tsk::Duration(), project->GetDuration(1, Aspose::Tasks::TimeUnitType::Day));
    task2->Set<Duration>(Tsk::Duration(), project->GetDuration(1, Aspose::Tasks::TimeUnitType::Day));
    
    System::SharedPtr<TaskLink> link = project->get_TaskLinks()->Add(task1, task2, Aspose::Tasks::TaskLinkType::FinishToStart);
    
    System::SharedPtr<Task> task3 = project->get_RootTask()->get_Children()->Add(u"Task 3");
    System::SharedPtr<Resource> rsc1 = project->get_Resources()->Add(u"Resource 1");
    System::SharedPtr<Resource> rsc2 = project->get_Resources()->Add(u"Resource 2");
    System::SharedPtr<Resource> rsc3 = project->get_Resources()->Add(u"Resource 3");
    
    System::SharedPtr<ResourceAssignment> assn1 = project->get_ResourceAssignments()->Add(task1, rsc1);
    System::SharedPtr<ResourceAssignment> assn2 = project->get_ResourceAssignments()->Add(task2, rsc2);
    System::SharedPtr<ResourceAssignment> assn3 = project->get_ResourceAssignments()->Add(task3, rsc3);
    
    System::SharedPtr<SaveOptions> options = System::MakeObject<PdfSaveOptions>();
    options->set_Timescale(Aspose::Tasks::Visualization::Timescale::ThirdsOfMonths);
    
    System::SharedPtr<BarStyle> style = System::MakeObject<BarStyle>();
    style->set_ItemType(Aspose::Tasks::Visualization::BarItemType::CriticalTask);
    
    style->set_InsideBarTextConverter(&CustomizeTextWithTaskBars::_anonymous_method_0);
    
    System::SharedPtr<BarStyle> style2 = System::MakeObject<BarStyle>();
    style2->set_BarColor(System::Drawing::Color::get_DarkOrchid());
    style2->set_ItemType(Aspose::Tasks::Visualization::BarItemType::Task);
    
    options->set_BarStyles(System::MakeObject<System::Collections::Generic::List<System::SharedPtr<BarStyle>>>());
    options->get_BarStyles()->Add(style);
    options->get_BarStyles()->Add(style2);
    
    project->Save(dataDir + u"result2_out.pdf", options);
    // ExEnd:CustomizeTextWithTaskBars
}

} // namespace Articles
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
