// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
(window->impl.Name ? window->impl.Name(window,##__VA_ARGS__) : false)
#define INVOKE_WINDOW_EVNT(Name, ...)\
if (window->event.Name) { window->event.Name(window,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _DrawWindow_x11_glx(Window window)
{
    // // make GLX context current
    // _libGLX.glXMakeCurrent(_x11.display, window->x11.win, window->x11.glrc);

    // // invoke 'OnWindowDraw' event
    // INVOKE_WINDOW_EVNT(OnWindowDraw)
    // glFlush();

    //  finally, swap the GLX buffers
    // _libGLX.glXSwapBuffers(_x11.display, window->x11.win);
    // _libGLX.glXSwapBuffers(_x11.display, window->x11.win);
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //

bool _CloseWindow_x11(Window window)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _CreateWindow_x11(const WindowCreateInfo* pCreateInfo, Window window)
{
    // load all module dependencies
    if (!_LoadModule_x11()) return false;

    // create a new X11 window (no graphics)
    XSetWindowAttributes attributes = {};
    attributes.event_mask |= ExposureMask;
    attributes.event_mask |= KeyPressMask;
    attributes.event_mask |= KeyReleaseMask;
    attributes.event_mask |= StructureNotifyMask;
    attributes.background_pixel = 0xff000000; // black
    window->x11.win = _libX11.XCreateWindow(
        _x11.display,
        _x11.root_window,
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
    assert(window->x11.win, "failed to create X11 window")
    _x11.windows[_x11.window_count++] = window->x11.win;
    _libX11.XMapWindow(_x11.display, window->x11.win);
    _libX11.XSaveContext(_x11.display, window->x11.win, _x11.context, (char*)window);
    _libX11.XSetWMProtocols(_x11.display, window->x11.win, &_x11.WM_DELETE_WINDOW, 1);
    window->impl.CloseWindow    = _CloseWindow_x11;
    window->impl.DestroyWindow  = _DestroyWindow_x11;
    window->impl.FocusWindow    = _FocusWindow_x11;
    window->impl.HideWindow     = _HideWindow_x11;
    window->impl.MaximizeWindow = _MaximizeWindow_x11;
    window->impl.MinimizeWindow = _MinimizeWindow_x11;
    window->impl.MoveWindow     = _MoveWindow_x11;
    window->impl.RestoreWindow  = _RestoreWindow_x11;
    window->impl.ShowWindow     = _ShowWindow_x11;
    window->impl.SizeWindow     = _SizeWindow_x11;
    window->event = *pCreateInfo->pEvents;

    // initialize a 3D graphics rendering context
    if (_CreateWindow_glx(pCreateInfo, window)) return true;
    error("failed to create X11 rendering context");
    _DestroyWindow_x11(window);
    return false;
}

bool _DestroyWindow_x11(Window window)
{
    // destroy the X11 window
    _libX11.XDeleteContext(_x11.display, window->x11.win, _x11.context);
    _libX11.XDestroyWindow(_x11.display, window->x11.win);

    // unload module dependencies
    if (!_x11.window_count--) _FreeModule_x11();
    return true;
}

bool _FocusWindow_x11(Window window, bool focus)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _HideWindow_x11(Window window)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _MaximizeWindow_x11(Window window)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _MinimizeWindow_x11(Window window)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _MoveWindow_x11(Window window, int32_t left, int32_t top)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _ReadWindowEvents_x11()
{
    // release the process to the OS for a bit
    sleep(0);

    // iterate through all queued X server messages
    XEvent event;
    Window window;
    _libX11.XPending(_x11.display);
    while (_x11.display->qlen)
    {
        // get the next X server event
        _libX11.XNextEvent(_x11.display, &event);

        // skip event that don't have a window
        if (_libX11.XFindContext(_x11.display, event.xany.window, _x11.context, (XPointer*)&window)) continue;
 
        // translate the current window event by type
        switch (event.type)
        {
            case ClientMessage:
            {
                if (event.xclient.data.l[0] == _x11.WM_DELETE_WINDOW)
                    //INVOKE_WINDOW_EVENT(OnWindowClose)
                    return false;
                break;
            }
            default:
                break;
        }
    }

    for (int i = 0; i < _x11.window_count; i++)
    {
        if (_libX11.XFindContext(_x11.display, _x11.windows[i], _x11.context, (XPointer*)&window)) continue;
        
        //printf("window %i\n", i);
        // make GLX context current
        _libGLX.glXMakeCurrent(_x11.display, window->x11.win, window->x11.glx);

        // invoke 'OnWindowDraw' event
        window->event.OnWindowDraw(window);
        //INVOKE_WINDOW_EVNT(OnWindowDraw)
        glFlush();
    }

    for (int i = 0; i < _x11.window_count; i++)
    {
        if (_libX11.XFindContext(_x11.display, _x11.windows[i], _x11.context, (XPointer*)&window)) continue;
        _libGLX.glXSwapBuffers(_x11.display, window->x11.win);
    }

    // flush all events in X server
    _libX11.XFlush(_x11.display);
    return true;
}

bool _RestoreWindow_x11(Window window)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _ShowWindow_x11(Window window)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

bool _SizeWindow_x11(Window window, uint32_t width, uint32_t height)
{
    // check if module is loaded
    ASSERT(_x11.OK, false, "uninitialized module 'x11'")
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //