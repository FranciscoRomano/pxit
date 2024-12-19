// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_library_user32_h__
#define __core_library_user32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windows.h>
#include <stdbool.h>

/// @brief Represents the "user32.dll" library and supported functions.
extern struct _Library_user32 {
    void* dll;
    BOOL     WINAPI (*AdjustWindowRect)(LPRECT,DWORD,BOOL);
    BOOL     WINAPI (*CloseWindow)(HWND hWnd);
    HWND     WINAPI (*CreateWindowExA)(DWORD,LPCSTR,LPCSTR,DWORD,int,int,int,int,HWND,HMENU,HINSTANCE,LPVOID);
    LRESULT  WINAPI (*DefWindowProcA)(HWND,UINT,WPARAM,LPARAM);
    WINBOOL  WINAPI (*DestroyWindow)(HWND);
    HDC      WINAPI (*GetDC)(HWND);
    LONG_PTR WINAPI (*GetWindowLongPtrA)(HWND,int);
    HCURSOR  WINAPI (*LoadCursorA)(HINSTANCE,LPCSTR);
    HICON    WINAPI (*LoadIconA)(HINSTANCE,LPCSTR);
    BOOL     WINAPI (*PeekMessageA)(LPMSG,HWND,UINT,UINT,UINT);
    void     WINAPI (*PostQuitMessage)(int);
    ATOM     WINAPI (*RegisterClassExA)(const WNDCLASSEXA*);
    int      WINAPI (*ReleaseDC)(HWND hWnd,HDC hDC);
    LONG_PTR WINAPI (*SetWindowLongPtrA)(HWND,int,LONG_PTR);
    BOOL     WINAPI (*TranslateMessage)(const MSG*);
    WINBOOL  WINAPI (*UnregisterClassA)(LPCSTR,HINSTANCE);
} _user32;

/// @brief Returns true if the "user32.dll" library was freed successfully.
bool _FreeLibrary_user32();

/// @brief Returns true if the "user32.dll" library was loaded successfully.
bool _LoadLibrary_user32();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_library_user32_h__
// -------------------------------------------------------------------------------------------------------------------------- //