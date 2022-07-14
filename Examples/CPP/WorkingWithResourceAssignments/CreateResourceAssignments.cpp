/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "CreateResourceAssignments.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <saving/Enums/SaveFileFormat.h>
#include <ResourceCollection.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(4041295628u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::CreateResourceAssignments, ThisTypeBaseTypesInfo);

void CreateResourceAssignments::Run()
{
    // ExStart:CreateResourceAssignments
    // Create empty project
    System::SharedPtr<Project> project1 = System::MakeObject<Project>();
    
    // Add new task and resource
    System::SharedPtr<Task> task1 = project1->get_RootTask()->get_Children()->Add(u"Task");
    System::SharedPtr<Resource> rsc1 = project1->get_Resources()->Add(u"Rsc");
    
    // Assign the resource desired task
    System::SharedPtr<ResourceAssignment> assn = project1->get_ResourceAssignments()->Add(task1, rsc1);
    // ExEnd:CreateResourceAssignments
    
    // Save project as PDF
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    project1->Save(dataDir + u"CreateResourceAssignments_out.pdf", Aspose::Tasks::Saving::SaveFileFormat::Pdf);
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
