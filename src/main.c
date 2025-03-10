//#include <pxit/pxit.h>
#include "core/windows/dxgi.h"
#include <stdlib.h>
#include <stdio.h>
#include <dxgi1_6.h>

const GUID DECLSPEC_SELECTANY bananas = { 0xa4966eed, 0x76db, 0x44da, { 0x84, 0xc1, 0xee, 0x9a, 0x7a, 0xfb, 0x20, 0xa8 } };

int main(void)
{
    if (!_load_dxgi_dll())
    {
        printf("failed to load library 'dxgi'\n");
        return EXIT_FAILURE;
    }

    
    IDXGIFactory7* factory = NULL;
    if (_dxgi.CreateDXGIFactory2(0, &bananas, (void**)&factory) == S_OK)
    {
        IDXGIAdapter* adapter;
        for (int i = 0; factory->lpVtbl->EnumAdapters(factory, i, &adapter) != DXGI_ERROR_NOT_FOUND; i++)
        {
            DXGI_ADAPTER_DESC adapter_desc;
            adapter->lpVtbl->GetDesc(adapter, &adapter_desc);

            printf("adapter_%i:\n", i);
            printf("- description: ");
            wprintf(adapter_desc.Description);
            printf("\n");
            printf("- dedicated-video-memory: %llu\n", adapter_desc.DedicatedVideoMemory);
            printf("- dedicated-system-memory: %llu\n", adapter_desc.DedicatedSystemMemory);
            printf("- shared-system-memory: %llu\n", adapter_desc.SharedSystemMemory);
            printf("- outputs:\n");

            IDXGIOutput* output;
            for (int ii = 0; adapter->lpVtbl->EnumOutputs(adapter, ii, &output) != DXGI_ERROR_NOT_FOUND; ii++)
            {
                DXGI_OUTPUT_DESC output_desc;
                output->lpVtbl->GetDesc(output, &output_desc);

                printf("    output_%i:\n", ii);
                printf("    - device-name: ");
                wprintf(output_desc.DeviceName);
                printf("\n");
                printf("    - desktop-coordinates:\n");
                printf("      - left: %li\n", output_desc.DesktopCoordinates.left);
                printf("      - top: %li\n", output_desc.DesktopCoordinates.top);
                printf("      - right: %li\n", output_desc.DesktopCoordinates.right);
                printf("      - bottom: %li\n", output_desc.DesktopCoordinates.bottom);
                printf("    - attached-to-desktop: %s\n", output_desc.AttachedToDesktop ? "true" : "false");
            }
        }

        factory->lpVtbl->Release(factory);
    }
    else
    {
        printf("failed to create dxgi factory 7\n");
    }

    if (!_free_dxgi_dll())
    {
        printf("failed to free library 'dxgi'\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
    // Window window;
    // Surface surface;

    // {
    //     WindowCreateInfo create_info = {};
    //     create_info.Width   = 320;
    //     create_info.Height  = 200;
    //     create_info.pTitle  = "My Window";
    //     CreateWindow(&create_info, &window);
    // }

    // {
    //     SurfaceCreateInfo create_info = {};
    //     create_info.Family = SURFACE_FAMILY_VULKAN;
    //     create_info.Window = window;
    //     CreateSurface(&create_info, &surface);
    // }

    // while (ReadEvents());
}