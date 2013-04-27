/********************************************************************
	created:	2011/06/30
	created:	30:6:2011   9:47
	file base:	IVideoDriver
	file ext:	h
	author:		axb
	
	purpose:	videodriver接口，封装视频相关操作
*********************************************************************/
#ifndef _IVIDEODRIVER_H_
#define _IVIDEODRIVER_H_

#include "position2d.h"
#include "SColor.h"
#include <d3dx9math.h>
#include <d3d9types.h>

namespace mycge{
	namespace render{
		typedef enum _TRANSFORMSTATETYPE {
			TS_VIEW          = 2,
			TS_PROJECTION    = 3,
			TS_TEXTURE0      = 16,
			TS_TEXTURE1      = 17,
			TS_TEXTURE2      = 18,
			TS_TEXTURE3      = 19,
			TS_TEXTURE4      = 20,
			TS_TEXTURE5      = 21,
			TS_TEXTURE6      = 22,
			TS_TEXTURE7      = 23,
			TS_FORCE_DWORD     = 0x7fffffff, /* force 32-bit size enum */
		} TRANSFORMSTATETYPE;

		typedef D3DVIEWPORT9 VIEWPORT  ;
		typedef D3DPRIMITIVETYPE PRIMITVETYPE ;
		typedef D3DFORMAT INDEXFORMAT ;
		typedef D3DMATERIAL9 IMaterial ;
		typedef D3DXMATRIXA16 MATRIXA16 ;
		typedef IDirect3DBaseTexture9 ITexture ;
		typedef IDirect3DVertexBuffer9 IVertexBuffer;
		class IVideoDriver{
		public:
			virtual bool beginScene(bool backBuffer=true, bool zBuffer=true,SColor color=SColor(255,0,0,0)) =0;
			virtual bool endScene() =0;
			virtual void setTransform(TRANSFORMSTATETYPE state, const MATRIXA16& mat) =0;
			virtual void setMaterial(THIS_ CONST IMaterial& pMaterial) =0;
			virtual void setViewPort(const VIEWPORT& area) =0;
			virtual const VIEWPORT* getViewPort() const =0;
			virtual void drawPrimitive(PRIMITVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)=0;
			virtual void drawIndexedPrimitive(PRIMITVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)=0;
			virtual void drawPrimitiveUP(PRIMITVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)=0;
			virtual void drawIndexedPrimitiveUP(PRIMITVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,INDEXFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)= 0;
			virtual void draw2DImage(const render::ITexture* texture,
				const core::position2d<s32>& destPos) =0;
			virtual void setFVF(DWORD FVF)=0;
			virtual void CreateVertexBuffer(UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IVertexBuffer** ppVertexBuffer,HANDLE* pSharedHandle)=0;
		};
	}
}
#endif // _IVIDEODRIVER_H_