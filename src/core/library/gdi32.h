// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_library_gdi32_h__
#define __core_library_gdi32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windows.h>
#include <stdbool.h>

/// @brief Represents the "gdi32.dll" library and supported functions.
extern struct _Library_gdi32 {
    void* dll;
    int     WINAPI (*ChoosePixelFormat)(HDC,const PIXELFORMATDESCRIPTOR*);
    WINBOOL WINAPI (*SetPixelFormat)(HDC,int,const PIXELFORMATDESCRIPTOR*);
} _gdi32;

/// @brief Returns true if the "gdi32.dll" library was freed successfully.
bool _FreeLibrary_gdi32();

/// @brief Returns true if the "gdi32.dll" library was loaded successfully.
bool _LoadLibrary_gdi32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_library_gdi32_h__
// -------------------------------------------------------------------------------------------------------------------------- //