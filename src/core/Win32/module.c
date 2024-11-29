// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
// -------------------------------------------------------------------------------------------------------------------------- //

struct ModuleWin32 Win32 = { NULL };

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

bool FreeModuleWin32()
{
    // check if module was unloaded
    if (!Win32.handle) return false;

    // unregister Win32 window class
    if (!UnregisterClassA(Win32.lpClassName, Win32.hInstance))
    {
        printf("ERROR: failed to unregister window class\n");
        return false;
    }

    Win32.handle = NULL;
    return true;
}

bool LoadModuleWin32()
{
    // check if module was loaded
    if (Win32.handle) return true;

    // get the Win32 instance handle
    Win32.hInstance = GetModuleHandleA(NULL);

    // set the Win32 window class name
    Win32.lpClassName = "WindowContextClassWin32";

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
    wc.hInstance     = Win32.hInstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = Win32.lpClassName;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!RegisterClassExA(&wc))
    {
        printf("ERROR: failed to register window class\n");
        return false;
    }

    Win32.handle = (void*)TRUE;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //