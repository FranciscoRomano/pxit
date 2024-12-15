#include <pxit/core/surface.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "main.GLES.c"

void on_surface_close(Surface surface)
{
    _DestroySurface(surface);
}

void on_surface_create(Surface surface)
{
    Init_GLES3();
}

void on_surface_paint(Surface surface)
{
    Draw_GLES3();
}

void on_surface_size(Surface surface, uint32_t width, uint32_t height)
{
    GLES20.glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
    Surface surface;

    SurfaceCallbacks callbacks;
    memset(&callbacks, 0, sizeof(SurfaceCallbacks));
    callbacks.OnSurfaceClose  = on_surface_close;
    callbacks.OnSurfaceCreate = on_surface_create;
    callbacks.OnSurfacePaint  = on_surface_paint;
    callbacks.OnSurfaceSize   = on_surface_size;

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

    while (_ReadSurfaceEvents())
    {
        #if IS_PLATFORM_LINUX
        callbacks.OnSurfacePaint(surface);
        #endif
    }
    return 0;
}