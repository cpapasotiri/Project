#include <iostream>
#include <cstring>

#include "graph.hpp"
#include "vector.hpp"
#include "IO.hpp"

using namespace std;

int main(int argc, char *argv[])
{   
    // validate main arguments
    char input_filepath[256], distance[2];
    int dimensions, K;
    if (main_args_validator(argc, argv, input_filepath, &dimensions, &K, distance) == -1)
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
        return -1;
    }  

    Graph<float> *graph = new Graph<float>(distance);
    cout << "Reading " << N << " points" << endl;
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

    // create output file
    char output_filepath[256];
    create_output_filepath(input_filepath, distance, K, output_filepath, sizeof(output_filepath));

    // Open the output file for writing 
    int outfile = open_filepath(output_filepath, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    if (outfile == -1)
    {
        cerr << "Error opening outfile" << endl;
        delete graph;
        return -1;
    }
    // graph->display_graph();

    // brute force algorithm calling
    graph->bruteForce(K);

    // store all neighbors into outfile
    graph->store_neighbors(outfile);
    
    // graph->display_graph();
    delete graph;
    if (close_filepath(outfile))
    {
        cerr << "Error closing outfile" << endl;
        return -1;
    }

    
    return 0;
}