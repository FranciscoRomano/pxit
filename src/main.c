#include "platform/X11/library.h"
#include "platform/X11/window.h"
#include <stdlib.h>
#include <stdio.h>

extern LibraryX11 X11;

int main(int argc, char** argv)
{
    if (!LoadLibraryX11())
    {
        printf("ERROR: failed to load X11 library\n");
        exit(EXIT_FAILURE);
    }

    WindowContextX11 ws;
    if (!CreateWindowContextX11(&ws))
    {
        printf("ERROR: failed to load X11 window context\n");
        exit(EXIT_FAILURE);
    }

    XSetWindowAttributes attr = {};
    attr.background_pixel = 0xffafe9af;
    attr.event_mask = StructureNotifyMask | KeyPressMask | KeyReleaseMask | ExposureMask;

    Window win = X11.XCreateWindow(
        ws.hDisplay,
        ws.hRootWindow,
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
    X11.XMapWindow(ws.hDisplay, win);

    X11.XSetWMProtocols(ws.hDisplay, win, &ws.wmDeleteWindow, 1);

    int is_window_open = 1;
    while (is_window_open)
    {
        XEvent evt = {};
        X11.XNextEvent(ws.hDisplay, &evt);

        switch(evt.type)
        {
            case KeyPress:
            case KeyRelease:
            {
                XKeyPressedEvent *Event = (XKeyPressedEvent*)&evt;
                if(Event->keycode == X11.XKeysymToKeycode(ws.hDisplay, XK_Escape))
                {
                    is_window_open = 0;
                }
                break;
            }
            case ClientMessage:
            {
                XClientMessageEvent* cm_evt = (XClientMessageEvent*)(&evt);
                if (evt.xclient.data.l[0] == ws.wmDeleteWindow)
                    is_window_open = 0;
            }
        }
    }

    DestroyWindowContextX11(&ws);
    FreeLibraryX11();
    return 0;
}