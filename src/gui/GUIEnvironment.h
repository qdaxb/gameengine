#pragma once

#include "IGUIEnvironment.h"
#include "IGUIElement.h"

namespace mycge
{
	namespace gui
	{
        class IEventReceiver;
        class IVideoDriver;
        class IOSOperator;

        class GUIEnvironment : public IGUIEnvironment, public IGUIElement
        {
        public:
            GUIEnvironment( IVideoDriver* pVideoDriver, IOSOperator* pOSOperator );

            virtual ~GUIEnvironment();

        public:
            virtual void DrawAll();

            virtual void Clear();

            virtual bool OnEvent( const SEvent& oEvent );

            virtual void SetUserEventReceiver( IEventReceiver* pEventReceiver );

            //! Returns the root gui element.
            virtual IGUIElement* GetRootGUIElement();

        public:
            virtual IGUIButton* AddButton( const Rect<int>& rcElement,
                const wchar_t* wcsText = NULL,
                const wchar_t* wcsToolTipText = NULL,
                IGUIElement* pParent = NULL,
                int nID = -1 );

        private:
            IEventReceiver* m_pUserEventReceiver;

            IVideoDriver* m_pVideoDriver;

            IOSOperator* m_pOSOperator;
        };
	}
}

