// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool _MakeCurrent_OpenGL_win32(Window window)
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

bool _SwapBuffers_OpenGL_win32(Window window)
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

// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_win32(const WindowCreateInfo* pCreateInfo, Window window)
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
    if (pCreateInfo->pEvents) memcpy(&window->event, pCreateInfo->pEvents, sizeof(WindowEvents));
    window->impl.DestroyWindow = _DestroyWindow_win32;

    // initialize the graphics rendering context
    if (_CreateWindow_wgl(pCreateInfo, window)) return true;
    printf("ERROR: failed to create Win32 rendering context\n");
    _user32.DestroyWindow(window->win32.hWnd);
    return false;
}

bool _DestroyWindow_win32(Window window)
{
    // destroy the Win32 window
    if (!_user32.DestroyWindow(window->win32.hWnd))
    {
        printf("ERROR: failed to destroy Win32 window\n");
        return false;
    }

    return true;
}

bool _ReadWindowEvents_win32()
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