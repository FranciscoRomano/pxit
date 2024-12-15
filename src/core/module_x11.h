// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_x11_h__
#define __core_module_x11_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdint.h>
#include <stdbool.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

/// @brief Represents the X11 module and supported functions.
extern struct _Module_X11 {
    void*    handle; // A X11 library handle.
    Display* dpy;    // A X11 display connection.
    XContext ctx;    // A X11 global context handle.
    Window   root;   // A X11 display root window handle.
    Atom     wmDeleteWindow;
    int      (*XChangeProperty)(Display*,Window,Atom,Atom,int,int,const char*,int);
    int      (*XChangeWindowAttributes)(Display*,Window,uint64_t,XSetWindowAttributes*);
    int      (*XCloseDisplay)(Display*);
    Colormap (*XCreateColormap)(Display*,Window,Visual*,int);
    Window   (*XCreateWindow)(Display*,Window,int,int,uint32_t,uint32_t,uint32_t,int,uint32_t,Visual*,uint64_t,XSetWindowAttributes*);
    Window   (*XDefaultRootWindow)(Display*);
    int      (*XDefaultScreen)(Display*);
    Screen   (*XDefaultScreenOfDisplay)(Display*);
    int      (*XDeleteContext)(Display*, XID, XContext);
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
} _X11;

/// @brief Returns true if the X11 module was freed successfully.
bool _FreeModule_X11();

/// @brief Returns true if the X11 module was loaded successfully.
bool _LoadModule_X11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_x11_h__
// -------------------------------------------------------------------------------------------------------------------------- //