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
    if (argc != 5)
    {
        cerr << "Usage: " << argv[0] << " <filepath> <dimensions> <K nearest neighbors> <distance type e or m>" << endl;
        return 1;
    }

    int dim = atoi(argv[2]); // dimensions of point
    if (dim <= 0)
    {
        cerr << "Invalid dimensions" << endl;
        return 1;
    }

    int K = atoi(argv[3]); // K nearest neighbors
    if (K <= 0)
    {
        cerr << "Invalid K" << endl;
        return 1;
    }

    char *distance = argv[4]; // distance type
    if (strcmp(distance, "e") != 0 && strcmp(distance, "m") != 0)
    {
        cerr << "Invalid distance type. Select e for euclidean or m for manhattan." << endl;
        return 1;
    }

    char *filepath = argv[1]; // inputFile
    int file = open(filepath, O_RDONLY);
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
    Graph<float> *graph = new Graph<float>(distance);

    start = clock();
    cout << "Reading " << N << " points" << endl;
    for (uint32_t i = 0; i < N; i++)
    {
        Vector<float> *data = new Vector<float>();
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
        delete data;
    }
    close(file);

    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for creation of points into graph: " << elapsed_time << endl;

    // select K random neighbors for each vertex
    cout << "Creating " << K << " random neighbors for each vertex" << endl;
    srand(time(0)); // needed by random vertex number generator
    graph->add_edges(K);

    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for creation of graph adges: " << elapsed_time << endl;

    // graph->display_graph();

    // implementation of NN-Descent Algorithm
    graph->NNDescent();

    graph->display_graph();
    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for everything: " << elapsed_time << endl;

    delete graph;

    return 0;
}
