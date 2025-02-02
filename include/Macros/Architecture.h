// ---------------------------------------------------------------------------------------------- //
// The MIT License (MIT)
// 
// Copyright (c) 2025 Francisco Romano
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ---------------------------------------------------------------------------------------------- //
#ifndef __Macros_Architecture_h__
#define __Macros_Architecture_h__ 1
// ---------------------------------------------------------------------------------------------- //
#if defined(i386)     ||\
    defined(__i386)   ||\
    defined(__i386__) ||\
    defined(_M_IX86)  ||\
    defined(_X86_)
  #define ARCHITECTURE_NAME "i386"
  #define ARCHITECTURE_I386  1
  #define ARCHITECTURE_32_BIT 1
#endif
// ---------------------------------------------------------------------------------------------- //
#if defined(__amd64)    ||\
    defined(__amd64__)  ||\
    defined(__x86_64)   ||\
    defined(__x86_64__) ||\
    defined(_M_AMD64)
  #define ARCHITECTURE_NAME "AMD64"
  #define ARCHITECTURE_AMD64 1
  #define ARCHITECTURE_64_BIT 1
#endif
// ---------------------------------------------------------------------------------------------- //
#if defined(__aarch64__) ||\
    defined(_M_ARM64)
  #define ARCHITECTURE_NAME "ARM64"
  #define ARCHITECTURE_ARM64 1
  #define ARCHITECTURE_64_BIT 1
#elif defined(__arm__)   ||\
    defined(__thumb__)   ||\
    defined(_ARM)        ||\
    defined(_M_ARM)      ||\
    defined(_M_ARMT)     ||\
    defined(__arm)
  #define ARCHITECTURE_NAME "ARM"
  #define ARCHITECTURE_ARM 1
  #define ARCHITECTURE_32_BIT 1
#endif
// ---------------------------------------------------------------------------------------------- //
#endif//__Macros_Architecture_h__
// ---------------------------------------------------------------------------------------------- //