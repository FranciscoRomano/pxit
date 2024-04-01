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
#ifndef __OpenGL_WGL_h__
#define __OpenGL_WGL_h__
#ifdef __cplusplus
extern "C" {
#endif//__cplusplus
// ---------------------------------------------------------------------------------------------- //
#include <Windows.h>

/// @brief Represents the library for managing OpenGL contexts on the Windows operating system.
typedef struct PxOpenGLCallbacks_WGL {
    BOOL  (WINAPI *CopyContext)(HGLRC,HGLRC,UINT);
    HGLRC (WINAPI *CreateContext)(HDC);
    HGLRC (WINAPI *CreateLayerContext)(HDC,int);
    BOOL  (WINAPI *DeleteContext)(HGLRC);
    BOOL  (WINAPI *DescribeLayerPlane)(HDC,int,int,UINT,LPLAYERPLANEDESCRIPTOR);
    HGLRC (WINAPI *GetCurrentContext)(VOID);
    HDC   (WINAPI *GetCurrentDC)(VOID);
    int   (WINAPI *GetLayerPaletteEntries)(HDC,int,int,int,COLORREF*);
    PROC  (WINAPI *GetProcAddress)(LPCSTR);
    BOOL  (WINAPI *MakeCurrent)(HDC,HGLRC);
    BOOL  (WINAPI *RealizeLayerPalette)(HDC,int,BOOL);
    int   (WINAPI *SetLayerPaletteEntries)(HDC,int,int,int,CONST COLORREF*);
    BOOL  (WINAPI *ShareLists)(HGLRC,HGLRC);
    BOOL  (WINAPI *SwapLayerBuffers)(HDC,UINT);
    DWORD (WINAPI *SwapMultipleBuffers)(UINT,CONST WGLSWAP*);
    BOOL  (WINAPI *UseFontBitmapsA)(HDC,DWORD,DWORD,DWORD);
    BOOL  (WINAPI *UseFontBitmapsW)(HDC,DWORD,DWORD,DWORD);
    BOOL  (WINAPI *UseFontOutlinesA)(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,int,LPGLYPHMETRICSFLOAT);
    BOOL  (WINAPI *UseFontOutlinesW)(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,int,LPGLYPHMETRICSFLOAT);
    BOOL  (WINAPI *ChoosePixelFormatARB)(HDC,const int*,const FLOAT*,UINT,int*,UINT*);
    HGLRC (WINAPI *CreateContextAttribsARB)(HDC,HGLRC,const int*);
    BOOL  (WINAPI *GetPixelFormatAttribivARB)(HDC,int,int,UINT,const int*,int*);
    BOOL  (WINAPI *GetPixelFormatAttribfvARB)(HDC,int,int,UINT,const int*,FLOAT*);
} PxOpenGLCallbacks_WGL;

/// @brief A structure containing all loaded WGL function pointers.
extern PxOpenGLCallbacks_WGL GOpenGLCallbacks_WGL;

/// @brief Returns "TRUE" if the WGL library has been freed/unloaded.
BOOL pxFreeOpenGL_WGL();

/// @brief Returns "TRUE" if the WGL library has been loaded/initialized.
/// @param hInstance     A handle to the application instance.
/// @param lpszClassName A string specifying the window class name.
BOOL pxLoadOpenGL_WGL(HINSTANCE hInstance, LPCSTR lpszClassName);

/// @brief Returns the address of a WGL library procedure from specified name.
/// @param lpProcName A string specifying the WGL procedure name.
PROC pxProcOpenGL_WGL(LPCSTR lpProcName);

// ---------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif//__cplusplus
#endif//__OpenGL_WGL_h__
// ---------------------------------------------------------------------------------------------- //