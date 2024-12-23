// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_linux_libGLX_h__
#define __core_linux_libGLX_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "libX11.h"

typedef struct __GLXContextRec*  GLXContext;
typedef struct __GLXFBConfigRec* GLXFBConfig;
typedef XID                      GLXFBConfigID;
typedef XID                      GLXContextID;
typedef XID                      GLXPbuffer;
typedef void                   (*GLXFunctionPtr)(void);

// -------------------------------------------------------------------------------------------------------------------------- //

/// @brief Represents the "libGLX.so" library and supported functions.
extern struct _libGLX_so {
    void*            so;
    XVisualInfo*   (*glXChooseVisual)(XDisplay*,int,int*);
    GLXContext     (*glXCreateContext)(XDisplay*,XVisualInfo*,GLXContext,XBool);
    void           (*glXDestroyContext)(XDisplay*,GLXContext);
    XBool          (*glXMakeCurrent)(XDisplay*,XDrawable,GLXContext);
    void           (*glXCopyContext)(XDisplay*,GLXContext,GLXContext,uint64_t);
    void           (*glXSwapBuffers)(XDisplay*,XDrawable);
    XPixmap        (*glXCreateGLXPixmap)(XDisplay*,XVisualInfo*,XPixmap);
    void           (*glXDestroyGLXPixmap)(XDisplay*,XPixmap);
    XBool          (*glXQueryExtension)(XDisplay*,int*,int*);
    XBool          (*glXQueryVersion)(XDisplay*,int*,int*);
    XBool          (*glXIsDirect)(XDisplay*,GLXContext);
    int            (*glXGetConfig)(XDisplay*,XVisualInfo*,int,int*);
    GLXContext     (*glXGetCurrentContext)();
    XDrawable      (*glXGetCurrentDrawable)();
    void           (*glXWaitGL)();
    void           (*glXWaitX)();
    void           (*glXUseXFont)(XFont,int,int,int);
    const char*    (*glXQueryExtensionsString)(XDisplay*,int);
    const char*    (*glXQueryServerString)(XDisplay*,int,int);
    const char*    (*glXGetClientString)(XDisplay*,int);
    XDisplay*      (*glXGetCurrentDisplay)();
    GLXFBConfig*   (*glXChooseFBConfig)(XDisplay*,int,const int*,int*);
    int            (*glXGetFBConfigAttrib)(XDisplay*,GLXFBConfig,int,int*);
    GLXFBConfig*   (*glXGetFBConfigs)(XDisplay*,int,int*);
    XVisualInfo*   (*glXGetVisualFromFBConfig)(XDisplay*,GLXFBConfig);
    XWindow        (*glXCreateWindow)(XDisplay*,GLXFBConfig,XWindow,const int*);
    void           (*glXDestroyWindow)(XDisplay*,XWindow);
    XPixmap        (*glXCreatePixmap)(XDisplay*,GLXFBConfig,XPixmap,const int*);
    void           (*glXDestroyPixmap)(XDisplay*,XPixmap);
    GLXPbuffer     (*glXCreatePbuffer)(XDisplay*,GLXFBConfig,const int*);
    void           (*glXDestroyPbuffer)(XDisplay*,GLXPbuffer);
    void           (*glXQueryDrawable)(XDisplay*,XDrawable,int,uint32_t*);
    GLXContext     (*glXCreateNewContext)(XDisplay*,GLXFBConfig,int,GLXContext,XBool);
    XBool          (*glXMakeContextCurrent)(XDisplay*,XDrawable,XDrawable,GLXContext);
    XDrawable      (*glXGetCurrentReadDrawable)();
    int            (*glXQueryContext)(XDisplay*,GLXContext,int,int*);
    void           (*glXSelectEvent)(XDisplay*,XDrawable,uint64_t);
    void           (*glXGetSelectedEvent)(XDisplay*,XDrawable,uint64_t*);
    GLXFunctionPtr (*glXGetProcAddressARB)(const char*);
    void*          (*glXGetProcAddress)(const char*);
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