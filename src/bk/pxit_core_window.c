#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pxit/core/window.h>

void on_key_down(Window window, uint32_t key)
{
    // close window if escape key is pressed
    if (key == KEY_ESCAPE) CloseWindow(window);
}

void on_window_paint(Window window)
{
    // ... rendering code goes here ...
}

void on_window_close(Window window)
{
    // destroy window once it is closed
    DestroyWindow(window);
}

int main(int argc, char** argv)
{
    // create the 1st window { 10, 10, 800, 600 }
    {
        WindowCallbacks callbacks;
        memset(&callbacks, 0, sizeof(WindowCallbacks));
        callbacks.OnKeyDown     = on_key_down;
        callbacks.OnWindowClose = on_window_close;
        callbacks.OnWindowPaint = on_window_paint;

        WindowCreateInfo create_info;
        memset(&create_info, 0, sizeof(WindowCreateInfo));
        create_info.Left       = 10;
        create_info.Top        = 10;
        create_info.Width      = 800;
        create_info.Height     = 600;
        create_info.pTitle     = "MyWindow1";
        create_info.pCallbacks = &callbacks;

        if (!CreateWindow(&create_info, NULL))
        {
            printf("ERROR: failed to create 1st window\n");
            exit(EXIT_FAILURE);
        }
    }

    // create the 2nd window { 80, 80, 300, 200 }
    {
        WindowCallbacks callbacks;
        memset(&callbacks, 0, sizeof(WindowCallbacks));
        callbacks.OnWindowClose = on_window_close;
        callbacks.OnWindowPaint = on_window_paint;

        WindowCreateInfo create_info;
        memset(&create_info, 0, sizeof(WindowCreateInfo));
        create_info.Left   = 80;
        create_info.Top    = 80;
        create_info.Width  = 300;
        create_info.Height = 200;
        create_info.pTitle = "MyWindow2";

        if (!CreateWindow(&create_info, NULL))
        {
            printf("ERROR: failed to create 2nd window\n");
            exit(EXIT_FAILURE);
        }
    }

    // read events until all windows are destroyed
    while (ReadWindowEvents())
    {
        // ... frame logic goes here ...
    }
}