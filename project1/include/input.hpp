#pragma once

#include <iostream>
#include "vector.hpp"
#include "graph.hpp"

using namespace std;

template <typename T>
class InputReader {
    private:
        FILE *file;     
        int dim;        // number of dimensions
        char *mode;     // open mode
    public:
        InputReader(const char *filepath, int dim, char *mode);
        // Vector<T> readData();
};

#include "../src/input.tpp"