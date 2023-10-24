#include "input.hpp"     

int import_sigmod2023_file(const char *filename) {
    if(stat(filename, &results) == 0){
        //  results.st_size is the size of the file in bytes
    } 
    else {
        // error
        }

    string x;
    ifstream infile;
    infile.open(filename, ios::binary | ios::in);
    infile.read(x, sizeof(uint32_t) * 100 * sizeof(float));//?
    

        return 0;
}