#include "AddWBSCodes.h"

#include <aspose.tasks.cpp/WbsCodeMaskCollection.h>
#include <aspose.tasks.cpp/WBSCodeMask.h>
#include <aspose.tasks.cpp/WBSCodeDefinition.h>
#include <aspose.tasks.cpp/TaskCollection.h>
#include <aspose.tasks.cpp/Task.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <aspose.tasks.cpp/saving/Enums/SaveFileFormat.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/enums/WBSSequence.h>
#include <cstdint>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithTasks {

RTTI_INFO_IMPL_HASH(5309529u, ::Aspose::Tasks::Examples::CPP::WorkingWithTasks::AddWBSCodes, ThisTypeBaseTypesInfo);

void AddWBSCodes::Run()
{
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // ExStart:AddWBSCodes
    System::SharedPtr<Project> proj = System::MakeObject<Project>();
    
    proj->set_WBSCodeDefinition(System::MakeObject<WBSCodeDefinition>());
    proj->get_WBSCodeDefinition()->set_GenerateWBSCode(true);
    proj->get_WBSCodeDefinition()->set_VerifyUniqueness(true);
    proj->get_WBSCodeDefinition()->set_CodePrefix(u"CRS-");
    
    System::SharedPtr<WBSCodeMask> mask = System::MakeObject<WBSCodeMask>();
    mask->set_Length(2);
    mask->set_Separator(u"-");
    mask->set_Sequence(Aspose::Tasks::WBSSequence::OrderedNumbers);
    proj->get_WBSCodeDefinition()->get_CodeMaskCollection()->Add(mask);
    
    mask = System::MakeObject<WBSCodeMask>();
    mask->set_Length(1);
    mask->set_Separator(u"-");
    mask->set_Sequence(Aspose::Tasks::WBSSequence::OrderedUppercaseLetters);
    proj->get_WBSCodeDefinition()->get_CodeMaskCollection()->Add(mask);
    
    System::SharedPtr<Task> tsk = proj->get_RootTask()->get_Children()->Add(u"Task 1");
    System::SharedPtr<Task> child = tsk->get_Children()->Add(u"Task 2");
    
    proj->Recalculate();
    proj->Save(dataDir + u"AddWBSCodes_out.xml", Aspose::Tasks::Saving::SaveFileFormat::Xml);
    // ExEnd:AddWBSCodes
}

} // namespace WorkingWithTasks
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
