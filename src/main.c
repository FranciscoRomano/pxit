#include "platform/X11/context.h"
#include <stdlib.h>
#include <stdio.h>

extern PxitPlatformX11 GX11;

int main(int argc, char** argv)
{
    InitPxitPlatformX11();

    if (GX11.lib) printf("X11 was initialized successfully\n");

    FreePxitPlatformX11();
    return 0;
}