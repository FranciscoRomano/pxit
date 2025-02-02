// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_win32_window_h__
#define __core_win32_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/window.h>
#include "windows/user32.h"

typedef struct _Window_win32_t {
    HWND  hWnd;  // A win32 window handle.
    HDC   hDC;   // A win32 device context.
    HGLRC hGLRC; // A OpenGL rendering context.
} _Window_win32_t;

bool _CloseWindow_win32(Window window);
bool _CreateWindow_win32(const WindowCreateInfo* pCreateInfo, Window window);
bool _DestroyWindow_win32(Window window);
bool _FocusWindow_win32(Window window, bool focus);
bool _HideWindow_win32(Window window);
bool _MaximizeWindow_win32(Window window);
bool _MinimizeWindow_win32(Window window);
bool _MoveWindow_win32(Window window, int32_t left, int32_t top);
bool _ReadWindowEvents_win32();
bool _RestoreWindow_win32(Window window);
bool _ShowWindow_win32(Window window);
bool _SizeWindow_win32(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_win32_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //