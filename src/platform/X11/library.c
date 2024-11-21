// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#define LOAD_LIBRARY_SYMBOL(Name)\
library->Name = dlsym(library->handle, #Name);\
if (!library->Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); exit(EXIT_FAILURE); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool FreeLibraryX11(LibraryX11* library)
{
    // check if library was unloaded
    if (!library->handle) return false;

    // unload and reset library handle
    dlclose(library->handle);
    library->handle = NULL;
    return true;
}

bool LoadLibraryX11(LibraryX11* library)
{
    // check if library was loaded
    if (library->handle) return true;

    // iterate through all library paths
    const char* paths[] = {
        "libX11.so.6.4.0",
        "libX11.so.6.4",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        library->handle = dlopen(paths[i], RTLD_LAZY);
        if (library->handle == NULL) continue;
        LOAD_LIBRARY_SYMBOL(XInternAtom)
        LOAD_LIBRARY_SYMBOL(XCreateColormap)
        LOAD_LIBRARY_SYMBOL(XOpenDisplay)
        LOAD_LIBRARY_SYMBOL(XChangeProperty)
        LOAD_LIBRARY_SYMBOL(XCloseDisplay)
        LOAD_LIBRARY_SYMBOL(XDefaultScreen)
        LOAD_LIBRARY_SYMBOL(XDeleteContext)
        LOAD_LIBRARY_SYMBOL(XDeleteProperty)
        LOAD_LIBRARY_SYMBOL(XDestroyWindow)
        LOAD_LIBRARY_SYMBOL(XFindContext)
        LOAD_LIBRARY_SYMBOL(XFlush)
        LOAD_LIBRARY_SYMBOL(XMapWindow)
        LOAD_LIBRARY_SYMBOL(XPending)
        LOAD_LIBRARY_SYMBOL(XNextEvent)
        LOAD_LIBRARY_SYMBOL(XrmUniqueQuark)
        LOAD_LIBRARY_SYMBOL(XSaveContext)
        LOAD_LIBRARY_SYMBOL(XScreenCount)
        LOAD_LIBRARY_SYMBOL(XUnmapWindow)
        LOAD_LIBRARY_SYMBOL(XKeysymToKeycode)
        LOAD_LIBRARY_SYMBOL(XDefaultScreenOfDisplay)
        LOAD_LIBRARY_SYMBOL(XScreenOfDisplay)
        LOAD_LIBRARY_SYMBOL(XSetWMProtocols)
        LOAD_LIBRARY_SYMBOL(XCreateWindow)
        LOAD_LIBRARY_SYMBOL(XDefaultRootWindow)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //