// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
(window->impl.Name ? window->impl.Name(window,##__VA_ARGS__) : false)
// -------------------------------------------------------------------------------------------------------------------------- //
bool CloseWindow(Window window)                                 { return INVOKE_WINDOW_IMPL(CloseWindow);               }
bool FocusWindow(Window window, bool focus)                     { return INVOKE_WINDOW_IMPL(FocusWindow, focus);        }
bool HideWindow(Window window)                                  { return INVOKE_WINDOW_IMPL(HideWindow);                }
bool MaximizeWindow(Window window)                              { return INVOKE_WINDOW_IMPL(MaximizeWindow);            }
bool MinimizeWindow(Window window)                              { return INVOKE_WINDOW_IMPL(MinimizeWindow);            }
bool MoveWindow(Window window, int32_t left, int32_t top)       { return INVOKE_WINDOW_IMPL(MoveWindow, left, top);     }
bool RestoreWindow(Window window)                               { return INVOKE_WINDOW_IMPL(RestoreWindow);             }
bool ShowWindow(Window window)                                  { return INVOKE_WINDOW_IMPL(ShowWindow);                }
bool SizeWindow(Window window, uint32_t width, uint32_t height) { return INVOKE_WINDOW_IMPL(SizeWindow, width, height); }
// -------------------------------------------------------------------------------------------------------------------------- //
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    // allocate window handle
    Window window = (Window)malloc(sizeof(Window_t));
    memset(window, 0, sizeof(Window_t));
    if (pWindow) *pWindow = window;

    // copy all window callbacks
    if (!pCreateInfo->pCallbacks) memset(&window->callbacks, 0, sizeof(WindowCallbacks));
    else memcpy(&window->callbacks, pCreateInfo->pCallbacks, sizeof(WindowCallbacks));

    // create native platform window
    #if IS_PLATFORM_LINUX
    if (_CreateWindow_x11(pCreateInfo, window)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (_CreateWindow_Win32(pCreateInfo, window)) return true;
    #endif

    free(window);
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool DestroyWindow(Window window)
{
    // destroy native platform window
    if (!INVOKE_WINDOW_IMPL(DestroyWindow)) return false;

    // release the allocated window handle
    free(window);
    return true;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool ReadWindowEvents()
{
    // read native platform window events
    bool result = false;
    #if IS_PLATFORM_LINUX
    result |= _ReadWindowEvents_x11();
    #elif IS_PLATFORM_WINDOWS
    result |= _ReadWindowEvents_Win32();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //