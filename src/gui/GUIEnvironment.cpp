#include "GUIEnvironment.h"
#include "GUIButton.h"
#include "IVideoDriver.h"
#include "IOSOperator.h"

namespace mycge
{
	namespace gui
	{
        GUIEnvironment::GUIEnvironment( IVideoDriver* pVideoDriver, IOSOperator* pOSOperator )
            :IGUIElement( EGUIET_ELEMENT, 0, 0, 0, Rect<int>(Position2D<int>( 0, 0), Position2D<int>( 100, 100))),
             m_pUserEventReceiver( 0 ),
             m_pVideoDriver( pVideoDriver ),
             m_pOSOperator( pOSOperator )
        {
        }

        GUIEnvironment::~GUIEnvironment()
        {
        }

        IGUIButton* GUIEnvironment::AddButton( const Rect<int>& rcElement, const wchar_t* wcsText /*= NULL*/, const wchar_t* wcsToolTipText /*= NULL*/, IGUIElement* pParent /*= NULL*/, int nID /*= -1 */ )
        {
            IGUIButton* pGUIButton = new GUIButton( this, m_pParent ? m_pParent : this, nID, rcElement );

            if ( NULL != wcsText )
            {
                pGUIButton->SetText( wcsText );
            }

            if ( NULL != wcsToolTipText )
            {
                pGUIButton->SetToolTipText( wcsToolTipText );
            }

            return pGUIButton;
        }

        void GUIEnvironment::SetUserEventReceiver( IEventReceiver* pEventReceiver )
        {
            m_pUserEventReceiver = pEventReceiver;
        }

        bool GUIEnvironment::OnEvent( const SEvent& oEvent )
        {
            bool bRet = false;
            if ( NULL != m_pUserEventReceiver &&
                 EET_MOUSE_INPUT_EVENT != oEvent.EventType &&
                 EET_KEY_INPUT_EVENT != oEvent.EventType &&
                 EET_GUI_EVENT != oEvent.EventType ||
                 oEvent.GUIEvent.Caller != this )
            {
                bRet = m_pUserEventReceiver->OnEvent( oEvent );
            }

            return bRet;
        }

        IGUIElement* GUIEnvironment::GetRootGUIElement()
        {
            return this;
        }

        void mycge::gui::GUIEnvironment::DrawAll()
        {
            if ( NULL != m_pVideoDriver )
            {
                Dimension2D<int> oDim2D( m_pVideoDriver->GetScreenSize() );
                // Change rect
                //...
                //
                Draw();
            }
        }

        void mycge::gui::GUIEnvironment::Clear()
        {
            list<IGUIElement*>& listChildren = GetRootGUIElement()->GetChildren();

            list<IGUIElement*>::iterator it = listChildren.begin();

            for ( it; it != listChildren.end(); ++it )
            {
                delete (*it);
                *it = NULL;
            }
        }	
	}
}

