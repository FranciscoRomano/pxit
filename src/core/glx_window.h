// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_glx_window_h__
#define __core_glx_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/window.h>
#include "linux/libGLX.h"

/// Returns true if a X11 OpenGL ES window was created successfully.
bool _CreateWindow_glx(const WindowCreateInfo* pCreateInfo, Window window);

/// Returns true if a X11 OpenGL ES window was destroyed successfully.
bool _DestroyWindow_glx(Window window);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_glx_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //