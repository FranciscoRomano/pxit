// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_linux_api_libX11_h__
#define __core_linux_api_libX11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdint.h>
#include <stdbool.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#define Bool int
typedef char *XPointer;
typedef XID KeySym;
typedef int              XContext;
typedef unsigned long    XID;
typedef unsigned long    Atom;
typedef unsigned long    VisualID;
typedef struct _XDisplay Display;
typedef XID              Cursor;
typedef XID              Pixmap;
typedef XID              Window;
typedef XID              Colormap;
typedef struct _XExtData XExtData;
typedef struct _XGC*     GC;
typedef unsigned char    KeyCode;

/// @brief Visual structure containing information about colormapping possible.
typedef struct {
    XExtData*     ext_data;     // hook for extension to hang data.
    VisualID      visualid;     // visual id of this visual.
    int           c_class;      // class of screen (monochrome, etc).
    unsigned long red_mask;     // mask values.
    unsigned long green_mask;   // mask values.
    unsigned long blue_mask;    // mask values.
    int           bits_per_rgb; // log base 2 of distinct color values.
    int           map_entries;  // color map entries.
} Visual;

/// @brief Depth structure containing information for each possible depth.
typedef struct {
    int     depth;    // this depth (Z) of the depth.
    int     nvisuals; // number of Visual types at this depth.
    Visual* visuals;  // list of visuals possible at this depth.
} Depth;

/// @brief Data structure with screen properties.
typedef struct {
    XExtData*     ext_data;          // hook for extension to hang data.
    Display*      display;           // back pointer to display structure.
    Window        root;              // Root window id.
    int           width,height;      // width and height of screen.
    int           mwidth,mheight;    // width and height of screen in millimeters.
    int           ndepths;           // number of depths possible.
    Depth*        depths;            // list of allowable depths on the screen.
    int           root_depth;        // bits per pixel.
    Visual*       root_visual;       // root visual.
    GC            default_gc;        // GC for the root root visual.
    Colormap      cmap;              // default color map.
    unsigned long white_pixel;       // White pixel values.
    unsigned long black_pixel;       // Black pixel values.
    int           max_maps,min_maps; // max and min color maps.
    int           backing_store;     // Never, WhenMapped, Always.
    Bool          save_unders;       // ???
    long          root_input_mask;   // initial root input mask.
} Screen;

/// @brief Data structure for setting window attributes.
typedef struct {
    Pixmap        background_pixmap;     // background or None or ParentRelative.
    unsigned long background_pixel;      // background pixel.
    Pixmap        border_pixmap;         // border of the window.
    unsigned long border_pixel;          // border pixel value.
    int           bit_gravity;           // one of bit gravity values.
    int           win_gravity;           // one of the window gravity values.
    int           backing_store;         // NotUseful, WhenMapped, Always.
    unsigned long backing_planes;        // planes to be preserved if possible.
    unsigned long backing_pixel;         // value to use in restoring planes.
    Bool          save_under;            // should bits under be saved? (popups).
    long          event_mask;            // set of events that should be saved.
    long          do_not_propagate_mask; // set of events that should not propagate.
    Bool          override_redirect;     // boolean value for override-redirect.
    Colormap      colormap;              // color map to be associated with window.
    Cursor        cursor;                // cursor to be displayed (or None).
} XSetWindowAttributes;

typedef struct {
    int           type;
    unsigned long serial;      // # of last request processed by server.
    Bool          send_event;  // true if this came from a SendEvent request.
    Display*      display;     // Display the event was read from.
    Window        window;      // window on which event was requested in event mask.
} XAnyEvent;

typedef struct {
    int           type;        // of event.
    unsigned long serial;      // # of last request processed by server.
    Bool          send_event;  // true if this came from a SendEvent request.
    Display*      display;     // Display the event was read from.
    Window        window;      // "event" window it is reported relative to.
    Window        root;        // root window that the event occurred on.
    Window        subwindow;   // child window.
    Time          time;        // milliseconds.
    int           x;           // pointer x, y coordinates in event window.
    int           y;           // pointer x, y coordinates in event window.
    int           x_root;      // coordinates relative to root.
    int           y_root;      // coordinates relative to root.
    unsigned int  state;       // key or button mask.
    unsigned int  button;      // detail.
    Bool          same_screen; // same screen flag.
} XButtonEvent;

typedef struct {
    int           type;
    unsigned long serial;     // # of last request processed by server.
    Bool          send_event; // true if this came from a SendEvent request.
    Display*      display;    // Display the event was read from.
    Window        event;
    Window        window;
    int           place;      // PlaceOnTop, PlaceOnBottom.
} XCirculateEvent;

typedef struct {
    int           type;
    unsigned long serial;     // # of last request processed by server.
    Bool          send_event; // true if this came from a SendEvent request.
    Display*      display;    // Display the event was read from.
    Window        parent;
    Window        window;
    int           place;      // PlaceOnTop, PlaceOnBottom.
} XCirculateRequestEvent;

/// @brief Data structure with event properties.
typedef union {
    int                    type;
    XAnyEvent              xany;
    XButtonEvent           xbutton;
    XCirculateEvent        xcirculate;
    XCirculateRequestEvent xcirculaterequest;
    XClientMessageEvent    xclient;
    XColormapEvent         xcolormap;
    XConfigureEvent        xconfigure;
    XConfigureRequestEvent xconfigurerequest;
    XCreateWindowEvent     xcreatewindow;
    XCrossingEvent         xcrossing;
    XDestroyWindowEvent    xdestroywindow;
    XErrorEvent            xerror;
    XExposeEvent           xexpose;
    XFocusChangeEvent      xfocus;
    XGenericEvent          xgeneric;
    XGenericEventCookie    xcookie;
    XGraphicsExposeEvent   xgraphicsexpose;
    XGravityEvent          xgravity;
    XKeyEvent              xkey;
    XKeymapEvent           xkeymap;
    XMapEvent              xmap;
    XMappingEvent          xmapping;
    XMapRequestEvent       xmaprequest;
    XMotionEvent           xmotion;
    XNoExposeEvent         xnoexpose;
    XPropertyEvent         xproperty;
    XReparentEvent         xreparent;
    XResizeRequestEvent    xresizerequest;
    XSelectionClearEvent   xselectionclear;
    XSelectionEvent        xselection;
    XSelectionRequestEvent xselectionrequest;
    XUnmapEvent            xunmap;
    XVisibilityEvent       xvisibility;
    long                   pad[24];
} XEvent;

/// @brief Represents the "libX11.so" library and supported functions.
extern struct _Library_libX11 {
    void* so;
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
#endif//__core_linux_api_libX11_h__
// -------------------------------------------------------------------------------------------------------------------------- //