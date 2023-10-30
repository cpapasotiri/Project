#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

using namespace std;

// <uint32_t> N (number of elements)
// N* element, where each element is 100 consecutive <float> 
// little endian format
int read_binary_file(const char *filename);

int read_csv_file(const char *filename);