//
// Created by Erik Sevre on 9/20/17.
//

#ifndef CIRCULAR_BUFFER_CIRCLE_BUFFER_YU_WANSANG_HPP
#define CIRCULAR_BUFFER_CIRCLE_BUFFER_YU_WANSANG_HPP

#include <vector>
#include "circle_buffer_abstract.hpp"


namespace yu{
    using vector = std::vector<char>;

    class CircularBuffer : public cbuff {
    public:
        CircularBuffer(size_t size)
                :_buffer{},_size{size}, _begin{0}, _end{1} {
            _buffer.reserve(size);
        };
        unsigned long count() const override {
            size_t ret = _size - (_end-1) + _begin;
            if (ret >= _size)
                ret -= _size;
            return ret;
        }
        bool full() const override {
            return _begin == _end;
        }
        void add(char data) override {
            if (!full()) {
                size_t _insert = _end;
                if (_insert == 0)
                    _insert = _size-1;
                else
                    --_insert;

                _buffer[_insert] = data;
                ++_end;
                _end -= (_end > _size)? _size:0;
            }
        }
        char remove() override {
            return _buffer[_begin++];
        }

    private:
        vector _buffer;
        size_t _size;

        size_t _begin;
        size_t _end;
    };
}

#endif //CIRCULAR_BUFFER_CIRCLE_BUFFER_YU_WANSANG_HPP
