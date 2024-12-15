// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define INVOKE_SURFACE_IMPL(Name, ...)\
if (surface->pfn##Name) { surface->pfn##Name(surface,##__VA_ARGS__); }
#define INVOKE_SURFACE_EVENT(Name, ...)\
if (surface->callbacks.Name) { surface->callbacks.Name(surface,##__VA_ARGS__); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool _FreeContext_OpenGL_X11(Surface surface)
{
    // destroy GLX context
    _GLX.glXMakeCurrent(_X11.dpy, 0, 0);
    _GLX.glXDestroyContext(_X11.dpy, surface->x11.glrc);

    // destroy window colormap
    XSetWindowAttributes swa;
    swa.colormap = 0;
    _X11.XChangeWindowAttributes(_X11.dpy, surface->x11.win, CWColormap, &swa);
    _X11.XFreeColormap(_X11.dpy, surface->x11.cmap);
    return true;
}

bool _MakeCurrent_OpenGL_X11(Surface surface)
{
    // make GLX context current
    if (!_GLX.glXMakeCurrent(_X11.dpy, surface->x11.win, surface->x11.glrc))
    {
        printf("ERROR: failed to make GLX context current\n");
        return false;
    }
    return true;
}

bool _SwapBuffers_OpenGL_X11(Surface surface)
{
    // swap GLX buffers
    _GLX.glXSwapBuffers(_X11.dpy, surface->x11.win);
    return true;
}

bool _InitContext_OpenGL_X11(Surface surface)
{
    // initialize GLX module
    if (!_LoadModule_GLX()) return false;
    
    // select GLX visual information
    XVisualInfo* vi = _GLX.glXGetVisualFromFBConfig(_X11.dpy, _GLX.fbc);
    if (!vi)
    {
        printf("ERROR: failed to select visual information\n");
        return false;
    }

    // create a GLX compatible colormap
    Window root = _X11.XScreenOfDisplay(_X11.dpy, vi->screen)->root;
    surface->x11.cmap = _X11.XCreateColormap(_X11.dpy, root, vi->visual, AllocNone);
    if (!surface->x11.cmap)
    {
        printf("ERROR: failed to create GLX compatible colormap\n");
        _X11.XFree(vi);
        return false;
    }

    // set compatible colormap to window
    XSetWindowAttributes swa;
    swa.colormap = surface->x11.cmap;
    _X11.XChangeWindowAttributes(_X11.dpy, surface->x11.win, CWColormap, &swa);
    _X11.XFree(vi);

    // create a new GLX rendering context
    surface->x11.glrc = _GLX.glXCreateNewContext(_X11.dpy, _GLX.fbc, GLX_RGBA_TYPE, 0, True);
    if (!surface->x11.glrc)
    {
        printf("ERROR: failed to create GLX context\n");
        swa.colormap = 0;
        _X11.XChangeWindowAttributes(_X11.dpy, surface->x11.win, CWColormap, &swa);
        _X11.XFreeColormap(_X11.dpy, surface->x11.cmap);
        return false;
    }

    // finalize the GLX initialization and return
    surface->pfnFreeContext = _FreeContext_OpenGL_X11;
    surface->pfnMakeCurrent = _MakeCurrent_OpenGL_X11;
    surface->pfnSwapBuffers = _SwapBuffers_OpenGL_X11;
    INVOKE_SURFACE_EVENT(OnSurfaceCreate)
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateSurface_X11(const SurfaceCreateInfo* pCreateInfo, Surface surface)
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
    surface->x11.win = _X11.XCreateWindow(
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
    if (!surface->x11.win)
    {
        printf("ERROR: failed to create X11 window\n");
        return false;
    }

    // set X11 protocols and save context
    _X11.XSetWMProtocols(_X11.dpy, surface->x11.win, &_X11.wmDeleteWindow, 1);
    _X11.XSaveContext(_X11.dpy, surface->x11.win, _X11.ctx, (char*)surface);

    // set X11 callbacks and implementation
    if (pCreateInfo->pCallbacks) memcpy(&surface->callbacks, pCreateInfo->pCallbacks, sizeof(SurfaceCallbacks));
    surface->pfnDestroySurface = _DestroySurface_X11;

    // initialize the graphics rendering context
    if (_InitContext_OpenGL_X11(surface)) return true;
    printf("ERROR: failed to create X11 rendering context\n");
    _X11.XDeleteContext(_X11.dpy, surface->x11.win, _X11.ctx);
    _X11.XDestroyWindow(_X11.dpy, surface->x11.win);
    return false;
}

bool _DestroySurface_X11(Surface surface)
{
    // destroy the X server window
    _X11.XDestroyWindow(_X11.dpy, surface->x11.win);
    return true;
}

bool _ReadSurfaceEvents_X11()
{
    // release the process to the OS for a bit
    sleep(0);

    // iterate through all queued X server messages
    XEvent event;
    Surface surface;
    _X11.XPending(_X11.dpy);
    while (QLength(_X11.dpy))
    {
        // get the next X server event
        _X11.XNextEvent(_X11.dpy, &event);

        // skip event that don't have a window
        if (_X11.XFindContext(_X11.dpy, event.xany.window, _X11.ctx, (XPointer*)&surface)) continue;

        // translate the current window event by type
        switch (event.type)
        {
            case ClientMessage:
                if (event.xclient.data.l[0] == _X11.wmDeleteWindow)
                    //INVOKE_SURFACE_EVENT(OnSurfaceClose)
                    return false;
                break;
            default:
                break;
        }
    }

    // flush all events in X server
    _X11.XFlush(_X11.dpy);
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //