#include <iostream>
#include <cmath>
#include "graph.hpp"
#include "vector.tpp"

using namespace std;

Graph::Graph(int vertices)
{
    this->number_of_vertices = vertices;
    adjacency_list = new list<int>[vertices];
}

Graph::~Graph()
{
    delete[] adjacency_list;
}

void Graph::add_edge(int v, int w)
{
    adjacency_list[v].push_back(w);
    adjacency_list[w].push_back(v);
}

void Graph::add_vertex()
{
    number_of_vertices++;
    list<int> *new_adjacency_list = new list<int>[number_of_vertices];
    for (int i = 0; i < number_of_vertices; i++)
    {
        new_adjacency_list[i] = adjacency_list[i];
    }
    delete[] adjacency_list;
    adjacency_list = new_adjacency_list;
}

void Graph::display_graph()
{
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Adjacency list of vertex: " << i << ": ";
        copy(adjacency_list[i].begin(), adjacency_list[i].end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

double Graph::euclideanDistance(const Vector<T> &point1, const Vector<T> &point2)
{
    if (point1.size() != point2.size())
    {
        throw std::invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < point1.size(); i++)
    {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

double Graph::manhattanDistance(const Vector<T> &point1, const Vector<T> &point2)
{ 
    if (point1.size()!= point2.size())
    {
        throw std::invalid_argument("Points should have the same dimensions.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < point1.size(); i++)
    {
        distance += abs(point1[i] - point2[i]);
    }
    return distance;

}
