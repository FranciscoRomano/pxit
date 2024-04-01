#include <GLES32.h>
#include <OpenGL_WGL.h>
#include <iostream>
#include <Windows.h>

bool is_running = false;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (is_running) switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            is_running = false;
            break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void* LetsGetThatOpenGLFunction(const char* name)
{
    return (void*)pxProcOpenGL_WGL(name);
}

int main(int argc, char** argv)
{
    WNDCLASSEXA wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEXW));
    wc.cbClsExtra    = 0;
    wc.cbSize        = sizeof(WNDCLASSEXW);
    wc.cbWndExtra    = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance     = GetModuleHandle(NULL);
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = "pxlibrary_win32";
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!RegisterClassExA(&wc))
    {
        MessageBoxA(NULL, "Failed to register Class", "BANANAS", MB_OK);
        return -1;
    }
    if (!pxLoadOpenGL_WGL(wc.hInstance, wc.lpszClassName))
    {
        MessageBoxA(NULL, "Failed to load WINGDI WGL library", "BANANAS", MB_OK);
        return -1;
    }

    // set style and size description
    DWORD style = WS_POPUP
                | WS_CLIPSIBLINGS
                | WS_CLIPCHILDREN
                | WS_SIZEBOX
                | WS_MINIMIZEBOX
                | WS_MAXIMIZEBOX
                | WS_CAPTION
                | WS_SYSMENU;
    RECT rect;
    int WINDOW_WIDTH = 800;
    int WINDOW_HEIGHT = 600;
    GetWindowRect(GetDesktopWindow(), &rect);
    rect.top    = (LONG)(((int)rect.bottom + WINDOW_HEIGHT) / 2 - WINDOW_HEIGHT + 0);
    rect.left   = (LONG)(((int)rect.right  + WINDOW_WIDTH ) / 2 - WINDOW_WIDTH  + 0);
    rect.right  = WINDOW_WIDTH;
    rect.bottom = WINDOW_HEIGHT;
    AdjustWindowRect(&rect, style, FALSE);

    // create window
    HWND h_window = CreateWindowExA(
        0,
        wc.lpszClassName,
        "PXIT Engine",
        style,
        rect.left,
        rect.top,
        rect.right,
        rect.bottom,
        NULL,
        NULL,
        wc.hInstance,
        (LPVOID)NULL
    );
    if (!h_window)
    {
        std::cout << "Failed to create Window\n";
        return -1;
    }

    // create device context
    HDC h_window_dc = GetDC(h_window);

    PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
        PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
        32,                   // Colordepth of the framebuffer.
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        24,                   // Number of bits for the depthbuffer
        8,                    // Number of bits for the stencilbuffer
        0,                    // Number of Aux buffers in the framebuffer.
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };
    int  letWindowsChooseThisPixelFormat;
    letWindowsChooseThisPixelFormat = ChoosePixelFormat(h_window_dc, &pfd); 
    SetPixelFormat(h_window_dc, letWindowsChooseThisPixelFormat, &pfd);

    auto glcontext = GOpenGLCallbacks_WGL.CreateContext(h_window_dc);
    GOpenGLCallbacks_WGL.MakeCurrent(h_window_dc, glcontext);

    if (LoadOpenGLES32(LetsGetThatOpenGLFunction) != 1)
    {
        MessageBoxA(NULL, "Failed to load OpenGL ES 3.2", "BANANAS", MB_OK);
        return -1;
    }

    MessageBoxA(0,(char*)glGetString(GL_VERSION), "OPENGL VERSION",0);

    // display window
    ShowWindow(h_window, SW_NORMAL);
    UpdateWindow(h_window);

    MSG msg = {};
    is_running = true;
    while (is_running)
    {
        // peek window messages
        while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
        {
            // translate & dispatch messages
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (!is_running)
            break;

        glClearColor(1, 0, 0, 1);
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT);

        //InvalidateRect(h_window, NULL, FALSE);
        //UpdateWindow(h_window);
        SwapBuffers(h_window_dc);
        Sleep(0);
    }

    GOpenGLCallbacks_WGL.DeleteContext(glcontext);
    ReleaseDC(h_window, h_window_dc);
    DestroyWindow(h_window);
    pxFreeOpenGL_WGL();
    UnregisterClassA(wc.lpszClassName, wc.hInstance);
    return 0;
}