#pragma once

#include "IGUISkin.h"
#include <d3dx9core.h>

namespace mycge
{
	namespace gui
	{
        class GUISkin : public IGUISkin
        {
        public:
            GUISkin(void);
            virtual ~GUISkin(void);

        public:
            //! returns default color
            virtual D3DCOLOR GetColor( EGUI_DEFAULT_COLOR color ) const;

            //! Sets a default color
            virtual void SetColor( EGUI_DEFAULT_COLOR which, D3DCOLOR newColor );

            //! returns size for the given size type
            virtual int GetSize( EGUI_DEFAULT_SIZE size ) const;

            //! Returns a default text.
            /** For example for Message box button captions:
            "OK", "Cancel", "Yes", "No" and so on. */
            virtual const wchar_t* GetDefaultText( EGUI_DEFAULT_TEXT text );

            //! Sets a default text.
            /** For example for Message box button captions:
            "OK", "Cancel", "Yes", "No" and so on. */
            virtual void SetDefaultText( EGUI_DEFAULT_TEXT which, const wchar_t* newText );

            //! Sets a default size
            virtual void SetSize( EGUI_DEFAULT_SIZE which, int size) = 0;

            //! returns the default font
            virtual IGUIFont* GetFont( EGUI_DEFAULT_FONT which = EGDF_DEFAULT);

            //! Sets a default font
            virtual void SetFont( IGUIFont* font, EGUI_DEFAULT_FONT which = EGDF_DEFAULT );

            //! Returns a default icon
            /** Returns the sprite index within the sprite bank */
            virtual unsigned int GetIcon( EGUI_DEFAULT_ICON icon ) const;

            //! Sets a default icon
            /** Sets the sprite index used for drawing icons like arrows,
            close buttons and ticks in checkboxes
            \param icon: Enum specifying which icon to change
            \param index: The sprite index used to draw this icon */
            virtual void SetIcon( EGUI_DEFAULT_ICON icon, unsigned int index );

        private:
            D3DCOLOR m_D3DColor;

            ID3DXFont* m_pGUIFont;

            ID3DXSprite* m_pSprite;
        };		
	}
}

