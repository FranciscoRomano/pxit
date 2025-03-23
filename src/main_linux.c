#include "core/private.h"

int main(void)
{
    if (!_load_libX11_so())
    {
        printf("failed to load library 'libX11'\n");
        exit(EXIT_FAILURE);
    }

    _free_libX11_so();
    return 0;
}