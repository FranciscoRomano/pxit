// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INVOKE_FUNCTION(Name, ...)\
if (window && window->pfn##Name) return window->pfn##Name(window->handle,##__VA_ARGS__); return false;
// -------------------------------------------------------------------------------------------------------------------------- //
bool CloseWindow(Window window)                                 { INVOKE_FUNCTION(CloseWindow)               }
bool DestroyWindow(Window window)                               { INVOKE_FUNCTION(DestroyWindow)             }
bool FocusWindow(Window window, bool focus)                     { INVOKE_FUNCTION(FocusWindow, focus)        }
bool HideWindow(Window window)                                  { INVOKE_FUNCTION(HideWindow)                }
bool MaximizeWindow(Window window)                              { INVOKE_FUNCTION(MaximizeWindow)            }
bool MinimizeWindow(Window window)                              { INVOKE_FUNCTION(MinimizeWindow)            }
bool MoveWindow(Window window, int32_t left, int32_t top)       { INVOKE_FUNCTION(MoveWindow, left, top)     }
bool RestoreWindow(Window window)                               { INVOKE_FUNCTION(RestoreWindow)             }
bool ShowWindow(Window window)                                  { INVOKE_FUNCTION(ShowWindow)                }
bool SizeWindow(Window window, uint32_t width, uint32_t height) { INVOKE_FUNCTION(SizeWindow, width, height) }
// -------------------------------------------------------------------------------------------------------------------------- //
#if IS_PLATFORM_LINUX
bool _CreateWindowX11(const WindowCreateInfo* pCreateInfo, Window* pWindow);
#elif IS_PLATFORM_WINDOWS
bool _CreateWindowWin32(const WindowCreateInfo* pCreateInfo, Window* pWindow);
#endif
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    #if IS_PLATFORM_LINUX
    if (_CreateWindowX11(pCreateInfo, pWindow)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (_CreateWindowWin32(pCreateInfo, pWindow)) return true;
    #endif
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
#if IS_PLATFORM_LINUX
bool _ReadWindowEventsX11();
#elif IS_PLATFORM_WINDOWS
bool _ReadWindowEventsWin32();
#endif
bool ReadWindowEvents()
{
    bool result = false;
    #if IS_PLATFORM_LINUX
    result |= _ReadWindowEventsX11();
    #elif IS_PLATFORM_WINDOWS
    result |= _ReadWindowEventsWin32();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //