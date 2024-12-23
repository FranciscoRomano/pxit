// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
if (window->pfn##Name) { window->pfn##Name(window,##__VA_ARGS__); }
#define INVOKE_WINDOW_EVENT(Name, ...)\
if (window->callbacks.Name) { window->callbacks.Name(window,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _FreeContext_OpenGL_X11(Window window)
{
    // destroy GLX context
    _libGLX.glXMakeCurrent(_X11.dpy, window->x11.win, 0);
    _libGLX.glXDestroyContext(_X11.dpy, window->x11.glrc);
    return true;
}

bool _MakeCurrent_OpenGL_X11(Window window)
{
    // make GLX context current
    if (!_libGLX.glXMakeCurrent(_X11.dpy, window->x11.win, window->x11.glrc))
    {
        printf("ERROR: failed to make GLX context current\n");
        return false;
    }
    return true;
}

bool _SwapBuffers_OpenGL_X11(Window window)
{
    // swap GLX buffers
    _libGLX.glXSwapBuffers(_X11.dpy, window->x11.win);
    return true;
}

bool _InitContext_OpenGL_X11(Window window)
{
    // initialize GLX module
    if (!_LoadModule_GLX()) return false;

    // set the GLX colormap in window
    XSetWindowAttributes swa;
    swa.colormap = _GLX.cmap;
    _libX11.XChangeWindowAttributes(_X11.dpy, window->x11.win, CWColormap, &swa);

    // create a new GLX rendering context
    window->x11.glrc = _libGLX.glXCreateNewContext(_X11.dpy, _GLX.fbc, GLX_RGBA_TYPE, 0, True);
    if (!window->x11.glrc || !_libGLX.glXMakeCurrent(_X11.dpy, window->x11.win, window->x11.glrc))
    {
        printf("ERROR: failed to create GLX context\n");
        return false;
    }

    // finalize the GLX initialization and return
    window->pfnFreeContext = _FreeContext_OpenGL_X11;
    window->pfnMakeCurrent = _MakeCurrent_OpenGL_X11;
    window->pfnSwapBuffers = _SwapBuffers_OpenGL_X11;
    INVOKE_WINDOW_EVENT(OnWindowCreate)
    _libX11.XMapWindow(_X11.dpy, window->x11.win);
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_X11(const WindowCreateInfo* pCreateInfo, Window window)
{
    // initialize X11 module
    if (!_LoadModule_X11()) return false;

    // create a new X server window
    XSetWindowAttributes attributes = {};
    attributes.event_mask |= ExposureMask;
    attributes.event_mask |= KeyPressMask;
    attributes.event_mask |= KeyReleaseMask;
    attributes.event_mask |= StructureNotifyMask;
    attributes.background_pixel = 0xff000000;
    window->x11.win = _libX11.XCreateWindow(
        _X11.dpy,
        _X11.root,
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
    if (!window->x11.win)
    {
        printf("ERROR: failed to create X11 window\n");
        return false;
    }

    // set X11 protocols and save context
    _libX11.XSetWMProtocols(_X11.dpy, window->x11.win, &_X11.wmDeleteWindow, 1);
    _libX11.XSaveContext(_X11.dpy, window->x11.win, _X11.ctx, (char*)window);

    // set X11 callbacks and implementation
    if (pCreateInfo->pCallbacks) memcpy(&window->callbacks, pCreateInfo->pCallbacks, sizeof(WindowCallbacks));
    window->pfnDestroyWindow = _DestroyWindow_X11;

    // initialize the graphics rendering context
    if (_InitContext_OpenGL_X11(window)) return true;
    printf("ERROR: failed to create X11 rendering context\n");
    _libX11.XDeleteContext(_X11.dpy, window->x11.win, _X11.ctx);
    _libX11.XDestroyWindow(_X11.dpy, window->x11.win);
    return false;
}

bool _DestroyWindow_X11(Window window)
{
    // destroy the X server window
    _libX11.XDestroyWindow(_X11.dpy, window->x11.win);
    return true;
}

bool _ReadWindowEvents_X11()
{
    // release the process to the OS for a bit
    sleep(0);

    // iterate through all queued X server messages
    XEvent event;
    Window window;
    _libX11.XPending(_X11.dpy);
    while (_X11.dpy->qlen)
    {
        // get the next X server event
        _libX11.XNextEvent(_X11.dpy, &event);

        // skip event that don't have a window
        if (_libX11.XFindContext(_X11.dpy, event.xany.window, _X11.ctx, (XPointer*)&window)) continue;

        // translate the current window event by type
        switch (event.type)
        {
            case Expose:
                INVOKE_WINDOW_IMPL(MakeCurrent)
                INVOKE_WINDOW_EVENT(OnWindowPaint)
                INVOKE_WINDOW_IMPL(SwapBuffers)
                break;
            case ClientMessage:
                if (event.xclient.data.l[0] == _X11.wmDeleteWindow)
                    //INVOKE_WINDOW_EVENT(OnWindowClose)
                    return false;
                break;
            default:
                break;
        }
    }

    // flush all events in X server
    _libX11.XFlush(_X11.dpy);
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //