// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_glx _glx = { NULL };

void* _LoadSymbol_glx(const char* name)
{
    void* p = (void*)_libGLX.glXGetProcAddress(name);
    if (p == (void*) 0) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 1) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 2) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 3) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*)-1) return (void*)dlsym(_libGLX.so, name);
    return p;
}

bool _FreeModule_glx()
{
    // check if module was unloaded
    if (!_glx.OK) return false;

    // unload and reset module handle
    _free_libGLX_so();
    _glx.OK = false;
    return true;
}

bool _LoadModule_glx()
{
    // check if module was loaded
    if (_glx.OK) return true;

    // load all module dependencies
    if (!_x11.OK)
    {
        printf("ERROR: unitialized module 'X11'\n");
        return false;
    }
    if (!_load_libGLX_so())
    {
        printf("ERROR: failed to load library 'libGLX.so'\n");
        return false;
    }
    if (!_load_gles(_LoadSymbol_glx))
    {
        printf("ERROR: failed to load library 'GLES'\n");
        return false;
    }

    _glx.OK = true;
    return true;
}