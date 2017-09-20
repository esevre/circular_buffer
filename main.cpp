/*
 *  Created by Erik Sevre on 9/20/17.
 *    Doctoral Student in Computational Science and Technology
 *    Seoul National University
 *
 *
 *  My answer to a post in C++ OpenSource Study (A Korean Facebook C++ community)
 *
 *  Main function was provided, I wrote a curcle_buffer class to fulfill the requirements.
 */


#include <iostream>
#include <string>
#include "circle_buffer.hpp"
#include "circle_buffer_array.hpp"
#include "test_circle_buffer.hpp"

int main() {

    // Run test on buffer using std::array
    {
        array_buffer::CircularBuffer<10> buf_array; // circular buffer of size 10
        std::cout << "Testing Array Buffer\n\n";
        test(buf_array);
        std::cout << "\n\n*****     Testing Finished     *****\n\n";
    }

    // Run test on buffer using std::vector
    {
        vector_buffer::CircularBuffer buf_vector(10);
        std::cout << "Testing Vector Buffer\n\n";
        test(buf_vector);
        std::cout << "\n\n*****     Testing Finished     *****\n\n";

    }


}
