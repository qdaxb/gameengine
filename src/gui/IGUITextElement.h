#pragma once

#include "IGUIElement.h"

namespace mycge
{
    namespace gui
    {
        class IGUITextElement : public IGUIElement
        {
        public:
            IGUITextElement( EGUI_ELEMENT_TYPE eType, IGUIEnvironment* pEnvironment, IGUIElement* pParent,
                int nID, const Rect<int>& rcElement )
                :IGUIElement( eType, pEnvironment, pParent, nID, rcElement )
            {

            }
        public:
            virtual void SetText( const wchar_t* wcsText )
            {
                m_strText = wcsText;
            }

            virtual const wchar_t* GetText() const
            {
                return m_strText.c_str();
            }

        protected:
            wstring m_strText;
        };
    }
}