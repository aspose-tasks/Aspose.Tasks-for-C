#include "WorkingWithProjects/CreatingReadingAndSaving/CreateProjectOnline.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <system/enumerator_adapter.h>
#include <Project.h>
#include <IO/Pwa/ProjectServerCredentials.h>
#include <IO/Pwa/ProjectServerManager.h>
#include <IO/Pwa/ProjectInfo.h>

#include "RunExamples.h"

namespace Aspose {

    namespace Tasks {

        namespace Examples {

            namespace CPP {

                namespace WorkingWithProjects {

                    namespace CreatingReadingAndSaving {

                        RTTI_INFO_IMPL_HASH(2625776660u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving::CreateProjectOnline, ThisTypeBaseTypesInfo);

                        void CreateProjectOnline::Run()
                        {
                            // ExStart:CreateProjectOnline
                            System::String sharepointDomainAddress = u"https://contoso.sharepoint.com";
                            System::String userName = u"admin@contoso.onmicrosoft.com";
                            System::String password = u"MyPassword";

                            System::SharedPtr<ProjectServerCredentials> credentials = System::MakeObject<ProjectServerCredentials>(sharepointDomainAddress, userName, password);

                            System::SharedPtr<Project> project = System::MakeObject<Project>(u"sample.mpp");

                            System::SharedPtr<ProjectServerManager> manager = System::MakeObject<ProjectServerManager>(credentials);
                            manager->CreateNewProject(project);
                            // ExEnd:CreateProjectOnline
                        }

                    } // namespace CreatingReadingAndSaving
                } // namespace WorkingWithProjects
            } // namespace CPP
        } // namespace Examples
    } // namespace Tasks
} // namespace Aspose
