// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "context.h"
#include <stdio.h>
// -------------------------------------------------------------------------------------------------------------------------- //

PxitPlatformWin32 GWin32 = { FALSE };

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void FreePxitPlatformWin32()
{
    // check if platform exists
    if (!GWin32.bExists) return;
    GWin32.bExists = FALSE;

    // unregister the window class
    if (!UnregisterClassA(GWin32.pClassName, GWin32.hInstance))
    {
        printf("ERROR: Failed to unregister class\n");
        exit(EXIT_FAILURE);
    };
}

void InitPxitPlatformWin32()
{
    // check if platform exists
    if (GWin32.bExists) return;
    GWin32.bExists = TRUE;

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
    wc.hInstance     = GWin32.hInstance = GetModuleHandleA(NULL);
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = "PxitMenu";
    wc.lpszClassName = GWin32.pClassName = "PxitClass";
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!RegisterClassExA(&wc))
    {
        printf("ERROR: Failed to register class\n");
        exit(EXIT_FAILURE);
    }

    // get the location of the executable
    const size_t location_size = sizeof(GWin32.location) / sizeof(CHAR);
    GetModuleFileNameA(GWin32.hInstance, GWin32.location, location_size);
    for (size_t i = location_size - 1; GWin32.location[i] != '\\'; i--)
    {
        GWin32.location[i] = (CHAR)0;
    }
}

// -------------------------------------------------------------------------------------------------------------------------- //