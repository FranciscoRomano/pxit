// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _gdi32
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _gdi32_dll _gdi32 = { NULL };

bool _free_gdi32_dll()
{
    // check if library was unloaded
    if (!_gdi32.dll) return true;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
    return true;
}

bool _load_gdi32_dll()
{
    // check if library was loaded
    if (_gdi32.dll) return true;

    // iterate through all library paths
    const char* paths[] = { "gdi32.dll", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        LIBRARY_MODULE_LOAD(paths[i])
        LIBRARY_MODULE_RSYM(ChoosePixelFormat)
        LIBRARY_MODULE_RSYM(DescribePixelFormat)
        LIBRARY_MODULE_RSYM(SetPixelFormat)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //