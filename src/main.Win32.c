#include "platform/Win32/context.h"
#include <stdio.h>

extern PxitPlatformWin32 GWin32;

HWND CreatePxitWindowWin32(LPCSTR name, int x, int y, int width, int height)
{
    InitPxitPlatformWin32();

    DWORD dwStyle = WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    HWND hWnd = CreateWindowExA(
        0,
        GWin32.lpClassName,
        name,
        dwStyle,
        x,
        y,
        width,
        height,
        NULL,
        NULL,
        GWin32.hInstance,
        (LPVOID)NULL
    );
    return hWnd;
}

void DestroyPxitWindowWin32(HWND hWnd)
{
    DestroyWindow(hWnd);

    FreePxitPlatformWin32();
}

int main(int argc, char** argv)
{
    HWND hWnd = CreatePxitWindowWin32("Hello World", 10, 10, 800, 600);

    printf(" - location: %s", GWin32.location);

    DestroyPxitWindowWin32(hWnd);
    return 0;
}