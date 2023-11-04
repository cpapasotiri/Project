#include <iostream>
#include <cstring>

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
    
    FILE* file = fopen(filename, "rb");
    if (file == nullptr){
        cerr << "Unable to open file" << endl;
        return 1;
    }

    // store file data to graph as vertices 
    Graph<float> *graph = new Graph<float>();
    Vector<float> data;
    int count = 0;
    float fnum;
    while (fscanf(file, "%f", &fnum) == 1){
        data.push_back(fnum);
        count++;
        if (count == dim){      // found point (vector creation complited), push to graph
            graph->add_vertex(data);
            data.resize(0);
            count = 0;
        }
    }
    fclose(file);

    cout << "IN MAIN" << endl;
    
    // create K nearest neighbors graph
    // select random neighbors for each vertex
    // Vertex<float> *v1 = graph->add_vertex(data);
    


    return 0;
}
