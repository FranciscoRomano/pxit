// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_library_opengl32_h__
#define __core_library_opengl32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <GLES3/gl32.h>
#include <GL/wgl.h>
#include <stdbool.h>

/// @brief Represents the "opengl32.dll" library and supported functions.
extern struct _Library_opengl32 {    
    void* dll;
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
} _opengl32;

/// @brief Returns true if the "opengl32.dll" library was freed successfully.
bool _FreeLibrary_opengl32();

/// @brief Returns true if the "opengl32.dll" library was loaded successfully.
bool _LoadLibrary_opengl32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_library_opengl32_h__
// -------------------------------------------------------------------------------------------------------------------------- //