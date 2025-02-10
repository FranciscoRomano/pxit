// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE, WHICH IS SHOWN BELOW: │
// └───────────────────────────────────────────────────────────────────────────────────────────┘
// 
// Copyright (c) 1999  The XFree86 Project Inc.
// 
// All Rights Reserved.
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
// AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// Except as contained in this notice, the name of The XFree86 Project
// Inc. shall not be used in advertising or otherwise to promote the
// sale, use or other dealings in this Software without prior written
// authorization from The XFree86 Project Inc..

#ifndef _X11_Xdefs_h_
#define _X11_Xdefs_h_

#include <stdint.h>

// Types definitions shared between server and clients
typedef uint32_t XAtom;
typedef int      XBool;
typedef uint32_t XID;
typedef uint32_t XMask;
typedef XID      XFont;

#endif// _X11_Xdefs_h_