#include "vector.hpp"

template <typename T>
Vector<T>::Vector() : capacity(10), size(0)
{
    array = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) : capacity(other.capacity), size(other.size)
{
    array = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
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
bool Vector<T>::operator==(Vector<T> &other)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == other.array[i])
        {
            return true;
        }
    }
    return false;
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
        delete[] array;
        array = newArray;
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
float Vector<T>::euclideanDistance(const Vector<T> &point2)
{
    if (this->get_size() != point2.get_size())
    {
        throw invalid_argument("Points should have the same dimensions.");
    }

    float distance = 0.0;
    for (size_t i = 0; i < this->get_size(); i++)
    {
        distance += pow(point2.array[i] - this->array[i], 2);
    }
    return (float)sqrt(distance);
}

template <typename T>
float Vector<T>::manhattanDistance(const Vector<T> &point2)
{
    if (this->get_size() != point2.get_size())
    {
        throw invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < this->get_size(); i++)
    {
        distance += abs(this->array[i] - point2.array[i]);
    }
    return distance;
}

template <typename T>
T Vector<T>::get_dimension_value(int dimension)
{
    if (dimension < 0 || dimension >= (int)this->get_size())
    {
        throw invalid_argument("Dimension out of range.");
    }
    return array[dimension];
}

template <typename T>
float Vector<T>::euclidean_dimesion(int dimension, const Vector<T> &point2)
{
    if ((this->get_size() != point2.get_size()) || (dimension < 0) || ((size_t)dimension > this->get_size()))
    {
        throw invalid_argument("Invalid dimension or point with different dimensions.");
    } 
    float diff = this->get_dimension_value(dimension) - point2.get_dimension_value(dimension);
    return diff * diff;
}

template <typename T>
bool Vector<T>::contains(T &element) 
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }
    return false;
}