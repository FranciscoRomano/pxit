// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "private.h"
// -------------------------------------------------------------------------------------------------------------------------- //
bool CloseWindow(Window window)                                 { return window_impl(CloseWindow);               }
bool HideWindow(Window window)                                  { return window_impl(HideWindow);                }
bool MoveWindow(Window window, int32_t left, int32_t top)       { return window_impl(MoveWindow, left, top);     }
bool ShowWindow(Window window)                                  { return window_impl(ShowWindow);                }
bool SizeWindow(Window window, uint32_t width, uint32_t height) { return window_impl(SizeWindow, width, height); }
// -------------------------------------------------------------------------------------------------------------------------- //
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    // allocate window handle
    Window window = (Window)malloc(sizeof(Window_t));
    memset(window, 0, sizeof(Window_t));
    if (pWindow) *pWindow = window;

    // copy all window callbacks
    if (pCreateInfo->pEvents) window->events = *pCreateInfo->pEvents;

    // create native platform window
    #if IS_PLATFORM_LINUX
    if (_CreateWindow_x11(pCreateInfo, window)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (win32_CreateWindow(pCreateInfo, window)) return true;
    #endif

    free(window);
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool DestroyWindow(Window window)
{
    // destroy native platform window
    if (!window_impl(DestroyWindow)) return false;

    // release the allocated window handle
    free(window);
    return true;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool ReadEvents()
{
    // read all platform specific events
    bool result = false;
    #if IS_PLATFORM_LINUX
    result |= _ReadWindowEvents_x11();
    #elif IS_PLATFORM_WINDOWS
    result |= win32_ReadEvents();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //