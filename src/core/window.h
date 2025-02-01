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
#include "glx_window.h"
#include "x11_window.h"
#else
typedef char _Window_x11_t;
#endif

#if IS_PLATFORM_WINDOWS
#include "window_win32.h"
#else
typedef char _Window_Win32_t;
#endif

typedef struct Window_t {
    union {
        _Window_Win32_t win32;
        _Window_x11_t   x11;
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