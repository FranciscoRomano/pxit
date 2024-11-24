// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include <stdlib.h>
#include <stdio.h>
// -------------------------------------------------------------------------------------------------------------------------- //

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    WindowWin32* window = (WindowWin32*)GetWindowLongPtrA(hwnd, 0);

    switch (uMsg)
    {
        case WM_CLOSE:
        {
            PostQuitMessage(0);
            return 0;
        }
        case WM_NCCREATE:
        {
            CREATESTRUCT* cs = (CREATESTRUCT*)lParam;
            SetWindowLongPtrA(hwnd, 0, (LONG_PTR)cs->lpCreateParams);
            break;
        }
        default:
            break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool CreateWindowWin32(WindowContextWin32* context, uint width, uint height, WindowWin32* window)
{
    // create a new Win32 window
    window->hWnd = CreateWindowExA(
        0,
        context->lpClassName,
        "",
        WS_POPUPWINDOW | WS_CAPTION | WS_SIZEBOX | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        0,
        0,
        width,
        height,
        NULL,
        NULL,
        context->hInstance,
        (LPVOID)window
    );
    if (!window->hWnd) return false;

    // get the window device context
    window->hDC = GetDC(window->hWnd);
    if (!window->hDC) return false;

    return true;
}

bool CreateWindowContextWin32(WindowContextWin32* context)
{
    // get the Win32 instance handle
    context->hInstance = GetModuleHandleA(NULL);

    // set the Win32 window class name
    context->lpClassName = "WindowContextClassWin32";

    // register a new Win32 window class
    WNDCLASSEXA wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEXW));
    wc.cbClsExtra    = 0;
    wc.cbSize        = sizeof(WNDCLASSEXW);
    wc.cbWndExtra    = sizeof(void*);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance     = context->hInstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = context->lpClassName;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    return RegisterClassExA(&wc) ? true : false;
}

bool DestroyWindowWin32(WindowContextWin32* context, WindowWin32* window)
{
    // release the window device context
    if (ReleaseDC(window->hWnd, window->hDC) == FALSE) return false;

    // destroy the Win32 window
    return DestroyWindow(window->hWnd);
}

bool DestroyWindowContextWin32(WindowContextWin32* context)
{
    // unregister Win32 window class
    return UnregisterClassA(context->lpClassName, context->hInstance);
}

bool ReadWindowEventsWin32(WindowContextWin32* context)
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