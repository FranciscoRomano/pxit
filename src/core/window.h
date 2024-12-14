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

#define WINDOW_FUNCTIONS 0
#include <pxit/core/window.h>

#if IS_PLATFORM_WINDOWS
#include "window_win32.h"
#else
typedef char _Window_Win32_t;
#endif

typedef struct Window_t {
    union {
        _Window_Win32_t win32;
    };
    WindowCallbacks callbacks;
    bool (*pfnCloseWindow)(struct Window_t*);
    bool (*pfnDestroyWindow)(struct Window_t*);
    bool (*pfnFocusWindow)(struct Window_t*, bool);
    bool (*pfnFreeContext)(struct Window_t*);
    bool (*pfnHideWindow)(struct Window_t*);
    bool (*pfnMakeCurrent)(struct Window_t*);
    bool (*pfnMaximizeWindow)(struct Window_t*);
    bool (*pfnMinimizeWindow)(struct Window_t*);
    bool (*pfnMoveWindow)(struct Window_t*, int32_t, int32_t);
    bool (*pfnRestoreWindow)(struct Window_t*);
    bool (*pfnShowWindow)(struct Window_t*);
    bool (*pfnSizeWindow)(struct Window_t*, uint32_t, uint32_t);
    bool (*pfnSwapBuffers)(struct Window_t*);
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