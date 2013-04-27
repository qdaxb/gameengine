#pragma once

#include "IGUIButton.h"

namespace mycge
{
    namespace gui
    {
        class IGUISkin;
        class GUIButton : public IGUIButton
        {
        public:
            GUIButton( IGUIEnvironment* pEnvironment, IGUIElement* pParent,
                int nID, const Rect<int>& rcButton );
            virtual ~GUIButton();

        public:
            virtual bool OnEvent( const SEvent& oEvent );

            virtual void Draw();

            //! Sets if the button should behave like a push button.
            /** Which means it can be in two states: Normal or Pressed. With a click on the button,
            the user can change the state of the button. */
            virtual void SetIsPushButton(bool bIsPushButton=true);

            //! Sets the pressed state of the button if this is a pushbutton
            virtual void SetPressed(bool bPressed=true);

            //! Returns if the button is currently pressed
            virtual bool IsPressed() const;

            //! Returns whether the button is a push button
            virtual bool IsPushButton() const;

            //! Sets if the button should use the skin to draw its border and button face (default is true)
            virtual void SetDrawBorder( bool bBorder=true );

            //! Returns if the border and button face are being drawn using the skin
            virtual bool IsDrawingBorder() const;

            //! Sets if the button should scale the button images to fit
            virtual void SetScaleImage( bool bScaleImage=true );

            //! Checks whether the button scales the used images
            virtual bool IsScalingImage() const;

        private:
            bool m_bIsPushButton;

            bool m_bPressed;

            bool m_bDrawBorder;

            IGUISkin* m_pSkin;
        };
    }
}
