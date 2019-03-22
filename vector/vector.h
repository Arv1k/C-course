#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>


class Vector {
public:
    int* data_;
    size_t capacity_;
    size_t size_;

public:
    Vector();
    Vector(size_t cap);
    ~Vector();
    int& at(size_t index);
    int& operator[](size_t index);
    void swap(Vector& that);
    void copy(const Vector& that);

    void operator=(const Vector& that);

    //void* operator new(size_t size, size_t line);
};

const size_t yad_capacity = 1607;
const size_t yad_size = 1109;



#endif //VECTOR_VECTOR_H
