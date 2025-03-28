// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct win32_Module win32 = { NULL };

LRESULT CALLBACK win32_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Window window = (Window)_user32.GetWindowLongPtrA(hWnd, 0);

    switch (uMsg)
    {
        case WM_CLOSE:
        {
            if (!window) break;
            window_evnt(OnWindowClose);
            win32_DestroyWindow(window);
            return 0;
        }
        case WM_DESTROY:
        {
            if (!window) break;
            window_evnt(OnWindowDestroy);
            if (!--win32.windowCount) _user32.PostQuitMessage(0);
            break;
        }
        case WM_ERASEBKGND:
        {
            if (!window) break;
            return 0;
        }
        case WM_LBUTTONDOWN:
        {
            if (!window) break;
            window_evnt(OnMouseDown, MOUSE_LEFT);
            return 0;
        }
        case WM_LBUTTONUP:
        {
            if (!window) break;
            window_evnt(OnMouseUp, MOUSE_LEFT);
            return 0;
        }
        case WM_MOUSELEAVE:
        {
            if (!window) break;
            POINT point;
            _user32.GetCursorPos(&point);
            window_evnt(OnMouseMove, point.x, point.y);
            return 0;
        }
        case WM_MOUSEMOVE:
        {
            if (!window) break;
            POINT point = {
                ((int)(short)((WORD)(((DWORD_PTR)(lParam)) & 0xffff))),
                ((int)(short)((WORD)((((DWORD_PTR)(lParam)) >> 16) & 0xffff))),
            };
            _user32.ClientToScreen(hWnd, &point);
            window_evnt(OnMouseMove, point.x, point.y);
            return 0;
        }
        case WM_SIZE:
        {
            if (!window) break;
            window_evnt(OnWindowSize, LOWORD(lParam), HIWORD(lParam));
            return 0;
        }
        default:
            break;
    }

    return _user32.DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

bool win32_FreeModule()
{
    // check if module was unloaded
    if (!win32.OK) return true;

    // unregister current window class
    _user32.UnregisterClassA(win32.lpClassName, win32.hInstance);

    // free all loaded module dependencies
    _free_user32_dll();
    win32.OK = false;
    return true;
}

bool win32_LoadModule()
{
    // check if module was loaded
    if (win32.OK) return true;

    // load all module dependencies
    if (!_load_user32_dll()) return failure("failed to load library 'user32.dll'");

    // set current process DPI aware
    if (_user32.SetProcessDPIAware)
        _user32.SetProcessDPIAware();
    if (_user32.SetProcessDpiAwareness)
        _user32.SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
    if (_user32.SetProcessDpiAwarenessContext)
    {
        _user32.SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE);
        _user32.SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    }

    // get the default instance handle
    win32.hInstance = GetModuleHandleA(NULL);

    // set the default window class name
    win32.lpClassName = "PxitWindowClass";

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
    wc.hInstance     = win32.hInstance;
    wc.lpfnWndProc   = win32_WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = win32.lpClassName;
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    if (!_user32.RegisterClassExA(&wc))
    {
        _free_user32_dll();
        return failure("failed to register window class");
    }
    win32.windowCount = 0;
    win32.OK = true;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //