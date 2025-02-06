// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define module_exit() _FreeModule_wgl(); return false;
#include "module.h"
#define LOAD_REQUIRED_SYMBOL(Name)\
_wgl.Name = _LoadSymbol_wgl(#Name);\
if (!_wgl.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_wgl _wgl = { NULL };
HWND               _wgl_hWnd;
HDC                _wgl_hDC;
HGLRC              _wgl_hGLRC;

void* _LoadSymbol_wgl(const char* name)
{
    void* p = (void*)_opengl32.wglGetProcAddress(name);
    if (p == (void*) 0) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*) 1) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*) 2) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*) 3) return (void*)GetProcAddress(_opengl32.dll, name);
    if (p == (void*)-1) return (void*)GetProcAddress(_opengl32.dll, name);
    return p;
}

bool  _FreeModule_wgl()
{
    // check if module was unloaded
    if (!_wgl.OK) return false;

    // release all allocated resources
    if (_wgl_hGLRC) {
        _opengl32.wglMakeCurrent(_wgl_hDC, NULL);
        _opengl32.wglDeleteContext(_wgl_hGLRC);
    }
    if (_wgl_hDC) _user32.ReleaseDC(_wgl_hWnd, _wgl_hDC);
    if (_wgl_hWnd) _user32.DestroyWindow(_wgl_hWnd);

    // unload module dependencies and reset
    library_free(opengl32);
    library_free(gdi32);
    _wgl_hGLRC = NULL;
    _wgl_hWnd  = NULL;
    _wgl_hDC   = NULL;
    _wgl.OK    = false;
    return true;
}

bool _LoadModule_wgl()
{
    // check if module was loaded
    if (_wgl.OK) return true;

    // load all module dependencies
    module_load(win32)
    library_load(gdi32)
    library_load(opengl32)

    // create a hidden window for loading WGL
    _wgl_hWnd = _user32.CreateWindowExA(
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
    assert(_wgl_hWnd, "failed to create window")

    // get the window's device context handle
    _wgl_hDC = _user32.GetDC(_wgl_hWnd);
    assert(_wgl_hDC, "failed to get device context")

    // choose & set the best/default pixel format
    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;    
    int format = _gdi32.ChoosePixelFormat(_wgl_hDC, &pfd);
    assert(format != 0, "failed to choose pixel format")
    BOOL result1 = _gdi32.SetPixelFormat(_wgl_hDC, format, &pfd);
    assert(result1 == TRUE, "failed to set pixel format")

    // create a WGL context for loading extensions
    _wgl_hGLRC = _opengl32.wglCreateContext(_wgl_hDC);
    assert(_wgl_hGLRC, "failed to create WGL context")
    BOOL result2 = _opengl32.wglMakeCurrent(_wgl_hDC, _wgl_hGLRC);
    assert(result2 == TRUE, "failed to make WGL context current")
    LOAD_REQUIRED_SYMBOL(wglChoosePixelFormatARB)
    LOAD_REQUIRED_SYMBOL(wglGetPixelFormatAttribivARB)
    LOAD_REQUIRED_SYMBOL(wglGetPixelFormatAttribfvARB)

    // load the OpenGL ES library with a custom loader
    bool result3 = _load_gles(_LoadSymbol_wgl);
    assert(result3 == true, "failed to load library 'gles'")

    // cleanup all resources that will no longer be used
    _opengl32.wglMakeCurrent(_wgl_hDC, NULL);
    _opengl32.wglDeleteContext(_wgl_hGLRC);
    _user32.ReleaseDC(_wgl_hWnd, _wgl_hDC);
    _user32.DestroyWindow(_wgl_hWnd);
    _wgl_hGLRC = NULL;
    _wgl_hWnd  = NULL;
    _wgl_hDC   = NULL;
    _wgl.OK    = true;
    return true;
}