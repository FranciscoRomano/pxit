// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __platform_GLX_library_h__
#define __platform_GLX_library_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdbool.h>
#include <GL/glx.h>

typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

/// @brief Represents the GLX library and supported functions.
extern struct LibraryGLX {    
    void*           handle;
    XVisualInfo*    (*glXChooseVisual)(Display*,int,int*);
    GLXContext      (*glXCreateContext)(Display*,XVisualInfo*,GLXContext,Bool);
    void            (*glXDestroyContext)(Display*,GLXContext);
    Bool            (*glXMakeCurrent)(Display*,GLXDrawable,GLXContext);
    void            (*glXCopyContext)(Display*,GLXContext,GLXContext,ulong);
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
    void            (*glXQueryDrawable)(Display*,GLXDrawable,int,uint*);
    GLXContext      (*glXCreateNewContext)(Display*,GLXFBConfig,int,GLXContext,Bool);
    Bool            (*glXMakeContextCurrent)(Display*,GLXDrawable,GLXDrawable,GLXContext);
    GLXDrawable     (*glXGetCurrentReadDrawable)();
    int             (*glXQueryContext)(Display*,GLXContext,int,int*);
    void            (*glXSelectEvent)(Display*,GLXDrawable,ulong);
    void            (*glXGetSelectedEvent)(Display*,GLXDrawable,ulong*);
    __GLXextFuncPtr (*glXGetProcAddressARB)(const uchar*);
    void*           (*glXGetProcAddress)(const uchar*);
} GLX;

/// @brief Returns true if the GLX library was freed successfully.
bool FreeLibraryGLX();

/// @brief Returns true if the GLX library was loaded successfully.
bool LoadLibraryGLX();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef DEFINE_SYMBOLS_GLX
#define glXChooseVisual           GLX.glXChooseVisual
#define glXCreateContext          GLX.glXCreateContext
#define glXDestroyContext         GLX.glXDestroyContext
#define glXMakeCurrent            GLX.glXMakeCurrent
#define glXCopyContext            GLX.glXCopyContext
#define glXSwapBuffers            GLX.glXSwapBuffers
#define glXCreateGLXPixmap        GLX.glXCreateGLXPixmap
#define glXDestroyGLXPixmap       GLX.glXDestroyGLXPixmap
#define glXQueryExtension         GLX.glXQueryExtension
#define glXQueryVersion           GLX.glXQueryVersion
#define glXIsDirect               GLX.glXIsDirect
#define glXGetConfig              GLX.glXGetConfig
#define glXGetCurrentContext      GLX.glXGetCurrentContext
#define glXGetCurrentDrawable     GLX.glXGetCurrentDrawable
#define glXWaitGL                 GLX.glXWaitGL
#define glXWaitX                  GLX.glXWaitX
#define glXUseXFont               GLX.glXUseXFont
#define glXQueryExtensionsString  GLX.glXQueryExtensionsString
#define glXQueryServerString      GLX.glXQueryServerString
#define glXGetClientString        GLX.glXGetClientString
#define glXGetCurrentDisplay      GLX.glXGetCurrentDisplay
#define glXChooseFBConfig         GLX.glXChooseFBConfig
#define glXGetFBConfigAttrib      GLX.glXGetFBConfigAttrib
#define glXGetFBConfigs           GLX.glXGetFBConfigs
#define glXGetVisualFromFBConfig  GLX.glXGetVisualFromFBConfig
#define glXCreateWindow           GLX.glXCreateWindow
#define glXDestroyWindow          GLX.glXDestroyWindow
#define glXCreatePixmap           GLX.glXCreatePixmap
#define glXDestroyPixmap          GLX.glXDestroyPixmap
#define glXCreatePbuffer          GLX.glXCreatePbuffer
#define glXDestroyPbuffer         GLX.glXDestroyPbuffer
#define glXQueryDrawable          GLX.glXQueryDrawable
#define glXCreateNewContext       GLX.glXCreateNewContext
#define glXMakeContextCurrent     GLX.glXMakeContextCurrent
#define glXGetCurrentReadDrawable GLX.glXGetCurrentReadDrawable
#define glXQueryContext           GLX.glXQueryContext
#define glXSelectEvent            GLX.glXSelectEvent
#define glXGetSelectedEvent       GLX.glXGetSelectedEvent
#define glXGetProcAddressARB      GLX.glXGetProcAddressARB
#define glXGetProcAddress         GLX.glXGetProcAddress
#endif//DEFINE_SYMBOLS_GLX
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__platform_GLX_library_h__
// -------------------------------------------------------------------------------------------------------------------------- //