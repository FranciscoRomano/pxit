// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_window_x11_h__
#define __core_window_x11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/window.h>
#include <stdbool.h>
#include <GL/glx.h>

/// @brief Represents a X11 window handle.
typedef struct _Window_X11 {
    Window     win;  // A X11 window handle.
    GLXContext glrc; // A X11 OpenGL rendering context.
} _Window_X11;

// bool _CloseWindow_X11(Window window);
bool _CreateWindow_X11(const WindowCreateInfo* pCreateInfo, Window window);
bool _DestroyWindow_X11(Window window);
// bool _FocusWindow_X11(Window window, bool focus);
// bool _HideWindow_X11(Window window);
// bool _MaximizeWindow_X11(Window window);
// bool _MinimizeWindow_X11(Window window);
// bool _MoveWindow_X11(Window window, int32_t left, int32_t top);
bool _ReadWindowEvents_X11();
// bool _RestoreWindow_X11(Window window);
// bool _ShowWindow_X11(Window window);
// bool _SizeWindow_X11(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_window_x11_h__
// -------------------------------------------------------------------------------------------------------------------------- //