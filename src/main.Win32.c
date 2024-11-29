#include "main.GLES3.c"
#include "core/WGL/library.h"
#include "core/Win32/window.h"

int main(int argc, char** argv)
{
    WindowContextWin32 ctx;
    if (!CreateWindowContextWin32(&ctx))
    {
        printf("ERROR: failed to create Win32 window context\n");
        exit(EXIT_FAILURE);
    }

    if (!LoadLibraryWGL(ctx.hInstance, ctx.lpClassName))
    {
        printf("ERROR: failed to load WGL library\n");
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

    HGLRC wgl_ctx = WGL.wglCreateContext(win.hDC);
    WGL.wglMakeCurrent(win.hDC, wgl_ctx);

    Init_GLES3();

    while (ReadWindowEventsWin32(&ctx))
    {
        Draw_GLES3();

        SwapBuffers(win.hDC);
    }

    WGL.wglMakeCurrent(win.hDC, NULL);
    WGL.wglDeleteContext(wgl_ctx);

    DestroyWindowWin32(&ctx, &win);
    DestroyWindowContextWin32(&ctx);
    return 0;
}