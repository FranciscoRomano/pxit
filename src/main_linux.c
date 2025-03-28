#include "core/private.h"

int main(void)
{
    if (!load_libX11())
    {
        FAILURE("could not load 'libX11' library");
        exit(EXIT_FAILURE);
    }

    if (!load_libGLX())
    {
        FAILURE("could not load 'libGLX' library");
        exit(EXIT_FAILURE);
    }

    free_libX11();
    free_libGLX();
    return 0;
}