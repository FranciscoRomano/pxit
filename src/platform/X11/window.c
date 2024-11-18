// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include "library.h"
#include <stdlib.h>
#include <stdio.h>
// -------------------------------------------------------------------------------------------------------------------------- //

extern LibraryX11 X11;

bool CreateWindowX11(WindowContextX11* context, uint width, uint height, WindowX11* window)
{
    // set window attributes
    XSetWindowAttributes attributes = {};
    attributes.event_mask |= ExposureMask;
    attributes.event_mask |= KeyPressMask;
    attributes.event_mask |= KeyReleaseMask;
    attributes.event_mask |= StructureNotifyMask;
    attributes.background_pixel = 0xff000000;

    // create a new X11 window
    window->hID = X11.XCreateWindow(
        context->hDisplay,
        context->hRootWindow,
        0,
        0,
        width,
        height,
        0,
        CopyFromParent,
        CopyFromParent,
        CopyFromParent,
        CWBackPixel | CWEventMask,
        &attributes
    );
    if (!window->hID) return false;
    X11.XMapWindow(context->hDisplay, window->hID);
    X11.XSetWMProtocols(context->hDisplay, window->hID, &context->wmDeleteWindow, 1);
    X11.XSaveContext(context->hDisplay, window->hID, context->hContext, (char*)window);
    return true;
}

bool CreateWindowContextX11(WindowContextX11* context)
{
    // open a connection to the X server
    context->hDisplay = X11.XOpenDisplay(NULL);
    if (!context->hDisplay) return false;

    // get a unique or the default context
    context->hContext = (XContext)X11.XrmUniqueQuark();

    // get the display's default root window
    context->hRootWindow = X11.XDefaultRootWindow(context->hDisplay);

    // get the 'WM_DELETE_WINDOW' event handle
    context->wmDeleteWindow = X11.XInternAtom(context->hDisplay, "WM_DELETE_WINDOW", False);
    return true;
}

bool DestroyWindowX11(WindowContextX11* context, WindowX11* window)
{
    // destroy the X11 window
    X11.XDeleteContext(context->hDisplay, window->hID, context->hContext);
    X11.XUnmapWindow(context->hDisplay, window->hID);
    X11.XDestroyWindow(context->hDisplay, window->hID);
    return true;
}

bool DestroyWindowContextX11(WindowContextX11* context)
{
    // close the connection to the X server
    X11.XCloseDisplay(context->hDisplay);
    context->hDisplay = NULL;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //