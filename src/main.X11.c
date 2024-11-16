#include "platform/X11/context.h"
#include <stdlib.h>
#include <stdio.h>

extern PxitPlatformX11 GX11;

int main(int argc, char** argv)
{
    InitPxitPlatformX11();

    Atom wmDeleteMessage = GX11.XInternAtom(GX11.dpy, "WM_DELETE_WINDOW", False);

    XSetWindowAttributes attr = {};
    attr.background_pixel = 0xffafe9af;
    attr.event_mask = StructureNotifyMask | KeyPressMask | KeyReleaseMask | ExposureMask;

    Window win = GX11.XCreateWindow(
        GX11.dpy,
        GX11.XDefaultRootWindow(GX11.dpy),
        0,
        0,
        800,
        600,
        0,                         // border width
        CopyFromParent,            // window depth
        CopyFromParent,            // window class
        CopyFromParent,            // window visual
        CWBackPixel | CWEventMask, // attribute mask
        &attr
    );
    GX11.XMapWindow(GX11.dpy, win);

    GX11.XSetWMProtocols(GX11.dpy, win, &wmDeleteMessage, 1);

    int is_window_open = 1;
    while (is_window_open)
    {
        XEvent evt = {};
        GX11.XNextEvent(GX11.dpy, &evt);

        switch(evt.type)
        {
            case KeyPress:
            case KeyRelease:
            {
                XKeyPressedEvent *Event = (XKeyPressedEvent*)&evt;
                if(Event->keycode == GX11.XKeysymToKeycode(GX11.dpy, XK_Escape))
                {
                    is_window_open = 0;
                }
                break;
            }
            case ClientMessage:
            {
                XClientMessageEvent* cm_evt = (XClientMessageEvent*)(&evt);
                if (evt.xclient.data.l[0] == wmDeleteMessage)
                    is_window_open = 0;
            }
        }
    }

    FreePxitPlatformX11();
    return 0;
}