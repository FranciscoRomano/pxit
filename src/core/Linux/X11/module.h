// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_X11_module_h__
#define __core_X11_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdbool.h>
#include <X11/X.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef unsigned int  uint;
typedef unsigned long ulong;

/// @brief Represents the X11 module and supported functions.
extern struct ModuleX11 {
    void*    handle;
    Display* hDisplay;
    XContext hContext;
    Window   hRootWindow;
    Atom     wmDeleteWindow;
    int      (*XChangeProperty)(Display*,Window,Atom,Atom,int,int,const char*,int);
    int      (*XChangeWindowAttributes)(Display*,Window,ulong,XSetWindowAttributes*);
    int      (*XCloseDisplay)(Display*);
    Colormap (*XCreateColormap)(Display*,Window,Visual*,int);
    Window   (*XCreateWindow)(Display*,Window,int,int,uint,uint,uint,int,uint,Visual*,ulong,XSetWindowAttributes*);
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
} X11;

                      
/// @brief Returns true if the X11 module was freed successfully.
bool FreeModuleX11();

/// @brief Returns true if the X11 module was loaded successfully.
bool LoadModuleX11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_X11_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //