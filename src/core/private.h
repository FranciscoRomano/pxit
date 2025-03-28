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
    #define DL_FREE(HNDL)      dlclose(HNDL);
    #define DL_LOAD(PATH)      dlopen(PATH, RTLD_LAZY)
    #define DL_SYMB(HNDL,NAME) dlsym(HNDL, #NAME)
#endif//IS_PLATFORM_LINUX

#if IS_PLATFORM_WINDOWS
    #include "windows/d3d9.h"
    #include "windows/dxgi.h"
    #include "windows/gdi32.h"
    #include "windows/kernel32.h"
    #include "windows/opengl32.h"
    #include "windows/user32.h"
    #define DL_FREE(HNDL)      FreeLibrary(HNDL);
    #define DL_LOAD(PATH)      LoadLibraryA(PATH))
    #define DL_SYMB(HNDL,NAME) ((void*)GetProcAddress(HNDL, #NAME))
#endif//IS_PLATFORM_WINDOWS

// -------------------------------------------------------------------------------------------------------------------------- //
#if defined(LIBRARY_NAME)
#define __JOIN__(LEFT,RIGHT) LEFT##RIGHT
#define __TYPE__(NAME) __JOIN__(NAME, _t)
#define __LOAD__(NAME) __JOIN__(load_, NAME)
#define __FREE__(NAME) __JOIN__(free_, NAME)
#define __PATH__(NAME) __JOIN__(NAME, _paths)

#define DEFINE_LIBRARY(...)\
const char* __PATH__(LIBRARY_NAME)[] = { __VA_ARGS__,NULL };\
struct __TYPE__(LIBRARY_NAME) LIBRARY_NAME = { NULL };\
bool __FREE__(LIBRARY_NAME)() {\
    if (!LIBRARY_NAME.hndl) return true;\
    DL_FREE(LIBRARY_NAME.hndl)\
    LIBRARY_NAME.hndl = NULL;\
    return true;\
}

#define DEFINE_SYMBOLS(...)\
bool __LOAD__(LIBRARY_NAME)() {\
    if (LIBRARY_NAME.hndl) return true;\
    for (size_t i = 0; __PATH__(LIBRARY_NAME)[i]; i++) {\
        if (!(LIBRARY_NAME.hndl = DL_LOAD(__PATH__(LIBRARY_NAME)[i]))) continue;\
        __VA_ARGS__\
        return true;\
    }\
    return false;\
}

#define OPTIONAL_SYMBOL(NAME)\
if (!(LIBRARY_NAME.NAME = DL_SYMB(LIBRARY_NAME.hndl, NAME))) {\
    WARNING("could not load symbol '" #NAME "'");\
}

#define REQUIRED_SYMBOL(NAME)\
if (!(LIBRARY_NAME.NAME = DL_SYMB(LIBRARY_NAME.hndl, NAME))) {\
    DL_FREE(LIBRARY_NAME.hndl);\
    LIBRARY_NAME.hndl = NULL;\
    return FAILURE("could not load symbol '" #NAME "'");\
}
#endif
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_private_h__
// -------------------------------------------------------------------------------------------------------------------------- //