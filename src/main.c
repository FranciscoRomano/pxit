#if defined(IS_PLATFORM_LINUX)
#include "main.X11.c"
#else
#include <pxit/core/window.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "main.GLES.c"

void on_window_close(Window window)
{
    _DestroyWindow(window);
}

void on_window_create(Window window)
{
    Init_GLES3();
}

void on_window_paint(Window window)
{
    Draw_GLES3();
}

void on_window_size(Window window, uint32_t width, uint32_t height)
{
    GLES20.glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
    WindowCallbacks callbacks;
    memset(&callbacks, 0, sizeof(WindowCallbacks));
    callbacks.OnWindowClose  = on_window_close;
    callbacks.OnWindowCreate = on_window_create;
    callbacks.OnWindowPaint  = on_window_paint;
    callbacks.OnWindowSize   = on_window_size;

    WindowCreateInfo create_info;
    create_info.Left       = 40;
    create_info.Top        = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "";
    create_info.pCallbacks = &callbacks;
    if (!_CreateWindow(&create_info, NULL))
    {
        printf("ERROR: failed to create window\n");
        exit(EXIT_FAILURE);
    }

    while (_ReadWindowEvents());
    return 0;
}
#endif