// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "context.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define X11_PATHS(Name)\
"/usr/lib/x86_64-linux-gnu/" Name,\
"/snap/gnome-42-2204/176/usr/lib/x86_64-linux-gnu/" Name,
#define X11_LOAD_SYMBOL(Name)\
GX11.Name = dlsym(GX11.lib, #Name);\
if (!GX11.Name) { printf("Failed to load symbol '" #Name "'\n"); exit(EXIT_FAILURE); }
// -------------------------------------------------------------------------------------------------------------------------- //

PxitPlatformX11 GX11 = {};

void FreePxitPlatformX11()
{
    // check if library was unloaded
    if (!GX11.lib) return;

    // close any connection with X server
    GX11.XCloseDisplay(GX11.dpy);
    dlclose(GX11.lib);
    GX11.lib = NULL;
}

void InitPxitPlatformX11()
{
    // check if library is already loaded
    if (GX11.lib) return;

    // iterate through all known library paths
    char const* paths[] = {
        X11_PATHS("libX11.so.6.4.0")
        X11_PATHS("libX11.so.6.4")
        X11_PATHS("libX11.so.6")
        X11_PATHS("libX11.so")
    };
    const size_t count = sizeof(paths) / sizeof(char*);
    for (size_t i = 0; i < count; i++)
    {
        // attempt to load the X library from path
        struct stat f;
        if (stat(paths[i], &f) != 0) continue;
        switch (f.st_mode & __S_IFMT)
        {
            case __S_IFLNK:
            case __S_IFREG:
                GX11.lib = dlopen(paths[i], RTLD_LAZY);
                if (GX11.lib) break;
            default:
                continue;
        }
        X11_LOAD_SYMBOL(XCloseDisplay)
        X11_LOAD_SYMBOL(XCreateColormap)
        X11_LOAD_SYMBOL(XCreateWindow)
        X11_LOAD_SYMBOL(XDefaultRootWindow)
        X11_LOAD_SYMBOL(XDefaultScreen)
        X11_LOAD_SYMBOL(XDefaultScreenOfDisplay)
        X11_LOAD_SYMBOL(XInternAtom)
        X11_LOAD_SYMBOL(XMapWindow)
        X11_LOAD_SYMBOL(XNextEvent)
        X11_LOAD_SYMBOL(XOpenDisplay)
        X11_LOAD_SYMBOL(XScreenCount)
        X11_LOAD_SYMBOL(XScreenOfDisplay)
        X11_LOAD_SYMBOL(XSetWMProtocols)
        X11_LOAD_SYMBOL(XKeysymToKeycode)

        // establish a new connection with the X server
        GX11.dpy = GX11.XOpenDisplay(NULL);
        if (!GX11.dpy)
        {
            printf("ERROR: Failed to connect to X server\n");
            exit(EXIT_FAILURE);
        }

        return;
    }
}

// -------------------------------------------------------------------------------------------------------------------------- //