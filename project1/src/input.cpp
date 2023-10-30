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
    
    // char buffer[results.st_size];
    // ifstream file(filename, ios::in | ios::binary);
    // file.read(buffer, results.st_size);
    // if (!file) {
    //     cout << "Error reading file" << endl;
    //     return 1;
    // }
    // else {
    //     cout << "File read successfully" << endl;
    //     cout << "Number of bytes read: " << file.gcount() << endl;
    //     file;
    //     cout << buffer << endl;
    //     file.close();
    // }

    // int x;
    // ifstream infile;
    // infile.open(filename, ios::in | ios::binary);
    // infile.read(&x, results.st_size);



    // ifstream file(filename, ios::binary | ios::ate);

    // if (file.is_open()) {
    //     // Get the size of the file
    //     streampos fileSize = file.tellg();
    //     file.seekg(0, ios::beg);

    //     // Create a buffer to read the file
    //     char* buffer = new char[fileSize];

    //     // Read the file
    //     file.read(buffer, fileSize);

    //     // Output the content of the file
    //     cout.write(buffer, fileSize);

    //     // Clean up
    //     delete[] buffer;
    //     file.close();
    // } else {
    //     cerr << "Unable to open file" << endl;
    // }

    // ifstream file(filename, ios::binary);

    // if (file.is_open()) {
    //     char c;
    //     while (file.get(c)) {
    //         cout << c;
    //     }
    //     file.close();
    // } else {
    //     cerr << "Unable to open file" << endl;
    // }

    ifstream file(filename, ios::binary);

    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            if (isprint(static_cast<double>(c))) {
                cout << c;
            } else {
                // cout << '.';
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    return 0;
}

int read_csv_file(const char *filename){
    cout << "Reading csv file: " << filename << endl;
    if (stat(filename, &results) == 0) {
        cout << "File exists" << endl;
        cout << "The size of file in bytes is " << results.st_size << endl << endl;
    }
    else {
        // error occurred
        cout << "File does not exist" << endl << endl;
        return stat(filename, &results);
    }

    ifstream file(filename, ios::in);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    return 0;
}