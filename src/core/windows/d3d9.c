// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _d3d9
#include "core/private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _d3d9_dll _d3d9 = { NULL };

bool _free_d3d9_dll()
{
    // check if library was unloaded
    if (!_d3d9.dll) return false;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
    return true;
}

bool _load_d3d9_dll()
{
    // check if library was loaded
    if (_d3d9.dll) return true;

    // iterate through all library paths
    const char* paths[] = { "d3d9.dll", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        LIBRARY_MODULE_LOAD(paths[i])
        LIBRARY_MODULE_RSYM(D3DPERF_BeginEvent)
        LIBRARY_MODULE_RSYM(D3DPERF_EndEvent)
        LIBRARY_MODULE_RSYM(D3DPERF_GetStatus)
        LIBRARY_MODULE_RSYM(D3DPERF_QueryRepeatFrame)
        LIBRARY_MODULE_RSYM(D3DPERF_SetMarker)
        LIBRARY_MODULE_RSYM(D3DPERF_SetOptions)
        LIBRARY_MODULE_RSYM(D3DPERF_SetRegion)
        LIBRARY_MODULE_RSYM(Direct3DCreate9)
        return true;
    }

    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //