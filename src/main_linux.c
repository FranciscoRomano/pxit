#include "core/private.h"

int main(void)
{
    WindowCreateInfo create_info = {};
    create_info.Width  = 320;
    create_info.Height = 200;
    create_info.pTitle = "My Window";
    create_info.Family = WINDOW_FAMILY_ANY;
    CreateWindow(&create_info, NULL);

    while (ReadEvents());

    return 0;
}