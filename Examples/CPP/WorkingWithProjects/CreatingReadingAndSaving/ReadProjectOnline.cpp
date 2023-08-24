#include "WorkingWithProjects/CreatingReadingAndSaving/ReadProjectOnline.h"

#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/collections/list.h>
#include <system/enumerator_adapter.h>
#include <aspose.tasks.cpp/Project.h>
#include <aspose.tasks.cpp/IO/Pwa/ProjectServerCredentials.h>
#include <aspose.tasks.cpp/IO/Pwa/ProjectServerManager.h>
#include <aspose.tasks.cpp/IO/Pwa/ProjectInfo.h>

#include "RunExamples.h"

namespace Aspose {

    namespace Tasks {

        namespace Examples {

            namespace CPP {

                namespace WorkingWithProjects {

                    namespace CreatingReadingAndSaving {

                        RTTI_INFO_IMPL_HASH(2625776660u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::CreatingReadingAndSaving::ReadProjectOnline, ThisTypeBaseTypesInfo);

                        void ReadProjectOnline::Run()
                        {
                            // ExStart:ReadProjectOnline
                            System::String sharepointDomainAddress = u"https://contoso.sharepoint.com";
                            System::String userName = u"admin@contoso.onmicrosoft.com";
                            System::String password = u"MyPassword";

                            System::SharedPtr<ProjectServerCredentials> credentials = System::MakeObject<ProjectServerCredentials>(sharepointDomainAddress, userName, password);

                            System::SharedPtr<ProjectServerManager> manager = System::MakeObject<ProjectServerManager>(credentials);
                            System::SharedPtr<System::Collections::Generic::IEnumerable<System::SharedPtr<ProjectInfo>>> list = manager->GetProjectList();

                            for (const auto& p : System::IterateOver(list))
                            {
                                System::Console::WriteLine(u"Name : " + p->get_Name());
                                System::Console::WriteLine(u"CreatedDate : " + p->get_CreatedDate().ToString());
                                System::Console::WriteLine(u"Name : " + p->get_LastSavedDate().ToString());
                            
                            }
                            // ExEnd:ReadProjectOnline
                        }

                    } // namespace CreatingReadingAndSaving
                } // namespace WorkingWithProjects
            } // namespace CPP
        } // namespace Examples
    } // namespace Tasks
} // namespace Aspose
