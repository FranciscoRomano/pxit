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
#ifndef __Macros_OperatingSystems_h__
#define __Macros_OperatingSystems_h__ 1
// ---------------------------------------------------------------------------------------------- //
#if defined(__ANDROID__)
  #define OPERATING_SYSTEM_ANDROID 1
#elif defined(_WIN32) ||\
      defined(_WIN64)
  #define OPERATING_SYSTEM_WINDOWS 1
#elif defined(__APPLE__)
  #define OPERATING_SYSTEM_APPLE 1
#elif defined(linux)     ||\
      defined(__linux)   ||\
      defined(__linux__)
  #define OPERATING_SYSTEM_LINUX 1
#elif defined(__unix) ||\
      defined(__unix__)
  #define OPERATING_SYSTEM_UNIX 1
#endif
// ---------------------------------------------------------------------------------------------- //
#endif//__Macros_OperatingSystems_h__
// ---------------------------------------------------------------------------------------------- //