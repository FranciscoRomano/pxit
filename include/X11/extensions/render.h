// ┌───────────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                           │
// │                                                                                               │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY.     │
// │ THE PREFIX "X" WAS ADDED TO ALL ENUMS, MACROS, STRUCTURES AND TYPE DEFINITIONS ALIKE.         │
// │                                                                                               │
// │ ALL MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE, WHICH IS SHOWN BELOW: │
// └───────────────────────────────────────────────────────────────────────────────────────────────┘
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

#include <X11/Xdefs.h>

typedef XID XGlyph;
typedef XID XGlyphSet;
typedef XID XPicture;
typedef XID XPictFormat;

#define X_RENDER_NAME                    "RENDER"
#define X_RENDER_MAJOR                   0
#define X_RENDER_MINOR                   11
#define X_RenderAddGlyphs                20
#define X_RenderAddGlyphsFromPicture     21
#define X_RenderChangePicture            5
#define X_RenderColorTrapezoids          14
#define X_RenderColorTriangles           15
#define X_RenderComposite                8
#define X_RenderCompositeGlyphs16        24
#define X_RenderCompositeGlyphs32        25
#define X_RenderCompositeGlyphs8         23
#define X_RenderCreateGlyphSet           17
#define X_RenderCreatePicture            4
#define X_RenderFillRectangles           26
#define X_RenderFreeGlyphs               22
#define X_RenderFreeGlyphSet             19
#define X_RenderFreePicture              7
#define X_RenderQueryDithers             3
#define X_RenderQueryPictFormats         1
#define X_RenderQueryVersion             0
#define X_RenderReferenceGlyphSet        18
#define X_RenderScale                    9
#define X_RenderSetPictureClipRectangles 6
// #define X_RenderTransform             16
#define X_RenderTrapezoids               10
#define X_RenderTriangles                11
#define X_RenderTriFan                   13
#define X_RenderTriStrip                 12

// Version 0.2
#define X_PictOpConjointAtop             0x29
#define X_PictOpConjointAtopReverse      0x2a
#define X_PictOpConjointClear            0x20
#define X_PictOpConjointDst              0x22
#define X_PictOpConjointIn               0x25
#define X_PictOpConjointInReverse        0x26
#define X_PictOpConjointMaximum          0x2b
#define X_PictOpConjointMinimum          0x20
#define X_PictOpConjointOut              0x27
#define X_PictOpConjointOutReverse       0x28
#define X_PictOpConjointOver             0x23
#define X_PictOpConjointOverReverse      0x24
#define X_PictOpConjointSrc              0x21
#define X_PictOpConjointXor              0x2b
#define X_PictOpDisjointAtop             0x19
#define X_PictOpDisjointAtopReverse      0x1a
#define X_PictOpDisjointClear            0x10
#define X_PictOpDisjointDst              0x12
#define X_PictOpDisjointIn               0x15
#define X_PictOpDisjointInReverse        0x16
#define X_PictOpDisjointMaximum          0x1b
#define X_PictOpDisjointMinimum          0x10
#define X_PictOpDisjointOut              0x17
#define X_PictOpDisjointOutReverse       0x18
#define X_PictOpDisjointOver             0x13
#define X_PictOpDisjointOverReverse      0x14
#define X_PictOpDisjointSrc              0x11
#define X_PictOpDisjointXor              0x1b

// Version 0.5
#define X_RenderCreateCursor             27

// Version 0.6
#define X_FilterBilinear                 "bilinear"
#define X_FilterNearest                  "nearest"
#define X_RenderQueryFilters             29
#define X_RenderSetPictureFilter         30
#define X_RenderSetPictureTransform      28
#define X_SubPixelHorizontalBGR          2
#define X_SubPixelHorizontalRGB          1
#define X_SubPixelNone                   5
#define X_SubPixelUnknown                0
#define X_SubPixelVerticalBGR            4
#define X_SubPixelVerticalRGB            3

// Version 0.7
#define X_RenderQueryPictIndexValues     2

// Version 0.8
#define X_RenderCreateAnimCursor         31

// Version 0.9
#define X_RenderAddTraps                 32

// Version 0.10
#define X_BadGlyph                       4
#define X_BadGlyphSet                    3
#define X_BadPictFormat                  0
#define X_BadPictOp                      2
#define X_BadPicture                     1
#define X_FilterAliasNone                -1
#define X_FilterBest                     "best" 
#define X_FilterConvolution              "convolution"
#define X_FilterFast                     "fast"
#define X_FilterGood                     "good"
#define X_PictOpAdd                      2
#define X_PictOpAtop                     9
#define X_PictOpAtopReverse              0
#define X_PictOpClear                    0
#define X_PictOpDst                      2
#define X_PictOpIn                       5
#define X_PictOpInReverse                6
#define X_PictOpMaximum                  3
#define X_PictOpMinimum                  0
#define X_PictOpOut                      7
#define X_PictOpOutReverse               8
#define X_PictOpOver                     3
#define X_PictOpOverReverse              4
#define X_PictOpSaturate                 3
#define X_PictOpSrc                      1
#define X_PictOpXor                      1
#define X_PictTypeDirect                 1
#define X_PictTypeIndexed                0
#define X_RenderCreateConicalGradient    36
#define X_RenderCreateLinearGradient     34
#define X_RenderCreateRadialGradient     35
#define X_RenderCreateSolidFill          33
#define X_RenderNumberErrors             (X_BadGlyph+1)
#define X_RenderNumberRequests           (X_RenderCreateConicalGradient+1)
#define X_RepeatNone                     0
#define X_RepeatNormal                   1
#define X_RepeatPad                      2
#define X_RepeatReflect                  3

// Version 0.11
#define X_CPAlphaMap                     (1 << 1)
#define X_CPAlphaXOrigin                 (1 << 2)
#define X_CPAlphaYOrigin                 (1 << 3)
#define X_CPClipMask                     (1 << 6)
#define X_CPClipXOrigin                  (1 << 4)
#define X_CPClipYOrigin                  (1 << 5)
#define X_CPComponentAlpha               (1 << 12)
#define X_CPDither                       (1 << 11)
#define X_CPGraphicsExposure             (1 << 7)
#define X_CPLastBit                      12
#define X_CPPolyEdge                     (1 << 9)
#define X_CPPolyMode                     (1 << 10)
#define X_CPRepeat                       (1 << 0)
#define X_CPSubwindowMode                (1 << 8)
#define X_PictOpBlendMaximum             0x3e
#define X_PictOpBlendMinimum             0x30
#define X_PictOpColorBurn                0x36
#define X_PictOpColorDodge               0x35
#define X_PictOpDarken                   0x33
#define X_PictOpDifference               0x39
#define X_PictOpExclusion                0x3a
#define X_PictOpHardLight                0x37
#define X_PictOpHSLColor                 0x3d
#define X_PictOpHSLHue                   0x3b
#define X_PictOpHSLLuminosity            0x3e
#define X_PictOpHSLSaturation            0x3c
#define X_PictOpLighten                  0x34
#define X_PictOpMultiply                 0x30
#define X_PictOpOverlay                  0x32
#define X_PictOpScreen                   0x31
#define X_PictOpSoftLight                0x38
#define X_PolyEdgeSharp                  0x00
#define X_PolyEdgeSmooth                 0x01
#define X_PolyModeImprecise              0x01
#define X_PolyModePrecise                0x00

#endif// _X11_extensions_render_h_