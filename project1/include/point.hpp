#pragma once

#include <iostream>
#include <stdexcept>

#include "vector.hpp"

using namespace std;

template <typename T>
class Point {
    private:
        Vector<T> data;
        int rows, cols;
    public:
        Point(int rows, int colms);
        ~Point();
        void set_data(T value, int row, int col);
        int get_data(int row, int col) const;
        void display_point() const;
};


#include "../src/point.tpp"