#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
// #include <vector>   // CHANGE THIS
#include "vector.hpp"


using namespace std;

// <uint32_t> N (number of elements)
// N* element, where each element is 100 consecutive <float> 
int read_binary_file(const char *filename);

// <double> x, <double> y 
int read_csv_file(const char *filename);