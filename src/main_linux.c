#include "core/private.h"

int main(void)
{
    if (!libX11_load())
    {
        FAILURE("could not load 'libX11' library");
        exit(EXIT_FAILURE);
    }

    if (!libGLX_load())
    {
        FAILURE("could not load 'libGLX' library");
        exit(EXIT_FAILURE);
    }

    libX11_free();
    libGLX_free();
    return 0;
}