#define WIN32_LEAN_AND_MEAN 1
#include "main.GLES.c"
#include "core/WGL/module.h"
#include "core/Win32/window.h"

void on_window_close(Window window)
{
    _DestroyWindowWin32((_WindowWin32*)window);
}

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
    if (!LoadModuleWGL())
    {
        printf("ERROR: failed to load WGL module\n");
        exit(EXIT_FAILURE);
    }

    _WindowWin32 window;
    WindowCallbacks callbacks;
    memset(&callbacks, 0, sizeof(WindowCallbacks));
    callbacks.OnWindowClose  = on_window_close;
    callbacks.OnWindowCreate = on_window_create;
    callbacks.OnWindowPaint  = on_window_paint;

    WindowCreateInfo create_info;
    create_info.Left       = 40;
    create_info.Top        = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "";
    create_info.pCallbacks = &callbacks;
    if (!_CreateWindowWin32(&create_info, &window))
    {
        printf("ERROR: failed to create Win32 window\n");
        exit(EXIT_FAILURE);
    }

    while (_ReadWindowEventsWin32());

    FreeModuleWGL();
    FreeModuleWin32();
    return 0;
}