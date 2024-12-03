// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_Linux_X11_window_h__
#define __core_Linux_X11_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "module.h"

/// @brief Represents a X11 window handle.
typedef struct WindowX11 {
    Window hID; // A X11 window.
} WindowX11;

/// @brief Returns true if the X11 window was created.
bool CreateWindowX11(int width, int height, WindowX11* window);

/// @brief Returns true if the X11 window was destroyed.
bool DestroyWindowX11(WindowX11* window);

/// @brief Returns true if all X11 window events were read.
bool ReadWindowEventsX11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_Linux_X11_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //