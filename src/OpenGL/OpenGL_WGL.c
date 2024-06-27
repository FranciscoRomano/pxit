// ---------------------------------------------------------------------------------------------- //
// The MIT License (MIT)
// 
// Copyright (c) 2024 Francisco Romano
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ---------------------------------------------------------------------------------------------- //
#include "OpenGL_WGL.h"
HMODULE               GOpenGLLibrary_WGL = NULL; // The WGL library handle
PxOpenGLCallbacks_WGL GOpenGLCallbacks_WGL;      // The WGL library callbacks
// ---------------------------------------------------------------------------------------------- //
BOOL pxFreeOpenGL_WGL()
{
    // 1) free WGL library (if not freed already)
    if (GOpenGLLibrary_WGL != NULL)
    {
        BOOL result = FreeLibrary(GOpenGLLibrary_WGL);
        GOpenGLLibrary_WGL = NULL;
        return result ? TRUE : FALSE;
    }

    return TRUE;
}
// ---------------------------------------------------------------------------------------------- //
BOOL pxLoadOpenGL_WGL(HINSTANCE hInstance, LPCSTR lpszClassName)
{
    // 1) load WGL library (if not loaded already)
    if (GOpenGLLibrary_WGL == NULL)
    {
        GOpenGLLibrary_WGL = LoadLibraryA("opengl32.dll");
        if (!GOpenGLLibrary_WGL)
        {
            MessageBoxA(NULL, "Failed to load 'opengl32.dll'", "ERROR", MB_OK);
            return FALSE;
        }
    }

    // 2) fetch all available WGL procedures by name
    #define IMPL_LOAD_PROCEDURE(Name)\
    *((PROC*)&GOpenGLCallbacks_WGL.Name) = GetProcAddress(GOpenGLLibrary_WGL, "wgl" #Name);
    IMPL_LOAD_PROCEDURE(CopyContext);
    IMPL_LOAD_PROCEDURE(CreateContext);
    IMPL_LOAD_PROCEDURE(CreateLayerContext);
    IMPL_LOAD_PROCEDURE(DeleteContext);
    IMPL_LOAD_PROCEDURE(DescribeLayerPlane);
    IMPL_LOAD_PROCEDURE(GetCurrentContext);
    IMPL_LOAD_PROCEDURE(GetCurrentDC);
    IMPL_LOAD_PROCEDURE(GetLayerPaletteEntries);
    IMPL_LOAD_PROCEDURE(GetProcAddress);
    IMPL_LOAD_PROCEDURE(MakeCurrent);
    IMPL_LOAD_PROCEDURE(RealizeLayerPalette);
    IMPL_LOAD_PROCEDURE(SetLayerPaletteEntries);
    IMPL_LOAD_PROCEDURE(ShareLists);
    IMPL_LOAD_PROCEDURE(SwapLayerBuffers);
    IMPL_LOAD_PROCEDURE(SwapMultipleBuffers);
    IMPL_LOAD_PROCEDURE(UseFontBitmapsA);
    IMPL_LOAD_PROCEDURE(UseFontBitmapsW);
    IMPL_LOAD_PROCEDURE(UseFontOutlinesA);
    IMPL_LOAD_PROCEDURE(UseFontOutlinesW);
    IMPL_LOAD_PROCEDURE(ChoosePixelFormatARB);
    IMPL_LOAD_PROCEDURE(CreateContextAttribsARB);
    IMPL_LOAD_PROCEDURE(GetPixelFormatAttribivARB);
    IMPL_LOAD_PROCEDURE(GetPixelFormatAttribfvARB);
    #undef IMPL_LOAD_PROCEDURE

    // 3) create a dummy window for loading OpenGL 2 or higher
    HWND h_window = CreateWindowExA(
        0L,
        lpszClassName,
        "impl_windows_wgl_window",
        WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
        0,
        0,
        1,
        1,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (!h_window)
    {
        MessageBoxA(NULL, "Failed to create dummy window", "ERROR", MB_OK);
        return FALSE;
    }
    HDC h_window_dc = GetDC(h_window);

    // 4) set the pixel format for the dummy window device context
    PIXELFORMATDESCRIPTOR pixel_format;
    ZeroMemory(&pixel_format, sizeof(pixel_format));
    pixel_format.nSize        = sizeof(pixel_format);
    pixel_format.nVersion     = 1;
    pixel_format.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pixel_format.iPixelType   = PFD_TYPE_RGBA;
    pixel_format.cColorBits   = 32;
    pixel_format.cDepthBits   = 24;
    pixel_format.cStencilBits = 8;
    pixel_format.dwLayerMask  = PFD_MAIN_PLANE;
    int cpf_result = ChoosePixelFormat(h_window_dc, &pixel_format);
    if (!cpf_result || !SetPixelFormat(h_window_dc, cpf_result, &pixel_format))
    {
        MessageBoxA(NULL, "Failed to set pixel format", "ERROR", MB_OK);
        ReleaseDC(h_window, h_window_dc);
        DestroyWindow(h_window);
        return FALSE;
    }

    // 5) create a new OpenGL context and fetch the required procedures
    HGLRC opengl1_context = GOpenGLCallbacks_WGL.CreateContext(h_window_dc);
    if (!opengl1_context)
    {
        MessageBoxA(NULL, "Failed to create opengl context", "ERROR", MB_OK);
        ReleaseDC(h_window, h_window_dc);
        DestroyWindow(h_window);
        return FALSE;
    }
    GOpenGLCallbacks_WGL.MakeCurrent(h_window_dc, opengl1_context);
    #define IMPL_LOAD_PROCEDURE(Name)\
    *((PROC*)&GOpenGLCallbacks_WGL.Name) = GOpenGLCallbacks_WGL.GetProcAddress("wgl" #Name);
    IMPL_LOAD_PROCEDURE(ChoosePixelFormatARB);
    IMPL_LOAD_PROCEDURE(CreateContextAttribsARB);
    IMPL_LOAD_PROCEDURE(GetPixelFormatAttribivARB);
    IMPL_LOAD_PROCEDURE(GetPixelFormatAttribfvARB);
    #undef IMPL_LOAD_PROCEDURE

    // 6) destroy OpenGL context, dummy device context and window before returning
    GOpenGLCallbacks_WGL.MakeCurrent(NULL, NULL);
    GOpenGLCallbacks_WGL.DeleteContext(opengl1_context);
    ReleaseDC(h_window, h_window_dc);
    DestroyWindow(h_window);
    return TRUE;
}
// ---------------------------------------------------------------------------------------------- //
PROC pxProcOpenGL_WGL(LPCSTR lpProcName)
{
    // 1) get the WGL procedure from name
    if (!GOpenGLCallbacks_WGL.GetProcAddress) return (PROC)NULL;
    void* p = (void*)GOpenGLCallbacks_WGL.GetProcAddress(lpProcName);

    // 2) check if the procedure address is valid
    if (p == 0 || (p == (void*)1) || (p == (void*)2) || (p == (void*)3) || (p == (void*)-1))
    {
        // 2.a) use library handle to get the address instead
        if (!GOpenGLLibrary_WGL) return (PROC)NULL;
        return (PROC)GetProcAddress(GOpenGLLibrary_WGL, lpProcName);
    }

    return (PROC)p;
}
// ---------------------------------------------------------------------------------------------- //