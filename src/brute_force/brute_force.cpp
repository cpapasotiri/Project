#include <iostream>
#include <cstring>

#include "graph.hpp"
#include "vector.hpp"
#include "IO.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        cerr << "Usage: " << argv[0] << " <filepath> <dimensions> <K nearest neighbors> <distance type e or m>" << endl;
        return 1;
    }

    int dim = atoi(argv[2]);  // dimensions of point
    if (dim <= 0)
    {
        cerr << "Invalid dimensions" << endl;
        return 1;
    }

    int K = atoi(argv[3]);    // K nearest neighbors
    if(K <= 0)
    {
        cerr << "Invalid K" << endl;
        return 1;
    }

    char *distance = argv[4]; // distance type
    if (strcmp(distance, "e") != 0 && strcmp(distance, "m") != 0){
        cerr << "Invalid distance type. Select e for euclidean or m for manhattan." << endl;
        return 1;
    }

    char *filepath = argv[1]; // inputFile
    int file = open_filepath(filepath, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    uint32_t N;
    if (read_from_filepath(file, &N, sizeof(uint32_t)) != sizeof(uint32_t))
    {
        cerr << "Error reading file" << endl;
        return 1;
    }  

    Graph<float> *graph = new Graph<float>(distance);
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

    // create output file
    char output_filepath[256];
    create_output_filepath(filepath, distance, output_filepath, sizeof(output_filepath));
        
    // Open the file for writing with read-write permissions, creating it if it doesn't exist
    int outfile = open_filepath(output_filepath, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR); 

    // graph->display_graph();

    // brute force algorithm calling
    graph->bruteForce(K);

    bool result = graph->store_neighbors(K, outfile);
    cout << result << endl;
    
    // graph->display_graph();
    
    close_filepath(outfile);

    delete graph;
    return 0;
}