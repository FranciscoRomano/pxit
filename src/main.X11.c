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

    WindowContextX11 ctx;
    if (!CreateWindowContextX11(&ctx))
    {
        printf("ERROR: failed to create X11 window context\n");
        exit(EXIT_FAILURE);
    }

    WindowX11 win;
    if (!CreateWindowX11(&ctx, 800, 600, &win))
    {
        printf("ERROR: failed to create X11 window\n");
        exit(EXIT_FAILURE);
    }

    int is_window_open = 1;
    while (is_window_open)
    {
        XEvent evt = {};
        X11.XNextEvent(ctx.hDisplay, &evt);

        switch(evt.type)
        {
            case KeyPress:
            case KeyRelease:
                if (evt.xkey.keycode == X11.XKeysymToKeycode(ctx.hDisplay, XK_Escape))
                    is_window_open = 0;
                break;
            case ClientMessage:
                if (evt.xclient.window == win.hID && evt.xclient.data.l[0] == ctx.wmDeleteWindow)
                    is_window_open = 0;
                break;
        }
    }

    DestroyWindow(&ctx, &win);
    DestroyWindowContextX11(&ctx);
    FreeLibraryX11();
    return 0;
}