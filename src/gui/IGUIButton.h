#pragma once

#include "IGUITextElement.h"

namespace mycge
{
    namespace gui
    {
        enum EGUI_BUTTON_STATE
        {
            //! The button is not pressed
            EGBS_BUTTON_UP=0,
            //! The button is currently pressed down
            EGBS_BUTTON_DOWN,
            //! The mouse cursor is over the button
            EGBS_BUTTON_MOUSE_OVER,
            //! The mouse cursor is not over the button
            EGBS_BUTTON_MOUSE_OFF,
            //! The button has the focus
            EGBS_BUTTON_FOCUSED,
            //! The button doesn't have the focus
            EGBS_BUTTON_NOT_FOCUSED,
            //! not used, counts the number of enumerated items
            EGBS_COUNT
        };

        //! Names for gui button state icons
        const char* const GUIButtonStateNames[] =
        {
            "buttonUp",
            "buttonDown",
            "buttonMouseOver",
            "buttonMouseOff",
            "buttonFocused",
            "buttonNotFocused",
            0,
            0,
        };

        class IGUIButton : public IGUITextElement
        {
        public:
            //! constructor
            IGUIButton( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcButton )
                : IGUITextElement( EGUIET_BUTTON, pEnvironment, pParent, nID, rcButton ) {}

            //! Sets if the button should behave like a push button.
            /** Which means it can be in two states: Normal or Pressed. With a click on the button,
            the user can change the state of the button. */
            virtual void SetIsPushButton(bool bIsPushButton = true) = 0;

            //! Sets the pressed state of the button if this is a pushbutton
            virtual void SetPressed(bool bPressed = true) = 0;

            //! Returns if the button is currently pressed
            virtual bool IsPressed() const = 0;

            //! Returns whether the button is a push button
            virtual bool IsPushButton() const = 0;

            //! Sets if the button should use the skin to draw its border and button face (default is true)
            virtual void SetDrawBorder( bool bBorder = true ) = 0;

            //! Returns if the border and button face are being drawn using the skin
            virtual bool IsDrawingBorder() const = 0;

            //! Sets if the button should scale the button images to fit
            virtual void SetScaleImage( bool bScaleImage = true ) = 0;

            //! Checks whether the button scales the used images
            virtual bool IsScalingImage() const = 0;
        };
    }
}