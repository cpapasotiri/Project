#include "input.hpp"     

struct stat results;

int read_binary_file(const char *filename) {
    cout << "Reading binary file: " << filename << endl;
    if (stat(filename, &results) == 0) {
        cout << "File exists" << endl;
        cout << "The size of file in bytes is " << results.st_size << endl << endl;
    }
    else {
        // error occurred
        cout << "File does not exist" << endl << endl;
        return stat(filename, &results);
    }
        return 0;
}