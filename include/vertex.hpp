#pragma once

#include <iostream>
#include "vector.hpp"

using namespace std;

template <typename T>
struct Vertex
{
    int id;
    Vector<T> *point;
    
    Vertex();
    Vertex(const Vertex<T> &other);
    Vertex(int i, Vector<T> *point);
    Vertex<T> &operator=(const Vertex<T> &other);
    bool operator==(Vertex<T> &other);
    ~Vertex();
};

#include "../templates/vertex.tpp"