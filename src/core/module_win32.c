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

struct _Module_Win32 _Win32 = { NULL };

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Surface surface = (Surface)GetWindowLongPtrA(hWnd, 0);

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
            PostQuitMessage(0);
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
            SetWindowLongPtrA(hWnd, 0, (LONG_PTR)cs->lpCreateParams);
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

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool _FreeModule_Win32()
{
    // check if module was unloaded
    if (!_Win32.handle) return false;

    // unregister Win32 window class
    if (!UnregisterClassA(_Win32.lpClassName, _Win32.hInstance))
    {
        printf("ERROR: failed to unregister window class\n");
        return false;
    }

    _Win32.handle = NULL;
    return true;
}

bool _LoadModule_Win32()
{
    // check if module was loaded
    if (_Win32.handle) return true;

    // get the Win32 instance handle
    _Win32.hInstance = GetModuleHandleA(NULL);

    // set the Win32 window class name
    _Win32.lpClassName = "PxitWindowClass";

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
    wc.hInstance     = _Win32.hInstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = _Win32.lpClassName;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!RegisterClassExA(&wc))
    {
        printf("ERROR: failed to register window class\n");
        return false;
    }

    _Win32.handle = (void*)TRUE;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //