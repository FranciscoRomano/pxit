#include "platform/X11/context.h"
#include <stdlib.h>
#include <stdio.h>

extern PxitPlatformX11 GX11;

int main(int argc, char** argv)
{
    InitPxitPlatformX11();

    XSetWindowAttributes attr = {};
    attr.background_pixel = 0xffafe9af;

    Window win = GX11.XCreateWindow(
        GX11.dpy,
        GX11.XDefaultRootWindow(GX11.dpy),
        0,
        0,
        800,
        600,
        0,              // border width
        CopyFromParent, // window depth
        CopyFromParent, // window class
        CopyFromParent, // window visual
        CWBackPixel,    // attribute mask
        &attr
    );
    GX11.XMapWindow(GX11.dpy, win);

    for (;;) {
        XEvent evt = {};
        GX11.XNextEvent(GX11.dpy, &evt);
    }

    FreePxitPlatformX11();
    return 0;
}