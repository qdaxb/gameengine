/********************************************************************
	created:	2011/06/30
	created:	30:6:2011   11:49
	file base:	CVideoControllerWin32
	file ext:	cpp
	author:		axb
	
	purpose:	WIN32平台的IVideoDriver实现类
*********************************************************************/
#include "CVideoControllerWin32.h"
#include "DXUT/DXUT.h"
#include <wtypes.h>
#include "CVideoDriverDX9.h"
#include "IVideoDriver.h"
#include "SColor.h"
namespace mycge{
	
	void CALLBACK OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext );
	CVideoControllerWin32* pVideoControllerWin32;
	render::IVideoDriver* CVideoControllerWin32::getVideoDriver()
	{
		return this->pVideoDriver;
	}

	bool CVideoControllerWin32::destory()
	{
		return true;
	}

	bool CVideoControllerWin32::init()
	{

		DXUTSetCallbackD3D9FrameRender( OnFrameRender );
		DXUTInit( true, true );
		DXUTSetHotkeyHandling( true, true, true );
		pVideoControllerWin32=this;
		return true;

	}

	void CVideoControllerWin32::setWindowCaption( const wchar_t* text )
	{

	}

	scene::ISceneManager* CVideoControllerWin32::getSceneManager()
	{
		return NULL;
	}

	bool CVideoControllerWin32::show(const wchar_t* title,int width,int height)
	{
		DXUTCreateWindow(title);
		this->pVideoDriver=new render::CVideoDriverDX9();
		((render::CVideoDriverDX9*) pVideoDriver)->initDriver(core::dimension2d<u32>(640,480),NULL,NULL,false,false,false,false,NULL);


		DXUTMainLoop();
		
		return true;
	}

	gui::IGUIEnvironment* CVideoControllerWin32::getGUIEnvironment()
	{
		return NULL;
	}
	void CALLBACK OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
	{
		render::IVideoDriver* pVideoDriver=pVideoControllerWin32->getVideoDriver();
		pVideoDriver->beginScene(true, true, render::SColor(255,100,101,140));
		pVideoDriver->endScene();
	}


}