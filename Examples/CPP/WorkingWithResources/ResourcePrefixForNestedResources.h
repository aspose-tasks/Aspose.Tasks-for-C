#pragma once

#include <system/string.h>
#include <system/shared_ptr.h>
#include <saving/Html/IImageSavingCallback.h>
#include <saving/Html/IFontSavingCallback.h>
#include <saving/Html/ICssSavingCallback.h>
#include <cstdint>

namespace Aspose { namespace Tasks { class CssSavingArgs; } }
namespace Aspose { namespace Tasks { class FontSavingArgs; } }
namespace Aspose { namespace Tasks { class ImageSavingArgs; } }
namespace Aspose { namespace Tasks { namespace Saving { class HtmlSaveOptions; } } }

namespace Aspose {

namespace Tasks {

namespace Examples {

namespace CPP {

namespace WorkingWithResources {

// ExStart:ResourcePrefixForNestedResources
class ResourcePrefixForNestedResources : public Aspose::Tasks::ICssSavingCallback, public Aspose::Tasks::IFontSavingCallback, public Aspose::Tasks::IImageSavingCallback
{
    typedef ResourcePrefixForNestedResources ThisType;
    typedef Aspose::Tasks::ICssSavingCallback BaseType;
    typedef Aspose::Tasks::IFontSavingCallback BaseType1;
    typedef Aspose::Tasks::IImageSavingCallback BaseType2;
    
    typedef ::System::BaseTypesInfo<BaseType, BaseType1, BaseType2> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    static System::String dataDir();
    static void Run();
    void CssSaving(System::SharedPtr<CssSavingArgs> args) override;
    void FontSaving(System::SharedPtr<FontSavingArgs> args) override;
    void ImageSaving(System::SharedPtr<ImageSavingArgs> args) override;
    
private:

    static System::SharedPtr<Aspose::Tasks::Saving::HtmlSaveOptions> GetSaveOptions(int32_t pageNumber);
    
};

// ExEnd:ResourcePrefixForNestedResources
} // namespace WorkingWithResources
} // namespace CPP
} // namespace Examples
} // namespace Tasks
} // namespace Aspose


