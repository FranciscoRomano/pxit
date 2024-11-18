#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_KEYUP:
            if (wParam == VK_ESCAPE)
            {
                printf("The escape key is up\n");
                PostQuitMessage(0);
            }
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE)
            {
                printf("The escape key is down\n");
            }
            break;
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        default:
            break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main(int argc, char** argv)
{
    HINSTANCE hInstance   = GetModuleHandleA(NULL);
    char*     lpClassName = "PxitPlatformWin32Class";

    // register a new window class
    WNDCLASSEXA wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEXW));
    wc.cbClsExtra    = 0;
    wc.cbSize        = sizeof(WNDCLASSEXW);
    wc.cbWndExtra    = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance     = hInstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = lpClassName;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!RegisterClassExA(&wc))
    {
        printf("ERROR: Failed to register class\n");
        exit(EXIT_FAILURE);
    }

    HWND hWnd = CreateWindowA(
        lpClassName,
        "",
        WS_POPUPWINDOW | WS_CAPTION | WS_SIZEBOX,
        10,
        10,
        800,
        600,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (hWnd == NULL)
    {
        printf("ERROR: Failed to create window\n");
        exit(EXIT_FAILURE);
    }

    ShowWindow(hWnd, SW_NORMAL);

    MSG msg = {};
    while (1)
    {
        if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
            if (msg.message == WM_QUIT) break;
        }
    }

    DestroyWindow(hWnd);

    if (!UnregisterClassA(lpClassName, hInstance))
    {
        printf("ERROR: Failed to unregister class\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}