// https://stackoverflow.com/questions/5036620/opengl-v1-1-off-screen-rendering-or-render-directly-to-bitmap
// https://community.khronos.org/t/pbuffer/31347
// https://learn.microsoft.com/en-us/windows/win32/opengl/wgl-functions
// https://github.com/Stehfyn/imgui-borderless-win32

#include <pxit/pxit.h>
#include <stdio.h>
#include <time.h>
#if IS_PLATFORM_WINDOWS
#include "core/windows/user32.h"
#endif// IS_PLATFORM_WINDOWS

const int size = 100;

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
"layout (location = 0) out vec4 fb_color;\n"
"uniform vec3 ub_color;"
"void main()\n"
"{\n"
"    fb_color = vec4(ub_color, 0.75);\n"
"}\0";

GLuint vbo;
GLuint program;
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
    glViewport(0, 0, size, size);
    glScissor(0, 0, size, size);

    glClearColor(0, 0, 0, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);

    glUseProgram(program);
    glUniform3f(glGetUniformLocation(program, "ub_color"), r, g, b);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 7);

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
    create_info.Width   = size;
    create_info.Height  = size;
    create_info.pTitle  = "My Window";
    create_info.pEvents = &events;
    CreateWindow(&create_info, &window);

    GLint success;
    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vshader_glsl, NULL);
    glCompileShader(vshader);
    glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to compile vertex shader\n");
        GLint length = 0;
        glGetShaderiv(vshader, GL_INFO_LOG_LENGTH, &length);
        GLchar* buffer = malloc(sizeof(GLchar) * (length + 1));
        glGetShaderInfoLog(vshader, length, &length, buffer);
        printf("ERROR: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &fshader_glsl, NULL);
    glCompileShader(fshader);
    glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to compile fragment shader\n");
        GLint length = 0;
        glGetShaderiv(fshader, GL_INFO_LOG_LENGTH, &length);
        GLchar* buffer = malloc(sizeof(GLchar) * (length + 1));
        glGetShaderInfoLog(fshader, length, &length, buffer);
        printf("ERROR: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    program = glCreateProgram();
    glAttachShader(program, vshader);
    glAttachShader(program, fshader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to link program\n");
        exit(EXIT_FAILURE);
    }
    glValidateProgram(program);
    glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
    if (!success)
    {
        printf("ERROR: failed to validate program\n");
        exit(EXIT_FAILURE);
    }

    glGenBuffers(1, &vbo);
    const float vbo_data[] = {
        0.00f,  0.00f,
        0.00f,  1.00f,
        0.65f, -1.00f,
       -1.00f,  0.25f,
        1.00f,  0.25f,
       -0.65f, -1.00f,
        0.00f,  1.00f,
    };
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vbo_data), vbo_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

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
            MoveWindow(window, window_x, window_y);
        }
        #endif// IS_PLATFORM_WINDOWS

        drag_mouse_x = point.x;
        drag_mouse_y = point.y;
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