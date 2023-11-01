#include "input.hpp"     

int read_binary_file(const char *filename) {
    cout << "Reading binary file: " << filename << endl;
    
    ifstream file(filename, ios::binary);    
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    uint32_t N;
    file.read(reinterpret_cast<char*>(&N), sizeof(uint32_t));

    // allocate memory for N elements, each containing 100 floats
    float** points = new float*[N];
    for (uint32_t i = 0; i < N; i++) {
        points[i] = new float[100];
        file.read(reinterpret_cast<char*>(points[i]), sizeof(float)* 100); 
    }

    for (uint32_t i = 0; i < N; i++) {
        cout << points[i][0] << endl;
    }

    for (uint32_t i = 0; i < N; i++) {
        delete points[i];
    }
    delete[] points;

    return 0;
}

int read_csv_file(const char *filename){
    cout << "Reading csv file: " << filename << endl;

    ifstream file(filename, ios::in);    
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    
    vector<pair<double, double>> points;
    string line;
    while (getline(file, line)) {
        istringstream lineStream(line);
        string x, y;
        if (getline(lineStream, x, ',') && getline(lineStream, y, ',')) {
            double x_value = stod(x);
            double y_value = stod(y);
            points.push_back(make_pair(x_value, y_value));
        }
    }
    
    for (auto point : points) {
        cout << point.first << " " << point.second << endl;
    }
    cout << endl ;

    file.close();

    return 0;
}