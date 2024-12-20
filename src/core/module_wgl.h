// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_module_wgl_h__
#define __core_module_wgl_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <stdbool.h>

/// @brief Represents a WGL module and all supported functions.
extern struct _Module_wgl {
    bool OK;
} _wgl;

/// @brief Returns true if the WGL module was freed successfully.
bool _FreeModule_wgl();

/// @brief Returns true if the WGL module was loaded successfully.
bool _LoadModule_wgl();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_module_wgl_h__
// -------------------------------------------------------------------------------------------------------------------------- //