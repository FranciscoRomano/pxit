#include "platform/GLX/library.h"
#include "platform/X11/library.h"
#include "platform/X11/window.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    LibraryX11 x11;
    if (!LoadLibraryX11(&x11))
    {
        printf("ERROR: failed to load X11 library\n");
        exit(EXIT_FAILURE);
    }

    LibraryGLX glx;
    if (!LoadLibraryGLX(&glx))
    {
        printf("ERROR: failed to load X11 library\n");
        exit(EXIT_FAILURE);
    }

    WindowContextX11 ctx;
    if (!CreateWindowContextX11(&x11, &ctx))
    {
        printf("ERROR: failed to create X11 window context\n");
        exit(EXIT_FAILURE);
    }

    WindowX11 win;
    if (!CreateWindowX11(&x11, &ctx, 800, 600, &win))
    {
        printf("ERROR: failed to create X11 window\n");
        exit(EXIT_FAILURE);
    }

    while (ReadWindowEventsX11(&x11, &ctx))
    {
        sleep(0);
    }

    DestroyWindowX11(&x11, &ctx, &win);
    DestroyWindowContextX11(&x11, &ctx);
    FreeLibraryGLX(&glx);
    FreeLibraryX11(&x11);
    return 0;
}