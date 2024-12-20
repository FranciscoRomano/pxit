// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_win32_h__
#define __core_module_win32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#ifndef WINDOW_FUNCTIONS
#define WINDOW_FUNCTIONS 0
#endif
#include <pxit/core/window.h>
#include <stdbool.h>
#include <windef.h>

/// @brief Represents a Win32 module and supported properties.
extern struct _Module_win32 {
    bool        OK;
    HINSTANCE   hInstance;
    const char* lpClassName;
} _win32;

/// @brief Returns true if the Win32 module was freed successfully.
bool _FreeModule_win32();

/// @brief Returns true if the Win32 module was loaded successfully.
bool _LoadModule_win32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_win32_h__
// -------------------------------------------------------------------------------------------------------------------------- //