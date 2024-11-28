#include "core/GLES3/library.h"
#include <stdlib.h>
#include <stdio.h>

// https://xcb.freedesktop.org/opengl/
// https://alexvia.com/post/002_initializing_opengl_on_x11/
// https://github.com/gamedevtech/X11OpenGLWindow

int success;

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

GLuint vshader;
GLuint fshader;
GLuint program;
GLuint vao;
GLuint vbo;

void Init_GLES3()
{
    GLES20.glDisable(GL_DEPTH_TEST);
    GLES20.glDisable(GL_CULL_FACE);

    vshader = GLES20.glCreateShader(GL_VERTEX_SHADER);
    GLES20.glShaderSource(vshader, 1, &vshader_glsl, NULL);
    GLES20.glCompileShader(vshader);
    GLES20.glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to compile vertex shader\n");
        exit(EXIT_FAILURE);
    }

    fshader = GLES20.glCreateShader(GL_FRAGMENT_SHADER);
    GLES20.glShaderSource(fshader, 1, &fshader_glsl, NULL);
    GLES20.glCompileShader(fshader);
    GLES20.glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to compile fragment shader\n");
        exit(EXIT_FAILURE);
    }

    program = GLES20.glCreateProgram();
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

    GLES30.glGenVertexArrays(1, &vao);
    GLES30.glBindVertexArray(vao);

    GLES20.glGenBuffers(1, &vbo);
    GLES20.glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GLES20.glBufferData(GL_ARRAY_BUFFER, sizeof(geometry_vbo), geometry_vbo, GL_STATIC_DRAW);

    GLES20.glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    GLES20.glEnableVertexAttribArray(0);

    GLES30.glBindVertexArray(0);
    GLES20.glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Draw_GLES3()
{
    GLES20.glClearColor(1, 0, 0, 1);
    GLES20.glClear(GL_COLOR_BUFFER_BIT);

    GLES20.glUseProgram(program);
    GLES30.glBindVertexArray(vao);
    GLES20.glDrawArrays(GL_TRIANGLES, 0, 3);
}