#include "vector.hpp"

template <typename T>
Vector<T>::Vector() : capacity(10), size(0)
{
    array = new T[capacity];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] array;
}

template <typename T>
T &Vector<T>::operator[](size_t index)
{
    if (index >= size)
    {
        throw out_of_range("Index out of range");
    }
    return array[index];
}

template <typename T>
void Vector<T>::resize(size_t new_size)
{
    if (new_size < size)
    {
        size = new_size;
    }
    else if (new_size > capacity)
    {
        capacity = new_size;
        T *newArray = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        array = newArray;
        delete[] newArray;
    }
}

template <typename T>
void Vector<T>::push_back(const T &element)
{
    if (size >= capacity)
    {
        capacity *= 2;
        T *newArray = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        array = newArray;
        delete[] newArray;
    }
    array[size++] = element;
}

template <typename T>
size_t Vector<T>::get_capacity() const
{
    return capacity;
}

template <typename T>
size_t Vector<T>::get_size() const
{
    return size;
}

template <typename T>
void Vector<T>::display_vector() const
{
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
double Vector<T>::euclideanDistance(const Vector<T> &point2)
{
    if (this->get_size() != point2.get_size())
    {
        throw std::invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < this->get_size(); i++)
    {
        distance += pow(this->array[i] - point2.array[i], 2);
    }
    return sqrt(distance);
}

template <typename T>
double Vector<T>::manhattanDistance(const Vector<T> &point2)
{
    if (this->get_size() != point2.get_size())
    {
        throw std::invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < this.get_size(); i++)
    {
        distance += abs(this->array[i] - point2.array[i]);
    }
    return distance;
}
