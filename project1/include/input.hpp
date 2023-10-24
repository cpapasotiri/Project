#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

struct stat results;

using namespace std;

// <uint32_t> N (number of elements)
// N* element, where each element is 100 consecutive <float> 
// little endian format
int import_sigmod2023_file(const char *filename);

int check_sigmod2023_file(const char *filename);