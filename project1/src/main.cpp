#include <iostream>
#include <string>

// #include "input.hpp"
#include "graph.hpp"
#include "vector.hpp"
#include "point.hpp"

using namespace std;

int main(int argc, char *argv[]){
    
    // read_binary_file("../project1/datasets/00000020.bin");
    // read_csv_file("../project1/datasets/points.csv");
    
    // Graph graph(5);
    // graph.add_edge(0, 1);
    // graph.add_edge(0, 2);
    // graph.add_edge(1, 2);
    // graph.add_edge(1, 3);
    // graph.add_edge(2, 3);
    // graph.add_edge(4, 3);
    // graph.display_graph();

    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.display_vector();
    
    return 0;
}
