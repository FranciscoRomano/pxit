#include "core/GLES3/library.h"
#include "core/GLX/library.h"
#include "core/X11/window.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// https://xcb.freedesktop.org/opengl/
// https://alexvia.com/post/002_initializing_opengl_on_x11/
// https://github.com/gamedevtech/X11OpenGLWindow

const char* vshader_glsl =
"#version 300 es\n"
"precision mediump float;\n"
"layout (location = 0) in vec2 vb_position;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(vb_position, 0.0, 1.0);\n"
"}\0";

const char* fshader_glsl =
"#version 300 es\n"
"precision mediump float;\n"
"layout(location = 0) out vec4 fb_color;\n"
"void main()\n"
"{\n"
"    fb_color = vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\0";

const float geometry_vbo[] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f,
};

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

    GLES20.glDisable(GL_DEPTH_TEST);
    GLES20.glDisable(GL_CULL_FACE);

    int success;

    GLuint vshader = GLES20.glCreateShader(GL_VERTEX_SHADER);
    GLES20.glShaderSource(vshader, 1, &vshader_glsl, NULL);
    GLES20.glCompileShader(vshader);
    GLES20.glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to compile vertex shader\n");
        exit(EXIT_FAILURE);
    }

    GLuint fshader = GLES20.glCreateShader(GL_FRAGMENT_SHADER);
    GLES20.glShaderSource(fshader, 1, &fshader_glsl, NULL);
    GLES20.glCompileShader(fshader);
    GLES20.glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to compile fragment shader\n");
        exit(EXIT_FAILURE);
    }

    GLuint program = GLES20.glCreateProgram();
    GLES20.glAttachShader(program, vshader);
    GLES20.glAttachShader(program, fshader);
    GLES20.glLinkProgram(program);
    GLES20.glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to link program\n");
        exit(EXIT_FAILURE);
    }
    GLES20.glValidateProgram(program);
    GLES20.glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to validate program\n");
        exit(EXIT_FAILURE);
    }

    GLuint vao;
    GLES30.glGenVertexArrays(1, &vao);
    GLES30.glBindVertexArray(vao);

    GLuint vbo;
    GLES20.glGenBuffers(1, &vbo);
    GLES20.glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GLES20.glBufferData(GL_ARRAY_BUFFER, sizeof(geometry_vbo), geometry_vbo, GL_STATIC_DRAW);

    GLES20.glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    GLES20.glEnableVertexAttribArray(0);

    GLES30.glBindVertexArray(0);
    GLES20.glBindBuffer(GL_ARRAY_BUFFER, 0);

    while (ReadWindowEventsX11(&ctx))
    {
        GLES20.glClearColor(1, 0, 0, 1);
        GLES20.glClear(GL_COLOR_BUFFER_BIT);

        GLES20.glUseProgram(program);
        GLES30.glBindVertexArray(vao);
        GLES20.glDrawArrays(GL_TRIANGLES, 0, 3);

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