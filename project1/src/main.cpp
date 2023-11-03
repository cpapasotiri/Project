#include <iostream>
#include <cstring>

// #include "input.hpp"
#include "graph.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "DLL.hpp"

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

    int dim = atoi(argv[4]);    // dimensions of point
    int K = atoi(argv[6]);      // K nearest neighbors

    Vector<float> vector;
    // Graph<int> graph(K);
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


    // read_binary_file("../project1/datasets/00000020.bin");
    // read_csv_file("../project1/datasets/points.csv");


    Vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(5);
    v.display_vector();

    Vector<int> point1;
    point1.push_back(1);
    point1.push_back(2);
    point1.push_back(3);

    Vector<int> point2;
    point2.push_back(4);
    point2.push_back(6);
    point2.push_back(8);

    Graph<int> *graph = new Graph<int>();
    graph->add_vertex(point1);
    graph->add_vertex(point2);
    graph->add_vertex(v);

    DLL<int>* dll = new DLL<int>();

    dll->addFirst(v);
    // dll.addFirst(point2);
    // dll.addLast(point2);
    // dll.addLast(point1);

    // dll.print();
// 
    // cout << point1.euclideanDistance(point2) << endl;

    delete dll;
    
    return 0;
}
