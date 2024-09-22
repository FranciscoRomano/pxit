// ---------------------------------------------------------------------------------------------- //
// The MIT License (MIT)
// 
// Copyright (c) 2024 Francisco Romano
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ---------------------------------------------------------------------------------------------- //
#ifndef __pxit_platform_x11_library_h__
#define __pxit_platform_x11_library_h__
#ifdef __cplusplus
extern "C" {
#endif

#include <X11/X.h>
#include <X11/Xlib.h>

typedef struct PxLibrary_X11 {
    Colormap (*XCreateColormap)(Display*, Window, Visual*, int);
    Display* (*XOpenDisplay)(const char*);
    int      (*XScreenCount)(Display*);
    Screen*  (*XScreenOfDisplay)(Display*, int);
} PxLibrary_X11;

extern PxLibrary_X11 X11;

int pxFreeLibrary_X11();
int pxLoadLibrary_X11();

#ifdef __cplusplus
}
#endif
#endif//__pxit_platform_x11_library_h__