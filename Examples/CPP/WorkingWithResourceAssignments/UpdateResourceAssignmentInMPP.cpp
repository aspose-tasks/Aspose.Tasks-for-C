/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "UpdateResourceAssignmentInMPP.h"

#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/ResourceCollection.h>
#include <aspose.tasks.cpp/ResourceAssignmentCollection.h>
#include <aspose.tasks.cpp/ResourceAssignment.h>
#include <aspose.tasks.cpp/Resource.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/Key.h>
#include <aspose.tasks.cpp/enums/AsnKey.h>
#include <aspose.tasks.cpp/Asn.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(3803439060u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::UpdateResourceAssignmentInMPP, ThisTypeBaseTypesInfo);

void UpdateResourceAssignmentInMPP::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:UpdateResourceAssignmentInMPP
        // Create project instance and access first task and resource
        System::SharedPtr<Project> project1 = System::MakeObject<Project>(dataDir + u"UpdateResourceAssignment.mpp");
        System::SharedPtr<Task> task = project1->get_RootTask()->get_Children()->GetById(1);
        System::SharedPtr<Resource> rsc = project1->get_Resources()->GetById(1);
        
        // Create resource assignment
        System::SharedPtr<ResourceAssignment> assn = project1->get_ResourceAssignments()->Add(task, rsc);
        assn->Set<System::String>(Asn::Notes(), u"Newly added assignment");
        
        // Save project as MPP
        project1->Save(dataDir + u"UpdateResourceAssignment_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
        // ExEnd:UpdateResourceAssignmentInMPP
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
