#pragma once

#include "IGUIElement.h"

namespace mycge
{
    namespace gui
    {
        //! Combobox widGet
        class IGUIComboBox : public IGUIElement
        {
        public:

            //! constructor
            IGUIComboBox( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcComboBox )
                : IGUIElement( EGUIET_COMBO_BOX, pEnvironment, pParent, nID, rcComboBox ) {}

            //! Returns amount of items in box
            virtual unsigned int GetItemCount() const = 0;

            //! Returns string of an item. the idx may be a value from 0 to itemCount-1
            virtual const wchar_t* GetItem( unsigned int nIndex ) const = 0;

            //! Returns item data of an item. the idx may be a value from 0 to itemCount-1
            virtual unsigned int GetItemData( unsigned int nIndex ) const = 0;

            //! Returns index based on item data
            virtual int GetIndexForItemData( unsigned int nData ) const = 0;

            //! Adds an item and returns the index of it
            virtual unsigned int AddItem( const wchar_t* wcsText, unsigned int nData = 0 ) = 0;

            //! Removes an item from the combo box.
            /** Warning. This will change the index of all following items */
            virtual void RemoveItem( unsigned int nIndex ) = 0;

            //! Deletes all items in the combo box
            virtual void Clear() = 0;

            //! Returns id of selected item. returns -1 if no item is selected.
            virtual int GetSelected() const = 0;

            //! Sets the selected item. Set this to -1 if no item should be selected
            virtual void SetSelected( int nIndex ) = 0;

            //! Sets text justification of the text area
            /** \param horizontal: EGUIA_UPPERLEFT for left justified (default),
            EGUIA_LOWEERRIGHT for right justified, or EGUIA_CENTER for centered text.
            \param vertical: EGUIA_UPPERLEFT to align with top edge,
            EGUIA_LOWEERRIGHT for bottom edge, or EGUIA_CENTER for centered text (default). */
            virtual void SetTextAlignment( EGUI_ALIGNMENT eHorizontal, EGUI_ALIGNMENT eVertical ) = 0;
        };
    }
}