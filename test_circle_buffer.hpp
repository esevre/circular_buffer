//
// Created by Erik Sevre on 9/20/17.
//

#ifndef CIRCULAR_BUFFER_TEST_CIRCLE_BUFFER_HPP
#define CIRCULAR_BUFFER_TEST_CIRCLE_BUFFER_HPP

#include <iostream>
#include "circle_buffer_abstract.hpp"

//
// this buffer must be passed as non-const for the tests
//
int test(cbuff &buf, bool verbose=true) {
    int retval = 0;
    //array_buffer::CircularBuffer<10> buf; // circular buffer of size 10

    if (buf.count() == 0) {
        if (verbose) {
            std::cout << "0 - Pass: Buffer correctly has 0 elements in it when created\n";
        }
    } else {
        if (verbose) {
            std::cout << "0 - Fail: Buffer has non-zero number of elements in it when created\n";
        }
        ++retval;
    }
//    if (buf.empty()) {
//        if (verbose) {
//            std::cout << "0.1 - Pass: Buffer correctly identified as empty at creation\n";
//        }
//    } else {
//        if (verbose) {
//            std::cout << "0 - Fail: Buffer not correctly identified as empty at creation\n";
//        }
//        ++retval;
//    }
    std::string hello = "hello";
    for (char c : hello) {
        buf.add(c);
    }
    if (buf.count() == hello.size()) {
        if (verbose) {
            std::cout << "1 - Pass: Buffer correctly has 5 elements in it after adding hello\n";
        }
    } else {
        if (verbose) {
            std::cout << "1 - Fail: Buffer has " << buf.count () << " elements it it after adding hello, should be 5\n";
        }
        ++retval;
    }
    char taken = buf.remove();
    if (taken == 'h') {
        if (verbose) {
            std::cout << "2 - Pass: h was removed from buffer\n";
        }
    } else {
        if (verbose) {
            std::cout << "2 - Fail: tried to remove first character, should have been 'h', but got '" << taken << "'\n";
        }
        ++retval;
    }
    std::string world = "world";
    bool allAdded = true;
    for (char c : world) {
        if (buf.full()) {
            allAdded = false;
        } else {
            buf.add(c);
        }
    }
    if (allAdded) {
        if (verbose) {
            std::cout << "3 - Pass: world was added\n";
        }
    } else {
        if (verbose) {
            std::cout << "3 - Fail: tried to add world, but the buffer said it was full\n";
        }
        ++retval;
    }
    std::string shouldMatch = "elloworld";
    std::string itwas;
    while (buf.count() > 0 && itwas.size() < 9) {
        itwas.push_back(buf.remove());
    }
    if (itwas == shouldMatch) {
        if (verbose) {
            std::cout << "4 - Pass: elloworld was removed\n";
        }
    } else {
        if (verbose) {
            std::cout << "4 - Fail: tried to remove elloworld, got " << itwas << '\n';
        }
        ++retval;
    }

    return retval;
}

#endif //CIRCULAR_BUFFER_TEST_CIRCLE_BUFFER_HPP
