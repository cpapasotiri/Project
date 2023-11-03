#include <iostream>
#include <cstring>

// #include "input.hpp"
#include "graph.hpp"
#include "vector.hpp"
#include "point.hpp"
//#include "distances.hpp"

using namespace std;


int main(int argc, char *argv[])
{
    if (argc != 7){
        cerr << "Usage: " << argv[0] << " -f <filepath> -d <dimensions> -k <K nearest neighbors>" << endl;
        return 1;
    }

    if (strcmp(argv[1], "-f") != 0 || strcmp(argv[3], "-d") != 0){
        cerr << "Usage: " << argv[0] << " -f <filepath> -d <dimensions> -k <K nearest neighbors>" << endl;
        return 1;
    }

    char *filename = argv[2];
    FILE *file = fopen(filename, "rb"); // read from binary file
    if (file == NULL){
        cerr << "Unable to open file" << endl;
        return 1;   
    }

    int dim = atoi(argv[4]);
    int K = atoi(argv[6]);

    Vector<float> vector;
    Graph<int> graph(K);
    float fnum;
    int count = 0;
    while (fscanf(file, "%f", &fnum) == 1){
        vector.push_back(fnum);
        count++;
        if (count == dim){
            // found point (vector creation complited), push to graph

            count = 0;
        }
    }



    return 0;
}
