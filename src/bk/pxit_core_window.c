#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pxit/core/window.h>

void on_key_down(Window win, uint32_t key)
{
    // close window is escape key is pressed
    if (key == KEY_ESCAPE) CloseWindow(win);
}

void on_window_paint(Window win)
{
    // ... rendering code goes here ...
}

void on_window_close(Window win)
{
    // destroy window once it is closed
    DestroyWindow(win);
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

        WindowCreateInfo info;
        memset(&info, 0, sizeof(WindowCreateInfo));
        info.Left       = 10;
        info.Top        = 10;
        info.Width      = 800;
        info.Height     = 600;
        info.pTitle     = "MyWindow1";
        info.pCallbacks = &callbacks;

        if (!CreateWindow(&info, NULL))
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

        WindowCreateInfo info;
        memset(&info, 0, sizeof(WindowCreateInfo));
        info.Left   = 80;
        info.Top    = 80;
        info.Width  = 300;
        info.Height = 200;
        info.pTitle = "MyWindow2";

        if (!CreateWindow(&info, NULL))
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