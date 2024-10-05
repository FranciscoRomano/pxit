// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// ---------------------------------------------------------------------------------------------- //
#ifndef __pxit_pxit_h__
#define __pxit_pxit_h__ 1
#ifdef __cplusplus
extern "C" {
#endif
// ---------------------------------------------------------------------------------------------- //
// IS_PLATFORM_LINUX - Used to detect any GNU/Linux Operating System
#if defined(linux) || defined(__linux) || defined(__linux__)
  #define IS_PLATFORM_LINUX 1
#else
  #define IS_PLATFORM_LINUX 0
#endif
// IS_PLATFORM_WINDOWS - Used to detect any Microsoft Windows Operating System
#if defined(_WIN32) || defined(_WIN64)
  #define IS_PLATFORM_WINDOWS 1
#else
  #define IS_PLATFORM_WINDOWS 0
#endif
// PLATFORM_CALL - Placed after the return type in function declarations.
//                 Useful for MSVC-style calling convention syntax.
#ifndef PLATFORM_CALL
  #if IS_PLATFORM_WINDOWS
    #define PLATFORM_CALL __stdcall
  #else
    #define PLATFORM_CALL
  #endif
#endif
// PLATFORM_HANDLE - Used to declare a handle with the specified name.
//                   Useful for abstracting any platform specific libraries.
#define PLATFORM_HANDLE(NAME) typedef struct NAME##_t* NAME;
// ---------------------------------------------------------------------------------------------- //

/// @brief Represent the result code
typedef enum PxResult {
    PX_SUCCESS = 0,
    PX_FAILURE = 1,
} PxResult;

#include "core/display.h"

// ---------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__pxit_pxit_h__
// ---------------------------------------------------------------------------------------------- //