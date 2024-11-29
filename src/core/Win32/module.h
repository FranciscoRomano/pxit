// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_Win32_module_h__
#define __core_Win32_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdbool.h>
#include <windows.h>

/// @brief Represents a Win32 module and all supported functions.
extern struct ModuleWin32 {
    void*       handle;
    HINSTANCE   hInstance;
    const char* lpClassName;
} Win32;

/// @brief Returns true if the Win32 module was freed successfully.
bool FreeModuleWin32();

/// @brief Returns true if the Win32 module was loaded successfully.
bool LoadModuleWin32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_Win32_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //