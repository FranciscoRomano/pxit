// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_windows_d3d9_h__
#define __core_windows_d3d9_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>
#include <winerror.h>
#include <stdbool.h>
#include <d3d9types.h>
#include <d3d9caps.h>

#define _FACD3D                                 0x876
#define MAKE_D3DHRESULT(code)                   MAKE_HRESULT(1,_FACD3D,code)
#define MAKE_D3DSTATUS(code)                    MAKE_HRESULT(0,_FACD3D,code)

#define D3D_OK                                  S_OK
#define D3D_SDK_VERSION                         32
#define D3DADAPTER_DEFAULT                      0
#define D3DCREATE_ADAPTERGROUP_DEVICE           0x00000200L
#define D3DCREATE_DISABLE_DRIVER_MANAGEMENT     0x00000100L
#define D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX  0x00000400L
#define D3DCREATE_DISABLE_PRINTSCREEN           0x00008000L
#define D3DCREATE_DISABLE_PSGP_THREADING        0x00002000L
#define D3DCREATE_ENABLE_PRESENTSTATS           0x00004000L
#define D3DCREATE_FPU_PRESERVE                  0x00000002L
#define D3DCREATE_HARDWARE_VERTEXPROCESSING     0x00000040L
#define D3DCREATE_MIXED_VERTEXPROCESSING        0x00000080L
#define D3DCREATE_MULTITHREADED                 0x00000004L
#define D3DCREATE_NOWINDOWCHANGES               0x00000800L
#define D3DCREATE_PUREDEVICE                    0x00000010L
#define D3DCREATE_SCREENSAVER                   0x10000000L
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING     0x00000020L
#define D3DCURSOR_IMMEDIATE_UPDATE              0x00000001L
#define D3DENUM_WHQL_LEVEL                      0x00000002L
#define D3DERR_CANNOTPROTECTCONTENT             MAKE_D3DHRESULT(2173)
#define D3DERR_CONFLICTINGRENDERSTATE           MAKE_D3DHRESULT(2081)
#define D3DERR_CONFLICTINGTEXTUREFILTER         MAKE_D3DHRESULT(2078)
#define D3DERR_CONFLICTINGTEXTUREPALETTE        MAKE_D3DHRESULT(2086)
#define D3DERR_DEVICEHUNG                       MAKE_D3DHRESULT(2164)
#define D3DERR_DEVICELOST                       MAKE_D3DHRESULT(2152)
#define D3DERR_DEVICENOTRESET                   MAKE_D3DHRESULT(2153)
#define D3DERR_DEVICEREMOVED                    MAKE_D3DHRESULT(2160)
#define D3DERR_DRIVERINTERNALERROR              MAKE_D3DHRESULT(2087)
#define D3DERR_DRIVERINVALIDCALL                MAKE_D3DHRESULT(2157)
#define D3DERR_INVALIDCALL                      MAKE_D3DHRESULT(2156)
#define D3DERR_INVALIDDEVICE                    MAKE_D3DHRESULT(2155)
#define D3DERR_MOREDATA                         MAKE_D3DHRESULT(2151)
#define D3DERR_NOTAVAILABLE                     MAKE_D3DHRESULT(2154)
#define D3DERR_NOTFOUND                         MAKE_D3DHRESULT(2150)
#define D3DERR_OUTOFVIDEOMEMORY                 MAKE_D3DHRESULT(380)
#define D3DERR_PRESENT_STATISTICS_DISJOINT      MAKE_D3DHRESULT(2180)
#define D3DERR_TOOMANYOPERATIONS                MAKE_D3DHRESULT(2077)
#define D3DERR_UNSUPPORTEDALPHAARG              MAKE_D3DHRESULT(2076)
#define D3DERR_UNSUPPORTEDALPHAOPERATION        MAKE_D3DHRESULT(2075)
#define D3DERR_UNSUPPORTEDCOLORARG              MAKE_D3DHRESULT(2074)
#define D3DERR_UNSUPPORTEDCOLOROPERATION        MAKE_D3DHRESULT(2073)
#define D3DERR_UNSUPPORTEDCRYPTO                MAKE_D3DHRESULT(2174)
#define D3DERR_UNSUPPORTEDFACTORVALUE           MAKE_D3DHRESULT(2079)
#define D3DERR_UNSUPPORTEDOVERLAY               MAKE_D3DHRESULT(2171)
#define D3DERR_UNSUPPORTEDOVERLAYFORMAT         MAKE_D3DHRESULT(2172)
#define D3DERR_UNSUPPORTEDTEXTUREFILTER         MAKE_D3DHRESULT(2082)
#define D3DERR_WASSTILLDRAWING                  MAKE_D3DHRESULT(540)
#define D3DERR_WRONGTEXTUREFORMAT               MAKE_D3DHRESULT(2072)
#define D3DOK_NOAUTOGEN                         MAKE_D3DSTATUS(2159)
#define D3DPRESENT_BACK_BUFFERS_MAX             3L
#define D3DPRESENT_BACK_BUFFERS_MAX_EX          30L
#define D3DPRESENT_DONOTWAIT                    1L
#define D3DPRESENT_LINEAR_CONTENT               2L
#define D3DSGR_CALIBRATE                        0x00000001L
#define D3DSGR_NO_CALIBRATION                   0x00000000L
#define D3DSPD_IUNKNOWN                         0x00000001L
#define S_NOT_RESIDENT                          MAKE_D3DSTATUS(2165)
#define S_PRESENT_MODE_CHANGED                  MAKE_D3DSTATUS(2167)
#define S_PRESENT_OCCLUDED                      MAKE_D3DSTATUS(2168)
#define S_RESIDENT_IN_SHARED_MEMORY             MAKE_D3DSTATUS(2166)

typedef struct IDirect3D9                       IDirect3D9;
typedef struct IDirect3DBaseTexture9            IDirect3DBaseTexture9;
typedef struct IDirect3DCubeTexture9            IDirect3DCubeTexture9;
typedef struct IDirect3DDevice9                 IDirect3DDevice9;
typedef struct IDirect3DIndexBuffer9            IDirect3DIndexBuffer9;
typedef struct IDirect3DPixelShader9            IDirect3DPixelShader9;
typedef struct IDirect3DQuery9                  IDirect3DQuery9;
typedef struct IDirect3DResource9               IDirect3DResource9;
typedef struct IDirect3DStateBlock9             IDirect3DStateBlock9;
typedef struct IDirect3DSurface9                IDirect3DSurface9;
typedef struct IDirect3DSwapChain9              IDirect3DSwapChain9;
typedef struct IDirect3DTexture9                IDirect3DTexture9;
typedef struct IDirect3DVertexBuffer9           IDirect3DVertexBuffer9;
typedef struct IDirect3DVertexDeclaration9      IDirect3DVertexDeclaration9;
typedef struct IDirect3DVertexShader9           IDirect3DVertexShader9;
typedef struct IDirect3DVolume9                 IDirect3DVolume9;
typedef struct IDirect3DVolumeTexture9          IDirect3DVolumeTexture9;
typedef struct PALETTEENTRY                     PALETTEENTRY;
typedef struct RGNDATA                          RGNDATA;

struct IDirect3D9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3D9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3D9*);
        ULONG                (WINAPI *Release)(IDirect3D9*);
        // IDirect3D9 methods
        HRESULT              (WINAPI *RegisterSoftwareDevice)(IDirect3D9*,void*);
        UINT                 (WINAPI *GetAdapterCount)(IDirect3D9*);
        HRESULT              (WINAPI *GetAdapterIdentifier)(IDirect3D9*,UINT,DWORD,D3DADAPTER_IDENTIFIER9*);
        UINT                 (WINAPI *GetAdapterModeCount)(IDirect3D9*,UINT,D3DFORMAT);
        HRESULT              (WINAPI *EnumAdapterModes)(IDirect3D9*,UINT,D3DFORMAT,UINT,D3DDISPLAYMODE*);
        HRESULT              (WINAPI *GetAdapterDisplayMode)(IDirect3D9*,UINT,D3DDISPLAYMODE*);
        HRESULT              (WINAPI *CheckDeviceType)(IDirect3D9*,UINT,D3DDEVTYPE,D3DFORMAT,D3DFORMAT,WINBOOL);
        HRESULT              (WINAPI *CheckDeviceFormat)(IDirect3D9*,UINT,D3DDEVTYPE,D3DFORMAT,DWORD,D3DRESOURCETYPE,D3DFORMAT);
        HRESULT              (WINAPI *CheckDeviceMultiSampleType)(IDirect3D9*,UINT,D3DDEVTYPE,D3DFORMAT,WINBOOL,D3DMULTISAMPLE_TYPE,DWORD*);
        HRESULT              (WINAPI *CheckDepthStencilMatch)(IDirect3D9*,UINT,D3DDEVTYPE,D3DFORMAT,D3DFORMAT,D3DFORMAT);
        HRESULT              (WINAPI *CheckDeviceFormatConversion)(IDirect3D9*,UINT,D3DDEVTYPE,D3DFORMAT,D3DFORMAT);
        HRESULT              (WINAPI *GetDeviceCaps)(IDirect3D9*,UINT,D3DDEVTYPE,D3DCAPS9*);
        HMONITOR             (WINAPI *GetAdapterMonitor)(IDirect3D9*,UINT);
        HRESULT              (WINAPI *CreateDevice)(IDirect3D9*,UINT,D3DDEVTYPE,HWND,DWORD,D3DPRESENT_PARAMETERS*,IDirect3DDevice9**);
    }* lpVtbl;
};

struct IDirect3DVolume9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DVolume9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DVolume9*);
        ULONG                (WINAPI *Release)(IDirect3DVolume9*);
        // IDirect3DVolume9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DVolume9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DVolume9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DVolume9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DVolume9*,REFGUID);
        HRESULT              (WINAPI *GetContainer)(IDirect3DVolume9*,REFIID,void**);
        HRESULT              (WINAPI *GetDesc)(IDirect3DVolume9*,D3DVOLUME_DESC*);
        HRESULT              (WINAPI *LockBox)(IDirect3DVolume9*,D3DLOCKED_BOX*,const D3DBOX*,DWORD);
        HRESULT              (WINAPI *UnlockBox)(IDirect3DVolume9*);
    }* lpVtbl;
};

struct IDirect3DSwapChain9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DSwapChain9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DSwapChain9*);
        ULONG                (WINAPI *Release)(IDirect3DSwapChain9*);
        // IDirect3DSwapChain9 methods
        HRESULT              (WINAPI *Present)(IDirect3DSwapChain9*,const RECT*,const RECT*,HWND,const RGNDATA*,DWORD);
        HRESULT              (WINAPI *GetFrontBufferData)(IDirect3DSwapChain9*,IDirect3DSurface9*);
        HRESULT              (WINAPI *GetBackBuffer)(IDirect3DSwapChain9*,UINT,D3DBACKBUFFER_TYPE,IDirect3DSurface9**);
        HRESULT              (WINAPI *GetRasterStatus)(IDirect3DSwapChain9*,D3DRASTER_STATUS*);
        HRESULT              (WINAPI *GetDisplayMode)(IDirect3DSwapChain9*,D3DDISPLAYMODE*);
        HRESULT              (WINAPI *GetDevice)(IDirect3DSwapChain9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *GetPresentParameters)(IDirect3DSwapChain9*,D3DPRESENT_PARAMETERS*);
    }* lpVtbl;
};

struct IDirect3DResource9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DResource9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DResource9*);
        ULONG                (WINAPI *Release)(IDirect3DResource9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DResource9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DResource9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DResource9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DResource9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DResource9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DResource9*);
        void                 (WINAPI *PreLoad)(IDirect3DResource9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DResource9*);
    }* lpVtbl;
};

struct IDirect3DSurface9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DSurface9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DSurface9*);
        ULONG                (WINAPI *Release)(IDirect3DSurface9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DSurface9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DSurface9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DSurface9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DSurface9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DSurface9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DSurface9*);
        void                 (WINAPI *PreLoad)(IDirect3DSurface9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DSurface9*);
        // IDirect3DSurface9 methods
        HRESULT              (WINAPI *GetContainer)(IDirect3DSurface9*,REFIID,void**);
        HRESULT              (WINAPI *GetDesc)(IDirect3DSurface9*,D3DSURFACE_DESC*);
        HRESULT              (WINAPI *LockRect)(IDirect3DSurface9*,D3DLOCKED_RECT*,const RECT*,DWORD);
        HRESULT              (WINAPI *UnlockRect)(IDirect3DSurface9*);
        HRESULT              (WINAPI *GetDC)(IDirect3DSurface9*,HDC*);
        HRESULT              (WINAPI *ReleaseDC)(IDirect3DSurface9*,HDC);
    }* lpVtbl;
};

struct IDirect3DVertexBuffer9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DVertexBuffer9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DVertexBuffer9*);
        ULONG                (WINAPI *Release)(IDirect3DVertexBuffer9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DVertexBuffer9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DVertexBuffer9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DVertexBuffer9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DVertexBuffer9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DVertexBuffer9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DVertexBuffer9*);
        void                 (WINAPI *PreLoad)(IDirect3DVertexBuffer9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DVertexBuffer9*);
        // IDirect3DVertexBuffer9 methods
        HRESULT              (WINAPI *Lock)(IDirect3DVertexBuffer9*,UINT,UINT,void**,DWORD);
        HRESULT              (WINAPI *Unlock)(IDirect3DVertexBuffer9*);
        HRESULT              (WINAPI *GetDesc)(IDirect3DVertexBuffer9*,D3DVERTEXBUFFER_DESC*);
    }* lpVtbl;
};

struct IDirect3DIndexBuffer9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DIndexBuffer9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DIndexBuffer9*);
        ULONG                (WINAPI *Release)(IDirect3DIndexBuffer9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DIndexBuffer9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DIndexBuffer9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DIndexBuffer9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DIndexBuffer9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DIndexBuffer9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DIndexBuffer9*);
        void                 (WINAPI *PreLoad)(IDirect3DIndexBuffer9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DIndexBuffer9*);
        // IDirect3DIndexBuffer9 methods
        HRESULT              (WINAPI *Lock)(IDirect3DIndexBuffer9*,UINT,UINT,void**,DWORD);
        HRESULT              (WINAPI *Unlock)(IDirect3DIndexBuffer9*);
        HRESULT              (WINAPI *GetDesc)(IDirect3DIndexBuffer9*,D3DINDEXBUFFER_DESC*);
    }* lpVtbl;
};

struct IDirect3DBaseTexture9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DBaseTexture9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DBaseTexture9*);
        ULONG                (WINAPI *Release)(IDirect3DBaseTexture9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DBaseTexture9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DBaseTexture9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DBaseTexture9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DBaseTexture9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DBaseTexture9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DBaseTexture9*);
        void                 (WINAPI *PreLoad)(IDirect3DBaseTexture9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DBaseTexture9*);
        // IDirect3DBaseTexture9 methods
        DWORD                (WINAPI *SetLOD)(IDirect3DBaseTexture9*,DWORD);
        DWORD                (WINAPI *GetLOD)(IDirect3DBaseTexture9*);
        DWORD                (WINAPI *GetLevelCount)(IDirect3DBaseTexture9*);
        HRESULT              (WINAPI *SetAutoGenFilterType)(IDirect3DBaseTexture9*,D3DTEXTUREFILTERTYPE);
        D3DTEXTUREFILTERTYPE (WINAPI *GetAutoGenFilterType)(IDirect3DBaseTexture9*);
        void                 (WINAPI *GenerateMipSubLevels)(IDirect3DBaseTexture9*);
    }* lpVtbl;
};

struct IDirect3DCubeTexture9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DCubeTexture9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DCubeTexture9*);
        ULONG                (WINAPI *Release)(IDirect3DCubeTexture9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DCubeTexture9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DCubeTexture9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DCubeTexture9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DCubeTexture9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DCubeTexture9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DCubeTexture9*);
        void                 (WINAPI *PreLoad)(IDirect3DCubeTexture9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DCubeTexture9*);
        // IDirect3DBaseTexture9 methods
        DWORD                (WINAPI *SetLOD)(IDirect3DCubeTexture9*,DWORD);
        DWORD                (WINAPI *GetLOD)(IDirect3DCubeTexture9*);
        DWORD                (WINAPI *GetLevelCount)(IDirect3DCubeTexture9*);
        HRESULT              (WINAPI *SetAutoGenFilterType)(IDirect3DCubeTexture9*,D3DTEXTUREFILTERTYPE);
        D3DTEXTUREFILTERTYPE (WINAPI *GetAutoGenFilterType)(IDirect3DCubeTexture9*);
        void                 (WINAPI *GenerateMipSubLevels)(IDirect3DCubeTexture9*);
        // IDirect3DCubeTexture9 methods
        HRESULT              (WINAPI *GetLevelDesc)(IDirect3DCubeTexture9*,UINT,D3DSURFACE_DESC*);
        HRESULT              (WINAPI *GetCubeMapSurface)(IDirect3DCubeTexture9*,D3DCUBEMAP_FACES,UINT,IDirect3DSurface9**);
        HRESULT              (WINAPI *LockRect)(IDirect3DCubeTexture9*,D3DCUBEMAP_FACES,UINT,D3DLOCKED_RECT*,const RECT*,DWORD);
        HRESULT              (WINAPI *UnlockRect)(IDirect3DCubeTexture9*,D3DCUBEMAP_FACES,UINT);
        HRESULT              (WINAPI *AddDirtyRect)(IDirect3DCubeTexture9*,D3DCUBEMAP_FACES,const RECT*);
    }* lpVtbl;
};

struct IDirect3DTexture9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DTexture9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DTexture9*);
        ULONG                (WINAPI *Release)(IDirect3DTexture9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DTexture9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DTexture9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DTexture9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DTexture9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DTexture9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DTexture9*);
        void                 (WINAPI *PreLoad)(IDirect3DTexture9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DTexture9*);
        // IDirect3DBaseTexture9 methods
        DWORD                (WINAPI *SetLOD)(IDirect3DTexture9*,DWORD);
        DWORD                (WINAPI *GetLOD)(IDirect3DTexture9*);
        DWORD                (WINAPI *GetLevelCount)(IDirect3DTexture9*);
        HRESULT              (WINAPI *SetAutoGenFilterType)(IDirect3DTexture9*,D3DTEXTUREFILTERTYPE);
        D3DTEXTUREFILTERTYPE (WINAPI *GetAutoGenFilterType)(IDirect3DTexture9*);
        void                 (WINAPI *GenerateMipSubLevels)(IDirect3DTexture9*);
        // IDirect3DTexture9 methods
        HRESULT              (WINAPI *GetLevelDesc)(IDirect3DTexture9*,UINT,D3DSURFACE_DESC*);
        HRESULT              (WINAPI *GetSurfaceLevel)(IDirect3DTexture9*,UINT,IDirect3DSurface9**);
        HRESULT              (WINAPI *LockRect)(IDirect3DTexture9*,UINT,D3DLOCKED_RECT*,const RECT*,DWORD);
        HRESULT              (WINAPI *UnlockRect)(IDirect3DTexture9*,UINT);
        HRESULT              (WINAPI *AddDirtyRect)(IDirect3DTexture9*,const RECT*);
    }* lpVtbl;
};

struct IDirect3DVolumeTexture9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DVolumeTexture9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DVolumeTexture9*);
        ULONG                (WINAPI *Release)(IDirect3DVolumeTexture9*);
        // IDirect3DResource9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DVolumeTexture9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *SetPrivateData)(IDirect3DVolumeTexture9*,REFGUID,const void*,DWORD,DWORD);
        HRESULT              (WINAPI *GetPrivateData)(IDirect3DVolumeTexture9*,REFGUID,void*,DWORD*);
        HRESULT              (WINAPI *FreePrivateData)(IDirect3DVolumeTexture9*,REFGUID);
        DWORD                (WINAPI *SetPriority)(IDirect3DVolumeTexture9*,DWORD);
        DWORD                (WINAPI *GetPriority)(IDirect3DVolumeTexture9*);
        void                 (WINAPI *PreLoad)(IDirect3DVolumeTexture9*);
        D3DRESOURCETYPE      (WINAPI *GetType)(IDirect3DVolumeTexture9*);
        // IDirect3DBaseTexture9 methods
        DWORD                (WINAPI *SetLOD)(IDirect3DVolumeTexture9*,DWORD);
        DWORD                (WINAPI *GetLOD)(IDirect3DVolumeTexture9*);
        DWORD                (WINAPI *GetLevelCount)(IDirect3DVolumeTexture9*);
        HRESULT              (WINAPI *SetAutoGenFilterType)(IDirect3DVolumeTexture9*,D3DTEXTUREFILTERTYPE);
        D3DTEXTUREFILTERTYPE (WINAPI *GetAutoGenFilterType)(IDirect3DVolumeTexture9*);
        void                 (WINAPI *GenerateMipSubLevels)(IDirect3DVolumeTexture9*);
        // IDirect3DVolumeTexture9 methods
        HRESULT              (WINAPI *GetLevelDesc)(IDirect3DVolumeTexture9*,UINT,D3DVOLUME_DESC*);
        HRESULT              (WINAPI *GetVolumeLevel)(IDirect3DVolumeTexture9*,UINT,IDirect3DVolume9**);
        HRESULT              (WINAPI *LockBox)(IDirect3DVolumeTexture9*,UINT,D3DLOCKED_BOX*,const D3DBOX*,DWORD);
        HRESULT              (WINAPI *UnlockBox)(IDirect3DVolumeTexture9*,UINT);
        HRESULT              (WINAPI *AddDirtyBox)(IDirect3DVolumeTexture9*,const D3DBOX*);
    }* lpVtbl;
};

struct IDirect3DVertexDeclaration9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DVertexDeclaration9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DVertexDeclaration9*);
        ULONG                (WINAPI *Release)(IDirect3DVertexDeclaration9*);
        // IDirect3DVertexDeclaration9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DVertexDeclaration9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *GetDeclaration)(IDirect3DVertexDeclaration9*,D3DVERTEXELEMENT9*,UINT*);
    }* lpVtbl;
};

struct IDirect3DVertexShader9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DVertexShader9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DVertexShader9*);
        ULONG                (WINAPI *Release)(IDirect3DVertexShader9*);
        // IDirect3DVertexShader9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DVertexShader9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *GetFunction)(IDirect3DVertexShader9*,void*,UINT*);
    }* lpVtbl;
};

struct IDirect3DPixelShader9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DPixelShader9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DPixelShader9*);
        ULONG                (WINAPI *Release)(IDirect3DPixelShader9*);
        // IDirect3DPixelShader9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DPixelShader9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *GetFunction)(IDirect3DPixelShader9*,void*,UINT*);
    }* lpVtbl;
};

struct IDirect3DStateBlock9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DStateBlock9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DStateBlock9*);
        ULONG                (WINAPI *Release)(IDirect3DStateBlock9*);
        // IDirect3DStateBlock9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DStateBlock9*,IDirect3DDevice9**);
        HRESULT              (WINAPI *Capture)(IDirect3DStateBlock9*);
        HRESULT              (WINAPI *Apply)(IDirect3DStateBlock9*);
    }* lpVtbl;
};

struct IDirect3DQuery9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DQuery9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DQuery9*);
        ULONG                (WINAPI *Release)(IDirect3DQuery9*);
        // IDirect3DQuery9 methods
        HRESULT              (WINAPI *GetDevice)(IDirect3DQuery9*,IDirect3DDevice9**);
        D3DQUERYTYPE         (WINAPI *GetType)(IDirect3DQuery9*);
        DWORD                (WINAPI *GetDataSize)(IDirect3DQuery9*);
        HRESULT              (WINAPI *Issue)(IDirect3DQuery9*,DWORD);
        HRESULT              (WINAPI *GetData)(IDirect3DQuery9*,void*,DWORD,DWORD);
    }* lpVtbl;
};

struct IDirect3DDevice9 {
    struct {
        // IUnknown methods
        HRESULT              (WINAPI *QueryInterface)(IDirect3DDevice9*,REFIID,void**);
        ULONG                (WINAPI *AddRef)(IDirect3DDevice9*);
        ULONG                (WINAPI *Release)(IDirect3DDevice9*);
        // IDirect3DDevice9 methods
        HRESULT              (WINAPI *TestCooperativeLevel)(IDirect3DDevice9*);
        UINT                 (WINAPI *GetAvailableTextureMem)(IDirect3DDevice9*);
        HRESULT              (WINAPI *EvictManagedResources)(IDirect3DDevice9*);
        HRESULT              (WINAPI *GetDirect3D)(IDirect3DDevice9*,IDirect3D9**);
        HRESULT              (WINAPI *GetDeviceCaps)(IDirect3DDevice9*,D3DCAPS9*);
        HRESULT              (WINAPI *GetDisplayMode)(IDirect3DDevice9*,UINT,D3DDISPLAYMODE*);
        HRESULT              (WINAPI *GetCreationParameters)(IDirect3DDevice9*,D3DDEVICE_CREATION_PARAMETERS*);
        HRESULT              (WINAPI *SetCursorProperties)(IDirect3DDevice9*,UINT,UINT,IDirect3DSurface9*);
        void                 (WINAPI *SetCursorPosition)(IDirect3DDevice9*,int,int,DWORD);
        WINBOOL              (WINAPI *ShowCursor)(IDirect3DDevice9*,WINBOOL);
        HRESULT              (WINAPI *CreateAdditionalSwapChain)(IDirect3DDevice9*,D3DPRESENT_PARAMETERS*,IDirect3DSwapChain9**);
        HRESULT              (WINAPI *GetSwapChain)(IDirect3DDevice9*,UINT,IDirect3DSwapChain9**);
        UINT                 (WINAPI *GetNumberOfSwapChains)(IDirect3DDevice9*);
        HRESULT              (WINAPI *Reset)(IDirect3DDevice9*,D3DPRESENT_PARAMETERS*);
        HRESULT              (WINAPI *Present)(IDirect3DDevice9*,const RECT*,const RECT*,HWND,const RGNDATA*);
        HRESULT              (WINAPI *GetBackBuffer)(IDirect3DDevice9*,UINT,UINT,D3DBACKBUFFER_TYPE,IDirect3DSurface9**);
        HRESULT              (WINAPI *GetRasterStatus)(IDirect3DDevice9*,UINT,D3DRASTER_STATUS*);
        HRESULT              (WINAPI *SetDialogBoxMode)(IDirect3DDevice9*,WINBOOL);
        void                 (WINAPI *SetGammaRamp)(IDirect3DDevice9*,UINT,DWORD,const D3DGAMMARAMP*);
        void                 (WINAPI *GetGammaRamp)(IDirect3DDevice9*,UINT,D3DGAMMARAMP*);
        HRESULT              (WINAPI *CreateTexture)(IDirect3DDevice9*,UINT,UINT,UINT,DWORD,D3DFORMAT,D3DPOOL,IDirect3DTexture9**,HANDLE*);
        HRESULT              (WINAPI *CreateVolumeTexture)(IDirect3DDevice9*,UINT,UINT,UINT,UINT,DWORD,D3DFORMAT,D3DPOOL,IDirect3DVolumeTexture9**,HANDLE*);
        HRESULT              (WINAPI *CreateCubeTexture)(IDirect3DDevice9*,UINT,UINT,DWORD,D3DFORMAT,D3DPOOL,IDirect3DCubeTexture9**,HANDLE*);
        HRESULT              (WINAPI *CreateVertexBuffer)(IDirect3DDevice9*,UINT,DWORD,DWORD,D3DPOOL,IDirect3DVertexBuffer9**,HANDLE*);
        HRESULT              (WINAPI *CreateIndexBuffer)(IDirect3DDevice9*,UINT,DWORD,D3DFORMAT,D3DPOOL,IDirect3DIndexBuffer9**,HANDLE*);
        HRESULT              (WINAPI *CreateRenderTarget)(IDirect3DDevice9*,UINT,UINT,D3DFORMAT,D3DMULTISAMPLE_TYPE,DWORD,WINBOOL,IDirect3DSurface9**,HANDLE*);
        HRESULT              (WINAPI *CreateDepthStencilSurface)(IDirect3DDevice9*,UINT,UINT,D3DFORMAT,D3DMULTISAMPLE_TYPE,DWORD,WINBOOL,IDirect3DSurface9**,HANDLE*);
        HRESULT              (WINAPI *UpdateSurface)(IDirect3DDevice9*,IDirect3DSurface9*,const RECT*,IDirect3DSurface9*,const POINT*);
        HRESULT              (WINAPI *UpdateTexture)(IDirect3DDevice9*,IDirect3DBaseTexture9*,IDirect3DBaseTexture9*);
        HRESULT              (WINAPI *GetRenderTargetData)(IDirect3DDevice9*,IDirect3DSurface9*,IDirect3DSurface9*);
        HRESULT              (WINAPI *GetFrontBufferData)(IDirect3DDevice9*,UINT,IDirect3DSurface9*);
        HRESULT              (WINAPI *StretchRect)(IDirect3DDevice9*,IDirect3DSurface9*,const RECT*,IDirect3DSurface9*,const RECT*,D3DTEXTUREFILTERTYPE);
        HRESULT              (WINAPI *ColorFill)(IDirect3DDevice9*,IDirect3DSurface9*,const RECT*,D3DCOLOR);
        HRESULT              (WINAPI *CreateOffscreenPlainSurface)(IDirect3DDevice9*,UINT,UINT,D3DFORMAT,D3DPOOL,IDirect3DSurface9**,HANDLE*);
        HRESULT              (WINAPI *SetRenderTarget)(IDirect3DDevice9*,DWORD,IDirect3DSurface9*);
        HRESULT              (WINAPI *GetRenderTarget)(IDirect3DDevice9*,DWORD,IDirect3DSurface9**);
        HRESULT              (WINAPI *SetDepthStencilSurface)(IDirect3DDevice9*,IDirect3DSurface9*);
        HRESULT              (WINAPI *GetDepthStencilSurface)(IDirect3DDevice9*,IDirect3DSurface9**);
        HRESULT              (WINAPI *BeginScene)(IDirect3DDevice9*);
        HRESULT              (WINAPI *EndScene)(IDirect3DDevice9*);
        HRESULT              (WINAPI *Clear)(IDirect3DDevice9*,DWORD,const D3DRECT*,DWORD,D3DCOLOR,float,DWORD);
        HRESULT              (WINAPI *SetTransform)(IDirect3DDevice9*,D3DTRANSFORMSTATETYPE,const D3DMATRIX*);
        HRESULT              (WINAPI *GetTransform)(IDirect3DDevice9*,D3DTRANSFORMSTATETYPE,D3DMATRIX*);
        HRESULT              (WINAPI *MultiplyTransform)(IDirect3DDevice9*,D3DTRANSFORMSTATETYPE,const D3DMATRIX*);
        HRESULT              (WINAPI *SetViewport)(IDirect3DDevice9*,const D3DVIEWPORT9*);
        HRESULT              (WINAPI *GetViewport)(IDirect3DDevice9*,D3DVIEWPORT9*);
        HRESULT              (WINAPI *SetMaterial)(IDirect3DDevice9*,const D3DMATERIAL9*);
        HRESULT              (WINAPI *GetMaterial)(IDirect3DDevice9*,D3DMATERIAL9*);
        HRESULT              (WINAPI *SetLight)(IDirect3DDevice9*,DWORD,const D3DLIGHT9*);
        HRESULT              (WINAPI *GetLight)(IDirect3DDevice9*,DWORD,D3DLIGHT9*);
        HRESULT              (WINAPI *LightEnable)(IDirect3DDevice9*,DWORD,WINBOOL);
        HRESULT              (WINAPI *GetLightEnable)(IDirect3DDevice9*,DWORD,WINBOOL*);
        HRESULT              (WINAPI *SetClipPlane)(IDirect3DDevice9*,DWORD,const float*);
        HRESULT              (WINAPI *GetClipPlane)(IDirect3DDevice9*,DWORD,float*);
        HRESULT              (WINAPI *SetRenderState)(IDirect3DDevice9*,D3DRENDERSTATETYPE,DWORD);
        HRESULT              (WINAPI *GetRenderState)(IDirect3DDevice9*,D3DRENDERSTATETYPE,DWORD*);
        HRESULT              (WINAPI *CreateStateBlock)(IDirect3DDevice9*,D3DSTATEBLOCKTYPE,IDirect3DStateBlock9**);
        HRESULT              (WINAPI *BeginStateBlock)(IDirect3DDevice9*);
        HRESULT              (WINAPI *EndStateBlock)(IDirect3DDevice9*,IDirect3DStateBlock9**);
        HRESULT              (WINAPI *SetClipStatus)(IDirect3DDevice9*,const D3DCLIPSTATUS9*);
        HRESULT              (WINAPI *GetClipStatus)(IDirect3DDevice9*,D3DCLIPSTATUS9*);
        HRESULT              (WINAPI *GetTexture)(IDirect3DDevice9*,DWORD,IDirect3DBaseTexture9**);
        HRESULT              (WINAPI *SetTexture)(IDirect3DDevice9*,DWORD,IDirect3DBaseTexture9*);
        HRESULT              (WINAPI *GetTextureStageState)(IDirect3DDevice9*,DWORD,D3DTEXTURESTAGESTATETYPE,DWORD*);
        HRESULT              (WINAPI *SetTextureStageState)(IDirect3DDevice9*,DWORD,D3DTEXTURESTAGESTATETYPE,DWORD);
        HRESULT              (WINAPI *GetSamplerState)(IDirect3DDevice9*,DWORD,D3DSAMPLERSTATETYPE,DWORD*);
        HRESULT              (WINAPI *SetSamplerState)(IDirect3DDevice9*,DWORD,D3DSAMPLERSTATETYPE,DWORD);
        HRESULT              (WINAPI *ValidateDevice)(IDirect3DDevice9*,DWORD*);
        HRESULT              (WINAPI *SetPaletteEntries)(IDirect3DDevice9*,UINT,const PALETTEENTRY*);
        HRESULT              (WINAPI *GetPaletteEntries)(IDirect3DDevice9*,UINT,PALETTEENTRY*);
        HRESULT              (WINAPI *SetCurrentTexturePalette)(IDirect3DDevice9*,UINT);
        HRESULT              (WINAPI *GetCurrentTexturePalette)(IDirect3DDevice9*,UINT*);
        HRESULT              (WINAPI *SetScissorRect)(IDirect3DDevice9*,const RECT*);
        HRESULT              (WINAPI *GetScissorRect)(IDirect3DDevice9*,RECT*);
        HRESULT              (WINAPI *SetSoftwareVertexProcessing)(IDirect3DDevice9*,WINBOOL);
        WINBOOL              (WINAPI *GetSoftwareVertexProcessing)(IDirect3DDevice9*);
        HRESULT              (WINAPI *SetNPatchMode)(IDirect3DDevice9*,float);
        float                (WINAPI *GetNPatchMode)(IDirect3DDevice9*);
        HRESULT              (WINAPI *DrawPrimitive)(IDirect3DDevice9*,D3DPRIMITIVETYPE,UINT,UINT);
        HRESULT              (WINAPI *DrawIndexedPrimitive)(IDirect3DDevice9*,D3DPRIMITIVETYPE,INT,UINT,UINT,UINT,UINT);
        HRESULT              (WINAPI *DrawPrimitiveUP)(IDirect3DDevice9*,D3DPRIMITIVETYPE,UINT,const void*,UINT);
        HRESULT              (WINAPI *DrawIndexedPrimitiveUP)(IDirect3DDevice9*,D3DPRIMITIVETYPE,UINT,UINT,UINT,const void*,D3DFORMAT,const void*,UINT);
        HRESULT              (WINAPI *ProcessVertices)(IDirect3DDevice9*,UINT,UINT,UINT,IDirect3DVertexBuffer9*,IDirect3DVertexDeclaration9*,DWORD);
        HRESULT              (WINAPI *CreateVertexDeclaration)(IDirect3DDevice9*,const D3DVERTEXELEMENT9*,IDirect3DVertexDeclaration9**);
        HRESULT              (WINAPI *SetVertexDeclaration)(IDirect3DDevice9*,IDirect3DVertexDeclaration9*);
        HRESULT              (WINAPI *GetVertexDeclaration)(IDirect3DDevice9*,IDirect3DVertexDeclaration9**);
        HRESULT              (WINAPI *SetFVF)(IDirect3DDevice9*,DWORD);
        HRESULT              (WINAPI *GetFVF)(IDirect3DDevice9*,DWORD*);
        HRESULT              (WINAPI *CreateVertexShader)(IDirect3DDevice9*,const DWORD*,IDirect3DVertexShader9**);
        HRESULT              (WINAPI *SetVertexShader)(IDirect3DDevice9*,IDirect3DVertexShader9*);
        HRESULT              (WINAPI *GetVertexShader)(IDirect3DDevice9*,IDirect3DVertexShader9**);
        HRESULT              (WINAPI *SetVertexShaderConstantF)(IDirect3DDevice9*,UINT,const float*,UINT);
        HRESULT              (WINAPI *GetVertexShaderConstantF)(IDirect3DDevice9*,UINT,float*,UINT);
        HRESULT              (WINAPI *SetVertexShaderConstantI)(IDirect3DDevice9*,UINT,const int*,UINT);
        HRESULT              (WINAPI *GetVertexShaderConstantI)(IDirect3DDevice9*,UINT,int*,UINT);
        HRESULT              (WINAPI *SetVertexShaderConstantB)(IDirect3DDevice9*,UINT,const WINBOOL*,UINT);
        HRESULT              (WINAPI *GetVertexShaderConstantB)(IDirect3DDevice9*,UINT,WINBOOL*,UINT);
        HRESULT              (WINAPI *SetStreamSource)(IDirect3DDevice9*,UINT,IDirect3DVertexBuffer9*,UINT,UINT);
        HRESULT              (WINAPI *GetStreamSource)(IDirect3DDevice9*,UINT,IDirect3DVertexBuffer9**,UINT*,UINT*);
        HRESULT              (WINAPI *SetStreamSourceFreq)(IDirect3DDevice9*,UINT,UINT);
        HRESULT              (WINAPI *GetStreamSourceFreq)(IDirect3DDevice9*,UINT,UINT*);
        HRESULT              (WINAPI *SetIndices)(IDirect3DDevice9*,IDirect3DIndexBuffer9*);
        HRESULT              (WINAPI *GetIndices)(IDirect3DDevice9*,IDirect3DIndexBuffer9**);
        HRESULT              (WINAPI *CreatePixelShader)(IDirect3DDevice9*,const DWORD*,IDirect3DPixelShader9**);
        HRESULT              (WINAPI *SetPixelShader)(IDirect3DDevice9*,IDirect3DPixelShader9*);
        HRESULT              (WINAPI *GetPixelShader)(IDirect3DDevice9*,IDirect3DPixelShader9**);
        HRESULT              (WINAPI *SetPixelShaderConstantF)(IDirect3DDevice9*,UINT,const float*,UINT);
        HRESULT              (WINAPI *GetPixelShaderConstantF)(IDirect3DDevice9*,UINT,float*,UINT);
        HRESULT              (WINAPI *SetPixelShaderConstantI)(IDirect3DDevice9*,UINT,const int*,UINT);
        HRESULT              (WINAPI *GetPixelShaderConstantI)(IDirect3DDevice9*,UINT,int*,UINT);
        HRESULT              (WINAPI *SetPixelShaderConstantB)(IDirect3DDevice9*,UINT,const WINBOOL*,UINT);
        HRESULT              (WINAPI *GetPixelShaderConstantB)(IDirect3DDevice9*,UINT,WINBOOL*,UINT);
        HRESULT              (WINAPI *DrawRectPatch)(IDirect3DDevice9*,UINT,const float*,const D3DRECTPATCH_INFO*);
        HRESULT              (WINAPI *DrawTriPatch)(IDirect3DDevice9*,UINT,const float*,const D3DTRIPATCH_INFO*);
        HRESULT              (WINAPI *DeletePatch)(IDirect3DDevice9*,UINT);
        HRESULT              (WINAPI *CreateQuery)(IDirect3DDevice9*,D3DQUERYTYPE,IDirect3DQuery9**);
    }* lpVtbl;
};

/// @brief Represents the "d3d9.dll" library and supported functions.
extern struct _d3d9_dll {
    HMODULE              dll;
    int         (WINAPI *D3DPERF_BeginEvent)(D3DCOLOR,LPCWSTR);
    int         (WINAPI *D3DPERF_EndEvent)(void);
    DWORD       (WINAPI *D3DPERF_GetStatus)(void);
    BOOL        (WINAPI *D3DPERF_QueryRepeatFrame)(void);
    void        (WINAPI *D3DPERF_SetMarker)(D3DCOLOR,LPCWSTR);
    void        (WINAPI *D3DPERF_SetOptions)(DWORD);
    void        (WINAPI *D3DPERF_SetRegion)(D3DCOLOR,LPCWSTR);
    IDirect3D9* (WINAPI *Direct3DCreate9)(UINT);
} _d3d9;

/// @brief Returns true if the "d3d9.dll" library was freed successfully.
bool _free_d3d9_dll();

/// @brief Returns true if the "d3d9.dll" library was loaded successfully.
bool _load_d3d9_dll();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_windows_d3d9_h__
// -------------------------------------------------------------------------------------------------------------------------- //