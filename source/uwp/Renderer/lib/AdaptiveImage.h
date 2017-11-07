#pragma once

#include "AdaptiveCards.Uwp.h"
#include "Enums.h"
#include "Image.h"
#include <windows.foundation.h>

namespace AdaptiveCards { namespace Uwp
{
    class AdaptiveImage :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::Uwp::IAdaptiveImage,
            ABI::AdaptiveCards::Uwp::IAdaptiveCardElement>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Uwp_AdaptiveImage, BaseTrust)

    public:
        AdaptiveImage();
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::Image>& sharedImage);

        // IAdaptiveImage
        IFACEMETHODIMP get_Url(_Out_ ABI::Windows::Foundation::IUriRuntimeClass** url);
        IFACEMETHODIMP put_Url(_In_ ABI::Windows::Foundation::IUriRuntimeClass* url);

        IFACEMETHODIMP get_Style(_Out_ ABI::AdaptiveCards::Uwp::ImageStyle* imageStyle);
        IFACEMETHODIMP put_Style(_In_ ABI::AdaptiveCards::Uwp::ImageStyle imageStyle);

        IFACEMETHODIMP get_Size(_Out_ ABI::AdaptiveCards::Uwp::ImageSize* imageSize);
        IFACEMETHODIMP put_Size(_In_ ABI::AdaptiveCards::Uwp::ImageSize imageSize);

        IFACEMETHODIMP get_AltText(_Out_ HSTRING *text);
        IFACEMETHODIMP put_AltText(_In_ HSTRING text);

        IFACEMETHODIMP get_HorizontalAlignment(_Out_ ABI::AdaptiveCards::Uwp::HAlignment* hAlignment);
        IFACEMETHODIMP put_HorizontalAlignment(_In_ ABI::AdaptiveCards::Uwp::HAlignment hAlignment);

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveCards::Uwp::ElementType* elementType);

        IFACEMETHODIMP get_Spacing(_Out_ ABI::AdaptiveCards::Uwp::Spacing* spacing);
        IFACEMETHODIMP put_Spacing(_In_ ABI::AdaptiveCards::Uwp::Spacing spacing);

        IFACEMETHODIMP get_Separator(_Out_ boolean* separator);
        IFACEMETHODIMP put_Separator(_In_ boolean separator);

        IFACEMETHODIMP get_Id(_Out_ HSTRING* id);
        IFACEMETHODIMP put_Id(_In_ HSTRING id);

        IFACEMETHODIMP get_ElementTypeString(_Out_ HSTRING* value);

        IFACEMETHODIMP ToJson(_Out_ ABI::Windows::Data::Json::IJsonObject** result);

    private:
        std::shared_ptr<AdaptiveCards::Image> m_sharedImage;
    };

    ActivatableClass(AdaptiveImage);
}}