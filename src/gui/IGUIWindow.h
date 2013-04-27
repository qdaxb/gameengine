#pragma once

#include "IGUITextElement.h"

namespace mycge
{
    namespace gui
    {
        class IGUIButton;

        //! Default moveable window GUI element with border, caption and close icons.
        class IGUIWindow : public IGUITextElement
        {
        public:

            //! constructor
            IGUIWindow( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcWindow )
                : IGUIElement( EGUIET_WINDOW, pEnvironment, pParent, nID, rcWindow ) {}

            //! Returns pointer to the close button
            /** You can hide the button by calling SetVisible(false) on the result. */
            virtual IGUIButton* GetCloseButton() const = 0;

            //! Returns pointer to the minimize button
            /** You can hide the button by calling SetVisible(false) on the result. */
            virtual IGUIButton* GetMinimizeButton() const = 0;

            //! Returns pointer to the maximize button
            /** You can hide the button by calling SetVisible(false) on the result. */
            virtual IGUIButton* GetMaximizeButton() const = 0;

            //! Returns true if the window can be dragged with the mouse, false if not
            virtual bool IsDraggable() const = 0;

            //! Sets whether the window can be dragged by the mouse
            virtual void SetDraggable( bool bDraggable ) = 0;

            //! Set if the window background will be drawn
            virtual void SetDrawBackground( bool bDraw ) = 0;

            //! Get if the window background will be drawn
            virtual bool GetDrawBackground() const = 0;

            //! Set if the window titlebar will be drawn
            //! Note: If the background is not drawn, then the titlebar is automatically also not drawn
            virtual void SetDrawTitlebar( bool bDraw ) = 0;

            //! Get if the window titlebar will be drawn
            virtual bool GetDrawTitlebar() const = 0;

            //! Returns the rectangle of the drawable area (without border and without titlebar)
            /** The coordinates are given relative to the top-left position of the gui element.<br>
            So to Get absolute positions you have to add the resulting rectangle to GetAbsolutePosition().UpperLeftCorner.<br>
            To Get it relative to the parent element you have to add the resulting rectangle to GetRelativePosition().UpperLeftCorner.
            Beware that adding a menu will not change the clientRect as menus are own gui elements, so in that case you might want to subtract
            the menu area additionally.	*/
            virtual Rect<int> GetClientRect() const = 0;
        };
    }
}