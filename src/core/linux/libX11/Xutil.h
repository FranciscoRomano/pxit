// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE.                       │
// └───────────────────────────────────────────────────────────────────────────────────────────┘

#ifndef _core_linux_libX11_Xutil_h_
#define _core_linux_libX11_Xutil_h_

// You must include <X11/Xlib.h> before including this file
#include "Xlib.h"
#include "keysym.h"
#include <stdint.h>

// The Xlib structs are full of implicit padding to properly align members
// We can't clean that up without breaking ABI, so tell clang not to bother complaining about it
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

#define AllValues                  0x000F      // Bitmask returned by XParseGeometry()
#define BitmapFileInvalid          2           // Return code for XReadBitmapFile and XWriteBitmapFile
#define BitmapNoMemory             3           // Return code for XReadBitmapFile and XWriteBitmapFile
#define BitmapOpenFailed           1           // Return code for XReadBitmapFile and XWriteBitmapFile
#define BitmapSuccess              0           // Return code for XReadBitmapFile and XWriteBitmapFile
#define HeightValue                0x0008      // Bitmask returned by XParseGeometry()
#define IconicState                3           // application wants to start as an icon
#define IconMaskHint               (1L << 5)   // definition for flags of XWMHints
#define IconPixmapHint             (1L << 2)   // definition for flags of XWMHints
#define IconPositionHint           (1L << 4)   // definition for flags of XWMHints
#define IconWindowHint             (1L << 3)   // definition for flags of XWMHints
#define InputHint                  (1L << 0)   // definition for flags of XWMHints
#define NormalState                1           // most applications want to start this way
#define NoValue                    0x0000      // Bitmask returned by XParseGeometry()
#define PAspect                    (1L << 7)   // program specified min and max aspect ratios
#define PBaseSize                  (1L << 8)   // program specified base for incrementing
#define PMaxSize                   (1L << 5)   // program specified maximum size
#define PMinSize                   (1L << 4)   // program specified minimum size
#define PPosition                  (1L << 2)   // program specified position
#define PResizeInc                 (1L << 6)   // program specified resize increments
#define PSize                      (1L << 3)   // program specified size
#define PWinGravity                (1L << 9)   // program specified window gravity
#define RectangleIn                1           // Return value from XRectInRegion()
#define RectangleOut               0           // Return value from XRectInRegion()
#define RectanglePart              2           // Return value from XRectInRegion()
#define ReleaseByFreeingColormap   ((XID) 1L)  // for killid field
#define StateHint                  (1L << 1)   // definition for flags of XWMHints
#define USPosition                 (1L << 0)   // user specified x, y
#define USSize                     (1L << 1)   // user specified width, height
#define VisualAllMask              0x1FF       // ???
#define VisualBitsPerRGBMask       0x100       // ???
#define VisualBlueMaskMask         0x40        // ???
#define VisualClassMask            0x8         // ???
#define VisualColormapSizeMask     0x80        // ???
#define VisualDepthMask            0x4         // ???
#define VisualGreenMaskMask        0x20        // ???
#define VisualIDMask               0x1         // ???
#define VisualNoMask               0x0         // ???
#define VisualRedMaskMask          0x10        // ???
#define VisualScreenMask           0x2         // ???
#define WidthValue                 0x0004      // Bitmask returned by XParseGeometry()
#define WindowGroupHint            (1L << 6)   // definition for flags of XWMHints
#define WithdrawnState             0           // for windows that are not mapped
#define XCNOENT                    2           // Context management associative lookup table return codes - No entry in table
#define XCNOMEM                    1           // Context management associative lookup table return codes - Out of memory
#define XConverterNotFound         -3          // ???
#define XCSUCCESS                  0           // Context management associative lookup table return codes - No error
#define XLocaleNotSupported        -2          // ???
#define XNegative                  0x0010      // Bitmask returned by XParseGeometry()
#define XNoMemory                  -1          // ???
#define XUrgencyHint               (1L << 8)   // definition for flags of XWMHints
#define XValue                     0x0001      // Bitmask returned by XParseGeometry()
#define YNegative                  0x0020      // Bitmask returned by XParseGeometry()
#define YValue                     0x0002      // Bitmask returned by XParseGeometry()
#define IsCursorKey(keysym)        (((XKeySym)(keysym) >= XK_Home)     && ((XKeySym)(keysym) <  XK_Select))
#define IsFunctionKey(keysym)      (((XKeySym)(keysym) >= XK_F1)       && ((XKeySym)(keysym) <= XK_F35))
#define IsKeypadKey(keysym)        (((XKeySym)(keysym) >= XK_KP_Space) && ((XKeySym)(keysym) <= XK_KP_Equal))
#define IsMiscFunctionKey(keysym)  (((XKeySym)(keysym) >= XK_Select)   && ((XKeySym)(keysym) <= XK_Break))
#define IsModifierKey(keysym)      ((((XKeySym)(keysym) >= XK_Shift_L) && ((XKeySym)(keysym) <= XK_Hyper_R)) || (((XKeySym)(keysym) >= XK_ISO_Lock) && ((XKeySym)(keysym) <= XK_ISO_Level5_Lock)) || ((XKeySym)(keysym) == XK_Mode_switch) || ((XKeySym)(keysym) == XK_Num_Lock))
#define IsPFKey(keysym)            (((XKeySym)(keysym) >= XK_KP_F1)    && ((XKeySym)(keysym) <= XK_KP_F4))
#define IsPrivateKeypadKey(keysym) (((XKeySym)(keysym) >= 0x11000000)  && ((XKeySym)(keysym) <= 0x1100FFFF))
#define XStringToContext(string)   ((XContext)XrmStringToQuark(string))
#define XUniqueContext()           ((XContext)XrmUniqueQuark())

typedef struct XClassHint          XClassHint;
typedef struct XComposeStatus      XComposeStatus;
typedef int32_t                    XContext;
typedef struct XIconSize           XIconSize;
typedef enum XICCEncodingStyle     XICCEncodingStyle;
typedef struct XRegion_t*          XRegion;
typedef struct XSizeHints          XSizeHints;
typedef struct XStandardColormap   XStandardColormap;
typedef struct XTextProperty       XTextProperty;
typedef struct XVisualInfo         XVisualInfo;
typedef struct XWMHints            XWMHints;

typedef enum XICCEncodingStyle {
    XStringStyle,                            // STRING
    XCompoundTextStyle,                      // COMPOUND_TEXT
    XTextStyle,                              // text in owner's encoding (current locale)
    XStdICCTextStyle,                        // STRING, else COMPOUND_TEXT
    XUTF8StringStyle                         // UTF8_STRING
} XICCEncodingStyle;

typedef struct XSizeHints {
    int64_t                   flags;         // marks which fields in this structure are defined
    int32_t                   x;             // obsolete for new window mgrs, but clients
    int32_t                   y;             // obsolete for new window mgrs, but clients
    int32_t                   width;         // should set so old wm's don't mess up
    int32_t                   height;        // should set so old wm's don't mess up
    int32_t                   min_width;     // ??
    int32_t                   min_height;    // ??
    int32_t                   max_width;     // ??
    int32_t                   max_height;    // ??
    int32_t                   width_inc;     // ??
    int32_t                   height_inc;    // ??
    struct { int32_t x,  y; } min_aspect;    // x: numerator, y: denominator
    struct { int32_t x,  y; } max_aspect;    // x: numerator, y: denominator
    int32_t                   base_width;    // added by ICCCM version 1
    int32_t                   base_height;   // added by ICCCM version 1
    int32_t                   win_gravity;   // added by ICCCM version 1
} XSizeHints;

typedef struct XWMHints {
    int64_t                   flags;         // marks which fields in this structure are defined
    int                       input;         // does this application rely on the window manager to get keyboard input?
    int32_t                   initial_state; // see below
    XPixmap                   icon_pixmap;   // pixmap to be used as icon
    XWindow                   icon_window;   // window to be used as icon
    int32_t                   icon_x;        // initial position of icon
    int32_t                   icon_y;        // initial position of icon
    XPixmap                   icon_mask;     // icon mask bitmap
    XID                       window_group;  // id of related window group
} XWMHints;

typedef struct XTextProperty {
    uint8_t*                  value;         // same as Property routines
    XAtom                     encoding;      // prop type
    int32_t                   format;        // prop data format: 8, 16, or 32
    uint64_t                  nitems;        // number of data items in value
} XTextProperty;

typedef struct XIconSize {
    int32_t                   min_width;     // ???
    int32_t                   min_height;    // ???
    int32_t                   max_width;     // ???
    int32_t                   max_height;    // ???
    int32_t                   width_inc;     // ???
    int32_t                   height_inc;    // ???
} XIconSize;

typedef struct XClassHint {
    char*                     res_name;      // ???
    char*                     res_class;     // ???
} XClassHint;

typedef struct XComposeStatus {
    void*                     compose_ptr;   // state table pointer
    int32_t                   chars_matched; // match state
} XComposeStatus;

typedef struct XVisualInfo {
  XVisual*                    visual;        // ???
  XVisualID                   visualid;      // ???
  int32_t                     screen;        // ???
  int32_t                     depth;         // ???
  int32_t                     c_class;       // ???
  uint64_t                    red_mask;      // ???
  uint64_t                    green_mask;    // ???
  uint64_t                    blue_mask;     // ???
  int32_t                     colormap_size; // ???
  int32_t                     bits_per_rgb;  // ???
} XVisualInfo;

typedef struct XStandardColormap {
    XColormap                 colormap;      // ???
    uint64_t                  red_max;       // ???
    uint64_t                  red_mult;      // ???
    uint64_t                  green_max;     // ???
    uint64_t                  green_mult;    // ???
    uint64_t                  blue_max;      // ???
    uint64_t                  blue_mult;     // ???
    uint64_t                  base_pixel;    // ???
    XVisualID                 visualid;      // added by ICCCM version 1
    XID                       killid;        // added by ICCCM version 1
} XStandardColormap;

#define XDestroyImage(...)               libX11.XDestroyImage(__VA_ARGS__)
#define XGetPixel(...)                   libX11.XGetPixel(__VA_ARGS__)
#define XPutPixel(...)                   libX11.XPutPixel(__VA_ARGS__)
#define XSubImage(...)                   libX11.XSubImage(__VA_ARGS__)
#define XAddPixel(...)                   libX11.XAddPixel(__VA_ARGS__)
#define XAllocClassHint(...)             libX11.XAllocClassHint(__VA_ARGS__)
#define XAllocIconSize(...)              libX11.XAllocIconSize(__VA_ARGS__)
#define XAllocSizeHints(...)             libX11.XAllocSizeHints(__VA_ARGS__)
#define XAllocStandardColormap(...)      libX11.XAllocStandardColormap(__VA_ARGS__)
#define XAllocWMHints(...)               libX11.XAllocWMHints(__VA_ARGS__)
#define XClipBox(...)                    libX11.XClipBox(__VA_ARGS__)
#define XCreateRegion(...)               libX11.XCreateRegion(__VA_ARGS__)
#define XDefaultString(...)              libX11.XDefaultString(__VA_ARGS__)
#define XDeleteContext(...)              libX11.XDeleteContext(__VA_ARGS__)
#define XDestroyRegion(...)              libX11.XDestroyRegion(__VA_ARGS__)
#define XEmptyRegion(...)                libX11.XEmptyRegion(__VA_ARGS__)
#define XEqualRegion(...)                libX11.XEqualRegion(__VA_ARGS__)
#define XFindContext(...)                libX11.XFindContext(__VA_ARGS__)
#define XGetClassHint(...)               libX11.XGetClassHint(__VA_ARGS__)
#define XGetIconSizes(...)               libX11.XGetIconSizes(__VA_ARGS__)
#define XGetNormalHints(...)             libX11.XGetNormalHints(__VA_ARGS__)
#define XGetRGBColormaps(...)            libX11.XGetRGBColormaps(__VA_ARGS__)
#define XGetSizeHints(...)               libX11.XGetSizeHints(__VA_ARGS__)
#define XGetStandardColormap(...)        libX11.XGetStandardColormap(__VA_ARGS__)
#define XGetTextProperty(...)            libX11.XGetTextProperty(__VA_ARGS__)
#define XGetVisualInfo(...)              libX11.XGetVisualInfo(__VA_ARGS__)
#define XGetWMClientMachine(...)         libX11.XGetWMClientMachine(__VA_ARGS__)
#define XGetWMHints(...)                 libX11.XGetWMHints(__VA_ARGS__)
#define XGetWMIconName(...)              libX11.XGetWMIconName(__VA_ARGS__)
#define XGetWMName(...)                  libX11.XGetWMName(__VA_ARGS__)
#define XGetWMNormalHints(...)           libX11.XGetWMNormalHints(__VA_ARGS__)
#define XGetWMSizeHints(...)             libX11.XGetWMSizeHints(__VA_ARGS__)
#define XGetZoomHints(...)               libX11.XGetZoomHints(__VA_ARGS__)
#define XIntersectRegion(...)            libX11.XIntersectRegion(__VA_ARGS__)
#define XConvertCase(...)                libX11.XConvertCase(__VA_ARGS__)
#define XLookupString(...)               libX11.XLookupString(__VA_ARGS__)
#define XMatchVisualInfo(...)            libX11.XMatchVisualInfo(__VA_ARGS__)
#define XOffsetRegion(...)               libX11.XOffsetRegion(__VA_ARGS__)
#define XPointInRegion(...)              libX11.XPointInRegion(__VA_ARGS__)
#define XPolygonRegion(...)              libX11.XPolygonRegion(__VA_ARGS__)
#define XRectInRegion(...)               libX11.XRectInRegion(__VA_ARGS__)
#define XSaveContext(...)                libX11.XSaveContext(__VA_ARGS__)
#define XSetClassHint(...)               libX11.XSetClassHint(__VA_ARGS__)
#define XSetIconSizes(...)               libX11.XSetIconSizes(__VA_ARGS__)
#define XSetNormalHints(...)             libX11.XSetNormalHints(__VA_ARGS__)
#define XSetRGBColormaps(...)            libX11.XSetRGBColormaps(__VA_ARGS__)
#define XSetSizeHints(...)               libX11.XSetSizeHints(__VA_ARGS__)
#define XSetStandardProperties(...)      libX11.XSetStandardProperties(__VA_ARGS__)
#define XSetTextProperty(...)            libX11.XSetTextProperty(__VA_ARGS__)
#define XSetWMClientMachine(...)         libX11.XSetWMClientMachine(__VA_ARGS__)
#define XSetWMHints(...)                 libX11.XSetWMHints(__VA_ARGS__)
#define XSetWMIconName(...)              libX11.XSetWMIconName(__VA_ARGS__)
#define XSetWMName(...)                  libX11.XSetWMName(__VA_ARGS__)
#define XSetWMNormalHints(...)           libX11.XSetWMNormalHints(__VA_ARGS__)
#define XSetWMProperties(...)            libX11.XSetWMProperties(__VA_ARGS__)
#define XmbSetWMProperties(...)          libX11.XmbSetWMProperties(__VA_ARGS__)
#define Xutf8SetWMProperties(...)        libX11.Xutf8SetWMProperties(__VA_ARGS__)
#define XSetWMSizeHints(...)             libX11.XSetWMSizeHints(__VA_ARGS__)
#define XSetRegion(...)                  libX11.XSetRegion(__VA_ARGS__)
#define XSetStandardColormap(...)        libX11.XSetStandardColormap(__VA_ARGS__)
#define XSetZoomHints(...)               libX11.XSetZoomHints(__VA_ARGS__)
#define XShrinkRegion(...)               libX11.XShrinkRegion(__VA_ARGS__)
#define XStringListToTextProperty(...)   libX11.XStringListToTextProperty(__VA_ARGS__)
#define XSubtractRegion(...)             libX11.XSubtractRegion(__VA_ARGS__)
#define XmbTextListToTextProperty(...)   libX11.XmbTextListToTextProperty(__VA_ARGS__)
#define XwcTextListToTextProperty(...)   libX11.XwcTextListToTextProperty(__VA_ARGS__)
#define Xutf8TextListToTextProperty(...) libX11.Xutf8TextListToTextProperty(__VA_ARGS__)
#define XwcFreeStringList(...)           libX11.XwcFreeStringList(__VA_ARGS__)
#define XTextPropertyToStringList(...)   libX11.XTextPropertyToStringList(__VA_ARGS__)
#define XmbTextPropertyToTextList(...)   libX11.XmbTextPropertyToTextList(__VA_ARGS__)
#define XwcTextPropertyToTextList(...)   libX11.XwcTextPropertyToTextList(__VA_ARGS__)
#define Xutf8TextPropertyToTextList(...) libX11.Xutf8TextPropertyToTextList(__VA_ARGS__)
#define XUnionRectWithRegion(...)        libX11.XUnionRectWithRegion(__VA_ARGS__)
#define XUnionRegion(...)                libX11.XUnionRegion(__VA_ARGS__)
#define XWMGeometry(...)                 libX11.XWMGeometry(__VA_ARGS__)
#define XXorRegion(...)                  libX11.XXorRegion(__VA_ARGS__)

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif//_core_linux_libX11_Xutil_h_