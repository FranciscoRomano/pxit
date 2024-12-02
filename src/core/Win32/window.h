// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_Win32_window_h__
#define __core_Win32_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "module.h"
#define WINDOW_FUNCTIONS 0
#include <pxit/core/window.h>

/// @brief Represents a Win32 window handle.
typedef struct _WindowWin32 {
    HWND            hWnd;
    WindowCallbacks callbacks;
    union {
        struct { HDC hDC; HGLRC hGLRC; } wgl;
    };
    bool (*pfnFreeContext)(struct _WindowWin32*);
    bool (*pfnMakeCurrent)(struct _WindowWin32*);
    bool (*pfnSwapBuffers)(struct _WindowWin32*);
} _WindowWin32;

/// @brief Returns true if the Win32 window was created.
bool _CreateWindowWin32(const WindowCreateInfo* pCreateInfo, _WindowWin32* pWindow);

/// @brief Returns true if the Win32 window was destroyed.
bool _DestroyWindowWin32(_WindowWin32* pWindow);

/// @brief Returns true if all Win32 window events were read.
bool _ReadWindowEventsWin32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_Win32_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //