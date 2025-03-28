// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

bool _CreateWindow_glx(const WindowCreateInfo* pCreateInfo, Window window)
{
    // load all module dependencies
    if (!_LoadModule_glx()) return false;

    // select best framebuffer configuration
    int count;
    int screen = XDefaultScreen(x11.display);
    static int attribs[] = {
        GLX_X_RENDERABLE,  1,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_RENDER_TYPE,   GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
        GLX_RED_SIZE,      8,
        GLX_GREEN_SIZE,    8,
        GLX_BLUE_SIZE,     8,
        GLX_ALPHA_SIZE,    8,
        GLX_DEPTH_SIZE,    24,
        GLX_STENCIL_SIZE,  8,
        GLX_DOUBLEBUFFER,  1,
        0
    };
    GLXFBConfig* fbc_array = glXChooseFBConfig(x11.display, screen, attribs, &count);
    if (!(count > 0 && fbc_array)) return failure("failed to select GLX framebuffer configuration");
    GLXFBConfig fbc = fbc_array[0];
    XFree(fbc_array);

    // create a compatible GLX rendering context
    XVisualInfo* vi = glXGetVisualFromFBConfig(x11.display, fbc);
    window->x11.cmap = XCreateColormap(x11.display, window->x11.win, vi->visual, AllocNone);
    XFree(vi);
    if (!window->x11.cmap) return failure("failed to create GLX compatible colormap");
    XSetWindowAttributes swa;
    swa.colormap = window->x11.cmap;
    XChangeWindowAttributes(x11.display, window->x11.win, CWColormap, &swa);
    window->x11.glx = glXCreateNewContext(x11.display, fbc, GLX_RGBA_TYPE, 0, 1);
    if (!window->x11.glx) return failure("failed to create GLX rendering context");
    glXMakeCurrent(x11.display, window->x11.win, window->x11.glx);
    window->impl.pDestroyWindow = _DestroyWindow_glx;
    return true;
}

bool _DestroyWindow_glx(Window window)
{
    // destroy the GLX rendering context and resources
    glXMakeCurrent(x11.display, window->x11.win, NULL);
    glXDestroyContext(x11.display, window->x11.glx);
    XFree((void*)window->x11.cmap);
    return x11_DestroyWindow(window);
}

bool _DrawWindow_glx(Window window)
{
    // set GLX rendering context as current
    glXMakeCurrent(x11.display, window->x11.win, window->x11.glx);

    // invoke "OnWindowDraw" event and flush
    // window_evnt(OnWindowDraw)
    // glFlush();

    // swap the back buffer with the main buffer
    glXSwapBuffers(x11.display, window->x11.win);
    return true;
}