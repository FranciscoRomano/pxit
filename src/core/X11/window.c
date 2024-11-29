// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include "window.h"
#include <stdlib.h>
#include <stdio.h>
// -------------------------------------------------------------------------------------------------------------------------- //

bool CreateWindowX11(int width, int height, WindowX11* window)
{
    // set window attributes
    XSetWindowAttributes attributes = {};
    attributes.event_mask |= ExposureMask;
    attributes.event_mask |= KeyPressMask;
    attributes.event_mask |= KeyReleaseMask;
    attributes.event_mask |= StructureNotifyMask;
    attributes.background_pixel = 0xff000000;

    // create a new X server window
    window->hID = X11.XCreateWindow(
        X11.hDisplay,
        X11.hRootWindow,
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
    X11.XMapWindow(X11.hDisplay, window->hID);
    X11.XSetWMProtocols(X11.hDisplay, window->hID, &X11.wmDeleteWindow, 1);
    X11.XSaveContext(X11.hDisplay, window->hID, X11.hContext, (char*)window);
    return true;
}

bool DestroyWindowX11(WindowX11* window)
{
    // destroy the X server window
    X11.XDeleteContext(X11.hDisplay, window->hID, X11.hContext);
    X11.XUnmapWindow(X11.hDisplay, window->hID);
    X11.XDestroyWindow(X11.hDisplay, window->hID);
    return true;
}

bool ReadWindowEventsX11()
{
    // iterate through all queued X server messages
    XEvent event;
    WindowX11* window;
    X11.XPending(X11.hDisplay);
    while (QLength(X11.hDisplay))
    {
        // get the next X server event
        X11.XNextEvent(X11.hDisplay, &event);

        // skip event that don't have a window
        if (X11.XFindContext(X11.hDisplay, event.xany.window, X11.hContext, (XPointer*)&window)) continue;

        // translate the current window event by type
        switch (event.type)
        {
            case ClientMessage:
                if (event.xclient.data.l[0] == X11.wmDeleteWindow)
                    return false;
                break;
            default:
                break;
        }
    }

    // flush all events in X server
    X11.XFlush(X11.hDisplay);
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //