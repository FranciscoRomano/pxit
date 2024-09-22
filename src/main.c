#include <stdio.h>
#include <stdlib.h>

#ifdef PX_PLATFORM_USE_X11
#include "platform/X11/library.h"
#endif//PX_PLATFORM_USE_X11

int main(int argc, char** argv)
{
    #ifdef PX_PLATFORM_USE_X11
    if (!pxLoadLibrary_X11()) exit(EXIT_FAILURE);

    Display* dpy = X11.XOpenDisplay(NULL);
    if (dpy == NULL)
    {
        printf("Failed to connect to X server\n");
        exit(EXIT_FAILURE);
    }

    int screen_count = X11.XScreenCount(dpy);
    printf("Screen count: %i\n", screen_count);
    for (int i = 0; i < screen_count; i++)
    {
        Screen* screen = X11.XScreenOfDisplay(dpy, i);
        
        printf("SCREEN_%i: {\n", i);
        printf("  ext_data: %li,\n", (long)screen->ext_data);
        printf("  display: %li,\n",  (long)screen->display);
        printf("  root: %li,\n",     (long)screen->root);
        printf("  width: %i,\n",      screen->width);
        printf("  height: %i,\n",     screen->height);
        printf("  mwidth: %i,\n",     screen->mwidth);
        printf("  mheight: %i,\n",    screen->mheight);
        printf("  ndepths: %i,\n",    screen->ndepths);
        if (screen->ndepths)
        {
            printf("  depths: [\n");
            for (int ii = 0; ii < screen->ndepths; ii++)
            {
                Depth* depth = screen->depths + ii;
                printf("    {\n");
                printf("      depth: %i,\n",    depth->depth);
                printf("      nvisuals: %i,\n", depth->nvisuals);
                if (depth->nvisuals)
                {
                    printf("      visuals: [\n");
                    for (int iii = 0; iii < depth->nvisuals; iii++)
                    {
                        Visual* visual = depth->visuals + iii;
                        printf("        {\n");
                        printf("          ext_data: %li,\n",    (long)visual->ext_data);
                        printf("          visualid: %li,\n",    (long)visual->visualid);
                        printf("          class: %i,\n",        visual->class);
                        printf("          red_mask: %li,\n",    visual->red_mask);
                        printf("          green_mask: %li,\n",  visual->green_mask);
                        printf("          blue_mask: %li,\n",   visual->blue_mask);
                        printf("          bits_per_rgb: %i,\n", visual->bits_per_rgb);
                        printf("          map_entries: %i\n",   visual->map_entries);
                        printf("        }%s", iii == (depth->nvisuals - 1) ? "\n" : ",\n");
                    }

                    printf("      ]\n");

                }
                else printf("      visuals: []\n");
                printf("    }%s", ii == (screen->ndepths - 1) ? "\n" : ",\n");
            }
            printf("  ],\n");
        }
        else printf("  depths: [],\n");
        printf("  root_depth : %i\n", screen->root_depth);
        if (screen->root_visual)
        {
            printf("  root_visual: {\n");
            printf("    ext_data: %li,\n",    (long)screen->root_visual->ext_data);
            printf("    visualid: %li,\n",    (long)screen->root_visual->visualid);
            printf("    class: %i,\n",        screen->root_visual->class);
            printf("    red_mask: %li,\n",    screen->root_visual->red_mask);
            printf("    green_mask: %li,\n",  screen->root_visual->green_mask);
            printf("    blue_mask: %li,\n",   screen->root_visual->blue_mask);
            printf("    bits_per_rgb: %i,\n", screen->root_visual->bits_per_rgb);
            printf("    map_entries: %i\n",   screen->root_visual->map_entries);
            printf("  },\n");
        }
        else printf("  root_visual: null,\n");
        printf("  default_gc: %li,\n",   (long)screen->default_gc);
        printf("  cmap: %li,\n",         screen->cmap);
        printf("  white_pixel: %li,\n",  screen->white_pixel);
        printf("  black_pixel: %li,\n",  screen->black_pixel);
        printf("  max_maps: %i,\n",      screen->max_maps);
        printf("  min_maps: %i,\n",      screen->min_maps);
        printf("  backing_store: %i,\n", screen->backing_store);
        printf("  save_unders: %s,\n",   screen->save_unders ? "true" : "false");
        printf("  save_unders: %li\n",   screen->root_input_mask);
        printf("}\n");
    }

    pxFreeLibrary_X11();
    #endif//PX_PLATFORM_USE_X11
    return 0;
}