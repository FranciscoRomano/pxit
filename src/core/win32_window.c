// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool win32_CreateWindow(const WindowCreateInfo* pCreateInfo, Window window)
{
    // initialize Win32 module
    if (!win32_LoadModule()) return false;

    // adjust area to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUP | WS_VISIBLE | WS_BORDER;
    _user32.AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    window->win32.hWnd = _user32.CreateWindowExA(
        0,
        win32.lpClassName,
        pCreateInfo->pTitle,
        dwStyle,
        pCreateInfo->Left + rect.left,
        pCreateInfo->Top + rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        win32.hInstance,
        NULL
    );
    if (!window->win32.hWnd) return failure("failed to create Win32 window");
    _user32.SetLayeredWindowAttributes(window->win32.hWnd, 0, 0, LWA_COLORKEY);
    _user32.SetLayeredWindowAttributes(window->win32.hWnd, 0, 255, LWA_ALPHA);
    _user32.SetWindowLongPtrA(window->win32.hWnd, 0, (LONG_PTR)window);
    win32.windowCount++;

    // set the Win32 window implementation
    window->impl.pCloseWindow   = win32_CloseWindow;
    window->impl.pDestroyWindow = win32_DestroyWindow;
    window->impl.pHideWindow    = win32_HideWindow;
    window->impl.pMoveWindow    = win32_MoveWindow;
    window->impl.pShowWindow    = win32_ShowWindow;
    window->impl.pSizeWindow    = win32_SizeWindow;
    window_evnt(OnWindowCreate);
    return true;
}

bool win32_CloseWindow(Window window)
{
    // close the Win32 window
    return _user32.CloseWindow(window->win32.hWnd) ? true : false;
}

bool win32_DestroyWindow(Window window)
{
    // destroy the Win32 window
    return _user32.DestroyWindow(window->win32.hWnd) ? true : false;
}

bool win32_HideWindow(Window window)
{
    // hide the Win32 window
    _user32.ShowWindow(window->win32.hWnd, SW_HIDE);
    return true;
}

bool win32_MoveWindow(Window window, int32_t left, int32_t top)
{
    // move the Win32 window
    return _user32.SetWindowPos(window->win32.hWnd, HWND_TOP, left, top, 0, 0, SWP_NOSIZE) ? true : false;
}

bool win32_ShowWindow(Window window)
{
    // hide the Win32 window
    _user32.ShowWindow(window->win32.hWnd, SW_SHOW);
    return true;
}

bool win32_SizeWindow(Window window, uint32_t width, uint32_t height)
{
    // size the Win32 window
    return _user32.SetWindowPos(window->win32.hWnd, HWND_TOP, 0, 0, width, height, SWP_NOMOVE) ? true : false;
}

bool win32_ReadEvents()
{
    // check if Win32 module is loaded
    if (!win32.OK) return false;

    // release process to OS (reduce high CPU)
    Sleep(0);

    // iterate through all queued Win32 messages
    MSG msg;
    while (_user32.PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
    {
        // translate and dispatch the Win32 message
        _user32.TranslateMessage(&msg);
        _user32.DispatchMessageA(&msg);

        // check if Win32 application should be closed
        if (msg.message == WM_QUIT)
        {
            win32_FreeModule();
            return false;
        }
    }
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //