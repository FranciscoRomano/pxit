// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
(window->impl.Name ? window->impl.Name(window,##__VA_ARGS__) : false)
#define INVOKE_WINDOW_EVNT(Name, ...)\
if (window->callbacks.Name) { window->callbacks.Name(window,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _DestroyWindow_x11_glx(Window window)
{
    // destroy GLX context
    _libGLX.glXMakeCurrent(_x11.display, window->x11.win, 0);
    _libGLX.glXDestroyContext(_x11.display, window->x11.glrc);

    // destroy the X11 window
    return _DestroyWindow_x11(window);
}

bool _DrawWindow_x11_glx(Window window)
{
    // make GLX context current
    _libGLX.glXMakeCurrent(_x11.display, window->x11.win, window->x11.glrc);

    // invoke 'OnWindowDraw' event
    INVOKE_WINDOW_EVNT(OnWindowDraw)
    glFlush();

    // finally, swap the GLX buffers
    //_libGLX.glXSwapBuffers(_x11.display, window->x11.win);
    _libGLX.glXSwapBuffers(_x11.display, window->x11.win);
    return true;
}

bool _CreateWindow_x11_glx(Window window)
{
    // initialize GLX module
    if (!_LoadModule_GLX()) return false;

    // create GLX compatible colormap
    XVisualInfo* vi = _libGLX.glXGetVisualFromFBConfig(_x11.display, _GLX.fbc);
    XWindow root = _libX11.XScreenOfDisplay(_x11.display, vi->screen)->root;
    window->x11.cmap = _libX11.XCreateColormap(_x11.display, window->x11.win, vi->visual, AllocNone);
    _libX11.XFree(vi);

    // set the window's default colormap
    XSetWindowAttributes swa;
    swa.colormap = window->x11.cmap;
    _libX11.XChangeWindowAttributes(_x11.display, window->x11.win, CWColormap, &swa);

    // create a new GLX rendering context
    window->x11.glrc = _libGLX.glXCreateNewContext(_x11.display, _GLX.fbc, GLX_RGBA_TYPE, 0, True);
    _libGLX.glXMakeCurrent(_x11.display, window->x11.win, window->x11.glrc);
    window->impl.DestroyWindow = _DestroyWindow_x11_glx;
    window->impl.DrawWindow    = _DrawWindow_x11_glx;
    INVOKE_WINDOW_EVNT(OnWindowCreate)
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
    // initialize X11 module
    if (!_LoadModule_x11())
    {
        printf("ERROR: failed to load module 'X11'\n");
        return false;
    }

    // check current window count
    if (_x11.window_count >= MAX_WINDOWS_X11)
    {
        printf("ERROR: max number of X11 windows reached\n");
        return false;
    }

    // create a new X server window
    XSetWindowAttributes attributes = {};
    attributes.event_mask |= ExposureMask;
    attributes.event_mask |= KeyPressMask;
    attributes.event_mask |= KeyReleaseMask;
    attributes.event_mask |= StructureNotifyMask;
    attributes.background_pixel = 0xff000000;
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
    ASSERT(window->x11.win, false, "failed to create X11 window")
    _libX11.XMapWindow(_x11.display, window->x11.win);
    _libX11.XSaveContext(_x11.display, window->x11.win, _x11.context, (char*)window);
    _libX11.XSetWMProtocols(_x11.display, window->x11.win, &_x11.WM_DELETE_WINDOW, 1);
    _x11.windows[_x11.window_count++] = window->x11.win;
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

    // initialize the graphics rendering context
    if (_CreateWindow_x11_glx(window)) return true;
    printf("ERROR: failed to create X11 rendering context\n");
    _libX11.XDeleteContext(_x11.display, window->x11.win, _x11.context);
    _libX11.XDestroyWindow(_x11.display, window->x11.win);
    _x11.window_count--;
    return false;
}

bool _DestroyWindow_x11(Window window)
{
    // destroy the X server window
    _libX11.XDestroyWindow(_x11.display, window->x11.win);
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
        if (_libX11.XFindContext(_x11.display, _x11.windows[i], _x11.context, (XPointer*)&window));
            INVOKE_WINDOW_IMPL(DrawWindow);

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