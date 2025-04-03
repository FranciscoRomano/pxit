// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE.                       │
// └───────────────────────────────────────────────────────────────────────────────────────────┘

#ifndef _core_linux_libX11_X_h_
#define _core_linux_libX11_X_h_

#include <stdint.h>

#define Above                       0
#define AllocAll                    1        // allocate entire map writeable
#define AllocNone                   0        // create map with no entries
#define AllowExposures              1
#define AllTemporary                0L       // special Resource ID passed to KillClient
#define AlreadyGrabbed              1
#define Always                      2
#define AnyButton                   0L       // special Button Code, passed to GrabButton
#define AnyKey                      0L       // special Key Code, passed to GrabKey
#define AnyModifier                 (1<<15)  // used in GrabButton, GrabKey
#define AnyPropertyType             0L       // special Atom, passed to GetProperty
#define ArcChord                    0        // join endpoints of arc
#define ArcPieSlice                 1        // join endpoints to center of arc
#define AsyncBoth                   6
#define AsyncKeyboard               3
#define AsyncPointer                0
#define AutoRepeatModeDefault       2
#define AutoRepeatModeOff           0
#define AutoRepeatModeOn            1
#define BadAccess                   10       // depends on context
#define BadAlloc                    11       // insufficient resources
#define BadAtom                     5        // parameter not an Atom
#define BadColor                    12       // no such colormap
#define BadCursor                   6        // parameter not a Cursor
#define BadDrawable                 9        // parameter not a Pixmap or Window
#define BadFont                     7        // parameter not a Font
#define BadGC                       13       // parameter not a GC
#define BadIDChoice                 14       // choice not in range or already used
#define BadImplementation           17       // server is defective
#define BadLength                   16       // Request length incorrect
#define BadMatch                    8        // parameter mismatch
#define BadName                     15       // font or color name doesn't exist
#define BadPixmap                   4        // parameter not a Pixmap
#define BadRequest                  1        // bad request code
#define BadValue                    2        // int parameter out of range
#define BadWindow                   3        // parameter not a Window
#define Below                       1
#define BottomIf                    3
#define Button1                     1
#define Button1Mask                 (1<<8)
#define Button1MotionMask           (1L<<8)
#define Button2                     2
#define Button2Mask                 (1<<9)
#define Button2MotionMask           (1L<<9)
#define Button3                     3
#define Button3Mask                 (1<<10)
#define Button3MotionMask           (1L<<10)
#define Button4                     4
#define Button4Mask                 (1<<11)
#define Button4MotionMask           (1L<<11)
#define Button5                     5
#define Button5Mask                 (1<<12)
#define Button5MotionMask           (1L<<12)
#define ButtonMotionMask            (1L<<13)
#define ButtonPress                 4
#define ButtonPressMask             (1L<<2)
#define ButtonRelease               5
#define ButtonReleaseMask           (1L<<3)
#define CapButt                     1
#define CapNotLast                  0
#define CapProjecting               3
#define CapRound                    2
#define CenterGravity               5
#define CirculateNotify             26
#define CirculateRequest            27
#define ClientMessage               33
#define ClipByChildren              0
#define ColormapChangeMask          (1L<<23)
#define ColormapInstalled           1
#define ColormapNotify              32
#define ColormapUninstalled         0
#define Complex                     0        // paths may intersect
#define ConfigureNotify             22
#define ConfigureRequest            23
#define ControlMapIndex             2
#define ControlMask                 (1<<2)
#define Convex                      2        // wholly convex
#define CoordModeOrigin             0        // relative to the origin
#define CoordModePrevious           1        // relative to previous point
#define CopyFromParent              0L       // border pixmap in CreateWindow and ChangeWindowAttributes special VisualID and special window class passed to CreateWindow
#define CreateNotify                16
#define CurrentTime                 0L       // special Time
#define CursorShape                 0        // largest size that can be displayed
#define CWBackingPixel              (1L<<8)
#define CWBackingPlanes             (1L<<7)
#define CWBackingStore              (1L<<6)
#define CWBackPixel                 (1L<<1)
#define CWBackPixmap                (1L<<0)
#define CWBitGravity                (1L<<4)
#define CWBorderPixel               (1L<<3)
#define CWBorderPixmap              (1L<<2)
#define CWBorderWidth               (1<<4)
#define CWColormap                  (1L<<13)
#define CWCursor                    (1L<<14)
#define CWDontPropagate             (1L<<12)
#define CWEventMask                 (1L<<11)
#define CWHeight                    (1<<3)
#define CWOverrideRedirect          (1L<<9)
#define CWSaveUnder                 (1L<<10)
#define CWSibling                   (1<<5)
#define CWStackMode                 (1<<6)
#define CWWidth                     (1<<2)
#define CWWinGravity                (1L<<5)
#define CWX                         (1<<0)
#define CWY                         (1<<1)
#define DefaultBlanking             2
#define DefaultExposures            2
#define DestroyAll                  0
#define DestroyNotify               17
#define DirectColor                 5
#define DisableAccess               0
#define DisableScreenInterval       0
#define DisableScreenSaver          0
#define DoBlue                      (1<<2)
#define DoGreen                     (1<<1)
#define DontAllowExposures          0
#define DontPreferBlanking          0
#define DoRed                       (1<<0)
#define EastGravity                 6
#define EnableAccess                1
#define EnterNotify                 7
#define EnterWindowMask             (1L<<4)
#define EvenOddRule                 0
#define Expose                      12
#define ExposureMask                (1L<<15)
#define FamilyChaos                 2
#define FamilyDECnet                1
#define FamilyInternet              0        // IPv4
#define FamilyInternet6             6        // IPv6
#define FamilyServerInterpreted     5
#define FillOpaqueStippled          3
#define FillSolid                   0
#define FillStippled                2
#define FillTiled                   1
#define FirstExtensionError         128
#define FocusChangeMask             (1L<<21)
#define FocusIn                     9
#define FocusOut                    10
#define FontChange                  255
#define FontLeftToRight             0
#define FontRightToLeft             1
#define ForgetGravity               0
#define GCArcMode                   (1L<<22)
#define GCBackground                (1L<<3)
#define GCCapStyle                  (1L<<6)
#define GCClipMask                  (1L<<19)
#define GCClipXOrigin               (1L<<17)
#define GCClipYOrigin               (1L<<18)
#define GCDashList                  (1L<<21)
#define GCDashOffset                (1L<<20)
#define GCFillRule                  (1L<<9)
#define GCFillStyle                 (1L<<8)
#define GCFont                      (1L<<14)
#define GCForeground                (1L<<2)
#define GCFunction                  (1L<<0)
#define GCGraphicsExposures         (1L<<16)
#define GCJoinStyle                 (1L<<7)
#define GCLastBit                   22
#define GCLineStyle                 (1L<<5)
#define GCLineWidth                 (1L<<4)
#define GCPlaneMask                 (1L<<1)
#define GCStipple                   (1L<<11)
#define GCSubwindowMode             (1L<<15)
#define GCTile                      (1L<<10)
#define GCTileStipXOrigin           (1L<<12)
#define GCTileStipYOrigin           (1L<<13)
#define GenericEvent                35
#define GrabFrozen                  4
#define GrabInvalidTime             2
#define GrabModeAsync               1
#define GrabModeSync                0
#define GrabNotViewable             3
#define GrabSuccess                 0
#define GraphicsExpose              13
#define GravityNotify               24
#define GrayScale                   1
#define GXand                       0x1      // src AND dst
#define GXandInverted               0x4      // NOT src AND dst
#define GXandReverse                0x2      // src AND NOT dst
#define GXclear                     0x0      // 0
#define GXcopy                      0x3      // src
#define GXcopyInverted              0xc      // NOT src
#define GXequiv                     0x9      // NOT src XOR dst
#define GXinvert                    0xa      // NOT dst
#define GXnand                      0xe      // NOT src OR NOT dst
#define GXnoop                      0x5      // dst
#define GXnor                       0x8      // NOT src AND NOT dst
#define GXor                        0x7      // src OR dst
#define GXorInverted                0xd      // NOT src OR dst
#define GXorReverse                 0xb      // src OR NOT dst
#define GXset                       0xf      // 1
#define GXxor                       0x6      // src XOR dst
#define HostDelete                  1
#define HostInsert                  0
#define IncludeInferiors            1
#define InputFocus                  1L       // destination window in SendEvent
#define InputOnly                   2
#define InputOutput                 1
#define IsUnmapped                  0
#define IsUnviewable                1
#define IsViewable                  2
#define JoinBevel                   2
#define JoinMiter                   0
#define JoinRound                   1
#define KBAutoRepeatMode            (1L<<7)
#define KBBellDuration              (1L<<3)
#define KBBellPercent               (1L<<1)
#define KBBellPitch                 (1L<<2)
#define KBKey                       (1L<<6)
#define KBKeyClickPercent           (1L<<0)
#define KBLed                       (1L<<4)
#define KBLedMode                   (1L<<5)
#define KeymapNotify                11
#define KeymapStateMask             (1L<<14)
#define KeyPress                    2
#define KeyPressMask                (1L<<0)
#define KeyRelease                  3
#define KeyReleaseMask              (1L<<1)
#define LASTEvent                   36       // must be bigger than any event #
#define LastExtensionError          255
#define LeaveNotify                 8
#define LeaveWindowMask             (1L<<5)
#define LedModeOff                  0
#define LedModeOn                   1
#define LineDoubleDash              2
#define LineOnOffDash               1
#define LineSolid                   0
#define LockMapIndex                1
#define LockMask                    (1<<1)
#define LowerHighest                1
#define LSBFirst                    0
#define MapNotify                   19
#define MappingBusy                 1
#define MappingFailed               2
#define MappingKeyboard             1
#define MappingModifier             0
#define MappingNotify               34
#define MappingPointer              2
#define MappingSuccess              0
#define MapRequest                  20
#define Mod1MapIndex                3
#define Mod1Mask                    (1<<3)
#define Mod2MapIndex                4
#define Mod2Mask                    (1<<4)
#define Mod3MapIndex                5
#define Mod3Mask                    (1<<5)
#define Mod4MapIndex                6
#define Mod4Mask                    (1<<6)
#define Mod5MapIndex                7
#define Mod5Mask                    (1<<7)
#define MotionNotify                6
#define MSBFirst                    1
#define NoEventMask                 0L
#define NoExpose                    14
#define Nonconvex                   1        // no paths intersect, but not convex
#define None                        0L       // universal null resource or null atom
#define NorthEastGravity            3
#define NorthGravity                2
#define NorthWestGravity            1
#define NoSymbol                    0L       // special KeySym
#define NotifyAncestor              0
#define NotifyDetailNone            7
#define NotifyGrab                  1
#define NotifyHint                  1        // for MotionNotify events
#define NotifyInferior              2
#define NotifyNonlinear             3
#define NotifyNonlinearVirtual      4
#define NotifyNormal                0
#define NotifyPointer               5
#define NotifyPointerRoot           6
#define NotifyUngrab                2
#define NotifyVirtual               1
#define NotifyWhileGrabbed          3
#define NotUseful                   0
#define Opposite                    4
#define OwnerGrabButtonMask         (1L<<24)
#define ParentRelative              1L       // background pixmap in CreateWindow and ChangeWindowAttributes
#define PlaceOnBottom               1
#define PlaceOnTop                  0
#define PointerMotionHintMask       (1L<<7)
#define PointerMotionMask           (1L<<6)
#define PointerRoot                 1L       // focus window in SetInputFocus
#define PointerWindow               0L       // destination window in SendEvent
#define PreferBlanking              1
#define PropertyChangeMask          (1L<<22)
#define PropertyDelete              1
#define PropertyNewValue            0
#define PropertyNotify              28
#define PropModeAppend              2
#define PropModePrepend             1
#define PropModeReplace             0
#define PseudoColor                 3
#define RaiseLowest                 0
#define ReparentNotify              21
#define ReplayKeyboard              5
#define ReplayPointer               2
#define ResizeRedirectMask          (1L<<18)
#define ResizeRequest               25
#define RetainPermanent             1
#define RetainTemporary             2
#define RevertToNone                (int)None
#define RevertToParent              2
#define RevertToPointerRoot         (int)PointerRoot
#define ScreenSaverActive           1
#define ScreenSaverReset            0
#define SelectionClear              29
#define SelectionNotify             31
#define SelectionRequest            30
#define SetModeDelete               1
#define SetModeInsert               0
#define ShiftMapIndex               0
#define ShiftMask                   (1<<0)
#define SouthEastGravity            9
#define SouthGravity                8
#define SouthWestGravity            7
#define StaticColor                 2
#define StaticGravity               10
#define StaticGray                  0
#define StippleShape                2        // size stippled fastest
#define StructureNotifyMask         (1L<<17)
#define SubstructureNotifyMask      (1L<<19)
#define SubstructureRedirectMask    (1L<<20)
#define Success                     0        // everything's okay
#define SyncBoth                    7
#define SyncKeyboard                4
#define SyncPointer                 1
#define TileShape                   1        // size tiled fastest
#define TopIf                       2
#define TrueColor                   4
#define UnmapGravity                0
#define UnmapNotify                 18
#define Unsorted                    0
#define VisibilityChangeMask        (1L<<16)
#define VisibilityFullyObscured     2
#define VisibilityNotify            15
#define VisibilityPartiallyObscured 1
#define VisibilityUnobscured        0
#define WestGravity                 4
#define WhenMapped                  1
#define WindingRule                 1
#define X_PROTOCOL                  11       // current protocol version
#define X_PROTOCOL_REVISION         0        // current minor version
#define XYBitmap                    0        // depth 1, XYFormat
#define XYPixmap                    1        // depth == drawable depth
#define YSorted                     1
#define YXBanded                    3
#define YXSorted                    2
#define ZPixmap                     2        // depth == drawable depth

typedef uint64_t                    XID;
typedef uint64_t                    XMask;
typedef uint64_t                    XAtom;
typedef uint64_t                    XVisualID;
typedef uint64_t                    XTime;
typedef XID                         XWindow;
typedef XID                         XDrawable;
typedef XID                         XFont;
typedef XID                         XPixmap;
typedef XID                         XCursor;
typedef XID                         XColormap;
typedef XID                         XGContext;
typedef XID                         XKeySym;
typedef uint8_t                     XKeyCode;

#endif//_core_linux_libX11_X_h_