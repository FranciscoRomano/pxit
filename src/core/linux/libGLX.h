// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_linux_libGLX_h__
#define __core_linux_libGLX_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "libGLX/glx.h"

/// @brief Represents the global context for the "libGLX.so" library.
extern struct _libGLX_so {
    void*                            so;
    XVisualInfo*                   (*glXChooseVisual)(XDisplay*,int32_t,int32_t*);
    GLXContext                     (*glXCreateContext)(XDisplay*,XVisualInfo*,GLXContext,int32_t);
    void                           (*glXDestroyContext)(XDisplay*,GLXContext);
    int32_t                        (*glXMakeCurrent)(XDisplay*,GLXDrawable,GLXContext);
    void                           (*glXCopyContext)(XDisplay*,GLXContext,GLXContext,uint64_t);
    void                           (*glXSwapBuffers)(XDisplay*,GLXDrawable);
    GLXPixmap                      (*glXCreateGLXPixmap)(XDisplay*,XVisualInfo*,XPixmap);
    void                           (*glXDestroyGLXPixmap)(XDisplay*,GLXPixmap);
    int32_t                        (*glXQueryExtension)(XDisplay*,int32_t*,int32_t*);
    int32_t                        (*glXQueryVersion)(XDisplay*,int32_t*,int32_t*);
    int32_t                        (*glXIsDirect)(XDisplay*,GLXContext);
    int32_t                        (*glXGetConfig)(XDisplay*,XVisualInfo*,int32_t,int32_t*);
    GLXContext                     (*glXGetCurrentContext)();
    GLXDrawable                    (*glXGetCurrentDrawable)();
    void                           (*glXWaitGL)();
    void                           (*glXWaitX)();
    void                           (*glXUseXFont)(XFont,int32_t,int32_t,int32_t);
    const char*                    (*glXQueryExtensionsString)(XDisplay*,int32_t);
    const char*                    (*glXQueryServerString)(XDisplay*,int32_t,int32_t);
    const char*                    (*glXGetClientString)(XDisplay*,int32_t);
    XDisplay*                      (*glXGetCurrentDisplay)();
    GLXFBConfig*                   (*glXChooseFBConfig)(XDisplay*,int32_t,const int32_t*,int32_t*);
    int32_t                        (*glXGetFBConfigAttrib)(XDisplay*,GLXFBConfig,int32_t,int32_t*);
    GLXFBConfig*                   (*glXGetFBConfigs)(XDisplay*,int32_t,int32_t*);
    XVisualInfo*                   (*glXGetVisualFromFBConfig)(XDisplay*,GLXFBConfig);
    GLXWindow                      (*glXCreateWindow)(XDisplay*,GLXFBConfig,XWindow,const int32_t*);
    void                           (*glXDestroyWindow)(XDisplay*,GLXWindow);
    GLXPixmap                      (*glXCreatePixmap)(XDisplay*,GLXFBConfig,XPixmap,const int32_t*);
    void                           (*glXDestroyPixmap)(XDisplay*,GLXPixmap);
    GLXPbuffer                     (*glXCreatePbuffer)(XDisplay*,GLXFBConfig,const int32_t*);
    void                           (*glXDestroyPbuffer)(XDisplay*,GLXPbuffer);
    void                           (*glXQueryDrawable)(XDisplay*,GLXDrawable,int32_t,uint32_t*);
    GLXContext                     (*glXCreateNewContext)(XDisplay*,GLXFBConfig,int32_t,GLXContext,int32_t);
    int32_t                        (*glXMakeContextCurrent)(XDisplay*,GLXDrawable,GLXDrawable,GLXContext);
    GLXDrawable                    (*glXGetCurrentReadDrawable)();
    int32_t                        (*glXQueryContext)(XDisplay*,GLXContext,int32_t,int32_t*);
    void                           (*glXSelectEvent)(XDisplay*,GLXDrawable,uint64_t);
    void                           (*glXGetSelectedEvent)(XDisplay*,GLXDrawable,uint64_t*);
    void*                          (*glXGetProcAddressARB)(const char*);
    void*                          (*glXGetProcAddress)(const char*);
    void*                          (*glXAllocateMemoryNV)(int32_t,float,float,float);
    void                           (*glXFreeMemoryNV)(void*);
    int32_t                        (*glXBindTexImageARB)(XDisplay*,GLXPbuffer,int32_t);
    int32_t                        (*glXReleaseTexImageARB)(XDisplay*,GLXPbuffer,int32_t);
    int32_t                        (*glXDrawableAttribARB)(XDisplay*,GLXDrawable,const int32_t*);
    int32_t                        (*glXGetFrameUsageMESA)(XDisplay*,GLXDrawable,float*);
    int32_t                        (*glXBeginFrameTrackingMESA)(XDisplay*,GLXDrawable);
    int32_t                        (*glXEndFrameTrackingMESA)(XDisplay*,GLXDrawable);
    int32_t                        (*glXQueryFrameTrackingMESA)(XDisplay*,GLXDrawable,int64_t*,int64_t*,float*);
    int32_t                        (*glXSwapIntervalMESA)(uint32_t);
    int32_t                        (*glXGetSwapIntervalMESA)();
    void                           (*glXBindTexImageEXT)(XDisplay*,GLXDrawable,int32_t,const int32_t*);
    void                           (*glXReleaseTexImageEXT)(XDisplay*,GLXDrawable,int32_t);
} _libGLX;

/// @brief Returns true if the "libGLX.so" library was freed successfully.
bool _free_libGLX_so();

/// @brief Returns true if the "libGLX.so" library was loaded successfully.
bool _load_libGLX_so();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_linux_libGLX_h__
// -------------------------------------------------------------------------------------------------------------------------- //