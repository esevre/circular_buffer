//
// Created by Erik Sevre on 9/20/17.
//

#ifndef CIRCULAR_BUFFER_CIRCLE_BUFFER_ARRAY_HPP
#define CIRCULAR_BUFFER_CIRCLE_BUFFER_ARRAY_HPP


#include <array>
#include "circle_buffer_abstract.hpp"

namespace array_buffer {
    template <int size>
    class CircularBuffer : public cbuff {
    private:
        //const size_t size;
        std::array<char, size> buffer;
        size_t head = 0; // index at the head, where new elts are added to the buffer
        size_t tail = 0; // index to the tail, where old elts are removed

    public:
        CircularBuffer() {}
        unsigned long count() const {
            if (head >= tail) {
                return head - tail;
            }
            return head - tail + size;
        }
        bool full() const { return size == this->count(); }
        bool empty() const {return this->count() == 0; }
        void add(char c) {
            // todo: add check for full buffer
            buffer[head] = c;
            ++head;
            head%=size;
        }
        char remove() {
            // todo: add check for empty buffer
            char val = buffer[tail];
            ++tail;
            tail%=size;
            return val;
        }
    };
}


#endif //CIRCULAR_BUFFER_CIRCLE_BUFFER_ARRAY_HPP
