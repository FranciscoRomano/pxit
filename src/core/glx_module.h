// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_glx_module_h__
#define __core_glx_module_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include "linux/libGLX.h"

/// @brief Represents the GLX module and supported functions.
extern struct _Module_glx {    
    bool OK;
} _glx;

/// @brief Returns true if the GLX module was freed successfully.
bool _FreeModule_glx();

/// @brief Returns true if the GLX module was loaded successfully.
bool _LoadModule_glx();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_glx_module_h__
// -------------------------------------------------------------------------------------------------------------------------- //