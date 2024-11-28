// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#define LOAD_LIBRARY_SYMBOL(Name)\
X11.Name = dlsym(X11.handle, #Name);\
if (!X11.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct LibraryX11 X11 = { NULL };

bool FreeLibraryX11()
{
    // check if library was unloaded
    if (!X11.handle) return false;

    // unload and reset library handle
    dlclose(X11.handle);
    X11.handle = NULL;
    return true;
}

bool LoadLibraryX11()
{
    // check if library was loaded
    if (X11.handle) return true;

    // iterate through all library paths
    const char* paths[] = {
        "libX11.so.6.4.0",
        "libX11.so.6.4",
        "libX11.so.6",
        "libX11.so",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        X11.handle = dlopen(paths[i], RTLD_LAZY);
        if (X11.handle == NULL) continue;
        LOAD_LIBRARY_SYMBOL(XChangeProperty)
        LOAD_LIBRARY_SYMBOL(XChangeWindowAttributes)
        LOAD_LIBRARY_SYMBOL(XCloseDisplay)
        LOAD_LIBRARY_SYMBOL(XCreateColormap)
        LOAD_LIBRARY_SYMBOL(XCreateWindow)
        LOAD_LIBRARY_SYMBOL(XDefaultRootWindow)
        LOAD_LIBRARY_SYMBOL(XDefaultScreen)
        LOAD_LIBRARY_SYMBOL(XDefaultScreenOfDisplay)
        LOAD_LIBRARY_SYMBOL(XDeleteContext)
        LOAD_LIBRARY_SYMBOL(XDeleteProperty)
        LOAD_LIBRARY_SYMBOL(XDestroyWindow)
        LOAD_LIBRARY_SYMBOL(XFindContext)
        LOAD_LIBRARY_SYMBOL(XFlush)
        LOAD_LIBRARY_SYMBOL(XFree)
        LOAD_LIBRARY_SYMBOL(XInternAtom)
        LOAD_LIBRARY_SYMBOL(XKeysymToKeycode)
        LOAD_LIBRARY_SYMBOL(XMapWindow)
        LOAD_LIBRARY_SYMBOL(XNextEvent)
        LOAD_LIBRARY_SYMBOL(XOpenDisplay)
        LOAD_LIBRARY_SYMBOL(XPending)
        LOAD_LIBRARY_SYMBOL(XrmUniqueQuark)
        LOAD_LIBRARY_SYMBOL(XSaveContext)
        LOAD_LIBRARY_SYMBOL(XScreenCount)
        LOAD_LIBRARY_SYMBOL(XScreenOfDisplay)
        LOAD_LIBRARY_SYMBOL(XSetWMProtocols)
        LOAD_LIBRARY_SYMBOL(XUnmapWindow)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //