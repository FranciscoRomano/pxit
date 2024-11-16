#include "platform/X11/library.h"
#include "platform/X11/window.h"
#include <stdlib.h>
#include <stdio.h>

extern LibraryX11 X11;

int is_window_open = 1;

bool ReadWindowEventsX11(WindowContextX11* context)
{
    XEvent event;
    WindowX11* window = NULL;

    X11.XPending(context->hDisplay);

    while (QLength(context->hDisplay))
    {
        X11.XNextEvent(context->hDisplay, &event);

        if (X11.XFindContext(context->hDisplay, event.xany.window, context->hContext, (XPointer*)&window)) continue;

        switch (event.type)
        {
            case KeyRelease:
                if (event.xkey.keycode == X11.XKeysymToKeycode(context->hDisplay, XK_Escape))
                    is_window_open = 0;
                break;
            case ClientMessage:
                if (event.xclient.data.l[0] == context->wmDeleteWindow)
                    is_window_open = 0;
                break;
        }
    }

    X11.XFlush(context->hDisplay);
}

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

    while (is_window_open)
    {
        ReadWindowEventsX11(&ctx);
    }

    DestroyWindow(&ctx, &win);
    DestroyWindowContextX11(&ctx);
    FreeLibraryX11();
    return 0;
}