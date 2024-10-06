#include <stdio.h>
#include <stdlib.h>
#include <pxit/pxit.h>

int main(int argc, char** argv)
{
    int count = 0;
    if (pxGetDisplays(&count, NULL) != PX_SUCCESS)
    {
        printf("Failed to fetch displays\n");
        exit(EXIT_FAILURE);
    }

    PxDisplay* displays = malloc(sizeof(PxDisplay) * count);
    if (pxGetDisplays(&count, displays) != PX_SUCCESS)
    {
        printf("Failed to fetch displays\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++)
    {
        PxDisplayInfo info = {};
        if (pxGetDisplayInfo(displays[i], &info) != PX_SUCCESS)
        {
            printf("Failed to fetch display[%i] information\n", i);
            continue;
        }

        printf("Display_%i\n", i);
        printf(" - ScreenX: %i\n", info.ScreenX);
        printf(" - ScreenY: %i\n", info.ScreenY);
        printf(" - ScreenW: %i\n", info.ScreenW);
        printf(" - ScreenH: %i\n", info.ScreenH);
        printf(" - Refresh: %i\n", info.Refresh);
        printf(" - Scaling: %i\n", info.Scaling);
    }

    return 0;
}