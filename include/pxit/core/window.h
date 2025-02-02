// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __pxit_core_window_h__
#define __pxit_core_window_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdint.h>
#include <stdbool.h>

#define KEY_NONE            0x00
#define KEY_0               0x01
#define KEY_1               0x02
#define KEY_2               0x03
#define KEY_3               0x04
#define KEY_4               0x05
#define KEY_5               0x06
#define KEY_6               0x07
#define KEY_7               0x08
#define KEY_8               0x09
#define KEY_9               0x0A
#define KEY_A               0x0B
#define KEY_APOSTROPHE      0x0C
#define KEY_B               0x0D
#define KEY_BACKSLASH       0x0E
#define KEY_BACKSPACE       0x0F
#define KEY_C               0x10
#define KEY_CAPS_LOCK       0x11
#define KEY_COMMA           0x12
#define KEY_D               0x13
#define KEY_E               0x14
#define KEY_ENTER           0x15
#define KEY_EQUALS          0x16
#define KEY_ESCAPE          0x17
#define KEY_F               0x18
#define KEY_F1              0x19
#define KEY_F10             0x1A
#define KEY_F11             0x1B
#define KEY_F12             0x1C
#define KEY_F2              0x1D
#define KEY_F3              0x1E
#define KEY_F4              0x1F
#define KEY_F5              0x20
#define KEY_F6              0x21
#define KEY_F7              0x22
#define KEY_F8              0x23
#define KEY_F9              0x24
#define KEY_G               0x25
#define KEY_GRAVE_ACCENT    0x26
#define KEY_H               0x27
#define KEY_I               0x28
#define KEY_J               0x29
#define KEY_K               0x2A
#define KEY_L               0x2B
#define KEY_LEFT_ALT        0x2C
#define KEY_LEFT_BRACKET    0x2D
#define KEY_LEFT_CTRL       0x2E
#define KEY_LEFT_SHIFT      0x2F
#define KEY_LEFT_SUPER      0x30
#define KEY_M               0x31
#define KEY_MENU            0x32
#define KEY_MINUS           0x33
#define KEY_N               0x34
#define KEY_O               0x35
#define KEY_P               0x36
#define KEY_PERIOD          0x37
#define KEY_Q               0x38
#define KEY_R               0x39
#define KEY_RIGHT_ALT       0x3A
#define KEY_RIGHT_BRACKET   0x3B
#define KEY_RIGHT_CTRL      0x3C
#define KEY_RIGHT_SHIFT     0x3D
#define KEY_RIGHT_SUPER     0x3E
#define KEY_S               0x3F
#define KEY_SEMICOLON       0x40
#define KEY_SLASH           0x41
#define KEY_SPACE           0x42
#define KEY_T               0x43
#define KEY_TAB             0x44
#define KEY_U               0x45
#define KEY_V               0x46
#define KEY_W               0x47
#define KEY_X               0x48
#define KEY_Y               0x49
#define KEY_Z               0x4A
#define KEY_DELETE          0x4B
#define KEY_DOWN_ARROW      0x4C
#define KEY_END             0x4D
#define KEY_HOME            0x4E
#define KEY_INSERT          0x4F
#define KEY_LEFT_ARROW      0x50
#define KEY_PAGE_DOWN       0x51
#define KEY_PAGE_UP         0x52
#define KEY_PAUSE           0x53
#define KEY_PRINT_SCREEN    0x54
#define KEY_RIGHT_ARROW     0x55
#define KEY_SCROLL_LOCK     0x56
#define KEY_UP_ARROW        0x57
#define KEY_NUMPAD_0        0x58
#define KEY_NUMPAD_1        0x59
#define KEY_NUMPAD_2        0x5A
#define KEY_NUMPAD_3        0x5B
#define KEY_NUMPAD_4        0x5C
#define KEY_NUMPAD_5        0x5D
#define KEY_NUMPAD_6        0x5E
#define KEY_NUMPAD_7        0x5F
#define KEY_NUMPAD_8        0x60
#define KEY_NUMPAD_9        0x61
#define KEY_NUMPAD_ADD      0x62
#define KEY_NUMPAD_DECIMAL  0x63
#define KEY_NUMPAD_DIVIDE   0x64
#define KEY_NUMPAD_ENTER    0x65
#define KEY_NUMPAD_EQUALS   0x66
#define KEY_NUMPAD_MULTIPLY 0x67
#define KEY_NUMPAD_SUBTRACT 0x68
#define KEY_NUM_LOCK        0x69
#define MOUSE_NONE          0x00
#define MOUSE_LEFT          0x01
#define MOUSE_MIDDLE        0x02
#define MOUSE_RIGHT         0x03

/// @brief Represents a native window handle.
typedef struct Window_t* Window;

/// @brief Represents all supported window events.
typedef struct WindowEvents {
    void (*OnCharacter)(Window,char);
    void (*OnKeyDown)(Window,uint32_t);
    void (*OnKeyUp)(Window,uint32_t);
    void (*OnMouseDown)(Window,uint32_t);
    void (*OnMouseEnter)(Window,uint32_t,uint32_t);
    void (*OnMouseLeave)(Window,uint32_t,uint32_t);
    void (*OnMouseMove)(Window,uint32_t,uint32_t);
    void (*OnMouseScroll)(Window,int32_t,int32_t);
    void (*OnMouseUp)(Window,uint32_t);
    void (*OnWindowClose)(Window);
    void (*OnWindowCreate)(Window);
    void (*OnWindowDestroy)(Window);
    void (*OnWindowDraw)(Window);
    void (*OnWindowFocus)(Window,bool);
    void (*OnWindowHide)(Window);
    void (*OnWindowMaximize)(Window);
    void (*OnWindowMinimize)(Window);
    void (*OnWindowMove)(Window,int32_t,int32_t);
    void (*OnWindowRestore)(Window);
    void (*OnWindowShow)(Window);
    void (*OnWindowSize)(Window,uint32_t,uint32_t);
} WindowEvents;

/// @brief Represents the parameters for a new window.
typedef struct WindowCreateInfo {
    int32_t       Left;
    int32_t       Top;
    uint32_t      Width;
    uint32_t      Height;
    const char*   pTitle;
    WindowEvents* pEvents;
} WindowCreateInfo;

bool CloseWindow(Window window);
bool CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow);
bool DestroyWindow(Window window);
bool DrawWindow(Window window);
bool FocusWindow(Window window, bool focus);
bool HideWindow(Window window);
bool MaximizeWindow(Window window);
bool MinimizeWindow(Window window);
bool MoveWindow(Window window, int32_t left, int32_t top);
bool ReadWindowEvents();
bool RestoreWindow(Window window);
bool ShowWindow(Window window);
bool SizeWindow(Window window, uint32_t width, uint32_t height);

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__pxit_core_window_h__
// -------------------------------------------------------------------------------------------------------------------------- //