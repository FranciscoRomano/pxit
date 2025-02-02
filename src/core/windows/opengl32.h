// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_windows_opengl32_h__
#define __core_windows_opengl32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>
#include <stdbool.h>

#define WGL_FONT_LINES      0
#define WGL_FONT_POLYGONS   1
#define WGL_SWAP_MAIN_PLANE 0x00000001
#define WGL_SWAP_OVERLAY1   0x00000002
#define WGL_SWAP_OVERLAY2   0x00000004
#define WGL_SWAP_OVERLAY3   0x00000008
#define WGL_SWAP_OVERLAY4   0x00000010
#define WGL_SWAP_OVERLAY5   0x00000020
#define WGL_SWAP_OVERLAY6   0x00000040
#define WGL_SWAP_OVERLAY7   0x00000080
#define WGL_SWAP_OVERLAY8   0x00000100
#define WGL_SWAP_OVERLAY9   0x00000200
#define WGL_SWAP_OVERLAY10  0x00000400
#define WGL_SWAP_OVERLAY11  0x00000800
#define WGL_SWAP_OVERLAY12  0x00001000
#define WGL_SWAP_OVERLAY13  0x00002000
#define WGL_SWAP_OVERLAY14  0x00004000
#define WGL_SWAP_OVERLAY15  0x00008000
#define WGL_SWAP_UNDERLAY1  0x00010000
#define WGL_SWAP_UNDERLAY2  0x00020000
#define WGL_SWAP_UNDERLAY3  0x00040000
#define WGL_SWAP_UNDERLAY4  0x00080000
#define WGL_SWAP_UNDERLAY5  0x00100000
#define WGL_SWAP_UNDERLAY6  0x00200000
#define WGL_SWAP_UNDERLAY7  0x00400000
#define WGL_SWAP_UNDERLAY8  0x00800000
#define WGL_SWAP_UNDERLAY9  0x01000000
#define WGL_SWAP_UNDERLAY10 0x02000000
#define WGL_SWAP_UNDERLAY11 0x04000000
#define WGL_SWAP_UNDERLAY12 0x08000000
#define WGL_SWAP_UNDERLAY13 0x10000000
#define WGL_SWAP_UNDERLAY14 0x20000000
#define WGL_SWAP_UNDERLAY15 0x40000000

/// @brief [Windows] Point float
typedef struct {
    FLOAT x;
    FLOAT y;
} POINTFLOAT;

/// @brief [Windows] Glyph metrics float
typedef struct {
    FLOAT      gmfBlackBoxX;
    FLOAT      gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT      gmfCellIncX;
    FLOAT      gmfCellIncY;
} GLYPHMETRICSFLOAT;

/// @brief [opengl32.dll] Layer plane descriptor
typedef struct {
    WORD     nSize;
    WORD     nVersion;
    DWORD    dwFlags;
    BYTE     iPixelType;
    BYTE     cColorBits;
    BYTE     cRedBits;
    BYTE     cRedShift;
    BYTE     cGreenBits;
    BYTE     cGreenShift;
    BYTE     cBlueBits;
    BYTE     cBlueShift;
    BYTE     cAlphaBits;
    BYTE     cAlphaShift;
    BYTE     cAccumBits;
    BYTE     cAccumRedBits;
    BYTE     cAccumGreenBits;
    BYTE     cAccumBlueBits;
    BYTE     cAccumAlphaBits;
    BYTE     cDepthBits;
    BYTE     cStencilBits;
    BYTE     cAuxBuffers;
    BYTE     iLayerPlane;
    BYTE     bReserved;
    COLORREF crTransparent;
} LAYERPLANEDESCRIPTOR;

/// @brief Represents the "opengl32.dll" library and supported functions.
extern struct _opengl32_dll {    
    void* dll;
    BOOL  WINAPI (*wglCopyContext)(HGLRC,HGLRC,UINT);
    HGLRC WINAPI (*wglCreateContext)(HDC);
    HGLRC WINAPI (*wglCreateLayerContext)(HDC,int);
    BOOL  WINAPI (*wglDeleteContext)(HGLRC);
    BOOL  WINAPI (*wglDescribeLayerPlane)(HDC,int,int,UINT,LAYERPLANEDESCRIPTOR*);
    HGLRC WINAPI (*wglGetCurrentContext)(void);
    HDC   WINAPI (*wglGetCurrentDC)(void);
    int   WINAPI (*wglGetLayerPaletteEntries)(HDC,int,int,int,COLORREF*);
    PROC  WINAPI (*wglGetProcAddress)(LPCSTR);
    BOOL  WINAPI (*wglMakeCurrent)(HDC,HGLRC);
    BOOL  WINAPI (*wglRealizeLayerPalette)(HDC,int,BOOL);
    int   WINAPI (*wglSetLayerPaletteEntries)(HDC,int,int,int,const COLORREF*);
    BOOL  WINAPI (*wglShareLists)(HGLRC,HGLRC);
    BOOL  WINAPI (*wglSwapLayerBuffers)(HDC,UINT);
    BOOL  WINAPI (*wglUseFontBitmapsA)(HDC,DWORD,DWORD,DWORD);
    BOOL  WINAPI (*wglUseFontBitmapsW)(HDC,DWORD,DWORD,DWORD);
    BOOL  WINAPI (*wglUseFontOutlinesA)(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,int,GLYPHMETRICSFLOAT*);
    BOOL  WINAPI (*wglUseFontOutlinesW)(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,int,GLYPHMETRICSFLOAT*);
} _opengl32;

/// @brief Returns true if the "opengl32.dll" library was freed successfully.
bool _free_opengl32_dll();

/// @brief Returns true if the "opengl32.dll" library was loaded successfully.
bool _load_opengl32_dll();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_windows_opengl32_h__
// -------------------------------------------------------------------------------------------------------------------------- //