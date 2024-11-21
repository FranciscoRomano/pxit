// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#define LOAD_LIBRARY_SYMBOL(Name)\
lib->Name = dlsym(lib->handle, #Name);\
if (!lib->Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); exit(EXIT_FAILURE); }
// -------------------------------------------------------------------------------------------------------------------------- //

bool FreeLibraryGLX(LibraryGLX* lib)
{
    // check if library was unloaded
    if (!lib->handle) return false;

    // unload and reset library handle
    dlclose(lib->handle);
    lib->handle = NULL;
    return true;
}

bool LoadLibraryGLX(LibraryGLX* lib)
{
    // check if library was loaded
    if (lib->handle) return true;

    // iterate through all library paths
    const char* paths[] = {
        "libGLX.so.0.0.0",
        "libGLX.so.0",
        "libGLX.so",
        NULL
    };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and required symbols
        lib->handle = dlopen(paths[i], RTLD_LAZY);
        if (lib->handle == NULL) continue;
        LOAD_LIBRARY_SYMBOL(glXChooseVisual)
        LOAD_LIBRARY_SYMBOL(glXCreateContext)
        LOAD_LIBRARY_SYMBOL(glXDestroyContext)
        LOAD_LIBRARY_SYMBOL(glXMakeCurrent)
        LOAD_LIBRARY_SYMBOL(glXCopyContext)
        LOAD_LIBRARY_SYMBOL(glXSwapBuffers)
        LOAD_LIBRARY_SYMBOL(glXCreateGLXPixmap)
        LOAD_LIBRARY_SYMBOL(glXDestroyGLXPixmap)
        LOAD_LIBRARY_SYMBOL(glXQueryExtension)
        LOAD_LIBRARY_SYMBOL(glXQueryVersion)
        LOAD_LIBRARY_SYMBOL(glXIsDirect)
        LOAD_LIBRARY_SYMBOL(glXGetConfig)
        LOAD_LIBRARY_SYMBOL(glXGetCurrentContext)
        LOAD_LIBRARY_SYMBOL(glXGetCurrentDrawable)
        LOAD_LIBRARY_SYMBOL(glXWaitGL)
        LOAD_LIBRARY_SYMBOL(glXWaitX)
        LOAD_LIBRARY_SYMBOL(glXUseXFont)
        LOAD_LIBRARY_SYMBOL(glXQueryExtensionsString)
        LOAD_LIBRARY_SYMBOL(glXQueryServerString)
        LOAD_LIBRARY_SYMBOL(glXGetClientString)
        LOAD_LIBRARY_SYMBOL(glXGetCurrentDisplay)
        LOAD_LIBRARY_SYMBOL(glXChooseFBConfig)
        LOAD_LIBRARY_SYMBOL(glXGetFBConfigAttrib)
        LOAD_LIBRARY_SYMBOL(glXGetFBConfigs)
        LOAD_LIBRARY_SYMBOL(glXGetVisualFromFBConfig)
        LOAD_LIBRARY_SYMBOL(glXCreateWindow)
        LOAD_LIBRARY_SYMBOL(glXDestroyWindow)
        LOAD_LIBRARY_SYMBOL(glXCreatePixmap)
        LOAD_LIBRARY_SYMBOL(glXDestroyPixmap)
        LOAD_LIBRARY_SYMBOL(glXCreatePbuffer)
        LOAD_LIBRARY_SYMBOL(glXDestroyPbuffer)
        LOAD_LIBRARY_SYMBOL(glXQueryDrawable)
        LOAD_LIBRARY_SYMBOL(glXCreateNewContext)
        LOAD_LIBRARY_SYMBOL(glXMakeContextCurrent)
        LOAD_LIBRARY_SYMBOL(glXGetCurrentReadDrawable)
        LOAD_LIBRARY_SYMBOL(glXQueryContext)
        LOAD_LIBRARY_SYMBOL(glXSelectEvent)
        LOAD_LIBRARY_SYMBOL(glXGetSelectedEvent)
        LOAD_LIBRARY_SYMBOL(glXGetProcAddressARB)
        LOAD_LIBRARY_SYMBOL(glXGetProcAddress)
        LOAD_LIBRARY_SYMBOL(glXAllocateMemoryNV)
        LOAD_LIBRARY_SYMBOL(glXFreeMemoryNV)
        LOAD_LIBRARY_SYMBOL(glXBindTexImageARB)
        LOAD_LIBRARY_SYMBOL(glXReleaseTexImageARB)
        LOAD_LIBRARY_SYMBOL(glXDrawableAttribARB)
        LOAD_LIBRARY_SYMBOL(glXGetFrameUsageMESA)
        LOAD_LIBRARY_SYMBOL(glXBeginFrameTrackingMESA)
        LOAD_LIBRARY_SYMBOL(glXEndFrameTrackingMESA)
        LOAD_LIBRARY_SYMBOL(glXQueryFrameTrackingMESA)
        LOAD_LIBRARY_SYMBOL(glXSwapIntervalMESA)
        LOAD_LIBRARY_SYMBOL(glXGetSwapIntervalMESA)
        LOAD_LIBRARY_SYMBOL(glXBindTexImageEXT)
        LOAD_LIBRARY_SYMBOL(glXReleaseTexImageEXT)
        return true;
    }
    return false;
}
