#include <pxit/pxit.h>
#include <stdio.h>

void draw0(Window window)
{
    glClearColor(0, 0, 1, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
}

void draw1(Window window)
{
    glClearColor(0, 1, 0, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
}

void draw2(Window window)
{
    glClearColor(0, 1, 1, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
}

void draw3(Window window)
{
    glClearColor(1, 0, 0, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(void)
{
    WindowEvents events = {};

    WindowCreateInfo create_info = {};
    create_info.Top     = 40;
    create_info.Left    = 40;
    create_info.Width   = 800;
    create_info.Height  = 600;
    create_info.pTitle  = "My Window";
    create_info.pEvents = &events;

    events.OnWindowDraw = draw0;
    CreateWindow(&create_info, NULL);

    events.OnWindowDraw = draw1;
    CreateWindow(&create_info, NULL);

    events.OnWindowDraw = draw2;
    CreateWindow(&create_info, NULL);

    events.OnWindowDraw = draw3;
    CreateWindow(&create_info, NULL);

    while (ReadWindowEvents());
}