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

#include <pxit/core/surface.h>
#include <stdbool.h>
#include <windef.h>

/// @brief Represents a Win32 module and all supported functions.
extern struct _Module_Win32 {
    void*       handle;
    HINSTANCE   hInstance;
    const char* lpClassName;
} _Win32;

/// @brief Returns true if the Win32 module was freed successfully.
bool _FreeModule_Win32();

/// @brief Returns true if the Win32 module was loaded successfully.
bool _LoadModule_Win32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_win32_h__
// -------------------------------------------------------------------------------------------------------------------------- //