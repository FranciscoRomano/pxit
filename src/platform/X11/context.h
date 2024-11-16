// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __pxit_platform_X11_context_h__
#define __pxit_platform_X11_context_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef unsigned int  uint;
typedef unsigned long ulong;

/// @brief Represents a X11 platform.
typedef struct PxitPlatformX11 {
    void*    lib;
    Display* dpy;
    int      (*XCloseDisplay)(Display*);
    Colormap (*XCreateColormap)(Display*,Window,Visual*,int);
    Window   (*XCreateWindow)(Display*,Window,int,int,uint,uint,uint,int,uint,Visual*,ulong,XSetWindowAttributes*);
    Window   (*XDefaultRootWindow)(Display*);
    int      (*XDefaultScreen)(Display*);
    Screen   (*XDefaultScreenOfDisplay)(Display*);
    Atom     (*XInternAtom)(Display*,const char*,Bool);
    int      (*XMapWindow)(Display*,Window);
    int      (*XNextEvent)(Display*,XEvent*);
    Display* (*XOpenDisplay)(const char*);
    int      (*XScreenCount)(Display*);
    Screen*  (*XScreenOfDisplay)(Display*,int);
    Status   (*XSetWMProtocols)(Display*,Window,Atom*,int);
    KeyCode  (*XKeysymToKeycode)(Display*,KeySym);
} PxitPlatformX11;

/// @brief Releases the global X11 platform.
void FreePxitPlatformX11();

/// @brief Initializes the global X11 platform.
void InitPxitPlatformX11();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__pxit_platform_X11_context_h__
// -------------------------------------------------------------------------------------------------------------------------- //