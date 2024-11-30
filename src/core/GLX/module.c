// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "../GLES/module.h"
#include "../X11/module.h"
#include "module.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
GLX.Name = dlsym(GLX.handle, #Name);\
if (!GLX.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct ModuleGLX GLX = { NULL };

void* private_loader_GLX(const char* name)
{
    void* p = (void*)GLX.glXGetProcAddress(name);
    if (p == (void*) 0) return (void*)dlsym(GLX.handle, name);
    if (p == (void*) 1) return (void*)dlsym(GLX.handle, name);
    if (p == (void*) 2) return (void*)dlsym(GLX.handle, name);
    if (p == (void*) 3) return (void*)dlsym(GLX.handle, name);
    if (p == (void*)-1) return (void*)dlsym(GLX.handle, name);
    return p;
}

bool FreeModuleGLX()
{
    // check if module was unloaded
    if (!GLX.handle) return false;

    // unload and reset module handle
    GLX.handle = NULL;
    return true;
}

bool LoadModuleGLX()
{
    // check if module was loaded
    if (GLX.handle) return true;

    // load all module dependencies
    if (!LoadModuleX11())
    {
        printf("ERROR: failed to load X11 module");
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
        GLX.handle = dlopen(paths[i], RTLD_LAZY);
        if (GLX.handle == NULL) continue;
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

        // finally, load the OpenGL ES module and all symbols
        if (!LoadModuleGLES(private_loader_GLX))
        {
            printf("ERROR: failed to load GLES module\n");
            return false;
        }

        return true;
    }

    return false;
}