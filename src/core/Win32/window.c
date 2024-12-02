// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
// -------------------------------------------------------------------------------------------------------------------------- //

bool _InitContextWGL(_WindowWin32* pWindow);

bool _CreateWindowWin32(const WindowCreateInfo* pCreateInfo, _WindowWin32* pWindow)
{
    // copy all window callbacks
    if (pCreateInfo->pCallbacks)
    {
        pWindow->callbacks.OnCharacter      = pCreateInfo->pCallbacks->OnCharacter;
        pWindow->callbacks.OnKeyDown        = pCreateInfo->pCallbacks->OnKeyDown;
        pWindow->callbacks.OnKeyUp          = pCreateInfo->pCallbacks->OnKeyUp;
        pWindow->callbacks.OnMouseDown      = pCreateInfo->pCallbacks->OnMouseDown;
        pWindow->callbacks.OnMouseEnter     = pCreateInfo->pCallbacks->OnMouseEnter;
        pWindow->callbacks.OnMouseLeave     = pCreateInfo->pCallbacks->OnMouseLeave;
        pWindow->callbacks.OnMouseMove      = pCreateInfo->pCallbacks->OnMouseMove;
        pWindow->callbacks.OnMouseScroll    = pCreateInfo->pCallbacks->OnMouseScroll;
        pWindow->callbacks.OnMouseUp        = pCreateInfo->pCallbacks->OnMouseUp;
        pWindow->callbacks.OnWindowClose    = pCreateInfo->pCallbacks->OnWindowClose;
        pWindow->callbacks.OnWindowCreate   = pCreateInfo->pCallbacks->OnWindowCreate;
        pWindow->callbacks.OnWindowDestroy  = pCreateInfo->pCallbacks->OnWindowDestroy;
        pWindow->callbacks.OnWindowFocus    = pCreateInfo->pCallbacks->OnWindowFocus;
        pWindow->callbacks.OnWindowHide     = pCreateInfo->pCallbacks->OnWindowHide;
        pWindow->callbacks.OnWindowMaximize = pCreateInfo->pCallbacks->OnWindowMaximize;
        pWindow->callbacks.OnWindowMinimize = pCreateInfo->pCallbacks->OnWindowMinimize;
        pWindow->callbacks.OnWindowMove     = pCreateInfo->pCallbacks->OnWindowMove;
        pWindow->callbacks.OnWindowPaint    = pCreateInfo->pCallbacks->OnWindowPaint;
        pWindow->callbacks.OnWindowRestore  = pCreateInfo->pCallbacks->OnWindowRestore;
        pWindow->callbacks.OnWindowShow     = pCreateInfo->pCallbacks->OnWindowShow;
        pWindow->callbacks.OnWindowSize     = pCreateInfo->pCallbacks->OnWindowSize;
    }
    else memset(&pWindow->callbacks, 0, sizeof(WindowCallbacks));

    // adjust region to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_VISIBLE | WS_SIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    pWindow->hWnd = CreateWindowExA(
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
        (LPVOID)pWindow
    );
    if (!pWindow->hWnd)
    {
        printf("ERROR: failed to create window\n");
        return false;
    }

    // create a OpenGL ES 3.2 WGL context
    if (!_InitContextWGL(pWindow))
    {
        printf("ERROR: failed to create graphics context\n");
        DestroyWindow(pWindow->hWnd);
        return false;
    }

    return true;
}

bool _DestroyWindowWin32(_WindowWin32* pWindow)
{
    // destroy context (impl)
    pWindow->pfnFreeContext(pWindow);

    // destroy the Win32 window
    if (!DestroyWindow(pWindow->hWnd))
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