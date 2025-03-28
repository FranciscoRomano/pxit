// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct x11_Module x11 = { NULL };

bool x11_FreeModule()
{
    // check if module is unloaded
    if (!x11.OK) return false;

    // check if windows have been closed
    if (x11.window_count == 0)
    {
        failure("uninitialized X11 windows");
        return false;
    }

    // close the connection to the X server
    if (XCloseDisplay(x11.display) != 0)
    {
        printf("ERROR: failed to close X11 display\n");
        return false;
    }

    _free_libX11_so();
    x11.OK = false;
    return true;
}

bool x11_LoadModule()
{
    // check if module is loaded
    if (x11.OK) return true;

    // load the "libX11.so" library
    if (!_load_libX11_so())
    {
        printf("ERROR: failed to load library 'libX11.so'\n");
        return false;
    }

    // open a connection to the X server
    x11.display = XOpenDisplay(NULL);
    if (!x11.display) return failure("failed to open X11 display");

    // get a unique or the default context
    x11.context = (XContext)XrmUniqueQuark();
    if (!x11.context) return failure("failed to fetch X11 context");

    // get the display's default root window
    x11.root_window = XDefaultRootWindow(x11.display);
    if (!x11.root_window) return failure("failed to get X11 root window");

    // get the internal atom 'WM_DELETE_WINDOW'
    x11.WM_DELETE_WINDOW = XInternAtom(x11.display, "WM_DELETE_WINDOW", 0);
    if (!x11.WM_DELETE_WINDOW) return failure("failed to get X11 'WM_DELETE_WINDOW' atom");

    x11.OK = true;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //