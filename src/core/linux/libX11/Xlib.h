// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE.                       │
// └───────────────────────────────────────────────────────────────────────────────────────────┘

#ifndef _core_linux_libX11_Xlib_h_
#define _core_linux_libX11_Xlib_h_

#include "X.h"
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

#define AllPlanes                                    ((uint64_t)~0L)
#define BitmapBitOrder(dpy)                          (((XDisplay*)(dpy))->bitmap_bit_order)
#define BitmapPad(dpy)                               (((XDisplay*)(dpy))->bitmap_pad)
#define BitmapUnit(dpy)                              (((XDisplay*)(dpy))->bitmap_unit)
#define BlackPixel(dpy,scr)                          (ScreenOfDisplay(dpy,scr)->black_pixel)
#define BlackPixelOfScreen(s)                        ((s)->black_pixel)
#define CellsOfScreen(s)                             (DefaultVisualOfScreen((s))->map_entries)
#define ConnectionNumber(dpy)                        (((XDisplay*)(dpy))->fd)
#define DefaultColormap(dpy,scr)                     (ScreenOfDisplay(dpy,scr)->cmap)
#define DefaultColormapOfScreen(s)                   ((s)->cmap)
#define DefaultDepth(dpy,scr)                        (ScreenOfDisplay(dpy,scr)->root_depth)
#define DefaultDepthOfScreen(s)                      ((s)->root_depth)
#define DefaultGC(dpy,scr)                           (ScreenOfDisplay(dpy,scr)->default_gc)
#define DefaultGCOfScreen(s)                         ((s)->default_gc)
#define DefaultRootWindow(dpy)                       (ScreenOfDisplay(dpy,DefaultScreen(dpy))->root)
#define DefaultScreen(dpy)                           (((XDisplay*)(dpy))->default_screen)
#define DefaultScreenOfDisplay(dpy)                  ScreenOfDisplay(dpy,DefaultScreen(dpy))
#define DefaultVisual(dpy,scr)                       (ScreenOfDisplay(dpy,scr)->root_visual)
#define DefaultVisualOfScreen(s)                     ((s)->root_visual)
#define DisplayCells(dpy,scr)                        (DefaultVisual(dpy,scr)->map_entries)
#define DisplayHeight(dpy,scr)                       (ScreenOfDisplay(dpy,scr)->height)
#define DisplayHeightMM(dpy,scr)                     (ScreenOfDisplay(dpy,scr)->mheight)
#define DisplayOfScreen(s)                           ((s)->display)
#define DisplayPlanes(dpy,scr)                       (ScreenOfDisplay(dpy,scr)->root_depth)
#define DisplayString(dpy)                           (((XDisplay*)(dpy))->display_name)
#define DisplayWidth(dpy,scr)                        (ScreenOfDisplay(dpy,scr)->width)
#define DisplayWidthMM(dpy,scr)                      (ScreenOfDisplay(dpy,scr)->mwidth)
#define DoesBackingStore(s)                          ((s)->backing_store)
#define DoesSaveUnders(s)                            ((s)->save_unders)
#define EventMaskOfScreen(s)                         ((s)->root_input_mask)
#define HeightMMOfScreen(s)                          ((s)->mheight)
#define HeightOfScreen(s)                            ((s)->height)
#define ImageByteOrder(dpy)                          (((XDisplay*)(dpy))->byte_order)
#define LastKnownRequestProcessed(dpy)               (((XDisplay*)(dpy))->last_request_read)
#define MaxCmapsOfScreen(s)                          ((s)->max_maps)
#define MinCmapsOfScreen(s)                          ((s)->min_maps)
#define NextRequest(dpy)                             (((XDisplay*)(dpy))->request + 1)
#define PlanesOfScreen(s)                            ((s)->root_depth)
#define ProtocolRevision(dpy)                        (((XDisplay*)(dpy))->proto_minor_version)
#define ProtocolVersion(dpy)                         (((XDisplay*)(dpy))->proto_major_version)
#define QLength(dpy)                                 (((XDisplay*)(dpy))->qlen)
#define QueuedAfterFlush                             2
#define QueuedAfterReading                           1
#define QueuedAlready                                0
#define RootWindow(dpy,scr)                          (ScreenOfDisplay(dpy,scr)->root)
#define RootWindowOfScreen(s)                        ((s)->root)
#define ScreenCount(dpy)                             (((XDisplay*)(dpy))->nscreens)
#define ScreenOfDisplay(dpy,scr)                     (&((XDisplay*)(dpy))->screens[scr])
#define ServerVendor(dpy)                            (((XDisplay*)(dpy))->vendor)
#define VendorRelease(dpy)                           (((XDisplay*)(dpy))->release)
#define WhitePixel(dpy,scr)                          (ScreenOfDisplay(dpy,scr)->white_pixel)
#define WhitePixelOfScreen(s)                        ((s)->white_pixel)
#define WidthMMOfScreen(s)                           ((s)->mwidth)
#define WidthOfScreen(s)                             ((s)->width)
#define XAllocID(dpy)                                ((*((XDisplay*)(dpy))->resource_alloc)((dpy)))
#define XBufferOverflow                              -1
#define XIMHighlight                                 (1L<<2)
#define XIMHotKeyStateOFF                            (0x0002L)
#define XIMHotKeyStateON                             (0x0001L)
#define XIMInitialState                              1L
#define XIMPreeditArea                               0x0001L
#define XIMPreeditCallbacks                          0x0002L
#define XIMPreeditDisable                            (1L<<1)
#define XIMPreeditEnable                             1L
#define XIMPreeditNone                               0x0010L
#define XIMPreeditNothing                            0x0008L
#define XIMPreeditPosition                           0x0004L
#define XIMPreeditUnKnown                            0L
#define XIMPreserveState                             (1L<<1)
#define XIMPrimary                                   (1L<<5)
#define XIMReverse                                   1L
#define XIMSecondary                                 (1L<<6)
#define XIMStatusArea                                0x0100L
#define XIMStatusCallbacks                           0x0200L
#define XIMStatusNone                                0x0800L
#define XIMStatusNothing                             0x0400L
#define XIMStringConversionBottomEdge                (0x00000008)
#define XIMStringConversionBuffer                    (0x0001)
#define XIMStringConversionChar                      (0x0004)
#define XIMStringConversionConcealed                 (0x00000010)
#define XIMStringConversionLeftEdge                  (0x00000001)
#define XIMStringConversionLine                      (0x0002)
#define XIMStringConversionRetrieval                 (0x0002)
#define XIMStringConversionRightEdge                 (0x00000002)
#define XIMStringConversionSubstitution              (0x0001)
#define XIMStringConversionTopEdge                   (0x00000004)
#define XIMStringConversionWord                      (0x0003)
#define XIMStringConversionWrapped                   (0x00000020)
#define XIMTertiary                                  (1L<<7)
#define XIMUnderline                                 (1L<<1)
#define XIMVisibleToBackword                         (1L<<9)
#define XIMVisibleToCenter                           (1L<<10)
#define XIMVisibleToForward                          (1L<<8)
#define XlibSpecificationRelease                     6
#define XLookupBoth                                  4
#define XLookupChars                                 2
#define XLookupKeySym                                3
#define XLookupNone                                  1
#define XNArea                                       "area"
#define XNAreaNeeded                                 "areaNeeded"
#define XNBackground                                 "background"
#define XNBackgroundPixmap                           "backgroundPixmap"
#define XNBaseFontName                               "baseFontName"
#define XNClientWindow                               "clientWindow"
#define XNColormap                                   "colorMap"
#define XNContextualDrawing                          "contextualDrawing"
#define XNCursor                                     "cursor"
#define XNDefaultString                              "defaultString"
#define XNDestroyCallback                            "destroyCallback"
#define XNDirectionalDependentDrawing                "directionalDependentDrawing"
#define XNFilterEvents                               "filterEvents"
#define XNFocusWindow                                "focusWindow"
#define XNFontInfo                                   "fontInfo"
#define XNFontSet                                    "fontSet"
#define XNForeground                                 "foreground"
#define XNGeometryCallback                           "geometryCallback"
#define XNHotKey                                     "hotKey"
#define XNHotKeyState                                "hotKeyState"
#define XNInputStyle                                 "inputStyle"
#define XNLineSpace                                  "lineSpace"
#define XNMissingCharSet                             "missingCharSet"
#define XNOMAutomatic                                "omAutomatic"
#define XNOrientation                                "orientation"
#define XNPreeditAttributes                          "preeditAttributes"
#define XNPreeditCaretCallback                       "preeditCaretCallback"
#define XNPreeditDoneCallback                        "preeditDoneCallback"
#define XNPreeditDrawCallback                        "preeditDrawCallback"
#define XNPreeditStartCallback                       "preeditStartCallback"
#define XNPreeditState                               "preeditState"
#define XNPreeditStateNotifyCallback                 "preeditStateNotifyCallback"
#define XNQueryICValuesList                          "queryICValuesList"
#define XNQueryIMValuesList                          "queryIMValuesList"
#define XNQueryInputStyle                            "queryInputStyle"
#define XNQueryOrientation                           "queryOrientation"
#define XNR6PreeditCallback                          "r6PreeditCallback"
#define XNRequiredCharSet                            "requiredCharSet"
#define XNResetState                                 "resetState"
#define XNResourceClass                              "resourceClass"
#define XNResourceName                               "resourceName"
#define XNSeparatorofNestedList                      "separatorofNestedList"
#define XNSpotLocation                               "spotLocation"
#define XNStatusAttributes                           "statusAttributes"
#define XNStatusDoneCallback                         "statusDoneCallback"
#define XNStatusDrawCallback                         "statusDrawCallback"
#define XNStatusStartCallback                        "statusStartCallback"
#define XNStdColormap                                "stdColorMap"
#define XNStringConversion                           "stringConversion"
#define XNStringConversionCallback                   "stringConversionCallback"
#define XNVaNestedList                               "XNVaNestedList"
#define XNVisiblePosition                            "visiblePosition"

typedef struct _XIC*                                 XIC;
typedef struct _XIM*                                 XIM;
typedef struct _XOC*                                 XOC;
typedef struct _XOC**                                XFontSet;
typedef struct _XOM*                                 XOM;
typedef struct XAnyEvent                             XAnyEvent;
typedef struct XArc                                  XArc;
typedef struct XButtonEvent                          XButtonEvent;
typedef struct XChar2b                               XChar2b;
typedef struct XCharStruct                           XCharStruct;
typedef struct XCirculateEvent                       XCirculateEvent;
typedef struct XCirculateRequestEvent                XCirculateRequestEvent;
typedef struct XClientMessageEvent                   XClientMessageEvent;
typedef struct XColor                                XColor;
typedef struct XColormapEvent                        XColormapEvent;
typedef struct XConfigureEvent                       XConfigureEvent;
typedef struct XConfigureRequestEvent                XConfigureRequestEvent;
typedef struct XCreateWindowEvent                    XCreateWindowEvent;
typedef struct XCrossingEvent                        XCrossingEvent;
typedef struct XDepth                                XDepth;
typedef struct XDestroyWindowEvent                   XDestroyWindowEvent;
typedef struct XDisplay                              XDisplay;
typedef struct XErrorEvent                           XErrorEvent;
typedef struct XExposeEvent                          XExposeEvent;
typedef struct XExtCodes                             XExtCodes;
typedef struct XExtData                              XExtData;
typedef struct XFocusChangeEvent                     XFocusChangeEvent;
typedef struct XFontProp                             XFontProp;
typedef struct XFontSetExtents                       XFontSetExtents;
typedef struct XFontStruct                           XFontStruct;
typedef struct _XGC*                                 XGC;
typedef struct XGCValues                             XGCValues;
typedef struct XGenericEvent                         XGenericEvent;
typedef struct XGenericEventCookie                   XGenericEventCookie;
typedef struct XGraphicsExposeEvent                  XGraphicsExposeEvent;
typedef struct XGravityEvent                         XGravityEvent;
typedef struct XHostAddress                          XHostAddress;
typedef struct XICCallback                           XICCallback;
typedef struct XImage                                XImage;
typedef struct XIMCallback                           XIMCallback;
typedef uint64_t                                     XIMFeedback;
typedef uint64_t                                     XIMHotKeyState;
typedef struct XIMHotKeyTrigger                      XIMHotKeyTrigger;
typedef struct XIMHotKeyTriggers                     XIMHotKeyTriggers;
typedef struct XIMPreeditCaretCallbackStruct         XIMPreeditCaretCallbackStruct;
typedef struct XIMPreeditDrawCallbackStruct          XIMPreeditDrawCallbackStruct;
typedef uint64_t                                     XIMPreeditState;
typedef struct XIMPreeditStateNotifyCallbackStruct   XIMPreeditStateNotifyCallbackStruct;
typedef uint64_t                                     XIMResetState;
typedef struct XIMStatusDrawCallbackStruct           XIMStatusDrawCallbackStruct;
typedef struct XIMStringConversionCallbackStruct     XIMStringConversionCallbackStruct;
typedef uint64_t                                     XIMStringConversionFeedback;
typedef uint16_t                                     XIMStringConversionOperation;
typedef uint16_t                                     XIMStringConversionPosition;
typedef uint16_t                                     XIMStringConversionType;
typedef uint64_t                                     XIMStyle;
typedef struct XIMStyles                             XIMStyles;
typedef struct XIMText                               XIMText;
typedef struct XIMValuesList                         XIMValuesList;
typedef struct XKeyboardControl                      XKeyboardControl;
typedef struct XKeyboardState                        XKeyboardState;
typedef struct XKeyEvent                             XKeyEvent;
typedef struct XKeymapEvent                          XKeymapEvent;
typedef struct XMapEvent                             XMapEvent;
typedef struct XMappingEvent                         XMappingEvent;
typedef struct XMapRequestEvent                      XMapRequestEvent;
typedef struct XmbTextItem                           XmbTextItem;
typedef struct XModifierKeymap                       XModifierKeymap;
typedef struct XMotionEvent                          XMotionEvent;
typedef struct XNoExposeEvent                        XNoExposeEvent;
typedef struct XOMCharSetList                        XOMCharSetList;
typedef struct XOMFontInfo                           XOMFontInfo;
typedef struct XOMOrientation                        XOMOrientation;
typedef struct XPixmapFormatValues                   XPixmapFormatValues;
typedef struct XPoint                                XPoint;
typedef struct XPrivate                              XPrivate;
typedef struct XPropertyEvent                        XPropertyEvent;
typedef struct XRectangle                            XRectangle;
typedef struct XReparentEvent                        XReparentEvent;
typedef struct XResizeRequestEvent                   XResizeRequestEvent;
typedef struct XrmHashBucketRec                      XrmHashBucketRec;
typedef struct XScreen                               XScreen;
typedef struct XScreenFormat                         XScreenFormat;
typedef struct XSegment                              XSegment;
typedef struct XSelectionClearEvent                  XSelectionClearEvent;
typedef struct XSelectionEvent                       XSelectionEvent;
typedef struct XSelectionRequestEvent                XSelectionRequestEvent;
typedef struct XServerInterpretedAddress             XServerInterpretedAddress;
typedef struct XSetWindowAttributes                  XSetWindowAttributes;
typedef struct XTextItem                             XTextItem;
typedef struct XTextItem16                           XTextItem16;
typedef struct XTimeCoord                            XTimeCoord;
typedef struct XUnmapEvent                           XUnmapEvent;
typedef void*                                        XVaNestedList;
typedef struct XVisibilityEvent                      XVisibilityEvent;
typedef struct XVisual                               XVisual;
typedef struct XwcTextItem                           XwcTextItem;
typedef struct XWindowAttributes                     XWindowAttributes;
typedef struct XWindowChanges                        XWindowChanges;
typedef void                                       (*XIMProc)(XIM,void*,void*);
typedef int32_t                                    (*XICProc)(XIC,void*,void*);
typedef void                                       (*XIDProc)(XDisplay*,void*,void*);
typedef void                                       (*XConnectionWatchProc)(XDisplay*,void*,int32_t,int32_t,void**);
typedef int32_t                                    (*XErrorHandler)(XDisplay*,XErrorEvent*);
typedef int32_t                                    (*XIOErrorHandler)(XDisplay*);
typedef void                                       (*XIOErrorExitHandler)(XDisplay*,void*);

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

#define _Xmblen(...)                          libX11._Xmblen(__VA_ARGS__)
#define _Xmbtowc(...)                         libX11._Xmbtowc(__VA_ARGS__)
#define _Xwctomb(...)                         libX11._Xwctomb(__VA_ARGS__)
#define XActivateScreenSaver(...)             libX11.XActivateScreenSaver(__VA_ARGS__)
#define XAddConnectionWatch(...)              libX11.XAddConnectionWatch(__VA_ARGS__)
#define XAddExtension(...)                    libX11.XAddExtension(__VA_ARGS__)
#define XAddHost(...)                         libX11.XAddHost(__VA_ARGS__)
#define XAddHosts(...)                        libX11.XAddHosts(__VA_ARGS__)
#define XAddToExtensionList(...)              libX11.XAddToExtensionList(__VA_ARGS__)
#define XAddToSaveSet(...)                    libX11.XAddToSaveSet(__VA_ARGS__)
#define XAllocColor(...)                      libX11.XAllocColor(__VA_ARGS__)
#define XAllocColorCells(...)                 libX11.XAllocColorCells(__VA_ARGS__)
#define XAllocColorPlanes(...)                libX11.XAllocColorPlanes(__VA_ARGS__)
#define XAllocNamedColor(...)                 libX11.XAllocNamedColor(__VA_ARGS__)
#define XAllowEvents(...)                     libX11.XAllowEvents(__VA_ARGS__)
#define XAllPlanes(...)                       libX11.XAllPlanes(__VA_ARGS__)
#define XAutoRepeatOff(...)                   libX11.XAutoRepeatOff(__VA_ARGS__)
#define XAutoRepeatOn(...)                    libX11.XAutoRepeatOn(__VA_ARGS__)
#define XBaseFontNameListOfFontSet(...)       libX11.XBaseFontNameListOfFontSet(__VA_ARGS__)
#define XBell(...)                            libX11.XBell(__VA_ARGS__)
#define XBitmapBitOrder(...)                  libX11.XBitmapBitOrder(__VA_ARGS__)
#define XBitmapPad(...)                       libX11.XBitmapPad(__VA_ARGS__)
#define XBitmapUnit(...)                      libX11.XBitmapUnit(__VA_ARGS__)
#define XBlackPixel(...)                      libX11.XBlackPixel(__VA_ARGS__)
#define XBlackPixelOfScreen(...)              libX11.XBlackPixelOfScreen(__VA_ARGS__)
#define XCellsOfScreen(...)                   libX11.XCellsOfScreen(__VA_ARGS__)
#define XChangeActivePointerGrab(...)         libX11.XChangeActivePointerGrab(__VA_ARGS__)
#define XChangeGC(...)                        libX11.XChangeGC(__VA_ARGS__)
#define XChangeKeyboardControl(...)           libX11.XChangeKeyboardControl(__VA_ARGS__)
#define XChangeKeyboardMapping(...)           libX11.XChangeKeyboardMapping(__VA_ARGS__)
#define XChangePointerControl(...)            libX11.XChangePointerControl(__VA_ARGS__)
#define XChangeProperty(...)                  libX11.XChangeProperty(__VA_ARGS__)
#define XChangeSaveSet(...)                   libX11.XChangeSaveSet(__VA_ARGS__)
#define XChangeWindowAttributes(...)          libX11.XChangeWindowAttributes(__VA_ARGS__)
#define XCheckIfEvent(...)                    libX11.XCheckIfEvent(__VA_ARGS__)
#define XCheckMaskEvent(...)                  libX11.XCheckMaskEvent(__VA_ARGS__)
#define XCheckTypedEvent(...)                 libX11.XCheckTypedEvent(__VA_ARGS__)
#define XCheckTypedWindowEvent(...)           libX11.XCheckTypedWindowEvent(__VA_ARGS__)
#define XCheckWindowEvent(...)                libX11.XCheckWindowEvent(__VA_ARGS__)
#define XCirculateSubwindows(...)             libX11.XCirculateSubwindows(__VA_ARGS__)
#define XCirculateSubwindowsDown(...)         libX11.XCirculateSubwindowsDown(__VA_ARGS__)
#define XCirculateSubwindowsUp(...)           libX11.XCirculateSubwindowsUp(__VA_ARGS__)
#define XClearArea(...)                       libX11.XClearArea(__VA_ARGS__)
#define XClearWindow(...)                     libX11.XClearWindow(__VA_ARGS__)
#define XCloseDisplay(...)                    libX11.XCloseDisplay(__VA_ARGS__)
#define XCloseIM(...)                         libX11.XCloseIM(__VA_ARGS__)
#define XCloseOM(...)                         libX11.XCloseOM(__VA_ARGS__)
#define XConfigureWindow(...)                 libX11.XConfigureWindow(__VA_ARGS__)
#define XConnectionNumber(...)                libX11.XConnectionNumber(__VA_ARGS__)
#define XContextDependentDrawing(...)         libX11.XContextDependentDrawing(__VA_ARGS__)
#define XContextualDrawing(...)               libX11.XContextualDrawing(__VA_ARGS__)
#define XConvertSelection(...)                libX11.XConvertSelection(__VA_ARGS__)
#define XCopyArea(...)                        libX11.XCopyArea(__VA_ARGS__)
#define XCopyColormapAndFree(...)             libX11.XCopyColormapAndFree(__VA_ARGS__)
#define XCopyGC(...)                          libX11.XCopyGC(__VA_ARGS__)
#define XCopyPlane(...)                       libX11.XCopyPlane(__VA_ARGS__)
#define XCreateBitmapFromData(...)            libX11.XCreateBitmapFromData(__VA_ARGS__)
#define XCreateColormap(...)                  libX11.XCreateColormap(__VA_ARGS__)
#define XCreateFontCursor(...)                libX11.XCreateFontCursor(__VA_ARGS__)
#define XCreateFontSet(...)                   libX11.XCreateFontSet(__VA_ARGS__)
#define XCreateGC(...)                        libX11.XCreateGC(__VA_ARGS__)
#define XCreateGlyphCursor(...)               libX11.XCreateGlyphCursor(__VA_ARGS__)
#define XCreateIC(...)                        libX11.XCreateIC(__VA_ARGS__)
#define XCreateImage(...)                     libX11.XCreateImage(__VA_ARGS__)
#define XCreateOC(...)                        libX11.XCreateOC(__VA_ARGS__)
#define XCreatePixmap(...)                    libX11.XCreatePixmap(__VA_ARGS__)
#define XCreatePixmapCursor(...)              libX11.XCreatePixmapCursor(__VA_ARGS__)
#define XCreatePixmapFromBitmapData(...)      libX11.XCreatePixmapFromBitmapData(__VA_ARGS__)
#define XCreateSimpleWindow(...)              libX11.XCreateSimpleWindow(__VA_ARGS__)
#define XCreateWindow(...)                    libX11.XCreateWindow(__VA_ARGS__)
#define XDefaultColormap(...)                 libX11.XDefaultColormap(__VA_ARGS__)
#define XDefaultColormapOfScreen(...)         libX11.XDefaultColormapOfScreen(__VA_ARGS__)
#define XDefaultDepth(...)                    libX11.XDefaultDepth(__VA_ARGS__)
#define XDefaultDepthOfScreen(...)            libX11.XDefaultDepthOfScreen(__VA_ARGS__)
#define XDefaultGC(...)                       libX11.XDefaultGC(__VA_ARGS__)
#define XDefaultGCOfScreen(...)               libX11.XDefaultGCOfScreen(__VA_ARGS__)
#define XDefaultRootWindow(...)               libX11.XDefaultRootWindow(__VA_ARGS__)
#define XDefaultScreen(...)                   libX11.XDefaultScreen(__VA_ARGS__)
#define XDefaultScreenOfDisplay(...)          libX11.XDefaultScreenOfDisplay(__VA_ARGS__)
#define XDefaultVisual(...)                   libX11.XDefaultVisual(__VA_ARGS__)
#define XDefaultVisualOfScreen(...)           libX11.XDefaultVisualOfScreen(__VA_ARGS__)
#define XDefineCursor(...)                    libX11.XDefineCursor(__VA_ARGS__)
#define XDeleteModifiermapEntry(...)          libX11.XDeleteModifiermapEntry(__VA_ARGS__)
#define XDeleteProperty(...)                  libX11.XDeleteProperty(__VA_ARGS__)
#define XDestroyIC(...)                       libX11.XDestroyIC(__VA_ARGS__)
#define XDestroyOC(...)                       libX11.XDestroyOC(__VA_ARGS__)
#define XDestroySubwindows(...)               libX11.XDestroySubwindows(__VA_ARGS__)
#define XDestroyWindow(...)                   libX11.XDestroyWindow(__VA_ARGS__)
#define XDirectionalDependentDrawing(...)     libX11.XDirectionalDependentDrawing(__VA_ARGS__)
#define XDisableAccessControl(...)            libX11.XDisableAccessControl(__VA_ARGS__)
#define XDisplayCells(...)                    libX11.XDisplayCells(__VA_ARGS__)
#define XDisplayHeight(...)                   libX11.XDisplayHeight(__VA_ARGS__)
#define XDisplayHeightMM(...)                 libX11.XDisplayHeightMM(__VA_ARGS__)
#define XDisplayKeycodes(...)                 libX11.XDisplayKeycodes(__VA_ARGS__)
#define XDisplayMotionBufferSize(...)         libX11.XDisplayMotionBufferSize(__VA_ARGS__)
#define XDisplayName(...)                     libX11.XDisplayName(__VA_ARGS__)
#define XDisplayOfIM(...)                     libX11.XDisplayOfIM(__VA_ARGS__)
#define XDisplayOfOM(...)                     libX11.XDisplayOfOM(__VA_ARGS__)
#define XDisplayOfScreen(...)                 libX11.XDisplayOfScreen(__VA_ARGS__)
#define XDisplayPlanes(...)                   libX11.XDisplayPlanes(__VA_ARGS__)
#define XDisplayString(...)                   libX11.XDisplayString(__VA_ARGS__)
#define XDisplayWidth(...)                    libX11.XDisplayWidth(__VA_ARGS__)
#define XDisplayWidthMM(...)                  libX11.XDisplayWidthMM(__VA_ARGS__)
#define XDoesBackingStore(...)                libX11.XDoesBackingStore(__VA_ARGS__)
#define XDoesSaveUnders(...)                  libX11.XDoesSaveUnders(__VA_ARGS__)
#define XDrawArc(...)                         libX11.XDrawArc(__VA_ARGS__)
#define XDrawArcs(...)                        libX11.XDrawArcs(__VA_ARGS__)
#define XDrawImageString(...)                 libX11.XDrawImageString(__VA_ARGS__)
#define XDrawImageString16(...)               libX11.XDrawImageString16(__VA_ARGS__)
#define XDrawLine(...)                        libX11.XDrawLine(__VA_ARGS__)
#define XDrawLines(...)                       libX11.XDrawLines(__VA_ARGS__)
#define XDrawPoint(...)                       libX11.XDrawPoint(__VA_ARGS__)
#define XDrawPoints(...)                      libX11.XDrawPoints(__VA_ARGS__)
#define XDrawRectangle(...)                   libX11.XDrawRectangle(__VA_ARGS__)
#define XDrawRectangles(...)                  libX11.XDrawRectangles(__VA_ARGS__)
#define XDrawSegments(...)                    libX11.XDrawSegments(__VA_ARGS__)
#define XDrawString(...)                      libX11.XDrawString(__VA_ARGS__)
#define XDrawString16(...)                    libX11.XDrawString16(__VA_ARGS__)
#define XDrawText(...)                        libX11.XDrawText(__VA_ARGS__)
#define XDrawText16(...)                      libX11.XDrawText16(__VA_ARGS__)
#define XEHeadOfExtensionList(...)            libX11.XEHeadOfExtensionList(__VA_ARGS__)
#define XEnableAccessControl(...)             libX11.XEnableAccessControl(__VA_ARGS__)
#define XEventMaskOfScreen(...)               libX11.XEventMaskOfScreen(__VA_ARGS__)
#define XEventsQueued(...)                    libX11.XEventsQueued(__VA_ARGS__)
#define XExtendedMaxRequestSize(...)          libX11.XExtendedMaxRequestSize(__VA_ARGS__)
#define XExtentsOfFontSet(...)                libX11.XExtentsOfFontSet(__VA_ARGS__)
#define XFetchBuffer(...)                     libX11.XFetchBuffer(__VA_ARGS__)
#define XFetchBytes(...)                      libX11.XFetchBytes(__VA_ARGS__)
#define XFetchName(...)                       libX11.XFetchName(__VA_ARGS__)
#define XFillArc(...)                         libX11.XFillArc(__VA_ARGS__)
#define XFillArcs(...)                        libX11.XFillArcs(__VA_ARGS__)
#define XFillPolygon(...)                     libX11.XFillPolygon(__VA_ARGS__)
#define XFillRectangle(...)                   libX11.XFillRectangle(__VA_ARGS__)
#define XFillRectangles(...)                  libX11.XFillRectangles(__VA_ARGS__)
#define XFilterEvent(...)                     libX11.XFilterEvent(__VA_ARGS__)
#define XFindOnExtensionList(...)             libX11.XFindOnExtensionList(__VA_ARGS__)
#define XFlush(...)                           libX11.XFlush(__VA_ARGS__)
#define XFlushGC(...)                         libX11.XFlushGC(__VA_ARGS__)
#define XFontsOfFontSet(...)                  libX11.XFontsOfFontSet(__VA_ARGS__)
#define XForceScreenSaver(...)                libX11.XForceScreenSaver(__VA_ARGS__)
#define XFree(...)                            libX11.XFree(__VA_ARGS__)
#define XFreeColormap(...)                    libX11.XFreeColormap(__VA_ARGS__)
#define XFreeColors(...)                      libX11.XFreeColors(__VA_ARGS__)
#define XFreeCursor(...)                      libX11.XFreeCursor(__VA_ARGS__)
#define XFreeEventData(...)                   libX11.XFreeEventData(__VA_ARGS__)
#define XFreeExtensionList(...)               libX11.XFreeExtensionList(__VA_ARGS__)
#define XFreeFont(...)                        libX11.XFreeFont(__VA_ARGS__)
#define XFreeFontInfo(...)                    libX11.XFreeFontInfo(__VA_ARGS__)
#define XFreeFontNames(...)                   libX11.XFreeFontNames(__VA_ARGS__)
#define XFreeFontPath(...)                    libX11.XFreeFontPath(__VA_ARGS__)
#define XFreeFontSet(...)                     libX11.XFreeFontSet(__VA_ARGS__)
#define XFreeGC(...)                          libX11.XFreeGC(__VA_ARGS__)
#define XFreeModifiermap(...)                 libX11.XFreeModifiermap(__VA_ARGS__)
#define XFreePixmap(...)                      libX11.XFreePixmap(__VA_ARGS__)
#define XFreeStringList(...)                  libX11.XFreeStringList(__VA_ARGS__)
#define XFreeThreads(...)                     libX11.XFreeThreads(__VA_ARGS__)
#define XGContextFromGC(...)                  libX11.XGContextFromGC(__VA_ARGS__)
#define XGeometry(...)                        libX11.XGeometry(__VA_ARGS__)
#define XGetAtomName(...)                     libX11.XGetAtomName(__VA_ARGS__)
#define XGetAtomNames(...)                    libX11.XGetAtomNames(__VA_ARGS__)
#define XGetCommand(...)                      libX11.XGetCommand(__VA_ARGS__)
#define XGetDefault(...)                      libX11.XGetDefault(__VA_ARGS__)
#define XGetErrorDatabaseText(...)            libX11.XGetErrorDatabaseText(__VA_ARGS__)
#define XGetErrorText(...)                    libX11.XGetErrorText(__VA_ARGS__)
#define XGetEventData(...)                    libX11.XGetEventData(__VA_ARGS__)
#define XGetFontPath(...)                     libX11.XGetFontPath(__VA_ARGS__)
#define XGetFontProperty(...)                 libX11.XGetFontProperty(__VA_ARGS__)
#define XGetGCValues(...)                     libX11.XGetGCValues(__VA_ARGS__)
#define XGetGeometry(...)                     libX11.XGetGeometry(__VA_ARGS__)
#define XGetIconName(...)                     libX11.XGetIconName(__VA_ARGS__)
#define XGetICValues(...)                     libX11.XGetICValues(__VA_ARGS__)
#define XGetImage(...)                        libX11.XGetImage(__VA_ARGS__)
#define XGetIMValues(...)                     libX11.XGetIMValues(__VA_ARGS__)
#define XGetInputFocus(...)                   libX11.XGetInputFocus(__VA_ARGS__)
#define XGetKeyboardControl(...)              libX11.XGetKeyboardControl(__VA_ARGS__)
#define XGetKeyboardMapping(...)              libX11.XGetKeyboardMapping(__VA_ARGS__)
#define XGetModifierMapping(...)              libX11.XGetModifierMapping(__VA_ARGS__)
#define XGetMotionEvents(...)                 libX11.XGetMotionEvents(__VA_ARGS__)
#define XGetOCValues(...)                     libX11.XGetOCValues(__VA_ARGS__)
#define XGetOMValues(...)                     libX11.XGetOMValues(__VA_ARGS__)
#define XGetPointerControl(...)               libX11.XGetPointerControl(__VA_ARGS__)
#define XGetPointerMapping(...)               libX11.XGetPointerMapping(__VA_ARGS__)
#define XGetScreenSaver(...)                  libX11.XGetScreenSaver(__VA_ARGS__)
#define XGetSelectionOwner(...)               libX11.XGetSelectionOwner(__VA_ARGS__)
#define XGetSubImage(...)                     libX11.XGetSubImage(__VA_ARGS__)
#define XGetTransientForHint(...)             libX11.XGetTransientForHint(__VA_ARGS__)
#define XGetWindowAttributes(...)             libX11.XGetWindowAttributes(__VA_ARGS__)
#define XGetWindowProperty(...)               libX11.XGetWindowProperty(__VA_ARGS__)
#define XGetWMColormapWindows(...)            libX11.XGetWMColormapWindows(__VA_ARGS__)
#define XGetWMProtocols(...)                  libX11.XGetWMProtocols(__VA_ARGS__)
#define XGrabButton(...)                      libX11.XGrabButton(__VA_ARGS__)
#define XGrabKey(...)                         libX11.XGrabKey(__VA_ARGS__)
#define XGrabKeyboard(...)                    libX11.XGrabKeyboard(__VA_ARGS__)
#define XGrabPointer(...)                     libX11.XGrabPointer(__VA_ARGS__)
#define XGrabServer(...)                      libX11.XGrabServer(__VA_ARGS__)
#define XHeightMMOfScreen(...)                libX11.XHeightMMOfScreen(__VA_ARGS__)
#define XHeightOfScreen(...)                  libX11.XHeightOfScreen(__VA_ARGS__)
#define XIconifyWindow(...)                   libX11.XIconifyWindow(__VA_ARGS__)
#define XIfEvent(...)                         libX11.XIfEvent(__VA_ARGS__)
#define XImageByteOrder(...)                  libX11.XImageByteOrder(__VA_ARGS__)
#define XIMOfIC(...)                          libX11.XIMOfIC(__VA_ARGS__)
#define XInitExtension(...)                   libX11.XInitExtension(__VA_ARGS__)
#define XInitImage(...)                       libX11.XInitImage(__VA_ARGS__)
#define XInitThreads(...)                     libX11.XInitThreads(__VA_ARGS__)
#define XInsertModifiermapEntry(...)          libX11.XInsertModifiermapEntry(__VA_ARGS__)
#define XInstallColormap(...)                 libX11.XInstallColormap(__VA_ARGS__)
#define XInternalConnectionNumbers(...)       libX11.XInternalConnectionNumbers(__VA_ARGS__)
#define XInternAtom(...)                      libX11.XInternAtom(__VA_ARGS__)
#define XInternAtoms(...)                     libX11.XInternAtoms(__VA_ARGS__)
#define XKeycodeToKeysym(...)                 libX11.XKeycodeToKeysym(__VA_ARGS__)
#define XKeysymToKeycode(...)                 libX11.XKeysymToKeycode(__VA_ARGS__)
#define XKeysymToString(...)                  libX11.XKeysymToString(__VA_ARGS__)
#define XKillClient(...)                      libX11.XKillClient(__VA_ARGS__)
#define XLastKnownRequestProcessed(...)       libX11.XLastKnownRequestProcessed(__VA_ARGS__)
#define XListDepths(...)                      libX11.XListDepths(__VA_ARGS__)
#define XListExtensions(...)                  libX11.XListExtensions(__VA_ARGS__)
#define XListFonts(...)                       libX11.XListFonts(__VA_ARGS__)
#define XListFontsWithInfo(...)               libX11.XListFontsWithInfo(__VA_ARGS__)
#define XListHosts(...)                       libX11.XListHosts(__VA_ARGS__)
#define XListInstalledColormaps(...)          libX11.XListInstalledColormaps(__VA_ARGS__)
#define XListPixmapFormats(...)               libX11.XListPixmapFormats(__VA_ARGS__)
#define XListProperties(...)                  libX11.XListProperties(__VA_ARGS__)
#define XLoadFont(...)                        libX11.XLoadFont(__VA_ARGS__)
#define XLoadQueryFont(...)                   libX11.XLoadQueryFont(__VA_ARGS__)
#define XLocaleOfFontSet(...)                 libX11.XLocaleOfFontSet(__VA_ARGS__)
#define XLocaleOfIM(...)                      libX11.XLocaleOfIM(__VA_ARGS__)
#define XLocaleOfOM(...)                      libX11.XLocaleOfOM(__VA_ARGS__)
#define XLockDisplay(...)                     libX11.XLockDisplay(__VA_ARGS__)
#define XLookupColor(...)                     libX11.XLookupColor(__VA_ARGS__)
#define XLookupKeysym(...)                    libX11.XLookupKeysym(__VA_ARGS__)
#define XLowerWindow(...)                     libX11.XLowerWindow(__VA_ARGS__)
#define XMapRaised(...)                       libX11.XMapRaised(__VA_ARGS__)
#define XMapSubwindows(...)                   libX11.XMapSubwindows(__VA_ARGS__)
#define XMapWindow(...)                       libX11.XMapWindow(__VA_ARGS__)
#define XMaskEvent(...)                       libX11.XMaskEvent(__VA_ARGS__)
#define XMaxCmapsOfScreen(...)                libX11.XMaxCmapsOfScreen(__VA_ARGS__)
#define XMaxRequestSize(...)                  libX11.XMaxRequestSize(__VA_ARGS__)
#define XmbDrawImageString(...)               libX11.XmbDrawImageString(__VA_ARGS__)
#define XmbDrawString(...)                    libX11.XmbDrawString(__VA_ARGS__)
#define XmbDrawText(...)                      libX11.XmbDrawText(__VA_ARGS__)
#define XmbLookupString(...)                  libX11.XmbLookupString(__VA_ARGS__)
#define XmbResetIC(...)                       libX11.XmbResetIC(__VA_ARGS__)
#define XmbTextEscapement(...)                libX11.XmbTextEscapement(__VA_ARGS__)
#define XmbTextExtents(...)                   libX11.XmbTextExtents(__VA_ARGS__)
#define XmbTextPerCharExtents(...)            libX11.XmbTextPerCharExtents(__VA_ARGS__)
#define XMinCmapsOfScreen(...)                libX11.XMinCmapsOfScreen(__VA_ARGS__)
#define XMoveResizeWindow(...)                libX11.XMoveResizeWindow(__VA_ARGS__)
#define XMoveWindow(...)                      libX11.XMoveWindow(__VA_ARGS__)
#define XNewModifiermap(...)                  libX11.XNewModifiermap(__VA_ARGS__)
#define XNextEvent(...)                       libX11.XNextEvent(__VA_ARGS__)
#define XNextRequest(...)                     libX11.XNextRequest(__VA_ARGS__)
#define XNoOp(...)                            libX11.XNoOp(__VA_ARGS__)
#define XOMOfOC(...)                          libX11.XOMOfOC(__VA_ARGS__)
#define XOpenDisplay(...)                     libX11.XOpenDisplay(__VA_ARGS__)
#define XOpenIM(...)                          libX11.XOpenIM(__VA_ARGS__)
#define XOpenOM(...)                          libX11.XOpenOM(__VA_ARGS__)
#define XParseColor(...)                      libX11.XParseColor(__VA_ARGS__)
#define XParseGeometry(...)                   libX11.XParseGeometry(__VA_ARGS__)
#define XPeekEvent(...)                       libX11.XPeekEvent(__VA_ARGS__)
#define XPeekIfEvent(...)                     libX11.XPeekIfEvent(__VA_ARGS__)
#define XPending(...)                         libX11.XPending(__VA_ARGS__)
#define XPlanesOfScreen(...)                  libX11.XPlanesOfScreen(__VA_ARGS__)
#define XProcessInternalConnection(...)       libX11.XProcessInternalConnection(__VA_ARGS__)
#define XProtocolRevision(...)                libX11.XProtocolRevision(__VA_ARGS__)
#define XProtocolVersion(...)                 libX11.XProtocolVersion(__VA_ARGS__)
#define XPutBackEvent(...)                    libX11.XPutBackEvent(__VA_ARGS__)
#define XPutImage(...)                        libX11.XPutImage(__VA_ARGS__)
#define XQLength(...)                         libX11.XQLength(__VA_ARGS__)
#define XQueryBestCursor(...)                 libX11.XQueryBestCursor(__VA_ARGS__)
#define XQueryBestSize(...)                   libX11.XQueryBestSize(__VA_ARGS__)
#define XQueryBestStipple(...)                libX11.XQueryBestStipple(__VA_ARGS__)
#define XQueryBestTile(...)                   libX11.XQueryBestTile(__VA_ARGS__)
#define XQueryColor(...)                      libX11.XQueryColor(__VA_ARGS__)
#define XQueryColors(...)                     libX11.XQueryColors(__VA_ARGS__)
#define XQueryExtension(...)                  libX11.XQueryExtension(__VA_ARGS__)
#define XQueryFont(...)                       libX11.XQueryFont(__VA_ARGS__)
#define XQueryKeymap(...)                     libX11.XQueryKeymap(__VA_ARGS__)
#define XQueryPointer(...)                    libX11.XQueryPointer(__VA_ARGS__)
#define XQueryTextExtents(...)                libX11.XQueryTextExtents(__VA_ARGS__)
#define XQueryTextExtents16(...)              libX11.XQueryTextExtents16(__VA_ARGS__)
#define XQueryTree(...)                       libX11.XQueryTree(__VA_ARGS__)
#define XRaiseWindow(...)                     libX11.XRaiseWindow(__VA_ARGS__)
#define XReadBitmapFile(...)                  libX11.XReadBitmapFile(__VA_ARGS__)
#define XReadBitmapFileData(...)              libX11.XReadBitmapFileData(__VA_ARGS__)
#define XRebindKeysym(...)                    libX11.XRebindKeysym(__VA_ARGS__)
#define XRecolorCursor(...)                   libX11.XRecolorCursor(__VA_ARGS__)
#define XReconfigureWMWindow(...)             libX11.XReconfigureWMWindow(__VA_ARGS__)
#define XRefreshKeyboardMapping(...)          libX11.XRefreshKeyboardMapping(__VA_ARGS__)
#define XRegisterIMInstantiateCallback(...)   libX11.XRegisterIMInstantiateCallback(__VA_ARGS__)
#define XRemoveConnectionWatch(...)           libX11.XRemoveConnectionWatch(__VA_ARGS__)
#define XRemoveFromSaveSet(...)               libX11.XRemoveFromSaveSet(__VA_ARGS__)
#define XRemoveHost(...)                      libX11.XRemoveHost(__VA_ARGS__)
#define XRemoveHosts(...)                     libX11.XRemoveHosts(__VA_ARGS__)
#define XReparentWindow(...)                  libX11.XReparentWindow(__VA_ARGS__)
#define XResetScreenSaver(...)                libX11.XResetScreenSaver(__VA_ARGS__)
#define XResizeWindow(...)                    libX11.XResizeWindow(__VA_ARGS__)
#define XResourceManagerString(...)           libX11.XResourceManagerString(__VA_ARGS__)
#define XRestackWindows(...)                  libX11.XRestackWindows(__VA_ARGS__)
#define XrmInitialize(...)                    libX11.XrmInitialize(__VA_ARGS__)
#define XrmUniqueQuark(...)                   libX11.XrmUniqueQuark(__VA_ARGS__)
#define XRootWindow(...)                      libX11.XRootWindow(__VA_ARGS__)
#define XRootWindowOfScreen(...)              libX11.XRootWindowOfScreen(__VA_ARGS__)
#define XRotateBuffers(...)                   libX11.XRotateBuffers(__VA_ARGS__)
#define XRotateWindowProperties(...)          libX11.XRotateWindowProperties(__VA_ARGS__)
#define XScreenCount(...)                     libX11.XScreenCount(__VA_ARGS__)
#define XScreenNumberOfScreen(...)            libX11.XScreenNumberOfScreen(__VA_ARGS__)
#define XScreenOfDisplay(...)                 libX11.XScreenOfDisplay(__VA_ARGS__)
#define XScreenResourceString(...)            libX11.XScreenResourceString(__VA_ARGS__)
#define XSelectInput(...)                     libX11.XSelectInput(__VA_ARGS__)
#define XSendEvent(...)                       libX11.XSendEvent(__VA_ARGS__)
#define XServerVendor(...)                    libX11.XServerVendor(__VA_ARGS__)
#define XSetAccessControl(...)                libX11.XSetAccessControl(__VA_ARGS__)
#define XSetArcMode(...)                      libX11.XSetArcMode(__VA_ARGS__)
#define XSetAuthorization(...)                libX11.XSetAuthorization(__VA_ARGS__)
#define XSetBackground(...)                   libX11.XSetBackground(__VA_ARGS__)
#define XSetClipMask(...)                     libX11.XSetClipMask(__VA_ARGS__)
#define XSetClipOrigin(...)                   libX11.XSetClipOrigin(__VA_ARGS__)
#define XSetClipRectangles(...)               libX11.XSetClipRectangles(__VA_ARGS__)
#define XSetCloseDownMode(...)                libX11.XSetCloseDownMode(__VA_ARGS__)
#define XSetCommand(...)                      libX11.XSetCommand(__VA_ARGS__)
#define XSetDashes(...)                       libX11.XSetDashes(__VA_ARGS__)
#define XSetErrorHandler(...)                 libX11.XSetErrorHandler(__VA_ARGS__)
#define XSetFillRule(...)                     libX11.XSetFillRule(__VA_ARGS__)
#define XSetFillStyle(...)                    libX11.XSetFillStyle(__VA_ARGS__)
#define XSetFont(...)                         libX11.XSetFont(__VA_ARGS__)
#define XSetFontPath(...)                     libX11.XSetFontPath(__VA_ARGS__)
#define XSetForeground(...)                   libX11.XSetForeground(__VA_ARGS__)
#define XSetFunction(...)                     libX11.XSetFunction(__VA_ARGS__)
#define XSetGraphicsExposures(...)            libX11.XSetGraphicsExposures(__VA_ARGS__)
#define XSetICFocus(...)                      libX11.XSetICFocus(__VA_ARGS__)
#define XSetIconName(...)                     libX11.XSetIconName(__VA_ARGS__)
#define XSetICValues(...)                     libX11.XSetICValues(__VA_ARGS__)
#define XSetIMValues(...)                     libX11.XSetIMValues(__VA_ARGS__)
#define XSetInputFocus(...)                   libX11.XSetInputFocus(__VA_ARGS__)
#define XSetIOErrorExitHandler(...)           libX11.XSetIOErrorExitHandler(__VA_ARGS__)
#define XSetIOErrorHandler(...)               libX11.XSetIOErrorHandler(__VA_ARGS__)
#define XSetLineAttributes(...)               libX11.XSetLineAttributes(__VA_ARGS__)
#define XSetLocaleModifiers(...)              libX11.XSetLocaleModifiers(__VA_ARGS__)
#define XSetModifierMapping(...)              libX11.XSetModifierMapping(__VA_ARGS__)
#define XSetOCValues(...)                     libX11.XSetOCValues(__VA_ARGS__)
#define XSetOMValues(...)                     libX11.XSetOMValues(__VA_ARGS__)
#define XSetPlaneMask(...)                    libX11.XSetPlaneMask(__VA_ARGS__)
#define XSetPointerMapping(...)               libX11.XSetPointerMapping(__VA_ARGS__)
#define XSetScreenSaver(...)                  libX11.XSetScreenSaver(__VA_ARGS__)
#define XSetSelectionOwner(...)               libX11.XSetSelectionOwner(__VA_ARGS__)
#define XSetState(...)                        libX11.XSetState(__VA_ARGS__)
#define XSetStipple(...)                      libX11.XSetStipple(__VA_ARGS__)
#define XSetSubwindowMode(...)                libX11.XSetSubwindowMode(__VA_ARGS__)
#define XSetTile(...)                         libX11.XSetTile(__VA_ARGS__)
#define XSetTransientForHint(...)             libX11.XSetTransientForHint(__VA_ARGS__)
#define XSetTSOrigin(...)                     libX11.XSetTSOrigin(__VA_ARGS__)
#define XSetWindowBackground(...)             libX11.XSetWindowBackground(__VA_ARGS__)
#define XSetWindowBackgroundPixmap(...)       libX11.XSetWindowBackgroundPixmap(__VA_ARGS__)
#define XSetWindowBorder(...)                 libX11.XSetWindowBorder(__VA_ARGS__)
#define XSetWindowBorderPixmap(...)           libX11.XSetWindowBorderPixmap(__VA_ARGS__)
#define XSetWindowBorderWidth(...)            libX11.XSetWindowBorderWidth(__VA_ARGS__)
#define XSetWindowColormap(...)               libX11.XSetWindowColormap(__VA_ARGS__)
#define XSetWMColormapWindows(...)            libX11.XSetWMColormapWindows(__VA_ARGS__)
#define XSetWMProtocols(...)                  libX11.XSetWMProtocols(__VA_ARGS__)
#define XStoreBuffer(...)                     libX11.XStoreBuffer(__VA_ARGS__)
#define XStoreBytes(...)                      libX11.XStoreBytes(__VA_ARGS__)
#define XStoreColor(...)                      libX11.XStoreColor(__VA_ARGS__)
#define XStoreColors(...)                     libX11.XStoreColors(__VA_ARGS__)
#define XStoreName(...)                       libX11.XStoreName(__VA_ARGS__)
#define XStoreNamedColor(...)                 libX11.XStoreNamedColor(__VA_ARGS__)
#define XStringToKeysym(...)                  libX11.XStringToKeysym(__VA_ARGS__)
#define XSupportsLocale(...)                  libX11.XSupportsLocale(__VA_ARGS__)
#define XSync(...)                            libX11.XSync(__VA_ARGS__)
#define XTextExtents(...)                     libX11.XTextExtents(__VA_ARGS__)
#define XTextExtents16(...)                   libX11.XTextExtents16(__VA_ARGS__)
#define XTextWidth(...)                       libX11.XTextWidth(__VA_ARGS__)
#define XTextWidth16(...)                     libX11.XTextWidth16(__VA_ARGS__)
#define XTranslateCoordinates(...)            libX11.XTranslateCoordinates(__VA_ARGS__)
#define XUndefineCursor(...)                  libX11.XUndefineCursor(__VA_ARGS__)
#define XUngrabButton(...)                    libX11.XUngrabButton(__VA_ARGS__)
#define XUngrabKey(...)                       libX11.XUngrabKey(__VA_ARGS__)
#define XUngrabKeyboard(...)                  libX11.XUngrabKeyboard(__VA_ARGS__)
#define XUngrabPointer(...)                   libX11.XUngrabPointer(__VA_ARGS__)
#define XUngrabServer(...)                    libX11.XUngrabServer(__VA_ARGS__)
#define XUninstallColormap(...)               libX11.XUninstallColormap(__VA_ARGS__)
#define XUnloadFont(...)                      libX11.XUnloadFont(__VA_ARGS__)
#define XUnlockDisplay(...)                   libX11.XUnlockDisplay(__VA_ARGS__)
#define XUnmapSubwindows(...)                 libX11.XUnmapSubwindows(__VA_ARGS__)
#define XUnmapWindow(...)                     libX11.XUnmapWindow(__VA_ARGS__)
#define XUnregisterIMInstantiateCallback(...) libX11.XUnregisterIMInstantiateCallback(__VA_ARGS__)
#define XUnsetICFocus(...)                    libX11.XUnsetICFocus(__VA_ARGS__)
#define Xutf8DrawImageString(...)             libX11.Xutf8DrawImageString(__VA_ARGS__)
#define Xutf8DrawString(...)                  libX11.Xutf8DrawString(__VA_ARGS__)
#define Xutf8DrawText(...)                    libX11.Xutf8DrawText(__VA_ARGS__)
#define Xutf8LookupString(...)                libX11.Xutf8LookupString(__VA_ARGS__)
#define Xutf8ResetIC(...)                     libX11.Xutf8ResetIC(__VA_ARGS__)
#define Xutf8TextEscapement(...)              libX11.Xutf8TextEscapement(__VA_ARGS__)
#define Xutf8TextExtents(...)                 libX11.Xutf8TextExtents(__VA_ARGS__)
#define Xutf8TextPerCharExtents(...)          libX11.Xutf8TextPerCharExtents(__VA_ARGS__)
#define XVaCreateNestedList(...)              libX11.XVaCreateNestedList(__VA_ARGS__)
#define XVendorRelease(...)                   libX11.XVendorRelease(__VA_ARGS__)
#define XVisualIDFromVisual(...)              libX11.XVisualIDFromVisual(__VA_ARGS__)
#define XWarpPointer(...)                     libX11.XWarpPointer(__VA_ARGS__)
#define XwcDrawImageString(...)               libX11.XwcDrawImageString(__VA_ARGS__)
#define XwcDrawString(...)                    libX11.XwcDrawString(__VA_ARGS__)
#define XwcDrawText(...)                      libX11.XwcDrawText(__VA_ARGS__)
#define XwcLookupString(...)                  libX11.XwcLookupString(__VA_ARGS__)
#define XwcResetIC(...)                       libX11.XwcResetIC(__VA_ARGS__)
#define XwcTextEscapement(...)                libX11.XwcTextEscapement(__VA_ARGS__)
#define XwcTextExtents(...)                   libX11.XwcTextExtents(__VA_ARGS__)
#define XwcTextPerCharExtents(...)            libX11.XwcTextPerCharExtents(__VA_ARGS__)
#define XWhitePixel(...)                      libX11.XWhitePixel(__VA_ARGS__)
#define XWhitePixelOfScreen(...)              libX11.XWhitePixelOfScreen(__VA_ARGS__)
#define XWidthMMOfScreen(...)                 libX11.XWidthMMOfScreen(__VA_ARGS__)
#define XWidthOfScreen(...)                   libX11.XWidthOfScreen(__VA_ARGS__)
#define XWindowEvent(...)                     libX11.XWindowEvent(__VA_ARGS__)
#define XWithdrawWindow(...)                  libX11.XWithdrawWindow(__VA_ARGS__)
#define XWriteBitmapFile(...)                 libX11.XWriteBitmapFile(__VA_ARGS__)

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif//_core_linux_libX11_Xlib_h_