// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_linux_libX11_h__
#define __core_linux_libX11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdint.h>
#include <stdbool.h>

typedef uint64_t                 XAtom;
typedef int                      XBool;
typedef uint64_t                 XColormap;
typedef int                      XContext;
typedef uint64_t                 XDrawable;
typedef uint64_t                 XID;
typedef uint64_t                 XKeySym;
typedef char*                    XPointer;
typedef int                      XStatus;
typedef uint64_t                 XVisualID;
typedef uint64_t                 XCursor;
typedef uint64_t                 XPixmap;
typedef uint64_t                 XWindow;
typedef struct _XDisplay         XDisplay;
typedef struct _XExtData         XExtData;
typedef struct _XPrivate         XPrivate;
typedef struct _XVisual          XVisual;
typedef struct _XGC              XGC;
typedef uint8_t                  XKeyCode;
typedef uint64_t                 XTime;
typedef struct _XDepth           XDepth;
typedef struct _XScreen          XScreen;
typedef struct _XScreenFormat    XScreenFormat;
typedef struct _XrmHashBucketRec XrmHashBucketRec;

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
    XExtData*              ext_data;              // hook for extension to hang data */
    int                    depth;                 // depth of this image format */
    int                    bits_per_pixel;        // bits/pixel at this depth */
    int                    scanline_pad;          // scanline must padded to this multiple */
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
    Screen    (*XDefaultScreenOfDisplay)(XDisplay*);
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