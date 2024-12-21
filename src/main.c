#include <pxit/pxit.h>

void draw(Window window)
{
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(void)
{
    Window window;

    WindowCallbacks callbacks = {};
    callbacks.OnWindowPaint = draw;

    WindowCreateInfo create_info = {};
    create_info.Top        = 40;
    create_info.Left       = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "My Window";
    create_info.pCallbacks = &callbacks;

    CreateWindow(&create_info, &window);

    while (ReadWindowEvents())
    {
        // ...sea wolves are cool...
    }
}