#include "input.hpp"

using namespace std;

template <typename T>
InputReader<T>::InputReader(const char *filename, int dim, const char *mode) : dim(dim) {
    file = fopen(filename, mode);
    if (file == nullptr){
        cerr << "Unable to open file" << endl;
    }
}

// template <typename T>
// Vector<T> InputReader<T>::readData(){
    // 
    // return;
// }