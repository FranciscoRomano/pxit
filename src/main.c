#include <pxit/pxit.h>
#include <stdio.h>
#include <time.h>
#if IS_PLATFORM_WINDOWS
#include "core/windows/user32.h"
#endif// IS_PLATFORM_WINDOWS

GLint count = 0;
GLfloat r = 1.0f, dr = 0.0001f;
GLfloat g = 1.0f, dg = 0.0002f;
GLfloat b = 1.0f, db = 0.0004f;

bool is_dragging = false;

int32_t window_x = 40;
int32_t window_y = 40;
int32_t drag_mouse_x = 40;
int32_t drag_mouse_y = 40;

void mouse_down(Window window, uint32_t key)
{
    if (key == MOUSE_LEFT) is_dragging = true;
}

void mouse_leave(Window window, uint32_t left, uint32_t top)
{
    is_dragging = false;
}

void mouse_up(Window window, uint32_t key)
{
    if (key == MOUSE_LEFT) is_dragging = false;
}

void window_draw(Window window)
{
    glClearColor(r, g, b, 0.5f);
    glViewport(0, 0, 1920, 1040);
    glScissor(0, 0, 1920, 1040);
    glClear(GL_COLOR_BUFFER_BIT);

    if (r >= 1.0f || r <= 0.0f) dr = -dr;
    if (g >= 1.0f || g <= 0.0f) dg = -dg;
    if (b >= 1.0f || b <= 0.0f) db = -db;
    r += dr;
    g += dg;
    b += db;

    count++;
}

int main(void)
{
    Window window;
    WindowEvents events = {};
    events.OnMouseDown  = mouse_down;
    events.OnMouseLeave = mouse_leave;
    events.OnMouseUp    = mouse_up;
    events.OnWindowDraw = window_draw;

    WindowCreateInfo create_info = {};
    create_info.Top     = window_y;
    create_info.Left    = window_x;
    create_info.Width   = 1920;
    create_info.Height  = 1040;
    create_info.pTitle  = "My Window";
    create_info.pEvents = &events;
    CreateWindow(&create_info, &window);

    double time, start = (double)clock() / CLOCKS_PER_SEC;

    while (ReadWindowEvents())
    {
        #if IS_PLATFORM_WINDOWS
        POINT point;
        _user32.GetCursorPos(&point);
        if (is_dragging)
        {
            window_x += point.x - drag_mouse_x;
            window_y += point.y - drag_mouse_y;
        }
        #endif// IS_PLATFORM_WINDOWS

        drag_mouse_x = point.x;
        drag_mouse_y = point.y;
        MoveWindow(window, window_x, window_y);
        DrawWindow(window);

        time = (double)clock() / CLOCKS_PER_SEC;
        if ((time - start) >= 1.0)
        {
            printf("fps: %i\n", count);
            count = 0;
            start = (double)clock() / CLOCKS_PER_SEC;
        }
    }
}