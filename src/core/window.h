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

struct Window_t {
    void* handle;
    bool (*pfnCloseWindow)(void* window);
    bool (*pfnDestroyWindow)(void* window);
    bool (*pfnFocusWindow)(void* window, bool focus);
    bool (*pfnHideWindow)(void* window);
    bool (*pfnMaximizeWindow)(void* window);
    bool (*pfnMinimizeWindow)(void* window);
    bool (*pfnMoveWindow)(void* window, int32_t left, int32_t top);
    bool (*pfnRestoreWindow)(void* window);
    bool (*pfnShowWindow)(void* window);
    bool (*pfnSizeWindow)(void* window, uint32_t width, uint32_t height);
};

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //