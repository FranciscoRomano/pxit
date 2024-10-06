// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "library.h"
#include <wayland-client.h>

PxWaylandClient WaylandClient = {};

PxResult pxFreeWaylandClient()
{
    // check if library is already loaded
    if (WaylandClient.lib == NULL) return PX_SUCCESS;

    // close the library and reset data to zeros.
    PLATFORM_LIBRARY_FREE(WaylandClient)
    return PX_SUCCESS;
}

PxResult pxLoadWaylandClient()
{
    // check if library is already loaded
    if (WaylandClient.lib != NULL) return PX_SUCCESS;

    // iterate through all potential library paths
    const char* paths[] = {
        PLATFORM_LIBRARY_PATH("libwayland-client.so.0.22.0"),
        PLATFORM_LIBRARY_PATH("libwayland-client.so.0.22"),
        PLATFORM_LIBRARY_PATH("libwayland-client.so.0")
        PLATFORM_LIBRARY_PATH("libwayland-client.so")
    };
    const size_t path_count = sizeof(paths) / sizeof(paths[0]);
    for (size_t i = 0; i < path_count; i++)
    {
        // attempt to load the library and symbols from path
        PLATFORM_LIBRARY_OPEN(WaylandClient, paths[i])
        PLATFORM_LIBRARY_LSYM(WaylandClient, wl_display_connect)
        PLATFORM_LIBRARY_LSYM(WaylandClient, wl_display_disconnect)
        return PX_SUCCESS;
    }

    printf("- ERROR: Failed to load library 'libwayland-client'\n");
    return PX_FAILURE;
}