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

#include "linux/libX11.h"

/// @brief Represents the X11 module and supported functions.
extern struct _Module_X11 {
    bool      OK;
    XDisplay* dpy;
    XContext  ctx;
    XWindow   root;
    XAtom     wmDeleteWindow;
} _X11;

/// @brief Returns true if the X11 module was freed successfully.
bool _FreeModule_X11();

/// @brief Returns true if the X11 module was loaded successfully.
bool _LoadModule_X11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_x11_h__
// -------------------------------------------------------------------------------------------------------------------------- //