#include "core/private.h"

int main(void)
{
    if (!user32_load())
    {
        failure("could not load 'user32' library");
        exit(EXIT_FAILURE);
    }

    if (!gdi32_load())
    {
        failure("could not load 'gdi32' library");
        exit(EXIT_FAILURE);
    }

    user32_free();
    gdi32_free();
    return 0;
}