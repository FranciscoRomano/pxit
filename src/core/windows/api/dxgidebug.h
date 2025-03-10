// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! THIS IS A MODIFIED VERSION OF THE ORIGINAL HEADER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! │
// ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
// │ DATE: 2025-02-27                                                                                                          │
// │ FILE: "C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\dxgidebug.h"                                                               │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// -------------------------------------------------------------------------------------------------------------------------- //
#ifndef __dxgidebug_h__
#define __dxgidebug_h__ 1
#ifdef __cplusplus
extern "C" {
#endif
// -------------------------------------------------------------------------------------------------------------------------- //

#include <windef.h>

DEFINE_GUID(DXGI_DEBUG_ALL,     0xe48ae283, 0xda80, 0x490b, 0x87, 0xe6, 0x43, 0xe9, 0xa9, 0xcf, 0xda, 0x08);
DEFINE_GUID(DXGI_DEBUG_DX,      0x35cdd7fc, 0x13b2, 0x421d, 0xa5, 0xd7, 0x7e, 0x44, 0x51, 0x28, 0x7d, 0x64);
DEFINE_GUID(DXGI_DEBUG_DXGI,    0x25cddaa4, 0xb1c6, 0x47e1, 0xac, 0x3e, 0x98, 0x87, 0x5b, 0x5a, 0x2e, 0x2a);
DEFINE_GUID(DXGI_DEBUG_APP,     0x06cd6e01, 0x4219, 0x4ebd, 0x87, 0x09, 0x27, 0xed, 0x23, 0x36, 0x0c, 0x62);
DEFINE_GUID(IID_IDXGIInfoQueue, 0xD67441C7, 0x672A, 0x476f, 0x9E, 0x82, 0xCD, 0x55, 0xB4, 0x49, 0x49, 0xCE);
DEFINE_GUID(IID_IDXGIDebug,     0x119E7452, 0xDE9E, 0x40fe, 0x88, 0x06, 0x88, 0xF9, 0x0C, 0x12, 0xB4, 0x41);
DEFINE_GUID(IID_IDXGIDebug1,    0xc5a05f0c, 0x16f2, 0x4adf, 0x9f, 0x4d, 0xa8, 0xc4, 0xd5, 0x8a, 0xc5, 0x50);

#define DXGI_DEBUG_BINARY_VERSION                          1
#define DXGI_INFO_QUEUE_DEFAULT_MESSAGE_COUNT_LIMIT        1024
#define DXGI_INFO_QUEUE_MESSAGE_ID_STRING_FROM_APPLICATION 0

typedef GUID                                               DXGI_DEBUG_ID;
typedef enum   DXGI_DEBUG_RLO_FLAGS                        DXGI_DEBUG_RLO_FLAGS;
typedef struct DXGI_INFO_QUEUE_FILTER                      DXGI_INFO_QUEUE_FILTER;
typedef struct DXGI_INFO_QUEUE_FILTER_DESC                 DXGI_INFO_QUEUE_FILTER_DESC;
typedef struct DXGI_INFO_QUEUE_MESSAGE                     DXGI_INFO_QUEUE_MESSAGE;
typedef enum   DXGI_INFO_QUEUE_MESSAGE_CATEGORY            DXGI_INFO_QUEUE_MESSAGE_CATEGORY;
typedef int                                                DXGI_INFO_QUEUE_MESSAGE_ID;
typedef enum   DXGI_INFO_QUEUE_MESSAGE_SEVERITY            DXGI_INFO_QUEUE_MESSAGE_SEVERITY;
typedef struct IDXGIInfoQueue                              IDXGIInfoQueue;
typedef struct IDXGIDebug                                  IDXGIDebug;
typedef struct IDXGIDebug1                                 IDXGIDebug1;

enum DXGI_DEBUG_RLO_FLAGS {
    DXGI_DEBUG_RLO_SUMMARY                                 = 0x1,
    DXGI_DEBUG_RLO_DETAIL                                  = 0x2,
    DXGI_DEBUG_RLO_IGNORE_INTERNAL                         = 0x4,
    DXGI_DEBUG_RLO_ALL                                     = 0x7,
};

enum DXGI_INFO_QUEUE_MESSAGE_CATEGORY {
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_UNKNOWN               = 0x0,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_MISCELLANEOUS         = 0x1,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_INITIALIZATION        = 0x2,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_CLEANUP               = 0x3,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_COMPILATION           = 0x4,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_STATE_CREATION        = 0x4,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_STATE_SETTING         = 0x5,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_STATE_GETTING         = 0x6,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_RESOURCE_MANIPULATION = 0x7,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_EXECUTION             = 0x8,
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY_SHADER                = 0x9,
};

enum DXGI_INFO_QUEUE_MESSAGE_SEVERITY {
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY_CORRUPTION            = 0x0,
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY_ERROR                 = 0x1,
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY_WARNING               = 0x2,
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY_INFO                  = 0x3,
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY_MESSAGE               = 0x4,
};

struct DXGI_INFO_QUEUE_MESSAGE {
    DXGI_DEBUG_ID                                          Producer;
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY                       Category;
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY                       Severity;
    DXGI_INFO_QUEUE_MESSAGE_ID                             ID;
    const char*                                            pDescription;
    SIZE_T                                                 DescriptionByteLength;
};

struct DXGI_INFO_QUEUE_FILTER_DESC {
    UINT                                                   NumCategories;
    DXGI_INFO_QUEUE_MESSAGE_CATEGORY*                      pCategoryList;
    UINT                                                   NumSeverities;
    DXGI_INFO_QUEUE_MESSAGE_SEVERITY*                      pSeverityList;
    UINT                                                   NumIDs;
    DXGI_INFO_QUEUE_MESSAGE_ID*                            pIDList;
};

struct DXGI_INFO_QUEUE_FILTER {
    DXGI_INFO_QUEUE_FILTER_DESC                            AllowList;
    DXGI_INFO_QUEUE_FILTER_DESC                            DenyList;
};

struct IDXGIInfoQueue {
    struct {
        HRESULT                                   (WINAPI *QueryInterface)(IDXGIInfoQueue*,REFIID,void**);
        ULONG                                     (WINAPI *AddRef)(IDXGIInfoQueue*);
        ULONG                                     (WINAPI *Release)(IDXGIInfoQueue*);
        HRESULT                                   (WINAPI *SetMessageCountLimit)(IDXGIInfoQueue*,DXGI_DEBUG_ID,UINT64);
        void                                      (WINAPI *ClearStoredMessages)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *GetMessage)(IDXGIInfoQueue*,DXGI_DEBUG_ID,UINT64,DXGI_INFO_QUEUE_MESSAGE*,SIZE_T*);
        UINT64                                    (WINAPI *GetNumStoredMessagesAllowedByRetrievalFilters)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT64                                    (WINAPI *GetNumStoredMessages)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT64                                    (WINAPI *GetNumMessagesDiscardedByMessageCountLimit)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT64                                    (WINAPI *GetMessageCountLimit)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT64                                    (WINAPI *GetNumMessagesAllowedByStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT64                                    (WINAPI *GetNumMessagesDeniedByStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *AddStorageFilterEntries)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_FILTER*);
        HRESULT                                   (WINAPI *GetStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_FILTER*,SIZE_T*);
        void                                      (WINAPI *ClearStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushEmptyStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushDenyAllStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushCopyOfStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_FILTER*);
        void                                      (WINAPI *PopStorageFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT                                      (WINAPI *GetStorageFilterStackSize)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *AddRetrievalFilterEntries)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_FILTER*);
        HRESULT                                   (WINAPI *GetRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_FILTER*,SIZE_T*);
        void                                      (WINAPI *ClearRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushEmptyRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushDenyAllRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushCopyOfRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *PushRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_FILTER*);
        void                                      (WINAPI *PopRetrievalFilter)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        UINT                                      (WINAPI *GetRetrievalFilterStackSize)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
        HRESULT                                   (WINAPI *AddMessage)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_CATEGORY,DXGI_INFO_QUEUE_MESSAGE_SEVERITY,DXGI_INFO_QUEUE_MESSAGE_ID,LPCSTR);
        HRESULT                                   (WINAPI *AddApplicationMessage)(IDXGIInfoQueue*,DXGI_INFO_QUEUE_MESSAGE_SEVERITY,LPCSTR);
        HRESULT                                   (WINAPI *SetBreakOnCategory)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_CATEGORY,BOOL);
        HRESULT                                   (WINAPI *SetBreakOnSeverity)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_SEVERITY,BOOL);
        HRESULT                                   (WINAPI *SetBreakOnID)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_ID,BOOL);
        BOOL                                      (WINAPI *GetBreakOnCategory)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_CATEGORY);
        BOOL                                      (WINAPI *GetBreakOnSeverity)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_SEVERITY);
        BOOL                                      (WINAPI *GetBreakOnID)(IDXGIInfoQueue*,DXGI_DEBUG_ID,DXGI_INFO_QUEUE_MESSAGE_ID);
        void                                      (WINAPI *SetMuteDebugOutput)(IDXGIInfoQueue*,DXGI_DEBUG_ID,BOOL);
        BOOL                                      (WINAPI *GetMuteDebugOutput)(IDXGIInfoQueue*,DXGI_DEBUG_ID);
    }* lpVtbl;
};

struct IDXGIDebug {
    struct {
        HRESULT                                   (WINAPI *QueryInterface)(IDXGIDebug*,REFIID,void**);
        ULONG                                     (WINAPI *AddRef)(IDXGIDebug*);
        ULONG                                     (WINAPI *Release)(IDXGIDebug*);
        HRESULT                                   (WINAPI *ReportLiveObjects)(IDXGIDebug*,GUID,DXGI_DEBUG_RLO_FLAGS);
    } *lpVtbl;
};

struct IDXGIDebug1 {
    struct {
        HRESULT                                   (WINAPI *QueryInterface)(IDXGIDebug1*,REFIID,void**);
        ULONG                                     (WINAPI *AddRef)(IDXGIDebug1*);
        ULONG                                     (WINAPI *Release)(IDXGIDebug1*);
        HRESULT                                   (WINAPI *ReportLiveObjects)(IDXGIDebug1*,GUID,DXGI_DEBUG_RLO_FLAGS);
        void                                      (WINAPI *EnableLeakTrackingForThread)(IDXGIDebug1*);
        void                                      (WINAPI *DisableLeakTrackingForThread)(IDXGIDebug1*);
        BOOL                                      (WINAPI *IsLeakTrackingEnabledForThread)(IDXGIDebug1*);
    } *lpVtbl;
};

// -------------------------------------------------------------------------------------------------------------------------- //
#ifdef __cplusplus
}
#endif
#endif//__dxgidebug_h__
// -------------------------------------------------------------------------------------------------------------------------- //