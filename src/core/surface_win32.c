// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_SURFACE_IMPL(Name, ...)\
if (surface->pfn##Name) { surface->pfn##Name(surface,##__VA_ARGS__); }
#define INVOKE_SURFACE_EVENT(Name, ...)\
if (surface->callbacks.Name) { surface->callbacks.Name(surface,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _FreeContext_OpenGL_Win32(Surface surface)
{
    // unset WGL context
    _WGL.wglMakeCurrent(surface->win32.hDC, NULL);

    // delete the WGL context
    if (!_WGL.wglDeleteContext(surface->win32.hGLRC))
    {
        printf("ERROR: failed to delete WGL context\n");
        return false;
    }

    // release the device context
    if (!ReleaseDC(surface->win32.hWnd, surface->win32.hDC))
    {
        printf("ERROR: failed to release device context\n");
        return false;
    }

    return true;
}

bool _MakeCurrent_OpenGL_Win32(Surface surface)
{
    // make WGL context current
    if (!_WGL.wglMakeCurrent(surface->win32.hDC, surface->win32.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        CloseWindow(surface->win32.hWnd);
        return false;
    }
    return true;
}

bool _SwapBuffers_OpenGL_Win32(Surface surface)
{
    // swap WGL layer buffers
    if (!_WGL.wglSwapLayerBuffers(surface->win32.hDC, WGL_SWAP_MAIN_PLANE))
    {
        printf("ERROR: failed to swap WGL layer buffers\n");
        CloseWindow(surface->win32.hWnd);
        return false;
    }
    return true;
}

bool _InitContext_OpenGL_Win32(Surface surface)
{
    // initialize WGL module
    if (!_LoadModule_WGL()) return false;

    // get window's device context
    surface->win32.hDC = GetDC(surface->win32.hWnd);
    if (!surface->win32.hDC)
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
    int format = ChoosePixelFormat(surface->win32.hDC, &pfd);
    if (format == 0 || SetPixelFormat(surface->win32.hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
        ReleaseDC(surface->win32.hWnd, surface->win32.hDC);
        return false;
    }

    // create a new WGL rendering context
    surface->win32.hGLRC = _WGL.wglCreateContext(surface->win32.hDC);
    if (!surface->win32.hGLRC)
    {
        printf("ERROR: failed to create WGL context\n");
        ReleaseDC(surface->win32.hWnd, surface->win32.hDC);
        return false;
    }

    // make the WGL rendering context current
    if (!_WGL.wglMakeCurrent(surface->win32.hDC, surface->win32.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        _WGL.wglDeleteContext(surface->win32.hGLRC);
        ReleaseDC(surface->win32.hWnd, surface->win32.hDC);
        return false;
    }

    // finalize the WGL initialization and return
    surface->pfnFreeContext = _FreeContext_OpenGL_Win32;
    surface->pfnMakeCurrent = _MakeCurrent_OpenGL_Win32;
    surface->pfnSwapBuffers = _SwapBuffers_OpenGL_Win32;
    INVOKE_SURFACE_EVENT(OnSurfaceCreate)
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateSurface_Win32(const SurfaceCreateInfo* pCreateInfo, Surface surface)
{
    // initialize Win32 module
    if (!_LoadModule_Win32()) return false;

    // adjust area to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE | WS_SIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    surface->win32.hWnd = CreateWindowExA(
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
        (LPVOID)surface
    );
    if (!surface->win32.hWnd)
    {
        printf("ERROR: failed to create Win32 window\n");
        return false;
    }

    // set Win32 callbacks and implementation
    if (pCreateInfo->pCallbacks) memcpy(&surface->callbacks, pCreateInfo->pCallbacks, sizeof(SurfaceCallbacks));
    surface->pfnDestroySurface = _DestroySurface_Win32;

    // initialize the graphics rendering context
    if (_InitContext_OpenGL_Win32(surface)) return true;
    printf("ERROR: failed to create Win32 rendering context\n");
    DestroyWindow(surface->win32.hWnd);
    return false;
}

bool _DestroySurface_Win32(Surface surface)
{
    // destroy context (impl)
    INVOKE_SURFACE_IMPL(FreeContext)

    // destroy the Win32 window
    if (!DestroyWindow(surface->win32.hWnd))
    {
        printf("ERROR: failed to destroy Win32 surface\n");
        return false;
    }

    return true;
}

bool _ReadSurfaceEvents_Win32()
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