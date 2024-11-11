#include "platform/Win32/context.h"

int main(int argc, char** argv)
{
    // initialize a platform context
    PlatformContextWin32 ctx;
    InitPlatformContextWin32(&ctx);

    // free the existing platform context
    FreePlatformContextWin32(&ctx);
    return 0;
}