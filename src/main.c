#include <pxit/pxit.h>

void draw(Window window)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void init0(Window window) { glClearColor(0, 0, 1, 1); }
void init1(Window window) { glClearColor(0, 1, 0, 1); }
void init2(Window window) { glClearColor(0, 1, 1, 1); }
void init3(Window window) { glClearColor(1, 0, 0, 1); }

int main(void)
{
    WindowCallbacks callbacks = {};
    callbacks.OnWindowDraw = draw;

    WindowCreateInfo create_info = {};
    create_info.Top        = 40;
    create_info.Left       = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "My Window";
    create_info.pCallbacks = &callbacks;

    callbacks.OnWindowCreate = init0;
    CreateWindow(&create_info, NULL);

    callbacks.OnWindowCreate = init1;
    CreateWindow(&create_info, NULL);

    callbacks.OnWindowCreate = init2;
    CreateWindow(&create_info, NULL);

    callbacks.OnWindowCreate = init3;
    CreateWindow(&create_info, NULL);

    while (ReadWindowEvents());
}