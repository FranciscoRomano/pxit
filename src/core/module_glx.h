// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_glx_h__
#define __core_module_glx_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdint.h>
#include <stdbool.h>
#include <GL/glx.h>

/// @brief Represents the GLX module and supported functions.
extern struct _Module_GLX {    
    void*           handle; // A GLX library handle.
    GLXFBConfig     fbc;    // A GLX Framebuffer configuration.
    XVisualInfo*    (*glXChooseVisual)(Display*,int,int*);
    GLXContext      (*glXCreateContext)(Display*,XVisualInfo*,GLXContext,Bool);
    void            (*glXDestroyContext)(Display*,GLXContext);
    Bool            (*glXMakeCurrent)(Display*,GLXDrawable,GLXContext);
    void            (*glXCopyContext)(Display*,GLXContext,GLXContext,uint64_t);
    void            (*glXSwapBuffers)(Display*,GLXDrawable);
    GLXPixmap       (*glXCreateGLXPixmap)(Display*,XVisualInfo*,Pixmap);
    void            (*glXDestroyGLXPixmap)(Display*,GLXPixmap);
    Bool            (*glXQueryExtension)(Display*,int*,int*);
    Bool            (*glXQueryVersion)(Display*,int*,int*);
    Bool            (*glXIsDirect)(Display*,GLXContext);
    int             (*glXGetConfig)(Display*,XVisualInfo*,int,int*);
    GLXContext      (*glXGetCurrentContext)();
    GLXDrawable     (*glXGetCurrentDrawable)();
    void            (*glXWaitGL)();
    void            (*glXWaitX)();
    void            (*glXUseXFont)(Font,int,int,int);
    const char*     (*glXQueryExtensionsString)(Display*,int);
    const char*     (*glXQueryServerString)(Display*,int,int);
    const char*     (*glXGetClientString)(Display*,int);
    Display*        (*glXGetCurrentDisplay)();
    GLXFBConfig*    (*glXChooseFBConfig)(Display*,int,const int*,int*);
    int             (*glXGetFBConfigAttrib)(Display*,GLXFBConfig,int,int*);
    GLXFBConfig*    (*glXGetFBConfigs)(Display*,int,int*);
    XVisualInfo*    (*glXGetVisualFromFBConfig)(Display*,GLXFBConfig);
    GLXWindow       (*glXCreateWindow)(Display*,GLXFBConfig,Window,const int*);
    void            (*glXDestroyWindow)(Display*,GLXWindow);
    GLXPixmap       (*glXCreatePixmap)(Display*,GLXFBConfig,Pixmap,const int*);
    void            (*glXDestroyPixmap)(Display*,GLXPixmap);
    GLXPbuffer      (*glXCreatePbuffer)(Display*,GLXFBConfig,const int*);
    void            (*glXDestroyPbuffer)(Display*,GLXPbuffer);
    void            (*glXQueryDrawable)(Display*,GLXDrawable,int,uint32_t*);
    GLXContext      (*glXCreateNewContext)(Display*,GLXFBConfig,int,GLXContext,Bool);
    Bool            (*glXMakeContextCurrent)(Display*,GLXDrawable,GLXDrawable,GLXContext);
    GLXDrawable     (*glXGetCurrentReadDrawable)();
    int             (*glXQueryContext)(Display*,GLXContext,int,int*);
    void            (*glXSelectEvent)(Display*,GLXDrawable,uint64_t);
    void            (*glXGetSelectedEvent)(Display*,GLXDrawable,uint64_t*);
    __GLXextFuncPtr (*glXGetProcAddressARB)(const char*);
    void*           (*glXGetProcAddress)(const char*);
} _GLX;

/// @brief Returns true if the GLX module was freed successfully.
bool _FreeModule_GLX();

/// @brief Returns true if the GLX module was loaded successfully.
bool _LoadModule_GLX();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_glx_h__
// -------------------------------------------------------------------------------------------------------------------------- //