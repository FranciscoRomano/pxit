// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __core_windows_dxgi_h__
#define __core_windows_dxgi_h__
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>
#include <stdbool.h>
#include "api/dxgiddi.h"
#include "api/dxgidebug.h"

/// @brief Represents the "dxgi.dll" library and supported functions.
extern struct _dxgi_dll {
    HMODULE          dll;
    HRESULT (WINAPI *CreateDXGIFactory)(REFIID,void**);
    HRESULT (WINAPI *CreateDXGIFactory1)(REFIID,void**);
    HRESULT (WINAPI *CreateDXGIFactory2)(UINT,REFIID,void**);
    HRESULT (WINAPI *DXGIDeclareAdapterRemovalSupport)();
    HRESULT (WINAPI *DXGIDisableVBlankVirtualization)();
    HRESULT (WINAPI *DXGIGetDebugInterface1)(UINT,REFIID,void**);
} _dxgi;

/// @brief Returns true if the "dxgi.dll" library was freed successfully.
bool _free_dxgi_dll();

/// @brief Returns true if the "dxgi.dll" library was loaded successfully.
bool _load_dxgi_dll();

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__core_windows_dxgi_h__
// -------------------------------------------------------------------------------------------------------------------------- //