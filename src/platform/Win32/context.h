// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
#ifndef __pxit_platform_Win32_context_h__
#define __pxit_platform_Win32_context_h__
#ifdef __cplusplus
extern "C" {
#endif

#include <Windows.h>

/// @brief Represents the Win32 API platform context.
typedef struct PlatformContextWin32 {
    HINSTANCE hInstance;
    LPCSTR    lpszClassName;
} PlatformContextWin32;

/// @brief Frees the specified Win32 API platform context.
void FreePlatformContextWin32(PlatformContextWin32* ctx);

/// @brief Initializes the specified Win32 API platform context.
void InitPlatformContextWin32(PlatformContextWin32* ctx);

#ifdef __cplusplus
}
#endif
#endif//__pxit_platform_Win32_context_h__