#include "platform/Win32/window.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    WindowContextWin32 ctx;
    if (!CreateWindowContextWin32(&ctx))
    {
        printf("ERROR: failed to create Win32 window context\n");
        exit(EXIT_FAILURE);
    }

    WindowWin32 win;
    if (!CreateWindowWin32(&ctx, 800, 600, &win))
    {
        printf("ERROR: failed to create Win32 window\n");
        exit(EXIT_FAILURE);
    }

    while (ReadWindowEventsWin32(&ctx))
    {
        Sleep(0);
    }

    DestroyWindowWin32(&ctx, &win);
    DestroyWindowContextWin32(&ctx);
    return 0;
}