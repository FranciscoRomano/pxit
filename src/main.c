#define GL_APICALL
#define GL_APIENTRY
#include <GLES3/gl32.h>
#include <pxit/core/window.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void draw(Window window)
{
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    Window window;

    WindowCallbacks callbacks;
    memset(&callbacks, 0, sizeof(WindowCallbacks));
    callbacks.OnWindowPaint = draw;

    WindowCreateInfo create_info;
    create_info.Left       = 40;
    create_info.Top        = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "";
    create_info.pCallbacks = &callbacks;
    if (!CreateWindow(&create_info, &window))
    {
        printf("ERROR: failed to create window\n");
        exit(EXIT_FAILURE);
    }

    while (ReadWindowEvents());
    return 0;
}