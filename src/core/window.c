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
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool ReadWindowEvents()
{
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //