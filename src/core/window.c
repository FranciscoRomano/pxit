// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //
bool CloseWindow(Window window)                                 { return WINDOW_IMPL(CloseWindow);               }
bool DrawWindow(Window window)                                  { return WINDOW_IMPL(DrawWindow);                }
bool FocusWindow(Window window, bool focus)                     { return WINDOW_IMPL(FocusWindow, focus);        }
bool HideWindow(Window window)                                  { return WINDOW_IMPL(HideWindow);                }
bool MaximizeWindow(Window window)                              { return WINDOW_IMPL(MaximizeWindow);            }
bool MinimizeWindow(Window window)                              { return WINDOW_IMPL(MinimizeWindow);            }
bool MoveWindow(Window window, int32_t left, int32_t top)       { return WINDOW_IMPL(MoveWindow, left, top);     }
bool RestoreWindow(Window window)                               { return WINDOW_IMPL(RestoreWindow);             }
bool ShowWindow(Window window)                                  { return WINDOW_IMPL(ShowWindow);                }
bool SizeWindow(Window window, uint32_t width, uint32_t height) { return WINDOW_IMPL(SizeWindow, width, height); }
// -------------------------------------------------------------------------------------------------------------------------- //
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    // allocate window handle
    Window window = (Window)malloc(sizeof(Window_t));
    memset(window, 0, sizeof(Window_t));
    if (pWindow) *pWindow = window;

    // copy all window callbacks
    if (!pCreateInfo->pEvents) memset(&window->event, 0, sizeof(WindowEvents));
    else memcpy(&window->event, pCreateInfo->pEvents, sizeof(WindowEvents));

    // create native platform window
    #if IS_PLATFORM_LINUX
    if (_CreateWindow_x11(pCreateInfo, window)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (_CreateWindow_win32(pCreateInfo, window)) return true;
    #endif

    free(window);
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool DestroyWindow(Window window)
{
    // destroy native platform window
    if (!WINDOW_IMPL(DestroyWindow)) return false;

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
    result |= _ReadWindowEvents_win32();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //