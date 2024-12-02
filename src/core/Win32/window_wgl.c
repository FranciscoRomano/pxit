// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
// -------------------------------------------------------------------------------------------------------------------------- //

bool _FreeContextWGL(_WindowWin32* pWindow)
{
    // unset WGL context
    WGL.wglMakeCurrent(pWindow->wgl.hDC, NULL);

    // delete the WGL context
    if (!WGL.wglDeleteContext(pWindow->wgl.hGLRC))
    {
        printf("ERROR: failed to delete WGL context\n");
        return false;
    }

    // release the device context
    if (!ReleaseDC(pWindow->hWnd, pWindow->wgl.hDC))
    {
        printf("ERROR: failed to release device context\n");
        return false;
    }

    return true;
}

bool _MakeCurrentWGL(_WindowWin32* pWindow)
{
    // make WGL context current
    if (WGL.wglMakeCurrent(pWindow->wgl.hDC, pWindow->wgl.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        return false;
    }

    return true;
}

bool _SwapBuffersWGL(_WindowWin32* pWindow)
{
    // swap WGL layer buffers
    if (!WGL.wglSwapLayerBuffers(pWindow->wgl.hDC, WGL_SWAP_MAIN_PLANE))
    {
        printf("ERROR: failed to swap WGL layer buffers\n");
        return false;
    }

    return true;
}

bool _InitContextWGL(_WindowWin32* pWindow)
{
    // get device context
    pWindow->wgl.hDC = GetDC(pWindow->hWnd);
    if (!pWindow->wgl.hDC)
    {
        printf("ERROR: failed to get device context\n");
        return false;
    }

    // set the pixel format
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType   = PFD_TYPE_RGBA;
    pfd.cColorBits   = 32;
    pfd.cDepthBits   = 24;
    pfd.cStencilBits = 8;
    int format = ChoosePixelFormat(pWindow->wgl.hDC, &pfd);
    if (format == 0 || SetPixelFormat(pWindow->wgl.hDC, format, &pfd) == FALSE)
    {
        printf("ERROR: failed to set pixel format\n");
        ReleaseDC(pWindow->hWnd, pWindow->wgl.hDC);
        return false;
    }

    // create a new WGL context
    pWindow->wgl.hGLRC = WGL.wglCreateContext(pWindow->wgl.hDC);
    if (!pWindow->wgl.hGLRC)
    {
        printf("ERROR: failed to create WGL context\n");
        ReleaseDC(pWindow->hWnd, pWindow->wgl.hDC);
        return false;
    }

    // make the WGL context current
    if (!WGL.wglMakeCurrent(pWindow->wgl.hDC, pWindow->wgl.hGLRC))
    {
        printf("ERROR: failed to make WGL context current\n");
        WGL.wglDeleteContext(pWindow->wgl.hGLRC);
        ReleaseDC(pWindow->hWnd, pWindow->wgl.hDC);
        return false;
    }

    // set default WGL implementation
    pWindow->pfnFreeContext = _FreeContextWGL;
    pWindow->pfnMakeCurrent = _MakeCurrentWGL;
    pWindow->pfnSwapBuffers = _SwapBuffersWGL;
    return true;
}