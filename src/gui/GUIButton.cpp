#include "GUIButton.h"

#include "IGUIEnvironment.h"

namespace mycge
{
    namespace gui
    {

        GUIButton::GUIButton( IGUIEnvironment* pEnvironment, IGUIElement* pParent,
            int nID, const Rect<int>& rcButton )
            :IGUIButton( pEnvironment, pParent, nID, rcButton )
        {
            
        }

        GUIButton::~GUIButton()
        {
        }

        bool GUIButton::OnEvent( const SEvent& oEvent )
        {
            if ( false == m_bEnable )
            {
                return IGUIElement::OnEvent( oEvent );
            }

            switch( oEvent.EventType )
            {
            case EET_KEY_INPUT_EVENT:
                if ( oEvent.KeyInput.bKeyDown &&
                    ( oEvent.KeyInput.Key == KEY_RETURN || oEvent.KeyInput.Key == KEY_SPACE ))
                {
                    if ( !m_bIsPushButton )
                    {
                        SetPressed( true );
                    }
                    else
                    {
                        SetPressed( !m_bPressed );
                    }

                    return true;
                }
                if ( m_bPressed && !m_bIsPushButton && oEvent.KeyInput.bKeyDown && oEvent.KeyInput.Key == KEY_ESCAPE)
                {
                    SetPressed( false );
                    return true;
                }
                else
                    if ( !oEvent.KeyInput.bKeyDown && m_bPressed &&
                        ( oEvent.KeyInput.Key == KEY_RETURN || oEvent.KeyInput.Key == KEY_SPACE ))
                    {
                        //Environment->removeFocus(this);

                        if ( !m_bIsPushButton )
                        {
                            SetPressed(false);
                        }

                        if ( NULL != m_pParent )
                        {
                            SEvent newEvent;
                            newEvent.EventType = EET_GUI_EVENT;
                            newEvent.GUIEvent.Caller = this;
                            newEvent.GUIEvent.Element = 0;
                            newEvent.GUIEvent.EventType = EGET_BUTTON_CLICKED;
                            m_pParent->OnEvent(newEvent);
                        }

                        return true;
                    }

                    break;
            case EET_GUI_EVENT:
                if ( oEvent.GUIEvent.EventType == EGET_ELEMENT_FOCUS_LOST)
                {
                    if (oEvent.GUIEvent.Caller == this && !m_bIsPushButton )
                    {
                        SetPressed( false );
                    }
                }
                break;
            case EET_MOUSE_INPUT_EVENT:
                if ( oEvent.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN )
                {
                    if ( m_Environment->HasFocus( this ) /*&&
                        !AbsoluteClippingRect.isPointInside( Position2D<int>( event.MouseInput.X, event.MouseInput.Y))*/)
                    {
                        m_Environment->RemoveFocus( this );
                        return false;
                    }

                    if ( !m_bIsPushButton )
                    {
                        SetPressed( true );
                    }

                    m_Environment->SetFocus( this );
                    return true;
                }
                else
                    if ( oEvent.MouseInput.Event == EMIE_LMOUSE_LEFT_UP )
                    {
                        bool wasPressed = m_bPressed;
                        //Environment->removeFocus(this);

                        /*if ( !AbsoluteClippingRect.isPointInside( Position2D<int>(event.MouseInput.X, event.MouseInput.Y ) ) )
                        {
                            if ( !m_bIsPushButton )
                            {
                                SetPressed( false );
                            }

                            return true;
                        }*/

                        if ( !m_bIsPushButton )
                        {
                            SetPressed( false );
                        }
                        else
                        {
                            SetPressed( !m_bPressed );
                        }

                        if (( !m_bIsPushButton && wasPressed && m_pParent ) ||
                            ( m_bIsPushButton && wasPressed != m_bPressed ))
                        {
                            SEvent newEvent;
                            newEvent.EventType = EET_GUI_EVENT;
                            newEvent.GUIEvent.Caller = this;
                            newEvent.GUIEvent.Element = 0;
                            newEvent.GUIEvent.EventType = EGET_BUTTON_CLICKED;
                            m_pParent->OnEvent(newEvent);
                        }

                        return true;
                    }
                    break;
            default:
                break;
            }

            return m_pParent ? m_pParent->OnEvent( oEvent ) : false;
        }

        void GUIButton::Draw()
        {

        }

        void GUIButton::SetIsPushButton( bool bIsPushButton/*=true*/ )
        {
            m_bIsPushButton = bIsPushButton;
        }

        void GUIButton::SetPressed( bool bPressed/*=true*/ )
        {
            m_bPressed = bPressed;
        }

        bool GUIButton::IsPressed() const
        {
            return m_bPressed;
        }

        bool GUIButton::IsPushButton() const
        {
            return m_bIsPushButton;
        }

        void GUIButton::SetDrawBorder( bool bBorder/*=true */ )
        {
            m_bDrawBorder = bBorder;
        }

        bool GUIButton::IsDrawingBorder() const
        {
            return m_bDrawBorder;
        }

        void GUIButton::SetScaleImage( bool bScaleImage/*=true */ )
        {

        }

        bool GUIButton::IsScalingImage() const
        {
            return true;
        }
    }
}
