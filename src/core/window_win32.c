// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
if (window->pfn##Name) { window->pfn##Name(window,##__VA_ARGS__); }
#define INVOKE_WINDOW_EVENT(Name, ...)\
if (window->callbacks.Name) { window->callbacks.Name(window,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _FreeContext_OpenGL_Win32(Window window)
{
    // unset WGL context
    _opengl32.wglMakeCurrent(window->win32.hDC, NULL);

    // delete the WGL context
    if (!_opengl32.wglDeleteContext(window->win32.hGLRC))
    {
        printf("ERROR: failed to delete WGL context\n");
        return false;
    }

    // release the device context
    if (!_user32.ReleaseDC(window->win32.hWnd, window->win32.hDC))
    {
        printf("ERROR: failed to release device context\n");
        return false;
    }

    return true;
}

bool _MakeCurrent_OpenGL_Win32(Window window)
{
    // make WGL context current
    if (!_opengl32.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        _user32.CloseWindow(window->win32.hWnd);
        return false;
    }
    return true;
}

bool _SwapBuffers_OpenGL_Win32(Window window)
{
    // swap WGL layer buffers
    if (!_opengl32.wglSwapLayerBuffers(window->win32.hDC, WGL_SWAP_MAIN_PLANE))
    {
        printf("ERROR: failed to swap WGL layer buffers\n");
        _user32.CloseWindow(window->win32.hWnd);
        return false;
    }
    return true;
}

bool _InitContext_OpenGL_Win32(Window window)
{
    // initialize WGL module
    if (!_LoadModule_wgl()) return false;

    // get window's device context
    window->win32.hDC = _user32.GetDC(window->win32.hWnd);
    if (!window->win32.hDC)
    {
        printf("ERROR: failed to get device context\n");
        return false;
    }

    // set the window's pixel format
    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    int format = _gdi32.ChoosePixelFormat(window->win32.hDC, &pfd);
    if (format == 0 || _gdi32.SetPixelFormat(window->win32.hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
        _user32.ReleaseDC(window->win32.hWnd, window->win32.hDC);
        return false;
    }

    // create a new WGL rendering context
    window->win32.hGLRC = _opengl32.wglCreateContext(window->win32.hDC);
    if (!window->win32.hGLRC)
    {
        printf("ERROR: failed to create WGL context\n");
        _user32.ReleaseDC(window->win32.hWnd, window->win32.hDC);
        return false;
    }

    // make the WGL rendering context current
    if (!_opengl32.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        _opengl32.wglDeleteContext(window->win32.hGLRC);
        _user32.ReleaseDC(window->win32.hWnd, window->win32.hDC);
        return false;
    }

    // finalize the WGL initialization and return
    window->pfnFreeContext = _FreeContext_OpenGL_Win32;
    window->pfnMakeCurrent = _MakeCurrent_OpenGL_Win32;
    window->pfnSwapBuffers = _SwapBuffers_OpenGL_Win32;
    INVOKE_WINDOW_EVENT(OnWindowCreate)
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_Win32(const WindowCreateInfo* pCreateInfo, Window window)
{
    // initialize Win32 module
    if (!_LoadModule_win32()) return false;

    // adjust area to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE | WS_SIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    _user32.AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    window->win32.hWnd = _user32.CreateWindowExA(
        0,
        _win32.lpClassName,
        pCreateInfo->pTitle,
        dwStyle,
        pCreateInfo->Left + rect.left,
        pCreateInfo->Top + rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        _win32.hInstance,
        (LPVOID)window
    );
    if (!window->win32.hWnd)
    {
        printf("ERROR: failed to create Win32 window\n");
        return false;
    }

    // set Win32 callbacks and implementation
    if (pCreateInfo->pCallbacks) memcpy(&window->callbacks, pCreateInfo->pCallbacks, sizeof(WindowCallbacks));
    window->pfnDestroyWindow = _DestroyWindow_Win32;

    // initialize the graphics rendering context
    if (_InitContext_OpenGL_Win32(window)) return true;
    printf("ERROR: failed to create Win32 rendering context\n");
    _user32.DestroyWindow(window->win32.hWnd);
    return false;
}

bool _DestroyWindow_Win32(Window window)
{
    // destroy context (impl)
    INVOKE_WINDOW_IMPL(FreeContext)

    // destroy the Win32 window
    if (!_user32.DestroyWindow(window->win32.hWnd))
    {
        printf("ERROR: failed to destroy Win32 window\n");
        return false;
    }

    return true;
}

bool _ReadWindowEvents_Win32()
{
    // release the process to the OS for a bit
    Sleep(0);

    // iterate through all queued Win32 messages
    MSG msg;
    while (_user32.PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
    {
        // translate and dispatch the Win32 message
        _user32.TranslateMessage(&msg);
        _user32.DispatchMessageA(&msg);

        // check if Win32 application should be closed
        if (msg.message == WM_QUIT) return false;
    }

    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //