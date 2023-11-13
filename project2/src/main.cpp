#include <iostream>
#include <cstring>
#include <cstdint>
#include <unistd.h>
#include <fcntl.h>
#include <ctime>

#include "graph.hpp"
#include "vector.hpp"
#include "DLL.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Usage: " << argv[0] << " <filepath> <dimensions> <K nearest neighbors>" << endl;
        return 1;
    }

    char *filename = argv[1]; // inputFile
    int dim = atoi(argv[2]);  // dimensions of point
    int K = atoi(argv[3]);    // K nearest neighbors
    if (dim <= 0 || K <= 0)
    {
        cerr << "Invalid dimensions or K" << endl;
    }

    // TODO use input.tpp & hpp files to read & use inputFile
    int file = open(filename, O_RDONLY);
    if (file == -1)
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    uint32_t N;
    if (read(file, &N, sizeof(uint32_t)) != sizeof(uint32_t))
    {
        cerr << "Error reading file" << endl;
        return 1;
    }

    //  measure the running time of ...
    clock_t start, end;
    double elapsed_time;

    // store file data to graph as vertices
    Graph<float> *graph = new Graph<float>();
    Vector<float> *data = new Vector<float>();

    start = clock();
    cout << "Reading " << N << " points" << endl;
    for (uint32_t i = 0; i < N; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            float fnum;
            if (read(file, &fnum, sizeof(float)) != sizeof(float))
            {
                cerr << "Error reading data" << endl;
                close(file);
                return 1;
            }
            data->push_back(fnum);
        }
        graph->add_vertex(data);
        data->clear();
    }
    close(file);
    delete data;
    
    end = clock();
    elapsed_time = double(end-start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for creation of points into graph: " << elapsed_time << endl;

    // select K random neighbors for each vertex
    cout << "Creating " << K << " random neighbors for each vertex" << endl;
    srand(time(0)); // needed by random vertex number generator
    graph->add_edges(K);
    
    end = clock();
    elapsed_time = double(end-start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for creation of graph adges: " << elapsed_time << endl;

    //graph->display_graph();

    // implementation of algorithm: running forever
    graph->NNDescent();

    //graph->display_graph();
    end = clock();
    elapsed_time = double(end-start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for everything: " << elapsed_time << endl;

    delete graph;

    return 0;
}
