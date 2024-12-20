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
#include "library/gles.h"

#if IS_PLATFORM_LINUX
#endif

#if IS_PLATFORM_WINDOWS
#include "library/gdi32.h"
#include "library/opengl32.h"
#include "library/user32.h"
#endif

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_library_h__
// -------------------------------------------------------------------------------------------------------------------------- //