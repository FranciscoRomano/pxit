// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_glx_h__
#define __core_module_glx_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "linux/libGLX.h"

/// @brief Represents the GLX module and supported functions.
extern struct _Module_GLX {    
    bool        OK;
    XColormap   cmap;
    GLXFBConfig fbc;
} _GLX;

/// @brief Returns true if the GLX module was freed successfully.
bool _FreeModule_GLX();

/// @brief Returns true if the GLX module was loaded successfully.
bool _LoadModule_GLX();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_glx_h__
// -------------------------------------------------------------------------------------------------------------------------- //