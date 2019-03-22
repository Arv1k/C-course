#include "vector.h"

Vector::Vector():
    data_(nullptr),
    capacity_(0),
    size_(0) {}

Vector::~Vector() {
    delete [] data_;
    data_ = nullptr;
    capacity_ = yad_capacity;
    size_ = yad_size;
}

Vector::Vector(size_t cap):
    data_(new int [cap]),
    capacity_(cap),
    size_(0) {}

int& Vector::at(size_t index) {
    assert(0 <= index && index <= capacity_);

    return data_[index];
}

int& Vector::operator[](size_t index) {
    return at(index);
}

void Vector::swap(Vector& that) {
    int* tmp_data = data_;
    data_ = that.data_;
    that.data_ = tmp_data;

    size_t tmp_cap = capacity_;
    capacity_ = that.capacity_;
    that.capacity_ = tmp_cap;

    size_t tmp_size = size_;
    size_ = that.size_;
    that.size_ = tmp_size;
}

void Vector::operator=(const Vector& that) {
    Vector tmp;
    tmp.copy(that);
    swap(tmp);
}

void Vector::copy(const Vector& that) {
    delete [] data_;

    data_ = new int [that.capacity_];
    memcpy(data_, that.data_, sizeof(*that.data_) * that.size_);

    capacity_ = that.capacity_;
    size_ = that.size_;
}


/*
void* Vector::operator new(size_t size, size_t line) {
    fprintf(stdout, "object, line %lu", line);

    return malloc(size);
}*/
