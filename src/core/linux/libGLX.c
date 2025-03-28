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
    MODULE_FREE()
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
        MODULE_LOAD(paths[i])
        MODULE_RSYM(glXChooseVisual)
        MODULE_RSYM(glXCreateContext)
        MODULE_RSYM(glXDestroyContext)
        MODULE_RSYM(glXMakeCurrent)
        MODULE_RSYM(glXCopyContext)
        MODULE_RSYM(glXSwapBuffers)
        MODULE_RSYM(glXCreateGLXPixmap)
        MODULE_RSYM(glXDestroyGLXPixmap)
        MODULE_RSYM(glXQueryExtension)
        MODULE_RSYM(glXQueryVersion)
        MODULE_RSYM(glXIsDirect)
        MODULE_RSYM(glXGetConfig)
        MODULE_RSYM(glXGetCurrentContext)
        MODULE_RSYM(glXGetCurrentDrawable)
        MODULE_RSYM(glXWaitGL)
        MODULE_RSYM(glXWaitX)
        MODULE_RSYM(glXUseXFont)
        MODULE_RSYM(glXQueryExtensionsString)
        MODULE_RSYM(glXQueryServerString)
        MODULE_RSYM(glXGetClientString)
        MODULE_RSYM(glXGetCurrentDisplay)
        MODULE_RSYM(glXChooseFBConfig)
        MODULE_RSYM(glXGetFBConfigAttrib)
        MODULE_RSYM(glXGetFBConfigs)
        MODULE_RSYM(glXGetVisualFromFBConfig)
        MODULE_RSYM(glXCreateWindow)
        MODULE_RSYM(glXDestroyWindow)
        MODULE_RSYM(glXCreatePixmap)
        MODULE_RSYM(glXDestroyPixmap)
        MODULE_RSYM(glXCreatePbuffer)
        MODULE_RSYM(glXDestroyPbuffer)
        MODULE_RSYM(glXQueryDrawable)
        MODULE_RSYM(glXCreateNewContext)
        MODULE_RSYM(glXMakeContextCurrent)
        MODULE_RSYM(glXGetCurrentReadDrawable)
        MODULE_RSYM(glXQueryContext)
        MODULE_RSYM(glXSelectEvent)
        MODULE_RSYM(glXGetSelectedEvent)
        MODULE_RSYM(glXGetProcAddressARB)
        MODULE_RSYM(glXGetProcAddress)
        MODULE_OSYM(glXAllocateMemoryNV)
        MODULE_OSYM(glXFreeMemoryNV)
        MODULE_OSYM(glXBindTexImageARB)
        MODULE_OSYM(glXReleaseTexImageARB)
        MODULE_OSYM(glXDrawableAttribARB)
        MODULE_OSYM(glXGetFrameUsageMESA)
        MODULE_OSYM(glXBeginFrameTrackingMESA)
        MODULE_OSYM(glXEndFrameTrackingMESA)
        MODULE_OSYM(glXQueryFrameTrackingMESA)
        MODULE_OSYM(glXSwapIntervalMESA)
        MODULE_OSYM(glXGetSwapIntervalMESA)
        MODULE_OSYM(glXBindTexImageEXT)
        MODULE_OSYM(glXReleaseTexImageEXT)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //