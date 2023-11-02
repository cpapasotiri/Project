#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector{
    private:
        T* array;
        size_t capacity;
        size_t size;
    public:
        Vector();
        ~Vector();
        T& operator[](size_t index);
        void resize(size_t new_size);
        void push_back(const T& element);
        size_t get_capacity() const;
        size_t get_size() const;
        void display_vector() const;
};

#include "../src/vector.tpp"