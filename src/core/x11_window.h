// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_x11_window_h__
#define __core_x11_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/window.h>
#include "linux/libGLX.h"
#include "linux/libX11.h"

typedef struct x11_Window_t {
    XWindow    win;  // A X11 window handle.
    XColormap  cmap; // A X11 colormap handle.
    GLXContext glx;  // A OpenGL rendering context.
} x11_Window_t;

bool x11_CloseWindow(Window window);
bool x11_CreateWindow(const WindowCreateInfo* pCreateInfo, Window window);
bool x11_DestroyWindow(Window window);
bool x11_HideWindow(Window window);
bool x11_MoveWindow(Window window, int32_t left, int32_t top);
bool x11_ReadEvents();
bool x11_ShowWindow(Window window);
bool x11_SizeWindow(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_x11_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //