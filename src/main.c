// https://wayland-book.com/wayland-display/creation.html
#include "platform/WaylandClient/library.h"

int main(int argc, char** argv)
{
    if (pxLoadWaylandClient() == PX_SUCCESS)
    {
        struct wl_display* dpy = WaylandClient.wl_display_connect(NULL);
        if (dpy != NULL)
        {
            printf("Connected to wayland display\n");
            WaylandClient.wl_display_disconnect(dpy);
            pxFreeWaylandClient();
            exit(EXIT_SUCCESS);
            return 0;
        }

        printf("Failed to connect to wayland display\n");
        pxFreeWaylandClient();
    }
    exit(EXIT_FAILURE);
    return 0;
}