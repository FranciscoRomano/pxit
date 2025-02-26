// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _opengl32
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _opengl32_dll _opengl32 = { NULL };

bool _free_opengl32_dll()
{
    // check if library was unloaded
    if (!_opengl32.dll) return true;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
    return true;
}

bool _load_opengl32_dll()
{
    // check if library was loaded
    if (_opengl32.dll) return true;

    // iterate through all library paths
    const char* paths[] = { "opengl32.dll", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        LIBRARY_MODULE_LOAD(paths[i])
        LIBRARY_MODULE_RSYM(wglCopyContext)
        LIBRARY_MODULE_RSYM(wglCreateContext)
        LIBRARY_MODULE_RSYM(wglCreateLayerContext)
        LIBRARY_MODULE_RSYM(wglDeleteContext)
        LIBRARY_MODULE_RSYM(wglDescribeLayerPlane)
        LIBRARY_MODULE_RSYM(wglGetCurrentContext)
        LIBRARY_MODULE_RSYM(wglGetCurrentDC)
        LIBRARY_MODULE_RSYM(wglGetLayerPaletteEntries)
        LIBRARY_MODULE_RSYM(wglGetProcAddress)
        LIBRARY_MODULE_RSYM(wglMakeCurrent)
        LIBRARY_MODULE_RSYM(wglRealizeLayerPalette)
        LIBRARY_MODULE_RSYM(wglSetLayerPaletteEntries)
        LIBRARY_MODULE_RSYM(wglShareLists)
        LIBRARY_MODULE_RSYM(wglSwapLayerBuffers)
        LIBRARY_MODULE_RSYM(wglUseFontBitmapsA)
        LIBRARY_MODULE_RSYM(wglUseFontBitmapsW)
        LIBRARY_MODULE_RSYM(wglUseFontOutlinesA)
        LIBRARY_MODULE_RSYM(wglUseFontOutlinesW)
        return true;
    }
    return false;
}