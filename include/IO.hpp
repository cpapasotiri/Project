#pragma once

#include <iostream>
#include <cstring>
// #include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

// create directory if it doesn't exist
bool create_directory(const char* path);

// THIS FUNCTION WORKS PROPERLY ONLY BY USING BINARY EXTENSION FILES:
// extract filename from filepath and use distance type to create a new filename in output_filepath 
// example: filepath = dataset/2dims.bin & distance = e => output_filepath = output/2dims_e.bin
// result stored in output_filepath
void create_output_filepath(char* filepath, char* distance, char* output_filepath, size_t output_filepath_len);

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