// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_win32_module_h__
#define __core_win32_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/window.h>
#include "windows/user32.h"

/// @brief Represents a Win32 module and supported properties.
extern struct win32_Module {
    bool        OK;
    HINSTANCE   hInstance;
    const char* lpClassName;
    uint32_t    windowCount;
} win32;

/// @brief Returns true if the Win32 module was freed successfully.
bool win32_FreeModule();

/// @brief Returns true if the Win32 module was loaded successfully.
bool win32_LoadModule();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_win32_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //