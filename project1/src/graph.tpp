#include <iostream>
#include <cmath>
#include "graph.hpp"


using namespace std;

template <typename T>
Graph<T>::Graph(int vertices)
{
    this->number_of_vertices = vertices;
    adjacency_list = new list<int>[vertices];
}

template <typename T>
Graph<T>::~Graph()
{
    delete[] adjacency_list;
}

template <typename T>
void Graph<T>::add_edge(int v, int w)
{
    adjacency_list[v].push_back(w);
    adjacency_list[w].push_back(v);
}

template <typename T>
void Graph<T>::add_vertex(const Vector<T>& point)
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

template <typename T>
void Graph<T>::display_graph()
{
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Adjacency list of vertex: " << i << ": ";
        cout << endl;
    }
}

