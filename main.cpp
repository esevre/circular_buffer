/*
 *  Created by Erik Sevre on 9/20/17.
 *    Doctoral Student in Computational Science and Technology
 *    Seoul National University
 *
 *
 *  My answer to a post in C++ OpenSource Study (A Korean Facebook C++ community)
 *
 *  Main function was provided, I wrote a circle_buffer class to fulfill the requirements.
 */


#include <iostream>
#include <chrono>
#include "circle_buffer.hpp"
#include "circle_buffer_array.hpp"
#include "circle_buffer_yu_wansang.hpp"
#include "test_circle_buffer.hpp"

int main() {
    // create chrono variables for timing in all scopes of this program
    std::chrono::time_point<std::chrono::system_clock> start, end;

    // Run test on buffer using std::array
    {
        start = std::chrono::system_clock::now();

        for (int i = 0; i < 100'000; ++i) {
            array_buffer::CircularBuffer<10> buffer; // circular buffer of size 10
            test(buffer, false);
        }

        end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    }

    // Run test on buffer using std::vector
    {

        start = std::chrono::system_clock::now();

        for (int i = 0; i < 100'000; ++i) {
            vector_buffer::CircularBuffer buffer(10);
            test(buffer, false);
        }

        end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;


    }

    // Run test on buffer using std::vector
    {

        start = std::chrono::system_clock::now();

        for (int i = 0; i < 100'000; ++i) {
            yu::CircularBuffer buffer(10);
            test(buffer, false);
        }

        end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;


    }


}
