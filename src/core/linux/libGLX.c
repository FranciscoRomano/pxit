// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "libGLX.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LOAD_REQUIRED_SYMBOL(Name)\
_libGLX.Name = dlsym(_libGLX.so, #Name);\
if (!_libGLX.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _libGLX_so _libGLX = { NULL };

bool _free_libGLX_so()
{
    // check if library was unloaded
    if (!_libGLX.so) return false;

    // unload and reset library handle
    dlclose(_libGLX.so);
    _libGLX.so = NULL;
    return true;
}

bool _load_libGLX_so()
{
    // check if library was loaded
    if (_libGLX.so) return true;

    // iterate through all library paths
    const char* paths[] = { "libGLX.so.0.0.0", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        _libGLX.so = dlopen(paths[i], RTLD_LAZY);
        if (_libGLX.so == NULL) continue;
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
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //