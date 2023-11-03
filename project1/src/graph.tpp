#include <iostream>
#include <cmath>
#include "graph.hpp"


using namespace std;

template <typename T>
Graph<T>::Graph(int vertices)
{
    this->number_of_vertices = vertices;
    adjacency_list = new DLL<int>[vertices];
}

template <typename T>
Graph<T>::~Graph()
{
    delete[] adjacency_list;
}

template <typename T>
void Graph<T>::add_edge(Vertex<T>& vertex_a, Vertex<T>& vertex_b)

{
    adjacency_list[vertex_a->id].addFirst(vertex_b);
    adjacency_list[vertex_b->id].addFirst(vertex_a);
}

template <typename T>
void Graph<T>::add_vertex(const Vector<T>& point)
{
    number_of_vertices++;
    DLL<int> *new_adjacency_list = new DLL<int>[number_of_vertices];
    for (int i = 0; i < number_of_vertices; i++)
    {
        new_adjacency_list[i] = adjacency_list[i];
    }
    delete[] adjacency_list;
    adjacency_list = new_adjacency_list;
}

template <typename T>
void Graph<T>::display_graph()
{
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Adjacency list of vertex: " << i << ": ";
        cout << endl;
    }
}

