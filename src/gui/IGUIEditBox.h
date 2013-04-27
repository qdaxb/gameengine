#pragma once

#include "IGUITextElement.h"

namespace mycge
{
    namespace gui
    {
        class IGUIFont;

        //! Single line edit box for editing simple text.
        class IGUIEditBox : public IGUITextElement
        {
        public:

            //! constructor
            IGUIEditBox( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcEditBox )
                : IGUIElement( EGUIET_EDIT_BOX, pEnvironment, pParent, nID, rcEditBox ) {}

            //! Sets another skin independent font.
            /** If this is set to zero, the button uses the font of the skin.
            \param font: New font to set. */
            virtual void SetOverrideFont( IGUIFont* font = NULL ) = 0;

            //! Sets another color for the text.
            /** If set, the edit box does not use the EGDC_BUTTON_TEXT color defined
            in the skin, but the set color instead. You don't need to call
            IGUIEditBox::enableOverrrideColor(true) after this, this is done
            by this function.
            If you set a color, and you want the text displayed with the color
            of the skin again, call IGUIEditBox::enableOverrideColor(false);
            \param color: New color of the text. */
            //virtual void setOverrideColor( video::SColor color ) = 0;

            //! Sets if the text should use the override color or the color in the gui skin.
            /** \param enable: If set to true, the override color, which can be set
            with IGUIEditBox::setOverrideColor is used, otherwise the
            EGDC_BUTTON_TEXT color of the skin. */
            virtual void EnableOverrideColor( bool bEnable ) = 0;

            //! Turns the border on or off
            /** \param border: true if you want the border to be drawn, false if not */
            virtual void SetDrawBorder( bool bBorder ) = 0;

            //! Sets text justification mode
            /** \param horizontal: EGUIA_UPPERLEFT for left justified (default),
            EGUIA_LOWEERRIGHT for right justified, or EGUIA_CENTER for centered text.
            \param vertical: EGUIA_UPPERLEFT to align with top edge,
            EGUIA_LOWEERRIGHT for bottom edge, or EGUIA_CENTER for centered text (default). */
            virtual void SetTextAlignment( EGUI_ALIGNMENT eHorizontal, EGUI_ALIGNMENT eVertical ) = 0;

            //! Enables or disables word wrap.
            /** \param enable: If set to true, words going over one line are
            broken to the next line. */
            virtual void SetWordWrap( bool bEnable ) = 0;

            //! Checks if word wrap is enabled
            /** \return true if word wrap is enabled, false otherwise */
            virtual bool IsWordWrapEnabled() const = 0;

            //! Enables or disables newlines.
            /** \param enable: If set to true, the EGET_EDITBOX_ENTER event will not be fired,
            instead a newline character will be inserted. */
            virtual void SetMultiLine( bool bEnable ) = 0;

            //! Checks if multi line editing is enabled
            /** \return true if multi-line is enabled, false otherwise */
            virtual bool IsMultiLineEnabled() const = 0;

            //! Enables or disables automatic scrolling with cursor position
            /** \param enable: If set to true, the text will move around with the cursor position */
            virtual void SetAutoScroll( bool bEnable ) = 0;

            //! Checks to see if automatic scrolling is enabled
            /** \return true if automatic scrolling is enabled, false if not */
            virtual bool IsAutoScrollEnabled() const = 0;

            //! Sets whether the edit box is a password box. Setting this to true will
            /** disable MultiLine, WordWrap and the ability to copy with ctrl+c or ctrl+x
            \param passwordBox: true to enable password, false to disable
            \param passwordChar: the character that is displayed instead of letters */
            virtual void SetPasswordBox( bool bPasswordBox, wchar_t wcsPasswordChar = L'*' ) = 0;

            //! Returns true if the edit box is currently a password box.
            virtual bool IsPasswordBox() const = 0;

            //! Sets the maximum amount of characters which may be entered in the box.
            /** \param max: Maximum amount of characters. If 0, the character amount is
            infinity. */
            virtual void SetMax( unsigned int nMax ) = 0;

            //! Returns maximum amount of characters, previously set by setMax();
            virtual unsigned int GetMax() const = 0;
        };
    }
}