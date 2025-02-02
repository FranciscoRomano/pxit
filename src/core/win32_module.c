// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_win32 _win32 = { NULL };

LRESULT CALLBACK _WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Window window = (Window)_user32.GetWindowLongPtrA(hWnd, 0);

    switch (uMsg)
    {
        case WM_CLOSE:
        {
            if (!window) break;
            WINDOW_EVENT(OnWindowClose)
            _DestroyWindow_win32(window);
            return 0;
        }
        case WM_DESTROY:
        {
            if (!window) break;
            WINDOW_EVENT(OnWindowDestroy)
            free(window);
            _user32.PostQuitMessage(0);
            break;
        }
        case WM_ERASEBKGND:
        {
            return 0;
        }
        case WM_NCCREATE:
        {
            CREATESTRUCTA* cs = (CREATESTRUCTA*)lParam;
            _user32.SetWindowLongPtrA(hWnd, 0, (LONG_PTR)cs->lpCreateParams);
            break;
        }
        case WM_SIZE:
        {
            if (!window) break;
            WINDOW_EVENT(OnWindowSize, LOWORD(lParam), HIWORD(lParam))
            return 0;
        }
        default:
            break;
    }

    return _user32.DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

bool _FreeModule_win32()
{
    // check if module was unloaded
    if (!_win32.OK) return false;

    // unregister the custom window class
    if (!_user32.UnregisterClassA(_win32.lpClassName, _win32.hInstance))
    {
        printf("ERROR: failed to unregister window class\n");
        _free_user32_dll();
        return false;
    }

    _free_user32_dll();
    _win32.OK = false;
    return true;
}

bool _LoadModule_win32()
{
    // check if module was loaded
    if (_win32.OK) return true;

    // load the "user32.dll" library
    if (!_load_user32_dll())
    {
        printf("ERROR: failed to load library 'user32.dll'\n");
        return false;
    }

    // fetch the Win32 instance handle
    _win32.hInstance = GetModuleHandleA(NULL);

    // set the default window class name
    _win32.lpClassName = "PxitWindowClass";

    // configure and register window class
    WNDCLASSEXA wc;
    memset(&wc, 0, sizeof(WNDCLASSEXA));
    wc.cbClsExtra    = 0;
    wc.cbSize        = sizeof(WNDCLASSEXA);
    wc.cbWndExtra    = sizeof(void*);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = _user32.LoadCursorA(NULL, IDC_ARROW);
    wc.hIcon         = _user32.LoadIconA(NULL, IDI_APPLICATION);
    wc.hIconSm       = _user32.LoadIconA(NULL, IDI_APPLICATION);
    wc.hInstance     = _win32.hInstance;
    wc.lpfnWndProc   = _WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = _win32.lpClassName;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!_user32.RegisterClassExA(&wc))
    {
        printf("ERROR: failed to register window class\n");
        _free_user32_dll();
        return false;
    }

    _win32.OK = true;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //