#pragma once

#include "IGUIElement.h"

namespace mycge
{
    namespace gui
    {
        //! Default scroll bar GUI element.
        class IGUIScrollBar : public IGUIElement
        {
        public:

            //! constructor
            IGUIScrollBar( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcScrollBar )
                : IGUIElement( EGUIET_SCROLL_BAR, pEnvironment, pParent, nID, rcScrollBar ) {}

            //! Sets the maximum value of the scrollbar.
            virtual void SetMax( int nMax ) = 0;
            //! Gets the maximum value of the scrollbar.
            virtual int GetMax() const = 0;

            //! Sets the minimum value of the scrollbar.
            virtual void SetMin( int nMin ) = 0;
            //! Gets the minimum value of the scrollbar.
            virtual int GetMin() const = 0;

            //! Gets the small step value
            virtual int GetSmallStep() const = 0;

            //! Sets the small step
            /** That is the amount that the value changes by when clicking
            on the buttons or using the cursor keys. */
            virtual void SetSmallStep( int nStep ) = 0;

            //! Gets the large step value
            virtual int GetLargeStep() const = 0;

            //! Sets the large step
            /** That is the amount that the value changes by when clicking
            in the tray, or using the page up and page down keys. */
            virtual void SetLargeStep( int nStep ) = 0;

            //! Gets the current position of the scrollbar
            virtual int GetPos() const = 0;

            //! Sets the current position of the scrollbar
            virtual void SetPos( int nPos ) = 0;
        };
    }
}