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
typedef struct WindowWin32 {
    HWND hWnd; // A Win32 window.
    HDC  hDC;  // A Win32 device context.
} WindowWin32;

/// @brief Returns true if the Win32 window was created.
bool CreateWindowWin32(const WindowCreateInfo* pCreateInfo, WindowWin32* pWindow);

/// @brief Returns true if the Win32 window was destroyed.
bool DestroyWindowWin32(WindowWin32* pWindow);

/// @brief Returns true if all Win32 window events were read.
bool ReadWindowEventsWin32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_Win32_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //