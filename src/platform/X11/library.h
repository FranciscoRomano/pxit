// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// ---------------------------------------------------------------------------------------------- //
#ifndef __pxit_platform_x11_library_h__
#define __pxit_platform_x11_library_h__
#ifdef __cplusplus
extern "C" {
#endif

#include <X11/X.h>
#include <X11/Xlib.h>

typedef struct PxLibrary_X11 {
    Display* dpy;
    Colormap (*XCreateColormap)(Display*, Window, Visual*, int);
    Display* (*XOpenDisplay)(const char*);
    int      (*XDefaultScreen)(Display*);
    int      (*XScreenCount)(Display*);
    Screen   (*XDefaultScreenOfDisplay)(Display*);
    Screen*  (*XScreenOfDisplay)(Display*, int);
} PxLibrary_X11;

extern PxLibrary_X11 X11;

int pxFreeLibrary_X11();
int pxLoadLibrary_X11();

#ifdef __cplusplus
}
#endif
#endif//__pxit_platform_x11_library_h__