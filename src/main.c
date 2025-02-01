#include <pxit/pxit.h>
#include <stdio.h>

void draw0(Window window)
{
    glClearColor(0, 0, 1, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("draw 0\n");
}

void draw1(Window window)
{
    glClearColor(0, 1, 0, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("draw 1\n");
}

void draw2(Window window)
{
    glClearColor(0, 1, 1, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("draw 2\n");
}

void draw3(Window window)
{
    glClearColor(1, 0, 0, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("draw 3\n");
}

int main(void)
{
    WindowCallbacks callbacks = {};

    WindowCreateInfo create_info = {};
    create_info.Top        = 40;
    create_info.Left       = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "My Window";
    create_info.pCallbacks = &callbacks;

    callbacks.OnWindowDraw = draw0;
    CreateWindow(&create_info, NULL);

    callbacks.OnWindowDraw = draw1;
    CreateWindow(&create_info, NULL);

    callbacks.OnWindowDraw = draw2;
    CreateWindow(&create_info, NULL);

    callbacks.OnWindowDraw = draw3;
    CreateWindow(&create_info, NULL);

    while (ReadWindowEvents());
}