// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE, WHICH IS SHOWN BELOW: │
// └───────────────────────────────────────────────────────────────────────────────────────────┘
// 
// Copyright 1985, 1986, 1987, 1991, 1998  The Open Group
// 
// Permission to use, copy, modify, distribute, and sell this software and its
// documentation for any purpose is hereby granted without fee, provided that
// the above copyright notice appear in all copies and that both that
// copyright notice and this permission notice appear in supporting
// documentation.
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
// AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// Except as contained in this notice, the name of The Open Group shall not be
// used in advertising or otherwise to promote the sale, use or other dealings
// in this Software without prior written authorization from The Open Group.
//
//    Xlib.h - Header definition and support file for the C subroutine
//    interface library (Xlib) to the X XWindow System Protocol (V11).
//    Structures and symbols starting with "_" are private to the library.

#ifndef _X11_Xlib_h_
#define _X11_Xlib_h_

#define XlibSpecificationRelease 6

#include <X11/X.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

// The Xlib structs are full of implicit padding to properly align members.
// We can't clean that up without breaking ABI, so tell clang not to bother complaining about it.
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

#define AllPlanes                       ((uint64_t)~0L)
#define BitmapBitOrder(dpy)             (((XDisplay*)(dpy))->bitmap_bit_order)
#define BitmapPad(dpy)                  (((XDisplay*)(dpy))->bitmap_pad)
#define BitmapUnit(dpy)                 (((XDisplay*)(dpy))->bitmap_unit)
#define BlackPixel(dpy,scr)             (ScreenOfDisplay(dpy,scr)->black_pixel)
#define BlackPixelOfScreen(s)           ((s)->black_pixel)
#define CellsOfScreen(s)                (DefaultVisualOfScreen((s))->map_entries)
#define ConnectionNumber(dpy)           (((XDisplay*)(dpy))->fd)
#define DefaultColormap(dpy,scr)        (ScreenOfDisplay(dpy,scr)->cmap)
#define DefaultColormapOfScreen(s)      ((s)->cmap)
#define DefaultDepth(dpy,scr)           (ScreenOfDisplay(dpy,scr)->root_depth)
#define DefaultDepthOfScreen(s)         ((s)->root_depth)
#define DefaultGC(dpy,scr)              (ScreenOfDisplay(dpy,scr)->default_gc)
#define DefaultGCOfScreen(s)            ((s)->default_gc)
#define DefaultRootWindow(dpy)          (ScreenOfDisplay(dpy,DefaultScreen(dpy))->root)
#define DefaultScreen(dpy)              (((XDisplay*)(dpy))->default_screen)
#define DefaultScreenOfDisplay(dpy)     ScreenOfDisplay(dpy,DefaultScreen(dpy))
#define DefaultVisual(dpy,scr)          (ScreenOfDisplay(dpy,scr)->root_visual)
#define DefaultVisualOfScreen(s)        ((s)->root_visual)
#define DisplayCells(dpy,scr)           (DefaultVisual(dpy,scr)->map_entries)
#define DisplayHeight(dpy,scr)          (ScreenOfDisplay(dpy,scr)->height)
#define DisplayHeightMM(dpy,scr)        (ScreenOfDisplay(dpy,scr)->mheight)
#define DisplayOfScreen(s)              ((s)->display)
#define DisplayPlanes(dpy,scr)          (ScreenOfDisplay(dpy,scr)->root_depth)
#define DisplayString(dpy)              (((XDisplay*)(dpy))->display_name)
#define DisplayWidth(dpy,scr)           (ScreenOfDisplay(dpy,scr)->width)
#define DisplayWidthMM(dpy,scr)         (ScreenOfDisplay(dpy,scr)->mwidth)
#define DoesBackingStore(s)             ((s)->backing_store)
#define DoesSaveUnders(s)               ((s)->save_unders)
#define EventMaskOfScreen(s)            ((s)->root_input_mask)
#define HeightMMOfScreen(s)             ((s)->mheight)
#define HeightOfScreen(s)               ((s)->height)
#define ImageByteOrder(dpy)             (((XDisplay*)(dpy))->byte_order)
#define LastKnownRequestProcessed(dpy)  (((XDisplay*)(dpy))->last_request_read)
#define MaxCmapsOfScreen(s)             ((s)->max_maps)
#define MinCmapsOfScreen(s)             ((s)->min_maps)
#define NextRequest(dpy)                (((XDisplay*)(dpy))->request + 1)
#define PlanesOfScreen(s)               ((s)->root_depth)
#define ProtocolRevision(dpy)           (((XDisplay*)(dpy))->proto_minor_version)
#define ProtocolVersion(dpy)            (((XDisplay*)(dpy))->proto_major_version)
#define QLength(dpy)                    (((XDisplay*)(dpy))->qlen)
#define QueuedAfterFlush                2
#define QueuedAfterReading              1
#define QueuedAlready                   0
#define RootWindow(dpy,scr)             (ScreenOfDisplay(dpy,scr)->root)
#define RootWindowOfScreen(s)           ((s)->root)
#define ScreenCount(dpy)                (((XDisplay*)(dpy))->nscreens)
#define ScreenOfDisplay(dpy,scr)        (&((XDisplay*)(dpy))->screens[scr])
#define ServerVendor(dpy)               (((XDisplay*)(dpy))->vendor)
#define VendorRelease(dpy)              (((XDisplay*)(dpy))->release)
#define WhitePixel(dpy,scr)             (ScreenOfDisplay(dpy,scr)->white_pixel)
#define WhitePixelOfScreen(s)           ((s)->white_pixel)
#define WidthMMOfScreen(s)              ((s)->mwidth)
#define WidthOfScreen(s)                ((s)->width)
#define XAllocID(dpy)                   ((*((XDisplay*)(dpy))->resource_alloc)((dpy)))
#define XBufferOverflow                 -1
#define XIMHighlight                    (1L<<2)
#define XIMHotKeyStateOFF               (0x0002L)
#define XIMHotKeyStateON                (0x0001L)
#define XIMInitialState                 1L
#define XIMPreeditArea                  0x0001L
#define XIMPreeditCallbacks             0x0002L
#define XIMPreeditDisable               (1L<<1)
#define XIMPreeditEnable                1L
#define XIMPreeditNone                  0x0010L
#define XIMPreeditNothing               0x0008L
#define XIMPreeditPosition              0x0004L
#define XIMPreeditUnKnown               0L
#define XIMPreserveState                (1L<<1)
#define XIMPrimary                      (1L<<5)
#define XIMReverse                      1L
#define XIMSecondary                    (1L<<6)
#define XIMStatusArea                   0x0100L
#define XIMStatusCallbacks              0x0200L
#define XIMStatusNone                   0x0800L
#define XIMStatusNothing                0x0400L
#define XIMStringConversionBottomEdge   (0x00000008)
#define XIMStringConversionBuffer       (0x0001)
#define XIMStringConversionChar         (0x0004)
#define XIMStringConversionConcealed    (0x00000010)
#define XIMStringConversionLeftEdge     (0x00000001)
#define XIMStringConversionLine         (0x0002)
#define XIMStringConversionRetrieval    (0x0002)
#define XIMStringConversionRightEdge    (0x00000002)
#define XIMStringConversionSubstitution (0x0001)
#define XIMStringConversionTopEdge      (0x00000004)
#define XIMStringConversionWord         (0x0003)
#define XIMStringConversionWrapped      (0x00000020)
#define XIMTertiary                     (1L<<7)
#define XIMUnderline                    (1L<<1)
#define XIMVisibleToBackword            (1L<<9)
#define XIMVisibleToCenter              (1L<<10)
#define XIMVisibleToForward             (1L<<8)
#define XLookupBoth                     4
#define XLookupChars                    2
#define XLookupKeySym                   3
#define XLookupNone                     1
#define XNArea                          "area"
#define XNAreaNeeded                    "areaNeeded"
#define XNBackground                    "background"
#define XNBackgroundPixmap              "backgroundPixmap"
#define XNBaseFontName                  "baseFontName"
#define XNClientWindow                  "clientWindow"
#define XNColormap                      "colorMap"
#define XNContextualDrawing             "contextualDrawing"
#define XNCursor                        "cursor"
#define XNDefaultString                 "defaultString"
#define XNDestroyCallback               "destroyCallback"
#define XNDirectionalDependentDrawing   "directionalDependentDrawing"
#define XNFilterEvents                  "filterEvents"
#define XNFocusWindow                   "focusWindow"
#define XNFontInfo                      "fontInfo"
#define XNFontSet                       "fontSet"
#define XNForeground                    "foreground"
#define XNGeometryCallback              "geometryCallback"
#define XNHotKey                        "hotKey"
#define XNHotKeyState                   "hotKeyState"
#define XNInputStyle                    "inputStyle"
#define XNLineSpace                     "lineSpace"
#define XNMissingCharSet                "missingCharSet"
#define XNOMAutomatic                   "omAutomatic"
#define XNOrientation                   "orientation"
#define XNPreeditAttributes             "preeditAttributes"
#define XNPreeditCaretCallback          "preeditCaretCallback"
#define XNPreeditDoneCallback           "preeditDoneCallback"
#define XNPreeditDrawCallback           "preeditDrawCallback"
#define XNPreeditStartCallback          "preeditStartCallback"
#define XNPreeditState                  "preeditState"
#define XNPreeditStateNotifyCallback    "preeditStateNotifyCallback"
#define XNQueryICValuesList             "queryICValuesList"
#define XNQueryIMValuesList             "queryIMValuesList"
#define XNQueryInputStyle               "queryInputStyle"
#define XNQueryOrientation              "queryOrientation"
#define XNR6PreeditCallback             "r6PreeditCallback"
#define XNRequiredCharSet               "requiredCharSet"
#define XNResetState                    "resetState"
#define XNResourceClass                 "resourceClass"
#define XNResourceName                  "resourceName"
#define XNSeparatorofNestedList         "separatorofNestedList"
#define XNSpotLocation                  "spotLocation"
#define XNStatusAttributes              "statusAttributes"
#define XNStatusDoneCallback            "statusDoneCallback"
#define XNStatusDrawCallback            "statusDrawCallback"
#define XNStatusStartCallback           "statusStartCallback"
#define XNStdColormap                   "stdColorMap"
#define XNStringConversion              "stringConversion"
#define XNStringConversionCallback      "stringConversionCallback"
#define XNVaNestedList                  "XNVaNestedList"
#define XNVisiblePosition               "visiblePosition"

typedef struct _XIC*                               XIC;
typedef struct _XIM*                               XIM;
typedef struct _XOC*                               XOC;
typedef struct _XOC**                              XFontSet;
typedef struct _XOM*                               XOM;
typedef struct XAnyEvent                           XAnyEvent;
typedef struct XArc                                XArc;
typedef struct XButtonEvent                        XButtonEvent;
typedef struct XChar2b                             XChar2b;
typedef struct XCharStruct                         XCharStruct;
typedef struct XCirculateEvent                     XCirculateEvent;
typedef struct XCirculateRequestEvent              XCirculateRequestEvent;
typedef struct XClientMessageEvent                 XClientMessageEvent;
typedef struct XColor                              XColor;
typedef struct XColormapEvent                      XColormapEvent;
typedef struct XConfigureEvent                     XConfigureEvent;
typedef struct XConfigureRequestEvent              XConfigureRequestEvent;
typedef struct XCreateWindowEvent                  XCreateWindowEvent;
typedef struct XCrossingEvent                      XCrossingEvent;
typedef struct XDepth                              XDepth;
typedef struct XDestroyWindowEvent                 XDestroyWindowEvent;
typedef struct XDisplay                            XDisplay;
typedef struct XErrorEvent                         XErrorEvent;
typedef struct XExposeEvent                        XExposeEvent;
typedef struct XExtCodes                           XExtCodes;
typedef struct XExtData                            XExtData;
typedef struct XFocusChangeEvent                   XFocusChangeEvent;
typedef struct XFontProp                           XFontProp;
typedef struct XFontSetExtents                     XFontSetExtents;
typedef struct XFontStruct                         XFontStruct;
typedef struct _XGC*                                XGC;
typedef struct XGCValues                           XGCValues;
typedef struct XGenericEvent                       XGenericEvent;
typedef struct XGenericEventCookie                 XGenericEventCookie;
typedef struct XGraphicsExposeEvent                XGraphicsExposeEvent;
typedef struct XGravityEvent                       XGravityEvent;
typedef struct XHostAddress                        XHostAddress;
typedef struct XICCallback                         XICCallback;
typedef struct XImage                              XImage;
typedef struct XIMCallback                         XIMCallback;
typedef uint64_t                                   XIMFeedback;
typedef uint64_t                                   XIMHotKeyState;
typedef struct XIMHotKeyTrigger                    XIMHotKeyTrigger;
typedef struct XIMHotKeyTriggers                   XIMHotKeyTriggers;
typedef struct XIMPreeditCaretCallbackStruct       XIMPreeditCaretCallbackStruct;
typedef struct XIMPreeditDrawCallbackStruct        XIMPreeditDrawCallbackStruct;
typedef uint64_t                                   XIMPreeditState;
typedef struct XIMPreeditStateNotifyCallbackStruct XIMPreeditStateNotifyCallbackStruct;
typedef uint64_t                                   XIMResetState;
typedef struct XIMStatusDrawCallbackStruct         XIMStatusDrawCallbackStruct;
typedef struct XIMStringConversionCallbackStruct   XIMStringConversionCallbackStruct;
typedef uint64_t                                   XIMStringConversionFeedback;
typedef uint16_t                                   XIMStringConversionOperation;
typedef uint16_t                                   XIMStringConversionPosition;
typedef uint16_t                                   XIMStringConversionType;
typedef uint64_t                                   XIMStyle;
typedef struct XIMStyles                           XIMStyles;
typedef struct XIMText                             XIMText;
typedef struct XIMValuesList                       XIMValuesList;
typedef struct XKeyboardControl                    XKeyboardControl;
typedef struct XKeyboardState                      XKeyboardState;
typedef struct XKeyEvent                           XKeyEvent;
typedef struct XKeymapEvent                        XKeymapEvent;
typedef struct XMapEvent                           XMapEvent;
typedef struct XMappingEvent                       XMappingEvent;
typedef struct XMapRequestEvent                    XMapRequestEvent;
typedef struct XmbTextItem                         XmbTextItem;
typedef struct XModifierKeymap                     XModifierKeymap;
typedef struct XMotionEvent                        XMotionEvent;
typedef struct XNoExposeEvent                      XNoExposeEvent;
typedef struct XOMCharSetList                      XOMCharSetList;
typedef struct XOMFontInfo                         XOMFontInfo;
typedef struct XOMOrientation                      XOMOrientation;
typedef struct XPixmapFormatValues                 XPixmapFormatValues;
typedef struct XPoint                              XPoint;
typedef struct XPrivate                            XPrivate;
typedef struct XPropertyEvent                      XPropertyEvent;
typedef struct XRectangle                          XRectangle;
typedef struct XReparentEvent                      XReparentEvent;
typedef struct XResizeRequestEvent                 XResizeRequestEvent;
typedef struct XrmHashBucketRec                    XrmHashBucketRec;
typedef struct XScreen                             XScreen;
typedef struct XScreenFormat                       XScreenFormat;
typedef struct XSegment                            XSegment;
typedef struct XSelectionClearEvent                XSelectionClearEvent;
typedef struct XSelectionEvent                     XSelectionEvent;
typedef struct XSelectionRequestEvent              XSelectionRequestEvent;
typedef struct XServerInterpretedAddress           XServerInterpretedAddress;
typedef struct XSetWindowAttributes                XSetWindowAttributes;
typedef struct XTextItem                           XTextItem;
typedef struct XTextItem16                         XTextItem16;
typedef struct XTimeCoord                          XTimeCoord;
typedef struct XUnmapEvent                         XUnmapEvent;
typedef void*                                      XVaNestedList;
typedef struct XVisibilityEvent                    XVisibilityEvent;
typedef struct XVisual                             XVisual;
typedef struct XwcTextItem                         XwcTextItem;
typedef struct XWindowAttributes                   XWindowAttributes;
typedef struct XWindowChanges                      XWindowChanges;

typedef void    (*XIMProc)(XIM,void*,void*);
typedef int32_t (*XICProc)(XIC,void*,void*);
typedef void    (*XIDProc)(XDisplay*,void*,void*);
typedef void    (*XConnectionWatchProc)(XDisplay*,void*,int32_t,int32_t,void**);
typedef int32_t (*XErrorHandler)(XDisplay*,XErrorEvent*);
typedef int32_t (*XIOErrorHandler)(XDisplay*);
typedef void    (*XIOErrorExitHandler)(XDisplay*,void*);

typedef enum XIMCaretDirection {
    XIMForwardChar,                                                       // ???
    XIMBackwardChar,                                                      // ???
    XIMForwardWord,                                                       // ???
    XIMBackwardWord,                                                      // ???
    XIMCaretUp,                                                           // ???
    XIMCaretDown,                                                         // ???
    XIMNextLine,                                                          // ???
    XIMPreviousLine,                                                      // ???
    XIMLineStart,                                                         // ???
    XIMLineEnd,                                                           // ???
    XIMAbsolutePosition,                                                  // ???
    XIMDontChange                                                         // ???
} XIMCaretDirection;

typedef enum XIMCaretStyle {
    XIMIsInvisible,                                                       // Disable caret feedback
    XIMIsPrimary,                                                         // UI defined caret feedback
    XIMIsSecondary                                                        // UI defined caret feedback
} XIMCaretStyle;

typedef enum XIMStatusDataType {
    XIMTextType,                                                          // ???
    XIMBitmapType                                                         // ???
} XIMStatusDataType;

typedef enum XOrientation {
    XOMOrientation_LTR_TTB,                                               // ???
    XOMOrientation_RTL_TTB,                                               // ???
    XOMOrientation_TTB_LTR,                                               // ???
    XOMOrientation_TTB_RTL,                                               // ???
    XOMOrientation_Context                                                // ???
} XOrientation;

typedef struct XExtData {
    int32_t                            number;                            // number returned by XRegisterExtension
    XExtData*                          next;                              // next item on list of data for structure
    int32_t                          (*free_private)(XExtData*);          // called to free private storage
    void*                              private_data;                      // data private to this extension
} XExtData;

typedef struct XExtCodes {
    int32_t                            extension;                         // extension number
    int32_t                            major_opcode;                      // major op-code assigned by server
    int32_t                            first_event;                       // first event number for the extension
    int32_t                            first_error;                       // first error number for the extension
} XExtCodes;

typedef struct XPixmapFormatValues {
    int32_t                            depth;                             // ???
    int32_t                            bits_per_pixel;                    // ???
    int32_t                            scanline_pad;                      // ???
} XPixmapFormatValues;

typedef struct XGCValues {
    int32_t                            function;                          // logical operation
    uint64_t                           plane_mask;                        // plane mask
    uint64_t                           foreground;                        // foreground pixel
    uint64_t                           background;                        // background pixel
    int32_t                            line_width;                        // line width
    int32_t                            line_style;                        // LineSolid, LineOnOffDash, LineDoubleDash
    int32_t                            cap_style;                         // CapNotLast, CapButt, CapRound, CapProjecting
    int32_t                            join_style;                        // JoinMiter, JoinRound, JoinBevel
    int32_t                            fill_style;                        // FillSolid, FillTiled, FillStippled, FillOpaqueStippled
    int32_t                            fill_rule;                         // EvenOddRule, WindingRule
    int32_t                            arc_mode;                          // ArcChord, ArcPieSlice
    XPixmap                            tile;                              // tile pixmap for tiling operations
    XPixmap                            stipple;                           // stipple 1 plane pixmap for stippling
    int32_t                            ts_x_origin;                       // offset for tile or stipple operations
    int32_t                            ts_y_origin;                       // ???
    XFont                              font;                              // default text font for text operations
    int32_t                            subwindow_mode;                    // ClipByChildren, IncludeInferiors
    int32_t                            graphics_exposures;                // boolean, should exposures be generated
    int32_t                            clip_x_origin;                     // origin for clipping
    int32_t                            clip_y_origin;                     // ???
    XPixmap                            clip_mask;                         // bitmap             clipping; other calls for rects
    int32_t                            dash_offset;                       // patterned/dashed line information
    char                               dashes;                            // ???
} XGCValues;

typedef struct _XGC {
    XExtData*                          ext_data;                          // hook for extension to hang data
    XGContext                          gid;                               // protocol ID for graphics context
}* XGC;

typedef struct XVisual {
    XExtData*                          ext_data;                          // hook for extension to hang data
    XVisualID                          visualid;                          // visual id of this visual
    int32_t                            c_class;                           // C++ class of screen (monochrome, etc.)
    uint64_t                           red_mask;                          // mask values
    uint64_t                           green_mask;                        // mask values
    uint64_t                           blue_mask;                         // mask values
    int32_t                            bits_per_rgb;                      // log base 2 of distinct color values
    int32_t                            map_entries;                       // color map entries
} XVisual;

typedef struct XDepth {
    int32_t                            depth;                             // this depth (Z) of the depth
    int32_t                            nvisuals;                          // number of XVisual types at this depth
    XVisual*                           visuals;                           // list of visuals possible at this depth
} XDepth;

typedef struct XScreen {
    XExtData*                          ext_data;                          // hook for extension to hang data
    XDisplay*                          display;                           // back pointer to display structure
    XWindow                            root;                              // Root window id
    int32_t                            width;                             // width of screen
    int32_t                            height;                            // height of screen
    int32_t                            mwidth;                            // width of screen in millimeters
    int32_t                            mheight;                           // height of screen in millimeters
    int32_t                            ndepths;                           // number of depths possible
    XDepth*                            depths;                            // list of allowable depths on the screen
    int32_t                            root_depth;                        // bits per pixel
    XVisual*                           root_visual;                       // root visual
    XGC                                default_gc;                        // GC for the root root visual
    XColormap                          cmap;                              // default color map
    uint64_t                           white_pixel;                       // ???
    uint64_t                           black_pixel;                       // White and Black pixel values
    int32_t                            max_maps;                          // max color maps
    int32_t                            min_maps;                          // min color maps
    int32_t                            backing_store;                     // Never, WhenMapped, Always
    int32_t                            save_unders;                       // ???
    int64_t                            root_input_mask;                   // initial root input mask
} XScreen;

typedef struct XScreenFormat {
    XExtData*                          ext_data;                          // hook for extension to hang data
    int32_t                            depth;                             // depth of this image format
    int32_t                            bits_per_pixel;                    // bits/pixel at this depth
    int32_t                            scanline_pad;                      // scanline must padded to this multiple
} XScreenFormat;

typedef struct XSetWindowAttributes {
    XPixmap                            background_pixmap;                 // background or None or ParentRelative
    uint64_t                           background_pixel;                  // background pixel
    XPixmap                            border_pixmap;                     // border of the window
    uint64_t                           border_pixel;                      // border pixel value
    int32_t                            bit_gravity;                       // one of bit gravity values
    int32_t                            win_gravity;                       // one of the window gravity values
    int32_t                            backing_store;                     // NotUseful, WhenMapped, Always
    uint64_t                           backing_planes;                    // planes to be preserved if possible
    uint64_t                           backing_pixel;                     // value to use in restoring planes
    int32_t                            save_under;                        // should bits under be saved? (popups)
    int64_t                            event_mask;                        // set of events that should be saved
    int64_t                            do_not_propagate_mask;             // set of events that should not propagate
    int32_t                            override_redirect;                 // boolean value for override-redirect
    XColormap                          colormap;                          // color map to be associated with window
    XCursor                            cursor;                            // cursor to be displayed (or None)
} XSetWindowAttributes;

typedef struct XWindowAttributes {
    int32_t                            x;                                 // location of window
    int32_t                            y;                                 // location of window
    int32_t                            width;                             // width of window
    int32_t                            height;                            // height of window
    int32_t                            border_width;                      // border width of window
    int32_t                            depth;                             // depth of window
    XVisual*                           visual;                            // the associated visual structure
    XWindow                            root;                              // root of screen containing window
    int32_t                            c_class;                           // C++ InputOutput, InputOnly
    int32_t                            bit_gravity;                       // one of bit gravity values
    int32_t                            win_gravity;                       // one of the window gravity values
    int32_t                            backing_store;                     // NotUseful, WhenMapped, Always
    uint64_t                           backing_planes;                    // planes to be preserved if possible
    uint64_t                           backing_pixel;                     // value to be used when restoring planes
    int32_t                            save_under;                        // boolean, should bits under be saved?
    XColormap                          colormap;                          // color map to be associated with window
    int32_t                            map_installed;                     // boolean, is color map currently installed
    int32_t                            map_state;                         // IsUnmapped, IsUnviewable, IsViewable
    int64_t                            all_event_masks;                   // set of events all people have interest in
    int64_t                            your_event_mask;                   // my event mask
    int64_t                            do_not_propagate_mask;             // set of events that should not propagate
    int32_t                            override_redirect;                 // boolean value for override-redirect
    XScreen*                           screen;                            // back pointer to correct screen
} XWindowAttributes;

typedef struct XHostAddress {
    int32_t                            family;                            // for example FamilyInternet
    int32_t                            length;                            // length of address, in bytes
    char*                              address;                           // pointer to where to find the bytes
} XHostAddress;

typedef struct XServerInterpretedAddress {
    int32_t                            typelength;                        // length of type string, in bytes
    int32_t                            valuelength;                       // length of value string, in bytes
    char*                              type;                              // pointer to where to find the type string
    char*                              value;                             // pointer to where to find the address
} XServerInterpretedAddress;

typedef struct XImage {
    int32_t                            width;                             // size of image
    int32_t                            height;                            // size of image
    int32_t                            xoffset;                           // number of pixels offset in X direction
    int32_t                            format;                            // XYBitmap, XYPixmap, ZPixmap
    char*                              data;                              // pointer to image data
    int32_t                            byte_order;                        // data byte order, LSBFirst, MSBFirst
    int32_t                            bitmap_unit;                       // quant. of scanline 8, 16, 32
    int32_t                            bitmap_bit_order;                  // LSBFirst, MSBFirst
    int32_t                            bitmap_pad;                        // 8, 16, 32 either XY or ZPixmap
    int32_t                            depth;                             // depth of image
    int32_t                            bytes_per_line;                    // accelerator to next line
    int32_t                            bits_per_pixel;                    // bits per pixel (ZPixmap)
    uint64_t                           red_mask;                          // bits in z arrangement
    uint64_t                           green_mask;                        // bits in z arrangement
    uint64_t                           blue_mask;                         // bits in z arrangement
    void*                              obdata;                            // hook for the object routines to hang on
    struct funcs {
        XImage*                      (*create_image)(XDisplay*,XVisual*,uint32_t,int32_t,int32_t,char*,uint32_t,uint32_t,int32_t,int32_t);
        int32_t                      (*destroy_image)(XImage*);
        uint64_t                     (*get_pixel)(XImage*,int32_t,int32_t);
        int32_t                      (*put_pixel)(XImage*,int32_t,int32_t,uint64_t);
        XImage*                      (*sub_image)(XImage*,int32_t,int32_t,uint32_t,uint32_t);
        int32_t                      (*add_pixel)(XImage*,int64_t);
    }                                  f;                                 // image manipulation routines
} XImage;

typedef struct XWindowChanges {
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
    int32_t                            width;                             // ???
    int32_t                            height;                            // ???
    int32_t                            border_width;                      // ???
    XWindow                            sibling;                           // ???
    int32_t                            stack_mode;                        // ???
} XWindowChanges;

typedef struct XColor {
    uint64_t                           pixel;                             // ???
    uint16_t                           red;                               // ???
    uint16_t                           green;                             // ???
    uint16_t                           blue;                              // ???
    char                               flags;                             // do_red, do_green, do_blue
    char                               pad;                               // ???
} XColor;

typedef struct XSegment {
    int16_t                            x1;                                // ???
    int16_t                            y1;                                // ???
    int16_t                            x2;                                // ???
    int16_t                            y2;                                // ???
} XSegment;

typedef struct XPoint {
    int16_t                            x;                                 // ???
    int16_t                            y;                                 // ???
} XPoint;

typedef struct XRectangle {
    int16_t                            x;                                 // ???
    int16_t                            y;                                 // ???
    uint16_t                           width;                             // ???
    uint16_t                           height;                            // ???
} XRectangle;

typedef struct XArc {
    int16_t                            x;                                 // ???
    int16_t                            y;                                 // ???
    uint16_t                           width;                             // ???
    uint16_t                           height;                            // ???
    int16_t                            angle1;                            // ???
    int16_t                            angle2;                            // ???
} XArc;

typedef struct XKeyboardControl {
    int32_t                            key_click_percent;                 // ???
    int32_t                            bell_percent;                      // ???
    int32_t                            bell_pitch;                        // ???
    int32_t                            bell_duration;                     // ???
    int32_t                            led;                               // ???
    int32_t                            led_mode;                          // ???
    int32_t                            key;                               // ???
    int32_t                            auto_repeat_mode;                  // On, Off, Default
} XKeyboardControl;

typedef struct XKeyboardState {
    int32_t                            key_click_percent;                 // ???
    int32_t                            bell_percent;                      // ???
    uint32_t                           bell_pitch;                        // ???
    uint32_t                           bell_duration;                     // ???
    uint64_t                           led_mask;                          // ???
    int32_t                            global_auto_repeat;                // ???
    char                               auto_repeats[32];                  // ???
} XKeyboardState;

typedef struct XTimeCoord {
    XTime                              time;                              // ???
    int16_t                            x;                                 // ???
    int16_t                            y;                                 // ???
} XTimeCoord;

typedef struct XModifierKeymap {
    int32_t                            max_keypermod;                     // The server's max # of keys per modifier
    XKeyCode*                          modifiermap;                       // An 8 by max_keypermod array of modifiers
} XModifierKeymap;

typedef struct XDisplay {
    XExtData*                          ext_data;                          // hook for extension to hang data
    XPrivate*                          private1;                          // ???
    int32_t                            fd;                                // Network socket
    int32_t                            private2;                          // ???
    int32_t                            proto_major_version;               // major version of server's X protocol
    int32_t                            proto_minor_version;               // minor version of servers X protocol
    char*                              vendor;                            // vendor of the server hardware
    XID                                private3;                          // ???
    XID                                private4;                          // ???
    XID                                private5;                          // ???
    int32_t                            private6;                          // ???
    XID                              (*resource_alloc)(XDisplay*);        // allocator function
    int32_t                            byte_order;                        // screen byte order, LSBFirst, MSBFirst */
    int32_t                            bitmap_unit;                       // padding and data requirements */
    int32_t                            bitmap_pad;                        // padding requirements on bitmaps */
    int32_t                            bitmap_bit_order;                  // LeastSignificant or MostSignificant */
    int32_t                            nformats;                          // number of pixmap formats in list */
    XScreenFormat*                     pixmap_format;                     // pixmap format list
    int32_t                            private8;                          // ???
    int32_t                            release;                           // release of the server
    XPrivate*                          private9;                          // ???
    XPrivate*                          private10;                         // ???
    int32_t                            qlen;                              // Length of input event queue
    uint64_t                           last_request_read;                 // seq number of last event read
    uint64_t                           request;                           // sequence number of last request
    void*                              private11;                         // ???
    void*                              private12;                         // ???
    void*                              private13;                         // ???
    void*                              private14;                         // ???
    uint32_t                           max_request_size;                  // maximum number 32 bit words in request
    XrmHashBucketRec*                  db;                                // ???
    int32_t                          (*private15)(XDisplay*);             // ???
    char*                              display_name;                      // "host:display" string used on this connect
    int32_t                            default_screen;                    // default screen for operations
    int32_t                            nscreens;                          // number of screens on this server
    XScreen*                           screens;                           // pointer to list of screens
    uint64_t                           motion_buffer;                     // size of motion buffer
    uint64_t                           private16;                         // ???
    int32_t                            min_keycode;                       // minimum defined keycode
    int32_t                            max_keycode;                       // maximum defined keycode
    void*                              private17;                         // ???
    void*                              private18;                         // ???
    int32_t                            private19;                         // ???
    char*                              xdefaults;                         // contents of defaults from server
} XDisplay;

typedef struct XKeyEvent {
    int32_t                            type;                              // of event
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // "event" window it is reported relative to
    XWindow                            root;                              // root window that the event occurred on
    XWindow                            subwindow;                         // child window
    XTime                              time;                              // milliseconds
    int32_t                            x;                                 // pointer x coordinates in event window
    int32_t                            y;                                 // pointer y coordinates in event window
    int32_t                            x_root;                            // coordinates relative to root
    int32_t                            y_root;                            // coordinates relative to root
    uint32_t                           state;                             // key or button mask
    uint32_t                           keycode;                           // detail
    int32_t                            same_screen;                       // same screen flag
} XKeyEvent;

typedef struct XButtonEvent {
    int32_t                            type;                              // of event
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // "event" window it is reported relative to
    XWindow                            root;                              // root window that the event occurred on
    XWindow                            subwindow;                         // child window
    XTime                              time;                              // milliseconds
    int32_t                            x;                                 // pointer x coordinates in event window
    int32_t                            y;                                 // pointer y coordinates in event window
    int32_t                            x_root;                            // coordinates relative to root
    int32_t                            y_root;                            // coordinates relative to root
    uint32_t                           state;                             // key or button mask
    uint32_t                           button;                            // detail
    int32_t                            same_screen;                       // same screen flag
} XButtonEvent;

typedef struct XMotionEvent {
    int32_t                            type;                              // of event
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // "event" window reported relative to
    XWindow                            root;                              // root window that the event occurred on
    XWindow                            subwindow;                         // child window
    XTime                              time;                              // milliseconds
    int32_t                            x;                                 // pointer x coordinates in event window
    int32_t                            y;                                 // pointer y coordinates in event window
    int32_t                            x_root;                            // coordinates relative to root
    int32_t                            y_root;                            // coordinates relative to root
    uint32_t                           state;                             // key or button mask
    char                               is_hint;                           // detail
    int32_t                            same_screen;                       // same screen flag
} XMotionEvent;

typedef struct XCrossingEvent {
    int32_t                            type;                              // of event
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // "event" window reported relative to
    XWindow                            root;                              // root window that the event occurred on
    XWindow                            subwindow;                         // child window
    XTime                              time;                              // milliseconds
    int32_t                            x;                                 // pointer x coordinates in event window
    int32_t                            y;                                 // pointer y coordinates in event window
    int32_t                            x_root;                            // coordinates relative to root
    int32_t                            y_root;                            // coordinates relative to root
    int32_t                            mode;                              // NotifyNormal, NotifyGrab, NotifyUngrab
    int32_t                            detail;                            // ???
    int32_t                            same_screen;                       // same screen flag
    int32_t                            focus;                             // boolean focus
    uint32_t                           state;                             // key or button mask
} XCrossingEvent;

typedef struct XFocusChangeEvent {
    int32_t                            type;                              // FocusIn or FocusOut
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // window of event
    int32_t                            mode;                              // NotifyNormal, NotifyWhileGrabbed, NotifyGrab, NotifyUngrab
    int32_t                            detail;                            // ???
} XFocusChangeEvent;

typedef struct XKeymapEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    char                               key_vector[32];                    // ???
} XKeymapEvent;

typedef struct XExposeEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
    int32_t                            width;                             // ???
    int32_t                            height;                            // ???
    int32_t                            count;                             // if non-zero, at least this many more
} XExposeEvent;

typedef struct XGraphicsExposeEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XDrawable                          drawable;                          // ???
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
    int32_t                            width;                             // ???
    int32_t                            height;                            // ???
    int32_t                            count;                             // if non-zero, at least this many more
    int32_t                            major_code;                        // core is CopyArea or CopyPlane
    int32_t                            minor_code;                        // not defined in the core
} XGraphicsExposeEvent;

typedef struct XNoExposeEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XDrawable                          drawable;                          // ???
    int32_t                            major_code;                        // core is CopyArea or CopyPlane
    int32_t                            minor_code;                        // not defined in the core
} XNoExposeEvent;

typedef struct XVisibilityEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    int32_t                            state;                             // Visibility state
} XVisibilityEvent;

typedef struct XCreateWindowEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            parent;                            // parent of the window
    XWindow                            window;                            // window id of window created
    int32_t                            x;                                 // window location
    int32_t                            y;                                 // window location
    int32_t                            width;                             // size of window
    int32_t                            height;                            // size of window
    int32_t                            border_width;                      // border width
    int32_t                            override_redirect;                 // creation should be overridden
} XCreateWindowEvent;

typedef struct XDestroyWindowEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
} XDestroyWindowEvent;

typedef struct XUnmapEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
    int32_t                            from_configure;                    // ???
} XUnmapEvent;

typedef struct XMapEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
    int32_t                            override_redirect;                 // boolean, is override set...
} XMapEvent;

typedef struct XMapRequestEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            parent;                            // ???
    XWindow                            window;                            // ???
} XMapRequestEvent;

typedef struct XReparentEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
    XWindow                            parent;                            // ???
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
    int32_t                            override_redirect;                 // ???
} XReparentEvent;

typedef struct XConfigureEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
    int32_t                            width;                             // ???
    int32_t                            height;                            // ???
    int32_t                            border_width;                      // ???
    XWindow                            above;                             // ???
    int32_t                            override_redirect;                 // ???
} XConfigureEvent;

typedef struct XGravityEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
} XGravityEvent;

typedef struct XResizeRequestEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    int32_t                            width;                             // ???
    int32_t                            height;                            // ???
} XResizeRequestEvent;

typedef struct XConfigureRequestEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            parent;                            // ???
    XWindow                            window;                            // ???
    int32_t                            x;                                 // ???
    int32_t                            y;                                 // ???
    int32_t                            width;                             // ???
    int32_t                            height;                            // ???
    int32_t                            border_width;                      // ???
    XWindow                            above;                             // ???
    int32_t                            detail;                            // Above, Below, TopIf, BottomIf, Opposite
    uint64_t                           value_mask;                        // ???
} XConfigureRequestEvent;

typedef struct XCirculateEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            event;                             // ???
    XWindow                            window;                            // ???
    int32_t                            place;                             // PlaceOnTop, PlaceOnBottom
} XCirculateEvent;

typedef struct XCirculateRequestEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            parent;                            // ???
    XWindow                            window;                            // ???
    int32_t                            place;                             // PlaceOnTop, PlaceOnBottom
} XCirculateRequestEvent;

typedef struct XPropertyEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    XAtom                              atom;                              // ???
    XTime                              time;                              // ???
    int32_t                            state;                             // NewValue, Deleted
} XPropertyEvent;

typedef struct XSelectionClearEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    XAtom                              selection;                         // ???
    XTime                              time;                              // ???
} XSelectionClearEvent;

typedef struct XSelectionRequestEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            owner;                             // ???
    XWindow                            requestor;                         // ???
    XAtom                              selection;                         // ???
    XAtom                              target;                            // ???
    XAtom                              property;                          // ???
    XTime                              time;                              // ???
} XSelectionRequestEvent;

typedef struct XSelectionEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            requestor;                         // ???
    XAtom                              selection;                         // ???
    XAtom                              target;                            // ???
    XAtom                              property;                          // ATOM or None
    XTime                              time;                              // ???
} XSelectionEvent;

typedef struct XColormapEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    XColormap                          colormap;                          // COLORMAP or None
    int32_t                            c_new;                             // C++
    int32_t                            state;                             // ColormapInstalled, ColormapUninstalled
} XColormapEvent;

typedef struct XClientMessageEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // ???
    XAtom                              message_type;                      // ???
    int32_t                            format;                            // ???
    union {
        char                           b[20];                             // ???
        int16_t                        s[10];                             // ???
        int64_t                        l[5];                              // ???
    }                                  data;                              // ???
} XClientMessageEvent;

typedef struct XMappingEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // unused
    int32_t                            request;                           // one of MappingModifier, MappingKeyboard, MappingPointer
    int32_t                            first_keycode;                     // first keycode
    int32_t                            count;                             // defines range of change w. first_keycode
} XMappingEvent;

typedef struct XErrorEvent {
    int32_t                            type;                              // ???
    XDisplay*                          display;                           // XDisplay the event was read from
    XID                                resourceid;                        // resource id
    uint64_t                           serial;                            // serial number of failed request
    uint8_t                            error_code;                        // error code of failed request
    uint8_t                            request_code;                      // Major op-code of failed request
    uint8_t                            minor_code;                        // Minor op-code of failed request
} XErrorEvent;

typedef struct XAnyEvent {
    int32_t                            type;                              // ???
    uint64_t                           serial;                            // # of last request processed by server
    int32_t                            send_event;                        // true if this came from a SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    XWindow                            window;                            // window on which event was requested in event mask
} XAnyEvent;

typedef struct XGenericEvent {
    int32_t                            type;                              // of event. Always GenericEvent
    uint64_t                           serial;                            // # of last request processed
    int32_t                            send_event;                        // true if from SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    int32_t                            extension;                         // major opcode of extension that caused the event
    int32_t                            evtype;                            // actual event type
} XGenericEvent;

typedef struct XGenericEventCookie {
    int32_t                            type;                              // of event. Always GenericEvent
    uint64_t                           serial;                            // # of last request processed
    int32_t                            send_event;                        // true if from SendEvent request
    XDisplay*                          display;                           // XDisplay the event was read from
    int32_t                            extension;                         // major opcode of extension that caused the event
    int32_t                            evtype;                            // actual event type
    uint32_t                           cookie;                            // ???
    void*                              data;                              // ???
} XGenericEventCookie;

typedef union XEvent {
    int32_t                            type;                              // must not be             changed; first element
    XAnyEvent                          xany;                              // ???
    XKeyEvent                          xkey;                              // ???
    XButtonEvent                       xbutton;                           // ???
    XMotionEvent                       xmotion;                           // ???
    XCrossingEvent                     xcrossing;                         // ???
    XFocusChangeEvent                  xfocus;                            // ???
    XExposeEvent                       xexpose;                           // ???
    XGraphicsExposeEvent               xgraphicsexpose;                   // ???
    XNoExposeEvent                     xnoexpose;                         // ???
    XVisibilityEvent                   xvisibility;                       // ???
    XCreateWindowEvent                 xcreatewindow;                     // ???
    XDestroyWindowEvent                xdestroywindow;                    // ???
    XUnmapEvent                        xunmap;                            // ???
    XMapEvent                          xmap;                              // ???
    XMapRequestEvent                   xmaprequest;                       // ???
    XReparentEvent                     xreparent;                         // ???
    XConfigureEvent                    xconfigure;                        // ???
    XGravityEvent                      xgravity;                          // ???
    XResizeRequestEvent                xresizerequest;                    // ???
    XConfigureRequestEvent             xconfigurerequest;                 // ???
    XCirculateEvent                    xcirculate;                        // ???
    XCirculateRequestEvent             xcirculaterequest;                 // ???
    XPropertyEvent                     xproperty;                         // ???
    XSelectionClearEvent               xselectionclear;                   // ???
    XSelectionRequestEvent             xselectionrequest;                 // ???
    XSelectionEvent                    xselection;                        // ???
    XColormapEvent                     xcolormap;                         // ???
    XClientMessageEvent                xclient;                           // ???
    XMappingEvent                      xmapping;                          // ???
    XErrorEvent                        xerror;                            // ???
    XKeymapEvent                       xkeymap;                           // ???
    XGenericEvent                      xgeneric;                          // ???
    XGenericEventCookie                xcookie;                           // ???
    int64_t                            pad[24];                           // ???
} XEvent;

typedef struct XCharStruct {
    int16_t                            lbearing;                          // origin to left edge of raster
    int16_t                            rbearing;                          // origin to right edge of raster
    int16_t                            width;                             // advance to next char's origin
    int16_t                            ascent;                            // baseline to top edge of raster
    int16_t                            descent;                           // baseline to bottom edge of raster
    uint16_t                           attributes;                        // per char flags (not predefined)
} XCharStruct;

typedef struct XFontProp {
    XAtom                              name;                              // ???
    uint64_t                           card32;                            // ???
} XFontProp;

typedef struct XFontStruct {
    XExtData*                          ext_data;                          // hook for extension to hang data
    XFont                              fid;                               // XFont id for this font
    uint32_t                           direction;                         // hint about direction the font is painted
    uint32_t                           min_char_or_byte2;                 // first character
    uint32_t                           max_char_or_byte2;                 // last character
    uint32_t                           min_byte1;                         // first row that exists
    uint32_t                           max_byte1;                         // last row that exists
    int32_t                            all_chars_exist;                   // flag if all characters have non-zero size
    uint32_t                           default_char;                      // char to print for undefined character
    int32_t                            n_properties;                      // how many properties there are
    XFontProp*                         properties;                        // pointer to array of additional properties
    XCharStruct                        min_bounds;                        // minimum bounds over all existing char
    XCharStruct                        max_bounds;                        // maximum bounds over all existing char
    XCharStruct*                       per_char;                          // first_char to last_char information
    int32_t                            ascent;                            // log. extent above baseline for spacing
    int32_t                            descent;                           // log. descent below baseline for spacing
} XFontStruct;

typedef struct XTextItem {
    char*                              chars;                             // pointer to string
    int32_t                            nchars;                            // number of characters
    int32_t                            delta;                             // delta between strings
    XFont                              font;                              // font to print it in, None don't change
} XTextItem;

typedef struct XChar2b {
    uint8_t                            byte1;                             // ???
    uint8_t                            byte2;                             // ???
} XChar2b;

typedef struct XTextItem16 {
    XChar2b*                           chars;                             // two byte characters
    int32_t                            nchars;                            // number of characters
    int32_t                            delta;                             // delta between strings
    XFont                              font;                              // font to print it in, None don't change
} XTextItem16;

typedef union XEDataObject {
    XDisplay*                          display;                           // ???
    XGC                                gc;                                // ???
    XVisual*                           visual;                            // ???
    XScreen*                           screen;                            // ???
    XScreenFormat*                     pixmap_format;                     // ???
    XFontStruct*                       font;                              // ???
} XEDataObject;

typedef struct XFontSetExtents {
    XRectangle                         max_ink_extent;                    // ???
    XRectangle                         max_logical_extent;                // ???
} XFontSetExtents;

typedef struct XmbTextItem {
    char*                              chars;                             // ???
    int32_t                            nchars;                            // ???
    int32_t                            delta;                             // ???
    XFontSet                           font_set;                          // ???
} XmbTextItem;

typedef struct XwcTextItem {
    wchar_t*                           chars;                             // ???
    int32_t                            nchars;                            // ???
    int32_t                            delta;                             // ???
    XFontSet                           font_set;                          // ???
} XwcTextItem;

typedef struct XOMCharSetList {
    int32_t                            charset_count;                     // ???
    char**                             charset_list;                      // ???
} XOMCharSetList;

typedef struct XOMOrientation {
    int32_t                            num_orientation;                   // ???
    XOrientation*                      orientation;                       // Input Text description
} XOMOrientation;

typedef struct XOMFontInfo {
    int32_t                            num_font;                          // ???
    XFontStruct**                      font_struct_list;                  // ???
    char**                             font_name_list;                    // ???
} XOMFontInfo;

typedef struct XIMStyles {
    uint16_t                           count_styles;                      // ???
    XIMStyle*                          supported_styles;                  // ???
} XIMStyles;


typedef struct XIMCallback {
    void*                              client_data;                       // ???
    XIMProc                            callback;                          // ???
} XIMCallback;

typedef struct XICCallback{
    void*                              client_data;                       // ???
    XICProc                            callback;                          // ???
} XICCallback;

typedef struct XIMText {
    uint16_t                           length;                            // ???
    XIMFeedback*                       feedback;                          // ???
    int32_t                            encoding_is_wchar;                 // ???
    union {
        char*                          multi_byte;                        // ???
        wchar_t*                       wide_char;                         // ???
    }                                  string;                            // ???
} XIMText;

typedef struct XIMPreeditStateNotifyCallbackStruct {
    XIMPreeditState                    state;                             // ???
} XIMPreeditStateNotifyCallbackStruct;

typedef struct _XIMStringConversionText {
    uint16_t                           length;                            // ???
    XIMStringConversionFeedback*       feedback;                          // ???
    int32_t                            encoding_is_wchar;                 // ???
    union {
        char*                          mbs;                               // ???
        wchar_t*                       wcs;                               // ???
    }                                  string;                            // ???
} XIMStringConversionText;

typedef struct XIMStringConversionCallbackStruct {
    XIMStringConversionPosition        position;                          // ???
    XIMCaretDirection                  direction;                         // ???
    XIMStringConversionOperation       operation;                         // ???
    uint16_t                           factor;                            // ???
    XIMStringConversionText*           text;                              // ???
} XIMStringConversionCallbackStruct;

typedef struct XIMPreeditDrawCallbackStruct {
    int32_t                            caret;                             // XCursor offset within pre-edit string
    int32_t                            chg_first;                         // Starting change position
    int32_t                            chg_length;                        // Length of the change in character count
    XIMText*                           text;                              // ???
} XIMPreeditDrawCallbackStruct;

typedef struct XIMPreeditCaretCallbackStruct {
    int32_t                            position;                          // Caret offset within pre-edit string
    XIMCaretDirection                  direction;                         // Caret moves direction
    XIMCaretStyle                      style;                             // Feedback of the caret
} XIMPreeditCaretCallbackStruct;

typedef struct XIMStatusDrawCallbackStruct {
    XIMStatusDataType                  type;                              // ???
    union {
        XIMText*                       text;                              // ???
        XPixmap                        bitmap;                            // ???
    }                                  data;                              // ???
} XIMStatusDrawCallbackStruct;

typedef struct XIMHotKeyTrigger {
    XKeySym                            keysym;                            // ???
    int32_t                            modifier;                          // ???
    int32_t                            modifier_mask;                     // ???
} XIMHotKeyTrigger;

typedef struct XIMHotKeyTriggers {
    int32_t                            num_hot_key;                       // ???
    XIMHotKeyTrigger*                  key;                               // ???
} XIMHotKeyTriggers;

typedef struct XIMValuesList {
    uint16_t                           count_values;                      // ???
    char**                             supported_values;                  // ???
} XIMValuesList;

int32_t              _Xmblen(char*,int32_t);
int32_t              _Xmbtowc(wchar_t*,char*,int32_t);
int32_t              _Xwctomb(char*,wchar_t);
int32_t              XActivateScreenSaver(XDisplay*);
int32_t              XAddConnectionWatch(XDisplay*,XConnectionWatchProc,void*);
XExtCodes*           XAddExtension(XDisplay*);
int32_t              XAddHost(XDisplay*,XHostAddress*);
int32_t              XAddHosts(XDisplay*,XHostAddress*,int32_t);
int32_t              XAddToExtensionList(XExtData**,XExtData*);
int32_t              XAddToSaveSet(XDisplay*,XWindow);
int32_t              XAllocColor(XDisplay*,XColormap,XColor*);
int32_t              XAllocColorCells(XDisplay*,XColormap,int32_t,uint64_t*,uint32_t,uint64_t*,uint32_t);
int32_t              XAllocColorPlanes(XDisplay*,XColormap,int32_t,uint64_t*,int32_t,int32_t,int32_t,int32_t,uint64_t*,uint64_t*,uint64_t*);
int32_t              XAllocNamedColor(XDisplay*,XColormap,const char*,XColor*,XColor*);
int32_t              XAllowEvents(XDisplay*,int32_t,XTime);
uint64_t             XAllPlanes(void);
int32_t              XAutoRepeatOff(XDisplay*);
int32_t              XAutoRepeatOn(XDisplay*);
char*                XBaseFontNameListOfFontSet(XFontSet);
int32_t              XBell(XDisplay*,int32_t);
int32_t              XBitmapBitOrder(XDisplay*);
int32_t              XBitmapPad(XDisplay*);
int32_t              XBitmapUnit(XDisplay*);
uint64_t             XBlackPixel(XDisplay*,int32_t);
uint64_t             XBlackPixelOfScreen(XScreen*);
int32_t              XCellsOfScreen(XScreen*);
int32_t              XChangeActivePointerGrab(XDisplay*,uint32_t,XCursor,XTime);
int32_t              XChangeGC(XDisplay*,XGC,uint64_t,XGCValues*);
int32_t              XChangeKeyboardControl(XDisplay*,uint64_t,XKeyboardControl*);
int32_t              XChangeKeyboardMapping(XDisplay*,int32_t,int32_t,XKeySym*,int32_t);
int32_t              XChangePointerControl(XDisplay*,int32_t,int32_t,int32_t,int32_t,int32_t);
int32_t              XChangeProperty(XDisplay*,XWindow,XAtom,XAtom,int32_t,int32_t,const uint8_t*,int32_t);
int32_t              XChangeSaveSet(XDisplay*,XWindow,int32_t);
int32_t              XChangeWindowAttributes(XDisplay*,XWindow,uint64_t,XSetWindowAttributes*);
int32_t              XCheckIfEvent(XDisplay*,XEvent*,int32_t(*)(XDisplay*,XEvent*,void*),void*);
int32_t              XCheckMaskEvent(XDisplay*,int64_t,XEvent*);
int32_t              XCheckTypedEvent(XDisplay*,int32_t,XEvent*);
int32_t              XCheckTypedWindowEvent(XDisplay*,XWindow,int32_t,XEvent*);
int32_t              XCheckWindowEvent(XDisplay*,XWindow,int64_t,XEvent*);
int32_t              XCirculateSubwindows(XDisplay*,XWindow,int32_t);
int32_t              XCirculateSubwindowsDown(XDisplay*,XWindow);
int32_t              XCirculateSubwindowsUp(XDisplay*,XWindow);
int32_t              XClearArea(XDisplay*,XWindow,int32_t,int32_t,uint32_t,uint32_t,int32_t);
int32_t              XClearWindow(XDisplay*,XWindow);
int32_t              XCloseDisplay(XDisplay*);
int32_t              XCloseIM(XIM);
int32_t              XCloseOM(XOM);
int32_t              XConfigureWindow(XDisplay*,XWindow,uint32_t,XWindowChanges*);
int32_t              XConnectionNumber(XDisplay*);
int32_t              XContextDependentDrawing(XFontSet);
int32_t              XContextualDrawing(XFontSet);
int32_t              XConvertSelection(XDisplay*,XAtom,XAtom,XAtom,XWindow,XTime);
int32_t              XCopyArea(XDisplay*,XDrawable,XDrawable,XGC,int32_t,int32_t,uint32_t,uint32_t,int32_t,int32_t);
XColormap            XCopyColormapAndFree(XDisplay*,XColormap);
int32_t              XCopyGC(XDisplay*,XGC,uint64_t,XGC);
int32_t              XCopyPlane(XDisplay*,XDrawable,XDrawable,XGC,int32_t,int32_t,uint32_t,uint32_t,int32_t,int32_t,uint64_t);
XPixmap              XCreateBitmapFromData(XDisplay*,XDrawable,const char*,uint32_t,uint32_t);
XColormap            XCreateColormap(XDisplay*,XWindow,XVisual*,int32_t);
XCursor              XCreateFontCursor(XDisplay*,uint32_t);
XFontSet             XCreateFontSet(XDisplay*,const char*,char***,int32_t*,char**);
XGC                  XCreateGC(XDisplay*,XDrawable,uint64_t,XGCValues*);
XCursor              XCreateGlyphCursor(XDisplay*,XFont,XFont,uint32_t,uint32_t,XColor const*,XColor const*);
XIC                  XCreateIC(XIM,...);
XImage*              XCreateImage(XDisplay*,XVisual*,uint32_t,int32_t,int32_t,char*,uint32_t,uint32_t,int32_t,int32_t);
XOC                  XCreateOC(XOM,...);
XPixmap              XCreatePixmap(XDisplay*,XDrawable,uint32_t,uint32_t,uint32_t);
XCursor              XCreatePixmapCursor(XDisplay*,XPixmap,XPixmap,XColor*,XColor*,uint32_t,uint32_t);
XPixmap              XCreatePixmapFromBitmapData(XDisplay*,XDrawable,char*,uint32_t,uint32_t,uint64_t,uint64_t,uint32_t);
XWindow              XCreateSimpleWindow(XDisplay*,XWindow,int32_t,int32_t,uint32_t,uint32_t,uint32_t,uint64_t,uint64_t);
XWindow              XCreateWindow(XDisplay*,XWindow,int32_t,int32_t,uint32_t,uint32_t,uint32_t,int32_t,uint32_t,XVisual*,uint64_t,XSetWindowAttributes*);
XColormap            XDefaultColormap(XDisplay*,int32_t);
XColormap            XDefaultColormapOfScreen(XScreen*);
int32_t              XDefaultDepth(XDisplay*,int32_t);
int32_t              XDefaultDepthOfScreen(XScreen*);
XGC                  XDefaultGC(XDisplay*,int32_t);
XGC                  XDefaultGCOfScreen(XScreen*);
XWindow              XDefaultRootWindow(XDisplay*);
int32_t              XDefaultScreen(XDisplay*);
XScreen*             XDefaultScreenOfDisplay(XDisplay*);
XVisual*             XDefaultVisual(XDisplay*,int32_t);
XVisual*             XDefaultVisualOfScreen(XScreen*);
int32_t              XDefineCursor(XDisplay*,XWindow,XCursor);
XModifierKeymap*     XDeleteModifiermapEntry(XModifierKeymap*,XKeyCode,int32_t);
int32_t              XDeleteProperty(XDisplay*,XWindow,XAtom);
void                 XDestroyIC(XIC);
void                 XDestroyOC(XOC);
int32_t              XDestroySubwindows(XDisplay*,XWindow);
int32_t              XDestroyWindow(XDisplay*,XWindow);
int32_t              XDirectionalDependentDrawing(XFontSet);
int32_t              XDisableAccessControl(XDisplay*);
int32_t              XDisplayCells(XDisplay*,int32_t);
int32_t              XDisplayHeight(XDisplay*,int32_t);
int32_t              XDisplayHeightMM(XDisplay*,int32_t);
int32_t              XDisplayKeycodes(XDisplay*,int32_t*,int32_t*);
uint64_t             XDisplayMotionBufferSize(XDisplay*);
char*                XDisplayName(const char*);
XDisplay*            XDisplayOfIM(XIM);
XDisplay*            XDisplayOfOM(XOM);
XDisplay*            XDisplayOfScreen(XScreen*);
int32_t              XDisplayPlanes(XDisplay*,int32_t);
char*                XDisplayString(XDisplay*);
int32_t              XDisplayWidth(XDisplay*,int32_t);
int32_t              XDisplayWidthMM(XDisplay*,int32_t);
int32_t              XDoesBackingStore(XScreen*);
int32_t              XDoesSaveUnders(XScreen*);
int32_t              XDrawArc(XDisplay*,XDrawable,XGC,int32_t,int32_t,uint32_t,uint32_t,int32_t,int32_t);
int32_t              XDrawArcs(XDisplay*,XDrawable,XGC,XArc*,int32_t);
int32_t              XDrawImageString(XDisplay*,XDrawable,XGC,int32_t,int32_t,const char*,int32_t);
int32_t              XDrawImageString16(XDisplay*,XDrawable,XGC,int32_t,int32_t,const XChar2b*,int32_t);
int32_t              XDrawLine(XDisplay*,XDrawable,XGC,int32_t,int32_t,int32_t,int32_t);
int32_t              XDrawLines(XDisplay*,XDrawable,XGC,XPoint*,int32_t,int32_t);
int32_t              XDrawPoint(XDisplay*,XDrawable,XGC,int32_t,int32_t);
int32_t              XDrawPoints(XDisplay*,XDrawable,XGC,XPoint*,int32_t,int32_t);
int32_t              XDrawRectangle(XDisplay*,XDrawable,XGC,int32_t,int32_t,uint32_t,uint32_t);
int32_t              XDrawRectangles(XDisplay*,XDrawable,XGC,XRectangle*,int32_t);
int32_t              XDrawSegments(XDisplay*,XDrawable,XGC,XSegment*,int32_t);
int32_t              XDrawString(XDisplay*,XDrawable,XGC,int32_t,int32_t,const char*,int32_t);
int32_t              XDrawString16(XDisplay*,XDrawable,XGC,int32_t,int32_t,const XChar2b*,int32_t);
int32_t              XDrawText(XDisplay*,XDrawable,XGC,int32_t,int32_t,XTextItem*,int32_t);
int32_t              XDrawText16(XDisplay*,XDrawable,XGC,int32_t,int32_t,XTextItem16*,int32_t);
XExtData**           XEHeadOfExtensionList(XEDataObject);
int32_t              XEnableAccessControl(XDisplay*);
int64_t              XEventMaskOfScreen(XScreen*);
int32_t              XEventsQueued(XDisplay*,int32_t);
int64_t              XExtendedMaxRequestSize(XDisplay*);
XFontSetExtents*     XExtentsOfFontSet(XFontSet);
char*                XFetchBuffer(XDisplay*,int32_t*,int32_t);
char*                XFetchBytes(XDisplay*,int32_t*);
int32_t              XFetchName(XDisplay*,XWindow,char**);
int32_t              XFillArc(XDisplay*,XDrawable,XGC,int32_t,int32_t,uint32_t,uint32_t,int32_t,int32_t);
int32_t              XFillArcs(XDisplay*,XDrawable,XGC,XArc*,int32_t);
int32_t              XFillPolygon(XDisplay*,XDrawable,XGC,XPoint*,int32_t,int32_t,int32_t);
int32_t              XFillRectangle(XDisplay*,XDrawable,XGC,int32_t,int32_t,uint32_t,uint32_t);
int32_t              XFillRectangles(XDisplay*,XDrawable,XGC,XRectangle*,int32_t);
int32_t              XFilterEvent(XEvent*,XWindow);
XExtData*            XFindOnExtensionList(XExtData**,int32_t);
int32_t              XFlush(XDisplay*);
void                 XFlushGC(XDisplay*,XGC);
int32_t              XFontsOfFontSet(XFontSet,XFontStruct***,char***);
int32_t              XForceScreenSaver(XDisplay*,int32_t);
int32_t              XFree(void*);
int32_t              XFreeColormap(XDisplay*,XColormap);
int32_t              XFreeColors(XDisplay*,XColormap,uint64_t*,int32_t,uint64_t);
int32_t              XFreeCursor(XDisplay*,XCursor);
void                 XFreeEventData(XDisplay*,XGenericEventCookie*);
int32_t              XFreeExtensionList(char**);
int32_t              XFreeFont(XDisplay*,XFontStruct*);
int32_t              XFreeFontInfo(char**,XFontStruct*,int32_t);
int32_t              XFreeFontNames(char**);
int32_t              XFreeFontPath(char**);
void                 XFreeFontSet(XDisplay*,XFontSet);
int32_t              XFreeGC(XDisplay*,XGC);
int32_t              XFreeModifiermap(XModifierKeymap*);
int32_t              XFreePixmap(XDisplay*,XPixmap);
void                 XFreeStringList(char**);
int32_t              XFreeThreads(void);
XGContext            XGContextFromGC(XGC);
int32_t              XGeometry(XDisplay*,int32_t,const char*,const char*,uint32_t,uint32_t,uint32_t,int32_t,int32_t,int32_t*,int32_t*,int32_t*,int32_t*);
char*                XGetAtomName(XDisplay*,XAtom);
int32_t              XGetAtomNames(XDisplay*,XAtom*,int32_t,char**);
int32_t              XGetCommand(XDisplay*,XWindow,char***,int32_t*);
char*                XGetDefault(XDisplay*,const char*,const char*);
int32_t              XGetErrorDatabaseText(XDisplay*,const char*,const char*,const char*,char*,int32_t);
int32_t              XGetErrorText(XDisplay*,int32_t,char*,int32_t);
int32_t              XGetEventData(XDisplay*,XGenericEventCookie*);
char**               XGetFontPath(XDisplay*,int32_t*);
int32_t              XGetFontProperty(XFontStruct*,XAtom,uint64_t*);
int32_t              XGetGCValues(XDisplay*,XGC,uint64_t,XGCValues*);
int32_t              XGetGeometry(XDisplay*,XDrawable,XWindow*,int32_t*,int32_t*,uint32_t*,uint32_t*,uint32_t*,uint32_t*);
int32_t              XGetIconName(XDisplay*,XWindow,char**);
char*                XGetICValues(XIC,...);
XImage*              XGetImage(XDisplay*,XDrawable,int32_t,int32_t,uint32_t,uint32_t,uint64_t,int32_t);
char*                XGetIMValues(XIM,...);
int32_t              XGetInputFocus(XDisplay*,XWindow*,int32_t*);
int32_t              XGetKeyboardControl(XDisplay*,XKeyboardState*);
XKeySym*             XGetKeyboardMapping(XDisplay*,XKeyCode,int32_t,int32_t*);
XModifierKeymap*     XGetModifierMapping(XDisplay*);
XTimeCoord*          XGetMotionEvents(XDisplay*,XWindow,XTime,XTime,int32_t*);
char*                XGetOCValues(XOC,...);
char*                XGetOMValues(XOM,...);
int32_t              XGetPointerControl(XDisplay*,int32_t*,int32_t*,int32_t*);
int32_t              XGetPointerMapping(XDisplay*,uint8_t*,int32_t);
int32_t              XGetScreenSaver(XDisplay*,int32_t*,int32_t*,int32_t*,int32_t*);
XWindow              XGetSelectionOwner(XDisplay*,XAtom);
XImage*              XGetSubImage(XDisplay*,XDrawable,int32_t,int32_t,uint32_t,uint32_t,uint64_t,int32_t,XImage*,int32_t,int32_t);
int32_t              XGetTransientForHint(XDisplay*,XWindow,XWindow*);
int32_t              XGetWindowAttributes(XDisplay*,XWindow,XWindowAttributes*);
int32_t              XGetWindowProperty(XDisplay*,XWindow,XAtom,int64_t,int64_t,int32_t,XAtom,XAtom*,int32_t*,uint64_t*,uint64_t*,uint8_t**);
int32_t              XGetWMColormapWindows(XDisplay*,XWindow,XWindow**,int32_t*);
int32_t              XGetWMProtocols(XDisplay*,XWindow,XAtom**,int32_t*);
int32_t              XGrabButton(XDisplay*,uint32_t,uint32_t,XWindow,int32_t,uint32_t,int32_t,int32_t,XWindow,XCursor);
int32_t              XGrabKey(XDisplay*,int32_t,uint32_t,XWindow,int32_t,int32_t,int32_t);
int32_t              XGrabKeyboard(XDisplay*,XWindow,int32_t,int32_t,int32_t,XTime);
int32_t              XGrabPointer(XDisplay*,XWindow,int32_t,uint32_t,int32_t,int32_t,XWindow,XCursor,XTime);
int32_t              XGrabServer(XDisplay*);
int32_t              XHeightMMOfScreen(XScreen*);
int32_t              XHeightOfScreen(XScreen*);
int32_t              XIconifyWindow(XDisplay*,XWindow,int32_t);
int32_t              XIfEvent(XDisplay*,XEvent*,int32_t(*)(XDisplay*,XEvent*,void*),void*);
int32_t              XImageByteOrder(XDisplay*);
XIM                  XIMOfIC(XIC);
XExtCodes*           XInitExtension(XDisplay*,const char*);
int32_t              XInitImage(XImage*);
int32_t              XInitThreads(void);
XModifierKeymap*     XInsertModifiermapEntry(XModifierKeymap*,XKeyCode,int32_t);
int32_t              XInstallColormap(XDisplay*,XColormap);
int32_t              XInternalConnectionNumbers(XDisplay*,int32_t**,int32_t*);
XAtom                XInternAtom(XDisplay*,const char*,int32_t);
int32_t              XInternAtoms(XDisplay*,char**,int32_t,int32_t,XAtom*);
XKeySym              XKeycodeToKeysym(XDisplay*,XKeyCode,int32_t);
XKeyCode             XKeysymToKeycode(XDisplay*,XKeySym);
char*                XKeysymToString(XKeySym);
int32_t              XKillClient(XDisplay*,XID);
uint64_t             XLastKnownRequestProcessed(XDisplay*);
int32_t*             XListDepths(XDisplay*,int32_t,int32_t*);
char**               XListExtensions(XDisplay*,int32_t*);
char**               XListFonts(XDisplay*,const char*,int32_t,int32_t*);
char**               XListFontsWithInfo(XDisplay*,const char*,int32_t,int32_t*,XFontStruct**);
XHostAddress*        XListHosts(XDisplay*,int32_t*,int32_t*);
XColormap*           XListInstalledColormaps(XDisplay*,XWindow,int32_t*);
XPixmapFormatValues* XListPixmapFormats(XDisplay*,int32_t*);
XAtom*               XListProperties(XDisplay*,XWindow,int32_t*);
XFont                XLoadFont(XDisplay*,const char*);
XFontStruct*         XLoadQueryFont(XDisplay*,const char*);
char*                XLocaleOfFontSet(XFontSet);
char*                XLocaleOfIM(XIM);
char*                XLocaleOfOM(XOM);
void                 XLockDisplay(XDisplay*);
int32_t              XLookupColor(XDisplay*,XColormap,const char*,XColor*,XColor*);
XKeySym              XLookupKeysym(XKeyEvent*,int32_t);
int32_t              XLowerWindow(XDisplay*,XWindow);
int32_t              XMapRaised(XDisplay*,XWindow);
int32_t              XMapSubwindows(XDisplay*,XWindow);
int32_t              XMapWindow(XDisplay*,XWindow);
int32_t              XMaskEvent(XDisplay*,int64_t,XEvent*);
int32_t              XMaxCmapsOfScreen(XScreen*);
int64_t              XMaxRequestSize(XDisplay*);
void                 XmbDrawImageString(XDisplay*,XDrawable,XFontSet,XGC,int32_t,int32_t,const char*,int32_t);
void                 XmbDrawString(XDisplay*,XDrawable,XFontSet,XGC,int32_t,int32_t,const char*,int32_t);
void                 XmbDrawText(XDisplay*,XDrawable,XGC,int32_t,int32_t,XmbTextItem*,int32_t);
int32_t              XmbLookupString(XIC,XKeyEvent*,char*,int32_t,XKeySym*,int32_t*);
char*                XmbResetIC(XIC);
int32_t              XmbTextEscapement(XFontSet,const char*,int32_t);
int32_t              XmbTextExtents(XFontSet,const char*,int32_t,XRectangle*,XRectangle*);
int32_t              XmbTextPerCharExtents(XFontSet,const char*,int32_t,XRectangle*,XRectangle*,int32_t,int32_t*,XRectangle*,XRectangle*);
int32_t              XMinCmapsOfScreen(XScreen*);
int32_t              XMoveResizeWindow(XDisplay*,XWindow,int32_t,int32_t,uint32_t,uint32_t);
int32_t              XMoveWindow(XDisplay*,XWindow,int32_t,int32_t);
XModifierKeymap*     XNewModifiermap(int32_t);
int32_t              XNextEvent(XDisplay*,XEvent*);
uint64_t             XNextRequest(XDisplay*);
int32_t              XNoOp(XDisplay*);
XOM                  XOMOfOC(XOC);
XDisplay*            XOpenDisplay(const char*);
XIM                  XOpenIM(XDisplay*,XrmHashBucketRec*,char*,char*);
XOM                  XOpenOM(XDisplay*,XrmHashBucketRec*,const char*,const char*);
int32_t              XParseColor(XDisplay*,XColormap,const char*,XColor*);
int32_t              XParseGeometry(const char*,int32_t*,int32_t*,uint32_t*,uint32_t*);
int32_t              XPeekEvent(XDisplay*,XEvent*);
int32_t              XPeekIfEvent(XDisplay*,XEvent*,int32_t(*)(XDisplay*,XEvent*,void*),void*);
int32_t              XPending(XDisplay*);
int32_t              XPlanesOfScreen(XScreen*);
void                 XProcessInternalConnection(XDisplay*,int32_t);
int32_t              XProtocolRevision(XDisplay*);
int32_t              XProtocolVersion(XDisplay*);
int32_t              XPutBackEvent(XDisplay*,XEvent*);
int32_t              XPutImage(XDisplay*,XDrawable,XGC,XImage*,int32_t,int32_t,int32_t,int32_t,uint32_t,uint32_t);
int32_t              XQLength(XDisplay*);
int32_t              XQueryBestCursor(XDisplay*,XDrawable,uint32_t,uint32_t,uint32_t*,uint32_t*);
int32_t              XQueryBestSize(XDisplay*,int32_t,XDrawable,uint32_t,uint32_t,uint32_t*,uint32_t*);
int32_t              XQueryBestStipple(XDisplay*,XDrawable,uint32_t,uint32_t,uint32_t*,uint32_t*);
int32_t              XQueryBestTile(XDisplay*,XDrawable,uint32_t,uint32_t,uint32_t*,uint32_t*);
int32_t              XQueryColor(XDisplay*,XColormap,XColor*);
int32_t              XQueryColors(XDisplay*,XColormap,XColor*,int32_t);
int32_t              XQueryExtension(XDisplay*,const char*,int32_t*,int32_t*,int32_t*);
XFontStruct*         XQueryFont(XDisplay*,XID);
int32_t              XQueryKeymap(XDisplay*,char[32]);
int32_t              XQueryPointer(XDisplay*,XWindow,XWindow*,XWindow*,int32_t*,int32_t*,int32_t*,int32_t*,uint32_t*);
int32_t              XQueryTextExtents(XDisplay*,XID,const char*,int32_t,int32_t*,int32_t*,int32_t*,XCharStruct*);
int32_t              XQueryTextExtents16(XDisplay*,XID,const XChar2b*,int32_t,int32_t*,int32_t*,int32_t*,XCharStruct*);
int32_t              XQueryTree(XDisplay*,XWindow,XWindow*,XWindow*,XWindow**,uint32_t*);
int32_t              XRaiseWindow(XDisplay*,XWindow);
int32_t              XReadBitmapFile(XDisplay*,XDrawable,const char*,uint32_t*,uint32_t*,XPixmap*,int32_t*,int32_t*);
int32_t              XReadBitmapFileData(const char*,uint32_t*,uint32_t*,uint8_t**,int32_t*,int32_t*);
int32_t              XRebindKeysym(XDisplay*,XKeySym,XKeySym*,int32_t,const uint8_t*,int32_t);
int32_t              XRecolorCursor(XDisplay*,XCursor,XColor*,XColor*);
int32_t              XReconfigureWMWindow(XDisplay*,XWindow,int32_t,uint32_t,XWindowChanges*);
int32_t              XRefreshKeyboardMapping(XMappingEvent*);
int32_t              XRegisterIMInstantiateCallback(XDisplay*,XrmHashBucketRec*,char*,char*,XIDProc,void*);
void                 XRemoveConnectionWatch(XDisplay*,XConnectionWatchProc,void*);
int32_t              XRemoveFromSaveSet(XDisplay*,XWindow);
int32_t              XRemoveHost(XDisplay*,XHostAddress*);
int32_t              XRemoveHosts(XDisplay*,XHostAddress*,int32_t);
int32_t              XReparentWindow(XDisplay*,XWindow,XWindow,int32_t,int32_t);
int32_t              XResetScreenSaver(XDisplay*);
int32_t              XResizeWindow(XDisplay*,XWindow,uint32_t,uint32_t);
char*                XResourceManagerString(XDisplay*);
int32_t              XRestackWindows(XDisplay*,XWindow*,int32_t);
void                 XrmInitialize(void);
int                  XrmUniqueQuark();
XWindow              XRootWindow(XDisplay*,int32_t);
XWindow              XRootWindowOfScreen(XScreen*);
int32_t              XRotateBuffers(XDisplay*,int32_t);
int32_t              XRotateWindowProperties(XDisplay*,XWindow,XAtom*,int32_t,int32_t);
int32_t              XScreenCount(XDisplay*);
int32_t              XScreenNumberOfScreen(XScreen*);
XScreen*             XScreenOfDisplay(XDisplay*,int32_t);
char*                XScreenResourceString(XScreen*);
int32_t              XSelectInput(XDisplay*,XWindow,int64_t);
int32_t              XSendEvent(XDisplay*,XWindow,int32_t,int64_t,XEvent*);
char*                XServerVendor(XDisplay*);
int32_t              XSetAccessControl(XDisplay*,int32_t);
int32_t              XSetArcMode(XDisplay*,XGC,int32_t);
void                 XSetAuthorization(char*,int32_t,char*,int32_t);
int32_t              XSetBackground(XDisplay*,XGC,uint64_t);
int32_t              XSetClipMask(XDisplay*,XGC,XPixmap);
int32_t              XSetClipOrigin(XDisplay*,XGC,int32_t,int32_t);
int32_t              XSetClipRectangles(XDisplay*,XGC,int32_t,int32_t,XRectangle*,int32_t,int32_t);
int32_t              XSetCloseDownMode(XDisplay*,int32_t);
int32_t              XSetCommand(XDisplay*,XWindow,char**,int32_t);
int32_t              XSetDashes(XDisplay*,XGC,int32_t,const char*,int32_t);
XErrorHandler        XSetErrorHandler(XErrorHandler);
int32_t              XSetFillRule(XDisplay*,XGC,int32_t);
int32_t              XSetFillStyle(XDisplay*,XGC,int32_t);
int32_t              XSetFont(XDisplay*,XGC,XFont);
int32_t              XSetFontPath(XDisplay*,char**,int32_t);
int32_t              XSetForeground(XDisplay*,XGC,uint64_t);
int32_t              XSetFunction(XDisplay*,XGC,int32_t);
int32_t              XSetGraphicsExposures(XDisplay*,XGC,int32_t);
void                 XSetICFocus(XIC);
int32_t              XSetIconName(XDisplay*,XWindow,const char*);
char*                XSetICValues(XIC,...);
char*                XSetIMValues(XIM,...);
int32_t              XSetInputFocus(XDisplay*,XWindow,int32_t,XTime);
void                 XSetIOErrorExitHandler(XDisplay*,XIOErrorExitHandler,void*);
XIOErrorHandler      XSetIOErrorHandler(XIOErrorHandler);
int32_t              XSetLineAttributes(XDisplay*,XGC,uint32_t,int32_t,int32_t,int32_t);
char*                XSetLocaleModifiers(const char*);
int32_t              XSetModifierMapping(XDisplay*,XModifierKeymap*);
char*                XSetOCValues(XOC,...);
char*                XSetOMValues(XOM,...);
int32_t              XSetPlaneMask(XDisplay*,XGC,uint64_t);
int32_t              XSetPointerMapping(XDisplay*,const uint8_t*,int32_t);
int32_t              XSetScreenSaver(XDisplay*,int32_t,int32_t,int32_t,int32_t);
int32_t              XSetSelectionOwner(XDisplay*,XAtom,XWindow,XTime);
int32_t              XSetState(XDisplay*,XGC,uint64_t,uint64_t,int32_t,uint64_t);
int32_t              XSetStipple(XDisplay*,XGC,XPixmap);
int32_t              XSetSubwindowMode(XDisplay*,XGC,int32_t);
int32_t              XSetTile(XDisplay*,XGC,XPixmap);
int32_t              XSetTransientForHint(XDisplay*,XWindow,XWindow);
int32_t              XSetTSOrigin(XDisplay*,XGC,int32_t,int32_t);
int32_t              XSetWindowBackground(XDisplay*,XWindow,uint64_t);
int32_t              XSetWindowBackgroundPixmap(XDisplay*,XWindow,XPixmap);
int32_t              XSetWindowBorder(XDisplay*,XWindow,uint64_t);
int32_t              XSetWindowBorderPixmap(XDisplay*,XWindow,XPixmap);
int32_t              XSetWindowBorderWidth(XDisplay*,XWindow,uint32_t);
int32_t              XSetWindowColormap(XDisplay*,XWindow,XColormap);
int32_t              XSetWMColormapWindows(XDisplay*,XWindow,XWindow*,int32_t);
int32_t              XSetWMProtocols(XDisplay*,XWindow,XAtom*,int32_t);
int32_t              XStoreBuffer(XDisplay*,const char*,int32_t,int32_t);
int32_t              XStoreBytes(XDisplay*,const char*,int32_t);
int32_t              XStoreColor(XDisplay*,XColormap,XColor*);
int32_t              XStoreColors(XDisplay*,XColormap,XColor*,int32_t);
int32_t              XStoreName(XDisplay*,XWindow,const char*);
int32_t              XStoreNamedColor(XDisplay*,XColormap,const char*,uint64_t,int32_t);
XKeySym              XStringToKeysym(const char*);
int32_t              XSupportsLocale(void);
int32_t              XSync(XDisplay*,int32_t);
int32_t              XTextExtents(XFontStruct*,const char*,int32_t,int32_t*,int32_t*,int32_t*,XCharStruct*);
int32_t              XTextExtents16(XFontStruct*,const XChar2b*,int32_t,int32_t*,int32_t*,int32_t*,XCharStruct*);
int32_t              XTextWidth(XFontStruct*,const char*,int32_t);
int32_t              XTextWidth16(XFontStruct*,const XChar2b*,int32_t);
int32_t              XTranslateCoordinates(XDisplay*,XWindow,XWindow,int32_t,int32_t,int32_t*,int32_t*,XWindow*);
int32_t              XUndefineCursor(XDisplay*,XWindow);
int32_t              XUngrabButton(XDisplay*,uint32_t,uint32_t,XWindow);
int32_t              XUngrabKey(XDisplay*,int32_t,uint32_t,XWindow);
int32_t              XUngrabKeyboard(XDisplay*,XTime);
int32_t              XUngrabPointer(XDisplay*,XTime);
int32_t              XUngrabServer(XDisplay*);
int32_t              XUninstallColormap(XDisplay*,XColormap);
int32_t              XUnloadFont(XDisplay*,XFont);
void                 XUnlockDisplay(XDisplay*);
int32_t              XUnmapSubwindows(XDisplay*,XWindow);
int32_t              XUnmapWindow(XDisplay*,XWindow);
int32_t              XUnregisterIMInstantiateCallback(XDisplay*,XrmHashBucketRec*,char*,char*,XIDProc,void*);
void                 XUnsetICFocus(XIC);
void                 Xutf8DrawImageString(XDisplay*,XDrawable,XFontSet,XGC,int32_t,int32_t,const char*,int32_t);
void                 Xutf8DrawString(XDisplay*,XDrawable,XFontSet,XGC,int32_t,int32_t,const char*,int32_t);
void                 Xutf8DrawText(XDisplay*,XDrawable,XGC,int32_t,int32_t,XmbTextItem*,int32_t);
int32_t              Xutf8LookupString(XIC,XKeyEvent*,char*,int32_t,XKeySym*,int32_t*);
char*                Xutf8ResetIC(XIC);
int32_t              Xutf8TextEscapement(XFontSet,const char*,int32_t);
int32_t              Xutf8TextExtents(XFontSet,const char*,int32_t,XRectangle*,XRectangle*);
int32_t              Xutf8TextPerCharExtents(XFontSet,const char*,int32_t,XRectangle*,XRectangle*,int32_t,int32_t*,XRectangle*,XRectangle*);
XVaNestedList        XVaCreateNestedList(int32_t,...);
int32_t              XVendorRelease(XDisplay*);
XVisualID            XVisualIDFromVisual(XVisual*);
int32_t              XWarpPointer(XDisplay*,XWindow,XWindow,int32_t,int32_t,uint32_t,uint32_t,int32_t,int32_t);
void                 XwcDrawImageString(XDisplay*,XDrawable,XFontSet,XGC,int32_t,int32_t,const wchar_t*,int32_t);
void                 XwcDrawString(XDisplay*,XDrawable,XFontSet,XGC,int32_t,int32_t,const wchar_t*,int32_t);
void                 XwcDrawText(XDisplay*,XDrawable,XGC,int32_t,int32_t,XwcTextItem*,int32_t);
int32_t              XwcLookupString(XIC,XKeyEvent*,wchar_t*,int32_t,XKeySym*,int32_t*);
wchar_t*             XwcResetIC(XIC);
int32_t              XwcTextEscapement(XFontSet,const wchar_t*,int32_t);
int32_t              XwcTextExtents(XFontSet,const wchar_t*,int32_t,XRectangle*,XRectangle*);
int32_t              XwcTextPerCharExtents(XFontSet,const wchar_t*,int32_t,XRectangle*,XRectangle*,int32_t,int32_t*,XRectangle*,XRectangle*);
uint64_t             XWhitePixel(XDisplay*,int32_t);
uint64_t             XWhitePixelOfScreen(XScreen*);
int32_t              XWidthMMOfScreen(XScreen*);
int32_t              XWidthOfScreen(XScreen*);
int32_t              XWindowEvent(XDisplay*,XWindow,int64_t,XEvent*);
int32_t              XWithdrawWindow(XDisplay*,XWindow,int32_t);
int32_t              XWriteBitmapFile(XDisplay*,const char*,XPixmap,uint32_t,uint32_t,int32_t,int32_t);

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif// _X11_Xlib_h_