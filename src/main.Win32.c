#include "core/Win32/window.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/GL.h>

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

    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    int format = ChoosePixelFormat(win.hDC, &pfd);
    if (format == 0 || SetPixelFormat(win.hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
        exit(EXIT_FAILURE);
    }

    HGLRC wgl_ctx = wglCreateContext(win.hDC);
    wglMakeCurrent(win.hDC, wgl_ctx);
    printf("- context: %lu", (UINT64)wgl_ctx);

    while (ReadWindowEventsWin32(&ctx))
    {
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        SwapBuffers(win.hDC);
    }

    wglMakeCurrent(win.hDC, NULL);
    wglDeleteContext(wgl_ctx);

    DestroyWindowWin32(&ctx, &win);
    DestroyWindowContextWin32(&ctx);
    return 0;
}