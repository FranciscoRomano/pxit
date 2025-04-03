#include "core/private.h"

int main(void)
{
    if (!load_user32())
    {
        FAILURE("could not load 'user32' library");
        exit(EXIT_FAILURE);
    }

    if (!load_gdi32())
    {
        FAILURE("could not load 'gdi32' library");
        exit(EXIT_FAILURE);
    }

    WNDCLASSEXA wc = { sizeof(WNDCLASSEXA) };
    wc.lpszClassName = "HiCanaanWindowClass";
    if (!user32.RegisterClassExA(&wc))
    {
        FAILURE("failed to register window class");
        exit(EXIT_FAILURE);
    }

    user32.UnregisterClassA(wc.lpszClassName, NULL);

    printf("Hi Canaan\n");
    free_user32();
    free_gdi32();
    return 0;
}