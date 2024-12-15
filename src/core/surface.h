// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_surface_h__
#define __core_surface_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/surface.h>

#if IS_PLATFORM_LINUX
#include "surface_x11.h"
#else
typedef char _Surface_X11;
#endif

#if IS_PLATFORM_WINDOWS
#include "surface_win32.h"
#else
typedef char _Surface_Win32_t;
#endif

typedef struct Surface_t {
    union {
        _Surface_Win32_t win32;
        _Surface_X11     x11;
    };
    SurfaceCallbacks callbacks;
    bool (*pfnCloseSurface)(struct Surface_t*);
    bool (*pfnDestroySurface)(struct Surface_t*);
    bool (*pfnFocusSurface)(struct Surface_t*, bool);
    bool (*pfnFreeContext)(struct Surface_t*);
    bool (*pfnHideSurface)(struct Surface_t*);
    bool (*pfnMakeCurrent)(struct Surface_t*);
    bool (*pfnMaximizeSurface)(struct Surface_t*);
    bool (*pfnMinimizeSurface)(struct Surface_t*);
    bool (*pfnMoveSurface)(struct Surface_t*, int32_t, int32_t);
    bool (*pfnRestoreSurface)(struct Surface_t*);
    bool (*pfnShowSurface)(struct Surface_t*);
    bool (*pfnSizeSurface)(struct Surface_t*, uint32_t, uint32_t);
    bool (*pfnSwapBuffers)(struct Surface_t*);
} Surface_t;

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_surface_h__
// -------------------------------------------------------------------------------------------------------------------------- //