// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define LOAD_REQUIRED_SYMBOL(Name)\
_wgl.Name = (void*)GetProcAddress(_wgl.handle, #Name);\
if (!_wgl.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_wgl _wgl = { NULL };

void* _Loader_WGL(const char* name)
{
    void* p = (void*)_opengl32.wglGetProcAddress(name);
    if (p == (void*) 0) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*) 1) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*) 2) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*) 3) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*)-1) return (void*)GetProcAddress(_opengl32.dll, name);
    return p;
}

bool _FreeModule_wgl()
{
    // check if module was unloaded
    if (!_wgl.OK) return false;

    // unload and reset module handle
    _free_opengl32_dll();
    _free_gdi32_dll();
    _wgl.OK = false;
    return true;
}

bool _LoadModule_wgl()
{
    // check if module was loaded
    if (_wgl.OK) return true;

    // load all module dependencies
    if (!_win32.OK)
    {
        printf("ERROR: unitialized module 'Win32'\n");
        return false;
    }
    if (!_load_gdi32_dll())
    {
        printf("ERROR: failed to load library 'gdi32.dll'\n");
        return false;
    }
    if (!_load_opengl32_dll())
    {
        printf("ERROR: failed to load library 'opengl32.dll'\n");
        _free_gdi32_dll();
        return false;
    }

    // create a hidden window for loading WGL
    HWND hWnd = _user32.CreateWindowExA(
        0,
        _win32.lpClassName,
        "LoadModuleWGL",
        WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
        0,
        0,
        1,
        1,
        NULL,
        NULL,
        _win32.hInstance,
        NULL
    );
    if (!hWnd)
    {
        printf("ERROR: failed to create window\n");
        _free_opengl32_dll();
        _free_gdi32_dll();
        return false;
    }

    // get the window's device context handle
    HDC hDC = _user32.GetDC(hWnd);
    if (!hDC)
    {
        printf("ERROR: failed to get device context\n");
        _user32.DestroyWindow(hWnd);
        _free_opengl32_dll();
        _free_gdi32_dll();
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
    int format = _gdi32.ChoosePixelFormat(hDC, &pfd);
    if (format == 0 || _gdi32.SetPixelFormat(hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
        _user32.ReleaseDC(hWnd, hDC);
        _user32.DestroyWindow(hWnd);
        _free_opengl32_dll();
        _free_gdi32_dll();
        return false;
    }

    // create WGL context for loading all extensions
    HGLRC hGLRC = _opengl32.wglCreateContext(hDC);
    if (!hGLRC || !_opengl32.wglMakeCurrent(hDC, hGLRC))
    {
        printf("ERROR: failed to create WGL context\n");
        if (hGLRC) _opengl32.wglDeleteContext(hGLRC);
        _user32.ReleaseDC(hWnd, hDC);
        _user32.DestroyWindow(hWnd);
        _free_opengl32_dll();
        _free_gdi32_dll();
        return false;
    }
    printf("WARNING: skipping WGL extensions\n");

    // load the OpenGL ES library with a custom loader
    if (!_LoadLibrary_gles(_Loader_WGL))
    {
        printf("ERROR: failed to load library 'gles'\n");
        _opengl32.wglMakeCurrent(hDC, NULL);
        _opengl32.wglDeleteContext(hGLRC);
        _user32.ReleaseDC(hWnd, hDC);
        _user32.DestroyWindow(hWnd);
        _free_opengl32_dll();
        _free_gdi32_dll();
        return false;
    }

    // cleanup all resources that will no longer be used
    _opengl32.wglMakeCurrent(hDC, NULL);
    _opengl32.wglDeleteContext(hGLRC);
    _user32.ReleaseDC(hWnd, hDC);
    _user32.DestroyWindow(hWnd);
    return true;
}