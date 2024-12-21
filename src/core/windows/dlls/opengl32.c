// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "opengl32.h"
#include "kernel32.h"
#include <stdio.h>
#include <stdlib.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
_opengl32.Name = (void*)GetProcAddress(_opengl32.dll, #Name);\
if (!_opengl32.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _opengl32_dll _opengl32 = { NULL };

bool _free_opengl32_dll()
{
    // check if library was unloaded
    if (!_opengl32.dll) return false;

    // unload and reset library handle
    FreeLibrary(_opengl32.dll);
    _opengl32.dll = NULL;
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
        _opengl32.dll = LoadLibraryA(paths[i]);
        if (_opengl32.dll == NULL) continue;
        LOAD_REQUIRED_SYMBOL(wglCopyContext)
        LOAD_REQUIRED_SYMBOL(wglCreateContext)
        LOAD_REQUIRED_SYMBOL(wglCreateLayerContext)
        LOAD_REQUIRED_SYMBOL(wglDeleteContext)
        LOAD_REQUIRED_SYMBOL(wglDescribeLayerPlane)
        LOAD_REQUIRED_SYMBOL(wglGetCurrentContext)
        LOAD_REQUIRED_SYMBOL(wglGetCurrentDC)
        LOAD_REQUIRED_SYMBOL(wglGetLayerPaletteEntries)
        LOAD_REQUIRED_SYMBOL(wglGetProcAddress)
        LOAD_REQUIRED_SYMBOL(wglMakeCurrent)
        LOAD_REQUIRED_SYMBOL(wglRealizeLayerPalette)
        LOAD_REQUIRED_SYMBOL(wglSetLayerPaletteEntries)
        LOAD_REQUIRED_SYMBOL(wglShareLists)
        LOAD_REQUIRED_SYMBOL(wglSwapLayerBuffers)
        LOAD_REQUIRED_SYMBOL(wglUseFontBitmapsA)
        LOAD_REQUIRED_SYMBOL(wglUseFontBitmapsW)
        LOAD_REQUIRED_SYMBOL(wglUseFontOutlinesA)
        LOAD_REQUIRED_SYMBOL(wglUseFontOutlinesW)
        return true;
    }
    return false;
}