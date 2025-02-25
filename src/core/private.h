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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define success(FMT,...) printf("success: " FMT "\n",##__VA_ARGS__) ? true : true
#define warning(FMT,...) printf("warning: " FMT "\n",##__VA_ARGS__) ? true : true
#define failure(FMT,...) printf("failure: " FMT "\n",##__VA_ARGS__) ? false : false

// -------------------------------------------------------------------------------------------------------------------------- //
// platform includes, macros and definitions

#if IS_PLATFORM_LINUX
  #include <dlfcn.h>
  #include <unistd.h>
  #include "linux/libGLX.h"
  #include "linux/libX11.h"
  #define dl_free(HNDL)      dlclose(HNDL)
  #define dl_hndl(NAME)      NAME.so
  #define dl_load(PATH)      dlopen(PATH, RTLD_LAZY)
  #define dl_lsym(HNDL,NAME) dlsym(HNDL, #NAME)
#endif

#if IS_PLATFORM_WINDOWS
  #define WIN32_LEAN_AND_MEAN 1
  #include "windows/d3d9.h"
  #include "windows/gdi32.h"
  #include "windows/kernel32.h"
  #include "windows/opengl32.h"
  #include "windows/user32.h"
  #define dl_free(HNDL)      FreeLibrary(HNDL)
  #define dl_hndl(NAME)      NAME.dll
  #define dl_load(PATH)      LoadLibraryA(PATH)
  #define dl_lsym(HNDL,NAME) (void*)GetProcAddress(HNDL, #NAME)
#endif

// -------------------------------------------------------------------------------------------------------------------------- //
#if defined(LIBRARY_MODULE)
  // Frees the current library module and resets all variables.
  #define LIBRARY_MODULE_FREE()\
  dl_free(dl_hndl(LIBRARY_MODULE));\
  dl_hndl(LIBRARY_MODULE) = NULL;
  // Loads the current library module with specified arguments.
  #define LIBRARY_MODULE_LOAD(...)\
  dl_hndl(LIBRARY_MODULE) = dl_load(__VA_ARGS__);\
  if (!dl_hndl(LIBRARY_MODULE)) continue;
  // Loads the optional symbol into the current library module.
  #define LIBRARY_MODULE_OSYM(NAME)\
  if (!(LIBRARY_MODULE.NAME = dl_lsym(dl_hndl(LIBRARY_MODULE), NAME))) {\
    warning("could not load symbol '" #NAME "'\n");\
  }
  // Loads the required symbol into the current library module.
  #define LIBRARY_MODULE_RSYM(NAME)\
  if (!(LIBRARY_MODULE.NAME = dl_lsym(dl_hndl(LIBRARY_MODULE), NAME))) {\
    LIBRARY_MODULE_FREE() return failure("could not to load symbol '" #NAME "'\n");\
  }
#endif//LIBRARY_MODULE
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_private_h__
// -------------------------------------------------------------------------------------------------------------------------- //