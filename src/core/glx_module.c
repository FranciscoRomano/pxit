// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include <dlfcn.h>
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_glx _glx = { NULL };

void* _Loader_glx(const char* name)
{
    void* p = (void*)_libGLX.glXGetProcAddress(name);
    if (p == (void*) 0) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 1) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 2) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 3) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*)-1) return (void*)dlsym(_libGLX.so, name);
    return p;
}

bool _FreeModule_glx()
{
    // check if module was unloaded
    if (!_glx.OK) return false;

    // unload and reset module handle
    _free_libGLX_so();
    _glx.OK = false;
    return true;
}

bool _LoadModule_glx()
{
    // check if module was loaded
    if (_glx.OK) return true;

    // load all module dependencies
    if (!_x11.OK)
    {
        printf("ERROR: unitialized module 'X11'\n");
        return false;
    }
    if (!_load_libGLX_so())
    {
        printf("ERROR: failed to load library 'libGLX.so'\n");
        return false;
    }
    if (!_LoadLibrary_gles(_Loader_glx))
    {
        printf("ERROR: failed to load library 'GLES'\n");
        return false;
    }

    _glx.OK = true;
    return true;
}

bool _CreateContext_glx(XWindow win, GLXContext* ctx, XColormap* cmap)
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
    XWindow root = _libX11.XDefaultRootWindow(_x11.display);
    (*cmap) = _libX11.XCreateColormap(_x11.display, root, vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = *cmap;
    _libX11.XChangeWindowAttributes(_x11.display, win, CWColormap, &swa);
    (*ctx) = _libGLX.glXCreateNewContext(_x11.display, fbc, GLX_RGBA_TYPE, 0, True);
    assert(*cmap, "failed to create compatible colormap");
    assert(*ctx, "failed to create GLX context");
    _libX11.XFree(vi);
    return true;
}