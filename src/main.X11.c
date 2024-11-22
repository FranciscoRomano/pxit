#include "platform/GLX/library.h"
#include "platform/X11/library.h"
#include "platform/X11/window.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// https://xcb.freedesktop.org/opengl/
// https://alexvia.com/post/002_initializing_opengl_on_x11/
// https://github.com/gamedevtech/X11OpenGLWindow

int main(int argc, char** argv)
{
    if (!LoadLibraryX11())
    {
        printf("ERROR: failed to load X11 library\n");
        exit(EXIT_FAILURE);
    }

    if (!LoadLibraryGLX())
    {
        printf("ERROR: failed to load GLX library\n");
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

    while (ReadWindowEventsX11(&ctx))
    {
        sleep(0);
    }

    DestroyWindowX11(&ctx, &win);
    DestroyWindowContextX11(&ctx);
    FreeLibraryGLX();
    FreeLibraryX11();
    return 0;
}