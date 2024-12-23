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

typedef uint64_t          Atom;
typedef int               Bool;
typedef uint64_t          Colormap;
typedef int               XContext;
typedef uint64_t          Drawable;
typedef struct _XDisplay  Display;
typedef uint64_t          XID;
typedef uint64_t          KeySym;
typedef char*             XPointer;
typedef int               Status;
typedef uint64_t          VisualID;
typedef uint64_t          Cursor;
typedef uint64_t          Pixmap;
typedef uint64_t          Window;
typedef struct _XExtData  XExtData;
typedef struct _XGC*      GC;
typedef uint8_t           KeyCode;
typedef uint64_t          Time;

typedef struct {
    XExtData*              ext_data;              // hook for extension to hang data.
    VisualID               visualid;              // visual id of this visual.
    int                    c_class;               // class of screen (monochrome, etc).
    uint64_t               red_mask;              // mask values.
    uint64_t               green_mask;            // mask values.
    uint64_t               blue_mask;             // mask values.
    int                    bits_per_rgb;          // log base 2 of distinct color values.
    int                    map_entries;           // color map entries.
} Visual;

typedef struct {
    int                    depth;                 // this depth (Z) of the depth.
    int                    nvisuals;              // number of Visual types at this depth.
    Visual*                visuals;               // list of visuals possible at this depth.
} Depth;

typedef struct {
    XExtData*              ext_data;              // hook for extension to hang data.
    Display*               display;               // back pointer to display structure.
    Window                 root;                  // Root window id.
    int                    width;                 // width and height of screen.
    int                    height;                // width and height of screen.
    int                    mwidth;                // width and height of screen in millimeters.
    int                    mheight;               // width and height of screen in millimeters.
    int                    ndepths;               // number of depths possible.
    Depth*                 depths;                // list of allowable depths on the screen.
    int                    root_depth;            // bits per pixel.
    Visual*                root_visual;           // root visual.
    GC                     default_gc;            // GC for the root root visual.
    Colormap               cmap;                  // default color map.
    uint64_t               white_pixel;           // White pixel values.
    uint64_t               black_pixel;           // Black pixel values.
    int                    max_maps;              // max and min color maps.
    int                    min_maps;              // max and min color maps.
    int                    backing_store;         // Never, WhenMapped, Always.
    Bool                   save_unders;           // ???
    long                   root_input_mask;       // initial root input mask.
} Screen;

typedef struct {
    Pixmap                 background_pixmap;     // background or None or ParentRelative.
    uint64_t               background_pixel;      // background pixel.
    Pixmap                 border_pixmap;         // border of the window.
    uint64_t               border_pixel;          // border pixel value.
    int                    bit_gravity;           // one of bit gravity values.
    int                    win_gravity;           // one of the window gravity values.
    int                    backing_store;         // NotUseful, WhenMapped, Always.
    uint64_t               backing_planes;        // planes to be preserved if possible.
    uint64_t               backing_pixel;         // value to use in restoring planes.
    Bool                   save_under;            // should bits under be saved? (popups).
    long                   event_mask;            // set of events that should be saved.
    long                   do_not_propagate_mask; // set of events that should not propagate.
    Bool                   override_redirect;     // boolean value for override-redirect.
    Colormap               colormap;              // color map to be associated with window.
    Cursor                 cursor;                // cursor to be displayed (or None).
} XSetWindowAttributes;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // window on which event was requested in event mask.
} XAnyEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // "event" window it is reported relative to.
    Window                 root;                  // root window that the event occurred on.
    Window                 subwindow;             // child window.
    Time                   time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    uint32_t               state;                 // key or button mask.
    uint32_t               button;                // detail.
    Bool                   same_screen;           // same screen flag.
} XButtonEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
    int                    place;                 // PlaceOnTop, PlaceOnBottom.
} XCirculateEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 parent;                // ???
    Window                 window;                // ???
    int                    place;                 // PlaceOnTop, PlaceOnBottom.
} XCirculateRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    Atom                   message_type;          // ???
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
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    Colormap               colormap;              // COLORMAP or None.
    Bool                   c_new;                 // C++.
    int                    state;                 // ColormapInstalled, ColormapUninstalled.
} XColormapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    border_width;          // ???
    Window                 above;                 // ???
    Bool                   override_redirect;     // ???
} XConfigureEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 parent;                // ???
    Window                 window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    border_width;          // ???
    Window                 above;                 // ???
    int                    detail;                // Above, Below, TopIf, BottomIf, Opposite.
    uint64_t               value_mask;            // ???
} XConfigureRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 parent;                // parent of the window.
    Window                 window;                // window id of window created.
    int                    x;                     // window location.
    int                    y;                     // window location.
    int                    width;                 // size of window.
    int                    height;                // size of window.
    int                    border_width;          // border width.
    Bool                   override_redirect;     // creation should be overridden.
} XCreateWindowEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // "event" window reported relative to.
    Window                 root;                  // root window that the event occurred on.
    Window                 subwindow;             // child window.
    Time                   time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    int                    mode;                  // NotifyNormal, NotifyGrab, NotifyUngrab.
    int                    detail;                // ???
    Bool                   same_screen;           // same screen flag.
    Bool                   focus;                 // boolean focus.
    uint32_t               state;                 // key or button mask.
} XCrossingEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
} XDestroyWindowEvent;

typedef struct {
    int                    type;                  // of event.
    Display*               display;               // Display the event was read from.
    XID                    resourceid;            // resource id.
    uint64_t               serial;                // serial number of failed request.
    uint8_t                error_code;            // error code of failed request.
    uint8_t                request_code;          // Major op-code of failed request.
    uint8_t                minor_code;            // Minor op-code of failed request.
} XErrorEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    int                    width;                 // ???
    int                    height;                // ???
    int                    count;                 // if non-zero, at least this many more.
} XExposeEvent;

typedef struct {
    int                    type;                  // FocusIn or FocusOut.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // window of event.
    int                    mode;                  // ???
    int                    detail;                // ???
} XFocusChangeEvent;

typedef struct {
    int                    type;                  // of event. Always GenericEvent.
    uint64_t               serial;                // # of last request processed.
    Bool                   send_event;            // true if from SendEvent request.
    Display*               display;               // Display the event was read from.
    int                    extension;             // major opcode of extension that caused the event.
    int                    evtype;                // actual event type.
} XGenericEvent;

typedef struct {
    int                    type;                  // of event. Always GenericEvent.
    uint64_t               serial;                // # of last request processed.
    Bool                   send_event;            // true if from SendEvent request.
    Display*               display;               // Display the event was read from.
    int                    extension;             // major opcode of extension that caused the event.
    int                    evtype;                // actual event type.
    uint32_t               cookie;                // ???
    void*                  data;                  // ???
} XGenericEventCookie;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Drawable               drawable;              // ???
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
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
} XGravityEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // "event" window it is reported relative to.
    Window                 root;                  // root window that the event occurred on.
    Window                 subwindow;             // child window.
    Time                   time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    uint32_t               state;                 // key or button mask.
    uint32_t               keycode;               // detail.
    Bool                   same_screen;           // same screen flag.
} XKeyEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    char        key_vector[32];        // ???
} XKeymapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
    Bool                   override_redirect;     // boolean, is override set...
} XMapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // unused.
    int                    request;               // one of MappingModifier, MappingKeyboard, MappingPointer.
    int                    first_keycode;         // first keycode.
    int                    count;                 // defines range of change w. first_keycode.
} XMappingEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 parent;                // ???
    Window                 window;                // ???
} XMapRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // "event" window reported relative to.
    Window                 root;                  // root window that the event occurred on.
    Window                 subwindow;             // child window.
    Time                   time;                  // milliseconds.
    int                    x;                     // pointer x, y coordinates in event window.
    int                    y;                     // pointer x, y coordinates in event window.
    int                    x_root;                // coordinates relative to root.
    int                    y_root;                // coordinates relative to root.
    uint32_t               state;                 // key or button mask.
    char                   is_hint;               // detail.
    Bool                   same_screen;           // same screen flag.
} XMotionEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Drawable               drawable;              // ???
    int                    major_code;            // core is CopyArea or CopyPlane.
    int                    minor_code;            // not defined in the core.
} XNoExposeEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    Atom                   atom;                  // ???
    Time                   time;                  // ???
    int                    state;                 // NewValue, Deleted.
} XPropertyEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
    Window                 parent;                // ???
    int                    x;                     // ???
    int                    y;                     // ???
    Bool                   override_redirect;     // ???
} XReparentEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    int                    width;                 // ???
    int                    height;                // ???
} XResizeRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
    Atom                   selection;             // ???
    Time                   time;                  // ???
} XSelectionClearEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 requestor;             // ???
    Atom                   selection;             // ???
    Atom                   target;                // ???
    Atom                   property;              // ATOM or None.
    Time                   time;                  // ???
} XSelectionEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 owner;                 // ???
    Window                 requestor;             // ???
    Atom                   selection;             // ???
    Atom                   target;                // ???
    Atom                   property;              // ???
    Time                   time;                  // ???
} XSelectionRequestEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 event;                 // ???
    Window                 window;                // ???
    Bool                   from_configure;        // ???
} XUnmapEvent;

typedef struct {
    int                    type;                  // of event.
    uint64_t               serial;                // # of last request processed by server.
    Bool                   send_event;            // true if this came from a SendEvent request.
    Display*               display;               // Display the event was read from.
    Window                 window;                // ???
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
    void*      so;
    int      (*XChangeProperty)(Display*,Window,Atom,Atom,int,int,const char*,int);
    int      (*XChangeWindowAttributes)(Display*,Window,uint64_t,XSetWindowAttributes*);
    int      (*XCloseDisplay)(Display*);
    Colormap (*XCreateColormap)(Display*,Window,Visual*,int);
    Window   (*XCreateWindow)(Display*,Window,int,int,uint32_t,uint32_t,uint32_t,int,uint32_t,Visual*,uint64_t,XSetWindowAttributes*);
    Window   (*XDefaultRootWindow)(Display*);
    int      (*XDefaultScreen)(Display*);
    Screen   (*XDefaultScreenOfDisplay)(Display*);
    int      (*XDeleteContext)(Display*,XID,XContext);
    int      (*XDeleteProperty)(Display*,Window,Atom);
    int      (*XDestroyWindow)(Display*,Window);
    int      (*XFindContext)(Display*,XID,XContext,XPointer*);
    int      (*XFlush)(Display*);
    int      (*XFree)(void*);
    int      (*XFreeColormap)(Display*,Colormap);
    Atom     (*XInternAtom)(Display*,const char*,Bool);
    KeyCode  (*XKeysymToKeycode)(Display*,KeySym);
    int      (*XMapWindow)(Display*,Window);
    int      (*XNextEvent)(Display*,XEvent*);
    Display* (*XOpenDisplay)(const char*);
    int      (*XPending)(Display*);
    int      (*XrmUniqueQuark)();
    int      (*XSaveContext)(Display*,XID,XContext,const char*);
    int      (*XScreenCount)(Display*);
    Screen*  (*XScreenOfDisplay)(Display*,int);
    Status   (*XSetWMProtocols)(Display*,Window,Atom*,int);
    int      (*XUnmapWindow)(Display*,Window);
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