// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE, WHICH IS SHOWN BELOW: │
// └───────────────────────────────────────────────────────────────────────────────────────────┘
// 
// Copyright © 2000 SuSE, Inc.
// 
// Permission to use, copy, modify, distribute, and sell this software and its
// documentation for any purpose is hereby granted without fee, provided that
// the above copyright notice appear in all copies and that both that
// copyright notice and this permission notice appear in supporting
// documentation, and that the name of SuSE not be used in advertising or
// publicity pertaining to distribution of the software without specific,
// written prior permission.  SuSE makes no representations about the
// suitability of this software for any purpose.  It is provided "as is"
// without express or implied warranty.
// 
// SuSE DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL SuSE
// BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
// 
// Author:  Keith Packard, SuSE, Inc.

#ifndef _X11_extensions_Xrender_h_
#define _X11_extensions_Xrender_h_

#include <stdint.h>
#include "render.h"
#include "../Xfuncproto.h"
#include "../Xlib.h"
#include "../Xosdefs.h"
#include "../Xutil.h"

#define X_PictFormatID        (1 << 0)
#define X_PictFormatType      (1 << 1)
#define X_PictFormatDepth     (1 << 2)
#define X_PictFormatRed       (1 << 3)
#define X_PictFormatRedMask   (1 << 4)
#define X_PictFormatGreen     (1 << 5)
#define X_PictFormatGreenMask (1 << 6)
#define X_PictFormatBlue      (1 << 7)
#define X_PictFormatBlueMask  (1 << 8)
#define X_PictFormatAlpha     (1 << 9)
#define X_PictFormatAlphaMask (1 << 10)
#define X_PictFormatColormap  (1 << 11)
#define X_DoubleToFixed(f)    ((int32_t) ((f) * 65536))
#define X_FixedToDouble(f)    (((double) (f)) / 65536)
#define X_PictStandardARGB32  0
#define X_PictStandardRGB24   1
#define X_PictStandardA8      2
#define X_PictStandardA4      3
#define X_PictStandardA1      4
#define X_PictStandardNUM     5

typedef struct {
    int16_t             red;
    int16_t             redMask;
    int16_t             green;
    int16_t             greenMask;
    int16_t             blue;
    int16_t             blueMask;
    int16_t             alpha;
    int16_t             alphaMask;
} XRenderDirectFormat;

typedef struct {
    XPictFormat         id;
    int32_t             type;
    int32_t             depth;
    XRenderDirectFormat direct;
    XColormap           colormap;
} XRenderPictFormat;

typedef struct {
    int32_t             repeat;
    XPicture            alpha_map;
    int32_t             alpha_x_origin;
    int32_t             alpha_y_origin;
    int32_t             clip_x_origin;
    int32_t             clip_y_origin;
    XPixmap             clip_mask;
    XBool               graphics_exposures;
    int32_t             subwindow_mode;
    int32_t             poly_edge;
    int32_t             poly_mode;
    XAtom               dither;
    XBool               component_alpha;
} XRenderPictureAttributes;

typedef struct {
    uint16_t            red;
    uint16_t            green;
    uint16_t            blue;
    uint16_t            alpha;
} XRenderColor;

typedef struct {
    uint16_t            width;
    uint16_t            height;
    int16_t             x;
    int16_t             y;
    int16_t             xOff;
    int16_t             yOff;
} XGlyphInfo;

typedef struct {
    XGlyphSet           glyphset;
    const char*         chars;
    int32_t             nchars;
    int32_t             xOff;
    int32_t             yOff;
} XGlyphElt8;

typedef struct {
    XGlyphSet           glyphset;
    const uint16_t*     chars;
    int32_t             nchars;
    int32_t             xOff;
    int32_t             yOff;
} XGlyphElt16;

typedef struct {
    XGlyphSet           glyphset;
    const uint32_t*     chars;
    int32_t             nchars;
    int32_t             xOff;
    int32_t             yOff;
} XGlyphElt32;

typedef struct {
    double              x;
    double              y;
} XPointDouble;

typedef struct {
    int32_t             x;
    int32_t             y;
} XPointFixed;

typedef struct {
    XPointFixed         p1;
    XPointFixed         p2;
} XLineFixed;

typedef struct {
    XPointFixed         p1;
    XPointFixed         p2;
    XPointFixed         p3;
} XTriangle;

typedef struct {
    int32_t             x;
    int32_t             y;
    int32_t             radius;
} XCircle;

typedef struct {
    int32_t             top;
    int32_t             bottom;
    XLineFixed          left;
    XLineFixed          right;
} XTrapezoid;

typedef struct {
    int32_t             matrix[3][3];
} XTransform;

typedef struct {
    int32_t             nfilter;
    char**              filter;
    int32_t             nalias;
    int16_t*            alias;
} XFilters;

typedef struct {
    uint64_t            pixel;
    uint16_t            red;
    uint16_t            green;
    uint16_t            blue;
    uint16_t            alpha;
} XIndexValue;

typedef struct {
    Cursor              cursor;
    uint64_t            delay;
} XAnimCursor;

typedef struct {
    int32_t             left;
    int32_t             right;
    int32_t             y;
} XSpanFix;

typedef struct {
    XSpanFix            top;
    XSpanFix            bottom;
} XTrap;

typedef struct {
    XPointFixed         p1;
    XPointFixed         p2;
} XLinearGradient;

typedef struct {
    XCircle             inner;
    XCircle             outer;
} XRadialGradient;

typedef struct {
    XPointFixed         center;
    int32_t             angle;
} XConicalGradient;

_XFUNCPROTOBEGIN
#define XRenderQueryExtension(...)           _libX11.XRenderQueryExtension(__VA_ARGS__)
#define XRenderQueryVersion(...)             _libX11.XRenderQueryVersion(__VA_ARGS__)
#define XRenderQueryFormats(...)             _libX11.XRenderQueryFormats(__VA_ARGS__)
#define XRenderQuerySubpixelOrder(...)       _libX11.XRenderQuerySubpixelOrder(__VA_ARGS__)
#define XRenderSetSubpixelOrder(...)         _libX11.XRenderSetSubpixelOrder(__VA_ARGS__)
#define XRenderFindVisualFormat(...)         _libX11.XRenderFindVisualFormat(__VA_ARGS__)
#define XRenderFindFormat(...)               _libX11.XRenderFindFormat(__VA_ARGS__)
#define XRenderFindStandardFormat(...)       _libX11.XRenderFindStandardFormat(__VA_ARGS__)
#define XRenderQueryPictIndexValues(...)     _libX11.XRenderQueryPictIndexValues(__VA_ARGS__)
#define XRenderCreatePicture(...)            _libX11.XRenderCreatePicture(__VA_ARGS__)
#define XRenderChangePicture(...)            _libX11.XRenderChangePicture(__VA_ARGS__)
#define XRenderSetPictureClipRectangles(...) _libX11.XRenderSetPictureClipRectangles(__VA_ARGS__)
#define XRenderSetPictureClipRegion(...)     _libX11.XRenderSetPictureClipRegion(__VA_ARGS__)
#define XRenderSetPictureTransform(...)      _libX11.XRenderSetPictureTransform(__VA_ARGS__)
#define XRenderFreePicture(...)              _libX11.XRenderFreePicture(__VA_ARGS__)
#define XRenderComposite(...)                _libX11.XRenderComposite(__VA_ARGS__)
#define XRenderCreateGlyphSet(...)           _libX11.XRenderCreateGlyphSet(__VA_ARGS__)
#define XRenderReferenceGlyphSet(...)        _libX11.XRenderReferenceGlyphSet(__VA_ARGS__)
#define XRenderFreeGlyphSet(...)             _libX11.XRenderFreeGlyphSet(__VA_ARGS__)
#define XRenderAddGlyphs(...)                _libX11.XRenderAddGlyphs(__VA_ARGS__)
#define XRenderFreeGlyphs(...)               _libX11.XRenderFreeGlyphs(__VA_ARGS__)
#define XRenderCompositeString8(...)         _libX11.XRenderCompositeString8(__VA_ARGS__)
#define XRenderCompositeString16(...)        _libX11.XRenderCompositeString16(__VA_ARGS__)
#define XRenderCompositeString32(...)        _libX11.XRenderCompositeString32(__VA_ARGS__)
#define XRenderCompositeText8(...)           _libX11.XRenderCompositeText8(__VA_ARGS__)
#define XRenderCompositeText16(...)          _libX11.XRenderCompositeText16(__VA_ARGS__)
#define XRenderCompositeText32(...)          _libX11.XRenderCompositeText32(__VA_ARGS__)
#define XRenderFillRectangle(...)            _libX11.XRenderFillRectangle(__VA_ARGS__)
#define XRenderFillRectangles(...)           _libX11.XRenderFillRectangles(__VA_ARGS__)
#define XRenderCompositeTrapezoids(...)      _libX11.XRenderCompositeTrapezoids(__VA_ARGS__)
#define XRenderCompositeTriangles(...)       _libX11.XRenderCompositeTriangles(__VA_ARGS__)
#define XRenderCompositeTriStrip(...)        _libX11.XRenderCompositeTriStrip(__VA_ARGS__)
#define XRenderCompositeTriFan(...)          _libX11.XRenderCompositeTriFan(__VA_ARGS__)
#define XRenderCompositeDoublePoly(...)      _libX11.XRenderCompositeDoublePoly(__VA_ARGS__)
#define XRenderParseColor(...)               _libX11.XRenderParseColor(__VA_ARGS__)
#define XRenderCreateCursor(...)             _libX11.XRenderCreateCursor(__VA_ARGS__)
#define XRenderQueryFilters(...)             _libX11.XRenderQueryFilters(__VA_ARGS__)
#define XRenderSetPictureFilter(...)         _libX11.XRenderSetPictureFilter(__VA_ARGS__)
#define XRenderCreateAnimCursor(...)         _libX11.XRenderCreateAnimCursor(__VA_ARGS__)
#define XRenderAddTraps(...)                 _libX11.XRenderAddTraps(__VA_ARGS__)
#define XRenderCreateSolidFill(...)          _libX11.XRenderCreateSolidFill(__VA_ARGS__)
#define XRenderCreateLinearGradient(...)     _libX11.XRenderCreateLinearGradient(__VA_ARGS__)
#define XRenderCreateRadialGradient(...)     _libX11.XRenderCreateRadialGradient(__VA_ARGS__)
#define XRenderCreateConicalGradient(...)    _libX11.XRenderCreateConicalGradient(__VA_ARGS__)
_XFUNCPROTOEND

#endif// _X11_extensions_Xrender_h_