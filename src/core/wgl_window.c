// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
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
    int format;
    int formats;
    int attribs[] = {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_DEPTH_BITS_ARB, 24,
        WGL_STENCIL_BITS_ARB, 8,
        WGL_ALPHA_BITS_ARB, 8,
        WGL_TRANSPARENT_ARB, GL_TRUE,
        0
    };
    BOOL result1 = _wgl.wglChoosePixelFormatARB(window->win32.hDC, attribs, NULL, 1, &format, &formats);
    assert(result1 == TRUE && formats > 0, "failed to choose pixel format");
    PIXELFORMATDESCRIPTOR pfd;
    _gdi32.DescribePixelFormat(window->win32.hDC, format, sizeof(pfd), &pfd);
    BOOL result2 = _gdi32.SetPixelFormat(window->win32.hDC, format, &pfd);
    assert(result2 == TRUE, "failed to set pixel format");

    // create a new WGL rendering context
    window->win32.hGLRC = _opengl32.wglCreateContext(window->win32.hDC);
    assert(window->win32.hGLRC, "failed to create WGL context")
    _opengl32.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC);
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
    // set WGL rendering context as current
    BOOL result = _opengl32.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC);
    assert(result == TRUE, "failed to set WGL rendering context as current")

    // invoke "OnWindowDraw" event and flush
    WINDOW_EVENT(OnWindowDraw)
    glFlush();

    // swap the back buffer with the main buffer
    _opengl32.wglSwapLayerBuffers(window->win32.hDC, WGL_SWAP_MAIN_PLANE);
    return true;
}