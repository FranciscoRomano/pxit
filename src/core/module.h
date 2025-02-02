// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_h__
#define __core_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //
// C standard library

#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------------------------------------------------------------------------------------------------------- //
// Pxit's core library

/// log a error message to the terminal or command line application.
#define error(Frmt,...)\
printf("ERROR: " Frmt "\n",##__VA_ARGS__)

/// loads the specified module, otherwise log a error message and returns false.
#define module_load(Name)\
if (!_LoadModule_##Name()) { error("failed to load module '" #Name "'"); return false; }

/// unloads the specified module, otherwise log a error message and returns false.
#define module_free(Name)\
if (!_FreeModule_##Name()) { error("failed to unload module '" #Name "'"); return false; }

#ifndef module_exit
/// asserts if expression evaluates to true, otherwise exit application.
#define assert(Expr,Frmt,...)\
if (!(Expr)) { error(Frmt,##__VA_ARGS__); exit(EXIT_FAILURE); }
#else
/// asserts if expression evaluates to true, otherwise unload current module.
#define assert(Expr,Frmt,...)\
if (!(Expr)) { error(Frmt,##__VA_ARGS__); module_exit(); return false; }
#endif

#if IS_PLATFORM_LINUX
#include <dlfcn.h>
#include <unistd.h>
#include "linux/libGLX.h"
#include "linux/libX11.h"
#include "glx_module.h"
#include "glx_window.h"
#include "x11_module.h"
#include "x11_window.h"
#define library_load(Name)\
if (!_load_##Name##_so()) { printf("ERROR: failed to load library '" #Name ".so'\n"); return false; }
#define library_free(Name)\
if (!_free_##Name##_so()) { printf("ERROR: failed to unload library '" #Name ".so'\n"); return false; }
#else
typedef char _Window_x11_t;
#endif

#if IS_PLATFORM_WINDOWS
#include <windef.h>
#include "windows/gdi32.h"
#include "windows/kernel32.h"
#include "windows/opengl32.h"
#include "windows/user32.h"
#include "wgl_module.h"
#include "wgl_window.h"
#include "win32_module.h"
#include "win32_window.h"
#define library_load(Name)\
if (!_load_##Name##_dll()) { printf("ERROR: failed to load library '" #Name ".dll'\n"); return false; }
#define library_free(Name)\
if (!_free_##Name##_dll()) { printf("ERROR: failed to unload library '" #Name ".dll'\n"); return false; }
#else
typedef char _Window_win32_t;
#endif

#include "assert.h"
#include "opengl/gles.h"

typedef struct Window_t {
    WindowEvents event;
    union {
        _Window_win32_t win32;
        _Window_x11_t   x11;
    };
    struct {
        bool (*CloseWindow)(Window);
        bool (*DestroyWindow)(Window);
        bool (*DrawWindow)(Window);
        bool (*FocusWindow)(Window, bool);
        bool (*HideWindow)(Window);
        bool (*MaximizeWindow)(Window);
        bool (*MinimizeWindow)(Window);
        bool (*MoveWindow)(Window, int32_t, int32_t);
        bool (*RestoreWindow)(Window);
        bool (*ShowWindow)(Window);
        bool (*SizeWindow)(Window, uint32_t, uint32_t);
    } impl;
} Window_t;

#define WINDOW_IMPL(Name,...)\
(window->impl.Name ? window->impl.Name(window,##__VA_ARGS__) : false)

#define WINDOW_EVENT(Name,...)\
if (window->event.Name) { window->event.Name(window,##__VA_ARGS__); }

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //