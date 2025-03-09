// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool x11_CloseWindow(Window window)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_CreateWindow(const WindowCreateInfo* pCreateInfo, Window window)
{
    // load all module dependencies
    if (!x11_LoadModule()) return false;

    // create a new X11 window (no graphics)
    XSetWindowAttributes attributes = {};
    attributes.event_mask |= ExposureMask;
    attributes.event_mask |= KeyPressMask;
    attributes.event_mask |= KeyReleaseMask;
    attributes.event_mask |= StructureNotifyMask;
    attributes.background_pixel = 0xff000000; // black
    window->x11.win = XCreateWindow(
        x11.display,
        x11.root_window,
        pCreateInfo->Left,
        pCreateInfo->Top,
        pCreateInfo->Width,
        pCreateInfo->Height,
        0,
        CopyFromParent,
        CopyFromParent,
        CopyFromParent,
        CWBackPixel | CWEventMask,
        &attributes
    );
    if (!window->x11.win) return failure("failed to create X11 window");
    x11.windows[x11.window_count++] = window->x11.win;
    XMapWindow(x11.display, window->x11.win);
    XSaveContext(x11.display, window->x11.win, x11.context, (char*)window);
    XSetWMProtocols(x11.display, window->x11.win, &x11.WM_DELETE_WINDOW, 1);
    window->impl.pCloseWindow    = x11_CloseWindow;
    window->impl.pDestroyWindow  = x11_DestroyWindow;
    window->impl.pHideWindow     = x11_HideWindow;
    window->impl.pMoveWindow     = x11_MoveWindow;
    window->impl.pShowWindow     = x11_ShowWindow;
    window->impl.pSizeWindow     = x11_SizeWindow;
    if (pCreateInfo->pEvents) window->events = *pCreateInfo->pEvents;
    return true;

    // // initialize a 3D graphics rendering context
    // if (_CreateWindow_glx(pCreateInfo, window)) return true;
    // error("failed to create X11 rendering context");
    // x11_DestroyWindow(window);
    // return false;
}

bool x11_DestroyWindow(Window window)
{
    // destroy the X11 window
    XDeleteContext(x11.display, window->x11.win, x11.context);
    XDestroyWindow(x11.display, window->x11.win);

    // unload module dependencies
    if (!x11.window_count--) x11_FreeModule();
    return true;
}

bool x11_HideWindow(Window window)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_MaximizeWindow(Window window)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_MinimizeWindow(Window window)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_MoveWindow(Window window, int32_t left, int32_t top)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_ReadEvents()
{
    // release the process to the OS for a bit
    sleep(0);

    // iterate through all queued X server messages
    XEvent event;
    Window window;
    XPending(x11.display);
    while (QLength(x11.display))
    {
        // get the next X server event
        XNextEvent(x11.display, &event);

        // skip event that don't have a window
        if (XFindContext(x11.display, event.xany.window, x11.context, (void**)&window)) continue;
 
        // translate the current window event by type
        switch (event.type)
        {
            case ClientMessage:
            {
                if (event.xclient.data.l[0] == x11.WM_DELETE_WINDOW)
                    //INVOKE_WINDOW_EVENT(OnWindowClose)
                    return false;
                break;
            }
            default:
                break;
        }
    }

    // flush all events in X server
    // XFlush(x11.display);
    return true;
}

bool x11_RestoreWindow(Window window)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_ShowWindow(Window window)
{
    return failure("function not implemented for module 'x11'");
}

bool x11_SizeWindow(Window window, uint32_t width, uint32_t height)
{
    return failure("function not implemented for module 'x11'");
}

// -------------------------------------------------------------------------------------------------------------------------- //