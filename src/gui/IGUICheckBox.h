#pragma once

#include "IGUITextElement.h"

namespace mycge
{
    namespace gui
    {
        //! GUI Check box interface.
        class IGUICheckBox : public IGUITextElement
        {
        public:

            //! constructor
            IGUICheckBox( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcCheckBox )
                : IGUIElement( EGUIET_CHECK_BOX, pEnvironment, pParent, nID, rcCheckBox ) {}

            //! Set if box is checked.
            virtual void SetChecked( bool bChecked ) = 0;

            //! Returns true if box is checked.
            virtual bool IsChecked() const = 0;
        };
    }
}