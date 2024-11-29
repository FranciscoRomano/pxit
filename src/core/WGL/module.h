// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_WGL_module_h__
#define __core_WGL_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <GL/wgl.h>
#include <stdbool.h>

/// @brief Represents a WGL module and all supported functions.
extern struct ModuleWGL {    
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

/// @brief Returns true if the WGL module was freed successfully.
bool FreeModuleWGL();

/// @brief Returns true if the WGL module was loaded successfully.
bool LoadModuleWGL();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_WGL_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //