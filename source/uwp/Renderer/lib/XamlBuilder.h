#pragma once

#include "AdaptiveCards.Uwp.h"
#include "ImageLoadTracker.h"
#include "IXamlBuilderListener.h"
#include "IImageLoadTrackerListener.h"
#include "AdaptiveCardRendererComponent.h"
#include <windows.storage.h>
#include "InputItem.h"
#include "RenderedAdaptiveCard.h"
#include "AdaptiveRenderContext.h"

namespace AdaptiveCards { namespace Uwp
{
    class AdaptiveCardRenderer;

    class XamlBuilder : public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        Microsoft::WRL::FtmBase,
        AdaptiveCards::Uwp::IImageLoadTrackerListener>
    {
        InspectableClass(L"AdaptiveCards.Uwp.XamlBuilder", BaseTrust)
    public:
        XamlBuilder();

        // IImageLoadTrackerListener
        STDMETHODIMP AllImagesLoaded();
        STDMETHODIMP ImagesLoadingHadError();

        void BuildXamlTreeFromAdaptiveCard(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCard* adaptiveCard,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** xamlTreeRoot,
            _In_ AdaptiveCards::Uwp::AdaptiveCardRenderer* renderer,
            _In_ AdaptiveCards::Uwp::AdaptiveRenderContext* renderContext,
            boolean isOuterCard = true,
            ABI::AdaptiveCards::Uwp::ContainerStyle defaultContainerStyle = ABI::AdaptiveCards::Uwp::ContainerStyle::Default);
        HRESULT AddListener(_In_ IXamlBuilderListener* listener) noexcept;
        HRESULT RemoveListener(_In_ IXamlBuilderListener* listener) noexcept;
        HRESULT SetFixedDimensions(_In_ UINT width, _In_ UINT height) noexcept;
        HRESULT SetEnableXamlImageHandling(_In_ bool enableXamlImageHandling) noexcept;

        void BuildImage(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** imageControl);

        static void BuildTextBlock(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** textBlockControl);
        static void BuildContainer(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** containerControl);
        static void BuildColumn(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** columnControl);
        static void BuildColumnSet(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** columnSetControl);
        static void BuildFactSet(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** factSetControl);
        static void BuildImageSet(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** imageSetControl);
        static void BuildChoiceSetInput(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** choiceSetInputControl);
        static void BuildDateInput(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** dateInputControl);
        static void BuildNumberInput(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** numberInputControl);
        static void BuildTextInput(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** textInputControl);
        static void BuildTimeInput(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** timeInputControl);
        static void BuildToggleInput(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** toggleInputControl);
        template<typename T>
        static HRESULT TryGetResourceFromResourceDictionaries(
            _In_ ABI::Windows::UI::Xaml::IResourceDictionary* resourceDictionary,
            _In_ std::wstring resourceName,
            _COM_Outptr_result_maybenull_ T** resource);

        static HRESULT SetStyleFromResourceDictionary(
            ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            std::wstring resourceName,
            ABI::Windows::UI::Xaml::IFrameworkElement* frameworkElement);

    private:
        ImageLoadTracker m_imageLoadTracker;
        std::set<Microsoft::WRL::ComPtr<IXamlBuilderListener>> m_listeners;
        Microsoft::WRL::ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamStatics> m_randomAccessStreamStatics;
        std::vector<Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, ABI::Windows::Web::Http::HttpProgress>>> m_getStreamOperations;
        std::vector<Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<UINT64, UINT64>>> m_copyStreamOperations;

        UINT m_fixedWidth = 0;
        UINT m_fixedHeight = 0;
        bool m_fixedDimensions = false;
        bool m_enableXamlImageHandling = false;
        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Uwp::IAdaptiveCardResourceResolvers> m_resourceResolvers;

        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IUIElement> CreateRootCardElement(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCard* adaptiveCard,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _COM_Outptr_ ABI::Windows::UI::Xaml::Controls::IPanel** childElementContainer);
        void ApplyBackgroundToRoot(
            _In_ ABI::Windows::UI::Xaml::Controls::IPanel* rootPanel,
            _In_ ABI::Windows::Foundation::IUriRuntimeClass* uri,
            _Inout_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs);
        template<typename T>
        void SetImageSource(T* destination, ABI::Windows::UI::Xaml::Media::IImageSource* imageSource);
        template<typename T>
        void SetImageOnUIElement(
            _In_ ABI::Windows::Foundation::IUriRuntimeClass* imageUrl,
            T* uiElement,
            ABI::AdaptiveCards::Uwp::IAdaptiveCardResourceResolvers* resolvers);
        template<typename T>
        void PopulateImageFromUrlAsync(_In_ ABI::Windows::Foundation::IUriRuntimeClass* imageUrl, T* imageControl);
        void FireAllImagesLoaded();
        void FireImagesLoadingHadError();
        void BuildShowCard(
            AdaptiveCards::Uwp::AdaptiveCardRenderer* renderer,
            ABI::AdaptiveCards::Uwp::IAdaptiveShowCardActionConfig* showCardActionConfig,
            ABI::AdaptiveCards::Uwp::IAdaptiveActionElement* action,
            _Inout_ AdaptiveCards::Uwp::AdaptiveRenderContext* renderContext,
            ABI::Windows::UI::Xaml::IUIElement** uiShowCard);
        void BuildActions(
            _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveCards::Uwp::IAdaptiveActionElement*>* children,
            _In_ AdaptiveCards::Uwp::AdaptiveCardRenderer* renderer,
            _In_ ABI::Windows::UI::Xaml::Controls::IPanel* parentPanel,
            _In_ bool insertSeparator,
            _Inout_ AdaptiveCards::Uwp::AdaptiveRenderContext* renderContext);

        static Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IUIElement> CreateSeparator(
            UINT spacing, UINT separatorThickness, ABI::Windows::UI::Color separatorColor, bool isHorizontal = true);
        static void ApplyMarginToXamlElement(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveHostConfig* hostConfig,
            _Inout_ ABI::Windows::UI::Xaml::IFrameworkElement* element);
        static Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> GetSolidColorBrush(_In_ ABI::Windows::UI::Color color);
        static void StyleXamlTextBlock(
            _In_ ABI::AdaptiveCards::Uwp::TextSize size,
            _In_ ABI::AdaptiveCards::Uwp::ForegroundColor color,
            ABI::AdaptiveCards::Uwp::ContainerStyle containerStyle,
            _In_ bool isSubtle,
            bool wrap,
            UINT32 maxWidth,
            _In_ ABI::AdaptiveCards::Uwp::TextWeight weight,
            _In_ ABI::Windows::UI::Xaml::Controls::ITextBlock* xamlTextBlock,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveHostConfig* hostConfig);
        static void StyleXamlTextBlock(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveTextConfig* textConfig,
            ABI::AdaptiveCards::Uwp::ContainerStyle containerStyle,
            _In_ ABI::Windows::UI::Xaml::Controls::ITextBlock* xamlTextBlock,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveHostConfig* hostConfig);
        static void BuildPanelChildren(
            _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveCards::Uwp::IAdaptiveCardElement*>* children,
            _In_ ABI::Windows::UI::Xaml::Controls::IPanel* parentPanel,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* context,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderArgs* renderArgs,
            _In_ std::function<void(ABI::Windows::UI::Xaml::IUIElement* child)> childCreatedCallback);
        static void GetSeparationConfigForElement(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* element,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveHostConfig* hostConfig,
            _Out_ UINT* spacing,
            _Out_ UINT* separatorThickness,
            _Out_ ABI::Windows::UI::Color* separatorColor,
            _Out_ bool* needsSeparator);
        static void BuildCompactChoiceSetInput(
            ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveChoiceSetInput* adaptiveChoiceSetInput,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** choiceInputSetControl);
        static void BuildExpandedChoiceSetInput(
            ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveChoiceSetInput* adaptiveChoiceInputSet,
            boolean isMultiSelect,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** choiceSetInputControl);
        static bool SupportsInteractivity(_In_ ABI::AdaptiveCards::Uwp::IAdaptiveHostConfig* hostConfig);

        static void WrapInFullWidthTouchTarget(
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveCardElement* adaptiveCardElement,
            _In_ ABI::Windows::UI::Xaml::IUIElement* elementToWrap,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveActionElement* action,
            _Inout_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext,
            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** finalElement);

        static void WireButtonClickToAction(
            _In_ ABI::Windows::UI::Xaml::Controls::IButton* button,
            _In_ ABI::AdaptiveCards::Uwp::IAdaptiveActionElement* action,
            _Inout_ ABI::AdaptiveCards::Uwp::IAdaptiveRenderContext* renderContext);

        static HRESULT AddHandledTappedEvent(_In_ ABI::Windows::UI::Xaml::IUIElement* uiElement);

        static HRESULT SetAutoImageSize(
            _In_ ABI::Windows::UI::Xaml::IFrameworkElement* imageControl,
            _In_ IInspectable* parentElement,
            _In_ ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource* imageSource);

    };
}}