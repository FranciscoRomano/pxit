// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
// -------------------------------------------------------------------------------------------------------------------------- //

bool CreateWindowWin32(int width, int height, WindowWin32* window)
{
    // adjust size to window style
    RECT rect = { 0, 0, width, height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_SIZEBOX | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    window->hWnd = CreateWindowExA(
        0,
        Win32.lpClassName,
        "",
        dwStyle,
        0,
        0,
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

    // get the window's default device context
    window->hDC = GetDC(window->hWnd);
    if (!window->hDC)
    {
        printf("ERROR: failed to get device context\n");
        DestroyWindow(window->hWnd);
        return false;
    }

    return true;
}

bool DestroyWindowWin32(WindowWin32* window)
{
    // release device context
    if (!ReleaseDC(window->hWnd, window->hDC))
    {
        printf("ERROR: failed to release device context\n");
        return false;
    }

    // destroy the Win32 window
    if (!DestroyWindow(window->hWnd))
    {
        printf("ERROR: failed to destroy window\n");
        return false;
    }
}

bool ReadWindowEventsWin32()
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