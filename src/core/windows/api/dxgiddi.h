// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! THIS IS A MODIFIED VERSION OF THE ORIGINAL HEADER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! │
// ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
// │ DATE: 2025-02-27                                                                                                          │
// │ FILE: "C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\dxgiddi.h"                                          │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __dxgiddi_h__
#define __dxgiddi_h__ 1
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <d3dukmdt.h>
#include "dxgitype.h"

#define _FACDXGI_DDI                                                             0x87b
#define MAKE_DXGI_DDI_HRESULT(code)                                              MAKE_HRESULT(1,_FACDXGI_DDI,code)
#define MAKE_DXGI_DDI_STATUS(code)                                               MAKE_HRESULT(0,_FACDXGI_DDI,code)
#define DXGI_DDI_MAX_MULTIPLANE_OVERLAY_ALLOCATIONS                              16
#define DXGI_DDI_PRIMARY_DRIVER_FLAG_NO_SCANOUT                                  0x1
#define DXGI_DDI_PRIMARY_INDIRECT                                                0x8
#define DXGI_DDI_PRIMARY_NONPREROTATED                                           0x2
#define DXGI_DDI_PRIMARY_OPTIONAL                                                0x1
#define DXGI_DDI_PRIMARY_STEREO                                                  0x4

typedef UINT_PTR                                                                 DXGI_DDI_HDEVICE;
typedef UINT_PTR                                                                 DXGI_DDI_HRESOURCE;

typedef enum DXGI_DDI_FLIP_INTERVAL_TYPE                                         DXGI_DDI_FLIP_INTERVAL_TYPE;
typedef enum DXGI_DDI_MODE_ROTATION                                              DXGI_DDI_MODE_ROTATION;
typedef enum DXGI_DDI_MODE_SCALING                                               DXGI_DDI_MODE_SCALING;
typedef enum DXGI_DDI_MODE_SCANLINE_ORDER                                        DXGI_DDI_MODE_SCANLINE_ORDER;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_BLEND                                   DXGI_DDI_MULTIPLANE_OVERLAY_BLEND;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS                            DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_FLAGS                                   DXGI_DDI_MULTIPLANE_OVERLAY_FLAGS;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS                             DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE                        DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT                           DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY                         DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT                      DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT;
typedef enum DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAGS                             DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAGS;
typedef enum DXGI_DDI_RESIDENCY                                                  DXGI_DDI_RESIDENCY;
typedef struct DXGI_DDI_ARG_BLT                                                  DXGI_DDI_ARG_BLT;
typedef struct DXGI_DDI_ARG_BLT_FLAGS                                            DXGI_DDI_ARG_BLT_FLAGS;
typedef struct DXGI_DDI_ARG_BLT1                                                 DXGI_DDI_ARG_BLT1;
typedef struct DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT              DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT;
typedef struct DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT                        DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT;
typedef struct DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT                          DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT;
typedef struct DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS                               DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS;
typedef struct DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS                             DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS;
typedef struct DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS                        DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS;
typedef struct DXGI_DDI_ARG_OFFERRESOURCES                                       DXGI_DDI_ARG_OFFERRESOURCES;
typedef struct DXGI_DDI_ARG_OFFERRESOURCES1                                      DXGI_DDI_ARG_OFFERRESOURCES1;
typedef struct DXGI_DDI_ARG_PRESENT                                              DXGI_DDI_ARG_PRESENT;
typedef struct DXGI_DDI_ARG_PRESENT1                                             DXGI_DDI_ARG_PRESENT1;
typedef struct DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY                             DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY;
typedef struct DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY1                            DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY1;
typedef struct DXGI_DDI_ARG_PRESENTSURFACE                                       DXGI_DDI_ARG_PRESENTSURFACE;
typedef struct DXGI_DDI_ARG_QUERYRESOURCERESIDENCY                               DXGI_DDI_ARG_QUERYRESOURCERESIDENCY;
typedef struct DXGI_DDI_ARG_RECLAIMRESOURCES                                     DXGI_DDI_ARG_RECLAIMRESOURCES;
typedef struct DXGI_DDI_ARG_RECLAIMRESOURCES1                                    DXGI_DDI_ARG_RECLAIMRESOURCES1;
typedef struct DXGI_DDI_ARG_RESOLVESHAREDRESOURCE                                DXGI_DDI_ARG_RESOLVESHAREDRESOURCE;
typedef struct DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES                           DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES;
typedef struct DXGI_DDI_ARG_SET_GAMMA_CONTROL                                    DXGI_DDI_ARG_SET_GAMMA_CONTROL;
typedef struct DXGI_DDI_ARG_SETDISPLAYMODE                                       DXGI_DDI_ARG_SETDISPLAYMODE;
typedef struct DXGI_DDI_ARG_SETRESOURCEPRIORITY                                  DXGI_DDI_ARG_SETRESOURCEPRIORITY;
typedef struct DXGI_DDI_ARG_TRIMRESIDENCYSET                                     DXGI_DDI_ARG_TRIMRESIDENCYSET;
typedef struct DXGI_DDI_BASE_ARGS                                                DXGI_DDI_BASE_ARGS;
typedef struct DXGI_DDI_BASE_CALLBACKS                                           DXGI_DDI_BASE_CALLBACKS;
typedef struct DXGI_DDI_BASE_FUNCTIONS                                           DXGI_DDI_BASE_FUNCTIONS;
typedef struct DXGI_DDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO              DXGI_DDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO;
typedef struct DXGI_DDI_MODE_DESC                                                DXGI_DDI_MODE_DESC;
typedef struct DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES                            DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES;
typedef struct DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES1                           DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES1;
typedef struct DXGI_DDI_MULTIPLANE_OVERLAY_CAPS                                  DXGI_DDI_MULTIPLANE_OVERLAY_CAPS;
typedef struct DXGI_DDI_MULTIPLANE_OVERLAY_GROUP_CAPS                            DXGI_DDI_MULTIPLANE_OVERLAY_GROUP_CAPS;
typedef struct DXGI_DDI_PRESENT_FLAGS                                            DXGI_DDI_PRESENT_FLAGS;
typedef struct DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY                               DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY;
typedef struct DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY1                              DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY1;
typedef struct DXGI_DDI_PRIMARY_DESC                                             DXGI_DDI_PRIMARY_DESC;
typedef struct DXGI_DDI_RATIONAL                                                 DXGI_DDI_RATIONAL;
typedef struct DXGI1_1_DDI_BASE_FUNCTIONS                                        DXGI1_1_DDI_BASE_FUNCTIONS;
typedef struct DXGI1_2_DDI_BASE_FUNCTIONS                                        DXGI1_2_DDI_BASE_FUNCTIONS;
typedef struct DXGI1_3_DDI_BASE_FUNCTIONS                                        DXGI1_3_DDI_BASE_FUNCTIONS;
typedef struct DXGI1_4_DDI_BASE_FUNCTIONS                                        DXGI1_4_DDI_BASE_FUNCTIONS;
typedef struct DXGI1_5_DDI_BASE_FUNCTIONS                                        DXGI1_5_DDI_BASE_FUNCTIONS;
typedef struct DXGI1_6_1_DDI_ARG_PRESENT                                         DXGI1_6_1_DDI_ARG_PRESENT;
typedef struct DXGI1_6_1_DDI_ARG_PRESENTMULTIPLANEOVERLAY                        DXGI1_6_1_DDI_ARG_PRESENTMULTIPLANEOVERLAY;
typedef struct DXGI1_6_1_DDI_BASE_FUNCTIONS                                      DXGI1_6_1_DDI_BASE_FUNCTIONS;
typedef struct DXGIDDI_MULTIPLANE_OVERLAY_ALLOCATION_INFO                        DXGIDDI_MULTIPLANE_OVERLAY_ALLOCATION_INFO;
typedef struct DXGIDDI_MULTIPLANE_OVERLAY_PLANE_INFO                             DXGIDDI_MULTIPLANE_OVERLAY_PLANE_INFO;
typedef struct DXGIDDICB_PRESENT                                                 DXGIDDICB_PRESENT;
typedef struct DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY                              DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY;
typedef struct DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1                             DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1;
typedef struct DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE                               DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE;
typedef struct DXGIDDICB_SUBMITPRESENTTOHWQUEUE                                  DXGIDDICB_SUBMITPRESENTTOHWQUEUE;

typedef HRESULT (WINAPI *PFNDDXGIDDI_PRESENTCB)(HANDLE,DXGIDDICB_PRESENT*);
typedef HRESULT (WINAPI *PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAYCB)(HANDLE,const DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY*);
typedef HRESULT (WINAPI *PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAY1CB)(HANDLE,const DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1*);
typedef HRESULT (WINAPI *PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB)(HANDLE,DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE*);
typedef HRESULT (WINAPI *PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB)(HANDLE,DXGIDDICB_SUBMITPRESENTTOHWQUEUE*);

// -------------------------------------------------------------------------------------------------------------------------- //

enum DXGI_DDI_FLIP_INTERVAL_TYPE {
    DXGI_DDI_FLIP_INTERVAL_IMMEDIATE                                             = 0x0000,
    DXGI_DDI_FLIP_INTERVAL_ONE                                                   = 0x0001,
    DXGI_DDI_FLIP_INTERVAL_TWO                                                   = 0x0002,
    DXGI_DDI_FLIP_INTERVAL_THREE                                                 = 0x0003,
    DXGI_DDI_FLIP_INTERVAL_FOUR                                                  = 0x0004,
    DXGI_DDI_FLIP_INTERVAL_IMMEDIATE_ALLOW_TEARING                               = 0x0005,
};

enum DXGI_DDI_MODE_ROTATION {
    DXGI_DDI_MODE_ROTATION_UNSPECIFIED                                           = 0x0000,
    DXGI_DDI_MODE_ROTATION_IDENTITY                                              = 0x0001,
    DXGI_DDI_MODE_ROTATION_ROTATE90                                              = 0x0002,
    DXGI_DDI_MODE_ROTATION_ROTATE180                                             = 0x0003,
    DXGI_DDI_MODE_ROTATION_ROTATE270                                             = 0x0004,
};

enum DXGI_DDI_MODE_SCALING {
    DXGI_DDI_MODE_SCALING_UNSPECIFIED                                            = 0x0000,
    DXGI_DDI_MODE_SCALING_STRETCHED                                              = 0x0001,
    DXGI_DDI_MODE_SCALING_CENTERED                                               = 0x0002,
};

enum DXGI_DDI_MODE_SCANLINE_ORDER {
    DXGI_DDI_MODE_SCANLINE_ORDER_UNSPECIFIED                                     = 0x0000,
    DXGI_DDI_MODE_SCANLINE_ORDER_PROGRESSIVE                                     = 0x0001,
    DXGI_DDI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST                               = 0x0002,
    DXGI_DDI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST                               = 0x0003,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_BLEND {
    DXGI_DDI_MULTIPLANE_OVERLAY_BLEND_OPAQUE                                     = 0x0000,
    DXGI_DDI_MULTIPLANE_OVERLAY_BLEND_ALPHABLEND                                 = 0x0001,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS {
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_ROTATION_WITHOUT_INDEPENDENT_FLIP   = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_VERTICAL_FLIP                       = 0x0002,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_HORIZONTAL_FLIP                     = 0x0004,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_DEINTERLACE                         = 0x0008,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_STEREO                              = 0x0010,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_RGB                                 = 0x0020,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_YUV                                 = 0x0040,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_BILINEAR_FILTER                     = 0x0080,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_HIGH_FILTER                         = 0x0100,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_ROTATION                            = 0x0200,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_FULLSCREEN_POST_COMPOSITION         = 0x0400,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_RESERVED1                                = 0x0800,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_SHARED                              = 0x1000,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_IMMEDIATE                           = 0x2000,
    DXGI_DDI_MULTIPLANE_OVERLAY_FEATURE_CAPS_PLANE0_FOR_VIRTUAL_MODE_ONLY        = 0x4000,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_FLAGS {
    DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_VERTICAL_FLIP                               = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_HORIZONTAL_FLIP                             = 0x0002,
    DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_FULLSCREEN_POST_COMPOSITION                 = 0x0004,
    DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_NO_SCANOUT_TRANFORMATION                    = 0x0008,
    DXGI_DDI_MULTIPLANE_OVERLAY_FLAG_NO_RENDER_PRESENT                           = 0x0010,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS {
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS_SEPARATE                             = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS_ROW_INTERLEAVED                      = 0x0004,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS_COLUMN_INTERLEAVED                   = 0x0008,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS_CHECKERBOARD                         = 0x0010,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_CAPS_FLIP_MODE                            = 0x0020,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE {
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_NONE                                 = 0x0000,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_FRAME0                               = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_FRAME1                               = 0x0002,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT {
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_MONO                               = 0x0000,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_HORIZONTAL                         = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_VERTICAL                           = 0x0002,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_SEPARATE                           = 0x0003,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_MONO_OFFSET                        = 0x0004,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_ROW_INTERLEAVED                    = 0x0005,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_COLUMN_INTERLEAVED                 = 0x0006,
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT_CHECKERBOARD                       = 0x0007,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY {
    DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY_BILINEAR                         = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY_HIGH                             = 0x0002,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT {
    DXGI_DDI_MULIIPLANE_OVERLAY_VIDEO_FRAME_FORMAT_PROGRESSIVE                   = 0x0000,
    DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT_INTERLACED_TOP_FIELD_FIRST    = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT_INTERLACED_BOTTOM_FIELD_FIRST = 0x0002,
};

enum DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAGS {
    DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE                         = 0x0001,
    DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709                                 = 0x0002,
    DXGI_DDI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC                                 = 0x0004,
};

enum DXGI_DDI_RESIDENCY {
    DXGI_DDI_RESIDENCY_FULLY_RESIDENT                                            = 0x0001,
    DXGI_DDI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY                                 = 0x0002,
    DXGI_DDI_RESIDENCY_EVICTED_TO_DISK                                           = 0x0003,
};

// -------------------------------------------------------------------------------------------------------------------------- //

struct DXGI_DDI_ARG_BLT {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_DDI_HRESOURCE                                                           hDstResource;
    UINT                                                                         DstSubresource;
    UINT                                                                         DstLeft;
    UINT                                                                         DstTop;
    UINT                                                                         DstRight;
    UINT                                                                         DstBottom;
    DXGI_DDI_HRESOURCE                                                           hSrcResource;
    UINT                                                                         SrcSubresource;
    DXGI_DDI_ARG_BLT_FLAGS                                                       Flags;
    DXGI_DDI_MODE_ROTATION                                                       Rotate;
};

struct DXGI_DDI_ARG_BLT_FLAGS {
    union {
        struct {
            UINT                                                                 Resolve  : 1;
            UINT                                                                 Convert  : 1;
            UINT                                                                 Stretch  : 1;
            UINT                                                                 Present  : 1;
            UINT                                                                 Reserved : 28;
        };
        UINT                                                                     Value;
    };
};

struct DXGI_DDI_ARG_BLT1 {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_DDI_HRESOURCE                                                           hDstResource;
    UINT                                                                         DstSubresource;
    UINT                                                                         DstLeft;
    UINT                                                                         DstTop;
    UINT                                                                         DstRight;
    UINT                                                                         DstBottom;
    DXGI_DDI_HRESOURCE                                                           hSrcResource;
    UINT                                                                         SrcSubresource;
    UINT                                                                         SrcLeft;
    UINT                                                                         SrcTop;
    UINT                                                                         SrcRight;
    UINT                                                                         SrcBottom;
    DXGI_DDI_ARG_BLT_FLAGS                                                       Flags;
    DXGI_DDI_MODE_ROTATION                                                       Rotate;
};

struct DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT {
    DXGI_DDI_HDEVICE                                                             hDevice;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    DXGI_FORMAT                                                                  Format;
    D3DDDI_COLOR_SPACE_TYPE                                                      ColorSpace;
    BOOL                                                                         Supported;
};

struct DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT {
    DXGI_DDI_HDEVICE                                                             hDevice;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    UINT                                                                         NumPlaneInfo;
    DXGI_DDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO*                        pPlaneInfo;
    BOOL                                                                         Supported;
};

struct DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT {
    DXGI_DDI_HDEVICE                                                             hDevice;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    UINT                                                                         DesiredPresentDuration;
    UINT                                                                         ClosestSmallerDuration;
    UINT                                                                         ClosestLargerDuration;
};

struct DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_GAMMA_CONTROL_CAPABILITIES*                                             pGammaCapabilities;
};

struct DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS {
    DXGI_DDI_HDEVICE                                                             hDevice;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    DXGI_DDI_MULTIPLANE_OVERLAY_CAPS                                             MultiplaneOverlayCaps;
};

struct DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS {
    DXGI_DDI_HDEVICE                                                             hDevice;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    UINT                                                                         GroupIndex;
    DXGI_DDI_MULTIPLANE_OVERLAY_GROUP_CAPS                                       MultiplaneOverlayGroupCaps;
};

struct DXGI_DDI_ARG_OFFERRESOURCES {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_HRESOURCE*                                                    pResources;
    UINT                                                                         Resources;
    D3DDDI_OFFER_PRIORITY                                                        Priority;
};

struct DXGI_DDI_ARG_OFFERRESOURCES1 {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_HRESOURCE*                                                    pResources;
    UINT                                                                         Resources;
    D3DDDI_OFFER_PRIORITY                                                        Priority;
    D3DDDI_OFFER_FLAGS                                                           Flags;
};

struct DXGI_DDI_ARG_PRESENT {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_DDI_HRESOURCE                                                           hSurfaceToPresent;
    UINT                                                                         SrcSubResourceIndex;
    DXGI_DDI_HRESOURCE                                                           hDstResource;
    UINT                                                                         DstSubResourceIndex;
    void*                                                                        pDXGIContext;
    DXGI_DDI_PRESENT_FLAGS                                                       Flags;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                                  FlipInterval;
};

struct DXGI_DDI_ARG_PRESENT1 {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_ARG_PRESENTSURFACE*                                           phSurfacesToPresent;
    UINT                                                                         SurfacesToPresent;
    DXGI_DDI_HRESOURCE                                                           hDstResource;
    UINT                                                                         DstSubResourceIndex;
    void*                                                                        pDXGIContext;
    DXGI_DDI_PRESENT_FLAGS                                                       Flags;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                                  FlipInterval;
    UINT                                                                         Reserved;
    const RECT*                                                                  pDirtyRects;
    UINT                                                                         DirtyRects;
    UINT                                                                         BackBufferMultiplicity;
};

struct DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY {
    DXGI_DDI_HDEVICE                                                             hDevice;
    void*                                                                        pDXGIContext;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    DXGI_DDI_PRESENT_FLAGS                                                       Flags;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                                  FlipInterval;
    UINT                                                                         PresentPlaneCount;
    DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY*                                         pPresentPlanes;
    UINT                                                                         Reserved;
};

struct DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY1 {
    DXGI_DDI_HDEVICE                                                             hDevice;
    void*                                                                        pDXGIContext;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    DXGI_DDI_PRESENT_FLAGS                                                       Flags;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                                  FlipInterval;
    UINT                                                                         PresentPlaneCount;
    DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY1*                                        pPresentPlanes;
};

struct DXGI_DDI_ARG_PRESENTSURFACE {
    DXGI_DDI_HRESOURCE                                                           hSurface;
    UINT                                                                         SubResourceIndex;
};

struct DXGI_DDI_ARG_QUERYRESOURCERESIDENCY {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_HRESOURCE*                                                    pResources;
    DXGI_DDI_RESIDENCY*                                                          pStatus;
    SIZE_T                                                                       Resources;
};

struct DXGI_DDI_ARG_RECLAIMRESOURCES {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_HRESOURCE*                                                    pResources;
    BOOL*                                                                        pDiscarded;
    UINT                                                                         Resources;
};

struct DXGI_DDI_ARG_RECLAIMRESOURCES1 {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_HRESOURCE*                                                    pResources;
    D3DDDI_RECLAIM_RESULT*                                                       pResults;
    UINT                                                                         Resources;
};

struct DXGI_DDI_ARG_RESOLVESHAREDRESOURCE {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_DDI_HRESOURCE                                                           hResource;
};

struct DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES {
    DXGI_DDI_HDEVICE                                                             hDevice;
    const DXGI_DDI_HRESOURCE*                                                    pResources;
    UINT                                                                         Resources;
};

struct DXGI_DDI_ARG_SET_GAMMA_CONTROL {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_GAMMA_CONTROL                                                           GammaControl;
};

struct DXGI_DDI_ARG_SETDISPLAYMODE {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_DDI_HRESOURCE                                                           hResource;
    UINT                                                                         SubResourceIndex;
};

struct DXGI_DDI_ARG_SETRESOURCEPRIORITY {
    DXGI_DDI_HDEVICE                                                             hDevice;
    DXGI_DDI_HRESOURCE                                                           hResource;
    UINT                                                                         Priority;
};

struct DXGI_DDI_ARG_TRIMRESIDENCYSET {
    DXGI_DDI_HDEVICE                                                             hDevice;
    D3DDDI_TRIMRESIDENCYSET_FLAGS                                                TrimFlags;
    UINT64                                                                       NumBytesToTrim;
};

struct DXGI_DDI_BASE_ARGS {
    DXGI_DDI_BASE_CALLBACKS*                                                     pDXGIBaseCallbacks;
    union {
        DXGI1_6_1_DDI_BASE_FUNCTIONS*                                            pDXGIDDIBaseFunctions6_1;
        DXGI1_5_DDI_BASE_FUNCTIONS*                                              pDXGIDDIBaseFunctions6;
        DXGI1_4_DDI_BASE_FUNCTIONS*                                              pDXGIDDIBaseFunctions5;
        DXGI1_3_DDI_BASE_FUNCTIONS*                                              pDXGIDDIBaseFunctions4;
        DXGI1_2_DDI_BASE_FUNCTIONS*                                              pDXGIDDIBaseFunctions3;
        DXGI1_1_DDI_BASE_FUNCTIONS*                                              pDXGIDDIBaseFunctions2;
        DXGI_DDI_BASE_FUNCTIONS*                                                 pDXGIDDIBaseFunctions;
    };
};

struct DXGI_DDI_BASE_CALLBACKS {
    PFNDDXGIDDI_PRESENTCB                                                        pfnPresentCb;
    PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAYCB                                     pfnPresentMultiplaneOverlayCb;
    PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAY1CB                                    pfnPresentMultiplaneOverlay1Cb;
    PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB                                      pfnSubmitPresentBltToHwQueueCb;
    PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB                                         pfnSubmitPresentToHwQueueCb;
};

struct DXGI_DDI_BASE_FUNCTIONS {
    HRESULT                                                             (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                             (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                             (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                             (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                             (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                             (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                             (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
};

struct DXGI_DDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO {
    DXGI_DDI_HRESOURCE                                                           hResource;
    UINT                                                                         SubResourceIndex;
    DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES                                       PlaneAttributes;
};

struct DXGI_DDI_MODE_DESC {
    UINT                                                                         Width;
    UINT                                                                         Height;
    DXGI_FORMAT                                                                  Format;
    DXGI_DDI_RATIONAL                                                            RefreshRate;
    DXGI_DDI_MODE_SCANLINE_ORDER                                                 ScanlineOrdering;
    DXGI_DDI_MODE_ROTATION                                                       Rotation;
    DXGI_DDI_MODE_SCALING                                                        Scaling;
};

struct DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES {
    UINT                                                                         Flags;
    RECT                                                                         SrcRect;
    RECT                                                                         DstRect;
    RECT                                                                         ClipRect;
    DXGI_DDI_MODE_ROTATION                                                       Rotation;
    DXGI_DDI_MULTIPLANE_OVERLAY_BLEND                                            Blend;
    UINT                                                                         DirtyRectCount;
    RECT*                                                                        pDirtyRects;
    DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT                               VideoFrameFormat;
    UINT                                                                         YCbCrFlags;
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT                                    StereoFormat;
    BOOL                                                                         StereoLeftViewFrame0;
    BOOL                                                                         StereoBaseViewFrame0;
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE                                 StereoFlipMode;
    DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY                                  StretchQuality;
};

struct DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES1 {
    UINT                                                                         Flags;
    RECT                                                                         SrcRect;
    RECT                                                                         DstRect;
    RECT                                                                         ClipRect;
    DXGI_DDI_MODE_ROTATION                                                       Rotation;
    DXGI_DDI_MULTIPLANE_OVERLAY_BLEND                                            Blend;
    UINT                                                                         DirtyRectCount;
    RECT*                                                                        pDirtyRects;
    DXGI_DDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT                               VideoFrameFormat;
    D3DDDI_COLOR_SPACE_TYPE                                                      ColorSpace;
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FORMAT                                    StereoFormat;
    BOOL                                                                         StereoLeftViewFrame0;
    BOOL                                                                         StereoBaseViewFrame0;
    DXGI_DDI_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE                                 StereoFlipMode;
    DXGI_DDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY                                  StretchQuality;
    UINT                                                                         ColorKey;
};

struct DXGI_DDI_MULTIPLANE_OVERLAY_CAPS {
    UINT                                                                         MaxPlanes;
    UINT                                                                         NumCapabilityGroups;
};

struct DXGI_DDI_MULTIPLANE_OVERLAY_GROUP_CAPS {
    UINT                                                                         NumPlanes;
    float                                                                        MaxStretchFactor;
    float                                                                        MaxShrinkFactor;
    UINT                                                                         OverlayCaps;
    UINT                                                                         StereoCaps;
};

struct DXGI_DDI_PRESENT_FLAGS {
    union {
        struct {
            UINT                                                                 Blt                  : 1;
            UINT                                                                 Flip                 : 1;
            UINT                                                                 PreferRight          : 1;
            UINT                                                                 TemporaryMono        : 1;
            UINT                                                                 AllowTearing         : 1;
            UINT                                                                 AllowFlexibleRefresh : 1;
            UINT                                                                 NoScanoutTransform   : 1;
            UINT                                                                 Reserved             : 25;
        };
        UINT                                                                     Value;
    };
};

struct DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY {
    UINT                                                                         LayerIndex;
    BOOL                                                                         Enabled;
    DXGI_DDI_HRESOURCE                                                           hResource;
    UINT                                                                         SubResourceIndex;
    DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES                                       PlaneAttributes;
};

struct DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY1 {
    UINT                                                                         LayerIndex;
    BOOL                                                                         Enabled;
    DXGI_DDI_HRESOURCE                                                           hResource;
    UINT                                                                         SubResourceIndex;
    DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES1                                      PlaneAttributes;
};

struct DXGI_DDI_PRIMARY_DESC {
    UINT                                                                         Flags;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                               VidPnSourceId;
    DXGI_DDI_MODE_DESC                                                           ModeDesc;
    UINT                                                                         DriverFlags;
};

struct DXGI_DDI_RATIONAL {
    UINT                                                                         Numerator;
    UINT                                                                         Denominator;
};

struct DXGI1_1_DDI_BASE_FUNCTIONS {
    HRESULT                                                             (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                             (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                             (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                             (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                             (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                             (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                             (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
    HRESULT                                                             (WINAPI *pfnResolveSharedResource)(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*);
};

struct DXGI1_2_DDI_BASE_FUNCTIONS {
    HRESULT                                                             (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                             (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                             (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                             (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                             (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                             (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                             (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
    HRESULT                                                             (WINAPI *pfnResolveSharedResource)(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*);
    HRESULT                                                             (WINAPI *pfnBlt1)(DXGI_DDI_ARG_BLT1*);
    HRESULT                                                             (WINAPI *pfnOfferResources)(DXGI_DDI_ARG_OFFERRESOURCES*);
    HRESULT                                                             (WINAPI *pfnReclaimResources)(DXGI_DDI_ARG_RECLAIMRESOURCES*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayFilterRange)(void*);
    HRESULT                                                             (WINAPI *pfnCheckMultiplaneOverlaySupport)(DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT*);
    HRESULT                                                             (WINAPI *pfnPresentMultiplaneOverlay)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY*);
};

struct DXGI1_3_DDI_BASE_FUNCTIONS {
    HRESULT                                                             (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                             (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                             (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                             (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                             (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                             (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                             (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
    HRESULT                                                             (WINAPI *pfnResolveSharedResource)(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*);
    HRESULT                                                             (WINAPI *pfnBlt1)(DXGI_DDI_ARG_BLT1*);
    HRESULT                                                             (WINAPI *pfnOfferResources)(DXGI_DDI_ARG_OFFERRESOURCES*);
    HRESULT                                                             (WINAPI *pfnReclaimResources)(DXGI_DDI_ARG_RECLAIMRESOURCES*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayGroupCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS*);
    HRESULT                                                             (WINAPI *pfnReserved1)(void*);
    HRESULT                                                             (WINAPI *pfnPresentMultiplaneOverlay)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY*);
    HRESULT                                                             (WINAPI *pfnReserved2)(void*);
    HRESULT                                                             (WINAPI *pfnPresent1)(DXGI_DDI_ARG_PRESENT1*);
    HRESULT                                                             (WINAPI *pfnCheckPresentDurationSupport)(DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT*);
};

struct DXGI1_4_DDI_BASE_FUNCTIONS {
    HRESULT                                                             (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                             (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                             (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                             (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                             (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                             (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                             (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
    HRESULT                                                             (WINAPI *pfnResolveSharedResource)(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*);
    HRESULT                                                             (WINAPI *pfnBlt1)(DXGI_DDI_ARG_BLT1*);
    HRESULT                                                             (WINAPI *pfnOfferResources)(DXGI_DDI_ARG_OFFERRESOURCES*);
    HRESULT                                                             (WINAPI *pfnReclaimResources)(DXGI_DDI_ARG_RECLAIMRESOURCES*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayGroupCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS*);
    HRESULT                                                             (WINAPI *pfnReserved1)(void*);
    HRESULT                                                             (WINAPI *pfnPresentMultiplaneOverlay)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY*);
    HRESULT                                                             (WINAPI *pfnReserved2)(void*);
    HRESULT                                                             (WINAPI *pfnPresent1)(DXGI_DDI_ARG_PRESENT1*);
    HRESULT                                                             (WINAPI *pfnCheckPresentDurationSupport)(DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT*);
    HRESULT                                                             (WINAPI *pfnTrimResidencySet)(DXGI_DDI_ARG_TRIMRESIDENCYSET*);
    HRESULT                                                             (WINAPI *pfnCheckMultiplaneOverlayColorSpaceSupport)(DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT*);
    HRESULT                                                             (WINAPI *pfnPresentMultiplaneOverlay1)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY1*);
};

struct DXGI1_5_DDI_BASE_FUNCTIONS {
    HRESULT                                                             (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                             (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                             (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                             (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                             (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                             (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                             (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
    HRESULT                                                             (WINAPI *pfnResolveSharedResource)(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*);
    HRESULT                                                             (WINAPI *pfnBlt1)(DXGI_DDI_ARG_BLT1*);
    HRESULT                                                             (WINAPI *pfnOfferResources1)(DXGI_DDI_ARG_OFFERRESOURCES1*);
    HRESULT                                                             (WINAPI *pfnReclaimResources)(DXGI_DDI_ARG_RECLAIMRESOURCES*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS*);
    HRESULT                                                             (WINAPI *pfnGetMultiplaneOverlayGroupCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS*);
    HRESULT                                                             (WINAPI *pfnReserved1)(void*);
    HRESULT                                                             (WINAPI *pfnPresentMultiplaneOverlay)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY*);
    HRESULT                                                             (WINAPI *pfnReserved2)(void*);
    HRESULT                                                             (WINAPI *pfnPresent1)(DXGI_DDI_ARG_PRESENT1*);
    HRESULT                                                             (WINAPI *pfnCheckPresentDurationSupport)(DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT*);
    HRESULT                                                             (WINAPI *pfnTrimResidencySet)(DXGI_DDI_ARG_TRIMRESIDENCYSET*);
    HRESULT                                                             (WINAPI *pfnCheckMultiplaneOverlayColorSpaceSupport)(DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT*);
    HRESULT                                                             (WINAPI *pfnPresentMultiplaneOverlay1)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY1*);
    HRESULT                                                             (WINAPI *pfnReclaimResources1)(DXGI_DDI_ARG_RECLAIMRESOURCES1*);
};

struct DXGI1_6_1_DDI_ARG_PRESENT {
    DXGI_DDI_HDEVICE                                                    hDevice;
    const DXGI_DDI_ARG_PRESENTSURFACE*                                  phSurfacesToPresent;
    UINT                                                                SurfacesToPresent;
    DXGI_DDI_HRESOURCE                                                  hDstResource;
    UINT                                                                DstSubResourceIndex;
    void*                                                               pDXGIContext;
    DXGI_DDI_PRESENT_FLAGS                                              Flags;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                         FlipInterval;
    DXGI_DDI_MODE_ROTATION                                              RotationHint;
    const RECT*                                                         pDirtyRects;
    UINT                                                                DirtyRects;
    UINT                                                                BackBufferMultiplicity;
};

struct DXGI1_6_1_DDI_ARG_PRESENTMULTIPLANEOVERLAY {
    DXGI_DDI_HDEVICE                                                    hDevice;
    void*                                                               pDXGIContext;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID                                      VidPnSourceId;
    DXGI_DDI_PRESENT_FLAGS                                              Flags;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                         FlipInterval;
    UINT                                                                PresentPlaneCount;
    DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY1*                               pPresentPlanes;
    DXGI_DDI_MODE_ROTATION*                                             pRotationHints;
};

struct DXGI1_6_1_DDI_BASE_FUNCTIONS {
    HRESULT                                                    (WINAPI *pfnPresent)(DXGI_DDI_ARG_PRESENT*);
    HRESULT                                                    (WINAPI *pfnGetGammaCaps)(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*);
    HRESULT                                                    (WINAPI *pfnSetDisplayMode)(DXGI_DDI_ARG_SETDISPLAYMODE*);
    HRESULT                                                    (WINAPI *pfnSetResourcePriority)(DXGI_DDI_ARG_SETRESOURCEPRIORITY*);
    HRESULT                                                    (WINAPI *pfnQueryResourceResidency)(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*);
    HRESULT                                                    (WINAPI *pfnRotateResourceIdentities)(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*);
    HRESULT                                                    (WINAPI *pfnBlt)(DXGI_DDI_ARG_BLT*);
    HRESULT                                                    (WINAPI *pfnResolveSharedResource)(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*);
    HRESULT                                                    (WINAPI *pfnBlt1)(DXGI_DDI_ARG_BLT1*);
    HRESULT                                                    (WINAPI *pfnOfferResources1)(DXGI_DDI_ARG_OFFERRESOURCES1*);
    HRESULT                                                    (WINAPI *pfnReclaimResources)(DXGI_DDI_ARG_RECLAIMRESOURCES*);
    HRESULT                                                    (WINAPI *pfnGetMultiplaneOverlayCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS*);
    HRESULT                                                    (WINAPI *pfnGetMultiplaneOverlayGroupCaps)(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS*);
    HRESULT                                                    (WINAPI *pfnReserved1)(void*);
    HRESULT                                                    (WINAPI *pfnPresentMultiplaneOverlay)(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY*);
    HRESULT                                                    (WINAPI *pfnReserved2)(void*);
    HRESULT                                                    (WINAPI *pfnPresent1)(DXGI1_6_1_DDI_ARG_PRESENT*);
    HRESULT                                                    (WINAPI *pfnCheckPresentDurationSupport)(DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT*);
    HRESULT                                                    (WINAPI *pfnTrimResidencySet)(DXGI_DDI_ARG_TRIMRESIDENCYSET*);
    HRESULT                                                    (WINAPI *pfnCheckMultiplaneOverlayColorSpaceSupport)(DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT*);
    HRESULT                                                    (WINAPI *pfnPresentMultiplaneOverlay1)(DXGI1_6_1_DDI_ARG_PRESENTMULTIPLANEOVERLAY*);
    HRESULT                                                    (WINAPI *pfnReclaimResources1)(DXGI_DDI_ARG_RECLAIMRESOURCES1*);
};

struct DXGIDDI_MULTIPLANE_OVERLAY_ALLOCATION_INFO {
    D3DKMT_HANDLE                                                       PresentAllocation;
    UINT                                                                SubResourceIndex;
};

struct DXGIDDI_MULTIPLANE_OVERLAY_PLANE_INFO {
    UINT                                                                ContextCount;
    HANDLE*                                                             pContextList;
    D3DKMT_HANDLE*                                                      pAllocationList;
    UINT                                                                DriverPrivateDataSize;
    void*                                                               pDriverPrivateData;
    BOOL                                                                SyncIntervalOverrideValid;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                         SyncIntervalOverride;
};

struct DXGIDDICB_PRESENT {
    D3DKMT_HANDLE                                                       hSrcAllocation;
    D3DKMT_HANDLE                                                       hDstAllocation;
    void*                                                               pDXGIContext;
    HANDLE                                                              hContext;
    UINT                                                                BroadcastContextCount;
    HANDLE                                                              BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
    D3DKMT_HANDLE*                                                      BroadcastSrcAllocation;
    D3DKMT_HANDLE*                                                      BroadcastDstAllocation;
    UINT                                                                PrivateDriverDataSize;
    PVOID                                                               pPrivateDriverData;
    BOOLEAN                                                             bOptimizeForComposition;
    BOOL                                                                SyncIntervalOverrideValid;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                         SyncIntervalOverride;
};

struct DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY {
    void*                                                               pDXGIContext;
    HANDLE                                                              hContext;
    UINT                                                                BroadcastContextCount;
    HANDLE                                                              BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
    DWORD                                                               AllocationInfoCount;
    DXGIDDI_MULTIPLANE_OVERLAY_ALLOCATION_INFO                          AllocationInfo[DXGI_DDI_MAX_MULTIPLANE_OVERLAY_ALLOCATIONS];
};

struct DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1 {
    void*                                                               pDXGIContext;
    DWORD                                                               PresentPlaneCount;
    DXGIDDI_MULTIPLANE_OVERLAY_PLANE_INFO**                             ppPresentPlanes;
};

struct DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE {
    D3DKMT_HANDLE                                                       hSrcAllocation;
    D3DKMT_HANDLE                                                       hDstAllocation;
    void*                                                               pDXGIContext;
    HANDLE                                                              hHwQueue;
    UINT64                                                              HwQueueProgressFenceId;
    UINT                                                                PrivateDriverDataSize;
    PVOID                                                               pPrivateDriverData;
};

struct DXGIDDICB_SUBMITPRESENTTOHWQUEUE {
    void*                                                               pDXGIContext;
    D3DKMT_HANDLE*                                                      BroadcastSrcAllocations;
    D3DKMT_HANDLE*                                                      BroadcastDstAllocations;
    HANDLE*                                                             hHwQueues;
    UINT                                                                BroadcastHwQueueCount;
    UINT                                                                PrivateDriverDataSize;
    PVOID                                                               pPrivateDriverData;
    BOOLEAN                                                             bOptimizeForComposition;
    BOOL                                                                SyncIntervalOverrideValid;
    DXGI_DDI_FLIP_INTERVAL_TYPE                                         SyncIntervalOverride;
};

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__dxgiddi_h__
// -------------------------------------------------------------------------------------------------------------------------- //