/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ReadWriteRateScaleForResourceAssignment.h"

#include <TaskCollection.h>
#include <Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/console.h>
#include <saving/Enums/SaveFileFormat.h>
#include <Rsc.h>
#include <ResourceCollection.h>
#include <ResourceAssignmentCollection.h>
#include <ResourceAssignment.h>
#include <Resource.h>
#include <Project.h>
#include <Key.h>
#include <enums/RscKey.h>
#include <enums/ResourceType.h>
#include <enums/RateScaleType.h>
#include <enums/AsnKey.h>
#include <cstdint>
#include <Asn.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResourceAssignments {

RTTI_INFO_IMPL_HASH(163083219u, ::Aspose::Tasks::Examples::CPP::WorkingWithResourceAssignments::ReadWriteRateScaleForResourceAssignment, ThisTypeBaseTypesInfo);

void ReadWriteRateScaleForResourceAssignment::Run()
{
try
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    //ExStart: ReadWriteRateScaleForResourceAssignment
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"New project 2013.mpp");
    
    auto task = project->get_RootTask()->get_Children()->Add(u"t1");
    
    auto materialResource = project->get_Resources()->Add(u"materialResource");
    materialResource->Set<ResourceType>(Rsc::Type(), Aspose::Tasks::ResourceType::Material);
    
    auto nonMaterialResource = project->get_Resources()->Add(u"nonMaterialResource");
    nonMaterialResource->Set<ResourceType>(Rsc::Type(), Aspose::Tasks::ResourceType::Work);
    
    auto materialResourceAssignment = project->get_ResourceAssignments()->Add(task, materialResource);
    materialResourceAssignment->Set<RateScaleType>(Asn::RateScale(), Aspose::Tasks::RateScaleType::Week);
    materialResourceAssignment->Set<int32_t>(Asn::Uid(), 1);
    
    auto nonMaterialResourceAssignment = project->get_ResourceAssignments()->Add(task, nonMaterialResource);
    nonMaterialResourceAssignment->Set<RateScaleType>(Asn::RateScale(), Aspose::Tasks::RateScaleType::Week);
    nonMaterialResourceAssignment->Set<int32_t>(Asn::Uid(), 2);
    
    project->Save(dataDir + u"output_out.mpp", Aspose::Tasks::Saving::SaveFileFormat::Mpp);
    
    auto resavedProject = System::MakeObject<Project>(dataDir + u"output_out.mpp");
    
    auto resavedMaterialResourceAssignment = resavedProject->get_ResourceAssignments()->GetByUid(1);
    System::Console::WriteLine(System::ObjectExt::Box<RateScaleType>(resavedMaterialResourceAssignment->Get<RateScaleType>(Asn::RateScale())));
    
    // only material resource assignments can have non-zero rate scale value.
    auto resavedNonMaterialResourceAssignment = resavedProject->get_ResourceAssignments()->GetByUid(2);
    //ExEnd: ReadWriteRateScaleForResourceAssignment
}
catch (System::NotSupportedException& ex)
{
    System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
}
}

} // namespace WorkingWithResourceAssignments
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
