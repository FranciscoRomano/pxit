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

typedef struct win32_Window_t {
    HWND  hWnd;  // A win32 window handle.
    HDC   hDC;   // A win32 device context.
    HGLRC hGLRC; // A OpenGL rendering context.
} win32_Window_t;

bool win32_CloseWindow(Window window);
bool win32_CreateWindow(const WindowCreateInfo* pCreateInfo, Window window);
bool win32_DestroyWindow(Window window);
bool win32_HideWindow(Window window);
bool win32_MoveWindow(Window window, int32_t left, int32_t top);
bool win32_ReadEvents();
bool win32_ShowWindow(Window window);
bool win32_SizeWindow(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_win32_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //