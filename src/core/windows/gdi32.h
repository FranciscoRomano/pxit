// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_windows_gdi32_h__
#define __core_windows_gdi32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>
#include <stdbool.h>

#define PFD_TYPE_RGBA             0
#define PFD_TYPE_COLORINDEX       1
#define PFD_MAIN_PLANE            0
#define PFD_OVERLAY_PLANE         1
#define PFD_UNDERLAY_PLANE        (-1)
#define PFD_DOUBLEBUFFER          0x00000001
#define PFD_STEREO                0x00000002
#define PFD_DRAW_TO_WINDOW        0x00000004
#define PFD_DRAW_TO_BITMAP        0x00000008
#define PFD_SUPPORT_GDI           0x00000010
#define PFD_SUPPORT_OPENGL        0x00000020
#define PFD_GENERIC_FORMAT        0x00000040
#define PFD_NEED_PALETTE          0x00000080
#define PFD_NEED_SYSTEM_PALETTE   0x00000100
#define PFD_SWAP_EXCHANGE         0x00000200
#define PFD_SWAP_COPY             0x00000400
#define PFD_SWAP_LAYER_BUFFERS    0x00000800
#define PFD_GENERIC_ACCELERATED   0x00001000
#define PFD_SUPPORT_DIRECTDRAW    0x00002000
#define PFD_DIRECT3D_ACCELERATED  0x00004000
#define PFD_SUPPORT_COMPOSITION   0x00008000
#define PFD_DEPTH_DONTCARE        0x20000000
#define PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#define PFD_STEREO_DONTCARE       0x80000000

// [Windows] Pixel format descriptor
typedef struct {
    WORD  nSize;
    WORD  nVersion;
    DWORD dwFlags;
    BYTE  iPixelType;
    BYTE  cColorBits;
    BYTE  cRedBits;
    BYTE  cRedShift;
    BYTE  cGreenBits;
    BYTE  cGreenShift;
    BYTE  cBlueBits;
    BYTE  cBlueShift;
    BYTE  cAlphaBits;
    BYTE  cAlphaShift;
    BYTE  cAccumBits;
    BYTE  cAccumRedBits;
    BYTE  cAccumGreenBits;
    BYTE  cAccumBlueBits;
    BYTE  cAccumAlphaBits;
    BYTE  cDepthBits;
    BYTE  cStencilBits;
    BYTE  cAuxBuffers;
    BYTE  iLayerType;
    BYTE  bReserved;
    DWORD dwLayerMask;
    DWORD dwVisibleMask;
    DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR;

/// @brief Represents the "gdi32.dll" library and supported functions.
extern struct _gdi32_dll {
    void* dll;
    int     WINAPI (*ChoosePixelFormat)(HDC,const PIXELFORMATDESCRIPTOR*);
    int     WINAPI (*DescribePixelFormat)(HDC,int,UINT,PIXELFORMATDESCRIPTOR*);
    UINT    WINAPI (*GetEnhMetaFilePixelFormat)(HENHMETAFILE,UINT,PIXELFORMATDESCRIPTOR*);
    int     WINAPI (*GetPixelFormat)(HDC);
    BOOL    WINAPI (*SetPixelFormat)(HDC,int,const PIXELFORMATDESCRIPTOR*);
    BOOL    WINAPI (*SwapBuffers)(HDC);
} _gdi32;

/// @brief Returns true if the "gdi32.dll" library was freed successfully.
bool _free_gdi32_dll();

/// @brief Returns true if the "gdi32.dll" library was loaded successfully.
bool _load_gdi32_dll();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_windows_gdi32_h__
// -------------------------------------------------------------------------------------------------------------------------- //