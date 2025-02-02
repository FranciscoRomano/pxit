// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_glx(const WindowCreateInfo* pCreateInfo, Window window)
{
    // load all module dependencies
    if (!_LoadModule_glx()) return false;

    // select best framebuffer configuration
    int count;
    int screen = _libX11.XDefaultScreen(_x11.display);
    static int attribs[] = {
        GLX_X_RENDERABLE,  GLX_TRUE,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_RENDER_TYPE,   GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
        GLX_RED_SIZE,      8,
        GLX_GREEN_SIZE,    8,
        GLX_BLUE_SIZE,     8,
        GLX_ALPHA_SIZE,    8,
        GLX_DEPTH_SIZE,    24,
        GLX_STENCIL_SIZE,  8,
        GLX_DOUBLEBUFFER,  GLX_TRUE,
        0
    };
    GLXFBConfig* fbc_array = _libGLX.glXChooseFBConfig(_x11.display, screen, attribs, &count);
    assert(count > 0 && fbc_array, "failed to select GLX framebuffer configuration");
    GLXFBConfig fbc = fbc_array[0];
    _libX11.XFree(fbc_array);

    // create a compatible GLX rendering context
    XVisualInfo* vi = _libGLX.glXGetVisualFromFBConfig(_x11.display, fbc);
    window->x11.cmap = _libX11.XCreateColormap(_x11.display, window->x11.win, vi->visual, AllocNone);
    _libX11.XFree(vi);
    assert(window->x11.cmap, "failed to create GLX compatible colormap")
    XSetWindowAttributes swa;
    swa.colormap = window->x11.cmap;
    _libX11.XChangeWindowAttributes(_x11.display, window->x11.win, CWColormap, &swa);
    window->x11.glx = _libGLX.glXCreateNewContext(_x11.display, fbc, GLX_RGBA_TYPE, 0, True);
    assert(window->x11.glx, "failed to create GLX rendering context");
    _libGLX.glXMakeCurrent(_x11.display, window->x11.win, window->x11.glx);
    window->impl.DestroyWindow = _DestroyWindow_glx;
    return true;
}

bool _DestroyWindow_glx(Window window)
{
    // destroy the GLX rendering context and resources
    _libGLX.glXMakeCurrent(_x11.display, window->x11.win, NULL);
    _libGLX.glXDestroyContext(_x11.display, window->x11.glx);
    _libX11.XFree(window->x11.cmap);
    return _DestroyWindow_x11(window);
}