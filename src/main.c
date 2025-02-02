#include <pxit/pxit.h>
#include <stdio.h>

GLfloat r = 1.0f, dr = 0.001f;
GLfloat g = 1.0f, dg = 0.002f;
GLfloat b = 1.0f, db = 0.004f;

void draw(Window window)
{
    glClearColor(r, g, b, 1);
    glViewport(0, 0, 800, 600);
    glClear(GL_COLOR_BUFFER_BIT);

    if (r >= 1.0f || r <= 0.0f) dr = -dr;
    if (g >= 1.0f || g <= 0.0f) dg = -dg;
    if (b >= 1.0f || b <= 0.0f) db = -db;
    r += dr;
    g += dg;
    b += db;
}

int main(void)
{
    Window window;
    WindowEvents events = {};
    events.OnWindowDraw = draw;

    WindowCreateInfo create_info = {};
    create_info.Top     = 40;
    create_info.Left    = 40;
    create_info.Width   = 800;
    create_info.Height  = 600;
    create_info.pTitle  = "My Window";
    create_info.pEvents = &events;
    CreateWindow(&create_info, &window);

    while (ReadWindowEvents())
    {
        DrawWindow(window);
    }
}