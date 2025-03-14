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

#include "libX11.h"

#define GLX_ACCUM_ALPHA_SIZE        17
#define GLX_ACCUM_BLUE_SIZE         16
#define GLX_ACCUM_BUFFER_BIT        0x00000080
#define GLX_ACCUM_GREEN_SIZE        15
#define GLX_ACCUM_RED_SIZE          14
#define GLX_ALPHA_SIZE              11
#define GLX_AUX_BUFFERS             7
#define GLX_AUX_BUFFERS_BIT         0x00000010
#define GLX_BACK_LEFT_BUFFER_BIT    0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT   0x00000008
#define GLX_BLUE_SIZE               10
#define GLX_BUFFER_SIZE             2
#define GLX_COLOR_INDEX_BIT         0x00000002
#define GLX_COLOR_INDEX_TYPE        0x8015
#define GLX_CONFIG_CAVEAT           0x20
#define GLX_DAMAGED                 0x8020
#define GLX_DEPTH_BUFFER_BIT        0x00000020
#define GLX_DEPTH_SIZE              12
#define GLX_DIRECT_COLOR            0x8003
#define GLX_DONT_CARE               0xFFFFFFFF
#define GLX_DOUBLEBUFFER            5
#define GLX_DRAWABLE_TYPE           0x8010
#define GLX_EVENT_MASK              0x801F
#define GLX_FALSE                   0
#define GLX_FBCONFIG_ID             0x8013
#define GLX_FRONT_LEFT_BUFFER_BIT   0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT  0x00000002
#define GLX_GRAY_SCALE              0x8006
#define GLX_GREEN_SIZE              9
#define GLX_HEIGHT                  0x801E
#define GLX_LARGEST_PBUFFER         0x801C
#define GLX_LEVEL                   3
#define GLX_MAX_PBUFFER_HEIGHT      0x8017
#define GLX_MAX_PBUFFER_PIXELS      0x8018
#define GLX_MAX_PBUFFER_WIDTH       0x8016
#define GLX_NON_CONFORMANT_CONFIG   0x800D
#define GLX_NONE                    0x8000
#define GLX_PBUFFER                 0x8023
#define GLX_PBUFFER_BIT             0x00000004
#define GLX_PBUFFER_CLOBBER_MASK    0x08000000
#define GLX_PBUFFER_HEIGHT          0x8040
#define GLX_PBUFFER_WIDTH           0x8041
#define GLX_PIXMAP_BIT              0x00000002
#define GLX_PRESERVED_CONTENTS      0x801B
#define GLX_PSEUDO_COLOR            0x8004
#define GLX_RED_SIZE                8
#define GLX_RENDER_TYPE             0x8011
#define GLX_RGBA                    4
#define GLX_RGBA_BIT                0x00000001
#define GLX_RGBA_TYPE               0x8014
#define GLX_SAVED                   0x8021
#define GLX_SCREEN                  0x800C
#define GLX_SLOW_CONFIG             0x8001
#define GLX_STATIC_COLOR            0x8005
#define GLX_STATIC_GRAY             0x8007
#define GLX_STENCIL_BUFFER_BIT      0x00000040
#define GLX_STENCIL_SIZE            13
#define GLX_STEREO                  6
#define GLX_TRANSPARENT_ALPHA_VALUE 0x28
#define GLX_TRANSPARENT_BLUE_VALUE  0x27
#define GLX_TRANSPARENT_GREEN_VALUE 0x26
#define GLX_TRANSPARENT_INDEX       0x8009
#define GLX_TRANSPARENT_INDEX_VALUE 0x24
#define GLX_TRANSPARENT_RED_VALUE   0x25
#define GLX_TRANSPARENT_RGB         0x8008
#define GLX_TRANSPARENT_TYPE        0x23
#define GLX_TRUE                    1
#define GLX_TRUE_COLOR              0x8002
#define GLX_USE_GL                  1
#define GLX_VISUAL_ID               0x800B
#define GLX_WIDTH                   0x801D
#define GLX_WINDOW                  0x8022
#define GLX_WINDOW_BIT              0x00000001
#define GLX_X_RENDERABLE            0x8012
#define GLX_X_VISUAL_TYPE           0x22

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
    GLXContext     (*glXCreateContext)(XDisplay*,XVisualInfo*,GLXContext,int);
    void           (*glXDestroyContext)(XDisplay*,GLXContext);
    int            (*glXMakeCurrent)(XDisplay*,XDrawable,GLXContext);
    void           (*glXCopyContext)(XDisplay*,GLXContext,GLXContext,uint64_t);
    void           (*glXSwapBuffers)(XDisplay*,XDrawable);
    XPixmap        (*glXCreateGLXPixmap)(XDisplay*,XVisualInfo*,XPixmap);
    void           (*glXDestroyGLXPixmap)(XDisplay*,XPixmap);
    int            (*glXQueryExtension)(XDisplay*,int*,int*);
    int            (*glXQueryVersion)(XDisplay*,int*,int*);
    int            (*glXIsDirect)(XDisplay*,GLXContext);
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
    GLXContext     (*glXCreateNewContext)(XDisplay*,GLXFBConfig,int,GLXContext,int);
    int            (*glXMakeContextCurrent)(XDisplay*,XDrawable,XDrawable,GLXContext);
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