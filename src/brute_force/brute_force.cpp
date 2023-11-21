#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

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

    // create output file
    size_t len = 256;
    char output_filepath[len];
    create_output_filepath(filepath, distance, output_filepath, len);
    cout << "Output filepath: " << output_filepath << endl; 

    Graph<float> *graph = new Graph<float>(distance);
    
    // Open the file for writing with read-write permissions, creating it if it doesn't exist
    int outfile = open(output_filepath, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR); 
    if (outfile == -1) 
    {
        cerr << "Unable to open file:" << output_filepath << endl;
        return 1;
    }

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

    graph->display_graph();
    graph->bruteForce(K);   // TODO: write calculations to binary file 
    graph->display_graph();
 
    // brute force algorithm calling
    // write distances to output_filepath file
    char* test = "test insert to file";
    if (write(outfile, test, strlen(test)) == -1) 
    {
        std::cerr << "Error writing to file: " << output_filepath << endl;
    }
    close(outfile);

    delete graph;
    return 0;
}