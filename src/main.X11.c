#include "main.GLES.c"
#include "core/GLX/module.h"
#include "core/X11/window.h"
#include <unistd.h>

int main(int argc, char** argv)
{
    if (!LoadModuleGLX())
    {
        printf("ERROR: failed to load GLX module\n");
        exit(EXIT_FAILURE);
    }

    WindowX11 win;
    if (!CreateWindowX11(800, 600, &win))
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
    GLXFBConfig* fbc = GLX.glXChooseFBConfig(X11.hDisplay, X11.XDefaultScreen(X11.hDisplay), fbc_attribs, &fbc_count);
    if (!fbc)
    {
        printf("ERROR: failed to retrieve GLX framebuffer config\n");
        exit(EXIT_FAILURE);
    }
    GLXFBConfig best_fbc = fbc[0];
    X11.XFree(fbc);

    XVisualInfo* vi = GLX.glXGetVisualFromFBConfig(X11.hDisplay, best_fbc);

    Colormap cm = X11.XCreateColormap(X11.hDisplay, X11.XScreenOfDisplay(X11.hDisplay, vi->screen)->root, vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = cm;
    X11.XChangeWindowAttributes(X11.hDisplay, win.hID, CWColormap, &swa);

    GLXContext glx_ctx = GLX.glXCreateNewContext(X11.hDisplay, best_fbc, GLX_RGBA_TYPE, 0, True);
    GLX.glXMakeCurrent(X11.hDisplay, win.hID, glx_ctx);
    if (!GLX.glXIsDirect(X11.hDisplay, glx_ctx))
    {
        printf("ERROR: failed to get direct GLX context\n");
        exit(EXIT_FAILURE);
    }

    Init_GLES3();

    while (ReadWindowEventsX11())
    {
        Draw_GLES3();

        GLX.glXSwapBuffers(X11.hDisplay, win.hID);
        sleep(0);
    }

    GLX.glXDestroyContext(X11.hDisplay, glx_ctx);
    DestroyWindowX11(&win);
    FreeModuleGLX();
    FreeModuleX11();
    return 0;
}