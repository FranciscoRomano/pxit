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

#include "library.h"

#if IS_PLATFORM_LINUX
#include <dlfcn.h>
#include <unistd.h>
#include "module_x11.h"
#include "module_glx.h"
#endif

#if IS_PLATFORM_WINDOWS
#include "module_wgl.h"
#include "module_win32.h"
#endif

#include "window.h"

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //