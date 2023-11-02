#include "distances.hpp"

template <typename T>
double euclideanDistance(const Vector<T> &point1, const Vector<T> &point2)
{
    if (point1.get_size() != point2.get_size())
    {
        throw std::invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < point1.get_size(); i++)
    {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

template <typename T>
double manhattanDistance(const Vector<T> &point1, const Vector<T> &point2)
{
    if (point1.get_size() != point2.get_size())
    {
        throw std::invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < point1.get_size(); i++)
    {
        distance += abs(point1[i] - point2[i]);
    }
    return distance;
}
