//
// Created by Erik Sevre on 9/20/17.
//

#ifndef CIRCULAR_BUFFER_CIRCLE_BUFFER_HPP
#define CIRCULAR_BUFFER_CIRCLE_BUFFER_HPP

/** TODO: 밑에 있는 코드를 구현 해야함! CircularBuffer here
*
* Its constructor should take the size of the buffer as an argument
*
* It needs to have the functions:
* - count() which returns how many things are in the buffer
* - full() which returns true iff the buffer is full
* - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
* - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
*/

#include <vector>
#include "circle_buffer_abstract.hpp"

namespace vector_buffer{

    class CircularBuffer : public cbuff {
    private:
        const size_t size;
        std::vector<char> buffer;
        size_t head = 0; // index at the head, where new elts are added to the buffer
        size_t tail = 0; // index to the tail, where old elts are removed

    public:
        explicit CircularBuffer(size_t size) : size(size), buffer(size) {}
        unsigned long count() const override {
            if (head >= tail) {
                return head - tail;
            }
            return head - tail + size;
        }
        bool full() const override { return this->size == this->count(); }
        bool empty() const  {return this->count() == 0; }
        void add(char c) override {
            // todo: add check for full buffer
            buffer[head] = c;
            ++head;
            head%=size;
        }
        char remove() override {
            // todo: add check for empty buffer
            char val = buffer[tail];
            ++tail;
            tail%=size;
            return val;
        }
    };
}


#endif //CIRCULAR_BUFFER_CIRCLE_BUFFER_HPP
