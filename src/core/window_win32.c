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
    _WGL.wglMakeCurrent(window->win32.hDC, NULL);

    // delete the WGL context
    if (!_WGL.wglDeleteContext(window->win32.hGLRC))
    {
        printf("ERROR: failed to delete WGL context\n");
        return false;
    }

    // release the device context
    if (!ReleaseDC(window->win32.hWnd, window->win32.hDC))
    {
        printf("ERROR: failed to release device context\n");
        return false;
    }

    return true;
}

bool _MakeCurrent_OpenGL_Win32(Window window)
{
    // make WGL context current
    if (!_WGL.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        CloseWindow(window->win32.hWnd);
        return false;
    }
    return true;
}

bool _SwapBuffers_OpenGL_Win32(Window window)
{
    // swap WGL layer buffers
    if (!_WGL.wglSwapLayerBuffers(window->win32.hDC, WGL_SWAP_MAIN_PLANE))
    {
        printf("ERROR: failed to swap WGL layer buffers\n");
        CloseWindow(window->win32.hWnd);
        return false;
    }
    return true;
}

bool _InitContext_OpenGL_Win32(Window window)
{
    // initialize WGL module
    if (!_LoadModule_WGL()) return false;

    // get window's device context
    window->win32.hDC = GetDC(window->win32.hWnd);
    if (!window->win32.hDC)
    {
        printf("ERROR: failed to get device context\n");
        return false;
    }

    // set the window's pixel format
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    int format = ChoosePixelFormat(window->win32.hDC, &pfd);
    if (format == 0 || SetPixelFormat(window->win32.hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
        ReleaseDC(window->win32.hWnd, window->win32.hDC);
        return false;
    }

    // create a new WGL rendering context
    window->win32.hGLRC = _WGL.wglCreateContext(window->win32.hDC);
    if (!window->win32.hGLRC)
    {
        printf("ERROR: failed to create WGL context\n");
        ReleaseDC(window->win32.hWnd, window->win32.hDC);
        return false;
    }

    // make the WGL rendering context current
    if (!_WGL.wglMakeCurrent(window->win32.hDC, window->win32.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        _WGL.wglDeleteContext(window->win32.hGLRC);
        ReleaseDC(window->win32.hWnd, window->win32.hDC);
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
    if (!_LoadModule_Win32()) return false;

    // adjust area to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE | WS_SIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    window->win32.hWnd = CreateWindowExA(
        0,
        _Win32.lpClassName,
        pCreateInfo->pTitle,
        dwStyle,
        pCreateInfo->Left + rect.left,
        pCreateInfo->Top + rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        _Win32.hInstance,
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
    DestroyWindow(window->win32.hWnd);
    return false;
}

bool _DestroyWindow_Win32(Window window)
{
    // destroy context (impl)
    INVOKE_WINDOW_IMPL(FreeContext)

    // destroy the Win32 window
    if (!DestroyWindow(window->win32.hWnd))
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
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
    {
        // translate and dispatch the Win32 message
        TranslateMessage(&msg);
        DispatchMessageA(&msg);

        // check if Win32 application should be closed
        if (msg.message == WM_QUIT) return false;
    }

    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //