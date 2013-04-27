#pragma once

#include "IEventReceiver.h"
#include "EGUIElementTypes.h"
#include "EGUIAlignment.h"
#include "GUIRect.h"
#include <list>
using namespace std;

namespace mycge
{
    namespace gui
    {
        class IGUIEnvironment;
        class IGUIElement : public IEventReceiver
        {
        public:
            //! Constructor
            IGUIElement( EGUI_ELEMENT_TYPE eType, IGUIEnvironment* pEnvironment, IGUIElement* pParent,
                int nID, const Rect<int>& rcElement )
                :m_bVisible( true ), 
                 m_bEnable( true ),
                 m_bSubElement( false ), 
                 m_Environment( pEnvironment ), 
                 m_eType( eType ),
                 m_nID( nID ),
                 m_pParent( pParent )
            {
                // if we were given a parent to attach to
                if ( NULL != pParent )
                {
                    pParent->AddChildren( this );
                    // recalculateAbsolutePosition(true);
                }
            }

            //! Destructor
            virtual ~IGUIElement()
            {
                // delete all children
                list<IGUIElement*>::iterator it = m_listChildren.begin();
                for ( it; it != m_listChildren.end(); ++it)
                {
                    (*it)->m_pParent = NULL;
                    delete (*it);
                    (*it) = NULL;
                }
            }

        public:
            virtual void Draw()
            {
                if ( false != IsVisible() )
                {
                    list<IGUIElement*>::iterator it = m_listChildren.begin();
                    for ( it; it != m_listChildren.end(); ++it )
                    {
                        (*it)->Draw();
                    }
                }
            }

            virtual bool IsEnabled() const
            {
                return m_bEnable;
            }

            virtual void SetEnabled( bool bEnabled )
            {
                m_bEnable = bEnabled;
            }

            virtual bool IsVisible() const
            {
                return m_bVisible;
            }

            virtual void SetVisible( bool bVisible )
            {
                m_bVisible = bVisible;
            }

            virtual bool IsSubElement() const 
            {
                return m_bSubElement;
            }

            //! returns true if the given element is a child of this one.
            //! \param child: The child element to check
            bool IsMyChild( IGUIElement* pChild ) const
            {
                if ( NULL == pChild)
                {
                    return false;
                }

                do
                {
                    if ( NULL != pChild->m_pParent )
                    {
                        pChild = pChild->m_pParent;
                    }

                } while ( pChild->m_pParent && pChild != this);

                //_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
                return pChild == this;
            }

            virtual void SetToolTipText( const wchar_t* wcsText )
            {
                m_strToolTipText = wcsText;
            }

            virtual const wchar_t* GetToolTipText() const
            {
                return m_strToolTipText.c_str();
            }

            virtual bool HasToolTipText() const
            {
                return m_strToolTipText.compare( L"") ? true : false;
            }

            virtual int GetID() const
            {
                return m_nID;
            }

            virtual void SetID( int nID )
            {
                m_nID = nID;
            }

            virtual EGUI_ELEMENT_TYPE GetType() const
            {
                return m_eType;
            }

        public:
            virtual void AddChildren( IGUIElement* pElement )
            {
                if ( NULL != pElement )
                {
                    pElement->m_pParent = this;
                    m_listChildren.push_back( pElement );
                }
            }

            virtual void RemoveChildren( IGUIElement* pElement )
            {
                if ( NULL != pElement )
                {
                    list<IGUIElement*>::iterator it = m_listChildren.begin();
                    for ( it; it != m_listChildren.end(); ++it )
                    {
                        if ( (*it) == pElement )
                        {
                            (*it)->m_pParent = NULL;
                            delete (*it);
                            m_listChildren.erase( it );
                            return;
                        }
                    }
                }
            }

            virtual void Remove()
            {
                if ( NULL != m_pParent )
                {
                    m_pParent->RemoveChildren( this );
                }
            }

            virtual list<IGUIElement*>& GetChildren()
            {
                return m_listChildren;
            }

        public:
            //! Called if an event happened.
            virtual bool OnEvent( const SEvent& oEvent )
            {
                return m_pParent ? m_pParent->OnEvent( oEvent ) : false;
            }

            //! Returns true if a point is within this element.
            /** Elements with a shape other than a rectangle should override this method */
            virtual bool IsPointInside( const Position2D<int>& point ) const
            {
                return true;//AbsoluteClippingRect.isPointInside(point);
            }

            //! animate the element and its children.
            virtual void OnPostRender( unsigned int nTimeMs )
            {
                if ( false != IsVisible() )
                {
                    list<IGUIElement*>::iterator it = m_listChildren.begin();
                    for (; it != m_listChildren.end(); ++it)
                    {
                        (*it)->OnPostRender( nTimeMs );
                    }
                }
            }

            //! Moves this element.
            virtual void move( Position2D<int> absoluteMovement)
            {
                //setRelativePosition(DesiredRect + absoluteMovement);
            }

         protected:
            IGUIElement* m_pParent;

            bool m_bVisible;

            bool m_bEnable;

            bool m_bSubElement;

            wstring m_strToolTipText;

            int m_nID;

            //! type of element
            EGUI_ELEMENT_TYPE m_eType;

            //! tells the element how to act when its parent is resized
            EGUI_ALIGNMENT m_AlignLeft, m_AlignRight, m_AlignTop, m_AlignBottom;

            //! GUI Environment
            IGUIEnvironment* m_Environment;

            list<IGUIElement*> m_listChildren;
        };
    }
}
