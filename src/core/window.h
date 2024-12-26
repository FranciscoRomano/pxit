// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_window_h__
#define __core_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/window.h>

#if IS_PLATFORM_LINUX
#include "linux/libGLX.h"
#include "linux/libX11.h"
typedef struct {
    XWindow    win;  // A X11 window handle.
    XColormap  cmap; // A X11 colormap handle.
    GLXContext glrc; // A X11 OpenGL rendering context.
} _Window_x11;
bool _CloseWindow_x11(Window);                          // X11 implementation of 'CloseWindow' function.
bool _CreateWindow_x11(const WindowCreateInfo*,Window); // X11 implementation of 'CreateWindow' function.
bool _DestroyWindow_x11(Window);                        // X11 implementation of 'DestroyWindow' function.
bool _FocusWindow_x11(Window, bool);                    // X11 implementation of 'FocusWindow' function.
bool _HideWindow_x11(Window);                           // X11 implementation of 'HideWindow' function.
bool _MaximizeWindow_x11(Window);                       // X11 implementation of 'MaximizeWindow' function.
bool _MinimizeWindow_x11(Window);                       // X11 implementation of 'MinimizeWindow' function.
bool _MoveWindow_x11(Window, int32_t, int32_t);         // X11 implementation of 'MoveWindow' function.
bool _ReadWindowEvents_x11();                           // X11 implementation of 'ReadWindowEvents' function.
bool _RestoreWindow_x11(Window);                        // X11 implementation of 'RestoreWindow' function.
bool _ShowWindow_x11(Window);                           // X11 implementation of 'ShowWindow' function.
bool _SizeWindow_x11(Window, uint32_t, uint32_t);       // X11 implementation of 'SizeWindow' function.
#else
typedef char _Window_x11;
#endif

#if IS_PLATFORM_WINDOWS
#include "window_win32.h"
#else
typedef char _Window_Win32_t;
#endif

typedef struct Window_t {
    union {
        _Window_Win32_t win32;
        _Window_x11     x11;
    };
    WindowCallbacks callbacks;
    struct {
        bool (*CloseWindow)(Window);
        bool (*DestroyWindow)(Window);
        bool (*DrawWindow)(Window);
        bool (*FocusWindow)(Window, bool);
        bool (*HideWindow)(Window);
        bool (*MaximizeWindow)(Window);
        bool (*MinimizeWindow)(Window);
        bool (*MoveWindow)(Window, int32_t, int32_t);
        bool (*RestoreWindow)(Window);
        bool (*ShowWindow)(Window);
        bool (*SizeWindow)(Window, uint32_t, uint32_t);
    } impl;
} Window_t;

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //