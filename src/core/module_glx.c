// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#include <dlfcn.h>
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_GLX _GLX = { NULL };

void* _Loader_GLX(const char* name)
{
    void* p = (void*)_libGLX.glXGetProcAddress(name);
    if (p == (void*) 0) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 1) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 2) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*) 3) return (void*)dlsym(_libGLX.so, name);
    if (p == (void*)-1) return (void*)dlsym(_libGLX.so, name);
    return p;
}

bool _FreeModule_GLX()
{
    // check if module was unloaded
    if (!_GLX.OK) return false;

    // unload and reset module handle
    _free_libGLX_so();
    _GLX.OK = false;
    return true;
}

bool _LoadModule_GLX()
{
    // check if module was loaded
    if (_GLX.OK) return true;

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

    // select best GLX framebuffer configuration
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
    if (count == 0 || !fbc_array)
    {
        printf("ERROR: failed to select GLX framebuffer configuration\n");
        return false;
    }
    _GLX.fbc = fbc_array[0];
    _libX11.XFree(fbc_array);

    // finally, load the OpenGL ES module and all symbols
    if (!_LoadLibrary_gles(_Loader_GLX))
    {
        printf("ERROR: failed to load GLES module\n");
        return false;
    }

    _GLX.OK = true;
    return true;
}