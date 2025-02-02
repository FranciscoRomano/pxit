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

typedef struct _Window_x11_t {
    XWindow    win;  // A X11 window handle.
    XColormap  cmap; // A X11 colormap handle.
    GLXContext glx;  // A OpenGL rendering context.
} _Window_x11_t;

bool _CloseWindow_x11(Window window);
bool _CreateWindow_x11(const WindowCreateInfo* pCreateInfo, Window window);
bool _DestroyWindow_x11(Window window);
bool _FocusWindow_x11(Window window, bool focus);
bool _HideWindow_x11(Window window);
bool _MaximizeWindow_x11(Window window);
bool _MinimizeWindow_x11(Window window);
bool _MoveWindow_x11(Window window, int32_t left, int32_t top);
bool _ReadWindowEvents_x11();
bool _RestoreWindow_x11(Window window);
bool _ShowWindow_x11(Window window);
bool _SizeWindow_x11(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_x11_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //