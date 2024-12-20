// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_SURFACE_IMPL(Name, ...)\
if (surface->pfn##Name) { surface->pfn##Name(surface,##__VA_ARGS__); }
#define INVOKE_SURFACE_EVENT(Name, ...)\
if (surface->callbacks.Name) { surface->callbacks.Name(surface,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_win32 _win32 = { NULL };

LRESULT CALLBACK _WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Surface surface = (Surface)_user32.GetWindowLongPtrA(hWnd, 0);

    switch (uMsg)
    {
        case WM_CLOSE:
        {
            if (!surface) break;
            INVOKE_SURFACE_EVENT(OnSurfaceClose)
            return 0;
        }
        case WM_DESTROY:
        {
            if (!surface) break;
            INVOKE_SURFACE_EVENT(OnSurfaceDestroy)
            free(surface);
            _user32.PostQuitMessage(0);
            break;
        }
        case WM_ENTERSIZEMOVE:
        {
            if (!surface) break;
            INVOKE_SURFACE_IMPL(MakeCurrent)
            INVOKE_SURFACE_EVENT(OnSurfacePaint)
            INVOKE_SURFACE_IMPL(SwapBuffers)
            return 0;
        }
        case WM_ERASEBKGND:
        {
            return 0;
        }
        case WM_EXITSIZEMOVE:
        {
            if (!surface) break;
            INVOKE_SURFACE_IMPL(MakeCurrent)
            INVOKE_SURFACE_EVENT(OnSurfacePaint)
            INVOKE_SURFACE_IMPL(SwapBuffers)
            return 0;
        }
        case WM_NCCREATE:
        {
            CREATESTRUCT* cs = (CREATESTRUCT*)lParam;
            _user32.SetWindowLongPtrA(hWnd, 0, (LONG_PTR)cs->lpCreateParams);
            break;
        }
        case WM_PAINT:
        {
            if (!surface) break;
            INVOKE_SURFACE_IMPL(MakeCurrent)
            INVOKE_SURFACE_EVENT(OnSurfacePaint)
            INVOKE_SURFACE_IMPL(SwapBuffers)
            return 0;
        }
        case WM_SIZE:
        {
            if (!surface) break;
            INVOKE_SURFACE_EVENT(OnSurfaceSize, LOWORD(lParam), HIWORD(lParam))
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
        _FreeLibrary_user32();
        return false;
    }

    _FreeLibrary_user32();
    _win32.OK = false;
    return true;
}

bool _LoadModule_win32()
{
    // check if module was loaded
    if (_win32.OK) return true;

    // load the "user32.dll" library
    if (!_LoadLibrary_user32())
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
    ZeroMemory(&wc, sizeof(WNDCLASSEXW));
    wc.cbClsExtra    = 0;
    wc.cbSize        = sizeof(WNDCLASSEXW);
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
        _FreeLibrary_user32();
        return false;
    }

    _win32.OK = true;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //