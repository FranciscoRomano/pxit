// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_win32(const WindowCreateInfo* pCreateInfo, Window window)
{
    // initialize Win32 module
    if (!_LoadModule_win32()) return false;

    // adjust area to window style
    RECT rect = { 0, 0, pCreateInfo->Width, pCreateInfo->Height };
    DWORD dwStyle = WS_POPUP | WS_VISIBLE;
    _user32.AdjustWindowRect(&rect, dwStyle, FALSE);

    // create a new Win32 popup window
    window->win32.hWnd = _user32.CreateWindowExA(
        WS_EX_ACCEPTFILES,
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
    if (pCreateInfo->pEvents) window->event = *pCreateInfo->pEvents;
    window->impl.MoveWindow = _MoveWindow_win32;
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

bool _MoveWindow_win32(Window window, int32_t left, int32_t top)
{
    // set the Win32 window position
    POINT point = { left, top };
    //_user32.ScreenToClient(window->win32.hWnd, &point);
    //UINT flags = SWP_NOZORDER | SWP_NOSIZE | SWP_NOREDRAW | SWP_NOREPOSITION | SWP_NOACTIVATE | SWP_NOSENDCHANGING;
    // UINT flags = SWP_NOSIZE | SWP_NOREPOSITION | SWP_NOSENDCHANGING;
    UINT flags = SWP_NOSIZE;
    _user32.SetWindowPos(window->win32.hWnd, HWND_TOP, point.x, point.y, 0, 0, flags);
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
        if (msg.message == WM_QUIT)
        {
            module_free(wgl)
            module_free(win32)
            return false;
        }
    }

    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //