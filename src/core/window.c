// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
if (window->pfn##Name) return window->pfn##Name(window,##__VA_ARGS__); return false;
// -------------------------------------------------------------------------------------------------------------------------- //
bool CloseWindow(Window window)                                 { INVOKE_WINDOW_IMPL(CloseWindow)               }
bool DestroyWindow(Window window)                               { INVOKE_WINDOW_IMPL(DestroyWindow)             }
bool FocusWindow(Window window, bool focus)                     { INVOKE_WINDOW_IMPL(FocusWindow, focus)        }
bool HideWindow(Window window)                                  { INVOKE_WINDOW_IMPL(HideWindow)                }
bool MaximizeWindow(Window window)                              { INVOKE_WINDOW_IMPL(MaximizeWindow)            }
bool MinimizeWindow(Window window)                              { INVOKE_WINDOW_IMPL(MinimizeWindow)            }
bool MoveWindow(Window window, int32_t left, int32_t top)       { INVOKE_WINDOW_IMPL(MoveWindow, left, top)     }
bool RestoreWindow(Window window)                               { INVOKE_WINDOW_IMPL(RestoreWindow)             }
bool ShowWindow(Window window)                                  { INVOKE_WINDOW_IMPL(ShowWindow)                }
bool SizeWindow(Window window, uint32_t width, uint32_t height) { INVOKE_WINDOW_IMPL(SizeWindow, width, height) }
// -------------------------------------------------------------------------------------------------------------------------- //
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    Window window = (Window)malloc(sizeof(Window_t));
    memset(window, 0, sizeof(Window_t));
    if (pWindow) (*pWindow) = window;

    #if IS_PLATFORM_LINUX
    if (_CreateWindow_X11(pCreateInfo, window)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (_CreateWindow_Win32(pCreateInfo, window)) return true;
    #endif

    free(window);
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool ReadWindowEvents()
{
    bool result = false;
    #if IS_PLATFORM_LINUX
    result |= _ReadWindowEvents_X11();
    #elif IS_PLATFORM_WINDOWS
    result |= _ReadWindowEvents_Win32();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //