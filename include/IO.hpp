#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

// main arguments validator
// brute_force executable: <filepath> <dimensions> <K nearest neighbors> <distance type e or m>
// project executable: <filepath> <dimensions> <K nearest neighbors> <distance type e or m> <delta> <p>
// returns -1 on error or 0 on success
int main_args_validator(int argc, char* argv[], char *input_filepath, int* dimensions, int* K, char *distance, int* delta, float* p);

// create directory if it doesn't exist
bool create_directory(const char* path);

// THIS FUNCTION WORKS PROPERLY ONLY BY USING BINARY EXTENSION FILES:
// extract filename from filepath and use distance type to create a new filename in output_filepath 
// example: filepath = dataset/2dims.bin & distance = e => output_filepath = output/2dims_e.bin
// result stored in output_filepath
void create_output_filepath(char* filepath, char* distance, int K, char* output_filepath, size_t output_filepath_len);

// open filepath using flags and mode
int open_filepath(const char* filepath, int flags, mode_t mode);

// close filepath with file descriptor fd
int close_filepath(int fd);

// read size into buf from file descriptor fd
// returns -1 on error or 0 on success
size_t read_from_filepath(int fd, void* buf, size_t size);

// write buf to file descriptor fd
// returns -1 on error or the number written bytes on success
int write_to_filepath(int fd, const void* buf, size_t size);

// calculate the length of an integer
int get_int_len(int number);

// convert int to string
void int_to_str(int number, char* str, int lenght);