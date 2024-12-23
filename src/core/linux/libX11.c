// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "libX11.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
_libX11.Name = dlsym(_libX11.so, #Name);\
if (!_libX11.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _libX11_so _libX11 = { NULL };

bool _free_libX11_so()
{
    // check if library was unloaded
    if (!_libX11.so) return false;

    // unload and reset library handle
    dlclose(_libX11.so);
    _libX11.so = NULL;
    return true;
}

bool _load_libX11_so()
{
    // check if library was loaded
    if (_libX11.so) return true;

    // iterate through all library paths
    const char* paths[] = { "libX11.so.6.4.0", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        _libX11.so = dlopen(paths[i], RTLD_LAZY);
        if (_libX11.so == NULL) continue;
        LOAD_REQUIRED_SYMBOL(XChangeProperty)
        LOAD_REQUIRED_SYMBOL(XChangeWindowAttributes)
        LOAD_REQUIRED_SYMBOL(XCloseDisplay)
        LOAD_REQUIRED_SYMBOL(XCreateColormap)
        LOAD_REQUIRED_SYMBOL(XCreateWindow)
        LOAD_REQUIRED_SYMBOL(XDefaultRootWindow)
        LOAD_REQUIRED_SYMBOL(XDefaultScreen)
        LOAD_REQUIRED_SYMBOL(XDefaultScreenOfDisplay)
        LOAD_REQUIRED_SYMBOL(XDeleteContext)
        LOAD_REQUIRED_SYMBOL(XDeleteProperty)
        LOAD_REQUIRED_SYMBOL(XDestroyWindow)
        LOAD_REQUIRED_SYMBOL(XFindContext)
        LOAD_REQUIRED_SYMBOL(XFlush)
        LOAD_REQUIRED_SYMBOL(XFree)
        LOAD_REQUIRED_SYMBOL(XFreeColormap)
        LOAD_REQUIRED_SYMBOL(XInternAtom)
        LOAD_REQUIRED_SYMBOL(XKeysymToKeycode)
        LOAD_REQUIRED_SYMBOL(XMapWindow)
        LOAD_REQUIRED_SYMBOL(XNextEvent)
        LOAD_REQUIRED_SYMBOL(XOpenDisplay)
        LOAD_REQUIRED_SYMBOL(XPending)
        LOAD_REQUIRED_SYMBOL(XrmUniqueQuark)
        LOAD_REQUIRED_SYMBOL(XSaveContext)
        LOAD_REQUIRED_SYMBOL(XScreenCount)
        LOAD_REQUIRED_SYMBOL(XScreenOfDisplay)
        LOAD_REQUIRED_SYMBOL(XSetWMProtocols)
        LOAD_REQUIRED_SYMBOL(XUnmapWindow)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //