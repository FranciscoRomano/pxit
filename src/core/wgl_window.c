// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_wgl(const WindowCreateInfo* pCreateInfo, Window window)
{
    // load all module dependencies
    if (!_LoadModule_wgl()) return false;

    // get the window's device context
    window->win32.hDC = _user32.GetDC(window->win32.hWnd);
    assert(window->win32.hDC, "failed to get device context")

    // set window's default pixel format
    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    int format = _gdi32.ChoosePixelFormat(window->win32.hDC, &pfd);
    assert(format != 0, "failed to choose pixel format")
    BOOL result1 = _gdi32.SetPixelFormat(window->win32.hDC, format, &pfd);
    assert(result1 == TRUE, "failed to set pixel format")

    // create a new WGL rendering context
    window->win32.hGLRC = _opengl32.wglCreateContext(window->win32.hDC);
    assert(window->win32.hGLRC, "failed to create WGL context")
    window->impl.DestroyWindow = _DestroyWindow_wgl;
    window->impl.DrawWindow = _DrawWindow_wgl;
    return true;
}

bool _DestroyWindow_wgl(Window window)
{
    // destroy the WGL rendering context and resources
    if (window->win32.hGLRC) {
        _opengl32.wglMakeCurrent(window->win32.hDC, NULL);
        _opengl32.wglDeleteContext(window->win32.hGLRC);
    }
    if (window->win32.hDC) _user32.ReleaseDC(window->win32.hWnd, window->win32.hDC);
    return _DestroyWindow_win32(window);
}

bool _DrawWindow_wgl(Window window)
{
    // set WGL rendering context as current.
    BOOL result = _opengl32.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC);
    assert(result == TRUE, "failed to set WGL rendering context as current")

    WINDOW_EVENT(OnWindowDraw)
    glFlush();

    _opengl32.wglSwapLayerBuffers(window->win32.hDC, WGL_SWAP_MAIN_PLANE);
}