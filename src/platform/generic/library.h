// ---------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
#ifndef __pxit_platform_generic_library_h__
#define __pxit_platform_generic_library_h__
#include <pxit/pxit.h>
// ---------------------------------------------------------------------------------------------- //
#if IS_PLATFORM_LINUX

    #include <dlfcn.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <unistd.h>

    #define PLATFORM_LIBRARY_PATH(NAME)\
    "/usr/lib/x86_64-linux-gnu/"                        NAME,\
    "/snap/gnome-42-2204/176/usr/lib/x86_64-linux-gnu/" NAME

    #define PLATFORM_LIBRARY_OPEN(LIBRARY,PATH)\
    struct stat f;\
    if (stat(PATH, &f) != 0) continue;\
    switch (f.st_mode & __S_IFMT) { case __S_IFLNK: case __S_IFREG: break; default: continue; }\
    LIBRARY.lib = dlopen(PATH, RTLD_LAZY);\
    if(LIBRARY.lib == NULL) continue;

    #define PLATFORM_LIBRARY_LSYM(LIBRARY,NAME)\
    LIBRARY.NAME = dlsym(LIBRARY.lib, #NAME);\
    if (LIBRARY.NAME == NULL) {\
        printf(" - ERROR: Failed to load symbol '" #NAME "'\n");\
        dlclose(LIBRARY.lib);\
        LIBRARY.lib = NULL;\
        return PX_FAILURE;\
    }

    #define PLATFORM_LIBRARY_FREE(LIBRARY)\
    dlclose(LIBRARY.lib);\
    LIBRARY.lib = NULL;\
    memset(&LIBRARY, 0, sizeof(LIBRARY));

#endif//IS_PLATFORM_LINUX
// ---------------------------------------------------------------------------------------------- //
#endif//__pxit_platform_generic_library_h__
// ---------------------------------------------------------------------------------------------- //