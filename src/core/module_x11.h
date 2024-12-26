// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_x11_h__
#define __core_module_x11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "linux/libGLX.h"
#include "linux/libX11.h"
#define MAX_WINDOWS_X11 100

/// @brief Represents the X11 module and supported functions.
extern struct _Module_x11 {
    bool      OK;
    XDisplay* display;
    XContext  context;
    XWindow   root_window;
    XAtom     WM_DELETE_WINDOW;
    XWindow   windows[MAX_WINDOWS_X11];
    uint16_t  window_count;
} _x11;

/// @brief Returns true if the X11 module was freed successfully.
bool _FreeModule_x11();

/// @brief Returns true if the X11 module was loaded successfully.
bool _LoadModule_x11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_x11_h__
// -------------------------------------------------------------------------------------------------------------------------- //