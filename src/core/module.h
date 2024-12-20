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

#if IS_PLATFORM_LINUX
#include <dlfcn.h>
#include <unistd.h>
#include "module_x11.h"
#include "module_glx.h"
#endif

#if IS_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#include "module_wgl.h"
#include "module_win32.h"
#endif

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module_gles.h"
#include "surface.h"
#include "library.h"

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //