#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

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
            
        }

    }
    close(file);

    // brute force algorithm calling

    // write distances to bin file  
    size_t len = strlen(filepath) + strlen("output/") + strlen("_") + strlen(distance) + 1;
    char output_filepath[256];
    create_output_filepath(filepath, distance, output_filepath, len);
    
    cout << "Output filepath: " << output_filepath << endl;
    // write(file)

    return 0;
}