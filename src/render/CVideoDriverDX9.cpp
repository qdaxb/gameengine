#include "CVideoDriverDX9.h"
#include "DXUT/DXUT.h"
namespace mycge{
	namespace render{
		void CVideoDriverDX9::drawIndexedPrimitive( PRIMITVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount )
		{

		}

		bool CVideoDriverDX9::beginScene( bool backBuffer/*=true*/, bool zBuffer/*=true*/, SColor color/*=SColor(255,0,0,0 ) */ )
		{
			DWORD flags = 0;
			if (backBuffer)
				flags |= D3DCLEAR_TARGET;

			if (zBuffer)
				flags |= D3DCLEAR_ZBUFFER;

			pID3DDevice->Clear( 0, NULL, flags, color.color, 1.0, 0);
			pID3DDevice->BeginScene();
			return true;
		}

		void CVideoDriverDX9::drawPrimitiveUP( PRIMITVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride )
		{

		}

		const VIEWPORT* CVideoDriverDX9::getViewPort() const
		{
			return NULL;
		}

		void CVideoDriverDX9::draw2DImage( const render::ITexture* texture, const core::position2d<s32>& destPos )
		{

		}

		void CVideoDriverDX9::setMaterial( THIS_ CONST IMaterial& pMaterial )
		{

		}

		bool CVideoDriverDX9::endScene()
		{
			pID3DDevice->EndScene();
			return true;
		}

		bool CVideoDriverDX9::initDriver( const core::dimension2d<u32>& screenSize, HWND hwnd, u32 bits, bool fullScreen, bool pureSoftware, bool highPrecisionFPU, bool vsync, u8 antiAlias )
		{
			DXUTSetCursorSettings( true, true );
			DXUTCreateDevice( !fullScreen, screenSize.Width,screenSize.Height );
			this->pID3D=DXUTGetD3D9Object();
			this->pID3DDevice=DXUTGetD3D9Device();
			pID3DDevice->SetFVF(D3DFVF_XYZ);
			return true;
		}

		void CVideoDriverDX9::setTransform( TRANSFORMSTATETYPE state, const D3DXMATRIXA16& mat )
		{

		}

		void CVideoDriverDX9::setViewPort( const VIEWPORT& area )
		{

		}

		void CVideoDriverDX9::drawPrimitive( PRIMITVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount )
		{
			pID3DDevice->DrawPrimitive(PrimitiveType,StartVertex,PrimitiveCount);
		}

		void CVideoDriverDX9::drawIndexedPrimitiveUP( PRIMITVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,INDEXFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride )
		{

		}

		void CVideoDriverDX9::setFVF( DWORD FVF )
		{
			pID3DDevice->SetFVF(FVF);
		}

	}
}

