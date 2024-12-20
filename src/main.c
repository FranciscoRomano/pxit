#define GL_APICALL
#define GL_APIENTRY
#include <GLES3/gl32.h>
#include <pxit/core/surface.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void draw(Surface surface)
{
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    Surface surface;

    SurfaceCallbacks callbacks;
    memset(&callbacks, 0, sizeof(SurfaceCallbacks));
    callbacks.OnSurfacePaint = draw;

    SurfaceCreateInfo create_info;
    create_info.Left       = 40;
    create_info.Top        = 40;
    create_info.Width      = 800;
    create_info.Height     = 600;
    create_info.pTitle     = "";
    create_info.pCallbacks = &callbacks;
    if (!_CreateSurface(&create_info, &surface))
    {
        printf("ERROR: failed to create surface\n");
        exit(EXIT_FAILURE);
    }

    while (_ReadSurfaceEvents());
    return 0;
}