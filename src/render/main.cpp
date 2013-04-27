#include "CVideoControllerWin32.h"
#include <windows.h>
INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, int )
{
	mycge::CVideoControllerWin32* videoController=new mycge::CVideoControllerWin32();
	videoController->init();


	videoController->show(L"test",800,600);
}