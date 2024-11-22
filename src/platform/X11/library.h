// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __platform_X11_library_h__
#define __platform_X11_library_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdbool.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

/// @brief Represents the X11 library and supported functions.
extern struct LibraryX11 {
    void*    handle;
    Atom     (*XInternAtom)(Display*,const char*,Bool);
    Colormap (*XCreateColormap)(Display*,Window,Visual*,int);
    Display* (*XOpenDisplay)(const char*);
    int      (*XChangeProperty)(Display*,Window,Atom,Atom,int,int,const uchar*,int);
    int      (*XCloseDisplay)(Display*);
    int      (*XDefaultScreen)(Display*);
    int      (*XDeleteContext)(Display*, XID, XContext);
    int      (*XDeleteProperty)(Display*,Window,Atom);
    int      (*XDestroyWindow)(Display*,Window);
    int      (*XFindContext)(Display*,XID,XContext,XPointer*);
    int      (*XFlush)(Display*);
    int      (*XMapWindow)(Display*,Window);
    int      (*XNextEvent)(Display*,XEvent*);
    int      (*XPending)(Display*);
    int      (*XrmUniqueQuark)();
    int      (*XSaveContext)(Display*,XID,XContext,const char*);
    int      (*XScreenCount)(Display*);
    int      (*XUnmapWindow)(Display*,Window);
    KeyCode  (*XKeysymToKeycode)(Display*,KeySym);
    Screen   (*XDefaultScreenOfDisplay)(Display*);
    Screen*  (*XScreenOfDisplay)(Display*,int);
    Status   (*XSetWMProtocols)(Display*,Window,Atom*,int);
    Window   (*XCreateWindow)(Display*,Window,int,int,uint,uint,uint,int,uint,Visual*,ulong,XSetWindowAttributes*);
    Window   (*XDefaultRootWindow)(Display*);
} X11;

/// @brief Returns true if the X11 library was freed successfully.
bool FreeLibraryX11();

/// @brief Returns true if the X11 library was loaded successfully.
bool LoadLibraryX11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef DEFINE_SYMBOLS_GLX
#define XInternAtom             X11.XInternAtom
#define XCreateColormap         X11.XCreateColormap
#define XOpenDisplay            X11.XOpenDisplay
#define XChangeProperty         X11.XChangeProperty
#define XCloseDisplay           X11.XCloseDisplay
#define XDefaultScreen          X11.XDefaultScreen
#define XDeleteContext          X11.XDeleteContext
#define XDeleteProperty         X11.XDeleteProperty
#define XDestroyWindow          X11.XDestroyWindow
#define XFindContext            X11.XFindContext
#define XFlush                  X11.XFlush
#define XMapWindow              X11.XMapWindow
#define XNextEvent              X11.XNextEvent
#define XPending                X11.XPending
#define XrmUniqueQuark          X11.XrmUniqueQuark
#define XSaveContext            X11.XSaveContext
#define XScreenCount            X11.XScreenCount
#define XUnmapWindow            X11.XUnmapWindow
#define XKeysymToKeycode        X11.XKeysymToKeycode
#define XDefaultScreenOfDisplay X11.XDefaultScreenOfDisplay
#define XScreenOfDisplay        X11.XScreenOfDisplay
#define XSetWMProtocols         X11.XSetWMProtocols
#define XCreateWindow           X11.XCreateWindow
#define XDefaultRootWindow      X11.XDefaultRootWindow
#endif//DEFINE_SYMBOLS_GLX
// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__platform_X11_library_h__
// -------------------------------------------------------------------------------------------------------------------------- //