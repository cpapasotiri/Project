#pragma once
#include <cmath>
#include "vector.hpp"

template <typename T>
double euclideanDistance(const Vector<T> &point1, const Vector<T> &point2);

template <typename T>
double manhattanDistance(const Vector<T> &point1, const Vector<T> &point2);