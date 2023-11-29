#include <iostream>
#include <cstring>
#include <cstdint>
#include <ctime>

#include "graph.hpp"
#include "vector.hpp"
#include "DLL.hpp"
#include "IO.hpp"

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
    int file = open_filepath(filepath, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    uint32_t N;
    if (read_from_filepath(file, &N, sizeof(uint32_t)) != sizeof(uint32_t))
    {
        cerr << "Error reading file" << endl;
        close_filepath(file);
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
            if (read_from_filepath(file, &fnum, sizeof(float)) != sizeof(float))
            {
                cerr << "Error reading data" << endl;
                close_filepath(file);
                return 1;
            }
            data->push_back(fnum);
        }
        graph->add_vertex(data);
        delete data;
    }
    close_filepath(file);

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

    //graph->display_graph();

    // implementation of NN-Descent Algorithm
    graph->NNDescent(K);

    //graph->display_graph();

    // open output file created by brute force  
    // char output_filepath[256];
    // create_output_filepath(filepath, distance, output_filepath, sizeof(output_filepath));
    // cout << "Output filepath: " << output_filepath << endl;
    // int output_file = open_filepath(output_filepath, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
    
    // if (read_from_filepath(output_file, &K, sizeof(Pair<float>)) != sizeof(Pair<float>))
    // {
    //     cerr << "Error reading output file" << endl;
    //     close_filepath(output_file);
    //     return 1;
    // }

    // cout << "Reading " << N*K << "vertices" << endl;
    // // for every k neighbors of every vertex compare 
    // for (uint32_t i = 0; i < N; i++)
    // {
    //     Vector<float> *vector = new Vector<float>();
    //     for (int j = 0; j < K; j++)
    //     {
    //         Vertex<float> *v = new Vertex<float>();
    //         if (read_from_filepath(output_file, v, sizeof(Vertex<float>)) != sizeof(Vertex<float>))
    //         {
    //             cerr << "Error reading output file" << endl;
    //             close_filepath(output_file);
    //             return 1;
    //         }
    //         vector->push_back(v);
    //     }
    //     delete v;
    // }
    // close_filepath(output_file); 

    // graph->display_graph();
    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for everything: " << elapsed_time << endl;

    delete graph;

    return 0;
}