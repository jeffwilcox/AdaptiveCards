﻿using Newtonsoft.Json;


namespace AdaptiveCards
{
    /// <summary>
    ///     The Image element allows for the inclusion of images in an Adaptive Card.
    /// </summary>
    public class AdaptiveImage : AdaptiveElement
    {
        public const string TypeName = "Image";

        public AdaptiveImage()
        {
            Type = TypeName;
        }

        /// <summary>
        ///     Size for the Image
        /// </summary>
        [JsonProperty(DefaultValueHandling = DefaultValueHandling.Ignore)]
        public AdaptiveImageSize Size { get; set; }

        /// <summary>
        ///     The style in which the image is displayed.
        /// </summary>
        [JsonProperty(DefaultValueHandling = DefaultValueHandling.Ignore)]
        public AdaptiveImageStyle Style { get; set; }

        /// <summary>
        ///     A url pointing to an image to display
        /// </summary>
        [JsonRequired]
        public string Url { get; set; }

        /// <summary>
        ///     Horizontal alignment for element
        /// </summary>
        [JsonProperty(DefaultValueHandling = DefaultValueHandling.Ignore)]
        public AdaptiveHorizontalAlignment HorizontalAlignment { get; set; }

        /// <summary>
        ///     Action for this image (this allows a default action to happen when a click on an image happens)
        /// </summary>
        [JsonProperty(DefaultValueHandling = DefaultValueHandling.Ignore)]
        public AdaptiveActionBase SelectAction { get; set; }

        /// <summary>
        ///     Alternate text to display for this image
        /// </summary>
        [JsonProperty(DefaultValueHandling = DefaultValueHandling.Ignore)]
        public string AltText { get; set; }
    }
}