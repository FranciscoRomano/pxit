// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#define X11_LIBRARY_SYMBOL(Name)\
X11.Name = dlsym(X11.lib, #Name); if (!X11.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); exit(EXIT_FAILURE); }
// -------------------------------------------------------------------------------------------------------------------------- //

LibraryX11 X11 = {};

bool FreeLibraryX11()
{
    // check if library was unloaded
    if (!X11.lib) return false;

    // unload and reset X11 library handle
    dlclose(X11.lib);
    X11.lib = NULL;
    return true;
}

bool LoadLibraryX11()
{
    // check if library was loaded
    if (X11.lib) return true;

    // iterate through all library paths
    const char* paths[] = {
        "libX11.so.6.4.0",
        "libX11.so.6.4",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and symbols from path
        X11.lib = dlopen(paths[i], RTLD_LAZY);
        if (X11.lib == NULL) continue;
        X11_LIBRARY_SYMBOL(XInternAtom)
        X11_LIBRARY_SYMBOL(XCreateColormap)
        X11_LIBRARY_SYMBOL(XOpenDisplay)
        X11_LIBRARY_SYMBOL(XChangeProperty)
        X11_LIBRARY_SYMBOL(XCloseDisplay)
        X11_LIBRARY_SYMBOL(XDefaultScreen)
        X11_LIBRARY_SYMBOL(XDeleteContext)
        X11_LIBRARY_SYMBOL(XDeleteProperty)
        X11_LIBRARY_SYMBOL(XDestroyWindow)
        X11_LIBRARY_SYMBOL(XFindContext)
        X11_LIBRARY_SYMBOL(XFlush)
        X11_LIBRARY_SYMBOL(XMapWindow)
        X11_LIBRARY_SYMBOL(XPending)
        X11_LIBRARY_SYMBOL(XNextEvent)
        X11_LIBRARY_SYMBOL(XrmUniqueQuark)
        X11_LIBRARY_SYMBOL(XSaveContext)
        X11_LIBRARY_SYMBOL(XScreenCount)
        X11_LIBRARY_SYMBOL(XUnmapWindow)
        X11_LIBRARY_SYMBOL(XKeysymToKeycode)
        X11_LIBRARY_SYMBOL(XDefaultScreenOfDisplay)
        X11_LIBRARY_SYMBOL(XScreenOfDisplay)
        X11_LIBRARY_SYMBOL(XSetWMProtocols)
        X11_LIBRARY_SYMBOL(XCreateWindow)
        X11_LIBRARY_SYMBOL(XDefaultRootWindow)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //