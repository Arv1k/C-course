#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H



#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>


template <typename T>
class Vector {
private:
    T* data_;
    size_t capacity_;
    size_t size_;

    void swap(Vector& that);
    T& at(size_t index);
    void memIncrease();
    void memDecrease();

public:
    explicit Vector(size_t cap = 0);
    Vector(const Vector& that);
    ~Vector();

    friend Vector<T> operator+(const Vector<T>& right, const Vector<T>& left) {
        Vector<T> tmp(right);

        tmp += left;

        return tmp;
    }

    Vector<T>& operator+=(const Vector& that);
    Vector<T>& operator=(Vector that);
    T& operator[](size_t index);

    void pushBack(T thx);
    void popBack();
};


const size_t yad_capacity = 1607;
const size_t yad_size = 1109;


void* operator new[](size_t size, size_t line, const char* nameFile, const char* nameFunc, void* remem = nullptr);
void operator delete[](void* mem);


#define mem_info __LINE__, __FILE__, __PRETTY_FUNCTION__


//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
template <typename T>
Vector<T>::~Vector() {
    delete [] data_;
    data_     = nullptr;
    capacity_ = yad_capacity;
    size_     = yad_size;
}

template <typename T>
Vector<T>::Vector(size_t cap):
        capacity_(cap),
        size_(0) {
    if (cap != 0)
        data_ = new(mem_info) T[cap];
    else
        data_ = nullptr;
}

template <typename T>
T& Vector<T>::at(size_t index) {
    assert(0 <= index && index <= capacity_);

    return data_[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return at(index);
}

template <typename T>
void Vector<T>::swap(Vector& that) {
    std::swap(data_,     that.data_);
    std::swap(capacity_, that.capacity_);
    std::swap(size_,     that.size_);
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector that) {
    swap(that);

    return *this;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& that) {
    data_ = new(mem_info) T[that.capacity_];
    memcpy(data_, that.data_, sizeof(*that.data_) * that.size_);

    capacity_ = that.capacity_;
    size_     = that.size_;
}

template <typename T>
void Vector<T>::pushBack(T thx) {
    assert(size_     != yad_size);
    assert(capacity_ != yad_capacity);

    if (size_ == capacity_) memIncrease();
    data_[size_++] = thx;
}

template <typename T>
void Vector<T>::popBack() {
    assert(!data_);
    assert(size_     != yad_size);
    assert(capacity_ != yad_capacity);

    if ((size_ - 1) * 4 == capacity_) memDecrease();
    data_[--size_] = 0;
}

template <typename T>
void Vector<T>::memIncrease() {
    assert(size_     != yad_size);
    assert(capacity_ != yad_capacity);

    if(!data_) {
        size_     = 0;
        capacity_ = 2;
        data_     = new(mem_info) T[capacity_];
    }

    else {
        capacity_ *= 2;
        data_      = new(mem_info, data_) T[capacity_];
    }
}

template <typename T>
void Vector<T>::memDecrease() {
    capacity_ /= 2;
    data_      = new(mem_info, data_) T[capacity_];
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& that) {
    size_t tmp = that.size_;

    if (that.size_ > size_) size_ = that.size_;

    if (that.size_ > capacity_) {
        capacity_ = that.capacity_;
        data_ = new(mem_info, data_) T[capacity_];
    }

    for (int i = 0; i < tmp; i++)
        this->data_[i] += that.data_[i];

    return *this;
}
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------



#endif //VECTOR_VECTOR_H
