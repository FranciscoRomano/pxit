// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_windows_kernel32_h__
#define __core_windows_kernel32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>

DECLSPEC_IMPORT WINBOOL WINAPI FreeLibrary (HMODULE hLibModule);
DECLSPEC_IMPORT FARPROC WINAPI GetProcAddress (HMODULE hModule, LPCSTR lpProcName);
DECLSPEC_IMPORT HMODULE WINAPI GetModuleHandleA (LPCSTR lpModuleName);
DECLSPEC_IMPORT HMODULE WINAPI GetModuleHandleW (LPCWSTR lpModuleName);
DECLSPEC_IMPORT WINBOOL WINAPI GetModuleHandleExA (DWORD dwFlags, LPCSTR lpModuleName, HMODULE *phModule);
DECLSPEC_IMPORT WINBOOL WINAPI GetModuleHandleExW (DWORD dwFlags, LPCWSTR lpModuleName, HMODULE *phModule);
DECLSPEC_IMPORT HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
DECLSPEC_IMPORT HMODULE WINAPI LoadLibraryExA (LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
DECLSPEC_IMPORT HMODULE WINAPI LoadLibraryExW (LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
DECLSPEC_IMPORT HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
DECLSPEC_IMPORT VOID    WINAPI Sleep (DWORD dwMilliseconds);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_windows_kernel32_h__
// -------------------------------------------------------------------------------------------------------------------------- //