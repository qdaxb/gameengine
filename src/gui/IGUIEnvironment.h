#pragma once

#include "GUIRect.h"
#include "EMessageBoxFlags.h"
#include "IEventReceiver.h"
#include <stddef.h>

namespace mycge
{
    namespace gui
    {
        class IGUIElement;
        class IGUIFont;
        class IGUIScrollBar;
        class IGUIImage;
        class IGUICheckBox;
        class IGUIListBox;
        class IGUITreeView;
        class IGUIInOutFader;
        class IGUIStaticText;
        class IGUIEditBox;
        class IGUISpinBox;
        class IGUITable;
        class IGUIContextMenu;
        class IGUIComboBox;
        class IGUIToolBar;
        class IGUIButton;
        class IGUIWindow;
        class ITexture;
        class IGUIDXDraw;

        class IGUIElement;
        
        class IGUIEnvironment
        {
        public:
            virtual void DrawAll() = 0;

            virtual void Clear() = 0;

            virtual IGUIElement* GetFocus() const = 0;

            virtual bool SetFocus( IGUIElement* pGUIElement ) = 0;

            virtual bool RemoveFocus( IGUIElement* pGUIElement ) = 0;

            virtual bool HasFocus( IGUIElement* pGUIElement ) const = 0;

            virtual IGUIElement* GetRootGUIElement() = 0;

        public:
            virtual IGUIElement* AddGUIElement( const char* szElementName,
                                                IGUIElement* pParent = NULL ) = 0;

            virtual IGUIFont* AddFont() = 0;

            virtual IGUIButton* AddButton( const Rect<int>& rcElement,
                                           const wchar_t* wcsText = NULL,
                                           const wchar_t* wcsToolTipText = NULL,
                                           IGUIElement* pParent = NULL,
                                           int nID = -1 ) = 0;

            virtual IGUICheckBox* AddCheckBox( const Rect<int>& rcElement,
                                               const wchar_t* wcsText = NULL,
                                               IGUIElement* pParent = NULL,
                                               int nID = -1 ) = 0;

            virtual IGUIEditBox* AddEditBox( const Rect<int>& rcElement,
                                             const wchar_t* wcsText = NULL,
                                             IGUIElement* pParent = NULL,
                                             int nID = -1,
                                             bool bBorder = false ) = 0;

            virtual IGUIListBox* AddListBox( const Rect<int>& rcElement,
                                             IGUIElement* pParent = NULL,
                                             int nID = -1,
                                             bool bDrawBackground = false ) = 0;

            virtual IGUITreeView* AddTreeView( const Rect<int>& rcElement,
                                               IGUIElement* pParent = NULL,
                                               int nID = -1,
                                               bool bScrollBarVertical = true,
                                               bool bScrollBarHorizontal = false ) = 0;

            virtual IGUIWindow* AddWindow( const Rect<int>& rcElement,
                                           const wchar_t* wcsText = NULL,
                                           IGUIElement* pParent = NULL,
                                           int nID = -1,
                                           bool bModal = false ) = 0;

            virtual IGUIStaticText* AddStaticText( const Rect<int>& rcElement,
                                                   const wchar_t* wcsText = NULL,
                                                   IGUIElement* pParent = NULL,
                                                   int nID = -1,
                                                   bool bBorder = false,
                                                   bool bWordWrap = false,
                                                   bool bDrawBackground = false ) = 0;

            virtual IGUIComboBox* AddComboBox( const Rect<int>& rcElement,
                                               const wchar_t* wcsText = NULL,
                                               IGUIElement* pParent = NULL,
                                               int nID = -1 ) = 0;

            virtual IGUIContextMenu* AddContextMenu( const Rect<int>& rcElement,
                                                     IGUIElement* pParent = NULL,
                                                     int nID = -1 ) = 0;

            virtual IGUITable* AddTable( const Rect<int>& rcElement,
                                         IGUIElement* pParent = NULL,
                                         int nID = -1,
                                         bool bDrawBackground = false ) = 0;

            virtual IGUIScrollBar* AddScrollBar( const Rect<int>& rcElement,        
                                                 bool bHorizontal,
                                                 IGUIElement* pParent = NULL,
                                                 int nID = -1 ) = 0;

            //! Adds an image element.
	        /** Use IGUIImage::setImage later to set the image to be displayed.
	        \param rectangle Rectangle specifying the borders of the image.
	        \param parent Parent gui element of the image.
	        \param id Id to identify the gui element.
	        \param text Title text of the image.
	        \return Pointer to the created image element. Returns 0 if an error
	        occurred. This pointer should not be dropped. See
	        IReferenceCounted::drop() for more information. */
            virtual IGUIImage* AddImage( const Rect<int>& rcElement,
                                         const wchar_t* wcsText = NULL,
                                         IGUIElement* pParent = NULL, 
                                         int nID = -1 ) = 0;

            //! Adds a message box.
            /** \param caption Text to be displayed the title of the message box.
            \param text Text to be displayed in the body of the message box.
            \param modal Defines if the dialog is modal. This means, that all other
            gui elements which were created before the message box cannot be used
            until this messagebox is removed.
            \param flags Flags specifying the layout of the message box. For example
            to create a message box with an OK and a CANCEL button on it, set this
            to (EMBF_OK | EMBF_CANCEL).
            \param parent Parent gui element of the message box.
            \param id Id with which the gui element can be identified.
            \param image Optional texture which will be displayed beside the text as an image
            \return Pointer to the created message box. Returns 0 if an error
            occurred. This pointer should not be dropped. See
            IReferenceCounted::drop() for more information. */
            virtual IGUIWindow* AddMessageBox( const wchar_t* wcsCaption, const wchar_t* wcsText=0,
                bool bModal = true, int nFlags = EMBF_OK, IGUIElement* pParent = NULL, int nID = -1, ITexture* pImage = NULL ) = 0;

            //! Adds an element for fading in or out.
            /** \param rectangle Rectangle specifying the borders of the fader.
            If the pointer is NULL, the whole screen is used.
            \param parent Parent item of the element, e.g. a window.
            \param id An identifier for the fader.
            \return Pointer to the created in-out-fader. Returns 0 if an error
            occurred. This pointer should not be dropped. See
            IReferenceCounted::drop() for more information. */
            virtual IGUIInOutFader* AddInOutFader( const Rect<int>* rcElement = NULL, 
                IGUIElement* pParent = NULL, 
                int nID = -1 ) = 0;

            //! Adds a spin box.
            /** An edit box with up and down buttons
            \param text Text to be displayed. Can be altered after creation by setText().
            \param rectangle Rectangle specifying the borders of the spin box.
            \param border Set to true if the spin box should have a 3d border.
            \param parent Parent item of the element, e.g. a window.
            Set it to 0 to place the spin box directly in the environment.
            \param id The ID of the element.
            \return Pointer to the created spin box. Returns 0 if an error occurred.
            This pointer should not be dropped. See IReferenceCounted::drop() for
            more information. */
            virtual IGUISpinBox* AddSpinBox( const Rect<int>& rcElement, 
                const wchar_t* wcsText, 
                bool bBorder = true, 
                IGUIElement* pParent = NULL, 
                int id = -1) = 0;

            //! Posts an input event to the environment.
            /** Usually you do not have to
            use this method, it is used by the engine internally.
            \param event The event to post.
            \return True if succeeded, else false. */
            virtual bool PostEventFromUser( const SEvent& oEvent ) = 0;

            //! This sets a new event receiver for gui events.
            /** Usually you do not have to
            use this method, it is used by the engine internally.
            \param evr Pointer to the new receiver. */
            virtual void SetUserEventReceiver( IEventReceiver* pEventReceiver ) = 0;

        };
    }
}

