// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_windows_user32_h__
#define __core_windows_user32_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>
#include <stdbool.h>

#define COLOR_3DDKSHADOW              21
#define COLOR_3DFACE                  15
#define COLOR_3DHIGHLIGHT             20
#define COLOR_3DHILIGHT               20
#define COLOR_3DLIGHT                 22
#define COLOR_3DSHADOW                16
#define COLOR_ACTIVEBORDER            10
#define COLOR_ACTIVECAPTION           2
#define COLOR_APPWORKSPACE            12
#define COLOR_BACKGROUND              1
#define COLOR_BTNFACE                 15
#define COLOR_BTNHIGHLIGHT            20
#define COLOR_BTNHILIGHT              20
#define COLOR_BTNSHADOW               16
#define COLOR_BTNTEXT                 18
#define COLOR_CAPTIONTEXT             9
#define COLOR_DESKTOP                 1
#define COLOR_GRADIENTACTIVECAPTION   27
#define COLOR_GRADIENTINACTIVECAPTION 28
#define COLOR_GRAYTEXT                17
#define COLOR_HIGHLIGHT               13
#define COLOR_HIGHLIGHTTEXT           14
#define COLOR_HOTLIGHT                26
#define COLOR_INACTIVEBORDER          11
#define COLOR_INACTIVECAPTION         3
#define COLOR_INACTIVECAPTIONTEXT     19
#define COLOR_INFOBK                  24
#define COLOR_INFOTEXT                23
#define COLOR_MENU                    4
#define COLOR_MENUBAR                 30
#define COLOR_MENUHILIGHT             29
#define COLOR_MENUTEXT                7
#define COLOR_SCROLLBAR               0
#define COLOR_WINDOW                  5
#define COLOR_WINDOWFRAME             6
#define COLOR_WINDOWTEXT              8
#define CS_BYTEALIGNCLIENT            0x1000
#define CS_BYTEALIGNWINDOW            0x2000
#define CS_CLASSDC                    0x0040
#define CS_DBLCLKS                    0x0008
#define CS_DROPSHADOW                 0x00020000
#define CS_GLOBALCLASS                0x4000
#define CS_HREDRAW                    0x0002
#define CS_IME                        0x00010000
#define CS_NOCLOSE                    0x0200
#define CS_OWNDC                      0x0020
#define CS_PARENTDC                   0x0080
#define CS_SAVEBITS                   0x0800
#define CS_VREDRAW                    0x0001
#define IDC_APPSTARTING               ((LPSTR)((ULONG_PTR)((WORD)(32650))))
#define IDC_ARROW                     ((LPSTR)((ULONG_PTR)((WORD)(32512))))
#define IDC_CROSS                     ((LPSTR)((ULONG_PTR)((WORD)(32515))))
#define IDC_HAND                      ((LPSTR)((ULONG_PTR)((WORD)(32649))))
#define IDC_HELP                      ((LPSTR)((ULONG_PTR)((WORD)(32651))))
#define IDC_IBEAM                     ((LPSTR)((ULONG_PTR)((WORD)(32513))))
#define IDC_ICON                      ((LPSTR)((ULONG_PTR)((WORD)(32641))))
#define IDC_NO                        ((LPSTR)((ULONG_PTR)((WORD)(32648))))
#define IDC_PERSON                    ((LPSTR)((ULONG_PTR)((WORD)(32672))))
#define IDC_PIN                       ((LPSTR)((ULONG_PTR)((WORD)(32671))))
#define IDC_SIZE                      ((LPSTR)((ULONG_PTR)((WORD)(32640))))
#define IDC_SIZEALL                   ((LPSTR)((ULONG_PTR)((WORD)(32646))))
#define IDC_SIZENESW                  ((LPSTR)((ULONG_PTR)((WORD)(32643))))
#define IDC_SIZENS                    ((LPSTR)((ULONG_PTR)((WORD)(32645))))
#define IDC_SIZENWSE                  ((LPSTR)((ULONG_PTR)((WORD)(32642))))
#define IDC_SIZEWE                    ((LPSTR)((ULONG_PTR)((WORD)(32644))))
#define IDC_UPARROW                   ((LPSTR)((ULONG_PTR)((WORD)(32516))))
#define IDC_WAIT                      ((LPSTR)((ULONG_PTR)((WORD)(32514))))
#define IDI_APPLICATION               ((LPSTR)((ULONG_PTR)((WORD)(32512))))
#define IDI_ASTERISK                  ((LPSTR)((ULONG_PTR)((WORD)(32516))))
#define IDI_ERROR                     ((LPSTR)((ULONG_PTR)((WORD)(32513))))
#define IDI_EXCLAMATION               ((LPSTR)((ULONG_PTR)((WORD)(32515))))
#define IDI_HAND                      ((LPSTR)((ULONG_PTR)((WORD)(32513))))
#define IDI_INFORMATION               ((LPSTR)((ULONG_PTR)((WORD)(32516))))
#define IDI_QUESTION                  ((LPSTR)((ULONG_PTR)((WORD)(32514))))
#define IDI_WARNING                   ((LPSTR)((ULONG_PTR)((WORD)(32515))))
#define IDI_WINLOGO                   ((LPSTR)((ULONG_PTR)((WORD)(32517))))
#define PM_NOREMOVE                   0x0000
#define PM_NOYIELD                    0x0002
#define PM_REMOVE                     0x0001
#define WM_ACTIVATE                   0x0006
#define WM_ACTIVATEAPP                0x001C
#define WM_AFXFIRST                   0x0360
#define WM_AFXLAST                    0x037F
#define WM_APP                        0x8000
#define WM_APPCOMMAND                 0x0319
#define WM_ASKCBFORMATNAME            0x030C
#define WM_CANCELJOURNAL              0x004B
#define WM_CANCELMODE                 0x001F
#define WM_CAPTURECHANGED             0x0215
#define WM_CHANGECBCHAIN              0x030D
#define WM_CHANGEUISTATE              0x0127
#define WM_CHAR                       0x0102
#define WM_CHARTOITEM                 0x002F
#define WM_CHILDACTIVATE              0x0022
#define WM_CLEAR                      0x0303
#define WM_CLOSE                      0x0010
#define WM_COMMAND                    0x0111
#define WM_COMMNOTIFY                 0x0044
#define WM_COMPACTING                 0x0041
#define WM_COMPAREITEM                0x0039
#define WM_CONTEXTMENU                0x007B
#define WM_COPY                       0x0301
#define WM_COPYDATA                   0x004A
#define WM_CREATE                     0x0001
#define WM_CTLCOLORBTN                0x0135
#define WM_CTLCOLORDLG                0x0136
#define WM_CTLCOLOREDIT               0x0133
#define WM_CTLCOLORLISTBOX            0x0134
#define WM_CTLCOLORMSGBOX             0x0132
#define WM_CTLCOLORSCROLLBAR          0x0137
#define WM_CTLCOLORSTATIC             0x0138
#define WM_CUT                        0x0300
#define WM_DEADCHAR                   0x0103
#define WM_DELETEITEM                 0x002D
#define WM_DESTROY                    0x0002
#define WM_DESTROYCLIPBOARD           0x0307
#define WM_DEVICECHANGE               0x0219
#define WM_DEVMODECHANGE              0x001B
#define WM_DISPLAYCHANGE              0x007E
#define WM_DRAWCLIPBOARD              0x0308
#define WM_DRAWITEM                   0x002B
#define WM_DROPFILES                  0x0233
#define WM_ENABLE                     0x000A
#define WM_ENDSESSION                 0x0016
#define WM_ENTERIDLE                  0x0121
#define WM_ENTERMENULOOP              0x0211
#define WM_ENTERSIZEMOVE              0x0231
#define WM_ERASEBKGND                 0x0014
#define WM_EXITMENULOOP               0x0212
#define WM_EXITSIZEMOVE               0x0232
#define WM_FONTCHANGE                 0x001D
#define WM_GETDLGCODE                 0x0087
#define WM_GETFONT                    0x0031
#define WM_GETHOTKEY                  0x0033
#define WM_GETICON                    0x007F
#define WM_GETMINMAXINFO              0x0024
#define WM_GETOBJECT                  0x003D
#define WM_GETTEXT                    0x000D
#define WM_GETTEXTLENGTH              0x000E
#define WM_HANDHELDFIRST              0x0358
#define WM_HANDHELDLAST               0x035F
#define WM_HELP                       0x0053
#define WM_HOTKEY                     0x0312
#define WM_HSCROLL                    0x0114
#define WM_HSCROLLCLIPBOARD           0x030E
#define WM_ICONERASEBKGND             0x0027
#define WM_IME_CHAR                   0x0286
#define WM_IME_COMPOSITION            0x010F
#define WM_IME_COMPOSITIONFULL        0x0284
#define WM_IME_CONTROL                0x0283
#define WM_IME_ENDCOMPOSITION         0x010E
#define WM_IME_KEYDOWN                0x0290
#define WM_IME_KEYLAST                0x010F
#define WM_IME_KEYUP                  0x0291
#define WM_IME_NOTIFY                 0x0282
#define WM_IME_REQUEST                0x0288
#define WM_IME_SELECT                 0x0285
#define WM_IME_SETCONTEXT             0x0281
#define WM_IME_STARTCOMPOSITION       0x010D
#define WM_INITDIALOG                 0x0110
#define WM_INITMENU                   0x0116
#define WM_INITMENUPOPUP              0x0117
#define WM_INPUT                      0x00FF
#define WM_INPUTLANGCHANGE            0x0051
#define WM_INPUTLANGCHANGEREQUEST     0x0050
#define WM_KEYDOWN                    0x0100
#define WM_KEYFIRST                   0x0100
#define WM_KEYLAST                    0x0109
#define WM_KEYUP                      0x0101
#define WM_KILLFOCUS                  0x0008
#define WM_LBUTTONDBLCLK              0x0203
#define WM_LBUTTONDOWN                0x0201
#define WM_LBUTTONUP                  0x0202
#define WM_MBUTTONDBLCLK              0x0209
#define WM_MBUTTONDOWN                0x0207
#define WM_MBUTTONUP                  0x0208
#define WM_MDIACTIVATE                0x0222
#define WM_MDICASCADE                 0x0227
#define WM_MDICREATE                  0x0220
#define WM_MDIDESTROY                 0x0221
#define WM_MDIGETACTIVE               0x0229
#define WM_MDIICONARRANGE             0x0228
#define WM_MDIMAXIMIZE                0x0225
#define WM_MDINEXT                    0x0224
#define WM_MDIREFRESHMENU             0x0234
#define WM_MDIRESTORE                 0x0223
#define WM_MDISETMENU                 0x0230
#define WM_MDITILE                    0x0226
#define WM_MEASUREITEM                0x002C
#define WM_MENUCHAR                   0x0120
#define WM_MENUCOMMAND                0x0126
#define WM_MENUDRAG                   0x0123
#define WM_MENUGETOBJECT              0x0124
#define WM_MENURBUTTONUP              0x0122
#define WM_MENUSELECT                 0x011F
#define WM_MOUSEACTIVATE              0x0021
#define WM_MOUSEFIRST                 0x0200
#define WM_MOUSEHOVER                 0x02A1
#define WM_MOUSELAST                  0x020D
#define WM_MOUSELEAVE                 0x02A3
#define WM_MOUSEMOVE                  0x0200
#define WM_MOUSEWHEEL                 0x020A
#define WM_MOVE                       0x0003
#define WM_MOVING                     0x0216
#define WM_NCACTIVATE                 0x0086
#define WM_NCCALCSIZE                 0x0083
#define WM_NCCREATE                   0x0081
#define WM_NCDESTROY                  0x0082
#define WM_NCHITTEST                  0x0084
#define WM_NCLBUTTONDBLCLK            0x00A3
#define WM_NCLBUTTONDOWN              0x00A1
#define WM_NCLBUTTONUP                0x00A2
#define WM_NCMBUTTONDBLCLK            0x00A9
#define WM_NCMBUTTONDOWN              0x00A7
#define WM_NCMBUTTONUP                0x00A8
#define WM_NCMOUSEHOVER               0x02A0
#define WM_NCMOUSELEAVE               0x02A2
#define WM_NCMOUSEMOVE                0x00A0
#define WM_NCPAINT                    0x0085
#define WM_NCRBUTTONDBLCLK            0x00A6
#define WM_NCRBUTTONDOWN              0x00A4
#define WM_NCRBUTTONUP                0x00A5
#define WM_NCXBUTTONDBLCLK            0x00AD
#define WM_NCXBUTTONDOWN              0x00AB
#define WM_NCXBUTTONUP                0x00AC
#define WM_NEXTDLGCTL                 0x0028
#define WM_NEXTMENU                   0x0213
#define WM_NOTIFY                     0x004E
#define WM_NOTIFYFORMAT               0x0055
#define WM_NULL                       0x0000
#define WM_PAINT                      0x000F
#define WM_PAINTCLIPBOARD             0x0309
#define WM_PAINTICON                  0x0026
#define WM_PALETTECHANGED             0x0311
#define WM_PALETTEISCHANGING          0x0310
#define WM_PARENTNOTIFY               0x0210
#define WM_PASTE                      0x0302
#define WM_PENWINFIRST                0x0380
#define WM_PENWINLAST                 0x038F
#define WM_POWER                      0x0048
#define WM_POWERBROADCAST             0x0218
#define WM_PRINT                      0x0317
#define WM_PRINTCLIENT                0x0318
#define WM_QUERYDRAGICON              0x0037
#define WM_QUERYENDSESSION            0x0011
#define WM_QUERYNEWPALETTE            0x030F
#define WM_QUERYOPEN                  0x0013
#define WM_QUERYUISTATE               0x0129
#define WM_QUEUESYNC                  0x0023
#define WM_QUIT                       0x0012
#define WM_RBUTTONDBLCLK              0x0206
#define WM_RBUTTONDOWN                0x0204
#define WM_RBUTTONUP                  0x0205
#define WM_RENDERALLFORMATS           0x0306
#define WM_RENDERFORMAT               0x0305
#define WM_SETCURSOR                  0x0020
#define WM_SETFOCUS                   0x0007
#define WM_SETFONT                    0x0030
#define WM_SETHOTKEY                  0x0032
#define WM_SETICON                    0x0080
#define WM_SETREDRAW                  0x000B
#define WM_SETTEXT                    0x000C
#define WM_SETTINGCHANGE              0x001A
#define WM_SHOWWINDOW                 0x0018
#define WM_SIZE                       0x0005
#define WM_SIZECLIPBOARD              0x030B
#define WM_SIZING                     0x0214
#define WM_SPOOLERSTATUS              0x002A
#define WM_STYLECHANGED               0x007D
#define WM_STYLECHANGING              0x007C
#define WM_SYNCPAINT                  0x0088
#define WM_SYSCHAR                    0x0106
#define WM_SYSCOLORCHANGE             0x0015
#define WM_SYSCOMMAND                 0x0112
#define WM_SYSDEADCHAR                0x0107
#define WM_SYSKEYDOWN                 0x0104
#define WM_SYSKEYUP                   0x0105
#define WM_TABLET_FIRST               0x02c0
#define WM_TABLET_LAST                0x02df
#define WM_TCARD                      0x0052
#define WM_THEMECHANGED               0x031A
#define WM_TIMECHANGE                 0x001E
#define WM_TIMER                      0x0113
#define WM_UNDO                       0x0304
#define WM_UNICHAR                    0x0109
#define WM_UNINITMENUPOPUP            0x0125
#define WM_UPDATEUISTATE              0x0128
#define WM_USER                       0x0400
#define WM_USERCHANGED                0x0054
#define WM_VKEYTOITEM                 0x002E
#define WM_VSCROLL                    0x0115
#define WM_VSCROLLCLIPBOARD           0x030A
#define WM_WINDOWPOSCHANGED           0x0047
#define WM_WINDOWPOSCHANGING          0x0046
#define WM_WININICHANGE               0x001A
#define WM_WTSSESSION_CHANGE          0x02B1
#define WM_XBUTTONDBLCLK              0x020D
#define WM_XBUTTONDOWN                0x020B
#define WM_XBUTTONUP                  0x020C
#define WS_BORDER                     0x00800000L
#define WS_CAPTION                    0x00C00000L
#define WS_CHILD                      0x40000000L
#define WS_CHILDWINDOW                0x40000000L
#define WS_CLIPCHILDREN               0x02000000L
#define WS_CLIPSIBLINGS               0x04000000L
#define WS_DISABLED                   0x08000000L
#define WS_DLGFRAME                   0x00400000L
#define WS_EX_ACCEPTFILES             0x00000010L
#define WS_EX_APPWINDOW               0x00040000L
#define WS_EX_CLIENTEDGE              0x00000200L
#define WS_EX_COMPOSITED              0x02000000L
#define WS_EX_CONTEXTHELP             0x00000400L
#define WS_EX_CONTROLPARENT           0x00010000L
#define WS_EX_DLGMODALFRAME           0x00000001L
#define WS_EX_LAYERED                 0x00080000L
#define WS_EX_LAYOUTRTL               0x00400000L
#define WS_EX_LEFT                    0x00000000L
#define WS_EX_LEFTSCROLLBAR           0x00004000L
#define WS_EX_LTRREADING              0x00000000L
#define WS_EX_MDICHILD                0x00000040L
#define WS_EX_NOACTIVATE              0x08000000L
#define WS_EX_NOINHERITLAYOUT         0x00100000L
#define WS_EX_NOPARENTNOTIFY          0x00000004L
#define WS_EX_OVERLAPPEDWINDOW        0x00000300L
#define WS_EX_PALETTEWINDOW           0x00000188L
#define WS_EX_RIGHT                   0x00001000L
#define WS_EX_RIGHTSCROLLBAR          0x00000000L
#define WS_EX_RTLREADING              0x00002000L
#define WS_EX_STATICEDGE              0x00020000L
#define WS_EX_TOOLWINDOW              0x00000080L
#define WS_EX_TOPMOST                 0x00000008L
#define WS_EX_TRANSPARENT             0x00000020L
#define WS_EX_WINDOWEDGE              0x00000100L
#define WS_GROUP                      0x00020000L
#define WS_HSCROLL                    0x00100000L
#define WS_ICONIC                     0x20000000L
#define WS_MAXIMIZE                   0x01000000L
#define WS_MAXIMIZEBOX                0x00010000L
#define WS_MINIMIZE                   0x20000000L
#define WS_MINIMIZEBOX                0x00020000L
#define WS_OVERLAPPED                 0x00000000L
#define WS_OVERLAPPEDWINDOW           0x00CF0000L
#define WS_POPUP                      0x80000000L
#define WS_POPUPWINDOW                0x80880000L
#define WS_SIZEBOX                    0x00040000L
#define WS_SYSMENU                    0x00080000L
#define WS_TABSTOP                    0x00010000L
#define WS_THICKFRAME                 0x00040000L
#define WS_TILED                      0x00000000L
#define WS_TILEDWINDOW                0x00CF0000L
#define WS_VISIBLE                    0x10000000L
#define WS_VSCROLL                    0x00200000L

// [Windows] Message
typedef struct {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
} MSG;

// [Windows] Window procedure
typedef LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);

// [Windows] Window class extended
typedef struct {
    UINT      cbSize;
    UINT      style;
    WNDPROC   lpfnWndProc;
    int       cbClsExtra;
    int       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCSTR    lpszMenuName;
    LPCSTR    lpszClassName;
    HICON     hIconSm;
} WNDCLASSEXA;

// [Windows] Create structure (ASCII)
typedef struct {
    LPVOID    lpCreateParams;
    HINSTANCE hInstance;
    HMENU     hMenu;
    HWND      hwndParent;
    int       cy;
    int       cx;
    int       y;
    int       x;
    LONG      style;
    LPCSTR    lpszName;
    LPCSTR    lpszClass;
    DWORD     dwExStyle;
} CREATESTRUCTA;

/// @brief Represents the "user32.dll" library and supported functions.
extern struct _user32_dll {
    void* dll;
    BOOL     WINAPI (*AdjustWindowRect)(LPRECT,DWORD,BOOL);
    BOOL     WINAPI (*CloseWindow)(HWND);
    HWND     WINAPI (*CreateWindowExA)(DWORD,LPCSTR,LPCSTR,DWORD,int,int,int,int,HWND,HMENU,HINSTANCE,LPVOID);
    LRESULT  WINAPI (*DefWindowProcA)(HWND,UINT,WPARAM,LPARAM);
    WINBOOL  WINAPI (*DestroyWindow)(HWND);
    LRESULT  WINAPI (*DispatchMessageA)(CONST MSG*);
    HDC      WINAPI (*GetDC)(HWND);
    LONG_PTR WINAPI (*GetWindowLongPtrA)(HWND,int);
    HCURSOR  WINAPI (*LoadCursorA)(HINSTANCE,LPCSTR);
    HICON    WINAPI (*LoadIconA)(HINSTANCE,LPCSTR);
    BOOL     WINAPI (*PeekMessageA)(MSG*,HWND,UINT,UINT,UINT);
    void     WINAPI (*PostQuitMessage)(int);
    ATOM     WINAPI (*RegisterClassExA)(CONST WNDCLASSEXA*);
    int      WINAPI (*ReleaseDC)(HWND,HDC);
    LONG_PTR WINAPI (*SetWindowLongPtrA)(HWND,int,LONG_PTR);
    BOOL     WINAPI (*TranslateMessage)(CONST MSG*);
    WINBOOL  WINAPI (*UnregisterClassA)(LPCSTR,HINSTANCE);
} _user32;

/// @brief Returns true if the "user32.dll" library was freed successfully.
bool _free_user32_dll();

/// @brief Returns true if the "user32.dll" library was loaded successfully.
bool _load_user32_dll();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_windows_user32_h__
// -------------------------------------------------------------------------------------------------------------------------- //