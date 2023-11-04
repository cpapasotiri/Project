#include <iostream>
#include <cstring>
#include <cstdint>
#include <unistd.h>
#include <fcntl.h>

// #include "input.hpp"
#include "graph.hpp"
#include "vector.hpp"
#include "DLL.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4){
        cerr << "Usage: " << argv[0] << " <filepath> <dimensions> <K nearest neighbors>" << endl;
        return 1;
    }

    char *filename = argv[1];   // inputFile
    int dim = atoi(argv[2]);    // dimensions of point
    int K = atoi(argv[3]);      // K nearest neighbors
    if (dim <= 0 || K <= 0){
        cerr << "Invalid dimensions or K" << endl;
    }
    
    // TODO use input.tpp & hpp files to read & use inputFile
    int file = open(filename, O_RDONLY);
    if (file == -1){
        cerr << "Unable to open file" << endl;
        return 1;
    }

    // store file data to graph as vertices 
    Graph<float> *graph = new Graph<float>();
    Vector<float> data;

    uint32_t N;
    if (read(file, &N, sizeof(uint32_t)) != sizeof(uint32_t)){
        cerr << "Error reading file" << endl;
        return 1;
    }
    // cout << "Reading " << N << " points" << endl;
    for (uint32_t i = 0; i < N; i++){
        
        for (int j = 0; j < dim; j++){
            float fnum;
            if (read(file, &fnum, sizeof(float)) != sizeof(float)){
                cerr << "Error reading data" << endl;
                close(file);
                return 1;
            }
            data.push_back(fnum);
        }
        graph->add_vertex(data);
        // cout << "Vertex " << i << ": ";
        // data.display_vector();
        // cout << endl;
        data.resize(0);
    }

   
    cout << "IN MAIN" << endl;
    
    // select K random neighbors for each vertex
    // Vertex<float> *v1 = graph->add_vertex(data);
    


    return 0;
}
