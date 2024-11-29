#define WIN32_LEAN_AND_MEAN 1
#include "main.GLES3.c"
#include "core/WGL/module.h"
#include "core/Win32/module.h"
#include "core/Win32/window.h"

int main(int argc, char** argv)
{
    if (!LoadModuleWGL())
    {
        printf("ERROR: failed to load WGL module\n");
        exit(EXIT_FAILURE);
    }

    WindowWin32 win;
    if (!CreateWindowWin32(800, 600, &win))
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

    while (ReadWindowEventsWin32())
    {
        Draw_GLES3();

        SwapBuffers(win.hDC);
    }

    WGL.wglMakeCurrent(win.hDC, NULL);
    WGL.wglDeleteContext(wgl_ctx);

    DestroyWindowWin32(&win);
    FreeModuleWGL();
    FreeModuleWin32();
    return 0;
}