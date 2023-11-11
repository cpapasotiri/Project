#include <iostream>
#include "vertex.hpp"

template <typename T>
Vertex<T>::Vertex() : id(0), point(new Vector<T>()) {}

template <typename T>
Vertex<T>::Vertex(const Vertex<T> &other) : id(other.id), point(new Vector<T>(*other.point)) {}

template <typename T>
Vertex<T> &Vertex<T>::operator=(const Vertex<T> &other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->point = other.point;
    }
    return *this;
}

template <typename T>
bool Vertex<T>::operator==(Vertex<T> &other)
{
    if ((this->point->operator==(*other.point)) && (this->id == other.id))
    {
        return true;
    }
    return false;
    
}


template <typename T>
Vertex<T>::~Vertex()
{
}