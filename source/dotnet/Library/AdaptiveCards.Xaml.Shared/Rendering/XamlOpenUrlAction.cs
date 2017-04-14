﻿using System.Windows;
using AdaptiveCards.Rendering;
#if WPF
using System.Windows.Controls;
#elif XAMARIN
using Xamarin.Forms;
using Button = AdaptiveCards.Rendering.ContentButton;
#endif

namespace AdaptiveCards.Rendering
{

    public static class XamlOpenUrlAction
    {
        public static FrameworkElement Render(TypedElement element, RenderContext context)
        {
            OpenUrlAction action = (OpenUrlAction)element;
            if (context.Options.AdaptiveCard.SupportsInteractivity)
            {
                Button uiButton = XamlUtilities.CreateActionButton(action, context); // content);
                uiButton.Click += (sender, e) =>
                {
                    context.Action(uiButton, new ActionEventArgs() { Action = action});
                };
                return uiButton;
            }
            return null;
        }
    }
}