// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
X11.Name = dlsym(X11.handle, #Name);\
if (!X11.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct ModuleX11 X11 = { NULL };

bool FreeModuleX11()
{
    // check if module was unloaded
    if (!X11.handle) return false;

    // close the connection to the X server
    if (!X11.XCloseDisplay(X11.hDisplay))
    {
        printf("ERROR: failed to close X11 display\n");
        return false;
    }

    // unload X11 module and reset module handle
    dlclose(X11.handle);
    X11.handle = NULL;
    return true;
}

bool LoadModuleX11()
{
    // check if module was loaded
    if (X11.handle) return true;

    // iterate through all module paths
    const char* paths[] = {
        "libX11.so.6.4.0",
        "libX11.so.6.4",
        "libX11.so.6",
        "libX11.so",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading module and any symbols
        X11.handle = dlopen(paths[i], RTLD_LAZY);
        if (X11.handle == NULL) continue;
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

        // open a connection to the X server
        X11.hDisplay = X11.XOpenDisplay(NULL);
        if (!X11.hDisplay)
        {
            printf("ERROR: failed to open X11 display\n");
            return false;
        }

        // get a unique or the default context
        X11.hContext = (XContext)X11.XrmUniqueQuark();
        if (!X11.hContext)
        {
            printf("ERROR: failed to get X11 context\n");
            return false;
        }

        // get the display's default root window
        X11.hRootWindow = X11.XDefaultRootWindow(X11.hDisplay);
        if (!X11.hRootWindow)
        {
            printf("ERROR: failed to get X11 root window\n");
            return false;
        }

        // get the 'WM_DELETE_WINDOW' event handle
        X11.wmDeleteWindow = X11.XInternAtom(X11.hDisplay, "WM_DELETE_WINDOW", False);
        if (!X11.wmDeleteWindow)
        {
            printf("ERROR: failed to get X11 intern atom\n");
            return false;
        }
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //