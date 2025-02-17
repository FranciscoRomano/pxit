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

#ifndef _X11_extensions_render_h_
#define _X11_extensions_render_h_

#include <stdint.h>

#define RENDER_NAME                    "RENDER"
#define RENDER_MAJOR                   0
#define RENDER_MINOR                   11
#define RenderAddGlyphs                20
#define RenderAddGlyphsFromPicture     21
#define RenderChangePicture            5
#define RenderColorTrapezoids          14
#define RenderColorTriangles           15
#define RenderComposite                8
#define RenderCompositeGlyphs16        24
#define RenderCompositeGlyphs32        25
#define RenderCompositeGlyphs8         23
#define RenderCreateGlyphSet           17
#define RenderCreatePicture            4
#define RenderFillRectangles           26
#define RenderFreeGlyphs               22
#define RenderFreeGlyphSet             19
#define RenderFreePicture              7
#define RenderQueryDithers             3
#define RenderQueryPictFormats         1
#define RenderQueryVersion             0
#define RenderReferenceGlyphSet        18
#define RenderScale                    9
#define RenderSetPictureClipRectangles 6
// #define RenderTransform             16
#define RenderTrapezoids               10
#define RenderTriangles                11
#define RenderTriFan                   13
#define RenderTriStrip                 12

// Version 0.2
#define PictOpConjointAtop             0x29
#define PictOpConjointAtopReverse      0x2a
#define PictOpConjointClear            0x20
#define PictOpConjointDst              0x22
#define PictOpConjointIn               0x25
#define PictOpConjointInReverse        0x26
#define PictOpConjointMaximum          0x2b
#define PictOpConjointMinimum          0x20
#define PictOpConjointOut              0x27
#define PictOpConjointOutReverse       0x28
#define PictOpConjointOver             0x23
#define PictOpConjointOverReverse      0x24
#define PictOpConjointSrc              0x21
#define PictOpConjointXor              0x2b
#define PictOpDisjointAtop             0x19
#define PictOpDisjointAtopReverse      0x1a
#define PictOpDisjointClear            0x10
#define PictOpDisjointDst              0x12
#define PictOpDisjointIn               0x15
#define PictOpDisjointInReverse        0x16
#define PictOpDisjointMaximum          0x1b
#define PictOpDisjointMinimum          0x10
#define PictOpDisjointOut              0x17
#define PictOpDisjointOutReverse       0x18
#define PictOpDisjointOver             0x13
#define PictOpDisjointOverReverse      0x14
#define PictOpDisjointSrc              0x11
#define PictOpDisjointXor              0x1b

// Version 0.5
#define RenderCreateCursor             27

// Version 0.6
#define FilterBilinear                 "bilinear"
#define FilterNearest                  "nearest"
#define RenderQueryFilters             29
#define RenderSetPictureFilter         30
#define RenderSetPictureTransform      28
#define SubPixelHorizontalBGR          2
#define SubPixelHorizontalRGB          1
#define SubPixelNone                   5
#define SubPixelUnknown                0
#define SubPixelVerticalBGR            4
#define SubPixelVerticalRGB            3

// Version 0.7
#define RenderQueryPictIndexValues     2

// Version 0.8
#define RenderCreateAnimCursor         31

// Version 0.9
#define RenderAddTraps                 32

// Version 0.10
#define BadGlyph                       4
#define BadGlyphSet                    3
#define BadPictFormat                  0
#define BadPictOp                      2
#define BadPicture                     1
#define FilterAliasNone                -1
#define FilterBest                     "best"
#define FilterConvolution              "convolution"
#define FilterFast                     "fast"
#define FilterGood                     "good"
#define PictOpAdd                      2
#define PictOpAtop                     9
#define PictOpAtopReverse              0
#define PictOpClear                    0
#define PictOpDst                      2
#define PictOpIn                       5
#define PictOpInReverse                6
#define PictOpMaximum                  3
#define PictOpMinimum                  0
#define PictOpOut                      7
#define PictOpOutReverse               8
#define PictOpOver                     3
#define PictOpOverReverse              4
#define PictOpSaturate                 3
#define PictOpSrc                      1
#define PictOpXor                      1
#define PictTypeDirect                 1
#define PictTypeIndexed                0
#define RenderCreateConicalGradient    36
#define RenderCreateLinearGradient     34
#define RenderCreateRadialGradient     35
#define RenderCreateSolidFill          33
#define RenderNumberErrors             (BadGlyph+1)
#define RenderNumberRequests           (RenderCreateConicalGradient+1)
#define RepeatNone                     0
#define RepeatNormal                   1
#define RepeatPad                      2
#define RepeatReflect                  3

// Version 0.11
#define CPAlphaMap                     (1 << 1)
#define CPAlphaXOrigin                 (1 << 2)
#define CPAlphaYOrigin                 (1 << 3)
#define CPClipMask                     (1 << 6)
#define CPClipXOrigin                  (1 << 4)
#define CPClipYOrigin                  (1 << 5)
#define CPComponentAlpha               (1 << 12)
#define CPDither                       (1 << 11)
#define CPGraphicsExposure             (1 << 7)
#define CPLastBit                      12
#define CPPolyEdge                     (1 << 9)
#define CPPolyMode                     (1 << 10)
#define CPRepeat                       (1 << 0)
#define CPSubwindowMode                (1 << 8)
#define PictOpBlendMaximum             0x3e
#define PictOpBlendMinimum             0x30
#define PictOpColorBurn                0x36
#define PictOpColorDodge               0x35
#define PictOpDarken                   0x33
#define PictOpDifference               0x39
#define PictOpExclusion                0x3a
#define PictOpHardLight                0x37
#define PictOpHSLColor                 0x3d
#define PictOpHSLHue                   0x3b
#define PictOpHSLLuminosity            0x3e
#define PictOpHSLSaturation            0x3c
#define PictOpLighten                  0x34
#define PictOpMultiply                 0x30
#define PictOpOverlay                  0x32
#define PictOpScreen                   0x31
#define PictOpSoftLight                0x38
#define PolyEdgeSharp                  0x00
#define PolyEdgeSmooth                 0x01
#define PolyModeImprecise              0x01
#define PolyModePrecise                0x00

typedef uint32_t XID;
typedef XID      XGlyph;
typedef XID      XGlyphSet;
typedef XID      XPicture;
typedef XID      XPictFormat;

#endif// _X11_extensions_render_h_