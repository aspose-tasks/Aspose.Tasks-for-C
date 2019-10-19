#include "WorkingWithProjects/CreatingReadingAndSaving/ReadProjectFiles.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <Project.h>

#include "RunExamples.h"

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithProjects {

namespace CreatingReadingAndSaving {

RTTI_INFO_IMPL_HASH(2625776660u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving::ReadProjectFiles, ThisTypeBaseTypesInfo);

void ReadProjectFiles::Run()
{
    // ExStart:ReadProjectFiles
    // The path to the documents directory.
    System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
    
    // Read existing project template file
    System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadProjectFiles.mpp");
    // ExEnd:ReadProjectFiles
}

} // namespace CreatingReadingAndSaving
} // namespace WorkingWithProjects
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
