#include "WorkingWithProjects/WorkingWithProjectProperties/ReadMetaProperties.h"

#include <system/enumerator_adapter.h>
#include <system/type_info.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/reflection/method_base.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/console.h>
#include <Project.h>
#include <Prj.h>
#include <NullableBool.h>
#include <Key.h>
#include <enums/PrjKey.h>
#include <cstdint>
#include <PropertyCollections/BuiltInProjectPropertyCollection.h>
#include <PropertyCollections/BuiltInProjectProperty.h>
#include <PropertyCollections/CustomProjectPropertyCollection.h>
#include <PropertyCollections/CustomProjectProperty.h>

#include "RunExamples.h"

namespace Aspose {

    namespace Tasks {

        namespace Examples {

            namespace CPP {

                namespace WorkingWithProjects {

                    namespace WorkingWithProjectProperties {

                        RTTI_INFO_IMPL_HASH(634675322u, ::Aspose::Tasks::Examples::CPP::WorkingWithProjects::WorkingWithProjectProperties::ReadMetaProperties, ThisTypeBaseTypesInfo);

                        void ReadMetaProperties::Run()
                        {
                            // ExStart:ReadMetaProperties
                            // The path to the documents directory.
                            System::String dataDir = RunExamples::GetDataDir(System::Reflection::MethodBase::GetCurrentMethod(ASPOSE_CURRENT_FUNCTION)->get_DeclaringType().get_FullName());

                            // Create a project reader instance
                            System::SharedPtr<Project> project = System::MakeObject<Project>(dataDir + u"ReadProjectInfo.mpp");

                            // Built-in properties are available directly:
                            System::Console::WriteLine(u"Author: " +  project->get_BuiltInProps()->get_Author());
                            System::Console::WriteLine(u"Category: " + project->get_BuiltInProps()->get_Category());
                            System::Console::WriteLine(u"Comments: " + project->get_BuiltInProps()->get_Comments());
                            System::Console::WriteLine(u"Company: " + project->get_BuiltInProps()->get_Company());
                            System::Console::WriteLine(u"HyperlinkBase: " + project->get_BuiltInProps()->get_HyperlinkBase());
                            System::Console::WriteLine(u"IsReadOnly: " + project->get_BuiltInProps()->get_IsReadOnly());
                            System::Console::WriteLine(u"Keywords: " + project->get_BuiltInProps()->get_Keywords());
                            System::Console::WriteLine(u"Manager: " + project->get_BuiltInProps()->get_Manager());
                            System::Console::WriteLine(u"Subject: " + project->get_BuiltInProps()->get_Subject());
                            System::Console::WriteLine(u"Title: " + project->get_BuiltInProps()->get_Title());
                            // ExEnd:ReadMetaProperties
                        }

                    } // namespace WorkingWithProjectProperties
                } // namespace WorkingWithProjects
            } // namespace CPP
        } // namespace Examples
    } // namespace Tasks
} // namespace Aspose
