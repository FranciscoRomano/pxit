// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "../Win32/module.h"
#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
WGL.Name = (void*)GetProcAddress(WGL.handle, #Name);\
if (!WGL.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct ModuleWGL WGL = { NULL };

void* _LoaderWGL(const char* name)
{
    void* p = (void*)WGL.wglGetProcAddress(name);
    if (p == (void*) 0) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*) 1) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*) 2) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*) 3) return (void*)GetProcAddress(WGL.handle, name);
    if (p == (void*)-1) return (void*)GetProcAddress(WGL.handle, name);
    return p;
}

bool FreeModuleWGL()
{
    // check if module was unloaded
    if (!WGL.handle) return false;

    // unload and reset module handle
    WGL.handle = NULL;
    return true;
}

bool LoadModuleWGL()
{
    // check if module was loaded
    if (WGL.handle) return true;

    // load all module dependencies
    if (!LoadModuleWin32())
    {
        printf("ERROR: failed to load Win32 module\n");
        return false;
    }

    // iterate through all module paths
    const char* paths[] = {
        "opengl32.dll",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading module and any symbols
        WGL.handle = LoadLibraryA(paths[i]);
        if (WGL.handle == NULL) continue;
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

        // create a hidden window for loading WGL
        HWND hWnd = CreateWindowExA(
            0,
            Win32.lpClassName,
            "LoadLibraryWGL",
            WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
            0,
            0,
            1,
            1,
            NULL,
            NULL,
            Win32.hInstance,
            NULL
        );
        if (!hWnd)
        {
            printf("ERROR: failed to create window\n");
            return false;
        }

        // get the window's device context handle
        HDC hDC = GetDC(hWnd);
        if (!hDC)
        {
            printf("ERROR: failed to get device context\n");
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
        printf("WARNING: skipping WGL extensions\n");

        // load the OpenGL ES module with a custom loader
        if (!LoadModuleGLES(_LoaderWGL))
        {
            printf("ERROR: failed to load GLES module\n");
            WGL.wglMakeCurrent(hDC, NULL);
            WGL.wglDeleteContext(hGLRC);
            ReleaseDC(hWnd, hDC);
            DestroyWindow(hWnd);
            return false;
        }

        // cleanup all resources that will no longer be used
        WGL.wglMakeCurrent(hDC, NULL);
        WGL.wglDeleteContext(hGLRC);
        ReleaseDC(hWnd, hDC);
        DestroyWindow(hWnd);
        return true;
    }
    return false;
}