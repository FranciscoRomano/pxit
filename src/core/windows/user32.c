// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_NAME user32
#define LIBRARY_HINT "user32.dll"
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

DEFINE_LIBRARY(
    REQUIRED_SYMBOL(AdjustWindowRect)
    REQUIRED_SYMBOL(ClientToScreen)
    REQUIRED_SYMBOL(CloseWindow)
    REQUIRED_SYMBOL(CreateWindowExA)
    REQUIRED_SYMBOL(DefWindowProcA)
    REQUIRED_SYMBOL(DestroyWindow)
    REQUIRED_SYMBOL(DispatchMessageA)
    REQUIRED_SYMBOL(GetCursorPos)
    REQUIRED_SYMBOL(GetDC)
    REQUIRED_SYMBOL(GetWindowLongPtrA)
    REQUIRED_SYMBOL(LoadCursorA)
    REQUIRED_SYMBOL(LoadIconA)
    REQUIRED_SYMBOL(MoveWindow)
    REQUIRED_SYMBOL(PeekMessageA)
    REQUIRED_SYMBOL(PostQuitMessage)
    REQUIRED_SYMBOL(RegisterClassExA)
    REQUIRED_SYMBOL(ReleaseCapture)
    REQUIRED_SYMBOL(ReleaseDC)
    REQUIRED_SYMBOL(ScreenToClient)
    REQUIRED_SYMBOL(SetCapture)
    REQUIRED_SYMBOL(SetFocus)
    REQUIRED_SYMBOL(SetLayeredWindowAttributes)
    OPTIONAL_SYMBOL(SetProcessDPIAware)
    OPTIONAL_SYMBOL(SetProcessDpiAwareness)
    OPTIONAL_SYMBOL(SetProcessDpiAwarenessContext)
    REQUIRED_SYMBOL(SetWindowLongPtrA)
    REQUIRED_SYMBOL(SetWindowPos)
    REQUIRED_SYMBOL(ShowWindow)
    REQUIRED_SYMBOL(TranslateMessage)
    REQUIRED_SYMBOL(UnregisterClassA)
    REQUIRED_SYMBOL(UpdateLayeredWindow)
)

// -------------------------------------------------------------------------------------------------------------------------- //