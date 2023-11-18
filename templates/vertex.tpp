#include <iostream>
#include "vertex.hpp"

template <typename T>
Vertex<T>::Vertex() : id(0), point(new Vector<T>()) 
{
    // cout << "1st constructor" << endl;
}

template <typename T>
Vertex<T>::Vertex(const Vertex<T> &other) : id(other.id), point(new Vector<T>(*other.point)) 
{
    // cout << "2nd constructor" << endl;
}

template <typename T>
Vertex<T>::Vertex(int i, Vector<T> *p) 
{
    // cout << "3rd constructor" << endl;
    id = i;
    point = new Vector<T>(*p);
}

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
    // cout << "Vertex dectructor" << endl;
    // point->~Vector();
    // delete point;
}