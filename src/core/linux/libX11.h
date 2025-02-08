// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_linux_libX11_h__
#define __core_linux_libX11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdint.h>
#include <stdbool.h>

#define AllocAll                  1
#define AllocNone                 0
#define Button1MotionMask        (1L<<8)
#define Button2MotionMask        (1L<<9)
#define Button3MotionMask        (1L<<10)
#define Button4MotionMask        (1L<<11)
#define Button5MotionMask        (1L<<12)
#define ButtonMotionMask         (1L<<13)
#define ButtonPress               4
#define ButtonPressMask          (1L<<2)
#define ButtonRelease             5
#define ButtonReleaseMask        (1L<<3)
#define CirculateNotify           26
#define CirculateRequest          27
#define ClientMessage             33
#define ColormapChangeMask       (1L<<23)
#define ColormapNotify            32
#define ConfigureNotify           22
#define ConfigureRequest          23
#define CopyFromParent            0L
#define CreateNotify              16
#define CWBackingPixel           (1L<<08)
#define CWBackingPlanes          (1L<<07)
#define CWBackingStore           (1L<<06)
#define CWBackPixel              (1L<<01)
#define CWBackPixmap             (1L<<00)
#define CWBitGravity             (1L<<04)
#define CWBorderPixel            (1L<<03)
#define CWBorderPixmap           (1L<<02)
#define CWColormap               (1L<<13)
#define CWCursor                 (1L<<14)
#define CWDontPropagate          (1L<<12)
#define CWEventMask              (1L<<11)
#define CWOverrideRedirect       (1L<<09)
#define CWSaveUnder              (1L<<10)
#define CWWinGravity             (1L<<05)
#define DestroyNotify             17
#define EnterNotify               7
#define EnterWindowMask          (1L<<4)
#define Expose                    12
#define ExposureMask             (1L<<15)
#define False                     0
#define FocusChangeMask          (1L<<21)
#define FocusIn                   9
#define FocusOut                  10
#define GenericEvent              35
#define GraphicsExpose            13
#define GravityNotify             24
#define KeymapNotify              11
#define KeymapStateMask          (1L<<14)
#define KeyPress                  2
#define KeyPressMask             (1L<<0)
#define KeyRelease                3
#define KeyReleaseMask           (1L<<1)
#define LASTEvent                 36
#define LeaveNotify               8
#define LeaveWindowMask          (1L<<5)
#define MapNotify                 19
#define MappingNotify             34
#define MapRequest                20
#define MotionNotify              6
#define NoEventMask               0L
#define NoExpose                  14
#define OwnerGrabButtonMask      (1L<<24)
#define PointerMotionHintMask    (1L<<7)
#define PointerMotionMask        (1L<<6)
#define PropertyChangeMask       (1L<<22)
#define PropertyNotify            28
#define ReparentNotify            21
#define ResizeRedirectMask       (1L<<18)
#define ResizeRequest             25
#define SelectionClear            29
#define SelectionNotify           31
#define SelectionRequest          30
#define StructureNotifyMask      (1L<<17)
#define SubstructureNotifyMask   (1L<<19)
#define SubstructureRedirectMask (1L<<20)
#define True                      1
#define UnmapNotify               18
#define VisibilityChangeMask     (1L<<16)
#define VisibilityNotify          15

typedef uint64_t                 XAtom;
typedef int                      XBool;
typedef uint64_t                 XColormap;
typedef int                      XContext;
typedef uint64_t                 XCursor;
typedef struct _XDepth           XDepth;
typedef struct _XDisplay         XDisplay;
typedef uint64_t                 XDrawable;
typedef struct _XExtData         XExtData;
typedef uint64_t                 XFont;
typedef struct _XGC              XGC;
typedef uint64_t                 XID;
typedef uint8_t                  XKeyCode;
typedef uint64_t                 XKeySym;
typedef uint64_t                 XPixmap;
typedef char*                    XPointer;
typedef struct _XPrivate         XPrivate;
typedef struct _XrmHashBucketRec XrmHashBucketRec;
typedef struct _XScreen          XScreen;
typedef struct _XScreenFormat    XScreenFormat;
typedef int                      XStatus;
typedef uint64_t                 XTime;
typedef struct _XVisual          XVisual;
typedef uint64_t                 XVisualID;
typedef struct _XVisualInfo      XVisualInfo;
typedef uint64_t                 XWindow;

struct _XDepth {
    int                    depth;                 // this depth (Z) of the depth.
    int                    nvisuals;              // number of Visual types at this depth.
    XVisual*               visuals;               // list of visuals possible at this depth.
};

struct _XDisplay {
    XExtData*              ext_data;              // hook for extension to hang data.
    XPrivate*              private1;              // ???
    int                    fd;                    // Network socket.
    int                    private2;              // ???
    int                    proto_major_version;   // major version of server's X protocol.
    int                    proto_minor_version;   // minor version of servers X protocol.
    char*                  vendor;                // vendor of the server hardware.
    XID                    private3;              // ???
    XID                    private4;              // ???
    XID                    private5;              // ???
    int                    private6;              // ???
    XID                  (*res_alloc)(XDisplay*); // resource allocator function.
    int                    byte_order;            // screen byte order, LSBFirst, MSBFirst.
    int                    bitmap_unit;           // padding and data requirements.
    int                    bitmap_pad;            // padding requirements on bitmaps.
    int                    bitmap_bit_order;      // LeastSignificant or MostSignificant.
    int                    nformats;              // number of pixmap formats in list.
    XScreenFormat*         pixmap_format;         // pixmap format list.
    int                    private8;              // ???
    int                    release;               // release of the server.
    XPrivate*              private9;              // ???
    XPrivate*              private10;             // ???
    int                    qlen;                  // Length of input event queue.
    uint64_t               last_request_read;     // seq number of last event read.
    uint64_t               request;               // sequence number of last request.
    XPointer               private11;             // ???
    XPointer               private12;             // ???
    XPointer               private13;             // ???
    XPointer               private14;             // ???
    unsigned               max_request_size;      // maximum number 32 bit words in request.
    XrmHashBucketRec*      db;                    // ???
    int                  (*private15)(XDisplay*); // ???
    char*                  display_name;          // "host:display" string used on this connect.
    int                    default_screen;        // default screen for operations.
    int                    nscreens;              // number of screens on this server.
    XScreen*               screens;               // pointer to list of screens.
    uint64_t               motion_buffer;         // size of motion buffer.
    uint64_t               private16;             // ???
    int                    min_keycode;           // minimum defined keycode.
    int                    max_keycode;           // maximum defined keycode.
    XPointer               private17;             // ???
    XPointer               private18;             // ???
    int                    private19;             // ???
    char*                  xdefaults;             // contents of defaults from server.
};

struct _XScreen {
    XExtData*              ext_data;              // hook for extension to hang data.
    XDisplay*              display;               // back pointer to display structure.
    XWindow                root;                  // Root window id.
    int                    width;                 // width and height of screen.
    int                    height;                // width and height of screen.
    int                    mwidth;                // width and height of screen in millimeters.
    int                    mheight;               // width and height of screen in millimeters.
    int                    ndepths;               // number of depths possible.
    XDepth*                depths;                // list of allowable depths on the screen.
    int                    root_depth;            // bits per pixel.
    XVisual*               root_visual;           // root visual.
    XGC*                   default_gc;            // XGCfor the root root visual.
    XColormap              cmap;                  // default color map.
    uint64_t               white_pixel;           // White pixel values.
    uint64_t               black_pixel;           // Black pixel values.
    int                    max_maps;              // max and min color maps.
    int                    min_maps;              // max and min color maps.
    int                    backing_store;         // Never, WhenMapped, Always.
    XBool                  save_unders;           // ???
    long                   root_input_mask;       // initial root input mask.
};

struct _XScreenFormat {
    XExtData*              ext_data;              // hook for extension to hang data.
    int                    depth;                 // depth of this image format.
    int                    bits_per_pixel;        // bits/pixel at this depth.
    int                    scanline_pad;          // scanline must padded to this multiple.
};

struct _XVisual {
    XExtData*              ext_data;              // hook for extension to hang data.
    XVisualID              visualid;              // visual id of this visual.
    int                    c_class;               // class of screen (monochrome, etc).
    uint64_t               red_mask;              // mask values.
    uint64_t               green_mask;            // mask values.
    uint64_t               blue_mask;             // mask values.
    int                    bits_per_rgb;          // log base 2 of distinct color values.
    int                    map_entries;           // color map entries.
};

struct _XVisualInfo {
    XVisual*               visual;                // ???
    XVisualID              visualid;              // ???
    int                    screen;                // ???
    int                    depth;                 // ???
    int                    c_class;               // ???
    uint64_t               red_mask;              // ???
    uint64_t               green_mask;            // ???
    uint64_t               blue_mask;             // ???
    int                    colormap_size;         // ???
    int                    bits_per_rgb;          // ???
};

typedef struct {
    XPixmap                background_pixmap;     // background or None or ParentRelative.
    uint64_t               background_pixel;      // background pixel.
    XPixmap                border_pixmap;         // border of the window.
    uint64_t               border_pixel;          // border pixel value.
    int                    bit_gravity;           // one of bit gravity values.
    int                    win_gravity;           // one of the window gravity values.
    int                    backing_store;         // NotUseful, WhenMapped, Always.
    uint64_t               backing_planes;        // planes to be preserved if possible.
    uint64_t               backing_pixel;         // value to use in restoring planes.
    XBool                  save_under;            // should bits under be saved? (popups).
    long                   event_mask;            // set of events that should be saved.
    long                   do_not_propagate_mask; // set of events that should not propagate.
    XBool                  override_redirect;     // boolean value for override-redirect.
    XColormap              colormap;              // color map to be associated with window.
    XCursor                cursor;                // cursor to be displayed (or None).
} XSetWindowAttributes;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // window on which event was requested in event mask.
} XAnyEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // "event" window it is reported relative to.
    XWindow                root;                  // root window that the event occurred on.
    XWindow                subwindow;             // child window.
    XTime                  time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    uint32_t               state;                 // key or button mask.
    uint32_t               button;                // detail.
    XBool                  same_screen;           // same screen flag.
} XButtonEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
    int                    place;                 // PlaceOnTop, PlaceOnBottom.
} XCirculateEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                parent;                // ???
    XWindow                window;                // ???
    int                    place;                 // PlaceOnTop, PlaceOnBottom.
} XCirculateRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    XAtom                  message_type;          // ???
    int                    format;                // ???
    union {
        char               b[20];                 // ???
        short              s[10];                 // ???
        long               l[5];                  // ???
    }                      data;                  // ???
} XClientMessageEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    XColormap              colormap;              // COLORMAP or None.
    XBool                  c_new;                 // C++.
    int                    state;                 // ColormapInstalled, ColormapUninstalled.
} XColormapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    border_width;          // ???
    XWindow                above;                 // ???
    XBool                  override_redirect;     // ???
} XConfigureEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                parent;                // ???
    XWindow                window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    border_width;          // ???
    XWindow                above;                 // ???
    int                    detail;                // Above, Below, TopIf, BottomIf, Opposite.
    uint64_t               value_mask;            // ???
} XConfigureRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                parent;                // parent of the window.
    XWindow                window;                // window id of window created.
    int                    x;                     // window location.
    int                    y;                     // window location.
    int                    width;                 // size of window.
    int                    height;                // size of window.
    int                    border_width;          // border width.
    XBool                  override_redirect;     // creation should be overridden.
} XCreateWindowEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // "event" window reported relative to.
    XWindow                root;                  // root window that the event occurred on.
    XWindow                subwindow;             // child window.
    XTime                  time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    int                    mode;                  // NotifyNormal, NotifyGrab, NotifyUngrab.
    int                    detail;                // ???
    XBool                  same_screen;           // same screen flag.
    XBool                  focus;                 // boolean focus.
    uint32_t               state;                 // key or button mask.
} XCrossingEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
} XDestroyWindowEvent;

typedef struct {
    int                    type;                  // of event.
    XDisplay*              display;               // Display the event was read from.
    XID                    resourceid;            // resource id.
    uint64_t               serial;                // serial number of failed request.
    uint8_t                error_code;            // error code of failed request.
    uint8_t                request_code;          // Major op-code of failed request.
    uint8_t                minor_code;            // Minor op-code of failed request.
} XErrorEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    count;                 // if non-zero, at least this many more.
} XExposeEvent;

typedef struct {
    int                    type;                  // FocusIn or FocusOut.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // window of event.
    int                    mode;                  // ???
    int                    detail;                // ???
} XFocusChangeEvent;

typedef struct {
    int                    type;                  // of event. Always GenericEvent.
    uint64_t               serial;                // # of last request processed.
    XBool                  send_event;            // true if from SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    int                    extension;             // major opcode of extension that caused the event.
    int                    evtype;                // actual event type.
} XGenericEvent;

typedef struct {
    int                    type;                  // of event. Always GenericEvent.
    uint64_t               serial;                // # of last request processed.
    XBool                  send_event;            // true if from SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    int                    extension;             // major opcode of extension that caused the event.
    int                    evtype;                // actual event type.
    uint32_t               cookie;                // ???
    void*                  data;                  // ???
} XGenericEventCookie;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XDrawable              drawable;              // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    count;                 // if non-zero, at least this many more.
    int                    major_code;            // core is CopyArea or CopyPlane.
    int                    minor_code;            // not defined in the core.
} XGraphicsExposeEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
} XGravityEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // "event" window it is reported relative to.
    XWindow                root;                  // root window that the event occurred on.
    XWindow                subwindow;             // child window.
    XTime                  time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    uint32_t               state;                 // key or button mask.
    uint32_t               keycode;               // detail.
    XBool                  same_screen;           // same screen flag.
} XKeyEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    char        key_vector[32];        // ???
} XKeymapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
    XBool                  override_redirect;     // boolean, is override set...
} XMapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // unused.
    int                    request;               // one of MappingModifier, MappingKeyboard, MappingPointer.
    int                    first_keycode;         // first keycode.
    int                    count;                 // defines range of change w. first_keycode.
} XMappingEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                parent;                // ???
    XWindow                window;                // ???
} XMapRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // "event" window reported relative to.
    XWindow                root;                  // root window that the event occurred on.
    XWindow                subwindow;             // child window.
    XTime                  time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    uint32_t               state;                 // key or button mask.
    char                   is_hint;               // detail.
    XBool                  same_screen;           // same screen flag.
} XMotionEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XDrawable              drawable;              // ???
    int                    major_code;            // core is CopyArea or CopyPlane.
    int                    minor_code;            // not defined in the core.
} XNoExposeEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    XAtom                  atom;                  // ???
    XTime                  time;                  // ???
    int                    state;                 // NewValue, Deleted.
} XPropertyEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
    XWindow                parent;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    XBool                  override_redirect;     // ???
} XReparentEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    int                    width;                 // ???
    int                    height;                // ???
} XResizeRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    XAtom                  selection;             // ???
    XTime                  time;                  // ???
} XSelectionClearEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                requestor;             // ???
    XAtom                  selection;             // ???
    XAtom                  target;                // ???
    XAtom                  property;              // ATOM or None.
    XTime                  time;                  // ???
} XSelectionEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                owner;                 // ???
    XWindow                requestor;             // ???
    XAtom                  selection;             // ???
    XAtom                  target;                // ???
    XAtom                  property;              // ???
    XTime                  time;                  // ???
} XSelectionRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                event;                 // ???
    XWindow                window;                // ???
    XBool                  from_configure;        // ???
} XUnmapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    XBool                  send_event;            // true if this came from a SendEvent request.
    XDisplay*              display;               // Display the event was read from.
    XWindow                window;                // ???
    int                    state;                 // Visibility state.
} XVisibilityEvent;

typedef union {
    int                    type;                  // ???
    XAnyEvent              xany;                  // ???
    XButtonEvent           xbutton;               // ???
    XCirculateEvent        xcirculate;            // ???
    XCirculateRequestEvent xcirculaterequest;     // ???
    XClientMessageEvent    xclient;               // ???
    XColormapEvent         xcolormap;             // ???
    XConfigureEvent        xconfigure;            // ???
    XConfigureRequestEvent xconfigurerequest;     // ???
    XCreateWindowEvent     xcreatewindow;         // ???
    XCrossingEvent         xcrossing;             // ???
    XDestroyWindowEvent    xdestroywindow;        // ???
    XErrorEvent            xerror;                // ???
    XExposeEvent           xexpose;               // ???
    XFocusChangeEvent      xfocus;                // ???
    XGenericEvent          xgeneric;              // ???
    XGenericEventCookie    xcookie;               // ???
    XGraphicsExposeEvent   xgraphicsexpose;       // ???
    XGravityEvent          xgravity;              // ???
    XKeyEvent              xkey;                  // ???
    XKeymapEvent           xkeymap;               // ???
    XMapEvent              xmap;                  // ???
    XMappingEvent          xmapping;              // ???
    XMapRequestEvent       xmaprequest;           // ???
    XMotionEvent           xmotion;               // ???
    XNoExposeEvent         xnoexpose;             // ???
    XPropertyEvent         xproperty;             // ???
    XReparentEvent         xreparent;             // ???
    XResizeRequestEvent    xresizerequest;        // ???
    XSelectionClearEvent   xselectionclear;       // ???
    XSelectionEvent        xselection;            // ???
    XSelectionRequestEvent xselectionrequest;     // ???
    XUnmapEvent            xunmap;                // ???
    XVisibilityEvent       xvisibility;           // ???
    long                   pad[24];               // ???
} XEvent;

// -------------------------------------------------------------------------------------------------------------------------- //

/// @brief Represents the "libX11.so" library and supported functions.
extern struct _libX11_so {
    void*       so;
    int       (*XChangeProperty)(XDisplay*,XWindow,XAtom,XAtom,int,int,const char*,int);
    int       (*XChangeWindowAttributes)(XDisplay*,XWindow,uint64_t,XSetWindowAttributes*);
    int       (*XCloseDisplay)(XDisplay*);
    XColormap (*XCreateColormap)(XDisplay*,XWindow,XVisual*,int);
    XWindow   (*XCreateWindow)(XDisplay*,XWindow,int,int,uint32_t,uint32_t,uint32_t,int,uint32_t,XVisual*,uint64_t,XSetWindowAttributes*);
    XWindow   (*XDefaultRootWindow)(XDisplay*);
    int       (*XDefaultScreen)(XDisplay*);
    XScreen   (*XDefaultScreenOfDisplay)(XDisplay*);
    int       (*XDeleteContext)(XDisplay*,XID,XContext);
    int       (*XDeleteProperty)(XDisplay*,XWindow,XAtom);
    int       (*XDestroyWindow)(XDisplay*,XWindow);
    int       (*XFindContext)(XDisplay*,XID,XContext,XPointer*);
    int       (*XFlush)(XDisplay*);
    int       (*XFree)(void*);
    int       (*XFreeColormap)(XDisplay*,XColormap);
    XAtom     (*XInternAtom)(XDisplay*,const char*,XBool);
    XKeyCode  (*XKeysymToKeycode)(XDisplay*,XKeySym);
    int       (*XMapWindow)(XDisplay*,XWindow);
    int       (*XNextEvent)(XDisplay*,XEvent*);
    XDisplay* (*XOpenDisplay)(const char*);
    int       (*XPending)(XDisplay*);
    int       (*XrmUniqueQuark)();
    int       (*XSaveContext)(XDisplay*,XID,XContext,const char*);
    int       (*XScreenCount)(XDisplay*);
    XScreen*  (*XScreenOfDisplay)(XDisplay*,int);
    XStatus   (*XSetWMProtocols)(XDisplay*,XWindow,XAtom*,int);
    int       (*XUnmapWindow)(XDisplay*,XWindow);


    // #include <X11/extensions/Xrender.h>
    XBool              (*XRenderQueryExtension)(XDisplay*,int32_t*,int32_t*);
    XStatus            (*XRenderQueryVersion)(XDisplay*,int32_t*,int32_t*);
    XStatus            (*XRenderQueryFormats)(XDisplay*);
    int32_t            (*XRenderQuerySubpixelOrder)(XDisplay*,int32_t);
    XBool              (*XRenderSetSubpixelOrder)(XDisplay*,int32_t,int32_t);
    XRenderPictFormat* (*XRenderFindVisualFormat)(XDisplay*,const XVisual*);
    XRenderPictFormat* (*XRenderFindFormat)(XDisplay*,uint64_t,const XRenderPictFormat*,int32_t);
    XRenderPictFormat* (*XRenderFindStandardFormat)(XDisplay*,int32_t);
    XIndexValue*       (*XRenderQueryPictIndexValues)(XDisplay*,const XRenderPictFormat*,int32_t*);
    XPicture           (*XRenderCreatePicture)(XDisplay*,XDrawable,const XRenderPictFormat*,uint64_t,const XRenderPictureAttributes*);
    void               (*XRenderChangePicture)(XDisplay*,XPicture,uint64_t,const XRenderPictureAttributes*);
    void               (*XRenderSetPictureClipRectangles)(XDisplay*,XPicture,int32_t,int32_t,const XRectangle*,int32_t);
    void               (*XRenderSetPictureClipRegion)(XDisplay*,XPicture,XRegion);
    void               (*XRenderSetPictureTransform)(XDisplay*,XPicture,XTransform*);
    void               (*XRenderFreePicture)(XDisplay*,XPicture);
    void               (*XRenderComposite)(XDisplay*,int32_t,XPicture,XPicture,XPicture,int32_t,int32_t,int32_t,int32_t,int32_t,int32_t,uint32_t,uint32_t);
    XGlyphSet          (*XRenderCreateGlyphSet)(XDisplay*,const XRenderPictFormat*);
    XGlyphSet          (*XRenderReferenceGlyphSet)(XDisplay*,XGlyphSet);
    void               (*XRenderFreeGlyphSet)(XDisplay*,XGlyphSet);
    void               (*XRenderAddGlyphs)(XDisplay*,XGlyphSet,const XGlyph*,const XGlyphInfo*,int32_t,const char*,int32_t);
    void               (*XRenderFreeGlyphs)(XDisplay*,XGlyphSet,const XGlyph*,int32_t);
    void               (*XRenderCompositeString8)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,XGlyphSet,int32_t,int32_t,int32_t,int32_t,const char*,int32_t);
    void               (*XRenderCompositeString16)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,XGlyphSet,int32_t,int32_t,int32_t,int32_t,const uint16_t*,int32_t);
    void               (*XRenderCompositeString32)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,XGlyphSet,int32_t,int32_t,int32_t,int32_t,const uint32_t*,int32_t);
    void               (*XRenderCompositeText8)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,int32_t,int32_t,const XGlyphElt8*,int32_t);
    void               (*XRenderCompositeText16)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,int32_t,int32_t,const XGlyphElt16*,int32_t);
    void               (*XRenderCompositeText32)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,int32_t,int32_t,const XGlyphElt32*,int32_t);
    void               (*XRenderFillRectangle)(XDisplay*,int32_t,XPicture,const XRenderColor*,int32_t,int32_t,uint32_t,uint32_t);
    void               (*XRenderFillRectangles)(XDisplay*,int32_t,XPicture,const XRenderColor*,const XRectangle*,int32_t);
    void               (*XRenderCompositeTrapezoids)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,const XTrapezoid*,int32_t);
    void               (*XRenderCompositeTriangles)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,const XTriangle*,int32_t);
    void               (*XRenderCompositeTriStrip)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,const XPointFixed*,int32_t);
    void               (*XRenderCompositeTriFan)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,const XPointFixed*,int32_t);
    void               (*XRenderCompositeDoublePoly)(XDisplay*,int32_t,XPicture,XPicture,const XRenderPictFormat*,int32_t,int32_t,int32_t,int32_t,const XPointDouble*,int32_t,int32_t);
    XStatus            (*XRenderParseColor)(XDisplay*,char*,XRenderColor*);
    XCursor            (*XRenderCreateCursor)(XDisplay*,XPicture,uint32_t,uint32_t);
    XFilters*          (*XRenderQueryFilters)(XDisplay*,XDrawable);
    void               (*XRenderSetPictureFilter)(XDisplay*,XPicture,const char*,int32_t*,int32_t);
    XCursor            (*XRenderCreateAnimCursor)(XDisplay*,int32_t,XAnimCursor*);
    void               (*XRenderAddTraps)(XDisplay*,XPicture,int32_t,int32_t,const XTrap*,int32_t);
    XPicture           (*XRenderCreateSolidFill)(XDisplay*,const XRenderColor*);
    XPicture           (*XRenderCreateLinearGradient)(XDisplay*,const XLinearGradient*,const int32_t*,const XRenderColor*,int32_t);
    XPicture           (*XRenderCreateRadialGradient)(XDisplay*,const XRadialGradient*,const int32_t*,const XRenderColor*,int32_t);
    XPicture           (*XRenderCreateConicalGradient)(XDisplay*,const XConicalGradient*,const int32_t*,const XRenderColor*,int32_t);
} _libX11;

/// @brief Returns true if the "libX11.so" library was freed successfully.
bool _free_libX11_so();

/// @brief Returns true if the "libX11.so" library was loaded successfully.
bool _load_libX11_so();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_linux_libX11_h__
// -------------------------------------------------------------------------------------------------------------------------- //