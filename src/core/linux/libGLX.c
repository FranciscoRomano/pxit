// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_NAME libGLX
#define LIBRARY_HINT "libGLX.so.0.0.0"
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

DEFINE_LIBRARY(
    // #include <GL/glx.h>
    REQUIRED_SYMBOL(glXChooseVisual)
    REQUIRED_SYMBOL(glXCreateContext)
    REQUIRED_SYMBOL(glXDestroyContext)
    REQUIRED_SYMBOL(glXMakeCurrent)
    REQUIRED_SYMBOL(glXCopyContext)
    REQUIRED_SYMBOL(glXSwapBuffers)
    REQUIRED_SYMBOL(glXCreateGLXPixmap)
    REQUIRED_SYMBOL(glXDestroyGLXPixmap)
    REQUIRED_SYMBOL(glXQueryExtension)
    REQUIRED_SYMBOL(glXQueryVersion)
    REQUIRED_SYMBOL(glXIsDirect)
    REQUIRED_SYMBOL(glXGetConfig)
    REQUIRED_SYMBOL(glXGetCurrentContext)
    REQUIRED_SYMBOL(glXGetCurrentDrawable)
    REQUIRED_SYMBOL(glXWaitGL)
    REQUIRED_SYMBOL(glXWaitX)
    REQUIRED_SYMBOL(glXUseXFont)
    REQUIRED_SYMBOL(glXQueryExtensionsString)
    REQUIRED_SYMBOL(glXQueryServerString)
    REQUIRED_SYMBOL(glXGetClientString)
    REQUIRED_SYMBOL(glXGetCurrentDisplay)
    REQUIRED_SYMBOL(glXChooseFBConfig)
    REQUIRED_SYMBOL(glXGetFBConfigAttrib)
    REQUIRED_SYMBOL(glXGetFBConfigs)
    REQUIRED_SYMBOL(glXGetVisualFromFBConfig)
    REQUIRED_SYMBOL(glXCreateWindow)
    REQUIRED_SYMBOL(glXDestroyWindow)
    REQUIRED_SYMBOL(glXCreatePixmap)
    REQUIRED_SYMBOL(glXDestroyPixmap)
    REQUIRED_SYMBOL(glXCreatePbuffer)
    REQUIRED_SYMBOL(glXDestroyPbuffer)
    REQUIRED_SYMBOL(glXQueryDrawable)
    REQUIRED_SYMBOL(glXCreateNewContext)
    REQUIRED_SYMBOL(glXMakeContextCurrent)
    REQUIRED_SYMBOL(glXGetCurrentReadDrawable)
    REQUIRED_SYMBOL(glXQueryContext)
    REQUIRED_SYMBOL(glXSelectEvent)
    REQUIRED_SYMBOL(glXGetSelectedEvent)
    REQUIRED_SYMBOL(glXGetProcAddressARB)
    REQUIRED_SYMBOL(glXGetProcAddress)
    OPTIONAL_SYMBOL(glXAllocateMemoryNV)
    OPTIONAL_SYMBOL(glXFreeMemoryNV)
    OPTIONAL_SYMBOL(glXBindTexImageARB)
    OPTIONAL_SYMBOL(glXReleaseTexImageARB)
    OPTIONAL_SYMBOL(glXDrawableAttribARB)
    OPTIONAL_SYMBOL(glXGetFrameUsageMESA)
    OPTIONAL_SYMBOL(glXBeginFrameTrackingMESA)
    OPTIONAL_SYMBOL(glXEndFrameTrackingMESA)
    OPTIONAL_SYMBOL(glXQueryFrameTrackingMESA)
    OPTIONAL_SYMBOL(glXSwapIntervalMESA)
    OPTIONAL_SYMBOL(glXGetSwapIntervalMESA)
    OPTIONAL_SYMBOL(glXBindTexImageEXT)
    OPTIONAL_SYMBOL(glXReleaseTexImageEXT)
)

// -------------------------------------------------------------------------------------------------------------------------- //