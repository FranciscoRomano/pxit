// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __platform_X11_window_h__
#define __platform_X11_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdbool.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

typedef unsigned int  uint;
typedef unsigned long ulong;

/// @brief Represents a X11 window handle.
typedef struct WindowX11 {
    Window hID; // A X11 window.
} WindowX11;

/// @brief Represents a X11 window context handle.
typedef struct WindowContextX11 {
    Display* hDisplay;       // A X server connection
    XContext hContext;       // A unique context handle
    Window   hRootWindow;    // The default root window
    Atom     wmDeleteWindow; // The WM_DELETE_WINDOW event
} WindowContextX11;

/// @brief Returns true if the X11 window was created.
bool CreateWindowX11(WindowContextX11* context, uint width, uint height, WindowX11* window);

/// @brief Returns true if a X11 window context was created.
bool CreateWindowContextX11(WindowContextX11* context);

/// @brief Returns true if the X11 window was destroyed.
bool DestroyWindowX11(WindowContextX11* context, WindowX11* window);

/// @brief Returns true if the X11 window context was destroyed.
bool DestroyWindowContextX11(WindowContextX11* context);

/// @brief Returns true if all X11 window events were read.
bool ReadWindowEventsX11(WindowContextX11* context);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__platform_X11_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //