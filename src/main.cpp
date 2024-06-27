#include <GLES32.h>
#include <OpenGL_WGL.h>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <Macros/Architecture.h>
#include <Macros/Compiler.h>
#include <Macros/OperatingSystem.h>
// https://github.com/cpredef/predef/blob/master/Compilers.md

bool is_running = false;

typedef struct PX_HMONITOR_INFO {
    HMONITOR hMonitor;
    RECT     rect;
} PX_HMONITOR_INFO;

std::vector<PX_HMONITOR_INFO> px_monitor_infos;

BOOL PxMonitorEnumProc(HMONITOR hMonitor, HDC hDC, LPRECT lpRect, LPARAM lParam)
{
    px_monitor_infos.push_back({
        hMonitor,
        *lpRect
    });
    return TRUE;
}

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
    std::string arch_info = ARCHITECTURE_NAME;
    std::string comp_info = COMPILER_VERSION_NAME " (" + std::to_string(COMPILER_VERSION) + ")";
    std::string title = arch_info + " | " + comp_info;

    MessageBoxA(NULL, title.c_str(), "Platform Information", MB_OK);

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

    EnumDisplayMonitors(NULL, NULL, PxMonitorEnumProc, 0);

    for (auto info : px_monitor_infos)
    {
        MONITORINFO hmonitor_info;
        hmonitor_info.cbSize = sizeof(MONITORINFO);
        if (!GetMonitorInfoW(info.hMonitor, &hmonitor_info)) continue;

        std::wstring msg;
        msg += std::wstring(L"DisplayMonitor\n");
        msg += std::wstring(L"- rcMonitor: {");
        msg += std::wstring(L" left: ")    + std::to_wstring(hmonitor_info.rcMonitor.left);
        msg += std::wstring(L", top: ")    + std::to_wstring(hmonitor_info.rcMonitor.top);
        msg += std::wstring(L", right: ")  + std::to_wstring(hmonitor_info.rcMonitor.right);
        msg += std::wstring(L", bottom: ") + std::to_wstring(hmonitor_info.rcMonitor.bottom);
        msg += std::wstring(L" }\n- rcWork: {");
        msg += std::wstring(L" left: ")    + std::to_wstring(hmonitor_info.rcWork.left);
        msg += std::wstring(L", top: ")    + std::to_wstring(hmonitor_info.rcWork.top);
        msg += std::wstring(L", right: ")  + std::to_wstring(hmonitor_info.rcWork.right);
        msg += std::wstring(L", bottom: ") + std::to_wstring(hmonitor_info.rcWork.bottom);
        msg += std::wstring(L" }");
        MessageBoxW(NULL, msg.c_str(), L"Device", MB_OK);
    }

    DISPLAY_DEVICEW display = {};
    display.cb = sizeof(DISPLAY_DEVICEW);
    for (int i = 0; EnumDisplayDevicesW(NULL, i, &display, EDD_GET_DEVICE_INTERFACE_NAME); i++)
    {
        std::wstring msg;
        msg += std::wstring(L"DisplayDevice[")    + std::to_wstring(i)    + L"]\n";
        msg += std::wstring(L"  DeviceName  : ")  + display.DeviceName   + L",\n";
        msg += std::wstring(L"  DeviceString: ")  + display.DeviceString + L",\n";
        msg += std::wstring(L"  DeviceID    : ")  + display.DeviceID     + L",\n";
        msg += std::wstring(L"  DeviceKey   : ")  + display.DeviceKey    + L",\n";
        MessageBoxW(NULL, msg.c_str(), L"Device", MB_OK);
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

    if (LoadOpenGLES20(LetsGetThatOpenGLFunction) != 1)
    {
        MessageBoxA(NULL, "Failed to load OpenGL ES 2.0", "ERROR", MB_OK);
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