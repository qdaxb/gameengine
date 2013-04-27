/********************************************************************
	created:	2011/06/29
	created:	29:6:2011   21:53
	file base:	IVideoManager
	file ext:	h
	author:		axb
	
	purpose:	videomanager接口，负责窗口的创建与初始化
*********************************************************************/
#ifndef _IVIDEOCONTROLLER_H_
#define _IVIDEOCONTROLLER_H_
namespace mycge{
	namespace gui {
		class IGUIEnvironment;
	} // end namespace gui

	namespace scene {
		class ISceneManager;
	}
	namespace render {
		class IVideoDriver;
	}
	class IVideoController
	{
	public:
		virtual bool init() = 0;
		virtual bool show(const wchar_t* title,int width,int height) = 0;
		virtual bool destory() = 0;
		virtual void setWindowCaption(const wchar_t* text) = 0;
		virtual gui::IGUIEnvironment* getGUIEnvironment() = 0;
		virtual scene::ISceneManager* getSceneManager()=0;
		virtual render::IVideoDriver* getVideoDriver()=0;
	protected:
	private:
	};
}
#endif