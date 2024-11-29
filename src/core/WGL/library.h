// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_WGL_library_h__
#define __core_WGL_library_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "../GLES3/library.h"
#include <GL/wgl.h>
#include <stdbool.h>

/// @brief Represents the WGL library and supported functions.
extern struct LibraryWGL {    
    void*                            handle;
    PFNWGLCOPYCONTEXTPROC            wglCopyContext;
    PFNWGLCREATECONTEXTPROC          wglCreateContext;
    PFNWGLCREATELAYERCONTEXTPROC     wglCreateLayerContext;
    PFNWGLDELETECONTEXTPROC          wglDeleteContext;
    PFNWGLDESCRIBELAYERPLANEPROC     wglDescribeLayerPlane;
    PFNWGLGETCURRENTCONTEXTPROC      wglGetCurrentContext;
    PFNWGLGETCURRENTDCPROC           wglGetCurrentDC;
    PFNWGLGETLAYERPALETTEENTRIESPROC wglGetLayerPaletteEntries;
    PFNWGLGETPROCADDRESSPROC         wglGetProcAddress;
    PFNWGLMAKECURRENTPROC            wglMakeCurrent;
    PFNWGLREALIZELAYERPALETTEPROC    wglRealizeLayerPalette;
    PFNWGLSETLAYERPALETTEENTRIESPROC wglSetLayerPaletteEntries;
    PFNWGLSHARELISTSPROC             wglShareLists;
    PFNWGLSWAPLAYERBUFFERSPROC       wglSwapLayerBuffers;
    PFNWGLUSEFONTBITMAPSAPROC        wglUseFontBitmapsA;
    PFNWGLUSEFONTBITMAPSWPROC        wglUseFontBitmapsW;
    PFNWGLUSEFONTOUTLINESAPROC       wglUseFontOutlinesA;
    PFNWGLUSEFONTOUTLINESWPROC       wglUseFontOutlinesW;
} WGL;

/// @brief Returns true if the WGL library was freed successfully.
bool FreeLibraryWGL();

/// @brief Returns true if the WGL library was loaded successfully.
bool LoadLibraryWGL(HINSTANCE hInstance, const char* lpClassName);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_WGL_library_h__
// -------------------------------------------------------------------------------------------------------------------------- //