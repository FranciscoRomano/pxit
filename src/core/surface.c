// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "surface.h"
#define INVOKE_SURFACE_IMPL(Name, ...)\
if (surface->pfn##Name) return surface->pfn##Name(surface,##__VA_ARGS__); return false;
// -------------------------------------------------------------------------------------------------------------------------- //
bool _CloseSurface(Surface surface)                                 { INVOKE_SURFACE_IMPL(CloseSurface)               }
bool _DestroySurface(Surface surface)                               { INVOKE_SURFACE_IMPL(DestroySurface)             }
bool _FocusSurface(Surface surface, bool focus)                     { INVOKE_SURFACE_IMPL(FocusSurface, focus)        }
bool _HideSurface(Surface surface)                                  { INVOKE_SURFACE_IMPL(HideSurface)                }
bool _MaximizeSurface(Surface surface)                              { INVOKE_SURFACE_IMPL(MaximizeSurface)            }
bool _MinimizeSurface(Surface surface)                              { INVOKE_SURFACE_IMPL(MinimizeSurface)            }
bool _MoveSurface(Surface surface, int32_t left, int32_t top)       { INVOKE_SURFACE_IMPL(MoveSurface, left, top)     }
bool _RestoreSurface(Surface surface)                               { INVOKE_SURFACE_IMPL(RestoreSurface)             }
bool _ShowSurface(Surface surface)                                  { INVOKE_SURFACE_IMPL(ShowSurface)                }
bool _SizeSurface(Surface surface, uint32_t width, uint32_t height) { INVOKE_SURFACE_IMPL(SizeSurface, width, height) }
// -------------------------------------------------------------------------------------------------------------------------- //
bool _CreateSurface(const SurfaceCreateInfo* pCreateInfo, Surface* pSurface)
{
    Surface surface = (Surface)malloc(sizeof(Surface_t));
    memset(surface, 0, sizeof(Surface_t));
    if (pSurface) (*pSurface) = surface;

    #if IS_PLATFORM_LINUX
    if (_CreateSurface_X11(pCreateInfo, surface)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (_CreateSurface_Win32(pCreateInfo, surface)) return true;
    #endif

    free(surface);
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool _ReadSurfaceEvents()
{
    bool result = false;
    #if IS_PLATFORM_LINUX
    result |= _ReadSurfaceEvents_X11();
    #elif IS_PLATFORM_WINDOWS
    result |= _ReadSurfaceEvents_Win32();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //