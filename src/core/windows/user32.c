// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "user32.h"
#include "kernel32.h"
#include <stdio.h>
#include <stdlib.h>
#define LOAD_OPTIONAL_SYMBOL(Name)\
_user32.Name = (void*)GetProcAddress(_user32.dll, #Name);\
if (!_user32.Name) { printf("WARNING: failed to load symbol '" #Name "'\n"); }
#define LOAD_REQUIRED_SYMBOL(Name)\
_user32.Name = (void*)GetProcAddress(_user32.dll, #Name);\
if (!_user32.Name) { printf("ERROR: failed to load symbol '" #Name "'\n"); return false; }
// -------------------------------------------------------------------------------------------------------------------------- //

struct _user32_dll _user32 = { NULL };

bool _free_user32_dll()
{
    // check if library was unloaded
    if (!_user32.dll) return false;

    // unload and reset library handle
    FreeLibrary(_user32.dll);
    _user32.dll = NULL;
    return true;
}

bool _load_user32_dll()
{
    // check if library was loaded
    if (_user32.dll) return true;

    // iterate through all library paths
    const char* paths[] = { "user32.dll", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        _user32.dll = LoadLibraryA(paths[i]);
        if (_user32.dll == NULL) continue;
        LOAD_REQUIRED_SYMBOL(AdjustWindowRect)
        LOAD_REQUIRED_SYMBOL(ClientToScreen)
        LOAD_REQUIRED_SYMBOL(CloseWindow)
        LOAD_REQUIRED_SYMBOL(CreateWindowExA)
        LOAD_REQUIRED_SYMBOL(DefWindowProcA)
        LOAD_REQUIRED_SYMBOL(DestroyWindow)
        LOAD_REQUIRED_SYMBOL(DispatchMessageA)
        LOAD_REQUIRED_SYMBOL(GetCursorPos)
        LOAD_REQUIRED_SYMBOL(GetDC)
        LOAD_REQUIRED_SYMBOL(GetWindowLongPtrA)
        LOAD_REQUIRED_SYMBOL(LoadCursorA)
        LOAD_REQUIRED_SYMBOL(LoadIconA)
        LOAD_REQUIRED_SYMBOL(MoveWindow)
        LOAD_REQUIRED_SYMBOL(PeekMessageA)
        LOAD_REQUIRED_SYMBOL(PostQuitMessage)
        LOAD_REQUIRED_SYMBOL(RegisterClassExA)
        LOAD_REQUIRED_SYMBOL(ReleaseCapture)
        LOAD_REQUIRED_SYMBOL(ReleaseDC)
        LOAD_REQUIRED_SYMBOL(ScreenToClient)
        LOAD_REQUIRED_SYMBOL(SetCapture)
        LOAD_REQUIRED_SYMBOL(SetLayeredWindowAttributes)
        LOAD_OPTIONAL_SYMBOL(SetProcessDPIAware)
        LOAD_OPTIONAL_SYMBOL(SetProcessDpiAwareness)
        LOAD_OPTIONAL_SYMBOL(SetProcessDpiAwarenessContext)
        LOAD_REQUIRED_SYMBOL(SetWindowLongPtrA)
        LOAD_REQUIRED_SYMBOL(SetWindowPos)
        LOAD_REQUIRED_SYMBOL(TranslateMessage)
        LOAD_REQUIRED_SYMBOL(UnregisterClassA)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //