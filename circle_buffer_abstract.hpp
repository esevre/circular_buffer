//
// Created by Erik Sevre on 9/20/17.
//
// Pure abstract circle buffer class to enable testing of various circle buffers
//

#ifndef CIRCULAR_BUFFER_CIRCLE_BUFFER_ABSTRACT_HPP
#define CIRCULAR_BUFFER_CIRCLE_BUFFER_ABSTRACT_HPP

//
//  Abstract Circle Buffer for creating functions to test multiple buffers for comparison
//
class cbuff {
public:
    virtual unsigned long count() const = 0;
    virtual bool full() const = 0;
    //virtual bool empty() const = 0;
    virtual void add(char) = 0;
    virtual char remove() = 0;
};


#endif //CIRCULAR_BUFFER_CIRCLE_BUFFER_ABSTRACT_HPP
