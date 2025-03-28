// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
//
// WARNING:
//   THIS IS A MODIFIED VERSION OF THE 'GL/glx.h' HEADER AND IS DISTRIBUTED UNDER THE SAME ORIGINAL LICENSE.
//
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_linux_libGLX_glx_h__
#define __core_linux_libGLX_glx_h__
#ifdef __cplusplus
extern "C" {
#endif

#include "../libX11.h"

#define GLX_VERSION_1_1                 1
#define GLX_VERSION_1_2                 1
#define GLX_VERSION_1_3                 1
#define GLX_VERSION_1_4                 1
#define GLX_EXTENSION_NAME              "GLX"
#define GLX_USE_GL                      1
#define GLX_BUFFER_SIZE                 2
#define GLX_LEVEL                       3
#define GLX_RGBA                        4
#define GLX_DOUBLEBUFFER                5
#define GLX_STEREO                      6
#define GLX_AUX_BUFFERS                 7
#define GLX_RED_SIZE                    8
#define GLX_GREEN_SIZE                  9
#define GLX_BLUE_SIZE                   10
#define GLX_ALPHA_SIZE                  11
#define GLX_DEPTH_SIZE                  12
#define GLX_STENCIL_SIZE                13
#define GLX_ACCUM_RED_SIZE              14
#define GLX_ACCUM_GREEN_SIZE            15
#define GLX_ACCUM_BLUE_SIZE             16
#define GLX_ACCUM_ALPHA_SIZE            17
#define GLX_BAD_SCREEN                  1
#define GLX_BAD_ATTRIBUTE               2
#define GLX_NO_EXTENSION                3
#define GLX_BAD_VISUAL                  4
#define GLX_BAD_CONTEXT                 5
#define GLX_BAD_VALUE                   6
#define GLX_BAD_ENUM                    7
#define GLX_VENDOR                      1
#define GLX_VERSION                     2
#define GLX_EXTENSIONS                  3
#define GLX_CONFIG_CAVEAT               0x20
#define GLX_DONT_CARE                   0xFFFFFFFF
#define GLX_X_VISUAL_TYPE               0x22
#define GLX_TRANSPARENT_TYPE            0x23
#define GLX_TRANSPARENT_INDEX_VALUE     0x24
#define GLX_TRANSPARENT_RED_VALUE       0x25
#define GLX_TRANSPARENT_GREEN_VALUE     0x26
#define GLX_TRANSPARENT_BLUE_VALUE      0x27
#define GLX_TRANSPARENT_ALPHA_VALUE     0x28
#define GLX_WINDOW_BIT                  0x00000001
#define GLX_PIXMAP_BIT                  0x00000002
#define GLX_PBUFFER_BIT                 0x00000004
#define GLX_AUX_BUFFERS_BIT             0x00000010
#define GLX_FRONT_LEFT_BUFFER_BIT       0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT      0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT        0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT       0x00000008
#define GLX_DEPTH_BUFFER_BIT            0x00000020
#define GLX_STENCIL_BUFFER_BIT          0x00000040
#define GLX_ACCUM_BUFFER_BIT            0x00000080
#define GLX_NONE                        0x8000
#define GLX_SLOW_CONFIG                 0x8001
#define GLX_TRUE_COLOR                  0x8002
#define GLX_DIRECT_COLOR                0x8003
#define GLX_PSEUDO_COLOR                0x8004
#define GLX_STATIC_COLOR                0x8005
#define GLX_GRAY_SCALE                  0x8006
#define GLX_STATIC_GRAY                 0x8007
#define GLX_TRANSPARENT_RGB             0x8008
#define GLX_TRANSPARENT_INDEX           0x8009
#define GLX_VISUAL_ID                   0x800B
#define GLX_SCREEN                      0x800C
#define GLX_NON_CONFORMANT_CONFIG       0x800D
#define GLX_DRAWABLE_TYPE               0x8010
#define GLX_RENDER_TYPE                 0x8011
#define GLX_X_RENDERABLE                0x8012
#define GLX_FBCONFIG_ID                 0x8013
#define GLX_RGBA_TYPE                   0x8014
#define GLX_COLOR_INDEX_TYPE            0x8015
#define GLX_MAX_PBUFFER_WIDTH           0x8016
#define GLX_MAX_PBUFFER_HEIGHT          0x8017
#define GLX_MAX_PBUFFER_PIXELS          0x8018
#define GLX_PRESERVED_CONTENTS          0x801B
#define GLX_LARGEST_PBUFFER             0x801C
#define GLX_WIDTH                       0x801D
#define GLX_HEIGHT                      0x801E
#define GLX_EVENT_MASK                  0x801F
#define GLX_DAMAGED                     0x8020
#define GLX_SAVED                       0x8021
#define GLX_WINDOW                      0x8022
#define GLX_PBUFFER                     0x8023
#define GLX_PBUFFER_HEIGHT              0x8040
#define GLX_PBUFFER_WIDTH               0x8041
#define GLX_RGBA_BIT                    0x00000001
#define GLX_COLOR_INDEX_BIT             0x00000002
#define GLX_PBUFFER_CLOBBER_MASK        0x08000000
#define GLX_SAMPLE_BUFFERS              0x186a0
#define GLX_SAMPLES                     0x186a1
#define GLX_PbufferClobber              0
#define GLX_BufferSwapComplete          1
#define GLX_FLOAT_COMPONENTS_NV         0x20B0
#define GLX_BIND_TO_TEXTURE_RGB_EXT     0x20D0
#define GLX_BIND_TO_TEXTURE_RGBA_EXT    0x20D1
#define GLX_BIND_TO_MIPMAP_TEXTURE_EXT  0x20D2
#define GLX_BIND_TO_TEXTURE_TARGETS_EXT 0x20D3
#define GLX_Y_INVERTED_EXT              0x20D4
#define GLX_TEXTURE_FORMAT_EXT          0x20D5
#define GLX_TEXTURE_TARGET_EXT          0x20D6
#define GLX_MIPMAP_TEXTURE_EXT          0x20D7
#define GLX_TEXTURE_FORMAT_NONE_EXT     0x20D8
#define GLX_TEXTURE_FORMAT_RGB_EXT      0x20D9
#define GLX_TEXTURE_FORMAT_RGBA_EXT     0x20DA
#define GLX_TEXTURE_1D_BIT_EXT          0x00000001
#define GLX_TEXTURE_2D_BIT_EXT          0x00000002
#define GLX_TEXTURE_RECTANGLE_BIT_EXT   0x00000004
#define GLX_TEXTURE_1D_EXT              0x20DB
#define GLX_TEXTURE_2D_EXT              0x20DC
#define GLX_TEXTURE_RECTANGLE_EXT       0x20DD
#define GLX_FRONT_LEFT_EXT              0x20DE
#define GLX_FRONT_RIGHT_EXT             0x20DF
#define GLX_BACK_LEFT_EXT               0x20E0
#define GLX_BACK_RIGHT_EXT              0x20E1
#define GLX_FRONT_EXT                   0x20DE
#define GLX_BACK_EXT                    0x20E0
#define GLX_AUX0_EXT                    0x20E2
#define GLX_AUX1_EXT                    0x20E3 
#define GLX_AUX2_EXT                    0x20E4 
#define GLX_AUX3_EXT                    0x20E5 
#define GLX_AUX4_EXT                    0x20E6 
#define GLX_AUX5_EXT                    0x20E7 
#define GLX_AUX6_EXT                    0x20E8
#define GLX_AUX7_EXT                    0x20E9 
#define GLX_AUX8_EXT                    0x20EA 
#define GLX_AUX9_EXT                    0x20EB

typedef void*                           GLXContext;
typedef void*                           GLXFBConfig;
typedef struct GLXBufferSwapComplete    GLXBufferSwapComplete;
typedef struct GLXPbufferClobberEvent   GLXPbufferClobberEvent;
typedef union GLXEvent                  GLXEvent;
typedef XID                             GLXContextID;
typedef XID                             GLXDrawable;
typedef XID                             GLXFBConfigID;
typedef XID                             GLXPbuffer;
typedef XID                             GLXPixmap;
typedef XID                             GLXWindow;

struct GLXBufferSwapComplete {
    int32_t                             type;                  // ???
    uint64_t                            serial;                // # of last request processed by server.
    int32_t                             send_event;            // true if this came from a SendEvent request.
    XDisplay*                           display;               // Display the event was read from.
    GLXDrawable                         drawable;              // drawable on which event was requested in event mask.
    int32_t                             event_type;            // ???
    int64_t                             ust;                   // ???
    int64_t                             msc;                   // ???
    int64_t                             sbc;                   // ???
};

struct GLXPbufferClobberEvent {
    int32_t                             event_type;            // GLX_DAMAGED or GLX_SAVED.
    int32_t                             draw_type;             // GLX_WINDOW or GLX_PBUFFER.
    uint64_t                            serial;                // # of last request processed by server.
    int32_t                             send_event;            // true if this came for SendEvent request.
    XDisplay*                           display;               // display the event was read from.
    GLXDrawable                         drawable;              // XID of Drawable.
    uint32_t                            buffer_mask;           // mask indicating which buffers are affected.
    uint32_t                            aux_buffer;            // which aux buffer was affected.
    int32_t                             x;                     // ???
    int32_t                             y;                     // ???
    int32_t                             width;                 // ???
    int32_t                             height;                // ???
    int32_t                             count;                 // if nonzero, at least this many more.
};

union GLXEvent {
    GLXPbufferClobberEvent              glxpbufferclobber;     // ???
    GLXBufferSwapComplete               glxbufferswapcomplete; // ???
    long                                pad[24];               // ???
};

#define glXChooseVisual(...)            _libGLX.glXChooseVisual(__VA_ARGS__)
#define glXCreateContext(...)           _libGLX.glXCreateContext(__VA_ARGS__)
#define glXDestroyContext(...)          _libGLX.glXDestroyContext(__VA_ARGS__)
#define glXMakeCurrent(...)             _libGLX.glXMakeCurrent(__VA_ARGS__)
#define glXCopyContext(...)             _libGLX.glXCopyContext(__VA_ARGS__)
#define glXSwapBuffers(...)             _libGLX.glXSwapBuffers(__VA_ARGS__)
#define glXCreateGLXPixmap(...)         _libGLX.glXCreateGLXPixmap(__VA_ARGS__)
#define glXDestroyGLXPixmap(...)        _libGLX.glXDestroyGLXPixmap(__VA_ARGS__)
#define glXQueryExtension(...)          _libGLX.glXQueryExtension(__VA_ARGS__)
#define glXQueryVersion(...)            _libGLX.glXQueryVersion(__VA_ARGS__)
#define glXIsDirect(...)                _libGLX.glXIsDirect(__VA_ARGS__)
#define glXGetConfig(...)               _libGLX.glXGetConfig(__VA_ARGS__)
#define glXGetCurrentContext(...)       _libGLX.glXGetCurrentContext(__VA_ARGS__)
#define glXGetCurrentDrawable(...)      _libGLX.glXGetCurrentDrawable(__VA_ARGS__)
#define glXWaitGL(...)                  _libGLX.glXWaitGL(__VA_ARGS__)
#define glXWaitX(...)                   _libGLX.glXWaitX(__VA_ARGS__)
#define glXUseXFont(...)                _libGLX.glXUseXFont(__VA_ARGS__)
#define glXQueryExtensionsString(...)   _libGLX.glXQueryExtensionsString(__VA_ARGS__)
#define glXQueryServerString(...)       _libGLX.glXQueryServerString(__VA_ARGS__)
#define glXGetClientString(...)         _libGLX.glXGetClientString(__VA_ARGS__)
#define glXGetCurrentDisplay(...)       _libGLX.glXGetCurrentDisplay(__VA_ARGS__)
#define glXChooseFBConfig(...)          _libGLX.glXChooseFBConfig(__VA_ARGS__)
#define glXGetFBConfigAttrib(...)       _libGLX.glXGetFBConfigAttrib(__VA_ARGS__)
#define glXGetFBConfigs(...)            _libGLX.glXGetFBConfigs(__VA_ARGS__)
#define glXGetVisualFromFBConfig(...)   _libGLX.glXGetVisualFromFBConfig(__VA_ARGS__)
#define glXCreateWindow(...)            _libGLX.glXCreateWindow(__VA_ARGS__)
#define glXDestroyWindow(...)           _libGLX.glXDestroyWindow(__VA_ARGS__)
#define glXCreatePixmap(...)            _libGLX.glXCreatePixmap(__VA_ARGS__)
#define glXDestroyPixmap(...)           _libGLX.glXDestroyPixmap(__VA_ARGS__)
#define glXCreatePbuffer(...)           _libGLX.glXCreatePbuffer(__VA_ARGS__)
#define glXDestroyPbuffer(...)          _libGLX.glXDestroyPbuffer(__VA_ARGS__)
#define glXQueryDrawable(...)           _libGLX.glXQueryDrawable(__VA_ARGS__)
#define glXCreateNewContext(...)        _libGLX.glXCreateNewContext(__VA_ARGS__)
#define glXMakeContextCurrent(...)      _libGLX.glXMakeContextCurrent(__VA_ARGS__)
#define glXGetCurrentReadDrawable(...)  _libGLX.glXGetCurrentReadDrawable(__VA_ARGS__)
#define glXQueryContext(...)            _libGLX.glXQueryContext(__VA_ARGS__)
#define glXSelectEvent(...)             _libGLX.glXSelectEvent(__VA_ARGS__)
#define glXGetSelectedEvent(...)        _libGLX.glXGetSelectedEvent(__VA_ARGS__)
#define glXGetProcAddressARB(...)       _libGLX.glXGetProcAddressARB(__VA_ARGS__)
#define glXGetProcAddress(...)          _libGLX.glXGetProcAddress(__VA_ARGS__)
#define glXAllocateMemoryNV(...)        _libGLX.glXAllocateMemoryNV(__VA_ARGS__)
#define glXFreeMemoryNV(...)            _libGLX.glXFreeMemoryNV(__VA_ARGS__)
#define glXBindTexImageARB(...)         _libGLX.glXBindTexImageARB(__VA_ARGS__)
#define glXReleaseTexImageARB(...)      _libGLX.glXReleaseTexImageARB(__VA_ARGS__)
#define glXDrawableAttribARB(...)       _libGLX.glXDrawableAttribARB(__VA_ARGS__)
#define glXGetFrameUsageMESA(...)       _libGLX.glXGetFrameUsageMESA(__VA_ARGS__)
#define glXBeginFrameTrackingMESA(...)  _libGLX.glXBeginFrameTrackingMESA(__VA_ARGS__)
#define glXEndFrameTrackingMESA(...)    _libGLX.glXEndFrameTrackingMESA(__VA_ARGS__)
#define glXQueryFrameTrackingMESA(...)  _libGLX.glXQueryFrameTrackingMESA(__VA_ARGS__)
#define glXSwapIntervalMESA(...)        _libGLX.glXSwapIntervalMESA(__VA_ARGS__)
#define glXGetSwapIntervalMESA(...)     _libGLX.glXGetSwapIntervalMESA(__VA_ARGS__)
#define glXBindTexImageEXT(...)         _libGLX.glXBindTexImageEXT(__VA_ARGS__)
#define glXReleaseTexImageEXT(...)      _libGLX.glXReleaseTexImageEXT(__VA_ARGS__)

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_linux_libGLX_glx_h__
// -------------------------------------------------------------------------------------------------------------------------- //