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

    HDC hDC = GetDC(win.hWnd);
    if (hDC == NULL)
    {
        printf("ERROR: failed to get device context from window\n");
        exit(EXIT_FAILURE);
    }

    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int format = ChoosePixelFormat(hDC, &pfd);
    if (format == 0 || SetPixelFormat(hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
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