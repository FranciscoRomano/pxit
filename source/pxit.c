// The MIT License (MIT)
// 
// Copyright (c) 2023 Francisco Romano
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

#include <pxit.h>
#include <windows.h>
#include <stdio.h>
#include <stdatomic.h>

const int CK_ALT_GROUP   = LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED;
const int VK_ALT_GROUP   = VK_MENU | VK_LMENU | VK_RMENU;
const int CK_CAPS_GROUP  = CAPSLOCK_ON;
const int VK_CAPS_GROUP  = VK_CAPITAL;
const int CK_CTRL_GROUP  = LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED;
const int VK_CTRL_GROUP  = VK_CONTROL | VK_LCONTROL | VK_RCONTROL;
const int CK_SHIFT_GROUP = SHIFT_PRESSED;
const int VK_SHIFT_GROUP = VK_SHIFT | VK_LSHIFT | VK_RSHIFT;

static HANDLE              PXIT_WIN32_STDIN;       // std win32 input handle
static HANDLE              PXIT_WIN32_STDOUT;      // std win32 output handle
static HWND                PXIT_WIN32_HWND;        // the win32 console window
static INPUT_RECORD        PXIT_WIN32_EVENTS[256]; // the win32 event/input records
static const int           PXIT_WIN32_EVENTS_LENGTH = sizeof(PXIT_WIN32_EVENTS) / sizeof(INPUT_RECORD);

static WORD                PXIT_KEYMAP[256] = {};  // the mouse & keyboard mapped values
static const int           PXIT_KEYMAP_LENGTH = sizeof(PXIT_KEYMAP) / sizeof(WORD);
static atomic_bool         PXIT_IS_RUNNING = 0;    // is the application currently running
static atomic_bool         PXIT_IS_CLOSING = 0;    // is the application currently closing
static PxitInitFunctionPtr PXIT_CALLBACK_INIT;     // the application's 'init' function pointer
static PxitQuitFunctionPtr PXIT_CALLBACK_QUIT;     // the application's 'quit' function pointer
static PxitTickFunctionPtr PXIT_CALLBACK_TICK;     // the application's 'tick' function pointer

void PXIT_KEY_INPUT(KEY_EVENT_RECORD* e)
{
    // get key event record data
    int vkd = e->bKeyDown;
    int vkc = e->wVirtualKeyCode;
    int cks = e->dwControlKeyState;
    
    // set the virtual key to array
    PXIT_KEYMAP[vkc] = vkd;
    PXIT_KEYMAP[PxitKey_ALT]   = (vkc & VK_ALT_GROUP   ? vkd : FALSE) | (WORD)(cks & CK_ALT_GROUP);
    PXIT_KEYMAP[PxitKey_CAPS]  = (vkc & VK_CAPS_GROUP  ? vkd : FALSE) | (WORD)(cks & CK_CAPS_GROUP);
    PXIT_KEYMAP[PxitKey_CTRL]  = (vkc & VK_CTRL_GROUP  ? vkd : FALSE) | (WORD)(cks & CK_CTRL_GROUP);
    PXIT_KEYMAP[PxitKey_SHIFT] = (vkc & VK_SHIFT_GROUP ? vkd : FALSE) | (WORD)(cks & CK_SHIFT_GROUP);
}

void PXIT_MOUSE_INPUT(MOUSE_EVENT_RECORD* e)
{
    // get mouse event record data
    int vbs = e->dwButtonState;
    int cks = e->dwControlKeyState;
    
    // set the virtual key to array
    PXIT_KEYMAP[PxitKey_MOUSE_L] = (vbs & 0x1);
    PXIT_KEYMAP[PxitKey_MOUSE_M] = (vbs & 0x4);
    PXIT_KEYMAP[PxitKey_MOUSE_R] = (vbs & 0x8);
    PXIT_KEYMAP[PxitKey_ALT]     = (cks & CK_ALT_GROUP);
    PXIT_KEYMAP[PxitKey_CAPS]    = (cks & CK_CAPS_GROUP);
    PXIT_KEYMAP[PxitKey_CTRL]    = (cks & CK_CTRL_GROUP);
    PXIT_KEYMAP[PxitKey_SHIFT]   = (cks & CK_SHIFT_GROUP);
}

static BOOL PXIT_CTRL_HANDLER(DWORD ctrl_type)
{
    // check for force close application
    // if (ctrl_type == CTRL_CLOSE_EVENT) return TRUE;
    // if (ctrl_type == CTRL_LOGOFF_EVENT) return TRUE;
    // if (ctrl_type == CTRL_SHUTDOWN_EVENT) return TRUE;
    
    // flag console as closing (we must exit)
    PXIT_IS_CLOSING = TRUE;
    while (PXIT_IS_RUNNING) Sleep(1);
    
    // return 'TRUE' once console process is done
    return TRUE;
}

int pxitApplicationEntryPoint(const PxitApplicationCreateInfo* info, int argc, char** argv)
{
    // check if initialised
    if (PXIT_IS_RUNNING) return FALSE;
    if (PXIT_IS_CLOSING) return FALSE;
    
    // allocate win32 console
    if (AllocConsole())
    {
        FILE* f;
        DWORD f_attrs = FILE_ATTRIBUTE_NORMAL;
        DWORD f_share = FILE_SHARE_READ | FILE_SHARE_WRITE;
        DWORD f_create = OPEN_EXISTING;
        DWORD f_access = GENERIC_READ | GENERIC_WRITE;
        
        freopen_s(&f, "CONOUT$", "w", stdout);
        freopen_s(&f, "CONOUT$", "w", stderr);
        freopen_s(&f, "CONIN$",  "r", stdin);
        
        HANDLE conin = CreateFileA("CONIN$", f_access, f_share, NULL, f_create, f_attrs, NULL);
        SetStdHandle(STD_INPUT_HANDLE, conin);
        
        HANDLE conout = CreateFileA("CONOUT$", f_access, f_share, NULL, f_create, f_attrs, NULL);
        SetStdHandle(STD_ERROR_HANDLE, conout);
        SetStdHandle(STD_OUTPUT_HANDLE, conout);
    }
    
    // set IO & window handles
    PXIT_WIN32_STDIN  = GetStdHandle(STD_INPUT_HANDLE);
    PXIT_WIN32_STDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
    PXIT_WIN32_HWND   = GetConsoleWindow();
    PXIT_CALLBACK_INIT = info->OnInit;
    PXIT_CALLBACK_QUIT = info->OnQuit;
    PXIT_CALLBACK_TICK = info->OnTick;
    
    // set console CTRL handler
    SetConsoleCtrlHandler(PXIT_CTRL_HANDLER, TRUE);
    
    // invoke library event "OnInit"
    PXIT_IS_CLOSING = FALSE;
    PXIT_IS_RUNNING = TRUE;
    PXIT_CALLBACK_INIT(argc, argv);
    
    // check if console is still running
    while (!PXIT_IS_CLOSING)
    {
        DWORD length = 0;
        if (PeekConsoleInputA(PXIT_WIN32_STDIN, PXIT_WIN32_EVENTS, 1, &length) && length)
        {
            // read all queued console inputs
            ReadConsoleInputA(PXIT_WIN32_STDIN, PXIT_WIN32_EVENTS, PXIT_WIN32_EVENTS_LENGTH, &length);
            
            // switch through each event type
            for (DWORD i = 0; i < length; i++)
            {
                switch (PXIT_WIN32_EVENTS[i].EventType)
                {
                case KEY_EVENT:
                    PXIT_KEY_INPUT(&PXIT_WIN32_EVENTS[i].Event.KeyEvent);
                    break;
                case MOUSE_EVENT:
                    PXIT_MOUSE_INPUT(&PXIT_WIN32_EVENTS[i].Event.MouseEvent);
                    break;
                default:
                    break;
                }
            }
        }
        
        // invoke library event "OnTick"
        PXIT_CALLBACK_TICK(0, 0);
        Sleep(0);
    }
    
    // release allocated win32 console
    PXIT_CALLBACK_QUIT();
    PXIT_IS_RUNNING = FALSE;
    return TRUE;
}

int pxitCloseApplication()
{
    // generate a CTRL + C close event
    if (!PXIT_IS_RUNNING) return FALSE;
    return GenerateConsoleCtrlEvent(CTRL_C_EVENT, 0);
}

int pxitGetKeyValue(PxitKey key)
{
    // return the mapped input value from key
    if (key < 0) return FALSE;
    if (key >= 256) return FALSE;
    return PXIT_KEYMAP[key];
}