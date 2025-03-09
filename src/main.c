#include <pxit/pxit.h>

int main(void)
{
    const uint32_t SCREEN_WIDTH     = 1920;
    const uint32_t SCREEN_HEIGHT    = 1020;

    const uint32_t CELLS_HORIZONTAL = 2;
    const uint32_t CELLS_VERTICAL   = 2;
    const uint32_t CELLS_PADDING    = 8;

    const uint32_t WINDOW_WIDTH     = (SCREEN_WIDTH  - (CELLS_PADDING * (CELLS_HORIZONTAL + 1))) / CELLS_HORIZONTAL;
    const uint32_t WINDOW_HEIGHT    = (SCREEN_HEIGHT - (CELLS_PADDING * (CELLS_VERTICAL   + 1))) / CELLS_VERTICAL;

    for (uint32_t left = 0; left < CELLS_HORIZONTAL; left++)
    {
        for (uint32_t top = 0; top < CELLS_VERTICAL; top++)
        {
            WindowCreateInfo create_info = {};
            create_info.Top     = CELLS_PADDING + (WINDOW_HEIGHT + CELLS_PADDING) * top;
            create_info.Left    = CELLS_PADDING + (WINDOW_WIDTH  + CELLS_PADDING) * left;
            create_info.Width   = WINDOW_WIDTH;
            create_info.Height  = WINDOW_HEIGHT;
            create_info.pTitle  = "My Window";
            CreateWindow(&create_info, NULL);
        }
    }

    while (ReadEvents());
}