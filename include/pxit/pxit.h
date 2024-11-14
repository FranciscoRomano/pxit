// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// ---------------------------------------------------------------------------------------------- //
#ifndef __pxit_pxit_h__
#define __pxit_pxit_h__
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
// ---------------------------------------------------------------------------------------------- //
#endif//__pxit_pxit_h__
// ---------------------------------------------------------------------------------------------- //