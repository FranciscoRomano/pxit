#include "platform/Win32/context.h"
#include <stdio.h>

extern PxitPlatformWin32 GWin32;

int main(int argc, char** argv)
{
    InitPxitPlatformWin32();

    printf(" - location: %s", GWin32.location);

    FreePxitPlatformWin32();
    return 0;
}