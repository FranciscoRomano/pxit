// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! THIS IS A MODIFIED VERSION OF THE ORIGINAL HEADER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! │
// ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
// │ DATE: 2025-02-27                                                                                                          │
// │ FILE: "C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\dxgitype.h"                                         │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __dxgitype_h__
#define __dxgitype_h__ 1
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "dxgicommon.h"
#include "dxgiformat.h"

#define _FACDXGI                                0x87a
#define MAKE_DXGI_HRESULT(code)                 MAKE_HRESULT(1, _FACDXGI, code)
#define MAKE_DXGI_STATUS(code)                  MAKE_HRESULT(0, _FACDXGI, code)

#define DXGI_CPU_ACCESS_NONE                    0
#define DXGI_CPU_ACCESS_DYNAMIC                 1
#define DXGI_CPU_ACCESS_READ_WRITE              2
#define DXGI_CPU_ACCESS_SCRATCH                 3
#define DXGI_CPU_ACCESS_FIELD                   15

typedef struct D3DCOLORVALUE                    D3DCOLORVALUE;
typedef struct DXGI_GAMMA_CONTROL               DXGI_GAMMA_CONTROL;
typedef struct DXGI_GAMMA_CONTROL_CAPABILITIES  DXGI_GAMMA_CONTROL_CAPABILITIES;
typedef struct DXGI_JPEG_AC_HUFFMAN_TABLE       DXGI_JPEG_AC_HUFFMAN_TABLE;
typedef struct DXGI_JPEG_DC_HUFFMAN_TABLE       DXGI_JPEG_DC_HUFFMAN_TABLE;
typedef struct DXGI_JPEG_QUANTIZATION_TABLE     DXGI_JPEG_QUANTIZATION_TABLE;
typedef struct DXGI_MODE_DESC                   DXGI_MODE_DESC;
typedef enum   DXGI_MODE_SCANLINE_ORDER         DXGI_MODE_SCANLINE_ORDER;
typedef enum   DXGI_MODE_SCALING                DXGI_MODE_SCALING;
typedef enum   DXGI_MODE_ROTATION               DXGI_MODE_ROTATION;
typedef struct DXGI_RGB                         DXGI_RGB;
typedef struct DXGI_RGBA                        DXGI_RGBA;

enum DXGI_MODE_SCANLINE_ORDER {
    DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED        = 0x0,
    DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE        = 0x1,
    DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST  = 0x2,
    DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST  = 0x3
};

enum DXGI_MODE_SCALING {
    DXGI_MODE_SCALING_UNSPECIFIED               = 0x0,
    DXGI_MODE_SCALING_CENTERED                  = 0x1,
    DXGI_MODE_SCALING_STRETCHED                 = 0x2
};

enum DXGI_MODE_ROTATION {
    DXGI_MODE_ROTATION_UNSPECIFIED              = 0x0,
    DXGI_MODE_ROTATION_IDENTITY                 = 0x1,
    DXGI_MODE_ROTATION_ROTATE90                 = 0x2,
    DXGI_MODE_ROTATION_ROTATE180                = 0x3,
    DXGI_MODE_ROTATION_ROTATE270                = 0x4
};

struct D3DCOLORVALUE {
    float                                       r;
    float                                       g;
    float                                       b;
    float                                       a;
};

struct DXGI_GAMMA_CONTROL {
    DXGI_RGB                                    Scale;
    DXGI_RGB                                    Offset;
    DXGI_RGB                                    GammaCurve[ 1025 ];
};

struct DXGI_GAMMA_CONTROL_CAPABILITIES {
    BOOL                                        ScaleAndOffsetSupported;
    float                                       MaxConvertedValue;
    float                                       MinConvertedValue;
    UINT                                        NumGammaControlPoints;
    float                                       ControlPointPositions[1025];
};

struct DXGI_MODE_DESC {
    UINT                                        Width;
    UINT                                        Height;
    DXGI_RATIONAL                               RefreshRate;
    DXGI_FORMAT                                 Format;
    DXGI_MODE_SCANLINE_ORDER                    ScanlineOrdering;
    DXGI_MODE_SCALING                           Scaling;
};

struct DXGI_JPEG_AC_HUFFMAN_TABLE {
    BYTE                                        CodeCounts[16];
    BYTE                                        CodeValues[162];
};

struct DXGI_JPEG_DC_HUFFMAN_TABLE {
    BYTE                                        CodeCounts[12];
    BYTE                                        CodeValues[12];
};

struct DXGI_JPEG_QUANTIZATION_TABLE {
    BYTE                                        Elements[64];
};

struct DXGI_RGB {
    float                                       Red;
    float                                       Green;
    float                                       Blue;
};

struct DXGI_RGBA {
    float                                       r;
    float                                       g;
    float                                       b;
    float                                       a;
};

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__dxgitype_h__
// -------------------------------------------------------------------------------------------------------------------------- //