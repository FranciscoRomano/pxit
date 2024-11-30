#define WIN32_LEAN_AND_MEAN 1
#include "main.GLES.c"
#include "core/WGL/module.h"
#include "core/Win32/window.h"

bool init = false;
HGLRC wgl_ctx;

void on_window_close(Window window)
{
    WindowWin32* window_win32 = (WindowWin32*)window;
    WGL.wglMakeCurrent(window_win32->hDC, NULL);
    WGL.wglDeleteContext(wgl_ctx);
    DestroyWindowWin32(window_win32);
}

void on_window_paint(Window window)
{
    WindowWin32* window_win32 = (WindowWin32*)window;
    if (!init)
    {
        PIXELFORMATDESCRIPTOR pfd;
        ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
        pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType   = PFD_TYPE_RGBA;
        pfd.cColorBits   = 32;
        pfd.cDepthBits   = 24;
        pfd.cStencilBits = 8;
        int format = ChoosePixelFormat(window_win32->hDC, &pfd);
        if (format == 0 || SetPixelFormat(window_win32->hDC, format, &pfd) == FALSE)
        {
            printf("ERROR: failed to set pixel format\n");
            exit(EXIT_FAILURE);
        }

        HGLRC wgl_ctx = WGL.wglCreateContext(window_win32->hDC);
        WGL.wglMakeCurrent(window_win32->hDC, wgl_ctx);
        Init_GLES3();
        init = true;
    }
    Draw_GLES3();
}

int main(int argc, char** argv)
{
    if (!LoadModuleWGL())
    {
        printf("ERROR: failed to load WGL module\n");
        exit(EXIT_FAILURE);
    }

    WindowWin32 window;
    {
        WindowCallbacks callbacks;
        memset(&callbacks, 0, sizeof(WindowCallbacks));
        callbacks.OnWindowClose = on_window_close;
        callbacks.OnWindowPaint = on_window_paint;

        WindowCreateInfo create_info;
        create_info.Left       = 40;
        create_info.Top        = 40;
        create_info.Width      = 800;
        create_info.Height     = 600;
        create_info.pTitle     = "";
        create_info.pCallbacks = &callbacks;
        if (!CreateWindowWin32(&create_info, &window))
        {
            printf("ERROR: failed to create Win32 window\n");
            exit(EXIT_FAILURE);
        }
    }

    while (ReadWindowEventsWin32());

    FreeModuleWGL();
    FreeModuleWin32();
    return 0;
}