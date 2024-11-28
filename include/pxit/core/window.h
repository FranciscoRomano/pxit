// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#pragma once
#include <stdint.h>

typedef struct WindowCallbacks {
    void (*OnKeyDown)(uint32_t);
    void (*OnKeyUp)(uint32_t);
    void (*OnMouseDown)(uint32_t);
    void (*OnMouseEnter)(uint32_t, uint32_t);
    void (*OnMouseLeave)(uint32_t, uint32_t);
    void (*OnMouseMove)(uint32_t, uint32_t);
    void (*OnMouseUp)(uint32_t);
    void (*OnWindowClose)();
    void (*OnWindowCreate)();
    void (*OnWindowFocus)(bool);
    void (*OnWindowFullscreen)(uint32_t, uint32_t);
    void (*OnWindowHide)();
    void (*OnWindowMaximize)(uint32_t, uint32_t);
    void (*OnWindowMinimize)();
    void (*OnWindowMove)(uint32_t, uint32_t);
    void (*OnWindowRestore)(uint32_t, uint32_t);
    void (*OnWindowShow)();
    void (*OnWindowSize)(uint32_t, uint32_t);
} WindowCallbacks;

// -------------------------------------------------------------------------------------------------------------------------- //