// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
// -------------------------------------------------------------------------------------------------------------------------- //

bool CreateWindowWin32(const WindowCreateInfo* pCreateInfo, WindowWin32* pWindow)
{
    // adjust size to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUPWINDOW | WS_CAPTION | WS_SIZEBOX | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
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

    // get the window's default device context
    pWindow->hDC = GetDC(pWindow->hWnd);
    if (!pWindow->hDC)
    {
        printf("ERROR: failed to get device context\n");
        DestroyWindow(pWindow->hWnd);
        return false;
    }

    return true;
}

bool DestroyWindowWin32(WindowWin32* pWindow)
{
    // release device context
    if (!ReleaseDC(pWindow->hWnd, pWindow->hDC))
    {
        printf("ERROR: failed to release device context\n");
        return false;
    }

    // destroy the Win32 window
    if (!DestroyWindow(pWindow->hWnd))
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