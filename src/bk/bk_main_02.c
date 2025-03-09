// https://stackoverflow.com/questions/5036620/opengl-v1-1-off-screen-rendering-or-render-directly-to-bitmap
// https://community.khronos.org/t/pbuffer/31347
// https://learn.microsoft.com/en-us/windows/win32/opengl/wgl-functions
// https://github.com/Stehfyn/imgui-borderless-win32
// https://stackoverflow.com/questions/4052940/how-to-make-an-opengl-rendering-context-with-transparent-background
// https://gist.github.com/rjmcguire/b05d061b6ab1625695a0
// http://www.directxtutorial.com/LessonList.aspx?listid=9
// https://www.3dgep.com/

#include "core/windows/d3d9.h"
#include "core/module.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct MonitorInfo {
    int32_t  left;
    int32_t  top;
    uint32_t width;
    uint32_t height;
} MonitorInfo;

int main(void)
{
    WindowCreateInfo info = {};
    info.Top    = 10;
    info.Left   = 10;
    info.Width  = 320;
    info.Height = 200;
    info.pTitle = "My Window";

    Window_t window;
    if (!_CreateWindow_win32(&info, &window))
    {
        printf("ERROR: failed to create window");
        exit(EXIT_FAILURE);
    }

    if (!_load_d3d9_dll())
    {
        printf("ERROR: failed to load library 'dxd9.dll'\n");
        exit(EXIT_FAILURE);
    }

    // create D3D9 interface
    IDirect3D9* d3d9 = _d3d9.Direct3DCreate9(D3D_SDK_VERSION);
    if (d3d9 == NULL)
    {
        printf("ERROR: failed to create d3d9 interface\n");
        exit(EXIT_FAILURE);
    }

    // create D3D9 device interface
    D3DPRESENT_PARAMETERS d3dpp = {};
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow = window.win32.hWnd;
    IDirect3DDevice9* d3d9_device = NULL;
    d3d9->lpVtbl->CreateDevice(d3d9, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window.win32.hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3d9_device);
    if (!d3d9_device)
    {
        printf("ERROR: failed to create d3d9 device\n");
    }

    uint8_t r = 0, g = 40, b = 100;
    while (ReadEvents())
    {
        // clear the window to a deep blue
        r += 1;
        g += 2;
        b += 4;
        d3d9_device->lpVtbl->Clear(d3d9_device, 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(r, g, b), 1.0f, 0);

        // begins the 3D scene
        d3d9_device->lpVtbl->BeginScene(d3d9_device);

        // do 3D rendering on the back buffer here

        // ends the 3D scene
        d3d9_device->lpVtbl->EndScene(d3d9_device);

        d3d9_device->lpVtbl->Present(d3d9_device, NULL, NULL, NULL, NULL);    // displays the created frame
    }

    if (!d3d9->lpVtbl->Release(d3d9) != 0)
    {
        printf("ERROR: the d3d9 interface is still in use\n");
    }

    if (!_free_d3d9_dll())
    {
        printf("ERROR: failed to free library 'dxd9.dll'\n");
    }

    if (!_DestroyWindow_win32(&window))
    {
        printf("ERROR: failed to destroy window\n");
    }

    _FreeModule_win32();
}