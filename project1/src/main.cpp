#include <iostream>
#include <string>

// #include "input.hpp"
#include "graph.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "DLL.hpp"

using namespace std;


int main(int argc, char *argv[])
{

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

    DLL<int> dll;

    dll.addFirst(point1);

    cout << point1.euclideanDistance(point2) << endl;

    return 0;
}
