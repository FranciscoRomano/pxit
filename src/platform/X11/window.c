// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include "library.h"
#include <stdlib.h>
#include <stdio.h>
// -------------------------------------------------------------------------------------------------------------------------- //

extern LibraryX11 X11;

bool CreateWindowContextX11(WindowContextX11* ctx)
{
    // open a connection to the X server
    ctx->hDisplay = X11.XOpenDisplay(NULL);
    if (!ctx->hDisplay)
    {
        printf("ERROR: failed to open connection to X server\n");
        exit(EXIT_FAILURE);
    }

    // get the display's default root window
    ctx->hRootWindow = X11.XDefaultRootWindow(ctx->hDisplay);

    // get the 'WM_DELETE_WINDOW' event handle
    ctx->wmDeleteWindow = X11.XInternAtom(ctx->hDisplay, "WM_DELETE_WINDOW", False);
    return true;
}

bool DestroyWindowContextX11(WindowContextX11* ctx)
{
    // close the connection to the X server
    X11.XCloseDisplay(ctx->hDisplay);
    ctx->hDisplay = NULL;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //