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
    if (!_X11.OK) return false;

    // close the connection to the X server
    if (_libX11.XCloseDisplay(_X11.dpy) != 0)
    {
        printf("ERROR: failed to close X11 display\n");
        return false;
    }

    _free_libX11_so();
    _X11.OK = false;
    return true;
}

bool _LoadModule_X11()
{
    // check if module was loaded
    if (_X11.OK) return true;

    // load the "libX11.so" library
    if (!_load_libX11_so())
    {
        printf("ERROR: failed to load library 'libX11.so'\n");
        return false;
    }

    // open a connection to the X server
    _X11.dpy = _libX11.XOpenDisplay(NULL);
    if (!_X11.dpy)
    {
        printf("ERROR: failed to open X11 display\n");
        return false;
    }

    // get a unique or the default context
    _X11.ctx = (XContext)_libX11.XrmUniqueQuark();
    if (!_X11.ctx)
    {
        printf("ERROR: failed to get X11 context\n");
        _libX11.XCloseDisplay(_X11.dpy);
        return false;
    }

    // get the display's default root window
    _X11.root = ((&_X11.dpy->screens[_X11.dpy->default_screen])->root);
    if (!_X11.root)
    {
        printf("ERROR: failed to get X11 root window\n");
        _libX11.XCloseDisplay(_X11.dpy);
        return false;
    }

    // get the internal atom 'WM_DELETE_WINDOW'
    _X11.wmDeleteWindow = _libX11.XInternAtom(_X11.dpy, "WM_DELETE_WINDOW", False);
    if (!_X11.wmDeleteWindow)
    {
        printf("ERROR: failed to get X11 intern atom\n");
        _libX11.XCloseDisplay(_X11.dpy);
        return false;
    }

    _X11.OK = true;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //