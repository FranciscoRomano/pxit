// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#define LOAD_LIBRARY_SYMBOL(Name)\
WGL.Name = (void*)GetProcAddress(WGL.handle, #Name);\
if (!WGL.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct LibraryWGL WGL = { NULL };

void* private_loader_WGL(const char* name)
{
    void* p = (void*)WGL.wglGetProcAddress(name);
    if (p == (void*) 0) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*) 1) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*) 2) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*) 3) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*)-1) return (void*)GetProcAddress(WGL.handle, name);
    return p;
}

bool FreeLibraryWGL()
{
    // check if library was unloaded
    if (!WGL.handle) return false;

    // unload and reset library handle
    WGL.handle = NULL;
    return true;
}

bool LoadLibraryWGL(HINSTANCE hInstance, const char* lpClassName)
{
    // check if library was loaded
    if (WGL.handle) return true;

    // iterate through all library paths
    const char* paths[] = {
        "opengl32.dll",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        WGL.handle = LoadLibraryA(paths[i]);
        if (WGL.handle == NULL) continue;
        LOAD_LIBRARY_SYMBOL(wglCopyContext)
        LOAD_LIBRARY_SYMBOL(wglCreateContext)
        LOAD_LIBRARY_SYMBOL(wglCreateLayerContext)
        LOAD_LIBRARY_SYMBOL(wglDeleteContext)
        LOAD_LIBRARY_SYMBOL(wglDescribeLayerPlane)
        LOAD_LIBRARY_SYMBOL(wglGetCurrentContext)
        LOAD_LIBRARY_SYMBOL(wglGetCurrentDC)
        LOAD_LIBRARY_SYMBOL(wglGetLayerPaletteEntries)
        LOAD_LIBRARY_SYMBOL(wglGetProcAddress)
        LOAD_LIBRARY_SYMBOL(wglMakeCurrent)
        LOAD_LIBRARY_SYMBOL(wglRealizeLayerPalette)
        LOAD_LIBRARY_SYMBOL(wglSetLayerPaletteEntries)
        LOAD_LIBRARY_SYMBOL(wglShareLists)
        LOAD_LIBRARY_SYMBOL(wglSwapLayerBuffers)
        LOAD_LIBRARY_SYMBOL(wglUseFontBitmapsA)
        LOAD_LIBRARY_SYMBOL(wglUseFontBitmapsW)
        LOAD_LIBRARY_SYMBOL(wglUseFontOutlinesA)
        LOAD_LIBRARY_SYMBOL(wglUseFontOutlinesW)

        // create a hidden window for loading WGL
        HWND hWnd = CreateWindowExA(
            0,
            lpClassName,
            "LoadLibraryWGL",
            WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
            0,
            0,
            1,
            1,
            NULL,
            NULL,
            hInstance,
            NULL
        );
        if (!hWnd)
        {
            printf("Failed to create Win32 window\n");
            return false;
        }

        // get the window's device context handle
        HDC hDC = GetDC(hWnd);
        if (!hDC)
        {
            printf("Failed to get window device context\n");
            DestroyWindow(hWnd);
            return false;
        }

        // choose & set the best/default pixel format
        PIXELFORMATDESCRIPTOR pfd;
        memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
        pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType   = PFD_TYPE_RGBA;
        pfd.cColorBits   = 32;
        pfd.cDepthBits   = 24;
        pfd.cStencilBits = 8;    
        int format = ChoosePixelFormat(hDC, &pfd);
        if (format == 0 || SetPixelFormat(hDC, format, &pfd) == FALSE)
        {
            printf("ERROR: failed to set pixel format\n");
            ReleaseDC(hWnd, hDC);
            DestroyWindow(hWnd);
            return false;
        }

        // create WGL context for loading all extensions
        HGLRC hGLRC = WGL.wglCreateContext(hDC);
        if (!hGLRC || !WGL.wglMakeCurrent(hDC, hGLRC))
        {
            printf("ERROR: failed to create WGL context\n");
            if (hGLRC) WGL.wglDeleteContext(hGLRC);
            ReleaseDC(hWnd, hDC);
            DestroyWindow(hWnd);
            return false;
        }
        printf("WARNING: currently no WGL extensions were loaded\n");

        // finally, load the OpenGL ES 3.2 library and symbols
        return LoadLibraryGLES32(private_loader_WGL);
    }
    return false;
}