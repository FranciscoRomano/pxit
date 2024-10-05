// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// ---------------------------------------------------------------------------------------------- //
#include <pxit/pxit.h>
#include "../platform/X11/library.h"

PxResult pxGetDisplay(PxDisplay* pDisplay)
{
    if (pxLoadLibrary_X11() != (int)PX_SUCCESS) return PX_FAILURE;

    int index = X11.XDefaultScreen(X11.dpy);
    *pDisplay = (PxDisplay)X11.XScreenOfDisplay(X11.dpy, index);
    return PX_SUCCESS;
}

PxResult pxGetDisplays(int* pCount, PxDisplay* pDisplays)
{
    if (pxLoadLibrary_X11() != (int)PX_SUCCESS) return PX_FAILURE;

    int screen_count = X11.XScreenCount(X11.dpy);
    if (pCount == NULL) return PX_FAILURE;
    *pCount = screen_count;

    if (pDisplays == NULL) return PX_SUCCESS;
    for (int i = 0; i < screen_count && i < *pCount; i++)
        pDisplays[i] = (PxDisplay)X11.XScreenOfDisplay(X11.dpy, i);
    return PX_SUCCESS;
}

PxResult pxGetDisplayInfo(PxDisplay Display, PxDisplayInfo* pDisplayInfo)
{
    if (pxLoadLibrary_X11() != (int)PX_SUCCESS) return PX_FAILURE;
    if (pDisplayInfo == NULL) return PX_FAILURE;
    if (Display == NULL) return PX_FAILURE;

    Screen* screen = (Screen*)(void*)Display;
    pDisplayInfo->ScreenX = 0;
    pDisplayInfo->ScreenY = 0;
    pDisplayInfo->ScreenW = screen->width;
    pDisplayInfo->ScreenH = screen->height;
    pDisplayInfo->Refresh = 0;
    pDisplayInfo->Scaling = 100;
    return PX_SUCCESS;
}

// ---------------------------------------------------------------------------------------------- //