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
#include "window_x11.h"
#else
typedef char _Window_X11;
#endif

#if IS_PLATFORM_WINDOWS
#include "window_win32.h"
#else
typedef char _Window_Win32_t;
#endif

typedef struct Window_t {
    union {
        _Window_Win32_t win32;
        _Window_X11     x11;
    };
    WindowCallbacks callbacks;
    bool (*pfnCloseWindow)(Window);
    bool (*pfnDestroyWindow)(Window);
    bool (*pfnFocusWindow)(Window, bool);
    bool (*pfnFreeContext)(Window);
    bool (*pfnHideWindow)(Window);
    bool (*pfnMakeCurrent)(Window);
    bool (*pfnMaximizeWindow)(Window);
    bool (*pfnMinimizeWindow)(Window);
    bool (*pfnMoveWindow)(Window, int32_t, int32_t);
    bool (*pfnRestoreWindow)(Window);
    bool (*pfnShowWindow)(Window);
    bool (*pfnSizeWindow)(Window, uint32_t, uint32_t);
    bool (*pfnSwapBuffers)(Window);
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