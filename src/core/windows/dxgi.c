// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _dxgi
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _dxgi_dll _dxgi = { NULL };

bool _free_dxgi_dll()
{
    // check if library was unloaded
    if (!_dxgi.dll) return true;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
    return true;
}

bool _load_dxgi_dll()
{
    // check if library was loaded
    if (_dxgi.dll) return true;

    // iterate through all library paths
    const char* paths[] = { "dxgi.dll", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        LIBRARY_MODULE_LOAD(paths[i])
        LIBRARY_MODULE_RSYM(CreateDXGIFactory)
        LIBRARY_MODULE_RSYM(CreateDXGIFactory1)
        LIBRARY_MODULE_RSYM(CreateDXGIFactory2)
        LIBRARY_MODULE_RSYM(DXGIDeclareAdapterRemovalSupport)
        LIBRARY_MODULE_RSYM(DXGIDisableVBlankVirtualization)
        LIBRARY_MODULE_RSYM(DXGIGetDebugInterface1)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //