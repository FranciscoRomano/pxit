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

#define SUCCESS(FMT,...) printf("success: " FMT "\n",##__VA_ARGS__) ? true : true
#define WARNING(FMT,...) printf("warning: " FMT "\n",##__VA_ARGS__) ? true : true
#define FAILURE(FMT,...) printf("failure: " FMT "\n",##__VA_ARGS__) ? false : false

// -------------------------------------------------------------------------------------------------------------------------- //
// platform includes, macros and definitions

#if IS_PLATFORM_LINUX
    #include <dlfcn.h>
    #include <unistd.h>
    #include "linux/libGLX.h"
    #include "linux/libX11.h"
    #include "x11_module.h"
    #include "x11_window.h"
    #define LIBRARY_FREE(LIB)      { dlclose(LIB.so); LIB.so = NULL; }
    #define LIBRARY_HNDL(LIB)      LIB.so
    #define LIBRARY_LOAD(LIB,PATH) (LIB.so = dlopen(PATH, RTLD_LAZY))
    #define LIBRARY_SYMB(LIB,NAME) dlsym(LIB.so, #NAME)
#else
    typedef uint8_t x11_Window_t;
#endif

#if IS_PLATFORM_WINDOWS
    #include "windows/d3d9.h"
    #include "windows/dxgi.h"
    #include "windows/gdi32.h"
    #include "windows/kernel32.h"
    #include "windows/opengl32.h"
    #include "windows/user32.h"
    #include "win32_module.h"
    #include "win32_window.h"
    #define LIBRARY_FREE(LIB)      { FreeLibrary(LIB.dll); LIB.dll = NULL; }
    #define LIBRARY_HNDL(LIB)      LIB.dll
    #define LIBRARY_LOAD(LIB,PATH) (LIB.dll = LoadLibraryA(LIB))
    #define LIBRARY_SYMB(LIB,NAME) (void*)GetProcAddress(LIB.dll, #NAME)
#else
    typedef uint8_t win32_Window_t;
#endif

typedef struct Window_t {
    WindowEvents events;
    WindowFamily family;
    union {
        win32_Window_t win32;
        x11_Window_t   x11;
    };
    struct {
        bool (*pCloseWindow)(Window);
        bool (*pDestroyWindow)(Window);
        bool (*pHideWindow)(Window);
        bool (*pMoveWindow)(Window, int32_t, int32_t);
        bool (*pShowWindow)(Window);
        bool (*pSizeWindow)(Window, uint32_t, uint32_t);
    } impl;
} Window_t;

#define window_impl(NAME,...) (window->impl.p##NAME   ? window->impl.p##NAME(window,##__VA_ARGS__)   : false)
#define window_evnt(NAME,...) (window->events.p##NAME ? window->events.p##NAME(window,##__VA_ARGS__) : false)

// -------------------------------------------------------------------------------------------------------------------------- //
#if defined(LIBRARY_MODULE)
    // Frees the current library module and resets all variables.
    #define LIBRARY_MODULE_FREE() LIBRARY_FREE(LIBRARY_MODULE);
    // Loads the current library module with specified arguments.
    #define LIBRARY_MODULE_LOAD(...)\
    dl_hndl(LIBRARY_MODULE) = dl_load(__VA_ARGS__);\
    if (!dl_hndl(LIBRARY_MODULE)) continue;
    // Loads the optional symbol into the current library module.
    #define LIBRARY_MODULE_OSYM(NAME)\
    if (!(LIBRARY_MODULE.NAME = dl_lsym(dl_hndl(LIBRARY_MODULE), NAME))) {\
        warning("could not load symbol '" #NAME "'");\
    }
    // Loads the required symbol into the current library module.
    #define LIBRARY_MODULE_RSYM(NAME)\
    if (!(LIBRARY_MODULE.NAME = dl_lsym(dl_hndl(LIBRARY_MODULE), NAME))) {\
        LIBRARY_MODULE_FREE() return failure("could not to load symbol '" #NAME "'");\
    }
#endif//LIBRARY_MODULE
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_private_h__
// -------------------------------------------------------------------------------------------------------------------------- //