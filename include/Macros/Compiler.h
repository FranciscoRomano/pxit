// ---------------------------------------------------------------------------------------------- //
// The MIT License (MIT)
// 
// Copyright (c) 2024 Francisco Romano
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
#ifndef __Macros_Compilers_h__
#define __Macros_Compilers_h__ 1
// ---------------------------------------------------------------------------------------------- //
#if defined(__clang__)
  #define COMPILER_CLANG 1
  #define COMPILER_VERSION_NAME "Clang"
  #define COMPILER_VERSION ((((unsigned int)__clang_major__) << 22)\
                           |(((unsigned int)__clang_minor__) << 12))
#elif defined(__GNUC__)
  #define COMPILER_GCC 1
  #define COMPILER_VERSION_NAME "GCC C/C++"
  #define COMPILER_VERSION ((((unsigned int)__GNUC__)       << 22)\
                           |(((unsigned int)__GNUC_MINOR__) << 12))
#elif defined(_MSC_VER)
  #define COMPILER_MSVC 1
  #define COMPILER_VERSION_NAME "Microsoft Visual C++ (MSVC)"
  #define COMPILER_VERSION _MSC_VER
#elif defined(__MINGW32__)
  #define COMPILER_MINGW 1
  #define COMPILER_VERSION_NAME "MinGW"
  #define COMPILER_VERSION ((((unsigned int)__MINGW32_MAJOR_VERSION) << 22)\
                           |(((unsigned int)__MINGW32_MINOR_VERSION) << 12))
#elif defined(__MINGW64__)
  #define COMPILER_MINGW 1
  #define COMPILER_VERSION_NAME "MinGW-w64"
  #define COMPILER_VERSION ((((unsigned int)__MINGW64_MAJOR_VERSION) << 22)\
                           |(((unsigned int)__MINGW64_MINOR_VERSION) << 12))
#endif
// ---------------------------------------------------------------------------------------------- //
#endif//__Macros_Compilers_h__
// ---------------------------------------------------------------------------------------------- //