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

#include <stdbool.h>
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif//WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef unsigned int  uint;
typedef unsigned long ulong;

/// @brief Represents a Win32 window handle.
typedef struct WindowWin32 {
    HWND hWnd; // A Win32 window.
    HDC  hDC;  // A Win32 device context.
} WindowWin32;

/// @brief Represents a Win32 window context handle.
typedef struct WindowContextWin32 {
    HINSTANCE   hInstance;
    const char* lpClassName;
} WindowContextWin32;

/// @brief Returns true if the Win32 window was created.
bool CreateWindowWin32(WindowContextWin32* context, uint width, uint height, WindowWin32* window);

/// @brief Returns true if a Win32 window context was created.
bool CreateWindowContextWin32(WindowContextWin32* context);

/// @brief Returns true if the Win32 window was destroyed.
bool DestroyWindowWin32(WindowContextWin32* context, WindowWin32* window);

/// @brief Returns true if the Win32 window context was destroyed.
bool DestroyWindowContextWin32(WindowContextWin32* context);

/// @brief Returns true if all Win32 window events were read.
bool ReadWindowEventsWin32(WindowContextWin32* context);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_Win32_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //