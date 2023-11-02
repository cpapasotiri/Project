#pragma once

#include <iostream>
#include <stdexcept>

#include "vector.hpp"

using namespace std;

template <typename T>
class Dimensions {
    private:
        Vector<T> data;
        int rows, cols;
    public:
        Dimensions(int rows, int colms);
        ~Dimensions();
        void set_data(T value, int row, int col);
        int get_data(int row, int col) const;
        void display_dimensions() const;
};


#include "../src/dimensions.tpp"