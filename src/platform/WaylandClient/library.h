// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
#ifndef __pxit_platform_WaylandClient_library_h__
#define __pxit_platform_WaylandClient_library_h__
#include "../generic/library.h"
BEGIN_EXTERN_C
// ---------------------------------------------------------------------------------------------- //

typedef struct PxWaylandClient {
    void*              lib;
    struct wl_display* (*wl_display_connect)(const char* name);
    void               (*wl_display_disconnect)(struct wl_display* display);
} PxWaylandClient;

extern PxWaylandClient WaylandClient;

PxResult PLATFORM_CALL pxFreeWaylandClient();
PxResult PLATFORM_CALL pxLoadWaylandClient();

// ---------------------------------------------------------------------------------------------- //
END_EXTERN_C
#endif//__pxit_platform_WaylandClient_library_h__
// ---------------------------------------------------------------------------------------------- //