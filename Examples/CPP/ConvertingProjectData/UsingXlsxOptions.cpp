/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/UsingXlsxOptions.h"

#include <aspose.tasks.cpp/visualization/View/ViewColumn.h>
#include <aspose.tasks.cpp/visualization/View/ResourceViewColumn.h>
#include <aspose.tasks.cpp/visualization/View/ProjectView.h>
#include <aspose.tasks.cpp/visualization/View/GanttChartColumn.h>
#include <aspose.tasks.cpp/visualization/View/AssignmentViewColumn.h>
#include <aspose.tasks.cpp/Tsk.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <aspose.tasks.cpp/saving/Excel/OpenXML/XlsxOptions.h>
#include <aspose.tasks.cpp/Rsc.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/TaskKey.h>
#include <aspose.tasks.cpp/enums/RscKey.h>
#include <aspose.tasks.cpp/enums/AsnKey.h>
#include <aspose.tasks.cpp/Asn.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
using namespace Aspose::Tasks::Visualization;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(654405702u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::UsingXlsxOptions, ThisTypeBaseTypesInfo);

System::String UsingXlsxOptions::_anonymous_method_0(System::SharedPtr<Task> task)
{
    return task->Get(Tsk::WBS());
}

System::String UsingXlsxOptions::_anonymous_method_1(System::SharedPtr<Resource> resource)
{
    return resource->Get<System::String>(Rsc::CostCenter());
}

System::String UsingXlsxOptions::_anonymous_method_2(System::SharedPtr<ResourceAssignment> assignment)
{
    return assignment->Get<System::String>(Asn::Notes());
}

void UsingXlsxOptions::Run()
{
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:UsingXlsxOptions
    // Read the input Project file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"CreateProject2.mpp");
    
    System::SharedPtr<XlsxOptions> options = System::MakeObject<XlsxOptions>();
    
    // Add desired Gantt Chart columns
    System::SharedPtr<GanttChartColumn> col = System::MakeObject<GanttChartColumn>(u"WBS", 100, &UsingXlsxOptions::_anonymous_method_0);
    options->get_View()->get_Columns()->Add(col);
    
    // Add desired resource view columns
    System::SharedPtr<ResourceViewColumn> rscCol = System::MakeObject<ResourceViewColumn>(u"Cost center", 100, &UsingXlsxOptions::_anonymous_method_1);
    options->get_ResourceView()->get_Columns()->Add(rscCol);
    
    // Add desired assignment view columns
    System::SharedPtr<AssignmentViewColumn> assnCol = System::MakeObject<AssignmentViewColumn>(u"Notes", 200, &UsingXlsxOptions::_anonymous_method_2);
    options->get_AssignmentView()->get_Columns()->Add(assnCol);
    
    project->Save(dataDir + u"UsingXlsxOptions_out.xlsx", options);
    // ExEnd:UsingXlsxOptions
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
