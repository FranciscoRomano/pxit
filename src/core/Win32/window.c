// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#define CALL_WINDOW_EVENT(Name, ...)\
if (window->callbacks.Name) { window->callbacks.Name((Window)window,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _InitContextWGL(_WindowWin32* window);

bool _CreateWindowWin32(const WindowCreateInfo* pCreateInfo, _WindowWin32* window)
{
    // copy all window callbacks
    if (pCreateInfo->pCallbacks)
    {
        window->callbacks.OnCharacter      = pCreateInfo->pCallbacks->OnCharacter;
        window->callbacks.OnKeyDown        = pCreateInfo->pCallbacks->OnKeyDown;
        window->callbacks.OnKeyUp          = pCreateInfo->pCallbacks->OnKeyUp;
        window->callbacks.OnMouseDown      = pCreateInfo->pCallbacks->OnMouseDown;
        window->callbacks.OnMouseEnter     = pCreateInfo->pCallbacks->OnMouseEnter;
        window->callbacks.OnMouseLeave     = pCreateInfo->pCallbacks->OnMouseLeave;
        window->callbacks.OnMouseMove      = pCreateInfo->pCallbacks->OnMouseMove;
        window->callbacks.OnMouseScroll    = pCreateInfo->pCallbacks->OnMouseScroll;
        window->callbacks.OnMouseUp        = pCreateInfo->pCallbacks->OnMouseUp;
        window->callbacks.OnWindowClose    = pCreateInfo->pCallbacks->OnWindowClose;
        window->callbacks.OnWindowCreate   = pCreateInfo->pCallbacks->OnWindowCreate;
        window->callbacks.OnWindowDestroy  = pCreateInfo->pCallbacks->OnWindowDestroy;
        window->callbacks.OnWindowFocus    = pCreateInfo->pCallbacks->OnWindowFocus;
        window->callbacks.OnWindowHide     = pCreateInfo->pCallbacks->OnWindowHide;
        window->callbacks.OnWindowMaximize = pCreateInfo->pCallbacks->OnWindowMaximize;
        window->callbacks.OnWindowMinimize = pCreateInfo->pCallbacks->OnWindowMinimize;
        window->callbacks.OnWindowMove     = pCreateInfo->pCallbacks->OnWindowMove;
        window->callbacks.OnWindowPaint    = pCreateInfo->pCallbacks->OnWindowPaint;
        window->callbacks.OnWindowRestore  = pCreateInfo->pCallbacks->OnWindowRestore;
        window->callbacks.OnWindowShow     = pCreateInfo->pCallbacks->OnWindowShow;
        window->callbacks.OnWindowSize     = pCreateInfo->pCallbacks->OnWindowSize;
    }
    else memset(&window->callbacks, 0, sizeof(WindowCallbacks));

    // adjust region to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE | WS_SIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    window->hWnd = CreateWindowExA(
        0,
        Win32.lpClassName,
        pCreateInfo->pTitle,
        dwStyle,
        pCreateInfo->Left + rect.left,
        pCreateInfo->Top + rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        Win32.hInstance,
        (LPVOID)window
    );
    if (!window->hWnd)
    {
        printf("ERROR: failed to create window\n");
        return false;
    }

    // create a OpenGL ES 3.2 WGL context
    if (!_InitContextWGL(window))
    {
        printf("ERROR: failed to create graphics context\n");
        DestroyWindow(window->hWnd);
        return false;
    }

    CALL_WINDOW_EVENT(OnWindowCreate)
    return true;
}

bool _DestroyWindowWin32(_WindowWin32* window)
{
    // destroy context (impl)
    window->pfnFreeContext(window);

    // destroy the Win32 window
    if (!DestroyWindow(window->hWnd))
    {
        printf("ERROR: failed to destroy window\n");
        return false;
    }

    return true;
}

bool _ReadWindowEventsWin32()
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