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

#define AllPlanes                      ((uint64_t)~0L)
#define BitmapBitOrder(dpy)            (((XDisplay*)(dpy))->bitmap_bit_order)
#define BitmapPad(dpy)                 (((XDisplay*)(dpy))->bitmap_pad)
#define BitmapUnit(dpy)                (((XDisplay*)(dpy))->bitmap_unit)
#define BlackPixel(dpy,scr)            (ScreenOfDisplay(dpy,scr)->black_pixel)
#define BlackPixelOfScreen(s)          ((s)->black_pixel)
#define CellsOfScreen(s)               (DefaultVisualOfScreen((s))->map_entries)
#define ConnectionNumber(dpy)          (((XDisplay*)(dpy))->fd)
#define DefaultColormap(dpy,scr)       (ScreenOfDisplay(dpy,scr)->cmap)
#define DefaultColormapOfScreen(s)     ((s)->cmap)
#define DefaultDepth(dpy,scr)          (ScreenOfDisplay(dpy,scr)->root_depth)
#define DefaultDepthOfScreen(s)        ((s)->root_depth)
#define DefaultGC(dpy,scr)             (ScreenOfDisplay(dpy,scr)->default_gc)
#define DefaultGCOfScreen(s)           ((s)->default_gc)
#define DefaultRootWindow(dpy)         (ScreenOfDisplay(dpy,DefaultScreen(dpy))->root)
#define DefaultScreen(dpy)             (((XDisplay*)(dpy))->default_screen)
#define DefaultScreenOfDisplay(dpy)    ScreenOfDisplay(dpy,DefaultScreen(dpy))
#define DefaultVisual(dpy,scr)         (ScreenOfDisplay(dpy,scr)->root_visual)
#define DefaultVisualOfScreen(s)       ((s)->root_visual)
#define DisplayCells(dpy,scr)          (DefaultVisual(dpy,scr)->map_entries)
#define DisplayHeight(dpy,scr)         (ScreenOfDisplay(dpy,scr)->height)
#define DisplayHeightMM(dpy,scr)       (ScreenOfDisplay(dpy,scr)->mheight)
#define DisplayOfScreen(s)             ((s)->display)
#define DisplayPlanes(dpy,scr)         (ScreenOfDisplay(dpy,scr)->root_depth)
#define DisplayString(dpy)             (((XDisplay*)(dpy))->display_name)
#define DisplayWidth(dpy,scr)          (ScreenOfDisplay(dpy,scr)->width)
#define DisplayWidthMM(dpy,scr)        (ScreenOfDisplay(dpy,scr)->mwidth)
#define DoesBackingStore(s)            ((s)->backing_store)
#define DoesSaveUnders(s)              ((s)->save_unders)
#define EventMaskOfScreen(s)           ((s)->root_input_mask)
#define False                          0
#define HeightMMOfScreen(s)            ((s)->mheight)
#define HeightOfScreen(s)              ((s)->height)
#define ImageByteOrder(dpy)            (((XDisplay*)(dpy))->byte_order)
#define LastKnownRequestProcessed(dpy) (((XDisplay*)(dpy))->last_request_read)
#define MaxCmapsOfScreen(s)            ((s)->max_maps)
#define MinCmapsOfScreen(s)            ((s)->min_maps)
#define NextRequest(dpy)               (((XDisplay*)(dpy))->request + 1)
#define PlanesOfScreen(s)              ((s)->root_depth)
#define ProtocolRevision(dpy)          (((XDisplay*)(dpy))->proto_minor_version)
#define ProtocolVersion(dpy)           (((XDisplay*)(dpy))->proto_major_version)
#define QLength(dpy)                   (((XDisplay*)(dpy))->qlen)
#define QueuedAfterFlush               2
#define QueuedAfterReading             1
#define QueuedAlready                  0
#define RootWindow(dpy,scr)            (ScreenOfDisplay(dpy,scr)->root)
#define RootWindowOfScreen(s)          ((s)->root)
#define ScreenCount(dpy)               (((XDisplay*)(dpy))->nscreens)
#define ScreenOfDisplay(dpy,scr)       (&((XDisplay*)(dpy))->screens[scr])
#define ServerVendor(dpy)              (((XDisplay*)(dpy))->vendor)
#define True                           1
#define VendorRelease(dpy)             (((XDisplay*)(dpy))->release)
#define WhitePixel(dpy,scr)            (ScreenOfDisplay(dpy,scr)->white_pixel)
#define WhitePixelOfScreen(s)          ((s)->white_pixel)
#define WidthMMOfScreen(s)             ((s)->mwidth)
#define WidthOfScreen(s)               ((s)->width)
#define XAllocID(dpy)                  ((*((XDisplay*)(dpy))->resource_alloc)((dpy)))

typedef struct XArc                      XArc;
typedef struct XColor                    XColor;
typedef struct XDepth                    XDepth;
typedef struct XDisplay                  XDisplay;
typedef struct XExtCodes                 XExtCodes;
typedef struct XExtData                  XExtData;
typedef struct XGC                       XGC;
typedef struct XGCValues                 XGCValues;
typedef struct XHostAddress              XHostAddress;
typedef struct XImage                    XImage;
typedef struct XKeyboardControl          XKeyboardControl;
typedef struct XKeyboardState            XKeyboardState;
typedef struct XModifierKeymap           XModifierKeymap;
typedef struct XPixmapFormatValues       XPixmapFormatValues;
typedef struct XPoint                    XPoint;
typedef struct XPrivate                  XPrivate;
typedef struct XRectangle                XRectangle;
typedef struct XrmHashBucketRec          XrmHashBucketRec;
typedef struct XScreen                   XScreen;
typedef struct XScreenFormat             XScreenFormat;
typedef struct XSegment                  XSegment;
typedef struct XServerInterpretedAddress XServerInterpretedAddress;
typedef struct XSetWindowAttributes      XSetWindowAttributes;
typedef struct XTimeCoord                XTimeCoord;
typedef struct XVisual                   XVisual;
typedef struct XWindowAttributes         XWindowAttributes;
typedef struct XWindowChanges            XWindowChanges;

typedef struct XExtData {
    int32_t             number;                            // number returned by XRegisterExtension
    XExtData*           next;                              // next item on list of data for structure
    int32_t           (*free_private)(XExtData*);          // called to free private storage
    void*               private_data;                      // data private to this extension
} XExtData;

typedef struct XExtCodes {
    int32_t             extension;                         // extension number
    int32_t             major_opcode;                      // major op-code assigned by server
    int32_t             first_event;                       // first event number for the extension
    int32_t             first_error;                       // first error number for the extension
} XExtCodes;

typedef struct XPixmapFormatValues {
    int32_t             depth;                             // ???
    int32_t             bits_per_pixel;                    // ???
    int32_t             scanline_pad;                      // ???
} XPixmapFormatValues;

typedef struct XGCValues {
    int32_t             function;                          // logical operation
    uint64_t            plane_mask;                        // plane mask
    uint64_t            foreground;                        // foreground pixel
    uint64_t            background;                        // background pixel
    int32_t             line_width;                        // line width
    int32_t             line_style;                        // LineSolid, LineOnOffDash, LineDoubleDash
    int32_t             cap_style;                         // CapNotLast, CapButt, CapRound, CapProjecting
    int32_t             join_style;                        // JoinMiter, JoinRound, JoinBevel
    int32_t             fill_style;                        // FillSolid, FillTiled, FillStippled, FillOpaqueStippled
    int32_t             fill_rule;                         // EvenOddRule, WindingRule
    int32_t             arc_mode;                          // ArcChord, ArcPieSlice
    XPixmap             tile;                              // tile pixmap for tiling operations
    XPixmap             stipple;                           // stipple 1 plane pixmap for stippling
    int32_t             ts_x_origin;                       // offset for tile or stipple operations
    int32_t             ts_y_origin;                       // ???
    XFont               font;                              // default text font for text operations
    int32_t             subwindow_mode;                    // ClipByChildren, IncludeInferiors
    int32_t             graphics_exposures;                // boolean, should exposures be generated
    int32_t             clip_x_origin;                     // origin for clipping
    int32_t             clip_y_origin;                     // ???
    XPixmap             clip_mask;                         // bitmap clipping; other calls for rects
    int32_t             dash_offset;                       // patterned/dashed line information
    char                dashes;                            // ???
} XGCValues;

typedef struct XGC {
    XExtData*           ext_data;                          // hook for extension to hang data
    XGContext           gid;                               // protocol ID for graphics context
}* XGC;

typedef struct XVisual {
    XExtData*           ext_data;                          // hook for extension to hang data
    XVisualID           visualid;                          // visual id of this visual
    int32_t             c_class;                           // C++ class of screen (monochrome, etc.)
    uint64_t            red_mask;                          // mask values
    uint64_t            green_mask;                        // mask values
    uint64_t            blue_mask;                         // mask values
    int32_t             bits_per_rgb;                      // log base 2 of distinct color values
    int32_t             map_entries;                       // color map entries
} XVisual;

typedef struct XDepth {
    int32_t             depth;                             // this depth (Z) of the depth
    int32_t             nvisuals;                          // number of XVisual types at this depth
    XVisual*            visuals;                           // list of visuals possible at this depth
} XDepth;

typedef struct XScreen {
    XExtData*           ext_data;                          // hook for extension to hang data
    XDisplay*           display;                           // back pointer to display structure
    XWindow             root;                              // Root window id
    int32_t             width;                             // width of screen
    int32_t             height;                            // height of screen
    int32_t             mwidth;                            // width of screen in millimeters
    int32_t             mheight;                           // height of screen in millimeters
    int32_t             ndepths;                           // number of depths possible
    XDepth*             depths;                            // list of allowable depths on the screen
    int32_t             root_depth;                        // bits per pixel
    XVisual*            root_visual;                       // root visual
    XGC                 default_gc;                        // GC for the root root visual
    XColormap           cmap;                              // default color map
    uint64_t            white_pixel;                       // ???
    uint64_t            black_pixel;                       // White and Black pixel values
    int32_t             max_maps;                          // max color maps
    int32_t             min_maps;                          // min color maps
    int32_t             backing_store;                     // Never, WhenMapped, Always
    int32_t             save_unders;                       // ???
    int64_t             root_input_mask;                   // initial root input mask
} XScreen;

typedef struct XScreenFormat {
    XExtData*           ext_data;                          // hook for extension to hang data
    int32_t             depth;                             // depth of this image format
    int32_t             bits_per_pixel;                    // bits/pixel at this depth
    int32_t             scanline_pad;                      // scanline must padded to this multiple
} XScreenFormat;

typedef struct XSetWindowAttributes {
    XPixmap             background_pixmap;                 // background or None or ParentRelative
    uint64_t            background_pixel;                  // background pixel
    XPixmap             border_pixmap;                     // border of the window
    uint64_t            border_pixel;                      // border pixel value
    int32_t             bit_gravity;                       // one of bit gravity values
    int32_t             win_gravity;                       // one of the window gravity values
    int32_t             backing_store;                     // NotUseful, WhenMapped, Always
    uint64_t            backing_planes;                    // planes to be preserved if possible
    uint64_t            backing_pixel;                     // value to use in restoring planes
    int32_t             save_under;                        // should bits under be saved? (popups)
    int64_t             event_mask;                        // set of events that should be saved
    int64_t             do_not_propagate_mask;             // set of events that should not propagate
    int32_t             override_redirect;                 // boolean value for override-redirect
    XColormap           colormap;                          // color map to be associated with window
    XCursor             cursor;                            // cursor to be displayed (or None)
} XSetWindowAttributes;

typedef struct XWindowAttributes {
    int32_t             x;                                 // location of window
    int32_t             y;                                 // location of window
    int32_t             width;                             // width of window
    int32_t             height;                            // height of window
    int32_t             border_width;                      // border width of window
    int32_t             depth;                             // depth of window
    XVisual*            visual;                            // the associated visual structure
    XWindow             root;                              // root of screen containing window
    int32_t             c_class;                           // C++ InputOutput, InputOnly
    int32_t             bit_gravity;                       // one of bit gravity values
    int32_t             win_gravity;                       // one of the window gravity values
    int32_t             backing_store;                     // NotUseful, WhenMapped, Always
    uint64_t            backing_planes;                    // planes to be preserved if possible
    uint64_t            backing_pixel;                     // value to be used when restoring planes
    int32_t             save_under;                        // boolean, should bits under be saved?
    XColormap           colormap;                          // color map to be associated with window
    int32_t             map_installed;                     // boolean, is color map currently installed
    int32_t             map_state;                         // IsUnmapped, IsUnviewable, IsViewable
    int64_t             all_event_masks;                   // set of events all people have interest in
    int64_t             your_event_mask;                   // my event mask
    int64_t             do_not_propagate_mask;             // set of events that should not propagate
    int32_t             override_redirect;                 // boolean value for override-redirect
    XScreen*            screen;                            // back pointer to correct screen
} XWindowAttributes;

typedef struct XHostAddress {
    int32_t             family;                            // for example FamilyInternet
    int32_t             length;                            // length of address, in bytes
    char*               address;                           // pointer to where to find the bytes
} XHostAddress;

typedef struct XServerInterpretedAddress {
    int32_t             typelength;                        // length of type string, in bytes
    int32_t             valuelength;                       // length of value string, in bytes
    char*               type;                              // pointer to where to find the type string
    char*               value;                             // pointer to where to find the address
} XServerInterpretedAddress;

typedef struct XImage {
    int32_t             width;                             // size of image
    int32_t             height;                            // size of image
    int32_t             xoffset;                           // number of pixels offset in X direction
    int32_t             format;                            // XYBitmap, XYPixmap, ZPixmap
    char*               data;                              // pointer to image data
    int32_t             byte_order;                        // data byte order, LSBFirst, MSBFirst
    int32_t             bitmap_unit;                       // quant. of scanline 8, 16, 32
    int32_t             bitmap_bit_order;                  // LSBFirst, MSBFirst
    int32_t             bitmap_pad;                        // 8, 16, 32 either XY or ZPixmap
    int32_t             depth;                             // depth of image
    int32_t             bytes_per_line;                    // accelerator to next line
    int32_t             bits_per_pixel;                    // bits per pixel (ZPixmap)
    uint64_t            red_mask;                          // bits in z arrangement
    uint64_t            green_mask;                        // bits in z arrangement
    uint64_t            blue_mask;                         // bits in z arrangement
    void*               obdata;                            // hook for the object routines to hang on
    struct funcs {
        XImage*       (*create_image)(XDisplay*,XVisual*,uint32_t,int32_t,int32_t,char*,uint32_t,uint32_t,int32_t,int32_t);
        int32_t       (*destroy_image)(XImage*);
        uint64_t      (*get_pixel)(XImage*,int32_t,int32_t);
        int32_t       (*put_pixel)(XImage*,int32_t,int32_t,uint64_t);
        XImage*       (*sub_image)(XImage*,int32_t,int32_t,uint32_t,uint32_t);
        int32_t       (*add_pixel)(XImage*,int64_t);
    }                   f;                                 // image manipulation routines
} XImage;

typedef struct XWindowChanges {
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
    int32_t             width, height;                     // ???
    int32_t             border_width;                      // ???
    XWindow             sibling;                           // ???
    int32_t             stack_mode;                        // ???
} XWindowChanges;

typedef struct XColor {
    uint64_t            pixel;                             // ???
    uint16_t            red;                               // ???
    uint16_t            green;                             // ???
    uint16_t            blue;                              // ???
    char                flags;                             // do_red, do_green, do_blue
    char                pad;                               // ???
} XColor;

typedef struct XSegment {
    int16_t             x1;                                // ???
    int16_t             y1;                                // ???
    int16_t             x2;                                // ???
    int16_t             y2;                                // ???
} XSegment;

typedef struct XPoint {
    int16_t             x;                                 // ???
    int16_t             y;                                 // ???
} XPoint;

typedef struct XRectangle {
    int16_t             x;                                 // ???
    int16_t             y;                                 // ???
    uint16_t            width;                             // ???
    uint16_t            height;                            // ???
} XRectangle;

typedef struct XArc {
    int16_t             x;                                 // ???
    int16_t             y;                                 // ???
    uint16_t            width;                             // ???
    uint16_t            height;                            // ???
    int16_t             angle1;                            // ???
    int16_t             angle2;                            // ???
} XArc;

typedef struct XKeyboardControl {
    int32_t             key_click_percent;                 // ???
    int32_t             bell_percent;                      // ???
    int32_t             bell_pitch;                        // ???
    int32_t             bell_duration;                     // ???
    int32_t             led;                               // ???
    int32_t             led_mode;                          // ???
    int32_t             key;                               // ???
    int32_t             auto_repeat_mode;                  // On, Off, Default
} XKeyboardControl;

typedef struct XKeyboardState {
    int32_t             key_click_percent;                 // ???
    int32_t             bell_percent;                      // ???
    uint32_t            bell_pitch, bell_duration;         // ???
    uint64_t            led_mask;                          // ???
    int32_t             global_auto_repeat;                // ???
    char                auto_repeats[32];                  // ???
} XKeyboardState;

typedef struct XTimeCoord {
    XTime               time;                              // ???
    int16_t             x;                                 // ???
    int16_t             y;                                 // ???
} XTimeCoord;

typedef struct XModifierKeymap {
    int32_t             max_keypermod;                     // The server's max # of keys per modifier
    XKeyCode*           modifiermap;                       // An 8 by max_keypermod array of modifiers
} XModifierKeymap;

typedef struct XDisplay {
    XExtData*           ext_data;                          // hook for extension to hang data
    XPrivate*           private1;                          // ???
    int32_t             fd;                                // Network socket
    int32_t             private2;                          // ???
    int32_t             proto_major_version;               // major version of server's X protocol
    int32_t             proto_minor_version;               // minor version of servers X protocol
    char*               vendor;                            // vendor of the server hardware
    XID                 private3;                          // ???
    XID                 private4;                          // ???
    XID                 private5;                          // ???
    int32_t             private6;                          // ???
    XID               (*resource_alloc)(XDisplay*);        // allocator function
    int32_t             byte_order;                        // screen byte order, LSBFirst, MSBFirst */
    int32_t             bitmap_unit;                       // padding and data requirements */
    int32_t             bitmap_pad;                        // padding requirements on bitmaps */
    int32_t             bitmap_bit_order;                  // LeastSignificant or MostSignificant */
    int32_t             nformats;                          // number of pixmap formats in list */
    XScreenFormat*      pixmap_format;                     // pixmap format list
    int32_t             private8;                          // ???
    int32_t             release;                           // release of the server
    XPrivate*           private9;                          // ???
    XPrivate*           private10;                         // ???
    int32_t             qlen;                              // Length of input event queue
    uint64_t            last_request_read;                 // seq number of last event read
    uint64_t            request;                           // sequence number of last request
    void*               private11;                         // ???
    void*               private12;                         // ???
    void*               private13;                         // ???
    void*               private14;                         // ???
    unsigned            max_request_size;                  // maximum number 32 bit words in request
    XrmHashBucketRec*   db;                                // ???
    int32_t           (*private15)(XDisplay*);             // ???
    char*               display_name;                      // "host:display" string used on this connect
    int32_t             default_screen;                    // default screen for operations
    int32_t             nscreens;                          // number of screens on this server
    XScreen*            screens;                           // pointer to list of screens
    uint64_t            motion_buffer;                     // size of motion buffer
    uint64_t            private16;                         // ???
    int32_t             min_keycode;                       // minimum defined keycode
    int32_t             max_keycode;                       // maximum defined keycode
    void*               private17;                         // ???
    void*               private18;                         // ???
    int32_t             private19;                         // ???
    char*               xdefaults;                         // contents of defaults from server
} XDisplay;

typedef struct XKeyEvent {
    int32_t             type;                              // of event
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // "event" window it is reported relative to
    XWindow             root;                              // root window that the event occurred on
    XWindow             subwindow;                         // child window
    XTime               time;                              // milliseconds
    int32_t             x;                                 // pointer x coordinates in event window
    int32_t             y;                                 // pointer y coordinates in event window
    int32_t             x_root;                            // coordinates relative to root
    int32_t             y_root;                            // coordinates relative to root
    uint32_t            state;                             // key or button mask
    uint32_t            keycode;                           // detail
    int32_t             same_screen;                       // same screen flag
} XKeyEvent;

typedef struct XButtonEvent {
    int32_t             type;                              // of event
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // "event" window it is reported relative to
    XWindow             root;                              // root window that the event occurred on
    XWindow             subwindow;                         // child window
    XTime               time;                              // milliseconds
    int32_t             x;                                 // pointer x coordinates in event window
    int32_t             y;                                 // pointer y coordinates in event window
    int32_t             x_root;                            // coordinates relative to root
    int32_t             y_root;                            // coordinates relative to root
    uint32_t            state;                             // key or button mask
    uint32_t            button;                            // detail
    int32_t             same_screen;                       // same screen flag
} XButtonEvent;

typedef struct XMotionEvent {
    int32_t             type;                              // of event
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // "event" window reported relative to
    XWindow             root;                              // root window that the event occurred on
    XWindow             subwindow;                         // child window
    XTime               time;                              // milliseconds
    int32_t             x;                                 // pointer x coordinates in event window
    int32_t             y;                                 // pointer y coordinates in event window
    int32_t             x_root;                            // coordinates relative to root
    int32_t             y_root;                            // coordinates relative to root
    uint32_t            state;                             // key or button mask
    char                is_hint;                           // detail
    int32_t             same_screen;                       // same screen flag
} XMotionEvent;

typedef struct XCrossingEvent {
    int32_t             type;                              // of event
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // "event" window reported relative to
    XWindow             root;                              // root window that the event occurred on
    XWindow             subwindow;                         // child window
    XTime               time;                              // milliseconds
    int32_t             x;                                 // pointer x coordinates in event window
    int32_t             y;                                 // pointer y coordinates in event window
    int32_t             x_root;                            // coordinates relative to root
    int32_t             y_root;                            // coordinates relative to root
    int32_t             mode;                              // NotifyNormal, NotifyGrab, NotifyUngrab
    int32_t             detail;                            // ???
    int32_t             same_screen;                       // same screen flag
    int32_t             focus;                             // boolean focus
    uint32_t            state;                             // key or button mask
} XCrossingEvent;

typedef struct XFocusChangeEvent {
    int32_t             type;                              // FocusIn or FocusOut
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // window of event
    int32_t             mode;                              // NotifyNormal, NotifyWhileGrabbed, NotifyGrab, NotifyUngrab
    int32_t             detail;                            // ???
} XFocusChangeEvent;

typedef struct XKeymapEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    char                key_vector[32];                    // ???
} XKeymapEvent;

typedef struct XExposeEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
    int32_t             width;                             // ???
    int32_t             height;                            // ???
    int32_t             count;                             // if non-zero, at least this many more
} XExposeEvent;

typedef struct XGraphicsExposeEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XDrawable           drawable;                          // ???
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
    int32_t             width;                             // ???
    int32_t             height;                            // ???
    int32_t             count;                             // if non-zero, at least this many more
    int32_t             major_code;                        // core is CopyArea or CopyPlane
    int32_t             minor_code;                        // not defined in the core
} XGraphicsExposeEvent;

typedef struct XNoExposeEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XDrawable           drawable;                          // ???
    int32_t             major_code;                        // core is CopyArea or CopyPlane
    int32_t             minor_code;                        // not defined in the core
} XNoExposeEvent;

typedef struct XVisibilityEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    int32_t             state;                             // Visibility state
} XVisibilityEvent;

typedef struct XCreateWindowEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             parent;                            // parent of the window
    XWindow             window;                            // window id of window created
    int32_t             x;                                 // window location
    int32_t             y;                                 // window location
    int32_t             width;                             // size of window
    int32_t             height;                            // size of window
    int32_t             border_width;                      // border width
    int32_t             override_redirect;                 // creation should be overridden
} XCreateWindowEvent;

typedef struct XDestroyWindowEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
} XDestroyWindowEvent;

typedef struct XUnmapEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
    int32_t             from_configure;                    // ???
} XUnmapEvent;

typedef struct XMapEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
    int32_t             override_redirect;                 // boolean, is override set...
} XMapEvent;

typedef struct XMapRequestEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             parent;                            // ???
    XWindow             window;                            // ???
} XMapRequestEvent;

typedef struct XReparentEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
    XWindow             parent;                            // ???
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
    int32_t             override_redirect;                 // ???
} XReparentEvent;

typedef struct XConfigureEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
    int32_t             width;                             // ???
    int32_t             height;                            // ???
    int32_t             border_width;                      // ???
    XWindow             above;                             // ???
    int32_t             override_redirect;                 // ???
} XConfigureEvent;

typedef struct XGravityEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
} XGravityEvent;

typedef struct XResizeRequestEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    int32_t             width;                             // ???
    int32_t             height;                            // ???
} XResizeRequestEvent;

typedef struct XConfigureRequestEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             parent;                            // ???
    XWindow             window;                            // ???
    int32_t             x;                                 // ???
    int32_t             y;                                 // ???
    int32_t             width, height;                     // ???
    int32_t             border_width;                      // ???
    XWindow             above;                             // ???
    int32_t             detail;                            // Above, Below, TopIf, BottomIf, Opposite
    uint64_t            value_mask;                        // ???
} XConfigureRequestEvent;

typedef struct XCirculateEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             event;                             // ???
    XWindow             window;                            // ???
    int32_t             place;                             // PlaceOnTop, PlaceOnBottom
} XCirculateEvent;

typedef struct XCirculateRequestEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             parent;                            // ???
    XWindow             window;                            // ???
    int32_t             place;                             // PlaceOnTop, PlaceOnBottom
} XCirculateRequestEvent;

typedef struct XPropertyEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    XAtom               atom;                              // ???
    XTime               time;                              // ???
    int32_t             state;                             // NewValue, Deleted
} XPropertyEvent;

typedef struct XSelectionClearEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    XAtom               selection;                         // ???
    XTime               time;                              // ???
} XSelectionClearEvent;

typedef struct XSelectionRequestEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             owner;                             // ???
    XWindow             requestor;                         // ???
    XAtom               selection;                         // ???
    XAtom               target;                            // ???
    XAtom               property;                          // ???
    XTime               time;                              // ???
} XSelectionRequestEvent;

typedef struct XSelectionEvent {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             requestor;                         // ???
    XAtom               selection;                         // ???
    XAtom               target;                            // ???
    XAtom               property;                          // ATOM or None
    XTime               time;                              // ???
} XSelectionEvent;

typedef struct {
    int32_t             type;                              // ???
    uint64_t            serial;                            // # of last request processed by server
    int32_t             send_event;                        // true if this came from a SendEvent request
    XDisplay*           display;                           // Display the event was read from
    XWindow             window;                            // ???
    XColormap           colormap;                          // COLORMAP or None
    int32_t             c_new;                             // C++
    int32_t             state;                             // ColormapInstalled, ColormapUninstalled
} XColormapEvent;

typedef struct {
    int32_t type;
    uint64_t serial;    /* # of last request processed by server */
    int32_t send_event;    /* true if this came from a SendEvent request */
    Display *display;    /* Display the event was read from */
    XWindow window;
    XAtom message_type;
    int32_t format;
    union {
        char b[20];
        int16_t s[10];
        int64_t l[5];
        } data;
} XClientMessageEvent;

typedef struct {
    int32_t type;
    uint64_t serial;    /* # of last request processed by server */
    int32_t send_event;    /* true if this came from a SendEvent request */
    Display *display;    /* Display the event was read from */
    XWindow window;        /* unused */
    int32_t request;        /* one of MappingModifier, MappingKeyboard,
                   MappingPointer */
    int32_t first_keycode;    /* first keycode */
    int32_t count;        /* defines range of change w. first_keycode*/
} XMappingEvent;

typedef struct {
    int32_t type;
    Display *display;    /* Display the event was read from */
    XID resourceid;        /* resource id */
    uint64_t serial;    /* serial number of failed request */
    unsigned char error_code;    /* error code of failed request */
    unsigned char request_code;    /* Major op-code of failed request */
    unsigned char minor_code;    /* Minor op-code of failed request */
} XErrorEvent;

typedef struct {
    int32_t type;
    uint64_t serial;    /* # of last request processed by server */
    int32_t send_event;    /* true if this came from a SendEvent request */
    Display *display;/* Display the event was read from */
    XWindow window;    /* window on which event was requested in event mask */
} XAnyEvent;


/***************************************************************
 *
 * GenericEvent.  This event is the standard event for all newer extensions.
 */

typedef struct
    {
    int32_t            type;         /* of event. Always GenericEvent */
    uint64_t  serial;       /* # of last request processed */
    int32_t           send_event;   /* true if from SendEvent request */
    Display        *display;     /* Display the event was read from */
    int32_t            extension;    /* major opcode of extension that caused the event */
    int32_t            evtype;       /* actual event type. */
    } XGenericEvent;

typedef struct {
    int32_t            type;         /* of event. Always GenericEvent */
    uint64_t  serial;       /* # of last request processed */
    int32_t           send_event;   /* true if from SendEvent request */
    Display        *display;     /* Display the event was read from */
    int32_t            extension;    /* major opcode of extension that caused the event */
    int32_t            evtype;       /* actual event type. */
    uint32_t   cookie;
    void           *data;
} XGenericEventCookie;

/*
 * this union is defined so Xlib can always use the same sized
 * event structure internally, to avoid memory fragmentation.
 */
typedef union _XEvent {
        int32_t type;        /* must not be changed; first element */
    XAnyEvent xany;
    XKeyEvent xkey;
    XButtonEvent xbutton;
    XMotionEvent xmotion;
    XCrossingEvent xcrossing;
    XFocusChangeEvent xfocus;
    XExposeEvent xexpose;
    XGraphicsExposeEvent xgraphicsexpose;
    XNoExposeEvent xnoexpose;
    XVisibilityEvent xvisibility;
    XCreateWindowEvent xcreatewindow;
    XDestroyWindowEvent xdestroywindow;
    XUnmapEvent xunmap;
    XMapEvent xmap;
    XMapRequestEvent xmaprequest;
    XReparentEvent xreparent;
    XConfigureEvent xconfigure;
    XGravityEvent xgravity;
    XResizeRequestEvent xresizerequest;
    XConfigureRequestEvent xconfigurerequest;
    XCirculateEvent xcirculate;
    XCirculateRequestEvent xcirculaterequest;
    XPropertyEvent xproperty;
    XSelectionClearEvent xselectionclear;
    XSelectionRequestEvent xselectionrequest;
    XSelectionEvent xselection;
    XColormapEvent xcolormap;
    XClientMessageEvent xclient;
    XMappingEvent xmapping;
    XErrorEvent xerror;
    XKeymapEvent xkeymap;
    XGenericEvent xgeneric;
    XGenericEventCookie xcookie;
    int64_t pad[24];
} XEvent;
#endif


/*
 * per character font metric information.
 */
typedef struct {
    int16_t    lbearing;    /* origin to left edge of raster */
    int16_t    rbearing;    /* origin to right edge of raster */
    int16_t    width;        /* advance to next char's origin */
    int16_t    ascent;        /* baseline to top edge of raster */
    int16_t    descent;    /* baseline to bottom edge of raster */
    uint16_t attributes;    /* per char flags (not predefined) */
} XCharStruct;

/*
 * To allow arbitrary information with fonts, there are additional properties
 * returned.
 */
typedef struct {
    XAtom name;
    uint64_t card32;
} XFontProp;

typedef struct {
    XExtData    *ext_data;    /* hook for extension to hang data */
    Font        fid;            /* Font id for this font */
    unsigned    direction;    /* hint about direction the font is painted */
    unsigned    min_char_or_byte2;/* first character */
    unsigned    max_char_or_byte2;/* last character */
    unsigned    min_byte1;    /* first row that exists */
    unsigned    max_byte1;    /* last row that exists */
    int32_t    all_chars_exist;/* flag if all characters have non-zero size*/
    unsigned    default_char;    /* char to print for undefined character */
    int32_t         n_properties;   /* how many properties there are */
    XFontProp    *properties;    /* pointer to array of additional properties*/
    XCharStruct    min_bounds;    /* minimum bounds over all existing char*/
    XCharStruct    max_bounds;    /* maximum bounds over all existing char*/
    XCharStruct    *per_char;    /* first_char to last_char information */
    int32_t        ascent;        /* log. extent above baseline for spacing */
    int32_t        descent;    /* log. descent below baseline for spacing */
} XFontStruct;

/*
 * PolyText routines take these as arguments.
 */
typedef struct {
    char *chars;        /* pointer to string */
    int32_t nchars;            /* number of characters */
    int32_t delta;            /* delta between strings */
    Font font;            /* font to print it in, None don't change */
} XTextItem;

typedef struct {        /* normal 16 bit characters are two bytes */
    unsigned char byte1;
    unsigned char byte2;
} XChar2b;

typedef struct {
    XChar2b *chars;        /* two byte characters */
    int32_t nchars;            /* number of characters */
    int32_t delta;            /* delta between strings */
    Font font;            /* font to print it in, None don't change */
} XTextItem16;


typedef union { Display *display;
        GC gc;
        XVisual *visual;
        Screen *screen;
        ScreenFormat *pixmap_format;
        XFontStruct *font; } XEDataObject;

typedef struct {
    XRectangle      max_ink_extent;
    XRectangle      max_logical_extent;
} XFontSetExtents;

/* unused:
typedef void (*XOMProc)();
 */

typedef struct _XOM *XOM;
typedef struct _XOC *XOC, *XFontSet;

typedef struct {
    char           *chars;
    int32_t             nchars;
    int32_t             delta;
    XFontSet        font_set;
} XmbTextItem;

typedef struct {
    wchar_t        *chars;
    int32_t             nchars;
    int32_t             delta;
    XFontSet        font_set;
} XwcTextItem;

#define XNRequiredCharSet "requiredCharSet"
#define XNQueryOrientation "queryOrientation"
#define XNBaseFontName "baseFontName"
#define XNOMAutomatic "omAutomatic"
#define XNMissingCharSet "missingCharSet"
#define XNDefaultString "defaultString"
#define XNOrientation "orientation"
#define XNDirectionalDependentDrawing "directionalDependentDrawing"
#define XNContextualDrawing "contextualDrawing"
#define XNFontInfo "fontInfo"

typedef struct {
    int32_t charset_count;
    char **charset_list;
} XOMCharSetList;

typedef enum {
    XOMOrientation_LTR_TTB,
    XOMOrientation_RTL_TTB,
    XOMOrientation_TTB_LTR,
    XOMOrientation_TTB_RTL,
    XOMOrientation_Context
} XOrientation;

typedef struct {
    int32_t num_orientation;
    XOrientation *orientation;    /* Input Text description */
} XOMOrientation;

typedef struct {
    int32_t num_font;
    XFontStruct **font_struct_list;
    char **font_name_list;
} XOMFontInfo;

typedef struct _XIM *XIM;
typedef struct _XIC *XIC;

typedef void (*XIMProc)(
    XIM,
    void*,
    void*
);

typedef int32_t (*XICProc)(
    XIC,
    void*,
    void*
);

typedef void (*XIDProc)(
    Display*,
    void*,
    void*
);

typedef uint64_t XIMStyle;

typedef struct {
    uint16_t count_styles;
    XIMStyle *supported_styles;
} XIMStyles;

#define XIMPreeditArea        0x0001L
#define XIMPreeditCallbacks    0x0002L
#define XIMPreeditPosition    0x0004L
#define XIMPreeditNothing    0x0008L
#define XIMPreeditNone        0x0010L
#define XIMStatusArea        0x0100L
#define XIMStatusCallbacks    0x0200L
#define XIMStatusNothing    0x0400L
#define XIMStatusNone        0x0800L

#define XNVaNestedList "XNVaNestedList"
#define XNQueryInputStyle "queryInputStyle"
#define XNClientWindow "clientWindow"
#define XNInputStyle "inputStyle"
#define XNFocusWindow "focusWindow"
#define XNResourceName "resourceName"
#define XNResourceClass "resourceClass"
#define XNGeometryCallback "geometryCallback"
#define XNDestroyCallback "destroyCallback"
#define XNFilterEvents "filterEvents"
#define XNPreeditStartCallback "preeditStartCallback"
#define XNPreeditDoneCallback "preeditDoneCallback"
#define XNPreeditDrawCallback "preeditDrawCallback"
#define XNPreeditCaretCallback "preeditCaretCallback"
#define XNPreeditStateNotifyCallback "preeditStateNotifyCallback"
#define XNPreeditAttributes "preeditAttributes"
#define XNStatusStartCallback "statusStartCallback"
#define XNStatusDoneCallback "statusDoneCallback"
#define XNStatusDrawCallback "statusDrawCallback"
#define XNStatusAttributes "statusAttributes"
#define XNArea "area"
#define XNAreaNeeded "areaNeeded"
#define XNSpotLocation "spotLocation"
#define XNColormap "colorMap"
#define XNStdColormap "stdColorMap"
#define XNForeground "foreground"
#define XNBackground "background"
#define XNBackgroundPixmap "backgroundPixmap"
#define XNFontSet "fontSet"
#define XNLineSpace "lineSpace"
#define XNCursor "cursor"

#define XNQueryIMValuesList "queryIMValuesList"
#define XNQueryICValuesList "queryICValuesList"
#define XNVisiblePosition "visiblePosition"
#define XNR6PreeditCallback "r6PreeditCallback"
#define XNStringConversionCallback "stringConversionCallback"
#define XNStringConversion "stringConversion"
#define XNResetState "resetState"
#define XNHotKey "hotKey"
#define XNHotKeyState "hotKeyState"
#define XNPreeditState "preeditState"
#define XNSeparatorofNestedList "separatorofNestedList"

#define XBufferOverflow        -1
#define XLookupNone        1
#define XLookupChars        2
#define XLookupKeySym        3
#define XLookupBoth        4

typedef void *XVaNestedList;

typedef struct {
    void* client_data;
    XIMProc callback;
} XIMCallback;

typedef struct {
    void* client_data;
    XICProc callback;
} XICCallback;

typedef uint64_t XIMFeedback;

#define XIMReverse        1L
#define XIMUnderline        (1L<<1)
#define XIMHighlight        (1L<<2)
#define XIMPrimary         (1L<<5)
#define XIMSecondary        (1L<<6)
#define XIMTertiary         (1L<<7)
#define XIMVisibleToForward     (1L<<8)
#define XIMVisibleToBackword     (1L<<9)
#define XIMVisibleToCenter     (1L<<10)

typedef struct _XIMText {
    uint16_t length;
    XIMFeedback *feedback;
    int32_t encoding_is_wchar;
    union {
    char *multi_byte;
    wchar_t *wide_char;
    } string;
} XIMText;

typedef    uint64_t     XIMPreeditState;

#define    XIMPreeditUnKnown    0L
#define    XIMPreeditEnable    1L
#define    XIMPreeditDisable    (1L<<1)

typedef    struct    _XIMPreeditStateNotifyCallbackStruct {
    XIMPreeditState state;
} XIMPreeditStateNotifyCallbackStruct;

typedef    uint64_t     XIMResetState;

#define    XIMInitialState        1L
#define    XIMPreserveState    (1L<<1)

typedef uint64_t XIMStringConversionFeedback;

#define    XIMStringConversionLeftEdge    (0x00000001)
#define    XIMStringConversionRightEdge    (0x00000002)
#define    XIMStringConversionTopEdge    (0x00000004)
#define    XIMStringConversionBottomEdge    (0x00000008)
#define    XIMStringConversionConcealed    (0x00000010)
#define    XIMStringConversionWrapped    (0x00000020)

typedef struct _XIMStringConversionText {
    uint16_t length;
    XIMStringConversionFeedback *feedback;
    int32_t encoding_is_wchar;
    union {
    char *mbs;
    wchar_t *wcs;
    } string;
} XIMStringConversionText;

typedef    uint16_t    XIMStringConversionPosition;

typedef    uint16_t    XIMStringConversionType;

#define    XIMStringConversionBuffer    (0x0001)
#define    XIMStringConversionLine        (0x0002)
#define    XIMStringConversionWord        (0x0003)
#define    XIMStringConversionChar        (0x0004)

typedef    uint16_t    XIMStringConversionOperation;

#define    XIMStringConversionSubstitution    (0x0001)
#define    XIMStringConversionRetrieval    (0x0002)

typedef enum {
    XIMForwardChar, XIMBackwardChar,
    XIMForwardWord, XIMBackwardWord,
    XIMCaretUp, XIMCaretDown,
    XIMNextLine, XIMPreviousLine,
    XIMLineStart, XIMLineEnd,
    XIMAbsolutePosition,
    XIMDontChange
} XIMCaretDirection;

typedef struct _XIMStringConversionCallbackStruct {
    XIMStringConversionPosition position;
    XIMCaretDirection direction;
    XIMStringConversionOperation operation;
    uint16_t factor;
    XIMStringConversionText *text;
} XIMStringConversionCallbackStruct;

typedef struct _XIMPreeditDrawCallbackStruct {
    int32_t caret;        /* XCursor offset within pre-edit string */
    int32_t chg_first;    /* Starting change position */
    int32_t chg_length;    /* Length of the change in character count */
    XIMText *text;
} XIMPreeditDrawCallbackStruct;

typedef enum {
    XIMIsInvisible,    /* Disable caret feedback */
    XIMIsPrimary,    /* UI defined caret feedback */
    XIMIsSecondary    /* UI defined caret feedback */
} XIMCaretStyle;

typedef struct _XIMPreeditCaretCallbackStruct {
    int32_t position;         /* Caret offset within pre-edit string */
    XIMCaretDirection direction; /* Caret moves direction */
    XIMCaretStyle style;     /* Feedback of the caret */
} XIMPreeditCaretCallbackStruct;

typedef enum {
    XIMTextType,
    XIMBitmapType
} XIMStatusDataType;

typedef struct _XIMStatusDrawCallbackStruct {
    XIMStatusDataType type;
    union {
    XIMText *text;
    XPixmap  bitmap;
    } data;
} XIMStatusDrawCallbackStruct;

typedef struct _XIMHotKeyTrigger {
    KeySym     keysym;
    int32_t         modifier;
    int32_t         modifier_mask;
} XIMHotKeyTrigger;

typedef struct _XIMHotKeyTriggers {
    int32_t             num_hot_key;
    XIMHotKeyTrigger    *key;
} XIMHotKeyTriggers;

typedef    uint64_t     XIMHotKeyState;

#define    XIMHotKeyStateON    (0x0001L)
#define    XIMHotKeyStateOFF    (0x0002L)

typedef struct {
    uint16_t count_values;
    char **supported_values;
} XIMValuesList;

_XFUNCPROTOBEGIN

#if defined(WIN32) && !defined(_XLIBINT_)
#define _Xdebug (*_Xdebug_p)
#endif

extern int32_t _Xdebug;



extern int32_t
_Xmblen(
    char *str,
    int32_t len
    );

extern XFontStruct *XLoadQueryFont(
    Display*        /* display */,
    _Xconst char*    /* name */
);

extern XFontStruct *XQueryFont(
    Display*        /* display */,
    XID            /* font_ID */
);


extern XTimeCoord *XGetMotionEvents(
    Display*        /* display */,
    XWindow        /* w */,
    XTime        /* start */,
    XTime        /* stop */,
    int32_t*        /* nevents_return */
);

extern XModifierKeymap *XDeleteModifiermapEntry(
    XModifierKeymap*    /* modmap */,
#if NeedWidePrototypes
    uint32_t    /* keycode_entry */,
#else
    KeyCode        /* keycode_entry */,
#endif
    int32_t            /* modifier */
);

extern XModifierKeymap    *XGetModifierMapping(
    Display*        /* display */
);

extern XModifierKeymap    *XInsertModifiermapEntry(
    XModifierKeymap*    /* modmap */,
#if NeedWidePrototypes
    uint32_t    /* keycode_entry */,
#else
    KeyCode        /* keycode_entry */,
#endif
    int32_t            /* modifier */
);

extern XModifierKeymap *XNewModifiermap(
    int32_t            /* max_keys_per_mod */
);

extern XImage *XCreateImage(
    Display*        /* display */,
    XVisual*        /* visual */,
    uint32_t    /* depth */,
    int32_t            /* format */,
    int32_t            /* offset */,
    char*        /* data */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t            /* bitmap_pad */,
    int32_t            /* bytes_per_line */
);
extern int32_t XInitImage(
    XImage*        /* image */
);
extern XImage *XGetImage(
    Display*        /* display */,
    Drawable        /* d */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint64_t    /* plane_mask */,
    int32_t            /* format */
);
extern XImage *XGetSubImage(
    Display*        /* display */,
    Drawable        /* d */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint64_t    /* plane_mask */,
    int32_t            /* format */,
    XImage*        /* dest_image */,
    int32_t            /* dest_x */,
    int32_t            /* dest_y */
);

/*
 * X function declarations.
 */
extern Display *XOpenDisplay(
    _Xconst char*    /* display_name */
);

extern void XrmInitialize(
    void
);

extern char *XFetchBytes(
    Display*        /* display */,
    int32_t*        /* nbytes_return */
);
extern char *XFetchBuffer(
    Display*        /* display */,
    int32_t*        /* nbytes_return */,
    int32_t            /* buffer */
);
extern char *XGetAtomName(
    Display*        /* display */,
    XAtom        /* atom */
);
extern int32_t XGetAtomNames(
    Display*        /* dpy */,
    XAtom*        /* atoms */,
    int32_t            /* count */,
    char**        /* names_return */
);
extern char *XGetDefault(
    Display*        /* display */,
    _Xconst char*    /* program */,
    _Xconst char*    /* option */
);
extern char *XDisplayName(
    _Xconst char*    /* string */
);
extern char *XKeysymToString(
    KeySym        /* keysym */
);

extern int32_t (*XSynchronize(
    Display*        /* display */,
    int32_t        /* onoff */
))(
    Display*        /* display */
);
extern int32_t (*XSetAfterFunction(
    Display*        /* display */,
    int32_t (*) (
         Display*    /* display */
            )        /* procedure */
))(
    Display*        /* display */
);
extern XAtom XInternAtom(
    Display*        /* display */,
    _Xconst char*    /* atom_name */,
    int32_t        /* only_if_exists */
);
extern int32_t XInternAtoms(
    Display*        /* dpy */,
    char**        /* names */,
    int32_t            /* count */,
    int32_t        /* onlyIfExists */,
    XAtom*        /* atoms_return */
);
extern XColormap XCopyColormapAndFree(
    Display*        /* display */,
    XColormap        /* colormap */
);
extern XColormap XCreateColormap(
    Display*        /* display */,
    XWindow        /* w */,
    XVisual*        /* visual */,
    int32_t            /* alloc */
);
extern XCursor XCreatePixmapCursor(
    Display*        /* display */,
    XPixmap        /* source */,
    XPixmap        /* mask */,
    XColor*        /* foreground_color */,
    XColor*        /* background_color */,
    uint32_t    /* x */,
    uint32_t    /* y */
);
extern XCursor XCreateGlyphCursor(
    Display*        /* display */,
    Font        /* source_font */,
    Font        /* mask_font */,
    uint32_t    /* source_char */,
    uint32_t    /* mask_char */,
    XColor _Xconst *    /* foreground_color */,
    XColor _Xconst *    /* background_color */
);
extern XCursor XCreateFontCursor(
    Display*        /* display */,
    uint32_t    /* shape */
);
extern Font XLoadFont(
    Display*        /* display */,
    _Xconst char*    /* name */
);
extern GC XCreateGC(
    Display*        /* display */,
    Drawable        /* d */,
    uint64_t    /* valuemask */,
    XGCValues*        /* values */
);
extern GContext XGContextFromGC(
    GC            /* gc */
);
extern void XFlushGC(
    Display*        /* display */,
    GC            /* gc */
);
extern XPixmap XCreatePixmap(
    Display*        /* display */,
    Drawable        /* d */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint32_t    /* depth */
);
extern XPixmap XCreateBitmapFromData(
    Display*        /* display */,
    Drawable        /* d */,
    _Xconst char*    /* data */,
    uint32_t    /* width */,
    uint32_t    /* height */
);
extern XPixmap XCreatePixmapFromBitmapData(
    Display*        /* display */,
    Drawable        /* d */,
    char*        /* data */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint64_t    /* fg */,
    uint64_t    /* bg */,
    uint32_t    /* depth */
);
extern XWindow XCreateSimpleWindow(
    Display*        /* display */,
    XWindow        /* parent */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint32_t    /* border_width */,
    uint64_t    /* border */,
    uint64_t    /* background */
);
extern XWindow XGetSelectionOwner(
    Display*        /* display */,
    XAtom        /* selection */
);
extern XWindow XCreateWindow(
    Display*        /* display */,
    XWindow        /* parent */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint32_t    /* border_width */,
    int32_t            /* depth */,
    uint32_t    /* class */,
    XVisual*        /* visual */,
    uint64_t    /* valuemask */,
    XSetWindowAttributes*    /* attributes */
);
extern XColormap *XListInstalledColormaps(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t*        /* num_return */
);
extern char **XListFonts(
    Display*        /* display */,
    _Xconst char*    /* pattern */,
    int32_t            /* maxnames */,
    int32_t*        /* actual_count_return */
);
extern char **XListFontsWithInfo(
    Display*        /* display */,
    _Xconst char*    /* pattern */,
    int32_t            /* maxnames */,
    int32_t*        /* count_return */,
    XFontStruct**    /* info_return */
);
extern char **XGetFontPath(
    Display*        /* display */,
    int32_t*        /* npaths_return */
);
extern char **XListExtensions(
    Display*        /* display */,
    int32_t*        /* nextensions_return */
);
extern XAtom *XListProperties(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t*        /* num_prop_return */
);
extern XHostAddress *XListHosts(
    Display*        /* display */,
    int32_t*        /* nhosts_return */,
    int32_t*        /* state_return */
);
_X_DEPRECATED
extern KeySym XKeycodeToKeysym(
    Display*        /* display */,
#if NeedWidePrototypes
    uint32_t    /* keycode */,
#else
    KeyCode        /* keycode */,
#endif
    int32_t            /* index */
);
extern KeySym XLookupKeysym(
    XKeyEvent*        /* key_event */,
    int32_t            /* index */
);
extern KeySym *XGetKeyboardMapping(
    Display*        /* display */,
#if NeedWidePrototypes
    uint32_t    /* first_keycode */,
#else
    KeyCode        /* first_keycode */,
#endif
    int32_t            /* keycode_count */,
    int32_t*        /* keysyms_per_keycode_return */
);
extern KeySym XStringToKeysym(
    _Xconst char*    /* string */
);
extern int64_t XMaxRequestSize(
    Display*        /* display */
);
extern int64_t XExtendedMaxRequestSize(
    Display*        /* display */
);
extern char *XResourceManagerString(
    Display*        /* display */
);
extern char *XScreenResourceString(
    Screen*        /* screen */
);
extern uint64_t XDisplayMotionBufferSize(
    Display*        /* display */
);
extern VisualID XVisualIDFromVisual(
    XVisual*        /* visual */
);

/* multithread routines */

extern int32_t XInitThreads(
    void
);

extern int32_t XFreeThreads(
    void
);

extern void XLockDisplay(
    Display*        /* display */
);

extern void XUnlockDisplay(
    Display*        /* display */
);

/* routines for dealing with extensions */

extern XExtCodes *XInitExtension(
    Display*        /* display */,
    _Xconst char*    /* name */
);

extern XExtCodes *XAddExtension(
    Display*        /* display */
);
extern XExtData *XFindOnExtensionList(
    XExtData**        /* structure */,
    int32_t            /* number */
);
extern XExtData **XEHeadOfExtensionList(
    XEDataObject    /* object */
);

/* these are routines for which there are also macros */
extern XWindow XRootWindow(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern XWindow XDefaultRootWindow(
    Display*        /* display */
);
extern XWindow XRootWindowOfScreen(
    Screen*        /* screen */
);
extern XVisual *XDefaultVisual(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern XVisual *XDefaultVisualOfScreen(
    Screen*        /* screen */
);
extern GC XDefaultGC(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern GC XDefaultGCOfScreen(
    Screen*        /* screen */
);
extern uint64_t XBlackPixel(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern uint64_t XWhitePixel(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern uint64_t XAllPlanes(
    void
);
extern uint64_t XBlackPixelOfScreen(
    Screen*        /* screen */
);
extern uint64_t XWhitePixelOfScreen(
    Screen*        /* screen */
);
extern uint64_t XNextRequest(
    Display*        /* display */
);
extern uint64_t XLastKnownRequestProcessed(
    Display*        /* display */
);
extern char *XServerVendor(
    Display*        /* display */
);
extern char *XDisplayString(
    Display*        /* display */
);
extern XColormap XDefaultColormap(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern XColormap XDefaultColormapOfScreen(
    Screen*        /* screen */
);
extern Display *XDisplayOfScreen(
    Screen*        /* screen */
);
extern Screen *XScreenOfDisplay(
    Display*        /* display */,
    int32_t            /* screen_number */
);
extern Screen *XDefaultScreenOfDisplay(
    Display*        /* display */
);
extern int64_t XEventMaskOfScreen(
    Screen*        /* screen */
);

extern int32_t XScreenNumberOfScreen(
    Screen*        /* screen */
);

typedef int32_t (*XErrorHandler) (        /* WARNING, this type not in Xlib spec */
    Display*        /* display */,
    XErrorEvent*    /* error_event */
);

extern XErrorHandler XSetErrorHandler (
    XErrorHandler    /* handler */
);


typedef int32_t (*XIOErrorHandler) (    /* WARNING, this type not in Xlib spec */
    Display*        /* display */
);

extern XIOErrorHandler XSetIOErrorHandler (
    XIOErrorHandler    /* handler */
);

typedef void (*XIOErrorExitHandler) ( /* WARNING, this type not in Xlib spec */
    Display*,        /* display */
    void*        /* user_data */
);

extern void XSetIOErrorExitHandler (
    Display*,            /* display */
    XIOErrorExitHandler,    /* handler */
    void*            /* user_data */
);

extern XPixmapFormatValues *XListPixmapFormats(
    Display*        /* display */,
    int32_t*        /* count_return */
);
extern int32_t *XListDepths(
    Display*        /* display */,
    int32_t            /* screen_number */,
    int32_t*        /* count_return */
);

/* ICCCM routines for things that don't require special include files; */
/* other declarations are given in Xutil.h                             */
extern int32_t XReconfigureWMWindow(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* screen_number */,
    uint32_t    /* mask */,
    XWindowChanges*    /* changes */
);

extern int32_t XGetWMProtocols(
    Display*        /* display */,
    XWindow        /* w */,
    XAtom**        /* protocols_return */,
    int32_t*        /* count_return */
);
extern int32_t XSetWMProtocols(
    Display*        /* display */,
    XWindow        /* w */,
    XAtom*        /* protocols */,
    int32_t            /* count */
);
extern int32_t XIconifyWindow(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* screen_number */
);
extern int32_t XWithdrawWindow(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* screen_number */
);
extern int32_t XGetCommand(
    Display*        /* display */,
    XWindow        /* w */,
    char***        /* argv_return */,
    int32_t*        /* argc_return */
);
extern int32_t XGetWMColormapWindows(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow**        /* windows_return */,
    int32_t*        /* count_return */
);
extern int32_t XSetWMColormapWindows(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow*        /* colormap_windows */,
    int32_t            /* count */
);
extern void XFreeStringList(
    char**        /* list */
);
extern int32_t XSetTransientForHint(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow        /* prop_window */
);

/* The following are given in alphabetical order */

extern int32_t XActivateScreenSaver(
    Display*        /* display */
);

extern int32_t XAddHost(
    Display*        /* display */,
    XHostAddress*    /* host */
);

extern int32_t XAddHosts(
    Display*        /* display */,
    XHostAddress*    /* hosts */,
    int32_t            /* num_hosts */
);

extern int32_t XAddToExtensionList(
    struct XExtData_t**    /* structure */,
    XExtData*        /* ext_data */
);

extern int32_t XAddToSaveSet(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XAllocColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    XColor*        /* screen_in_out */
);

extern int32_t XAllocColorCells(
    Display*        /* display */,
    XColormap        /* colormap */,
    int32_t            /* contig */,
    uint64_t*    /* plane_masks_return */,
    uint32_t    /* nplanes */,
    uint64_t*    /* pixels_return */,
    uint32_t     /* npixels */
);

extern int32_t XAllocColorPlanes(
    Display*        /* display */,
    XColormap        /* colormap */,
    int32_t        /* contig */,
    uint64_t*    /* pixels_return */,
    int32_t            /* ncolors */,
    int32_t            /* nreds */,
    int32_t            /* ngreens */,
    int32_t            /* nblues */,
    uint64_t*    /* rmask_return */,
    uint64_t*    /* gmask_return */,
    uint64_t*    /* bmask_return */
);

extern int32_t XAllocNamedColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    _Xconst char*    /* color_name */,
    XColor*        /* screen_def_return */,
    XColor*        /* exact_def_return */
);

extern int32_t XAllowEvents(
    Display*        /* display */,
    int32_t            /* event_mode */,
    XTime        /* time */
);

extern int32_t XAutoRepeatOff(
    Display*        /* display */
);

extern int32_t XAutoRepeatOn(
    Display*        /* display */
);

extern int32_t XBell(
    Display*        /* display */,
    int32_t            /* percent */
);

extern int32_t XBitmapBitOrder(
    Display*        /* display */
);

extern int32_t XBitmapPad(
    Display*        /* display */
);

extern int32_t XBitmapUnit(
    Display*        /* display */
);

extern int32_t XCellsOfScreen(
    Screen*        /* screen */
);

extern int32_t XChangeActivePointerGrab(
    Display*        /* display */,
    uint32_t    /* event_mask */,
    XCursor        /* cursor */,
    XTime        /* time */
);

extern int32_t XChangeGC(
    Display*        /* display */,
    GC            /* gc */,
    uint64_t    /* valuemask */,
    XGCValues*        /* values */
);

extern int32_t XChangeKeyboardControl(
    Display*        /* display */,
    uint64_t    /* value_mask */,
    XKeyboardControl*    /* values */
);

extern int32_t XChangeKeyboardMapping(
    Display*        /* display */,
    int32_t            /* first_keycode */,
    int32_t            /* keysyms_per_keycode */,
    KeySym*        /* keysyms */,
    int32_t            /* num_codes */
);

extern int32_t XChangePointerControl(
    Display*        /* display */,
    int32_t        /* do_accel */,
    int32_t        /* do_threshold */,
    int32_t            /* accel_numerator */,
    int32_t            /* accel_denominator */,
    int32_t            /* threshold */
);

extern int32_t XChangeProperty(
    Display*        /* display */,
    XWindow        /* w */,
    XAtom        /* property */,
    XAtom        /* type */,
    int32_t            /* format */,
    int32_t            /* mode */,
    _Xconst unsigned char*    /* data */,
    int32_t            /* nelements */
);

extern int32_t XChangeSaveSet(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* change_mode */
);

extern int32_t XChangeWindowAttributes(
    Display*        /* display */,
    XWindow        /* w */,
    uint64_t    /* valuemask */,
    XSetWindowAttributes* /* attributes */
);

extern int32_t XCheckIfEvent(
    Display*        /* display */,
    XEvent*        /* event_return */,
    int32_t (*) (
           Display*            /* display */,
               XEvent*            /* event */,
               void*            /* arg */
             )        /* predicate */,
    void*        /* arg */
);

extern int32_t XCheckMaskEvent(
    Display*        /* display */,
    int64_t        /* event_mask */,
    XEvent*        /* event_return */
);

extern int32_t XCheckTypedEvent(
    Display*        /* display */,
    int32_t            /* event_type */,
    XEvent*        /* event_return */
);

extern int32_t XCheckTypedWindowEvent(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* event_type */,
    XEvent*        /* event_return */
);

extern int32_t XCheckWindowEvent(
    Display*        /* display */,
    XWindow        /* w */,
    int64_t        /* event_mask */,
    XEvent*        /* event_return */
);

extern int32_t XCirculateSubwindows(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* direction */
);

extern int32_t XCirculateSubwindowsDown(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XCirculateSubwindowsUp(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XClearArea(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t        /* exposures */
);

extern int32_t XClearWindow(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XCloseDisplay(
    Display*        /* display */
);

extern int32_t XConfigureWindow(
    Display*        /* display */,
    XWindow        /* w */,
    uint32_t    /* value_mask */,
    XWindowChanges*    /* values */
);

extern int32_t XConnectionNumber(
    Display*        /* display */
);

extern int32_t XConvertSelection(
    Display*        /* display */,
    XAtom        /* selection */,
    XAtom         /* target */,
    XAtom        /* property */,
    XWindow        /* requestor */,
    XTime        /* time */
);

extern int32_t XCopyArea(
    Display*        /* display */,
    Drawable        /* src */,
    Drawable        /* dest */,
    GC            /* gc */,
    int32_t            /* src_x */,
    int32_t            /* src_y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t            /* dest_x */,
    int32_t            /* dest_y */
);

extern int32_t XCopyGC(
    Display*        /* display */,
    GC            /* src */,
    uint64_t    /* valuemask */,
    GC            /* dest */
);

extern int32_t XCopyPlane(
    Display*        /* display */,
    Drawable        /* src */,
    Drawable        /* dest */,
    GC            /* gc */,
    int32_t            /* src_x */,
    int32_t            /* src_y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t            /* dest_x */,
    int32_t            /* dest_y */,
    uint64_t    /* plane */
);

extern int32_t XDefaultDepth(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDefaultDepthOfScreen(
    Screen*        /* screen */
);

extern int32_t XDefaultScreen(
    Display*        /* display */
);

extern int32_t XDefineCursor(
    Display*        /* display */,
    XWindow        /* w */,
    XCursor        /* cursor */
);

extern int32_t XDeleteProperty(
    Display*        /* display */,
    XWindow        /* w */,
    XAtom        /* property */
);

extern int32_t XDestroyWindow(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XDestroySubwindows(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XDoesBackingStore(
    Screen*        /* screen */
);

extern int32_t XDoesSaveUnders(
    Screen*        /* screen */
);

extern int32_t XDisableAccessControl(
    Display*        /* display */
);


extern int32_t XDisplayCells(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDisplayHeight(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDisplayHeightMM(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDisplayKeycodes(
    Display*        /* display */,
    int32_t*        /* min_keycodes_return */,
    int32_t*        /* max_keycodes_return */
);

extern int32_t XDisplayPlanes(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDisplayWidth(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDisplayWidthMM(
    Display*        /* display */,
    int32_t            /* screen_number */
);

extern int32_t XDrawArc(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t            /* angle1 */,
    int32_t            /* angle2 */
);

extern int32_t XDrawArcs(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XArc*        /* arcs */,
    int32_t            /* narcs */
);

extern int32_t XDrawImageString(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst char*    /* string */,
    int32_t            /* length */
);

extern int32_t XDrawImageString16(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst XChar2b*    /* string */,
    int32_t            /* length */
);

extern int32_t XDrawLine(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x1 */,
    int32_t            /* y1 */,
    int32_t            /* x2 */,
    int32_t            /* y2 */
);

extern int32_t XDrawLines(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XPoint*        /* points */,
    int32_t            /* npoints */,
    int32_t            /* mode */
);

extern int32_t XDrawPoint(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */
);

extern int32_t XDrawPoints(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XPoint*        /* points */,
    int32_t            /* npoints */,
    int32_t            /* mode */
);

extern int32_t XDrawRectangle(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */
);

extern int32_t XDrawRectangles(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XRectangle*        /* rectangles */,
    int32_t            /* nrectangles */
);

extern int32_t XDrawSegments(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XSegment*        /* segments */,
    int32_t            /* nsegments */
);

extern int32_t XDrawString(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst char*    /* string */,
    int32_t            /* length */
);

extern int32_t XDrawString16(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst XChar2b*    /* string */,
    int32_t            /* length */
);

extern int32_t XDrawText(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    XTextItem*        /* items */,
    int32_t            /* nitems */
);

extern int32_t XDrawText16(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    XTextItem16*    /* items */,
    int32_t            /* nitems */
);

extern int32_t XEnableAccessControl(
    Display*        /* display */
);

extern int32_t XEventsQueued(
    Display*        /* display */,
    int32_t            /* mode */
);

extern int32_t XFetchName(
    Display*        /* display */,
    XWindow        /* w */,
    char**        /* window_name_return */
);

extern int32_t XFillArc(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t            /* angle1 */,
    int32_t            /* angle2 */
);

extern int32_t XFillArcs(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XArc*        /* arcs */,
    int32_t            /* narcs */
);

extern int32_t XFillPolygon(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XPoint*        /* points */,
    int32_t            /* npoints */,
    int32_t            /* shape */,
    int32_t            /* mode */
);

extern int32_t XFillRectangle(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */
);

extern int32_t XFillRectangles(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XRectangle*        /* rectangles */,
    int32_t            /* nrectangles */
);

extern int32_t XFlush(
    Display*        /* display */
);

extern int32_t XForceScreenSaver(
    Display*        /* display */,
    int32_t            /* mode */
);

extern int32_t XFree(
    void*        /* data */
);

extern int32_t XFreeColormap(
    Display*        /* display */,
    XColormap        /* colormap */
);

extern int32_t XFreeColors(
    Display*        /* display */,
    XColormap        /* colormap */,
    uint64_t*    /* pixels */,
    int32_t            /* npixels */,
    uint64_t    /* planes */
);

extern int32_t XFreeCursor(
    Display*        /* display */,
    XCursor        /* cursor */
);

extern int32_t XFreeExtensionList(
    char**        /* list */
);

extern int32_t XFreeFont(
    Display*        /* display */,
    XFontStruct*    /* font_struct */
);

extern int32_t XFreeFontInfo(
    char**        /* names */,
    XFontStruct*    /* free_info */,
    int32_t            /* actual_count */
);

extern int32_t XFreeFontNames(
    char**        /* list */
);

extern int32_t XFreeFontPath(
    char**        /* list */
);

extern int32_t XFreeGC(
    Display*        /* display */,
    GC            /* gc */
);

extern int32_t XFreeModifiermap(
    XModifierKeymap*    /* modmap */
);

extern int32_t XFreePixmap(
    Display*        /* display */,
    XPixmap        /* pixmap */
);

extern int32_t XGeometry(
    Display*        /* display */,
    int32_t            /* screen */,
    _Xconst char*    /* position */,
    _Xconst char*    /* default_position */,
    uint32_t    /* bwidth */,
    uint32_t    /* fwidth */,
    uint32_t    /* fheight */,
    int32_t            /* xadder */,
    int32_t            /* yadder */,
    int32_t*        /* x_return */,
    int32_t*        /* y_return */,
    int32_t*        /* width_return */,
    int32_t*        /* height_return */
);

extern int32_t XGetErrorDatabaseText(
    Display*        /* display */,
    _Xconst char*    /* name */,
    _Xconst char*    /* message */,
    _Xconst char*    /* default_string */,
    char*        /* buffer_return */,
    int32_t            /* length */
);

extern int32_t XGetErrorText(
    Display*        /* display */,
    int32_t            /* code */,
    char*        /* buffer_return */,
    int32_t            /* length */
);

extern int32_t XGetFontProperty(
    XFontStruct*    /* font_struct */,
    XAtom        /* atom */,
    uint64_t*    /* value_return */
);

extern int32_t XGetGCValues(
    Display*        /* display */,
    GC            /* gc */,
    uint64_t    /* valuemask */,
    XGCValues*        /* values_return */
);

extern int32_t XGetGeometry(
    Display*        /* display */,
    Drawable        /* d */,
    XWindow*        /* root_return */,
    int32_t*        /* x_return */,
    int32_t*        /* y_return */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */,
    uint32_t*    /* border_width_return */,
    uint32_t*    /* depth_return */
);

extern int32_t XGetIconName(
    Display*        /* display */,
    XWindow        /* w */,
    char**        /* icon_name_return */
);

extern int32_t XGetInputFocus(
    Display*        /* display */,
    XWindow*        /* focus_return */,
    int32_t*        /* revert_to_return */
);

extern int32_t XGetKeyboardControl(
    Display*        /* display */,
    XKeyboardState*    /* values_return */
);

extern int32_t XGetPointerControl(
    Display*        /* display */,
    int32_t*        /* accel_numerator_return */,
    int32_t*        /* accel_denominator_return */,
    int32_t*        /* threshold_return */
);

extern int32_t XGetPointerMapping(
    Display*        /* display */,
    unsigned char*    /* map_return */,
    int32_t            /* nmap */
);

extern int32_t XGetScreenSaver(
    Display*        /* display */,
    int32_t*        /* timeout_return */,
    int32_t*        /* interval_return */,
    int32_t*        /* prefer_blanking_return */,
    int32_t*        /* allow_exposures_return */
);

extern int32_t XGetTransientForHint(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow*        /* prop_window_return */
);

extern int32_t XGetWindowProperty(
    Display*        /* display */,
    XWindow        /* w */,
    XAtom        /* property */,
    int64_t        /* long_offset */,
    int64_t        /* long_length */,
    int32_t        /* delete */,
    XAtom        /* req_type */,
    XAtom*        /* actual_type_return */,
    int32_t*        /* actual_format_return */,
    uint64_t*    /* nitems_return */,
    uint64_t*    /* bytes_after_return */,
    unsigned char**    /* prop_return */
);

extern int32_t XGetWindowAttributes(
    Display*        /* display */,
    XWindow        /* w */,
    XWindowAttributes*    /* window_attributes_return */
);

extern int32_t XGrabButton(
    Display*        /* display */,
    uint32_t    /* button */,
    uint32_t    /* modifiers */,
    XWindow        /* grab_window */,
    int32_t        /* owner_events */,
    uint32_t    /* event_mask */,
    int32_t            /* pointer_mode */,
    int32_t            /* keyboard_mode */,
    XWindow        /* confine_to */,
    XCursor        /* cursor */
);

extern int32_t XGrabKey(
    Display*        /* display */,
    int32_t            /* keycode */,
    uint32_t    /* modifiers */,
    XWindow        /* grab_window */,
    int32_t        /* owner_events */,
    int32_t            /* pointer_mode */,
    int32_t            /* keyboard_mode */
);

extern int32_t XGrabKeyboard(
    Display*        /* display */,
    XWindow        /* grab_window */,
    int32_t        /* owner_events */,
    int32_t            /* pointer_mode */,
    int32_t            /* keyboard_mode */,
    XTime        /* time */
);

extern int32_t XGrabPointer(
    Display*        /* display */,
    XWindow        /* grab_window */,
    int32_t        /* owner_events */,
    uint32_t    /* event_mask */,
    int32_t            /* pointer_mode */,
    int32_t            /* keyboard_mode */,
    XWindow        /* confine_to */,
    XCursor        /* cursor */,
    XTime        /* time */
);

extern int32_t XGrabServer(
    Display*        /* display */
);

extern int32_t XHeightMMOfScreen(
    Screen*        /* screen */
);

extern int32_t XHeightOfScreen(
    Screen*        /* screen */
);

extern int32_t XIfEvent(
    Display*        /* display */,
    XEvent*        /* event_return */,
    int32_t (*) (
           Display*            /* display */,
               XEvent*            /* event */,
               void*            /* arg */
             )        /* predicate */,
    void*        /* arg */
);

extern int32_t XImageByteOrder(
    Display*        /* display */
);

extern int32_t XInstallColormap(
    Display*        /* display */,
    XColormap        /* colormap */
);

extern KeyCode XKeysymToKeycode(
    Display*        /* display */,
    KeySym        /* keysym */
);

extern int32_t XKillClient(
    Display*        /* display */,
    XID            /* resource */
);

extern int32_t XLookupColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    _Xconst char*    /* color_name */,
    XColor*        /* exact_def_return */,
    XColor*        /* screen_def_return */
);

extern int32_t XLowerWindow(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XMapRaised(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XMapSubwindows(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XMapWindow(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XMaskEvent(
    Display*        /* display */,
    int64_t        /* event_mask */,
    XEvent*        /* event_return */
);

extern int32_t XMaxCmapsOfScreen(
    Screen*        /* screen */
);

extern int32_t XMinCmapsOfScreen(
    Screen*        /* screen */
);

extern int32_t XMoveResizeWindow(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* x */,
    int32_t            /* y */,
    uint32_t    /* width */,
    uint32_t    /* height */
);

extern int32_t XMoveWindow(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t            /* x */,
    int32_t            /* y */
);

extern int32_t XNextEvent(
    Display*        /* display */,
    XEvent*        /* event_return */
);

extern int32_t XNoOp(
    Display*        /* display */
);

extern int32_t XParseColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    _Xconst char*    /* spec */,
    XColor*        /* exact_def_return */
);

extern int32_t XParseGeometry(
    _Xconst char*    /* parsestring */,
    int32_t*        /* x_return */,
    int32_t*        /* y_return */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */
);

extern int32_t XPeekEvent(
    Display*        /* display */,
    XEvent*        /* event_return */
);

extern int32_t XPeekIfEvent(
    Display*        /* display */,
    XEvent*        /* event_return */,
    int32_t (*) (
           Display*        /* display */,
               XEvent*        /* event */,
               void*        /* arg */
             )        /* predicate */,
    void*        /* arg */
);

extern int32_t XPending(
    Display*        /* display */
);

extern int32_t XPlanesOfScreen(
    Screen*        /* screen */
);

extern int32_t XProtocolRevision(
    Display*        /* display */
);

extern int32_t XProtocolVersion(
    Display*        /* display */
);


extern int32_t XPutBackEvent(
    Display*        /* display */,
    XEvent*        /* event */
);

extern int32_t XPutImage(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    XImage*        /* image */,
    int32_t            /* src_x */,
    int32_t            /* src_y */,
    int32_t            /* dest_x */,
    int32_t            /* dest_y */,
    uint32_t    /* width */,
    uint32_t    /* height */
);

extern int32_t XQLength(
    Display*        /* display */
);

extern int32_t XQueryBestCursor(
    Display*        /* display */,
    Drawable        /* d */,
    uint32_t        /* width */,
    uint32_t    /* height */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */
);

extern int32_t XQueryBestSize(
    Display*        /* display */,
    int32_t            /* class */,
    Drawable        /* which_screen */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */
);

extern int32_t XQueryBestStipple(
    Display*        /* display */,
    Drawable        /* which_screen */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */
);

extern int32_t XQueryBestTile(
    Display*        /* display */,
    Drawable        /* which_screen */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */
);

extern int32_t XQueryColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    XColor*        /* def_in_out */
);

extern int32_t XQueryColors(
    Display*        /* display */,
    XColormap        /* colormap */,
    XColor*        /* defs_in_out */,
    int32_t            /* ncolors */
);

extern int32_t XQueryExtension(
    Display*        /* display */,
    _Xconst char*    /* name */,
    int32_t*        /* major_opcode_return */,
    int32_t*        /* first_event_return */,
    int32_t*        /* first_error_return */
);

extern int32_t XQueryKeymap(
    Display*        /* display */,
    char [32]        /* keys_return */
);

extern int32_t XQueryPointer(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow*        /* root_return */,
    XWindow*        /* child_return */,
    int32_t*        /* root_x_return */,
    int32_t*        /* root_y_return */,
    int32_t*        /* win_x_return */,
    int32_t*        /* win_y_return */,
    uint32_t*       /* mask_return */
);

extern int32_t XQueryTextExtents(
    Display*        /* display */,
    XID            /* font_ID */,
    _Xconst char*    /* string */,
    int32_t            /* nchars */,
    int32_t*        /* direction_return */,
    int32_t*        /* font_ascent_return */,
    int32_t*        /* font_descent_return */,
    XCharStruct*    /* overall_return */
);

extern int32_t XQueryTextExtents16(
    Display*        /* display */,
    XID            /* font_ID */,
    _Xconst XChar2b*    /* string */,
    int32_t            /* nchars */,
    int32_t*        /* direction_return */,
    int32_t*        /* font_ascent_return */,
    int32_t*        /* font_descent_return */,
    XCharStruct*    /* overall_return */
);

extern int32_t XQueryTree(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow*        /* root_return */,
    XWindow*        /* parent_return */,
    XWindow**        /* children_return */,
    uint32_t*    /* nchildren_return */
);

extern int32_t XRaiseWindow(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XReadBitmapFile(
    Display*        /* display */,
    Drawable         /* d */,
    _Xconst char*    /* filename */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */,
    XPixmap*        /* bitmap_return */,
    int32_t*        /* x_hot_return */,
    int32_t*        /* y_hot_return */
);

extern int32_t XReadBitmapFileData(
    _Xconst char*    /* filename */,
    uint32_t*    /* width_return */,
    uint32_t*    /* height_return */,
    unsigned char**    /* data_return */,
    int32_t*        /* x_hot_return */,
    int32_t*        /* y_hot_return */
);

extern int32_t XRebindKeysym(
    Display*        /* display */,
    KeySym        /* keysym */,
    KeySym*        /* list */,
    int32_t            /* mod_count */,
    _Xconst unsigned char*    /* string */,
    int32_t            /* bytes_string */
);

extern int32_t XRecolorCursor(
    Display*        /* display */,
    XCursor        /* cursor */,
    XColor*        /* foreground_color */,
    XColor*        /* background_color */
);

extern int32_t XRefreshKeyboardMapping(
    XMappingEvent*    /* event_map */
);

extern int32_t XRemoveFromSaveSet(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XRemoveHost(
    Display*        /* display */,
    XHostAddress*    /* host */
);

extern int32_t XRemoveHosts(
    Display*        /* display */,
    XHostAddress*    /* hosts */,
    int32_t            /* num_hosts */
);

extern int32_t XReparentWindow(
    Display*        /* display */,
    XWindow        /* w */,
    XWindow        /* parent */,
    int32_t            /* x */,
    int32_t            /* y */
);

extern int32_t XResetScreenSaver(
    Display*        /* display */
);

extern int32_t XResizeWindow(
    Display*        /* display */,
    XWindow        /* w */,
    uint32_t    /* width */,
    uint32_t    /* height */
);

extern int32_t XRestackWindows(
    Display*        /* display */,
    XWindow*        /* windows */,
    int32_t            /* nwindows */
);

extern int32_t XRotateBuffers(
    Display*        /* display */,
    int32_t            /* rotate */
);

extern int32_t XRotateWindowProperties(
    Display*        /* display */,
    XWindow        /* w */,
    XAtom*        /* properties */,
    int32_t            /* num_prop */,
    int32_t            /* npositions */
);

extern int32_t XScreenCount(
    Display*        /* display */
);

extern int32_t XSelectInput(
    Display*        /* display */,
    XWindow        /* w */,
    int64_t        /* event_mask */
);

extern int32_t XSendEvent(
    Display*        /* display */,
    XWindow        /* w */,
    int32_t        /* propagate */,
    int64_t        /* event_mask */,
    XEvent*        /* event_send */
);

extern int32_t XSetAccessControl(
    Display*        /* display */,
    int32_t            /* mode */
);

extern int32_t XSetArcMode(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* arc_mode */
);

extern int32_t XSetBackground(
    Display*        /* display */,
    GC            /* gc */,
    uint64_t    /* background */
);

extern int32_t XSetClipMask(
    Display*        /* display */,
    GC            /* gc */,
    XPixmap        /* pixmap */
);

extern int32_t XSetClipOrigin(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* clip_x_origin */,
    int32_t            /* clip_y_origin */
);

extern int32_t XSetClipRectangles(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* clip_x_origin */,
    int32_t            /* clip_y_origin */,
    XRectangle*        /* rectangles */,
    int32_t            /* n */,
    int32_t            /* ordering */
);

extern int32_t XSetCloseDownMode(
    Display*        /* display */,
    int32_t            /* close_mode */
);

extern int32_t XSetCommand(
    Display*        /* display */,
    XWindow        /* w */,
    char**        /* argv */,
    int32_t            /* argc */
);

extern int32_t XSetDashes(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* dash_offset */,
    _Xconst char*    /* dash_list */,
    int32_t            /* n */
);

extern int32_t XSetFillRule(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* fill_rule */
);

extern int32_t XSetFillStyle(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* fill_style */
);

extern int32_t XSetFont(
    Display*        /* display */,
    GC            /* gc */,
    Font        /* font */
);

extern int32_t XSetFontPath(
    Display*        /* display */,
    char**        /* directories */,
    int32_t            /* ndirs */
);

extern int32_t XSetForeground(
    Display*        /* display */,
    GC            /* gc */,
    uint64_t    /* foreground */
);

extern int32_t XSetFunction(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* function */
);

extern int32_t XSetGraphicsExposures(
    Display*        /* display */,
    GC            /* gc */,
    int32_t        /* graphics_exposures */
);

extern int32_t XSetIconName(
    Display*        /* display */,
    XWindow        /* w */,
    _Xconst char*    /* icon_name */
);

extern int32_t XSetInputFocus(
    Display*        /* display */,
    XWindow        /* focus */,
    int32_t            /* revert_to */,
    XTime        /* time */
);

extern int32_t XSetLineAttributes(
    Display*        /* display */,
    GC            /* gc */,
    uint32_t    /* line_width */,
    int32_t            /* line_style */,
    int32_t            /* cap_style */,
    int32_t            /* join_style */
);

extern int32_t XSetModifierMapping(
    Display*        /* display */,
    XModifierKeymap*    /* modmap */
);

extern int32_t XSetPlaneMask(
    Display*        /* display */,
    GC            /* gc */,
    uint64_t    /* plane_mask */
);

extern int32_t XSetPointerMapping(
    Display*        /* display */,
    _Xconst unsigned char*    /* map */,
    int32_t            /* nmap */
);

extern int32_t XSetScreenSaver(
    Display*        /* display */,
    int32_t            /* timeout */,
    int32_t            /* interval */,
    int32_t            /* prefer_blanking */,
    int32_t            /* allow_exposures */
);

extern int32_t XSetSelectionOwner(
    Display*        /* display */,
    XAtom            /* selection */,
    XWindow        /* owner */,
    XTime        /* time */
);

extern int32_t XSetState(
    Display*        /* display */,
    GC            /* gc */,
    uint64_t     /* foreground */,
    uint64_t    /* background */,
    int32_t            /* function */,
    uint64_t    /* plane_mask */
);

extern int32_t XSetStipple(
    Display*        /* display */,
    GC            /* gc */,
    XPixmap        /* stipple */
);

extern int32_t XSetSubwindowMode(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* subwindow_mode */
);

extern int32_t XSetTSOrigin(
    Display*        /* display */,
    GC            /* gc */,
    int32_t            /* ts_x_origin */,
    int32_t            /* ts_y_origin */
);

extern int32_t XSetTile(
    Display*        /* display */,
    GC            /* gc */,
    XPixmap        /* tile */
);

extern int32_t XSetWindowBackground(
    Display*        /* display */,
    XWindow        /* w */,
    uint64_t    /* background_pixel */
);

extern int32_t XSetWindowBackgroundPixmap(
    Display*        /* display */,
    XWindow        /* w */,
    XPixmap        /* background_pixmap */
);

extern int32_t XSetWindowBorder(
    Display*        /* display */,
    XWindow        /* w */,
    uint64_t    /* border_pixel */
);

extern int32_t XSetWindowBorderPixmap(
    Display*        /* display */,
    XWindow        /* w */,
    XPixmap        /* border_pixmap */
);

extern int32_t XSetWindowBorderWidth(
    Display*        /* display */,
    XWindow        /* w */,
    uint32_t    /* width */
);

extern int32_t XSetWindowColormap(
    Display*        /* display */,
    XWindow        /* w */,
    XColormap        /* colormap */
);

extern int32_t XStoreBuffer(
    Display*        /* display */,
    _Xconst char*    /* bytes */,
    int32_t            /* nbytes */,
    int32_t            /* buffer */
);

extern int32_t XStoreBytes(
    Display*        /* display */,
    _Xconst char*    /* bytes */,
    int32_t            /* nbytes */
);

extern int32_t XStoreColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    XColor*        /* color */
);

extern int32_t XStoreColors(
    Display*        /* display */,
    XColormap        /* colormap */,
    XColor*        /* color */,
    int32_t            /* ncolors */
);

extern int32_t XStoreName(
    Display*        /* display */,
    XWindow        /* w */,
    _Xconst char*    /* window_name */
);

extern int32_t XStoreNamedColor(
    Display*        /* display */,
    XColormap        /* colormap */,
    _Xconst char*    /* color */,
    uint64_t    /* pixel */,
    int32_t            /* flags */
);

extern int32_t XSync(
    Display*        /* display */,
    int32_t        /* discard */
);

extern int32_t XTextExtents(
    XFontStruct*    /* font_struct */,
    _Xconst char*    /* string */,
    int32_t            /* nchars */,
    int32_t*        /* direction_return */,
    int32_t*        /* font_ascent_return */,
    int32_t*        /* font_descent_return */,
    XCharStruct*    /* overall_return */
);

extern int32_t XTextExtents16(
    XFontStruct*    /* font_struct */,
    _Xconst XChar2b*    /* string */,
    int32_t            /* nchars */,
    int32_t*        /* direction_return */,
    int32_t*        /* font_ascent_return */,
    int32_t*        /* font_descent_return */,
    XCharStruct*    /* overall_return */
);

extern int32_t XTextWidth(
    XFontStruct*    /* font_struct */,
    _Xconst char*    /* string */,
    int32_t            /* count */
);

extern int32_t XTextWidth16(
    XFontStruct*    /* font_struct */,
    _Xconst XChar2b*    /* string */,
    int32_t            /* count */
);

extern int32_t XTranslateCoordinates(
    Display*        /* display */,
    XWindow        /* src_w */,
    XWindow        /* dest_w */,
    int32_t            /* src_x */,
    int32_t            /* src_y */,
    int32_t*        /* dest_x_return */,
    int32_t*        /* dest_y_return */,
    XWindow*        /* child_return */
);

extern int32_t XUndefineCursor(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XUngrabButton(
    Display*        /* display */,
    uint32_t    /* button */,
    uint32_t    /* modifiers */,
    XWindow        /* grab_window */
);

extern int32_t XUngrabKey(
    Display*        /* display */,
    int32_t            /* keycode */,
    uint32_t    /* modifiers */,
    XWindow        /* grab_window */
);

extern int32_t XUngrabKeyboard(
    Display*        /* display */,
    XTime        /* time */
);

extern int32_t XUngrabPointer(
    Display*        /* display */,
    XTime        /* time */
);

extern int32_t XUngrabServer(
    Display*        /* display */
);

extern int32_t XUninstallColormap(
    Display*        /* display */,
    XColormap        /* colormap */
);

extern int32_t XUnloadFont(
    Display*        /* display */,
    Font        /* font */
);

extern int32_t XUnmapSubwindows(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XUnmapWindow(
    Display*        /* display */,
    XWindow        /* w */
);

extern int32_t XVendorRelease(
    Display*        /* display */
);

extern int32_t XWarpPointer(
    Display*        /* display */,
    XWindow        /* src_w */,
    XWindow        /* dest_w */,
    int32_t            /* src_x */,
    int32_t            /* src_y */,
    uint32_t    /* src_width */,
    uint32_t    /* src_height */,
    int32_t            /* dest_x */,
    int32_t            /* dest_y */
);

extern int32_t XWidthMMOfScreen(
    Screen*        /* screen */
);

extern int32_t XWidthOfScreen(
    Screen*        /* screen */
);

extern int32_t XWindowEvent(
    Display*        /* display */,
    XWindow        /* w */,
    int64_t        /* event_mask */,
    XEvent*        /* event_return */
);

extern int32_t XWriteBitmapFile(
    Display*        /* display */,
    _Xconst char*    /* filename */,
    XPixmap        /* bitmap */,
    uint32_t    /* width */,
    uint32_t    /* height */,
    int32_t            /* x_hot */,
    int32_t            /* y_hot */
);

extern int32_t XSupportsLocale (void);

extern char *XSetLocaleModifiers(
    const char*        /* modifier_list */
);

extern XOM XOpenOM(
    Display*            /* display */,
    struct _XrmHashBucketRec*    /* rdb */,
    _Xconst char*        /* res_name */,
    _Xconst char*        /* res_class */
);

extern int32_t XCloseOM(
    XOM            /* om */
);

extern char *XSetOMValues(
    XOM            /* om */,
    ...
) _X_SENTINEL(0);

extern char *XGetOMValues(
    XOM            /* om */,
    ...
) _X_SENTINEL(0);

extern Display *XDisplayOfOM(
    XOM            /* om */
);

extern char *XLocaleOfOM(
    XOM            /* om */
);

extern XOC XCreateOC(
    XOM            /* om */,
    ...
) _X_SENTINEL(0);

extern void XDestroyOC(
    XOC            /* oc */
);

extern XOM XOMOfOC(
    XOC            /* oc */
);

extern char *XSetOCValues(
    XOC            /* oc */,
    ...
) _X_SENTINEL(0);

extern char *XGetOCValues(
    XOC            /* oc */,
    ...
) _X_SENTINEL(0);

extern XFontSet XCreateFontSet(
    Display*        /* display */,
    _Xconst char*    /* base_font_name_list */,
    char***        /* missing_charset_list */,
    int32_t*        /* missing_charset_count */,
    char**        /* def_string */
);

extern void XFreeFontSet(
    Display*        /* display */,
    XFontSet        /* font_set */
);

extern int32_t XFontsOfFontSet(
    XFontSet        /* font_set */,
    XFontStruct***    /* font_struct_list */,
    char***        /* font_name_list */
);

extern char *XBaseFontNameListOfFontSet(
    XFontSet        /* font_set */
);

extern char *XLocaleOfFontSet(
    XFontSet        /* font_set */
);

extern int32_t XContextDependentDrawing(
    XFontSet        /* font_set */
);

extern int32_t XDirectionalDependentDrawing(
    XFontSet        /* font_set */
);

extern int32_t XContextualDrawing(
    XFontSet        /* font_set */
);

extern XFontSetExtents *XExtentsOfFontSet(
    XFontSet        /* font_set */
);

extern int32_t XmbTextEscapement(
    XFontSet        /* font_set */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */
);

extern int32_t XwcTextEscapement(
    XFontSet        /* font_set */,
    _Xconst wchar_t*    /* text */,
    int32_t            /* num_wchars */
);

extern int32_t Xutf8TextEscapement(
    XFontSet        /* font_set */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */
);

extern int32_t XmbTextExtents(
    XFontSet        /* font_set */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */,
    XRectangle*        /* overall_ink_return */,
    XRectangle*        /* overall_logical_return */
);

extern int32_t XwcTextExtents(
    XFontSet        /* font_set */,
    _Xconst wchar_t*    /* text */,
    int32_t            /* num_wchars */,
    XRectangle*        /* overall_ink_return */,
    XRectangle*        /* overall_logical_return */
);

extern int32_t Xutf8TextExtents(
    XFontSet        /* font_set */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */,
    XRectangle*        /* overall_ink_return */,
    XRectangle*        /* overall_logical_return */
);

extern int32_t XmbTextPerCharExtents(
    XFontSet        /* font_set */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */,
    XRectangle*        /* ink_extents_buffer */,
    XRectangle*        /* logical_extents_buffer */,
    int32_t            /* buffer_size */,
    int32_t*        /* num_chars */,
    XRectangle*        /* overall_ink_return */,
    XRectangle*        /* overall_logical_return */
);

extern int32_t XwcTextPerCharExtents(
    XFontSet        /* font_set */,
    _Xconst wchar_t*    /* text */,
    int32_t            /* num_wchars */,
    XRectangle*        /* ink_extents_buffer */,
    XRectangle*        /* logical_extents_buffer */,
    int32_t            /* buffer_size */,
    int32_t*        /* num_chars */,
    XRectangle*        /* overall_ink_return */,
    XRectangle*        /* overall_logical_return */
);

extern int32_t Xutf8TextPerCharExtents(
    XFontSet        /* font_set */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */,
    XRectangle*        /* ink_extents_buffer */,
    XRectangle*        /* logical_extents_buffer */,
    int32_t            /* buffer_size */,
    int32_t*        /* num_chars */,
    XRectangle*        /* overall_ink_return */,
    XRectangle*        /* overall_logical_return */
);

extern void XmbDrawText(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    XmbTextItem*    /* text_items */,
    int32_t            /* nitems */
);

extern void XwcDrawText(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    XwcTextItem*    /* text_items */,
    int32_t            /* nitems */
);

extern void Xutf8DrawText(
    Display*        /* display */,
    Drawable        /* d */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    XmbTextItem*    /* text_items */,
    int32_t            /* nitems */
);

extern void XmbDrawString(
    Display*        /* display */,
    Drawable        /* d */,
    XFontSet        /* font_set */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */
);

extern void XwcDrawString(
    Display*        /* display */,
    Drawable        /* d */,
    XFontSet        /* font_set */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst wchar_t*    /* text */,
    int32_t            /* num_wchars */
);

extern void Xutf8DrawString(
    Display*        /* display */,
    Drawable        /* d */,
    XFontSet        /* font_set */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */
);

extern void XmbDrawImageString(
    Display*        /* display */,
    Drawable        /* d */,
    XFontSet        /* font_set */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */
);

extern void XwcDrawImageString(
    Display*        /* display */,
    Drawable        /* d */,
    XFontSet        /* font_set */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst wchar_t*    /* text */,
    int32_t            /* num_wchars */
);

extern void Xutf8DrawImageString(
    Display*        /* display */,
    Drawable        /* d */,
    XFontSet        /* font_set */,
    GC            /* gc */,
    int32_t            /* x */,
    int32_t            /* y */,
    _Xconst char*    /* text */,
    int32_t            /* bytes_text */
);

extern XIM XOpenIM(
    Display*            /* dpy */,
    struct _XrmHashBucketRec*    /* rdb */,
    char*            /* res_name */,
    char*            /* res_class */
);

extern int32_t XCloseIM(
    XIM /* im */
);

extern char *XGetIMValues(
    XIM /* im */, ...
) _X_SENTINEL(0);

extern char *XSetIMValues(
    XIM /* im */, ...
) _X_SENTINEL(0);

extern Display *XDisplayOfIM(
    XIM /* im */
);

extern char *XLocaleOfIM(
    XIM /* im*/
);

extern XIC XCreateIC(
    XIM /* im */, ...
) _X_SENTINEL(0);

extern void XDestroyIC(
    XIC /* ic */
);

extern void XSetICFocus(
    XIC /* ic */
);

extern void XUnsetICFocus(
    XIC /* ic */
);

extern wchar_t *XwcResetIC(
    XIC /* ic */
);

extern char *XmbResetIC(
    XIC /* ic */
);

extern char *Xutf8ResetIC(
    XIC /* ic */
);

extern char *XSetICValues(
    XIC /* ic */, ...
) _X_SENTINEL(0);

extern char *XGetICValues(
    XIC /* ic */, ...
) _X_SENTINEL(0);

extern XIM XIMOfIC(
    XIC /* ic */
);

extern int32_t XFilterEvent(
    XEvent*    /* event */,
    XWindow    /* window */
);

extern int32_t XmbLookupString(
    XIC            /* ic */,
    XKeyEvent*    /* event */,
    char*        /* buffer_return */,
    int32_t            /* bytes_buffer */,
    KeySym*        /* keysym_return */,
    int32_t*        /* status_return */
);

extern int32_t XwcLookupString(
    XIC            /* ic */,
    XKeyEvent*    /* event */,
    wchar_t*        /* buffer_return */,
    int32_t            /* wchars_buffer */,
    KeySym*        /* keysym_return */,
    int32_t*        /* status_return */
);

extern int32_t Xutf8LookupString(
    XIC            /* ic */,
    XKeyEvent*    /* event */,
    char*        /* buffer_return */,
    int32_t            /* bytes_buffer */,
    KeySym*        /* keysym_return */,
    int32_t*        /* status_return */
);

extern XVaNestedList XVaCreateNestedList(
    int32_t /*unused*/, ...
) _X_SENTINEL(0);

/* internal connections for IMs */

extern int32_t XRegisterIMInstantiateCallback(
    Display*            /* dpy */,
    struct _XrmHashBucketRec*    /* rdb */,
    char*            /* res_name */,
    char*            /* res_class */,
    XIDProc            /* callback */,
    void*            /* client_data */
);

extern int32_t XUnregisterIMInstantiateCallback(
    Display*            /* dpy */,
    struct _XrmHashBucketRec*    /* rdb */,
    char*            /* res_name */,
    char*            /* res_class */,
    XIDProc            /* callback */,
    void*            /* client_data */
);

typedef void (*XConnectionWatchProc)(
    Display*            /* dpy */,
    void*            /* client_data */,
    int32_t                /* fd */,
    int32_t            /* opening */,     /* open or close flag */
    void**            /* watch_data */ /* open sets, close uses */
);


extern int32_t XInternalConnectionNumbers(
    Display*            /* dpy */,
    int32_t**            /* fd_return */,
    int32_t*            /* count_return */
);

extern void XProcessInternalConnection(
    Display*            /* dpy */,
    int32_t                /* fd */
);

extern int32_t XAddConnectionWatch(
    Display*            /* dpy */,
    XConnectionWatchProc    /* callback */,
    void*            /* client_data */
);

extern void XRemoveConnectionWatch(
    Display*            /* dpy */,
    XConnectionWatchProc    /* callback */,
    void*            /* client_data */
);

extern void XSetAuthorization(
    char *            /* name */,
    int32_t                /* namelen */,
    char *            /* data */,
    int32_t                /* datalen */
);

extern int32_t _Xmbtowc(
    wchar_t *            /* wstr */,
    char *            /* str */,
    int32_t                /* len */
);

extern int32_t _Xwctomb(
    char *            /* str */,
    wchar_t            /* wc */
);

extern int32_t XGetEventData(
    Display*            /* dpy */,
    XGenericEventCookie*    /* cookie*/
);

extern void XFreeEventData(
    Display*            /* dpy */,
    XGenericEventCookie*    /* cookie*/
);

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif// _X11_Xlib_h_