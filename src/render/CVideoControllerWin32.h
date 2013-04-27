#include "IVideoController.h"
#include <wtypes.h>
#include <d3d9.h>
namespace mycge{
	namespace render{
		class IVideoDriver;
	}
	class CVideoControllerWin32:public IVideoController{
	private:
		render::IVideoDriver* pVideoDriver;
	protected:
	public:

		virtual render::IVideoDriver* getVideoDriver() ;

		virtual bool destory() ;

		virtual bool init() ;

		virtual void setWindowCaption( const wchar_t* text ) ;

		virtual scene::ISceneManager* getSceneManager() ;

		virtual bool show(const wchar_t* title,int width,int height) ;

		virtual gui::IGUIEnvironment* getGUIEnvironment() ;

	};
}