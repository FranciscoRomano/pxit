// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _libGLX
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _libGLX_so _libGLX = { NULL };

bool _free_libGLX_so()
{
    // check if library was unloaded
    if (!_libGLX.so) return true;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
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
        LIBRARY_MODULE_LOAD(paths[i])
        LIBRARY_MODULE_RSYM(glXChooseVisual)
        LIBRARY_MODULE_RSYM(glXCreateContext)
        LIBRARY_MODULE_RSYM(glXDestroyContext)
        LIBRARY_MODULE_RSYM(glXMakeCurrent)
        LIBRARY_MODULE_RSYM(glXCopyContext)
        LIBRARY_MODULE_RSYM(glXSwapBuffers)
        LIBRARY_MODULE_RSYM(glXCreateGLXPixmap)
        LIBRARY_MODULE_RSYM(glXDestroyGLXPixmap)
        LIBRARY_MODULE_RSYM(glXQueryExtension)
        LIBRARY_MODULE_RSYM(glXQueryVersion)
        LIBRARY_MODULE_RSYM(glXIsDirect)
        LIBRARY_MODULE_RSYM(glXGetConfig)
        LIBRARY_MODULE_RSYM(glXGetCurrentContext)
        LIBRARY_MODULE_RSYM(glXGetCurrentDrawable)
        LIBRARY_MODULE_RSYM(glXWaitGL)
        LIBRARY_MODULE_RSYM(glXWaitX)
        LIBRARY_MODULE_RSYM(glXUseXFont)
        LIBRARY_MODULE_RSYM(glXQueryExtensionsString)
        LIBRARY_MODULE_RSYM(glXQueryServerString)
        LIBRARY_MODULE_RSYM(glXGetClientString)
        LIBRARY_MODULE_RSYM(glXGetCurrentDisplay)
        LIBRARY_MODULE_RSYM(glXChooseFBConfig)
        LIBRARY_MODULE_RSYM(glXGetFBConfigAttrib)
        LIBRARY_MODULE_RSYM(glXGetFBConfigs)
        LIBRARY_MODULE_RSYM(glXGetVisualFromFBConfig)
        LIBRARY_MODULE_RSYM(glXCreateWindow)
        LIBRARY_MODULE_RSYM(glXDestroyWindow)
        LIBRARY_MODULE_RSYM(glXCreatePixmap)
        LIBRARY_MODULE_RSYM(glXDestroyPixmap)
        LIBRARY_MODULE_RSYM(glXCreatePbuffer)
        LIBRARY_MODULE_RSYM(glXDestroyPbuffer)
        LIBRARY_MODULE_RSYM(glXQueryDrawable)
        LIBRARY_MODULE_RSYM(glXCreateNewContext)
        LIBRARY_MODULE_RSYM(glXMakeContextCurrent)
        LIBRARY_MODULE_RSYM(glXGetCurrentReadDrawable)
        LIBRARY_MODULE_RSYM(glXQueryContext)
        LIBRARY_MODULE_RSYM(glXSelectEvent)
        LIBRARY_MODULE_RSYM(glXGetSelectedEvent)
        LIBRARY_MODULE_RSYM(glXGetProcAddressARB)
        LIBRARY_MODULE_RSYM(glXGetProcAddress)
        LIBRARY_MODULE_RSYM(glXAllocateMemoryNV)
        LIBRARY_MODULE_RSYM(glXFreeMemoryNV)
        LIBRARY_MODULE_RSYM(glXBindTexImageARB)
        LIBRARY_MODULE_RSYM(glXReleaseTexImageARB)
        LIBRARY_MODULE_RSYM(glXDrawableAttribARB)
        LIBRARY_MODULE_RSYM(glXGetFrameUsageMESA)
        LIBRARY_MODULE_RSYM(glXBeginFrameTrackingMESA)
        LIBRARY_MODULE_RSYM(glXEndFrameTrackingMESA)
        LIBRARY_MODULE_RSYM(glXQueryFrameTrackingMESA)
        LIBRARY_MODULE_RSYM(glXSwapIntervalMESA)
        LIBRARY_MODULE_RSYM(glXGetSwapIntervalMESA)
        LIBRARY_MODULE_RSYM(glXBindTexImageEXT)
        LIBRARY_MODULE_RSYM(glXReleaseTexImageEXT)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //