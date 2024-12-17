// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
#define LOAD_REQUIRED_SYMBOL(Name)\
_GLX.Name = dlsym(_GLX.handle, #Name);\
if (!_GLX.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_GLX _GLX = { NULL };

void* _Loader_GLX(const char* name)
{
    void* p = (void*)_GLX.glXGetProcAddress(name);
    if (p == (void*) 0) return (void*)dlsym(_GLX.handle, name);
    if (p == (void*) 1) return (void*)dlsym(_GLX.handle, name);
    if (p == (void*) 2) return (void*)dlsym(_GLX.handle, name);
    if (p == (void*) 3) return (void*)dlsym(_GLX.handle, name);
    if (p == (void*)-1) return (void*)dlsym(_GLX.handle, name);
    return p;
}

bool _FreeModule_GLX()
{
    // check if module was unloaded
    if (!_GLX.handle) return false;

    // unload and reset module handle
    _GLX.handle = NULL;
    return true;
}

bool _LoadModule_GLX()
{
    // check if module was loaded
    if (_GLX.handle) return true;

    // load all module dependencies
    if (!_LoadModule_X11())
    {
        printf("ERROR: failed to load X11 module\n");
        return false;
    }

    // iterate through all module paths
    const char* paths[] = {
        "libGLX.so.0.0.0",
        "libGLX.so.0.0",
        "libGLX.so.0",
        "libGLX.so",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading module and any symbols
        _GLX.handle = dlopen(paths[i], RTLD_LAZY);
        if (_GLX.handle == NULL) continue;
        LOAD_REQUIRED_SYMBOL(glXChooseVisual)
        LOAD_REQUIRED_SYMBOL(glXCreateContext)
        LOAD_REQUIRED_SYMBOL(glXDestroyContext)
        LOAD_REQUIRED_SYMBOL(glXMakeCurrent)
        LOAD_REQUIRED_SYMBOL(glXCopyContext)
        LOAD_REQUIRED_SYMBOL(glXSwapBuffers)
        LOAD_REQUIRED_SYMBOL(glXCreateGLXPixmap)
        LOAD_REQUIRED_SYMBOL(glXDestroyGLXPixmap)
        LOAD_REQUIRED_SYMBOL(glXQueryExtension)
        LOAD_REQUIRED_SYMBOL(glXQueryVersion)
        LOAD_REQUIRED_SYMBOL(glXIsDirect)
        LOAD_REQUIRED_SYMBOL(glXGetConfig)
        LOAD_REQUIRED_SYMBOL(glXGetCurrentContext)
        LOAD_REQUIRED_SYMBOL(glXGetCurrentDrawable)
        LOAD_REQUIRED_SYMBOL(glXWaitGL)
        LOAD_REQUIRED_SYMBOL(glXWaitX)
        LOAD_REQUIRED_SYMBOL(glXUseXFont)
        LOAD_REQUIRED_SYMBOL(glXQueryExtensionsString)
        LOAD_REQUIRED_SYMBOL(glXQueryServerString)
        LOAD_REQUIRED_SYMBOL(glXGetClientString)
        LOAD_REQUIRED_SYMBOL(glXGetCurrentDisplay)
        LOAD_REQUIRED_SYMBOL(glXChooseFBConfig)
        LOAD_REQUIRED_SYMBOL(glXGetFBConfigAttrib)
        LOAD_REQUIRED_SYMBOL(glXGetFBConfigs)
        LOAD_REQUIRED_SYMBOL(glXGetVisualFromFBConfig)
        LOAD_REQUIRED_SYMBOL(glXCreateWindow)
        LOAD_REQUIRED_SYMBOL(glXDestroyWindow)
        LOAD_REQUIRED_SYMBOL(glXCreatePixmap)
        LOAD_REQUIRED_SYMBOL(glXDestroyPixmap)
        LOAD_REQUIRED_SYMBOL(glXCreatePbuffer)
        LOAD_REQUIRED_SYMBOL(glXDestroyPbuffer)
        LOAD_REQUIRED_SYMBOL(glXQueryDrawable)
        LOAD_REQUIRED_SYMBOL(glXCreateNewContext)
        LOAD_REQUIRED_SYMBOL(glXMakeContextCurrent)
        LOAD_REQUIRED_SYMBOL(glXGetCurrentReadDrawable)
        LOAD_REQUIRED_SYMBOL(glXQueryContext)
        LOAD_REQUIRED_SYMBOL(glXSelectEvent)
        LOAD_REQUIRED_SYMBOL(glXGetSelectedEvent)
        LOAD_REQUIRED_SYMBOL(glXGetProcAddressARB)
        LOAD_REQUIRED_SYMBOL(glXGetProcAddress)

        // select best GLX framebuffer configuration
        int count;
        int screen = _X11.XDefaultScreen(_X11.dpy);
        static int attribs[] = {
            GLX_X_RENDERABLE,  True,
            GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
            GLX_RENDER_TYPE,   GLX_RGBA_BIT,
            GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
            GLX_RED_SIZE,      8,
            GLX_GREEN_SIZE,    8,
            GLX_BLUE_SIZE,     8,
            GLX_ALPHA_SIZE,    8,
            GLX_DEPTH_SIZE,    24,
            GLX_STENCIL_SIZE,  8,
            GLX_DOUBLEBUFFER,  True,
            None
        };
        GLXFBConfig* fbc_array = _GLX.glXChooseFBConfig(_X11.dpy, screen, attribs, &count);
        if (count == 0 || !fbc_array)
        {
            printf("ERROR: failed to select GLX framebuffer configuration\n");
            return false;
        }
        _GLX.fbc = fbc_array[0];
        _X11.XFree(fbc_array);


        // select best GLX visual information with FBC
        XVisualInfo* vi = _GLX.glXGetVisualFromFBConfig(_X11.dpy, _GLX.fbc);
        if (!vi)
        {
            printf("ERROR: failed to select visual information\n");
            return false;
        }

        // create a GLX compatible colormap in best visual
        Window root = _X11.XScreenOfDisplay(_X11.dpy, vi->screen)->root;
        _GLX.cmap = _X11.XCreateColormap(_X11.dpy, root, vi->visual, AllocNone);
        _X11.XFree(vi);
        if (!_GLX.cmap)
        {
            printf("ERROR: failed to create GLX colormap.\n");
            return false;
        }

        // finally, load the OpenGL ES module and all symbols
        if (!_LoadModule_GLES(_Loader_GLX))
        {
            printf("ERROR: failed to load GLES module\n");
            return false;
        }

        return true;
    }

    return false;
}