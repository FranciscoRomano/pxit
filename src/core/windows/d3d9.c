// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "d3d9.h"
#include "kernel32.h"
#include <stdio.h>
#include <stdlib.h>
#define LOAD_REQUIRED_SYMBOL(NAME)\
_d3d9.NAME = (void*)GetProcAddress(_d3d9.dll, #NAME);\
if (!_d3d9.NAME) { printf("ERROR: failed to load symbol '" #NAME "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _d3d9_dll _d3d9 = { NULL };

bool _free_d3d9_dll()
{
    // check if library was unloaded
    if (!_d3d9.dll) return false;

    // unload and reset library handle
    FreeLibrary(_d3d9.dll);
    _d3d9.dll = NULL;
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
        _d3d9.dll = LoadLibraryA(paths[i]);
        if (_d3d9.dll == NULL) continue;
        LOAD_REQUIRED_SYMBOL(D3DPERF_BeginEvent)
        LOAD_REQUIRED_SYMBOL(D3DPERF_EndEvent)
        LOAD_REQUIRED_SYMBOL(D3DPERF_GetStatus)
        LOAD_REQUIRED_SYMBOL(D3DPERF_QueryRepeatFrame)
        LOAD_REQUIRED_SYMBOL(D3DPERF_SetMarker)
        LOAD_REQUIRED_SYMBOL(D3DPERF_SetOptions)
        LOAD_REQUIRED_SYMBOL(D3DPERF_SetRegion)
        LOAD_REQUIRED_SYMBOL(Direct3DCreate9)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //