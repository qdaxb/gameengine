#pragma once

#include "IGUIElement.h"

namespace mycge
{
    namespace gui
    {
        //! Enumeration for listbox colors
        enum EGUI_LISTBOX_COLOR
        {
            //! Color of text
            EGUI_LBC_TEXT=0,
            //! Color of selected text
            EGUI_LBC_TEXT_HIGHLIGHT,
            //! Color of icon
            EGUI_LBC_ICON,
            //! Color of selected icon
            EGUI_LBC_ICON_HIGHLIGHT,
            //! Not used, just counts the number of available colors
            EGUI_LBC_COUNT
        };


        //! Default list box GUI element.
        class IGUIListBox : public IGUIElement
        {
        public:
            //! constructor
            IGUIListBox( IGUIEnvironment* pEnvironment, IGUIElement* pParent, int nID, Rect<int> rcListBox )
                : IGUIElement( EGUIET_LIST_BOX, pEnvironment, pParent, nID, rcListBox ) {}

            //! returns amount of list items
            virtual unsigned int GetItemCount() const = 0;

            //! returns string of a list item. the may id be a value from 0 to itemCount-1
            virtual const wchar_t* GetListItem( unsigned int nID ) const = 0;

            //! adds an list item, returns id of item
            virtual unsigned int AddItem( const wchar_t* wcsText ) = 0;

            //! adds an list item with an icon
            /** \param text Text of list entry
            \param icon Sprite index of the Icon within the current sprite bank. Set it to -1 if you want no icon
            \return The id of the new created item */
            virtual unsigned int AddItem( const wchar_t* wcsText, int nIcon ) = 0;

            //! Removes an item from the list
            virtual void RemoveItem( unsigned int nIndex ) = 0;

            //! Returns the icon of an item
            virtual int GetIcon( unsigned int nIndex ) const = 0;

            //! Sets the sprite bank which should be used to draw list icons.
            /** This font is Set to the sprite bank of the built-in-font by
            default. A sprite can be displayed in front of every list item.
            An icon is an index within the icon sprite bank. Several
            default icons are available in the skin through GetIcon. */
            //virtual void SetSpriteBank( IGUISpriteBank* bank ) = 0;

            //! Clears the list, deletes all items in the listbox
            virtual void Clear() = 0;

            //! returns id of selected item. returns -1 if no item is selected.
            virtual int GetSelected() const = 0;

            //! Sets the selected item. Set this to -1 if no item should be selected
            virtual void SetSelected( int nIndex ) = 0;

            //! Sets the selected item. Set this to 0 if no item should be selected
            virtual void SetSelected( const wchar_t* wcsItem ) = 0;

            //! Set whether the listbox should scroll to newly selected items
            virtual void SetAutoScrollEnabled( bool bScroll) = 0;

            //! returns true if automatic scrolling is enabled, false if not.
            virtual bool IsAutoScrollEnabled() const = 0;

            //! Set all item colors at given index to color
            //virtual void SetItemOverrideColor( unsigned int nIndex, const video::SColor &color) = 0;

            //! Set all item colors of specified type at given index to color
            //virtual void SetItemOverrideColor( unsigned int nIndex, EGUI_LISTBOX_COLOR eColorType, const video::SColor &color) = 0;

            //! Clear all item colors at index
            virtual void ClearItemOverrideColor( unsigned int nIndex ) = 0;

            //! Clear item color at index for given colortype
            virtual void ClearItemOverrideColor( unsigned int nIndex, EGUI_LISTBOX_COLOR eColorType) = 0;

            //! Has the item at index its color overwritten?
            virtual bool HasItemOverrideColor(unsigned int nIndex, EGUI_LISTBOX_COLOR eColorType) const = 0;

            //! return the overwrite color at given item index.
            //virtual video::SColor GetItemOverrideColor(unsigned int index, EGUI_LISTBOX_COLOR colorType) const = 0;

            //! return the default color which is used for the given colorType
            //virtual video::SColor GetItemDefaultColor(EGUI_LISTBOX_COLOR colorType) const = 0;

            //! Set the item at the given index
            virtual void SetItem( unsigned int nIndex, const wchar_t* wcsText, int nIcon ) = 0;

            //! Insert the item at the given index
            /** \return The index on success or -1 on failure. */
            virtual int InsertItem( unsigned int nIndex, const wchar_t* wcsText, int nIcon ) = 0;

            //! Swap the items at the given indices
            virtual void SwapItems( unsigned int nIndex1, unsigned int nIndex2 ) = 0;

            //! Set global itemHeight
            virtual void SetItemHeight( int nHeight ) = 0;

            //! Sets whether to draw the background
            virtual void SetDrawBackground( bool bDraw ) = 0;
        }
    }