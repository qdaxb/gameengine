#include <d3d9.h>
#include "IVideoDriver.h"
namespace mycge{
	namespace render{
		class CVideoDriverDX9:public IVideoDriver{

		private:
			IDirect3D9* pID3D;
			IDirect3DDevice9* pID3DDevice;
		protected:
		public:
			
			virtual void drawIndexedPrimitive( PRIMITVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount ) ;

			virtual bool beginScene( bool backBuffer=true, bool zBuffer=true, SColor color=SColor(255,0,0,0 ) );

			virtual void drawPrimitiveUP( PRIMITVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride ) ;

			virtual const VIEWPORT* getViewPort() const;

			virtual void draw2DImage( const render::ITexture* texture, const core::position2d<s32>& destPos ) ;

			virtual void setMaterial( THIS_ CONST IMaterial& pMaterial ) ;

			virtual bool endScene() ;

			virtual void drawPrimitive( PRIMITVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount ) ;

			virtual void setTransform( TRANSFORMSTATETYPE state, const D3DXMATRIXA16& mat ) ;

			virtual void setViewPort( const VIEWPORT& area ) ;

			virtual void drawIndexedPrimitiveUP( PRIMITVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,INDEXFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride ) ;

			virtual bool initDriver(const core::dimension2d<u32>& screenSize,
				HWND hwnd, u32 bits, bool fullScreen, bool pureSoftware,
				bool highPrecisionFPU, bool vsync, u8 antiAlias);
			virtual void setFVF(DWORD FVF);

		};
	}
}