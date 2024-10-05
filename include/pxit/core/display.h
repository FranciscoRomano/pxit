// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// ---------------------------------------------------------------------------------------------- //
#ifndef __pxit_core_display_h__
#define __pxit_core_display_h__
#ifdef __cplusplus
extern "C" {
#endif

PLATFORM_HANDLE(PxDisplay)

/// @brief Represents the information about a display.
typedef struct PxDisplayInfo {
    int Scaling; // The scale percentage of the display (ex: 100 => 100%)
    int ScreenX; // The horizontal offset from the left of the display.
    int ScreenY; // The vertical offset from the top of the display.
    int ScreenW; // The horizontal size of the display.
    int ScreenH; // The vertical size of the display.
    int Refresh; // The refresh rate of the display in Hertz (Hz).
} PxDisplayInfo;

PxResult PLATFORM_CALL pxGetDisplay(PxDisplay* pDisplay);
PxResult PLATFORM_CALL pxGetDisplays(int* pCount, PxDisplay* pDisplays);
PxResult PLATFORM_CALL pxGetDisplayInfo(PxDisplay Display, PxDisplayInfo* pDisplayInfo);

#ifdef __cplusplus
}
#endif
#endif//__pxit_core_display_h__