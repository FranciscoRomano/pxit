// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_surface_x11_h__
#define __core_surface_x11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/surface.h>
#include <stdbool.h>
#include <GL/glx.h>

/// @brief Represents a X11 surface handle.
typedef struct _Surface_X11 {
    Window     win;  // A X11 window handle.
    Colormap   cmap; // A X11 colormap handle.
    GLXContext glrc; // A X11 OpenGL rendering context.
} _Surface_X11;

// bool _CloseSurface_X11(Surface surface);
bool _CreateSurface_X11(const SurfaceCreateInfo* pCreateInfo, Surface surface);
bool _DestroySurface_X11(Surface surface);
// bool _FocusSurface_X11(Surface surface, bool focus);
// bool _HideSurface_X11(Surface surface);
// bool _MaximizeSurface_X11(Surface surface);
// bool _MinimizeSurface_X11(Surface surface);
// bool _MoveSurface_X11(Surface surface, int32_t left, int32_t top);
bool _ReadSurfaceEvents_X11();
// bool _RestoreSurface_X11(Surface surface);
// bool _ShowSurface_X11(Surface surface);
// bool _SizeSurface_X11(Surface surface, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_surface_x11_h__
// -------------------------------------------------------------------------------------------------------------------------- //