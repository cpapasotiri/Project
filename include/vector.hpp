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
    Vector(const Vector<T> &other);
    ~Vector();
    T &operator[](size_t index);
    bool operator==(Vector<T> &other);
    void push_back(const T &element);
    size_t get_capacity() const;
    size_t get_size() const;
    void display_vector() const;
    float euclideanDistance(const Vector<T> &point2);
    float manhattanDistance(const Vector<T> &point2);
    T get_dimension_value(int dimension);
    float euclidean_dimesion(int dimension, const Vector<T> &point2);
    bool contains(T &element);
};

#include "../templates/vector.tpp"