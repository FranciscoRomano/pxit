// ------------------------------------------------------------------------------ //
// The MIT License (MIT)                                                          //
//                                                                                //
// Copyright (c) 2024, Francisco Romano                                           //
//                                                                                //
// Permission is hereby granted, free of charge, to any person obtaining a copy   //
// of this software and associated documentation files (the "Software"), to deal  //
// in the Software without restriction, including without limitation the rights   //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      //
// copies of the Software, and to permit persons to whom the Software is          //
// furnished to do so, subject to the following conditions:                       //
//                                                                                //
// The above copyright notice and this permission notice shall be included in all //
// copies or substantial portions of the Software.                                //
//                                                                                //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    //
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  //
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  //
// SOFTWARE.                                                                      //
// ------------------------------------------------------------------------------ //
#pragma once
#include <stdint.h>
#include <initializer_list>
#include <vector>

namespace std
{
    template<class T>
    class buffer final
    {
    public:
        constexpr buffer() = default;

        template<class It>
        buffer(const std::vector<It>& source, size_t offset, size_t stride)
        {
            m_first = ((uint8_t*)source.data()) + offset;
            m_count = (source.size() * sizeof(It)) / stride;
            m_block = stride;
        };

        const size_t size() const
        {
            return m_count;
        }

        T& operator[](const size_t& position)
        {
            return *(T*)(m_first + m_block * position);
        }

        const T& operator[](const size_t& position) const
        {
            return *(T*)(m_first + m_block * position);
        }
    private:
        uint8_t* m_first = nullptr;
        size_t   m_count = 0;
        size_t   m_block = 0;
    };
}