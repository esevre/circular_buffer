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

int main() {
    int retval = 0;
    CircularBuffer buf(10); // circular buffer of size 10
    if (buf.count() == 0) {
        std::cout << "0 - Pass: Buffer correctly has 0 elements in it when created\n";
    } else {
        std::cout << "0 - Fail: Buffer has non-zero number of elements in it when created\n";
        ++retval;
    }
    if (buf.empty()) {
        std::cout << "0.1 - Pass: Buffer correctly identified as empty at creation\n";
    } else {
        std::cout << "0 - Fail: Buffer not correctly identified as empty at creation\n";
        ++retval;
    }
    std::string hello = "hello";
    for (char c : hello) {
        buf.add(c);
    }
    if (buf.count() == hello.size()) {
        std::cout << "1 - Pass: Buffer correctly has 5 elements in it after adding hello\n";
    } else {
        std::cout << "1 - Fail: Buffer has " << buf.count () << " elements it it after adding hello, should be 5\n";
        ++retval;
    }
    char taken = buf.remove();
    if (taken == 'h') {
        std::cout << "2 - Pass: h was removed from buffer\n";
    } else {
        std::cout << "2 - Fail: tried to remove first character, should have been 'h', but got '" << taken << "'\n";
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
        std::cout << "3 - Pass: world was added\n";
    } else {
        std::cout << "3 - Fail: tried to add world, but the buffer said it was full\n";
        ++retval;
    }
    std::string shouldMatch = "elloworld";
    std::string itwas;
    while (buf.count() > 0 && itwas.size() < 9) {
        itwas.push_back(buf.remove());
    }
    if (itwas == shouldMatch) {
        std::cout << "4 - Pass: elloworld was removed\n";
    } else {
        std::cout << "4 - Fail: tried to remove elloworld, got " << itwas << '\n';
        ++retval;
    }
    return retval;
}
