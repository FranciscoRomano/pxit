// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_x11_module_h__
#define __core_x11_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "linux/libGLX.h"
#include "linux/libX11.h"
#define MAX_WINDOWS_X11 100

/// @brief Represents the X11 module and supported functions.
extern struct x11_Module {
    bool      OK;
    XDisplay* display;
    XContext  context;
    XWindow   root_window;
    XAtom     WM_DELETE_WINDOW;
    XWindow   windows[MAX_WINDOWS_X11];
    uint16_t  window_count;
} x11;

/// @brief Returns true if the X11 module was freed successfully.
bool x11_FreeModule();

/// @brief Returns true if the X11 module was loaded successfully.
bool x11_LoadModule();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_x11_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //