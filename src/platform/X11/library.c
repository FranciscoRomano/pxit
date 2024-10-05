// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <pxit/pxit.h>
#include <dlfcn.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#define X11_LIBRARY_PATH(NAME)\
"/usr/lib/x86_64-linux-gnu/"                        NAME,\
"/snap/gnome-42-2204/176/usr/lib/x86_64-linux-gnu/" NAME

#define X11_LOAD_SYMBOL(NAME)\
X11.NAME = dlsym(X11_LIBRARY, #NAME);\
if (X11.NAME == NULL) {\
    printf(" - ERROR: Failed to load symbol '" #NAME "'\n");\
    dlclose(X11_LIBRARY);\
    X11_LIBRARY = NULL;\
    continue;\
}

PxLibrary_X11 X11 = {};
void* X11_LIBRARY = NULL;
const char* X11_LIBRARY_PATH[] = {
    X11_LIBRARY_PATH("libX11.so.6.4.0"),
    X11_LIBRARY_PATH("libX11.so.6.4"),
    X11_LIBRARY_PATH("libX11.so.6")
    X11_LIBRARY_PATH("libX11.so")
};
const size_t X11_LIBRARY_PATH_COUNT = sizeof(X11_LIBRARY_PATH) / sizeof(X11_LIBRARY_PATH[0]);

// -------------------------------------------------------------------------------------------------------------------------- //
int pxFreeLibrary_X11()
{
    // check if library is already loaded
    if (X11_LIBRARY == NULL) return PX_SUCCESS;

    // close the library and reset data to zeros.
    dlclose(X11_LIBRARY);
    X11_LIBRARY = NULL;
    memset(&X11, 0, sizeof(X11));
    return PX_SUCCESS;
}
// -------------------------------------------------------------------------------------------------------------------------- //
int pxLoadLibrary_X11(PxLibrary_X11* library)
{
    // check if library is already loaded
    if (X11_LIBRARY != NULL) return PX_SUCCESS;

    // iterate through all potential library paths
    for (size_t i = 0; i < X11_LIBRARY_PATH_COUNT; i++)
    {
        // 1) check if the library path exists
        struct stat f;
        if (stat(X11_LIBRARY_PATH[i], &f) != 0) continue;
        switch (f.st_mode & __S_IFMT)
        {
            case __S_IFLNK:
            case __S_IFREG:
                break;
            default:
                continue;
        }

        // 2) attempt to load the library from path.
        printf("Loading X11 '%s'", X11_LIBRARY_PATH[i]);
        X11_LIBRARY = dlopen(X11_LIBRARY_PATH[i], RTLD_LAZY);
        if (X11_LIBRARY == NULL) { printf(" - ERROR\n"); continue; }

        // 3) fetch all required library symbols/functions
        X11_LOAD_SYMBOL(XCreateColormap)
        X11_LOAD_SYMBOL(XDefaultScreen)
        X11_LOAD_SYMBOL(XDefaultScreenOfDisplay)
        X11_LOAD_SYMBOL(XOpenDisplay)
        X11_LOAD_SYMBOL(XScreenCount)
        X11_LOAD_SYMBOL(XScreenOfDisplay)

        // 4) finally, open the default X11 display and store it
        X11.dpy = X11.XOpenDisplay(NULL);
        if (X11.dpy == NULL)
        {
            printf(" - ERROR: Failed to connect to X server\n");
            dlclose(X11_LIBRARY);
            X11_LIBRARY = NULL;
            continue;
        }
        printf(" - DONE\n");
        return PX_SUCCESS;
    }

    return PX_FAILURE;
}
// -------------------------------------------------------------------------------------------------------------------------- //