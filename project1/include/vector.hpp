#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector
{
private:
    T *array;
    size_t capacity;
    size_t size;

public:
    Vector();
    ~Vector();
    T &operator[](size_t index);
    void push_back(const T &element);
    size_t get_capacity() const;
    size_t get_size() const;
    void display_vector() const;
    double euclideanDistance(const Vector<T> &point2);
    double manhattanDistance(const Vector<T> &point2);
};

#include "../templates/vector.tpp"