// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "context.h"
#include <stdio.h>
// -------------------------------------------------------------------------------------------------------------------------- //

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void FreePlatformContextWin32(PlatformContextWin32* ctx)
{
    // unregister a window class
    if (!(UnregisterClassA(ctx->lpszClassName, ctx->hInstance)))
    {
        printf("ERROR: Failed to unregister class\n");
        exit(EXIT_FAILURE);
    };
}

void InitPlatformContextWin32(PlatformContextWin32* ctx)
{
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
    wc.hInstance     = ctx->hInstance = ctx->hInstance;
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = "PxitMenu";
    wc.lpszClassName = ctx->lpszClassName = "PxitClass";
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    if (!(RegisterClassExA(&wc)))
    {
        printf("ERROR: Failed to register class\n");
        exit(EXIT_FAILURE);
    };
}

// -------------------------------------------------------------------------------------------------------------------------- //