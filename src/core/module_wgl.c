// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define LOAD_REQUIRED_SYMBOL(Name)\
_WGL.Name = (void*)GetProcAddress(_WGL.handle, #Name);\
if (!_WGL.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_WGL _WGL = { NULL };

void* _Loader_WGL(const char* name)
{
    void* p = (void*)_WGL.wglGetProcAddress(name);
    if (p == (void*) 0) return (void*)GetProcAddress(_WGL.handle, name);
    if (p == (void*) 1) return (void*)GetProcAddress(_WGL.handle, name);
    if (p == (void*) 2) return (void*)GetProcAddress(_WGL.handle, name);
    if (p == (void*) 3) return (void*)GetProcAddress(_WGL.handle, name);
    if (p == (void*)-1) return (void*)GetProcAddress(_WGL.handle, name);
    return p;
}

bool _FreeModule_WGL()
{
    // check if module was unloaded
    if (!_WGL.handle) return false;

    // unload and reset module handle
    _WGL.handle = NULL;
    return true;
}

bool _LoadModule_WGL()
{
    // check if module was loaded
    if (_WGL.handle) return true;

    // load all module dependencies
    if (!_LoadModule_Win32())
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
        _WGL.handle = LoadLibraryA(paths[i]);
        if (_WGL.handle == NULL) continue;
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
            _Win32.lpClassName,
            "LoadModuleWGL",
            WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
            0,
            0,
            1,
            1,
            NULL,
            NULL,
            _Win32.hInstance,
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
        HGLRC hGLRC = _WGL.wglCreateContext(hDC);
        if (!hGLRC || !_WGL.wglMakeCurrent(hDC, hGLRC))
        {
            printf("ERROR: failed to create WGL context\n");
            if (hGLRC) _WGL.wglDeleteContext(hGLRC);
            ReleaseDC(hWnd, hDC);
            DestroyWindow(hWnd);
            return false;
        }
        printf("WARNING: skipping WGL extensions\n");

        // load the OpenGL ES module with a custom loader
        if (!_LoadModule_GLES(_Loader_WGL))
        {
            printf("ERROR: failed to load GLES module\n");
            _WGL.wglMakeCurrent(hDC, NULL);
            _WGL.wglDeleteContext(hGLRC);
            ReleaseDC(hWnd, hDC);
            DestroyWindow(hWnd);
            return false;
        }

        // cleanup all resources that will no longer be used
        _WGL.wglMakeCurrent(hDC, NULL);
        _WGL.wglDeleteContext(hGLRC);
        ReleaseDC(hWnd, hDC);
        DestroyWindow(hWnd);
        return true;
    }
    return false;
}