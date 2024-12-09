#include <pxit/core/window.h>
#include "main.GLES.c"

void on_window_create(Window window)
{
    Init_GLES3();
}

void on_window_paint(Window window)
{
    Draw_GLES3();
}

int main(int argc, char** argv)
{
    WindowCallbacks callbacks;
    memset(&callbacks, 0, sizeof(WindowCallbacks));
    callbacks.OnWindowCreate = on_window_create;
    callbacks.OnWindowPaint  = on_window_paint;

    WindowCreateInfo create_info;
    create_info.Left       = 40;
    create_info.Top        = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "";
    create_info.pCallbacks = &callbacks;
    if (!CreateWindow(&create_info, NULL))
    {
        printf("ERROR: failed to create window\n");
        exit(EXIT_FAILURE);
    }

    while (ReadWindowEvents());
    return 0;
}