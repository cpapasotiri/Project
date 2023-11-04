#include <iostream>
#include <cmath>
#include "graph.hpp"

using namespace std;

template <typename T>
Vertex<T>::Vertex(int id, Vector<T> point) : id(id), point(point)
{
}

template <typename T>
Vertex<T>::Vertex() : id(0), point(Vector<T>()) {}

template <typename T>
Vertex<T> &Vertex<T>::operator=(const Vertex<T> &other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->point = other.point; 
    }
    return *this;
}

template <typename T>
Graph<T>::Graph()
{
    number_of_vertices = 0;
    vertices = Vector<Vertex<T>>();
    adjacency_list = Vector<DLL<T>>();
}

template <typename T>
Graph<T>::~Graph()
{
    // for (int i = 0; i < number_of_vertices; i++)
    // {
    //     delete vertices[i];
    // }
    // delete[] adjacency_list;
}

// save vertex to vector and create a adjacency list for its neighbors
template <typename T>
void Graph<T>::add_vertex(const Vector<T> point) // CHECK if vertex pushed in the vectors & return boolean
{   
    cout << "bika mesa" << endl;
    Vertex<T> vertex;
    vertex.id = number_of_vertices;
    vertex.point = point;
    cout << "Vertex " << number_of_vertices << " added" << endl;
    vertices.push_back(vertex);
    cout << "pushback done" << endl;
    adjacency_list.push_back(DLL<T>());
    cout << "pushback adjacecny done" << endl;
    number_of_vertices++;
    cout << "number of vertices: " << number_of_vertices << endl;
}

// create K random unique edges for each vertex
template <typename T>
void Graph<T>::add_edges(int K)
{ // create K edges in adjList for each vertex in vertices vector
    // random select of vertex edges

    for (int i = 0; i < number_of_vertices; i++)
    { // for each vertex
        for (int j = 0; j < K; j++)
        { // select K random numbers
        }
    }
}

template <typename T>
void Graph<T>::add_edge(const Vertex<T> &vertex_a, const Vertex<T> &vertex_b)
{
    adjacency_list[vertex_a.id].addFirst(vertex_b.point);
    adjacency_list[vertex_b.id].addFirst(vertex_a.point);
}

template <typename T>
int Graph<T>::get_number_of_vertices() const
{
    return number_of_vertices;
}

template <typename T>
Vertex<T> *Graph<T>::get_vertex(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid vertex id" << endl;
        return nullptr;
    }
    return vertices[id];
}

template <typename T>
DLL<T> *Graph<T>::get_adjacent_list(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid adjacency list id" << endl;
        return nullptr;
    }
    return adjacency_list[id];
}

template <typename T>
void Graph<T>::display_graph()
{ // for each vertex print adjacency graph
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Vertex " << i << ": ";
        vertices[i].display_vector();
        cout << "adjacency list: " << i << ": ";
        adjacency_list[i].print();
        cout << endl;
    }
}
