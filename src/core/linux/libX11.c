// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#define LIBRARY_MODULE _libX11
#include "../private.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _libX11_so _libX11 = { NULL };

bool _free_libX11_so()
{
    // check if library was unloaded
    if (!_libX11.so) return false;

    // unload and reset library module
    LIBRARY_MODULE_FREE()
    return true;
}

bool _load_libX11_so()
{
    // check if library was loaded
    if (_libX11.so) return true;

    // iterate through all library paths
    const char* paths[] = { "libX11.so.6.4.0", NULL };
    for (size_t i = 0; paths[i]; i++)
    {
        // try loading library and any symbols
        LIBRARY_MODULE_LOAD(paths[i])
        // #include <X11/Xlib.h>
        LIBRARY_MODULE_RSYM(_Xmblen)
        LIBRARY_MODULE_RSYM(_Xmbtowc)
        LIBRARY_MODULE_RSYM(_Xwctomb)
        LIBRARY_MODULE_RSYM(XActivateScreenSaver)
        LIBRARY_MODULE_RSYM(XAddConnectionWatch)
        LIBRARY_MODULE_RSYM(XAddExtension)
        LIBRARY_MODULE_RSYM(XAddHost)
        LIBRARY_MODULE_RSYM(XAddHosts)
        LIBRARY_MODULE_RSYM(XAddToExtensionList)
        LIBRARY_MODULE_RSYM(XAddToSaveSet)
        LIBRARY_MODULE_RSYM(XAllocColor)
        LIBRARY_MODULE_RSYM(XAllocColorCells)
        LIBRARY_MODULE_RSYM(XAllocColorPlanes)
        LIBRARY_MODULE_RSYM(XAllocNamedColor)
        LIBRARY_MODULE_RSYM(XAllowEvents)
        LIBRARY_MODULE_RSYM(XAllPlanes)
        LIBRARY_MODULE_RSYM(XAutoRepeatOff)
        LIBRARY_MODULE_RSYM(XAutoRepeatOn)
        LIBRARY_MODULE_RSYM(XBaseFontNameListOfFontSet)
        LIBRARY_MODULE_RSYM(XBell)
        LIBRARY_MODULE_RSYM(XBitmapBitOrder)
        LIBRARY_MODULE_RSYM(XBitmapPad)
        LIBRARY_MODULE_RSYM(XBitmapUnit)
        LIBRARY_MODULE_RSYM(XBlackPixel)
        LIBRARY_MODULE_RSYM(XBlackPixelOfScreen)
        LIBRARY_MODULE_RSYM(XCellsOfScreen)
        LIBRARY_MODULE_RSYM(XChangeActivePointerGrab)
        LIBRARY_MODULE_RSYM(XChangeGC)
        LIBRARY_MODULE_RSYM(XChangeKeyboardControl)
        LIBRARY_MODULE_RSYM(XChangeKeyboardMapping)
        LIBRARY_MODULE_RSYM(XChangePointerControl)
        LIBRARY_MODULE_RSYM(XChangeProperty)
        LIBRARY_MODULE_RSYM(XChangeSaveSet)
        LIBRARY_MODULE_RSYM(XChangeWindowAttributes)
        LIBRARY_MODULE_RSYM(XCheckIfEvent)
        LIBRARY_MODULE_RSYM(XCheckMaskEvent)
        LIBRARY_MODULE_RSYM(XCheckTypedEvent)
        LIBRARY_MODULE_RSYM(XCheckTypedWindowEvent)
        LIBRARY_MODULE_RSYM(XCheckWindowEvent)
        LIBRARY_MODULE_RSYM(XCirculateSubwindows)
        LIBRARY_MODULE_RSYM(XCirculateSubwindowsDown)
        LIBRARY_MODULE_RSYM(XCirculateSubwindowsUp)
        LIBRARY_MODULE_RSYM(XClearArea)
        LIBRARY_MODULE_RSYM(XClearWindow)
        LIBRARY_MODULE_RSYM(XCloseDisplay)
        LIBRARY_MODULE_RSYM(XCloseIM)
        LIBRARY_MODULE_RSYM(XCloseOM)
        LIBRARY_MODULE_RSYM(XConfigureWindow)
        LIBRARY_MODULE_RSYM(XConnectionNumber)
        LIBRARY_MODULE_RSYM(XContextDependentDrawing)
        LIBRARY_MODULE_RSYM(XContextualDrawing)
        LIBRARY_MODULE_RSYM(XConvertSelection)
        LIBRARY_MODULE_RSYM(XCopyArea)
        LIBRARY_MODULE_RSYM(XCopyColormapAndFree)
        LIBRARY_MODULE_RSYM(XCopyGC)
        LIBRARY_MODULE_RSYM(XCopyPlane)
        LIBRARY_MODULE_RSYM(XCreateBitmapFromData)
        LIBRARY_MODULE_RSYM(XCreateColormap)
        LIBRARY_MODULE_RSYM(XCreateFontCursor)
        LIBRARY_MODULE_RSYM(XCreateFontSet)
        LIBRARY_MODULE_RSYM(XCreateGC)
        LIBRARY_MODULE_RSYM(XCreateGlyphCursor)
        LIBRARY_MODULE_RSYM(XCreateIC)
        LIBRARY_MODULE_RSYM(XCreateImage)
        LIBRARY_MODULE_RSYM(XCreateOC)
        LIBRARY_MODULE_RSYM(XCreatePixmap)
        LIBRARY_MODULE_RSYM(XCreatePixmapCursor)
        LIBRARY_MODULE_RSYM(XCreatePixmapFromBitmapData)
        LIBRARY_MODULE_RSYM(XCreateSimpleWindow)
        LIBRARY_MODULE_RSYM(XCreateWindow)
        LIBRARY_MODULE_RSYM(XDefaultColormap)
        LIBRARY_MODULE_RSYM(XDefaultColormapOfScreen)
        LIBRARY_MODULE_RSYM(XDefaultDepth)
        LIBRARY_MODULE_RSYM(XDefaultDepthOfScreen)
        LIBRARY_MODULE_RSYM(XDefaultGC)
        LIBRARY_MODULE_RSYM(XDefaultGCOfScreen)
        LIBRARY_MODULE_RSYM(XDefaultRootWindow)
        LIBRARY_MODULE_RSYM(XDefaultScreen)
        LIBRARY_MODULE_RSYM(XDefaultScreenOfDisplay)
        LIBRARY_MODULE_RSYM(XDefaultVisual)
        LIBRARY_MODULE_RSYM(XDefaultVisualOfScreen)
        LIBRARY_MODULE_RSYM(XDefineCursor)
        LIBRARY_MODULE_RSYM(XDeleteModifiermapEntry)
        LIBRARY_MODULE_RSYM(XDeleteProperty)
        LIBRARY_MODULE_RSYM(XDestroyIC)
        LIBRARY_MODULE_RSYM(XDestroyOC)
        LIBRARY_MODULE_RSYM(XDestroySubwindows)
        LIBRARY_MODULE_RSYM(XDestroyWindow)
        LIBRARY_MODULE_RSYM(XDirectionalDependentDrawing)
        LIBRARY_MODULE_RSYM(XDisableAccessControl)
        LIBRARY_MODULE_RSYM(XDisplayCells)
        LIBRARY_MODULE_RSYM(XDisplayHeight)
        LIBRARY_MODULE_RSYM(XDisplayHeightMM)
        LIBRARY_MODULE_RSYM(XDisplayKeycodes)
        LIBRARY_MODULE_RSYM(XDisplayMotionBufferSize)
        LIBRARY_MODULE_RSYM(XDisplayName)
        LIBRARY_MODULE_RSYM(XDisplayOfIM)
        LIBRARY_MODULE_RSYM(XDisplayOfOM)
        LIBRARY_MODULE_RSYM(XDisplayOfScreen)
        LIBRARY_MODULE_RSYM(XDisplayPlanes)
        LIBRARY_MODULE_RSYM(XDisplayString)
        LIBRARY_MODULE_RSYM(XDisplayWidth)
        LIBRARY_MODULE_RSYM(XDisplayWidthMM)
        LIBRARY_MODULE_RSYM(XDoesBackingStore)
        LIBRARY_MODULE_RSYM(XDoesSaveUnders)
        LIBRARY_MODULE_RSYM(XDrawArc)
        LIBRARY_MODULE_RSYM(XDrawArcs)
        LIBRARY_MODULE_RSYM(XDrawImageString)
        LIBRARY_MODULE_RSYM(XDrawImageString16)
        LIBRARY_MODULE_RSYM(XDrawLine)
        LIBRARY_MODULE_RSYM(XDrawLines)
        LIBRARY_MODULE_RSYM(XDrawPoint)
        LIBRARY_MODULE_RSYM(XDrawPoints)
        LIBRARY_MODULE_RSYM(XDrawRectangle)
        LIBRARY_MODULE_RSYM(XDrawRectangles)
        LIBRARY_MODULE_RSYM(XDrawSegments)
        LIBRARY_MODULE_RSYM(XDrawString)
        LIBRARY_MODULE_RSYM(XDrawString16)
        LIBRARY_MODULE_RSYM(XDrawText)
        LIBRARY_MODULE_RSYM(XDrawText16)
        LIBRARY_MODULE_RSYM(XEHeadOfExtensionList)
        LIBRARY_MODULE_RSYM(XEnableAccessControl)
        LIBRARY_MODULE_RSYM(XEventMaskOfScreen)
        LIBRARY_MODULE_RSYM(XEventsQueued)
        LIBRARY_MODULE_RSYM(XExtendedMaxRequestSize)
        LIBRARY_MODULE_RSYM(XExtentsOfFontSet)
        LIBRARY_MODULE_RSYM(XFetchBuffer)
        LIBRARY_MODULE_RSYM(XFetchBytes)
        LIBRARY_MODULE_RSYM(XFetchName)
        LIBRARY_MODULE_RSYM(XFillArc)
        LIBRARY_MODULE_RSYM(XFillArcs)
        LIBRARY_MODULE_RSYM(XFillPolygon)
        LIBRARY_MODULE_RSYM(XFillRectangle)
        LIBRARY_MODULE_RSYM(XFillRectangles)
        LIBRARY_MODULE_RSYM(XFilterEvent)
        LIBRARY_MODULE_RSYM(XFindOnExtensionList)
        LIBRARY_MODULE_RSYM(XFlush)
        LIBRARY_MODULE_RSYM(XFlushGC)
        LIBRARY_MODULE_RSYM(XFontsOfFontSet)
        LIBRARY_MODULE_RSYM(XForceScreenSaver)
        LIBRARY_MODULE_RSYM(XFree)
        LIBRARY_MODULE_RSYM(XFreeColormap)
        LIBRARY_MODULE_RSYM(XFreeColors)
        LIBRARY_MODULE_RSYM(XFreeCursor)
        LIBRARY_MODULE_RSYM(XFreeEventData)
        LIBRARY_MODULE_RSYM(XFreeExtensionList)
        LIBRARY_MODULE_RSYM(XFreeFont)
        LIBRARY_MODULE_RSYM(XFreeFontInfo)
        LIBRARY_MODULE_RSYM(XFreeFontNames)
        LIBRARY_MODULE_RSYM(XFreeFontPath)
        LIBRARY_MODULE_RSYM(XFreeFontSet)
        LIBRARY_MODULE_RSYM(XFreeGC)
        LIBRARY_MODULE_RSYM(XFreeModifiermap)
        LIBRARY_MODULE_RSYM(XFreePixmap)
        LIBRARY_MODULE_RSYM(XFreeStringList)
        LIBRARY_MODULE_RSYM(XFreeThreads)
        LIBRARY_MODULE_RSYM(XGContextFromGC)
        LIBRARY_MODULE_RSYM(XGeometry)
        LIBRARY_MODULE_RSYM(XGetAtomName)
        LIBRARY_MODULE_RSYM(XGetAtomNames)
        LIBRARY_MODULE_RSYM(XGetCommand)
        LIBRARY_MODULE_RSYM(XGetDefault)
        LIBRARY_MODULE_RSYM(XGetErrorDatabaseText)
        LIBRARY_MODULE_RSYM(XGetErrorText)
        LIBRARY_MODULE_RSYM(XGetEventData)
        LIBRARY_MODULE_RSYM(XGetFontPath)
        LIBRARY_MODULE_RSYM(XGetFontProperty)
        LIBRARY_MODULE_RSYM(XGetGCValues)
        LIBRARY_MODULE_RSYM(XGetGeometry)
        LIBRARY_MODULE_RSYM(XGetIconName)
        LIBRARY_MODULE_RSYM(XGetICValues)
        LIBRARY_MODULE_RSYM(XGetImage)
        LIBRARY_MODULE_RSYM(XGetIMValues)
        LIBRARY_MODULE_RSYM(XGetInputFocus)
        LIBRARY_MODULE_RSYM(XGetKeyboardControl)
        LIBRARY_MODULE_RSYM(XGetKeyboardMapping)
        LIBRARY_MODULE_RSYM(XGetModifierMapping)
        LIBRARY_MODULE_RSYM(XGetMotionEvents)
        LIBRARY_MODULE_RSYM(XGetOCValues)
        LIBRARY_MODULE_RSYM(XGetOMValues)
        LIBRARY_MODULE_RSYM(XGetPointerControl)
        LIBRARY_MODULE_RSYM(XGetPointerMapping)
        LIBRARY_MODULE_RSYM(XGetScreenSaver)
        LIBRARY_MODULE_RSYM(XGetSelectionOwner)
        LIBRARY_MODULE_RSYM(XGetSubImage)
        LIBRARY_MODULE_RSYM(XGetTransientForHint)
        LIBRARY_MODULE_RSYM(XGetWindowAttributes)
        LIBRARY_MODULE_RSYM(XGetWindowProperty)
        LIBRARY_MODULE_RSYM(XGetWMColormapWindows)
        LIBRARY_MODULE_RSYM(XGetWMProtocols)
        LIBRARY_MODULE_RSYM(XGrabButton)
        LIBRARY_MODULE_RSYM(XGrabKey)
        LIBRARY_MODULE_RSYM(XGrabKeyboard)
        LIBRARY_MODULE_RSYM(XGrabPointer)
        LIBRARY_MODULE_RSYM(XGrabServer)
        LIBRARY_MODULE_RSYM(XHeightMMOfScreen)
        LIBRARY_MODULE_RSYM(XHeightOfScreen)
        LIBRARY_MODULE_RSYM(XIconifyWindow)
        LIBRARY_MODULE_RSYM(XIfEvent)
        LIBRARY_MODULE_RSYM(XImageByteOrder)
        LIBRARY_MODULE_RSYM(XIMOfIC)
        LIBRARY_MODULE_RSYM(XInitExtension)
        LIBRARY_MODULE_RSYM(XInitImage)
        LIBRARY_MODULE_RSYM(XInitThreads)
        LIBRARY_MODULE_RSYM(XInsertModifiermapEntry)
        LIBRARY_MODULE_RSYM(XInstallColormap)
        LIBRARY_MODULE_RSYM(XInternalConnectionNumbers)
        LIBRARY_MODULE_RSYM(XInternAtom)
        LIBRARY_MODULE_RSYM(XInternAtoms)
        LIBRARY_MODULE_RSYM(XKeycodeToKeysym)
        LIBRARY_MODULE_RSYM(XKeysymToKeycode)
        LIBRARY_MODULE_RSYM(XKeysymToString)
        LIBRARY_MODULE_RSYM(XKillClient)
        LIBRARY_MODULE_RSYM(XLastKnownRequestProcessed)
        LIBRARY_MODULE_RSYM(XListDepths)
        LIBRARY_MODULE_RSYM(XListExtensions)
        LIBRARY_MODULE_RSYM(XListFonts)
        LIBRARY_MODULE_RSYM(XListFontsWithInfo)
        LIBRARY_MODULE_RSYM(XListHosts)
        LIBRARY_MODULE_RSYM(XListInstalledColormaps)
        LIBRARY_MODULE_RSYM(XListPixmapFormats)
        LIBRARY_MODULE_RSYM(XListProperties)
        LIBRARY_MODULE_RSYM(XLoadFont)
        LIBRARY_MODULE_RSYM(XLoadQueryFont)
        LIBRARY_MODULE_RSYM(XLocaleOfFontSet)
        LIBRARY_MODULE_RSYM(XLocaleOfIM)
        LIBRARY_MODULE_RSYM(XLocaleOfOM)
        LIBRARY_MODULE_RSYM(XLockDisplay)
        LIBRARY_MODULE_RSYM(XLookupColor)
        LIBRARY_MODULE_RSYM(XLookupKeysym)
        LIBRARY_MODULE_RSYM(XLowerWindow)
        LIBRARY_MODULE_RSYM(XMapRaised)
        LIBRARY_MODULE_RSYM(XMapSubwindows)
        LIBRARY_MODULE_RSYM(XMapWindow)
        LIBRARY_MODULE_RSYM(XMaskEvent)
        LIBRARY_MODULE_RSYM(XMaxCmapsOfScreen)
        LIBRARY_MODULE_RSYM(XMaxRequestSize)
        LIBRARY_MODULE_RSYM(XmbDrawImageString)
        LIBRARY_MODULE_RSYM(XmbDrawString)
        LIBRARY_MODULE_RSYM(XmbDrawText)
        LIBRARY_MODULE_RSYM(XmbLookupString)
        LIBRARY_MODULE_RSYM(XmbResetIC)
        LIBRARY_MODULE_RSYM(XmbTextEscapement)
        LIBRARY_MODULE_RSYM(XmbTextExtents)
        LIBRARY_MODULE_RSYM(XmbTextPerCharExtents)
        LIBRARY_MODULE_RSYM(XMinCmapsOfScreen)
        LIBRARY_MODULE_RSYM(XMoveResizeWindow)
        LIBRARY_MODULE_RSYM(XMoveWindow)
        LIBRARY_MODULE_RSYM(XNewModifiermap)
        LIBRARY_MODULE_RSYM(XNextEvent)
        LIBRARY_MODULE_RSYM(XNextRequest)
        LIBRARY_MODULE_RSYM(XNoOp)
        LIBRARY_MODULE_RSYM(XOMOfOC)
        LIBRARY_MODULE_RSYM(XOpenDisplay)
        LIBRARY_MODULE_RSYM(XOpenIM)
        LIBRARY_MODULE_RSYM(XOpenOM)
        LIBRARY_MODULE_RSYM(XParseColor)
        LIBRARY_MODULE_RSYM(XParseGeometry)
        LIBRARY_MODULE_RSYM(XPeekEvent)
        LIBRARY_MODULE_RSYM(XPeekIfEvent)
        LIBRARY_MODULE_RSYM(XPending)
        LIBRARY_MODULE_RSYM(XPlanesOfScreen)
        LIBRARY_MODULE_RSYM(XProcessInternalConnection)
        LIBRARY_MODULE_RSYM(XProtocolRevision)
        LIBRARY_MODULE_RSYM(XProtocolVersion)
        LIBRARY_MODULE_RSYM(XPutBackEvent)
        LIBRARY_MODULE_RSYM(XPutImage)
        LIBRARY_MODULE_RSYM(XQLength)
        LIBRARY_MODULE_RSYM(XQueryBestCursor)
        LIBRARY_MODULE_RSYM(XQueryBestSize)
        LIBRARY_MODULE_RSYM(XQueryBestStipple)
        LIBRARY_MODULE_RSYM(XQueryBestTile)
        LIBRARY_MODULE_RSYM(XQueryColor)
        LIBRARY_MODULE_RSYM(XQueryColors)
        LIBRARY_MODULE_RSYM(XQueryExtension)
        LIBRARY_MODULE_RSYM(XQueryFont)
        LIBRARY_MODULE_RSYM(XQueryKeymap)
        LIBRARY_MODULE_RSYM(XQueryPointer)
        LIBRARY_MODULE_RSYM(XQueryTextExtents)
        LIBRARY_MODULE_RSYM(XQueryTextExtents16)
        LIBRARY_MODULE_RSYM(XQueryTree)
        LIBRARY_MODULE_RSYM(XRaiseWindow)
        LIBRARY_MODULE_RSYM(XReadBitmapFile)
        LIBRARY_MODULE_RSYM(XReadBitmapFileData)
        LIBRARY_MODULE_RSYM(XRebindKeysym)
        LIBRARY_MODULE_RSYM(XRecolorCursor)
        LIBRARY_MODULE_RSYM(XReconfigureWMWindow)
        LIBRARY_MODULE_RSYM(XRefreshKeyboardMapping)
        LIBRARY_MODULE_RSYM(XRegisterIMInstantiateCallback)
        LIBRARY_MODULE_RSYM(XRemoveConnectionWatch)
        LIBRARY_MODULE_RSYM(XRemoveFromSaveSet)
        LIBRARY_MODULE_RSYM(XRemoveHost)
        LIBRARY_MODULE_RSYM(XRemoveHosts)
        LIBRARY_MODULE_RSYM(XReparentWindow)
        LIBRARY_MODULE_RSYM(XResetScreenSaver)
        LIBRARY_MODULE_RSYM(XResizeWindow)
        LIBRARY_MODULE_RSYM(XResourceManagerString)
        LIBRARY_MODULE_RSYM(XRestackWindows)
        LIBRARY_MODULE_RSYM(XrmInitialize)
        LIBRARY_MODULE_RSYM(XrmUniqueQuark)
        LIBRARY_MODULE_RSYM(XRootWindow)
        LIBRARY_MODULE_RSYM(XRootWindowOfScreen)
        LIBRARY_MODULE_RSYM(XRotateBuffers)
        LIBRARY_MODULE_RSYM(XRotateWindowProperties)
        LIBRARY_MODULE_RSYM(XScreenCount)
        LIBRARY_MODULE_RSYM(XScreenNumberOfScreen)
        LIBRARY_MODULE_RSYM(XScreenOfDisplay)
        LIBRARY_MODULE_RSYM(XScreenResourceString)
        LIBRARY_MODULE_RSYM(XSelectInput)
        LIBRARY_MODULE_RSYM(XSendEvent)
        LIBRARY_MODULE_RSYM(XServerVendor)
        LIBRARY_MODULE_RSYM(XSetAccessControl)
        LIBRARY_MODULE_RSYM(XSetArcMode)
        LIBRARY_MODULE_RSYM(XSetAuthorization)
        LIBRARY_MODULE_RSYM(XSetBackground)
        LIBRARY_MODULE_RSYM(XSetClipMask)
        LIBRARY_MODULE_RSYM(XSetClipOrigin)
        LIBRARY_MODULE_RSYM(XSetClipRectangles)
        LIBRARY_MODULE_RSYM(XSetCloseDownMode)
        LIBRARY_MODULE_RSYM(XSetCommand)
        LIBRARY_MODULE_RSYM(XSetDashes)
        LIBRARY_MODULE_RSYM(XSetErrorHandler)
        LIBRARY_MODULE_RSYM(XSetFillRule)
        LIBRARY_MODULE_RSYM(XSetFillStyle)
        LIBRARY_MODULE_RSYM(XSetFont)
        LIBRARY_MODULE_RSYM(XSetFontPath)
        LIBRARY_MODULE_RSYM(XSetForeground)
        LIBRARY_MODULE_RSYM(XSetFunction)
        LIBRARY_MODULE_RSYM(XSetGraphicsExposures)
        LIBRARY_MODULE_RSYM(XSetICFocus)
        LIBRARY_MODULE_RSYM(XSetIconName)
        LIBRARY_MODULE_RSYM(XSetICValues)
        LIBRARY_MODULE_RSYM(XSetIMValues)
        LIBRARY_MODULE_RSYM(XSetInputFocus)
        LIBRARY_MODULE_RSYM(XSetIOErrorExitHandler)
        LIBRARY_MODULE_RSYM(XSetIOErrorHandler)
        LIBRARY_MODULE_RSYM(XSetLineAttributes)
        LIBRARY_MODULE_RSYM(XSetLocaleModifiers)
        LIBRARY_MODULE_RSYM(XSetModifierMapping)
        LIBRARY_MODULE_RSYM(XSetOCValues)
        LIBRARY_MODULE_RSYM(XSetOMValues)
        LIBRARY_MODULE_RSYM(XSetPlaneMask)
        LIBRARY_MODULE_RSYM(XSetPointerMapping)
        LIBRARY_MODULE_RSYM(XSetScreenSaver)
        LIBRARY_MODULE_RSYM(XSetSelectionOwner)
        LIBRARY_MODULE_RSYM(XSetState)
        LIBRARY_MODULE_RSYM(XSetStipple)
        LIBRARY_MODULE_RSYM(XSetSubwindowMode)
        LIBRARY_MODULE_RSYM(XSetTile)
        LIBRARY_MODULE_RSYM(XSetTransientForHint)
        LIBRARY_MODULE_RSYM(XSetTSOrigin)
        LIBRARY_MODULE_RSYM(XSetWindowBackground)
        LIBRARY_MODULE_RSYM(XSetWindowBackgroundPixmap)
        LIBRARY_MODULE_RSYM(XSetWindowBorder)
        LIBRARY_MODULE_RSYM(XSetWindowBorderPixmap)
        LIBRARY_MODULE_RSYM(XSetWindowBorderWidth)
        LIBRARY_MODULE_RSYM(XSetWindowColormap)
        LIBRARY_MODULE_RSYM(XSetWMColormapWindows)
        LIBRARY_MODULE_RSYM(XSetWMProtocols)
        LIBRARY_MODULE_RSYM(XStoreBuffer)
        LIBRARY_MODULE_RSYM(XStoreBytes)
        LIBRARY_MODULE_RSYM(XStoreColor)
        LIBRARY_MODULE_RSYM(XStoreColors)
        LIBRARY_MODULE_RSYM(XStoreName)
        LIBRARY_MODULE_RSYM(XStoreNamedColor)
        LIBRARY_MODULE_RSYM(XStringToKeysym)
        LIBRARY_MODULE_RSYM(XSupportsLocale)
        LIBRARY_MODULE_RSYM(XSync)
        LIBRARY_MODULE_RSYM(XTextExtents)
        LIBRARY_MODULE_RSYM(XTextExtents16)
        LIBRARY_MODULE_RSYM(XTextWidth)
        LIBRARY_MODULE_RSYM(XTextWidth16)
        LIBRARY_MODULE_RSYM(XTranslateCoordinates)
        LIBRARY_MODULE_RSYM(XUndefineCursor)
        LIBRARY_MODULE_RSYM(XUngrabButton)
        LIBRARY_MODULE_RSYM(XUngrabKey)
        LIBRARY_MODULE_RSYM(XUngrabKeyboard)
        LIBRARY_MODULE_RSYM(XUngrabPointer)
        LIBRARY_MODULE_RSYM(XUngrabServer)
        LIBRARY_MODULE_RSYM(XUninstallColormap)
        LIBRARY_MODULE_RSYM(XUnloadFont)
        LIBRARY_MODULE_RSYM(XUnlockDisplay)
        LIBRARY_MODULE_RSYM(XUnmapSubwindows)
        LIBRARY_MODULE_RSYM(XUnmapWindow)
        LIBRARY_MODULE_RSYM(XUnregisterIMInstantiateCallback)
        LIBRARY_MODULE_RSYM(XUnsetICFocus)
        LIBRARY_MODULE_RSYM(Xutf8DrawImageString)
        LIBRARY_MODULE_RSYM(Xutf8DrawString)
        LIBRARY_MODULE_RSYM(Xutf8DrawText)
        LIBRARY_MODULE_RSYM(Xutf8LookupString)
        LIBRARY_MODULE_RSYM(Xutf8ResetIC)
        LIBRARY_MODULE_RSYM(Xutf8TextEscapement)
        LIBRARY_MODULE_RSYM(Xutf8TextExtents)
        LIBRARY_MODULE_RSYM(Xutf8TextPerCharExtents)
        LIBRARY_MODULE_RSYM(XVaCreateNestedList)
        LIBRARY_MODULE_RSYM(XVendorRelease)
        LIBRARY_MODULE_RSYM(XVisualIDFromVisual)
        LIBRARY_MODULE_RSYM(XWarpPointer)
        LIBRARY_MODULE_RSYM(XwcDrawImageString)
        LIBRARY_MODULE_RSYM(XwcDrawString)
        LIBRARY_MODULE_RSYM(XwcDrawText)
        LIBRARY_MODULE_RSYM(XwcLookupString)
        LIBRARY_MODULE_RSYM(XwcResetIC)
        LIBRARY_MODULE_RSYM(XwcTextEscapement)
        LIBRARY_MODULE_RSYM(XwcTextExtents)
        LIBRARY_MODULE_RSYM(XwcTextPerCharExtents)
        LIBRARY_MODULE_RSYM(XWhitePixel)
        LIBRARY_MODULE_RSYM(XWhitePixelOfScreen)
        LIBRARY_MODULE_RSYM(XWidthMMOfScreen)
        LIBRARY_MODULE_RSYM(XWidthOfScreen)
        LIBRARY_MODULE_RSYM(XWindowEvent)
        LIBRARY_MODULE_RSYM(XWithdrawWindow)
        LIBRARY_MODULE_RSYM(XWriteBitmapFile)
        // #include <X11/Xutil.h>
        LIBRARY_MODULE_RSYM(XDestroyImage)
        LIBRARY_MODULE_RSYM(XGetPixel)
        LIBRARY_MODULE_RSYM(XPutPixel)
        LIBRARY_MODULE_RSYM(XSubImage)
        LIBRARY_MODULE_RSYM(XAddPixel)
        LIBRARY_MODULE_RSYM(XAllocClassHint)
        LIBRARY_MODULE_RSYM(XAllocIconSize)
        LIBRARY_MODULE_RSYM(XAllocSizeHints)
        LIBRARY_MODULE_RSYM(XAllocStandardColormap)
        LIBRARY_MODULE_RSYM(XAllocWMHints)
        LIBRARY_MODULE_RSYM(XClipBox)
        LIBRARY_MODULE_RSYM(XCreateRegion)
        LIBRARY_MODULE_RSYM(XDefaultString)
        LIBRARY_MODULE_RSYM(XDeleteContext)
        LIBRARY_MODULE_RSYM(XDestroyRegion)
        LIBRARY_MODULE_RSYM(XEmptyRegion)
        LIBRARY_MODULE_RSYM(XEqualRegion)
        LIBRARY_MODULE_RSYM(XFindContext)
        LIBRARY_MODULE_RSYM(XGetClassHint)
        LIBRARY_MODULE_RSYM(XGetIconSizes)
        LIBRARY_MODULE_RSYM(XGetNormalHints)
        LIBRARY_MODULE_RSYM(XGetRGBColormaps)
        LIBRARY_MODULE_RSYM(XGetSizeHints)
        LIBRARY_MODULE_RSYM(XGetStandardColormap)
        LIBRARY_MODULE_RSYM(XGetTextProperty)
        LIBRARY_MODULE_RSYM(XGetVisualInfo)
        LIBRARY_MODULE_RSYM(XGetWMClientMachine)
        LIBRARY_MODULE_RSYM(XGetWMHints)
        LIBRARY_MODULE_RSYM(XGetWMIconName)
        LIBRARY_MODULE_RSYM(XGetWMName)
        LIBRARY_MODULE_RSYM(XGetWMNormalHints)
        LIBRARY_MODULE_RSYM(XGetWMSizeHints)
        LIBRARY_MODULE_RSYM(XGetZoomHints)
        LIBRARY_MODULE_RSYM(XIntersectRegion)
        LIBRARY_MODULE_RSYM(XConvertCase)
        LIBRARY_MODULE_RSYM(XLookupString)
        LIBRARY_MODULE_RSYM(XMatchVisualInfo)
        LIBRARY_MODULE_RSYM(XOffsetRegion)
        LIBRARY_MODULE_RSYM(XPointInRegion)
        LIBRARY_MODULE_RSYM(XPolygonRegion)
        LIBRARY_MODULE_RSYM(XRectInRegion)
        LIBRARY_MODULE_RSYM(XSaveContext)
        LIBRARY_MODULE_RSYM(XSetClassHint)
        LIBRARY_MODULE_RSYM(XSetIconSizes)
        LIBRARY_MODULE_RSYM(XSetNormalHints)
        LIBRARY_MODULE_RSYM(XSetRGBColormaps)
        LIBRARY_MODULE_RSYM(XSetSizeHints)
        LIBRARY_MODULE_RSYM(XSetStandardProperties)
        LIBRARY_MODULE_RSYM(XSetTextProperty)
        LIBRARY_MODULE_RSYM(XSetWMClientMachine)
        LIBRARY_MODULE_RSYM(XSetWMHints)
        LIBRARY_MODULE_RSYM(XSetWMIconName)
        LIBRARY_MODULE_RSYM(XSetWMName)
        LIBRARY_MODULE_RSYM(XSetWMNormalHints)
        LIBRARY_MODULE_RSYM(XSetWMProperties)
        LIBRARY_MODULE_RSYM(XmbSetWMProperties)
        LIBRARY_MODULE_RSYM(Xutf8SetWMProperties)
        LIBRARY_MODULE_RSYM(XSetWMSizeHints)
        LIBRARY_MODULE_RSYM(XSetRegion)
        LIBRARY_MODULE_RSYM(XSetStandardColormap)
        LIBRARY_MODULE_RSYM(XSetZoomHints)
        LIBRARY_MODULE_RSYM(XShrinkRegion)
        LIBRARY_MODULE_RSYM(XStringListToTextProperty)
        LIBRARY_MODULE_RSYM(XSubtractRegion)
        LIBRARY_MODULE_RSYM(XmbTextListToTextProperty)
        LIBRARY_MODULE_RSYM(XwcTextListToTextProperty)
        LIBRARY_MODULE_RSYM(Xutf8TextListToTextProperty)
        LIBRARY_MODULE_RSYM(XwcFreeStringList)
        LIBRARY_MODULE_RSYM(XTextPropertyToStringList)
        LIBRARY_MODULE_RSYM(XmbTextPropertyToTextList)
        LIBRARY_MODULE_RSYM(XwcTextPropertyToTextList)
        LIBRARY_MODULE_RSYM(Xutf8TextPropertyToTextList)
        LIBRARY_MODULE_RSYM(XUnionRectWithRegion)
        LIBRARY_MODULE_RSYM(XUnionRegion)
        LIBRARY_MODULE_RSYM(XWMGeometry)
        LIBRARY_MODULE_RSYM(XXorRegion)
        return true;
    }
    return false;
}

// -------------------------------------------------------------------------------------------------------------------------- //