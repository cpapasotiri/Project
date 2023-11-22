#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
// #include <sys/types.h>

using namespace std;

// create directory if it doesn't exist
bool create_directory(const char* path);

// THESE FUNCTIONS WORKS PROPERLY ONLY BY USING BINARY EXTENSION FILES:

// extract filename from filepath and use distance type to create a new filename in output_filepath 
// example: filepath = dataset/2dims.bin & distance = e => output_filepath = output/2dims_e.bin
// result stored in output_filepath
void create_output_filepath(char* filepath, char* distance, char* output_filepath, size_t output_filepath_len);