// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_library_h__
#define __core_library_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "opengl/gles.h"

#if IS_PLATFORM_LINUX
#include "linux/libGLX.h"
#include "linux/libX11.h"
#endif

#if IS_PLATFORM_WINDOWS
#include <windef.h>
#include "windows/gdi32.h"
#include "windows/kernel32.h"
#include "windows/opengl32.h"
#include "windows/user32.h"
#endif

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_library_h__
// -------------------------------------------------------------------------------------------------------------------------- //