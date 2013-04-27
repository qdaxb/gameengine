#include "GUISkin.h"

namespace mycge
{
	namespace gui
	{
        GUISkin::GUISkin(void)
        {
        }

        GUISkin::~GUISkin(void)
        {
        }		

        D3DCOLOR GUISkin::GetColor( EGUI_DEFAULT_COLOR color ) const
        {
            return 0;
        }

        void GUISkin::SetColor( EGUI_DEFAULT_COLOR which, D3DCOLOR newColor )
        {

        }

        int GUISkin::GetSize( EGUI_DEFAULT_SIZE size ) const
        {
            return 0;
        }

        const wchar_t* GUISkin::GetDefaultText( EGUI_DEFAULT_TEXT text )
        {
            return 0;
        }

        void GUISkin::SetDefaultText( EGUI_DEFAULT_TEXT which, const wchar_t* newText )
        {

        }

        void GUISkin::SetSize( EGUI_DEFAULT_SIZE which, int size )
        {

        }

        IGUIFont* GUISkin::GetFont( EGUI_DEFAULT_FONT which /*= EGDF_DEFAULT*/ )
        {
            return 0;
        }

        void GUISkin::SetFont( IGUIFont* font, EGUI_DEFAULT_FONT which /*= EGDF_DEFAULT */ )
        {

        }

        unsigned int GUISkin::GetIcon( EGUI_DEFAULT_ICON icon ) const
        {
            return 0;
        }

        void GUISkin::SetIcon( EGUI_DEFAULT_ICON icon, unsigned int index )
        {

        }

    }
}

