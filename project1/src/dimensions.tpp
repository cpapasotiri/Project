#include "dimensions.hpp"

template <typename T>
Dimensions<T>::Dimensions(int rows, int colms) {
    this->rows = rows;
    this->cols = colms;
    data = new Vector<T>[rows];
    for (int i = 0; i < rows; ++i){
        data[i] = new Vector<T>[cols];
    }
}

template <typename T>
Dimensions<T>::~Dimensions(){
    for (int i = 0; i < rows; ++i){
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
void Dimensions<T>::set_data(T value, int row, int col){
    if (row >= 0 && row < rows && col >= 0 && col < cols){
        data[row][col] = value;
    } else{
        cerr << "Invalid index" << endl;
    }
}

template <typename T>
int Dimensions<T>::get_data(int row, int col) const{
    if (row >= 0 && row < rows && col >= 0 && col < cols){
        return data[row][col];
    } else{
        cerr << "Invalid index" << endl;
        return T();     // default value for invalid index
    }
}

template <typename T>
void Dimensions<T>::display_dimensions() const{
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}