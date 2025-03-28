#include "core/private.h"

int main(void)
{
    if (!_load_libX11_so())
    {
        FAILURE("could not load 'libX11' library");
        exit(EXIT_FAILURE);
    }

    if (!_load_libGLX_so())
    {
        FAILURE("could not load 'libGLX' library");
        exit(EXIT_FAILURE);
    }

    _free_libX11_so();
    _free_libGLX_so();
    return 0;
}