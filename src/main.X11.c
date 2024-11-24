#include "core/GLX/library.h"
#include "core/X11/window.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// https://xcb.freedesktop.org/opengl/
// https://alexvia.com/post/002_initializing_opengl_on_x11/
// https://github.com/gamedevtech/X11OpenGLWindow

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

    int major_version;
    int minor_version;
    if (!GLX.glXQueryVersion(ctx.hDisplay, &major_version, &minor_version))
    {
        printf("ERROR: failed to query GLX library version");
        exit(EXIT_FAILURE);
    }
    if ((major_version == 1 && minor_version < 3) || major_version < 1)
    {
        printf("ERROR: GLX library version must be 1.3 or greater");
        exit(EXIT_FAILURE);
    }
    printf("-- using GLX v%i.%i\n", major_version, minor_version);

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
    printf("-- found %i matching FB configs.\n", fbc_count);
    GLXFBConfig best_fbc = fbc[0];
    X11.XFree(fbc);

    XVisualInfo* vi = GLX.glXGetVisualFromFBConfig(ctx.hDisplay, best_fbc);

    Colormap cm = X11.XCreateColormap(ctx.hDisplay, X11.XScreenOfDisplay(ctx.hDisplay, vi->screen)->root, vi->visual, AllocNone);
    XSetWindowAttributes swa;
    swa.colormap = cm;
    X11.XChangeWindowAttributes(ctx.hDisplay, win.hID, CWColormap, &swa);

    GLXContext glx_ctx = GLX.glXCreateNewContext(ctx.hDisplay, best_fbc, GLX_RGBA_TYPE, 0, True);
    if (GLX.glXIsDirect(ctx.hDisplay, glx_ctx))
    {
        printf("-- direct GLX context obtained\n");
    }

    void (*pfn_glClearColor)(float,float,float,float) = GLX.glXGetProcAddress("glClearColor");
    void (*pfn_glClear)(unsigned int) = GLX.glXGetProcAddress("glClear");
    
    while (ReadWindowEventsX11(&ctx))
    {
        GLX.glXMakeCurrent(ctx.hDisplay, win.hID, glx_ctx);

        pfn_glClearColor(1, 0, 0, 1);
        pfn_glClear(GL_COLOR_BUFFER_BIT);

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