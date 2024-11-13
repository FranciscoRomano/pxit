// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __pxit_platform_Win32_context_h__
#define __pxit_platform_Win32_context_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <Windows.h>

/// @brief Represents a Win32 platform.
typedef struct PxitPlatformWin32 {
    BOOL      bExists;
    HINSTANCE hInstance;
    LPCSTR    lpClassName;
    CHAR      location[MAX_PATH];
} PxitPlatformWin32;

/// @brief Releases the global Win32 platform.
void FreePxitPlatformWin32();

/// @brief Initializes the global Win32 platform.
void InitPxitPlatformWin32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__pxit_platform_Win32_context_h__
// -------------------------------------------------------------------------------------------------------------------------- //