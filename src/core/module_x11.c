// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define LOAD_REQUIRED_SYMBOL(Name)\
_X11.Name = dlsym(_X11.handle, #Name);\
if (!_X11.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_X11 _X11 = { NULL };

bool _FreeModule_X11()
{
    // check if module was unloaded
    if (!_X11.handle) return false;

    // close the connection to the X server
    if (_X11.XCloseDisplay(_X11.dpy) != 0)
    {
        printf("ERROR: failed to close X11 display\n");
        return false;
    }

    // unload X11 module and reset module handle
    dlclose(_X11.handle);
    _X11.handle = NULL;
    return true;
}

bool _LoadModule_X11()
{
    // check if module was loaded
    if (_X11.handle) return true;

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
        _X11.handle = dlopen(paths[i], RTLD_LAZY);
        if (_X11.handle == NULL) continue;
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

        // open a connection to the X server
        _X11.dpy = _X11.XOpenDisplay(NULL);
        if (!_X11.dpy)
        {
            printf("ERROR: failed to open X11 display\n");
            return false;
        }

        // get a unique or the default context
        _X11.ctx = (XContext)_X11.XrmUniqueQuark();
        if (!_X11.ctx)
        {
            printf("ERROR: failed to get X11 context\n");
            return false;
        }

        // get the display's default root window
        _X11.root = DefaultRootWindow(_X11.dpy);
        if (!_X11.root)
        {
            printf("ERROR: failed to get X11 root window\n");
            return false;
        }

        // get the 'WM_DELETE_WINDOW' event handle
        _X11.wmDeleteWindow = _X11.XInternAtom(_X11.dpy, "WM_DELETE_WINDOW", False);
        if (!_X11.wmDeleteWindow)
        {
            printf("ERROR: failed to get X11 intern atom\n");
            return false;
        }
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //