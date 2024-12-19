// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "gdi32.h"
#include <stdio.h>
#include <stdlib.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
_gdi32.Name = (void*)GetProcAddress(_gdi32.dll, #Name);\
if (!_gdi32.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Library_gdi32 _gdi32 = { NULL };

bool _FreeLibrary_gdi32()
{
    // check if library was unloaded
    if (!_gdi32.dll) return false;

    // unload and reset library handle
    FreeLibrary(_gdi32.dll);
    _gdi32.dll = NULL;
    return true;
}

bool _LoadLibrary_gdi32()
{
    // check if library was loaded
    if (_gdi32.dll) return true;

    // iterate through all library paths
    const char* paths[] = { "gdi32.dll", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        _gdi32.dll = LoadLibraryA(paths[i]);
        if (_gdi32.dll == NULL) continue;
        LOAD_REQUIRED_SYMBOL(ChoosePixelFormat)
        LOAD_REQUIRED_SYMBOL(SetPixelFormat)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //