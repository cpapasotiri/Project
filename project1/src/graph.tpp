#include <iostream>
#include <cmath>
#include "graph.hpp"

using namespace std;

template <typename T>
Vertex<T>::Vertex(int id, const Vector<T> &point) : id(id), point(point)
{
}

template <typename T>
Graph<T>::Graph()
{
    number_of_vertices = 0;
    vertex = nullptr;
    adjacency_list = Vector<DLL<T>>();
}

template <typename T>
Graph<T>::~Graph()
{
    delete[] adjacency_list;
}

template <typename T>
void Graph<T>::add_edge(const Vertex<T> &vertex_a, const Vertex<T> &vertex_b)

{
    adjacency_list[vertex_a.id].addFirst(vertex_b.point);
    adjacency_list[vertex_b.id].addFirst(vertex_a.point);
}

template <typename T>
Vertex<T> *Graph<T>::add_vertex(const Vector<T> &point)
{
    Vertex<T> *vertex = new Vertex<T>(number_of_vertices, point);
    adjacency_list.push_back(DLL<T>());
    number_of_vertices++;
    return vertex;
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
