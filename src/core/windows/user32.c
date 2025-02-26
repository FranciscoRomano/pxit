// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _user32
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _user32_dll _user32 = { NULL };

bool _free_user32_dll()
{
    // check if library was unloaded
    if (!_user32.dll) return true;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
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
        LIBRARY_MODULE_LOAD(paths[i])
        LIBRARY_MODULE_RSYM(AdjustWindowRect)
        LIBRARY_MODULE_RSYM(ClientToScreen)
        LIBRARY_MODULE_RSYM(CloseWindow)
        LIBRARY_MODULE_RSYM(CreateWindowExA)
        LIBRARY_MODULE_RSYM(DefWindowProcA)
        LIBRARY_MODULE_RSYM(DestroyWindow)
        LIBRARY_MODULE_RSYM(DispatchMessageA)
        LIBRARY_MODULE_RSYM(GetCursorPos)
        LIBRARY_MODULE_RSYM(GetDC)
        LIBRARY_MODULE_RSYM(GetWindowLongPtrA)
        LIBRARY_MODULE_RSYM(LoadCursorA)
        LIBRARY_MODULE_RSYM(LoadIconA)
        LIBRARY_MODULE_RSYM(MoveWindow)
        LIBRARY_MODULE_RSYM(PeekMessageA)
        LIBRARY_MODULE_RSYM(PostQuitMessage)
        LIBRARY_MODULE_RSYM(RegisterClassExA)
        LIBRARY_MODULE_RSYM(ReleaseCapture)
        LIBRARY_MODULE_RSYM(ReleaseDC)
        LIBRARY_MODULE_RSYM(ScreenToClient)
        LIBRARY_MODULE_RSYM(SetCapture)
        LIBRARY_MODULE_RSYM(SetFocus)
        LIBRARY_MODULE_RSYM(SetLayeredWindowAttributes)
        LIBRARY_MODULE_OSYM(SetProcessDPIAware)
        LIBRARY_MODULE_OSYM(SetProcessDpiAwareness)
        LIBRARY_MODULE_OSYM(SetProcessDpiAwarenessContext)
        LIBRARY_MODULE_RSYM(SetWindowLongPtrA)
        LIBRARY_MODULE_RSYM(SetWindowPos)
        LIBRARY_MODULE_RSYM(ShowWindow)
        LIBRARY_MODULE_RSYM(TranslateMessage)
        LIBRARY_MODULE_RSYM(UnregisterClassA)
        LIBRARY_MODULE_RSYM(UpdateLayeredWindow)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //