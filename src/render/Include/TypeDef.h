/********************************************************************
	created:	2011/06/30
	created:	30:6:2011   10:19
	file base:	typeDef
	file ext:	h
	author:		axb
	
	purpose:	类型定义
*********************************************************************/

#ifndef __TYPEDEF_H_INCLUDED__
#define __TYPEDEF_H_INCLUDED__


namespace mycge
{

//! 8 bit unsigned variable.
/** This is a typedef for unsigned char, it ensures portability of the engine. */
#ifdef _MSC_VER
typedef unsigned __int8		us8;
#else
typedef unsigned char		us8;
#endif

//! 8 bit signed variable.
/** This is a typedef for signed char, it ensures portability of the engine. */
#ifdef _MSC_VER
typedef __int8			s8;
#else
typedef signed char		s8;
#endif

//! 8 bit character variable.
/** This is a typedef for char, it ensures portability of the engine. */
typedef char			c8;



//! 16 bit unsigned variable.
/** This is a typedef for unsigned short, it ensures portability of the engine. */
#ifdef _MSC_VER
typedef unsigned __int16	us16;
#else
typedef unsigned short		us16;
#endif

//! 16 bit signed variable.
/** This is a typedef for signed short, it ensures portability of the engine. */
#ifdef _MSC_VER
typedef __int16			s16;
#else
typedef signed short		s16;
#endif



//! 32 bit unsigned variable.
/** This is a typedef for unsigned int, it ensures portability of the engine. */
#ifdef _MSC_VER
typedef unsigned __int32	us32;
#else
typedef unsigned int		us32;
#endif

//! 32 bit signed variable.
/** This is a typedef for signed int, it ensures portability of the engine. */
#ifdef _MSC_VER
typedef __int32			s32;
#else
typedef signed int		s32;
#endif



// 64 bit signed variable.
// This is a typedef for __int64, it ensures portability of the engine.
// This type is currently not used by the engine and not supported by compilers
// other than Microsoft Compilers, so it is outcommented.
//typedef __int64				s64;

typedef us16 u16;
typedef us32 u32;
typedef us8 u8;

//! 32 bit floating point variable.
/** This is a typedef for float, it ensures portability of the engine. */
typedef float				f32;

//! 64 bit floating point variable.
/** This is a typedef for double, it ensures portability of the engine. */
typedef double				d64;
typedef double f64;

} // end namespace irr

#endif 