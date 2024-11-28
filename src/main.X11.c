#include "main.GLES3.c"
#include "core/GLX/library.h"
#include "core/X11/window.h"
#include <unistd.h>

int main(int argc, char** argv)
{
    if (!LoadLibraryX11())
    {
        printf("ERROR: failed to load X11 library\n");
        exit(EXIT_FAILURE);
    }

    if (!LoadLibraryGLX())
    {
        printf("ERROR: failed to load GLX library\n");
        exit(EXIT_FAILURE);
    }

    WindowContextX11 ctx;
    if (!CreateWindowContextX11(&ctx))
    {
        printf("ERROR: failed to create X11 window context\n");
        exit(EXIT_FAILURE);
    }

    WindowX11 win;
    if (!CreateWindowX11(&ctx, 800, 600, &win))
    {
        printf("ERROR: failed to create X11 window\n");
        exit(EXIT_FAILURE);
    }

    int fbc_count;
    static int fbc_attribs[] = {
      GLX_X_RENDERABLE,  True,
      GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
      GLX_RENDER_TYPE,   GLX_RGBA_BIT,
      GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
      GLX_RED_SIZE,      8,
      GLX_GREEN_SIZE,    8,
      GLX_BLUE_SIZE,     8,
      GLX_ALPHA_SIZE,    8,
      GLX_DEPTH_SIZE,    24,
      GLX_STENCIL_SIZE,  8,
      GLX_DOUBLEBUFFER,  True,
      None
    };
    GLXFBConfig* fbc = GLX.glXChooseFBConfig(ctx.hDisplay, X11.XDefaultScreen(ctx.hDisplay), fbc_attribs, &fbc_count);
    if (!fbc)
    {
        printf("ERROR: failed to retrieve GLX framebuffer config\n");
        exit(EXIT_FAILURE);
    }
    GLXFBConfig best_fbc = fbc[0];
    X11.XFree(fbc);

    XVisualInfo* vi = GLX.glXGetVisualFromFBConfig(ctx.hDisplay, best_fbc);

    Colormap cm = X11.XCreateColormap(ctx.hDisplay, X11.XScreenOfDisplay(ctx.hDisplay, vi->screen)->root, vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = cm;
    X11.XChangeWindowAttributes(ctx.hDisplay, win.hID, CWColormap, &swa);

    GLXContext glx_ctx = GLX.glXCreateNewContext(ctx.hDisplay, best_fbc, GLX_RGBA_TYPE, 0, True);
    GLX.glXMakeCurrent(ctx.hDisplay, win.hID, glx_ctx);
    if (!GLX.glXIsDirect(ctx.hDisplay, glx_ctx))
    {
        printf("ERROR: failed to get direct GLX context\n");
        exit(EXIT_FAILURE);
    }

    Init_GLES3();

    while (ReadWindowEventsX11(&ctx))
    {
        Draw_GLES3();

        GLX.glXSwapBuffers(ctx.hDisplay, win.hID);
        sleep(0);
    }

    GLX.glXDestroyContext(ctx.hDisplay, glx_ctx);
    DestroyWindowX11(&ctx, &win);
    DestroyWindowContextX11(&ctx);
    FreeLibraryGLX();
    FreeLibraryX11();
    return 0;
}