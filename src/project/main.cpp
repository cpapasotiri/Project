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
    // validate main arguments
    char input_filepath[256], distance[2];
    int dimensions, K;
    if (main_args_validator(argc, argv, input_filepath, &dimensions, &K, distance) != 0)
    {
        cerr << "Error validating main arguments" << endl;
        return -1;
    }
    cout << "input_filepath: " << input_filepath << ", dimensions = " << dimensions << ", K = " << K << ", distance = " <<  distance << endl;
    
    // open for reading input file
    int file = open_filepath(input_filepath, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file == -1) 
    {
        cerr << "Error opening input file" << endl;
        return -1;
    }

    uint32_t N;
    if (read_from_filepath(file, &N, sizeof(uint32_t)) != sizeof(uint32_t))
    {
        cerr << "Error reading file" << endl;
        close_filepath(file);
        return -1;
    }

    // measure the running time of ...
    clock_t start, end;
    double elapsed_time;

    // store file data to graph as vertices
    Graph<float> *graph = new Graph<float>(distance);

    start = clock();
    cout << "Reading " << N << " points from " << input_filepath << endl;
    for (uint32_t i = 0; i < N; i++)
    {
        Vector<float> *data = new Vector<float>();
        for (int j = 0; j < dimensions; j++)
        {
            float fnum;
            if (read_from_filepath(file, &fnum, sizeof(float)) != sizeof(float))
            {
                cerr << "Error reading data" << endl;
                close_filepath(file);
                return -1;
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
    cout << "Elapsed time for creation of graph neighbors: " << elapsed_time << endl;

   // graph->display_graph();

    // implementation of NN-Descent Algorithm
    graph->NNDescent(K);

    //graph->display_graph();
    // open for reading output file created by brute force
    char output_filepath[256];
    create_output_filepath(input_filepath, distance, K, output_filepath, sizeof(output_filepath));

    int output_file = open_filepath(output_filepath, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_file == -1) 
    {
        cerr << "Error opening output file" << endl;
        delete graph;
        return -1;
    }


   // graph->display_graph();
    cout << "Reading vertices from outfile" << endl;
    // Compare k neighbors of every vertex from brute_force using
    int success = graph->compare_neighbors(output_file);
    cout << "NN-Descend was " << success << "% successful!" << endl;

    if (close_filepath(output_file))
    {
        cerr << "Error closing outfile" << endl;
        return -1;
    }

    end = clock();
    elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time for everything: " << elapsed_time << endl;

    delete graph;

    return 0;
}