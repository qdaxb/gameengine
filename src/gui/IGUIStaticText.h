#pragma once

#include "IGUITextElement.h"

namespace mycGet
{
    namespace gui
    {
        class IGUIFont;

        //! Multi or single line text label.
        class IGUIStaticText : public IGUITextElement
        {
        public:

            //! constructor
            IGUIStaticText( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcStaticText )
                : IGUIElement( EGUIET_STATIC_TEXT, pEnvironment, pParent, nID, rcStaticText ) {}

            //! Sets another skin independent font.
            /** If this is Set to zero, the button uses the font of the skin.
            \param font: New font to Set. */
            virtual void SetOverrideFont( IGUIFont* pFont = NULL ) = 0;

            //! Getts the override font (if any)
            /** \return The override font (may be 0) */
            virtual IGUIFont* GettOverrideFont() const = 0;

            //! Sets another color for the text.
            /** If Set, the static text does not use the EGDC_BUTTON_TEXT color defined
            in the skin, but the Set color instead. You don't need to call
            IGUIStaticText::enableOverrrideColor(true) after this, this is done
            by this function.
            If you Set a color, and you want the text displayed with the color
            of the skin again, call IGUIStaticText::enableOverrideColor(false);
            \param color: New color of the text. */
            //virtual void SetOverrideColor(video::SColor color) = 0;

            //! Getts the override color
            /** \return: The override color */
            //virtual video::SColor const& GettOverrideColor(void) const = 0;

            //! Sets if the static text should use the overide color or the color in the gui skin.
            /** \param enable: If Set to true, the override color, which can be Set
            with IGUIStaticText::SetOverrideColor is used, otherwise the
            EGDC_BUTTON_TEXT color of the skin. */
            virtual void EnableOverrideColor( bool bEnable ) = 0;

            //! Checks if an override color is enabled
            /** \return true if the override color is enabled, false otherwise */
            virtual bool IsOverrideColorEnabled() const = 0;

            //! Sets another color for the background.
            //virtual void SetBackgroundColor(video::SColor color) = 0;

            //! Sets whether to draw the background
            virtual void SetDrawBackground( bool bDraw ) = 0;

            //! Sets whether to draw the border
            virtual void SetDrawBorder( bool bDraw ) = 0;

            //! Sets text justification mode
            /** \param horizontal: EGUIA_UPPERLEFT for left justified (default),
            EGUIA_LOWEERRIGHT for right justified, or EGUIA_CENTER for centered text.
            \param vertical: EGUIA_UPPERLEFT to align with top edGet,
            EGUIA_LOWEERRIGHT for bottom edGet, or EGUIA_CENTER for centered text (default). */
            virtual void SetTextAlignment( EGUI_ALIGNMENT eHorizontal, EGUI_ALIGNMENT eVertical ) = 0;

            //! Enables or disables word wrap for using the static text as multiline text control.
            /** \param enable: If Set to true, words going over one line are
            broken on to the next line. */
            virtual void SetWordWrap( bool bEnable ) = 0;

            //! Checks if word wrap is enabled
            /** \return true if word wrap is enabled, false otherwise */
            virtual bool IsWordWrapEnabled() const = 0;

            //! Returns the height of the text in pixels when it is drawn.
            /** This is useful for adjusting the layout of gui elements based on the height
            of the multiline text in this element.
            \return Height of text in pixels. */
            virtual int GettTextHeight() const = 0;

            //! Returns the width of the current text, in the current font
            /** If the text is broken, this returns the width of the widest line
            \return The width of the text, or the widest broken line. */
            virtual int GettTextWidth() const = 0;
        };
    }
}