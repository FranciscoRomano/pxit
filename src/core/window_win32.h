// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_window_win32_h__
#define __core_window_win32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#define WINDOW_FUNCTIONS 0
#include <pxit/core/window.h>
#include <stdbool.h>
#include <windef.h>

typedef struct _Window_Win32_t {
    HWND  hWnd;  // A win32 window handle.
    HDC   hDC;   // A win32 device context.
    HGLRC hGLRC; // A win32 OpenGL rendering context.
} _Window_Win32_t;

// bool _CloseWindow_Win32(Window window);
bool _CreateWindow_Win32(const WindowCreateInfo* pCreateInfo, Window window);
bool _DestroyWindow_Win32(Window window);
// bool _FocusWindow_Win32(Window window, bool focus);
// bool _HideWindow_Win32(Window window);
// bool _MaximizeWindow_Win32(Window window);
// bool _MinimizeWindow_Win32(Window window);
// bool _MoveWindow_Win32(Window window, int32_t left, int32_t top);
bool _ReadWindowEvents_Win32();
// bool _RestoreWindow_Win32(Window window);
// bool _ShowWindow_Win32(Window window);
// bool _SizeWindow_Win32(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_window_win32_h__
// -------------------------------------------------------------------------------------------------------------------------- //