// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_private_h__
#define __core_private_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //
// common includes, macros and definitions

#include <memory.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS(FMT,...) printf("success: " FMT "\n",##__VA_ARGS__) ? true  : true
#define WARNING(FMT,...) printf("warning: " FMT "\n",##__VA_ARGS__) ? true  : true
#define FAILURE(FMT,...) printf("failure: " FMT "\n",##__VA_ARGS__) ? false : false

// -------------------------------------------------------------------------------------------------------------------------- //
// platform includes, macros and definitions

#if IS_PLATFORM_LINUX
    #include <dlfcn.h>
    #include <unistd.h>
    #include "linux/libGLX.h"
    #include "linux/libX11.h"
    #define LIBRARY_FREE(LIB)      { dlclose(LIB.so); LIB.so = NULL; }
    #define LIBRARY_HNDL(LIB)      LIB.so
    #define LIBRARY_LOAD(LIB,PATH) (LIB.so = dlopen(PATH, RTLD_LAZY))
    #define LIBRARY_PROC(LIB,NAME) (LIB.NAME || (LIB.NAME = dlsym(LIB.so, #NAME)))
#endif//IS_PLATFORM_LINUX

#if IS_PLATFORM_WINDOWS
    #include "windows/d3d9.h"LIB.NAME
    #include "windows/dxgi.h"
    #include "windows/gdi32.h"
    #include "windows/kernel32.h"
    #include "windows/opengl32.h"
    #include "windows/user32.h"
    #define LIBRARY_FREE(LIB)      { FreeLibrary(LIB.dll); LIB.dll = NULL; }
    #define LIBRARY_HNDL(LIB)      LIB.dll
    #define LIBRARY_LOAD(LIB,PATH) (LIB.dll = LoadLibraryA(PATH))
    #define LIBRARY_PROC(LIB,NAME) (LIB.NAME || (LIB.NAME = (void*)GetProcAddress(LIB.dll, #NAME)))
#endif//IS_PLATFORM_WINDOWS

// -------------------------------------------------------------------------------------------------------------------------- //
#if defined(LIBRARY_MODULE)
    #define MODULE_FREE() LIBRARY_FREE(LIBRARY_MODULE);
    #define MODULE_LOAD(...) if (!LIBRARY_LOAD(LIBRARY_MODULE, __VA_ARGS__)) continue;
    #define MODULE_OSYM(NAME) if (!LIBRARY_PROC(LIBRARY_MODULE, NAME)) WARNING("could not load symbol '" #NAME "'");
    #define MODULE_RSYM(NAME) if (!LIBRARY_PROC(LIBRARY_MODULE, NAME)) return FAILURE("could not load symbol '" #NAME "'");
#endif//LIBRARY_MODULE
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_private_h__
// -------------------------------------------------------------------------------------------------------------------------- //