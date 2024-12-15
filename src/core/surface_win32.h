// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_surface_win32_h__
#define __core_surface_win32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <pxit/core/surface.h>
#include <stdbool.h>
#include <windef.h>

typedef struct _Surface_Win32_t {
    HWND  hWnd;  // A win32 window handle.
    HDC   hDC;   // A win32 device context.
    HGLRC hGLRC; // A win32 OpenGL rendering context.
} _Surface_Win32_t;

// bool _CloseSurface_Win32(Surface surface);
bool _CreateSurface_Win32(const SurfaceCreateInfo* pCreateInfo, Surface surface);
bool _DestroySurface_Win32(Surface surface);
// bool _FocusSurface_Win32(Surface surface, bool focus);
// bool _HideSurface_Win32(Surface surface);
// bool _MaximizeSurface_Win32(Surface surface);
// bool _MinimizeSurface_Win32(Surface surface);
// bool _MoveSurface_Win32(Surface surface, int32_t left, int32_t top);
bool _ReadSurfaceEvents_Win32();
// bool _RestoreSurface_Win32(Surface surface);
// bool _ShowSurface_Win32(Surface surface);
// bool _SizeSurface_Win32(Surface surface, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_surface_win32_h__
// -------------------------------------------------------------------------------------------------------------------------- //