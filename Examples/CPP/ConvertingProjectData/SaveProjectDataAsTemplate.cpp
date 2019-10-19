/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Tasks for .NET API reference 
when the project is build. Please check https:// Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Tasks for .NET API from https://www.nuget.org/packages/Aspose.Tasks/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/tasks
*/
#include "ConvertingProjectData/SaveProjectDataAsTemplate.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <saving/SaveTemplateOptions.h>
#include <ProjectFileInfo.h>
#include <Project.h>
#include <enums/FileFormat.h>

#include "RunExamples.h"


using namespace Aspose::Tasks::Saving;
namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace ConvertingProjectData {

RTTI_INFO_IMPL_HASH(854131789u, ::Aspose::Tasks::Examples::CPP::ConvertingProjectData::SaveProjectDataAsTemplate, ThisTypeBaseTypesInfo);

void SaveProjectDataAsTemplate::Run()
{
    try
    {
        // The path to the documents directory.
        System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());
        
        // ExStart:SaveProjectDataAsTemplate   
        const System::String projectName = u"Project2.mpp";
        System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + projectName);
        System::SharedPtr<ProjectFileInfo> projectFileInfo = Project::GetProjectFileInfo(dataDir + projectName);
        
        if (Aspose::Tasks::FileFormat::MPP14 == projectFileInfo->get_ProjectFileFormat())
        {
            System::Console::WriteLine(u"Project file format is ok");
        }
        
        System::SharedPtr<SaveTemplateOptions> options = System::MakeObject<SaveTemplateOptions>();
        options->set_RemoveActualValues(true);
        options->set_RemoveBaselineValues(true);
        
        const System::String templateName = u"SaveProjectDataAsTemplate_out.mpt";
        project->SaveAsTemplate(dataDir + templateName);
        
        System::SharedPtr<ProjectFileInfo> templateFileInfo = Project::GetProjectFileInfo(dataDir + templateName);
        if (Aspose::Tasks::FileFormat::MPT14 == templateFileInfo->get_ProjectFileFormat())
        {
            System::Console::WriteLine(u"Template FileFormat is ok");
        }
        // ExEnd:SaveProjectDataAsTemplate
    }
    catch (System::NotSupportedException& ex)
    {
        System::Console::WriteLine(ex->get_Message() + u"\nThis example will only work if you apply a valid Aspose License. You can purchase full license or get 30 day temporary license from http://www.aspose.com/purchase/default.aspx.");
    }
    
}

} // namespace ConvertingProjectData
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose
