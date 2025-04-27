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

/// @brief Returns true after writing a "success" log message.
inline static bool success(const char* message,...)
{
    va_list arguments;
    va_start(arguments, message);
    fprintf(stdout, "[success] :: ");
    vfprintf(stdout, message, arguments);
    fputc('\n',stdout);
    va_end(arguments);
    return true;
}

/// @brief Returns true after writing a "warning" log message.
inline static bool warning(const char* message,...)
{
    va_list arguments;
    va_start(arguments, message);
    fprintf(stderr, "[warning] :: ");
    vfprintf(stderr, message, arguments);
    fputc('\n',stderr);
    va_end(arguments);
    return true;
}

/// @brief Returns false after writing a "failure" log message.
inline static bool failure(const char* message,...)
{
    va_list arguments;
    va_start(arguments, message);
    fprintf(stderr, "[failure] :: ");
    vfprintf(stderr, message, arguments);
    fputc('\n',stderr);
    va_end(arguments);
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //
// platform includes, macros and definitions

#if IS_PLATFORM_LINUX
    #include <dlfcn.h>
    #include <unistd.h>
    #include "linux/libGLX.h"
    #include "linux/libX11.h"
    inline static void  dl_free(void* lib)                   { dlclose(lib);                   }
    inline static void* dl_load(const char* path)            { return dlopen(path, RTLD_LAZY); }
    inline static void* dl_symb(void* lib, const char* name) { return dlsym(lib, name);        }
#elif IS_PLATFORM_WINDOWS
    #include "windows/gdi32.h"
    #include "windows/kernel32.h"
    #include "windows/user32.h"
    inline static void  dl_free(void* lib)                   { FreeLibrary(lib);                 }
    inline static void* dl_load(const char* path)            { return LoadLibraryA(path);        }
    inline static void* dl_symb(void* lib, const char* name) { return GetProcAddress(lib, name); }
#else
#error "[pxit] unsupported platform"
#endif

// -------------------------------------------------------------------------------------------------------------------------- //
#if defined(LIBRARY_NAME) && defined(LIBRARY_HINT)

#define __JOIN__(LEFT,RIGHT) LEFT##RIGHT
#define __TYPE__(NAME) __JOIN__(NAME, _t)
#define __LOAD__(NAME) __JOIN__(NAME, _load)
#define __FREE__(NAME) __JOIN__(NAME, _free)

#define DEFINE_LIBRARY(...)\
struct __TYPE__(LIBRARY_NAME) LIBRARY_NAME = { NULL };\
bool __FREE__(LIBRARY_NAME)() {\
    if (!LIBRARY_NAME.hndl) return true;\
    dl_free(LIBRARY_NAME.hndl);\
    LIBRARY_NAME.hndl = NULL;\
    return true;\
}\
bool __LOAD__(LIBRARY_NAME)() {\
    if (LIBRARY_NAME.hndl) return true;\
    const char* paths[] = { LIBRARY_HINT, NULL };\
    for (size_t i = 0; paths[i]; i++) {\
        if (!(LIBRARY_NAME.hndl = dl_load(paths[i]))) continue;\
        __VA_ARGS__\
        return true;\
    }\
    return false;\
}

#define OPTIONAL_SYMBOL(NAME)\
if (!(LIBRARY_NAME.NAME = dl_symb(LIBRARY_NAME.hndl, #NAME))) {\
    warning("could not load symbol '" #NAME "'");\
}

#define REQUIRED_SYMBOL(NAME)\
if (!(LIBRARY_NAME.NAME = dl_symb(LIBRARY_NAME.hndl, #NAME))) {\
    dl_free(LIBRARY_NAME.hndl);\
    LIBRARY_NAME.hndl = NULL;\
    return failure("could not load symbol '" #NAME "'");\
}

#endif
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_private_h__
// -------------------------------------------------------------------------------------------------------------------------- //