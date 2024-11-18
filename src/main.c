#if defined(IS_PLATFORM_LINUX)
#include "main.X11.c"
#elif defined(IS_PLATFORM_WINDOWS)
#include "main.Win32.c"
#else
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    printf("Platform not supported!\n");
    exit(EXIT_FAILURE);
    return 0;
}
#endif